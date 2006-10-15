/*BHEADER**********************************************************************
 * Copyright (c) 2006   The Regents of the University of California.
 * Produced at the Lawrence Livermore National Laboratory.
 * Written by the HYPRE team. UCRL-CODE-222953.
 * All rights reserved.
 *
 * This file is part of HYPRE (see http://www.llnl.gov/CASC/hypre/).
 * Please see the COPYRIGHT_and_LICENSE file for the copyright notice, 
 * disclaimer, contact information and the GNU Lesser General Public License.
 *
 * HYPRE is free software; you can redistribute it and/or modify it under the 
 * terms of the GNU General Public License (as published by the Free Software
 * Foundation) version 2.1 dated February 1999.
 *
 * HYPRE is distributed in the hope that it will be useful, but WITHOUT ANY 
 * WARRANTY; without even the IMPLIED WARRANTY OF MERCHANTABILITY or FITNESS 
 * FOR A PARTICULAR PURPOSE.  See the terms and conditions of the GNU General
 * Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * $Revision$
 ***********************************************************************EHEADER*/

#include "headers.h"

/*--------------------------------------------------------------------------
 * This routine serves as an alternative to the MatrixAssemble routine for the
 * semi interpolation and restriction operators.  It allows us to avoid having
 * to deal with zero boxes when figuring out communications patterns.
 *
 * The issue arises in the following scenario for process p.  In the diagram,
 * process p only owns grid points denoted by '|' and not those denoted by ':'.
 * The center of the stencil is represented by an 'x'.
 *
 *    x----> <----x----> <----x   stencil coeffs needed for P^T
 *     <----x----> <----x---->    stencil coeffs needed for P
 *     <----x<--->x<--->x---->    stencil coeffs needed for A
 *
 *    :-----:-----|-----:-----:   fine grid
 *    :-----------|-----------:   coarse grid
 *
 *     <----------x---------->    stencil coeffs to be computed for RAP
 *
 * The issue is with the grid for P, which is empty on process p.  Previously,
 * we added ghost zones to get the appropriate neighbor data, and we did this
 * even for zero boxes.  Unfortunately, dealing with zero boxes is a major pain,
 * so the below routine eliminates the need for handling zero boxes when
 * computing communication information.
 *
 *--------------------------------------------------------------------------*/

int
hypre_StructInterpAssemble( hypre_StructMatrix  *A,
                            hypre_StructMatrix  *P,
                            int                  P_stored_as_transpose,
                            int                  cdir,
                            hypre_Index          index,
                            hypre_Index          stride )
{
   hypre_StructGrid     *grid = hypre_StructMatrixGrid(A);

   hypre_BoxArrayArray  *box_aa;
   hypre_BoxArray       *box_a;
   hypre_Box            *box;

   hypre_CommInfo       *comm_info;
   hypre_CommPkg        *comm_pkg;
   hypre_CommHandle     *comm_handle;

   int                   num_ghost[] = {0, 0, 0, 0, 0, 0};
   int                   i, j, s, dim;

   if (hypre_StructMatrixConstantCoefficient(P) != 0)
   {
      return hypre_error_flag;
   }

   /* set num_ghost */
   dim = hypre_StructGridDim(grid);
   for (j = 0; j < dim; j++)
   {
      num_ghost[2*j]   = 1;
      num_ghost[2*j+1] = 1;
   }
   if (P_stored_as_transpose)
   {
      num_ghost[2*cdir]   = 2;
      num_ghost[2*cdir+1] = 2;
   }

   /* comm_info <-- From fine grid grown by num_ghost */

   hypre_CreateCommInfoFromNumGhost(grid, num_ghost, &comm_info);

   /* Project and map comm_info onto coarsened index space */

   hypre_CommInfoProjectSend(comm_info, index, stride);
   hypre_CommInfoProjectRecv(comm_info, index, stride);

   for (s = 0; s < 3; s++)
   {
      switch(s)
      {
         case 0:
            box_aa = hypre_CommInfoSendBoxes(comm_info);
            hypre_SetIndex(hypre_CommInfoSendStride(comm_info), 1, 1, 1);
            break;
         case 1:
            box_aa = hypre_CommInfoRecvBoxes(comm_info);
            hypre_SetIndex(hypre_CommInfoRecvStride(comm_info), 1, 1, 1);
            break;
         case 2:
            box_aa = hypre_CommInfoSendRBoxes(comm_info);
            break;
      }

      hypre_ForBoxArrayI(j, box_aa)
         {
            box_a = hypre_BoxArrayArrayBoxArray(box_aa, j);
            hypre_ForBoxI(i, box_a)
               {
                  box = hypre_BoxArrayBox(box_a, i);
                  hypre_StructMapFineToCoarse(hypre_BoxIMin(box), index, stride,
                                              hypre_BoxIMin(box));
                  hypre_StructMapFineToCoarse(hypre_BoxIMax(box), index, stride,
                                              hypre_BoxIMax(box));
               }
         }
   }

   comm_pkg = hypre_StructMatrixCommPkg(P);
   if (comm_pkg)
   {
      hypre_CommPkgDestroy(comm_pkg);
   }
   
   hypre_CommPkgCreate(comm_info,
                       hypre_StructMatrixDataSpace(P),
                       hypre_StructMatrixDataSpace(P),
                       hypre_StructMatrixNumValues(P),
                       hypre_StructMatrixComm(P),
                       &comm_pkg);
   hypre_StructMatrixCommPkg(P) = comm_pkg;

   hypre_InitializeCommunication(comm_pkg,
                                 hypre_StructMatrixData(P),
                                 hypre_StructMatrixData(P),
                                 &comm_handle);
   hypre_FinalizeCommunication(comm_handle);

   return hypre_error_flag;
}
