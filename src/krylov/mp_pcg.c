/******************************************************************************
 * Copyright 1998-2019 Lawrence Livermore National Security, LLC and other
 * HYPRE Project Developers. See the top-level COPYRIGHT file for details.
 *
 * SPDX-License-Identifier: (Apache-2.0 OR MIT)
 ******************************************************************************/

#include "_hypre_utilities.h"
#include "krylov.h"

/*** NOTE: The functions in this file are only built when Mixed-Precision is enabled ***/

/*--------------------------------------------------------------------------
* *hypre_PCGCreate
*--------------------------------------------------------------------------*/
void 
*hypre_PCGCreate( hypre_PCGFunctions *pcg_functions, HYPRE_Precision solver_precision)
{
   hypre_PCGData *pcg_data;
   switch (solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         pcg_data = (hypre_PCGData *)hypre_PCGCreate_flt ( pcg_functions);
         break;
      case HYPRE_REAL_DOUBLE:
         pcg_data = (hypre_PCGData *)hypre_PCGCreate_dbl ( pcg_functions);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         pcg_data = (hypre_PCGData *)hypre_PCGCreate_ldbl ( pcg_functions);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   /* set solver precision for solver data */
   pcg_data->solver_precision = solver_precision;
   return (void*)pcg_data;
}

/*--------------------------------------------------------------------------
* hypre_PCGDestroy
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGDestroy( void *pcg_vdata)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGDestroy_flt ( pcg_vdata);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGDestroy_dbl ( pcg_vdata);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGDestroy_ldbl ( pcg_vdata);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGGetResidual
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGGetResidual( void *pcg_vdata, void **residual)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGGetResidual_flt ( pcg_vdata, residual);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGGetResidual_dbl ( pcg_vdata, residual);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGGetResidual_ldbl ( pcg_vdata, residual);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGSetup
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGSetup( void *pcg_vdata, void *A, void *b, void *x)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGSetup_flt ( pcg_vdata, A, b, x);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGSetup_dbl ( pcg_vdata, A, b, x);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGSetup_ldbl ( pcg_vdata, A, b, x);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGSolve
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGSolve( void *pcg_vdata, void *A, void *b, void *x)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGSolve_flt ( pcg_vdata, A, b, x);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGSolve_dbl ( pcg_vdata, A, b, x);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGSolve_ldbl ( pcg_vdata, A, b, x);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGSetTol
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGSetTol( void *pcg_vdata, HYPRE_Real tol)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGSetTol_flt ( pcg_vdata, tol);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGSetTol_dbl ( pcg_vdata, tol);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGSetTol_ldbl ( pcg_vdata, tol);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGGetTol
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGGetTol( void *pcg_vdata, HYPRE_Real *tol)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGGetTol_flt ( pcg_vdata, tol);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGGetTol_dbl ( pcg_vdata, tol);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGGetTol_ldbl ( pcg_vdata, tol);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGSetAbsoluteTol
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGSetAbsoluteTol( void *pcg_vdata, HYPRE_Real a_tol)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGSetAbsoluteTol_flt ( pcg_vdata, a_tol);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGSetAbsoluteTol_dbl ( pcg_vdata, a_tol);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGSetAbsoluteTol_ldbl ( pcg_vdata, a_tol);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGGetAbsoluteTol
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGGetAbsoluteTol( void *pcg_vdata, HYPRE_Real *a_tol)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGGetAbsoluteTol_flt ( pcg_vdata, a_tol);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGGetAbsoluteTol_dbl ( pcg_vdata, a_tol);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGGetAbsoluteTol_ldbl ( pcg_vdata, a_tol);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGSetAbsoluteTolFactor
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGSetAbsoluteTolFactor( void *pcg_vdata, HYPRE_Real atolf)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGSetAbsoluteTolFactor_flt ( pcg_vdata, atolf);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGSetAbsoluteTolFactor_dbl ( pcg_vdata, atolf);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGSetAbsoluteTolFactor_ldbl ( pcg_vdata, atolf);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGGetAbsoluteTolFactor
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGGetAbsoluteTolFactor( void *pcg_vdata, HYPRE_Real *atolf)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGGetAbsoluteTolFactor_flt ( pcg_vdata, atolf);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGGetAbsoluteTolFactor_dbl ( pcg_vdata, atolf);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGGetAbsoluteTolFactor_ldbl ( pcg_vdata, atolf);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGSetResidualTol
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGSetResidualTol( void *pcg_vdata, HYPRE_Real rtol)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGSetResidualTol_flt ( pcg_vdata, rtol);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGSetResidualTol_dbl ( pcg_vdata, rtol);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGSetResidualTol_ldbl ( pcg_vdata, rtol);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGGetResidualTol
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGGetResidualTol( void *pcg_vdata, HYPRE_Real *rtol)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGGetResidualTol_flt ( pcg_vdata, rtol);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGGetResidualTol_dbl ( pcg_vdata, rtol);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGGetResidualTol_ldbl ( pcg_vdata, rtol);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGSetConvergenceFactorTol
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGSetConvergenceFactorTol( void *pcg_vdata, HYPRE_Real cf_tol)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGSetConvergenceFactorTol_flt ( pcg_vdata, cf_tol);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGSetConvergenceFactorTol_dbl ( pcg_vdata, cf_tol);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGSetConvergenceFactorTol_ldbl ( pcg_vdata, cf_tol);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGGetConvergenceFactorTol
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGGetConvergenceFactorTol( void *pcg_vdata, HYPRE_Real *cf_tol)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGGetConvergenceFactorTol_flt ( pcg_vdata, cf_tol);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGGetConvergenceFactorTol_dbl ( pcg_vdata, cf_tol);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGGetConvergenceFactorTol_ldbl ( pcg_vdata, cf_tol);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGSetMaxIter
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGSetMaxIter( void *pcg_vdata, HYPRE_Int max_iter)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGSetMaxIter_flt ( pcg_vdata, max_iter);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGSetMaxIter_dbl ( pcg_vdata, max_iter);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGSetMaxIter_ldbl ( pcg_vdata, max_iter);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGGetMaxIter
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGGetMaxIter( void *pcg_vdata, HYPRE_Int *max_iter)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGGetMaxIter_flt ( pcg_vdata, max_iter);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGGetMaxIter_dbl ( pcg_vdata, max_iter);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGGetMaxIter_ldbl ( pcg_vdata, max_iter);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGSetTwoNorm
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGSetTwoNorm( void *pcg_vdata, HYPRE_Int two_norm)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGSetTwoNorm_flt ( pcg_vdata, two_norm);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGSetTwoNorm_dbl ( pcg_vdata, two_norm);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGSetTwoNorm_ldbl ( pcg_vdata, two_norm);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGGetTwoNorm
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGGetTwoNorm( void *pcg_vdata, HYPRE_Int *two_norm)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGGetTwoNorm_flt ( pcg_vdata, two_norm);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGGetTwoNorm_dbl ( pcg_vdata, two_norm);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGGetTwoNorm_ldbl ( pcg_vdata, two_norm);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGSetRelChange
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGSetRelChange( void *pcg_vdata, HYPRE_Int rel_change)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGSetRelChange_flt ( pcg_vdata, rel_change);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGSetRelChange_dbl ( pcg_vdata, rel_change);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGSetRelChange_ldbl ( pcg_vdata, rel_change);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGGetRelChange
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGGetRelChange( void *pcg_vdata, HYPRE_Int *rel_change)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGGetRelChange_flt ( pcg_vdata, rel_change);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGGetRelChange_dbl ( pcg_vdata, rel_change);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGGetRelChange_ldbl ( pcg_vdata, rel_change);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGSetRecomputeResidual
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGSetRecomputeResidual( void *pcg_vdata, HYPRE_Int recompute_residual)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGSetRecomputeResidual_flt ( pcg_vdata, recompute_residual);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGSetRecomputeResidual_dbl ( pcg_vdata, recompute_residual);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGSetRecomputeResidual_ldbl ( pcg_vdata, recompute_residual);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGGetRecomputeResidual
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGGetRecomputeResidual( void *pcg_vdata, HYPRE_Int *recompute_residual)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGGetRecomputeResidual_flt ( pcg_vdata, recompute_residual);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGGetRecomputeResidual_dbl ( pcg_vdata, recompute_residual);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGGetRecomputeResidual_ldbl ( pcg_vdata, recompute_residual);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGSetRecomputeResidualP
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGSetRecomputeResidualP( void *pcg_vdata, HYPRE_Int recompute_residual_p)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGSetRecomputeResidualP_flt ( pcg_vdata, recompute_residual_p);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGSetRecomputeResidualP_dbl ( pcg_vdata, recompute_residual_p);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGSetRecomputeResidualP_ldbl ( pcg_vdata, recompute_residual_p);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGGetRecomputeResidualP
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGGetRecomputeResidualP( void *pcg_vdata, HYPRE_Int *recompute_residual_p)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGGetRecomputeResidualP_flt ( pcg_vdata, recompute_residual_p);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGGetRecomputeResidualP_dbl ( pcg_vdata, recompute_residual_p);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGGetRecomputeResidualP_ldbl ( pcg_vdata, recompute_residual_p);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGSetStopCrit
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGSetStopCrit( void *pcg_vdata, HYPRE_Int stop_crit)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGSetStopCrit_flt ( pcg_vdata, stop_crit);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGSetStopCrit_dbl ( pcg_vdata, stop_crit);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGSetStopCrit_ldbl ( pcg_vdata, stop_crit);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGGetStopCrit
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGGetStopCrit( void *pcg_vdata, HYPRE_Int *stop_crit)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGGetStopCrit_flt ( pcg_vdata, stop_crit);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGGetStopCrit_dbl ( pcg_vdata, stop_crit);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGGetStopCrit_ldbl ( pcg_vdata, stop_crit);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGGetPrecond
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGGetPrecond( void *pcg_vdata, HYPRE_Solver *precond_data_ptr)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGGetPrecond_flt ( pcg_vdata, precond_data_ptr);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGGetPrecond_dbl ( pcg_vdata, precond_data_ptr);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGGetPrecond_ldbl ( pcg_vdata, precond_data_ptr);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGSetPrecond
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGSetPrecond(void *pcg_vdata,
 		HYPRE_Int (*precond)(void*,void*,void*,void*),
 		HYPRE_Int (*precond_setup)(void*,void*,void*,void*),
 		void *precond_data)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGSetPrecond_flt (pcg_vdata, precond, precond_setup, precond_data);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGSetPrecond_dbl (pcg_vdata, precond, precond_setup, precond_data);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGSetPrecond_ldbl (pcg_vdata, precond, precond_setup, precond_data);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGSetPrintLevel
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGSetPrintLevel( void *pcg_vdata, HYPRE_Int level)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGSetPrintLevel_flt ( pcg_vdata, level);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGSetPrintLevel_dbl ( pcg_vdata, level);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGSetPrintLevel_ldbl ( pcg_vdata, level);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGGetPrintLevel
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGGetPrintLevel( void *pcg_vdata, HYPRE_Int *level)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGGetPrintLevel_flt ( pcg_vdata, level);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGGetPrintLevel_dbl ( pcg_vdata, level);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGGetPrintLevel_ldbl ( pcg_vdata, level);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGSetLogging
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGSetLogging( void *pcg_vdata, HYPRE_Int level)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGSetLogging_flt ( pcg_vdata, level);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGSetLogging_dbl ( pcg_vdata, level);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGSetLogging_ldbl ( pcg_vdata, level);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGGetLogging
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGGetLogging( void *pcg_vdata, HYPRE_Int *level)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGGetLogging_flt ( pcg_vdata, level);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGGetLogging_dbl ( pcg_vdata, level);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGGetLogging_ldbl ( pcg_vdata, level);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGSetHybrid
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGSetHybrid( void *pcg_vdata, HYPRE_Int level)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGSetHybrid_flt ( pcg_vdata, level);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGSetHybrid_dbl ( pcg_vdata, level);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGSetHybrid_ldbl ( pcg_vdata, level);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGGetNumIterations
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGGetNumIterations( void *pcg_vdata, HYPRE_Int *num_iterations)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGGetNumIterations_flt ( pcg_vdata, num_iterations);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGGetNumIterations_dbl ( pcg_vdata, num_iterations);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGGetNumIterations_ldbl ( pcg_vdata, num_iterations);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGGetConverged
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGGetConverged( void *pcg_vdata, HYPRE_Int *converged)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGGetConverged_flt ( pcg_vdata, converged);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGGetConverged_dbl ( pcg_vdata, converged);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGGetConverged_ldbl ( pcg_vdata, converged);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGPrintLogging
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGPrintLogging( void *pcg_vdata, HYPRE_Int myid)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGPrintLogging_flt ( pcg_vdata, myid);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGPrintLogging_dbl ( pcg_vdata, myid);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGPrintLogging_ldbl ( pcg_vdata, myid);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_PCGGetFinalRelativeResidualNorm
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_PCGGetFinalRelativeResidualNorm( void *pcg_vdata, HYPRE_Real *relative_residual_norm)
{
   hypre_PCGData *pcg_data = (hypre_PCGData *)pcg_vdata;
   switch (pcg_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_PCGGetFinalRelativeResidualNorm_flt ( pcg_vdata, relative_residual_norm);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_PCGGetFinalRelativeResidualNorm_dbl ( pcg_vdata, relative_residual_norm);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_PCGGetFinalRelativeResidualNorm_ldbl ( pcg_vdata, relative_residual_norm);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}
