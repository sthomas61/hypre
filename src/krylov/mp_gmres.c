/******************************************************************************
 * Copyright 1998-2019 Lawrence Livermore National Security, LLC and other
 * HYPRE Project Developers. See the top-level COPYRIGHT file for details.
 *
 * SPDX-License-Identifier: (Apache-2.0 OR MIT)
 ******************************************************************************/

#include "_hypre_utilities.h"
#include "krylov.h"



/*--------------------------------------------------------------------------
* *hypre_GMRESCreate
*--------------------------------------------------------------------------*/
void 
*hypre_GMRESCreate( hypre_GMRESFunctions *gmres_functions)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_functions;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESCreate_flt ( gmres_functions);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESCreate_dbl ( gmres_functions);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESCreate_ldbl ( gmres_functions);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return (void*)gmres_data;
}

/*--------------------------------------------------------------------------
* hypre_GMRESDestroy
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESDestroy( void *gmres_vdata)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESDestroy_flt ( gmres_vdata);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESDestroy_dbl ( gmres_vdata);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESDestroy_ldbl ( gmres_vdata);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESGetResidual
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESGetResidual( void *gmres_vdata, void **residual)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESGetResidual_flt ( gmres_vdata, residual);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESGetResidual_dbl ( gmres_vdata, residual);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESGetResidual_ldbl ( gmres_vdata, residual);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESSetup
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESSetup( void *gmres_vdata, void *A, void *b, void *x)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESSetup_flt ( gmres_vdata, A, b, x);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESSetup_dbl ( gmres_vdata, A, b, x);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESSetup_ldbl ( gmres_vdata, A, b, x);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESSolve
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESSolve( void *gmres_vdata, void *A, void *b, void *x)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESSolve_flt ( gmres_vdata, A, b, x);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESSolve_dbl ( gmres_vdata, A, b, x);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESSolve_ldbl ( gmres_vdata, A, b, x);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESSetKDim
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESSetKDim( void *gmres_vdata, HYPRE_Int k_dim)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESSetKDim_flt ( gmres_vdata, k_dim);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESSetKDim_dbl ( gmres_vdata, k_dim);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESSetKDim_ldbl ( gmres_vdata, k_dim);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESGetKDim
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESGetKDim( void *gmres_vdata, HYPRE_Int *k_dim)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESGetKDim_flt ( gmres_vdata, k_dim);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESGetKDim_dbl ( gmres_vdata, k_dim);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESGetKDim_ldbl ( gmres_vdata, k_dim);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESSetTol
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESSetTol( void *gmres_vdata, HYPRE_Real tol)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESSetTol_flt ( gmres_vdata, tol);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESSetTol_dbl ( gmres_vdata, tol);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESSetTol_ldbl ( gmres_vdata, tol);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESGetTol
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESGetTol( void *gmres_vdata, HYPRE_Real *tol)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESGetTol_flt ( gmres_vdata, tol);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESGetTol_dbl ( gmres_vdata, tol);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESGetTol_ldbl ( gmres_vdata, tol);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESSetAbsoluteTol
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESSetAbsoluteTol( void *gmres_vdata, HYPRE_Real a_tol)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESSetAbsoluteTol_flt ( gmres_vdata, a_tol);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESSetAbsoluteTol_dbl ( gmres_vdata, a_tol);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESSetAbsoluteTol_ldbl ( gmres_vdata, a_tol);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESGetAbsoluteTol
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESGetAbsoluteTol( void *gmres_vdata, HYPRE_Real *a_tol)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESGetAbsoluteTol_flt ( gmres_vdata, a_tol);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESGetAbsoluteTol_dbl ( gmres_vdata, a_tol);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESGetAbsoluteTol_ldbl ( gmres_vdata, a_tol);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESSetConvergenceFactorTol
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESSetConvergenceFactorTol( void *gmres_vdata, HYPRE_Real cf_tol)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESSetConvergenceFactorTol_flt ( gmres_vdata, cf_tol);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESSetConvergenceFactorTol_dbl ( gmres_vdata, cf_tol);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESSetConvergenceFactorTol_ldbl ( gmres_vdata, cf_tol);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESGetConvergenceFactorTol
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESGetConvergenceFactorTol( void *gmres_vdata, HYPRE_Real *cf_tol)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESGetConvergenceFactorTol_flt ( gmres_vdata, cf_tol);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESGetConvergenceFactorTol_dbl ( gmres_vdata, cf_tol);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESGetConvergenceFactorTol_ldbl ( gmres_vdata, cf_tol);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESSetMinIter
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESSetMinIter( void *gmres_vdata, HYPRE_Int min_iter)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESSetMinIter_flt ( gmres_vdata, min_iter);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESSetMinIter_dbl ( gmres_vdata, min_iter);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESSetMinIter_ldbl ( gmres_vdata, min_iter);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESGetMinIter
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESGetMinIter( void *gmres_vdata, HYPRE_Int *min_iter)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESGetMinIter_flt ( gmres_vdata, min_iter);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESGetMinIter_dbl ( gmres_vdata, min_iter);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESGetMinIter_ldbl ( gmres_vdata, min_iter);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESSetMaxIter
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESSetMaxIter( void *gmres_vdata, HYPRE_Int max_iter)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESSetMaxIter_flt ( gmres_vdata, max_iter);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESSetMaxIter_dbl ( gmres_vdata, max_iter);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESSetMaxIter_ldbl ( gmres_vdata, max_iter);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESGetMaxIter
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESGetMaxIter( void *gmres_vdata, HYPRE_Int *max_iter)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESGetMaxIter_flt ( gmres_vdata, max_iter);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESGetMaxIter_dbl ( gmres_vdata, max_iter);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESGetMaxIter_ldbl ( gmres_vdata, max_iter);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESSetRelChange
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESSetRelChange( void *gmres_vdata, HYPRE_Int rel_change)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESSetRelChange_flt ( gmres_vdata, rel_change);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESSetRelChange_dbl ( gmres_vdata, rel_change);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESSetRelChange_ldbl ( gmres_vdata, rel_change);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESGetRelChange
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESGetRelChange( void *gmres_vdata, HYPRE_Int *rel_change)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESGetRelChange_flt ( gmres_vdata, rel_change);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESGetRelChange_dbl ( gmres_vdata, rel_change);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESGetRelChange_ldbl ( gmres_vdata, rel_change);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESSetSkipRealResidualCheck
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESSetSkipRealResidualCheck( void *gmres_vdata, HYPRE_Int skip_real_r_check)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESSetSkipRealResidualCheck_flt ( gmres_vdata, skip_real_r_check);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESSetSkipRealResidualCheck_dbl ( gmres_vdata, skip_real_r_check);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESSetSkipRealResidualCheck_ldbl ( gmres_vdata, skip_real_r_check);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESGetSkipRealResidualCheck
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESGetSkipRealResidualCheck( void *gmres_vdata, HYPRE_Int *skip_real_r_check)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESGetSkipRealResidualCheck_flt ( gmres_vdata, skip_real_r_check);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESGetSkipRealResidualCheck_dbl ( gmres_vdata, skip_real_r_check);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESGetSkipRealResidualCheck_ldbl ( gmres_vdata, skip_real_r_check);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESSetStopCrit
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESSetStopCrit( void *gmres_vdata, HYPRE_Int stop_crit)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESSetStopCrit_flt ( gmres_vdata, stop_crit);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESSetStopCrit_dbl ( gmres_vdata, stop_crit);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESSetStopCrit_ldbl ( gmres_vdata, stop_crit);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESGetStopCrit
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESGetStopCrit( void *gmres_vdata, HYPRE_Int *stop_crit)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESGetStopCrit_flt ( gmres_vdata, stop_crit);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESGetStopCrit_dbl ( gmres_vdata, stop_crit);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESGetStopCrit_ldbl ( gmres_vdata, stop_crit);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESSetPrecond
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESSetPrecond(void *gmres_vdata,
 		HYPRE_Int (*precond)(void*,void*,void*,void*),
 		HYPRE_Int (*precond_setup)(void*,void*,void*,void*),
 		void *precond_data)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESSetPrecond_flt (gmres_vdata, precond, precond_setup, precond_data);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESSetPrecond_dbl (gmres_vdata, precond, precond_setup, precond_data);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESSetPrecond_ldbl (gmres_vdata, precond, precond_setup, precond_data);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESGetPrecond
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESGetPrecond( void *gmres_vdata, HYPRE_Solver *precond_data_ptr)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESGetPrecond_flt ( gmres_vdata, precond_data_ptr);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESGetPrecond_dbl ( gmres_vdata, precond_data_ptr);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESGetPrecond_ldbl ( gmres_vdata, precond_data_ptr);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESSetPrintLevel
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESSetPrintLevel( void *gmres_vdata, HYPRE_Int level)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESSetPrintLevel_flt ( gmres_vdata, level);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESSetPrintLevel_dbl ( gmres_vdata, level);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESSetPrintLevel_ldbl ( gmres_vdata, level);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESGetPrintLevel
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESGetPrintLevel( void *gmres_vdata, HYPRE_Int *level)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESGetPrintLevel_flt ( gmres_vdata, level);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESGetPrintLevel_dbl ( gmres_vdata, level);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESGetPrintLevel_ldbl ( gmres_vdata, level);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESSetLogging
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESSetLogging( void *gmres_vdata, HYPRE_Int level)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESSetLogging_flt ( gmres_vdata, level);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESSetLogging_dbl ( gmres_vdata, level);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESSetLogging_ldbl ( gmres_vdata, level);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESGetLogging
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESGetLogging( void *gmres_vdata, HYPRE_Int *level)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESGetLogging_flt ( gmres_vdata, level);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESGetLogging_dbl ( gmres_vdata, level);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESGetLogging_ldbl ( gmres_vdata, level);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESSetHybrid
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESSetHybrid( void *gmres_vdata, HYPRE_Int level)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESSetHybrid_flt ( gmres_vdata, level);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESSetHybrid_dbl ( gmres_vdata, level);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESSetHybrid_ldbl ( gmres_vdata, level);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESGetNumIterations
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESGetNumIterations( void *gmres_vdata, HYPRE_Int *num_iterations)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESGetNumIterations_flt ( gmres_vdata, num_iterations);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESGetNumIterations_dbl ( gmres_vdata, num_iterations);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESGetNumIterations_ldbl ( gmres_vdata, num_iterations);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESGetConverged
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESGetConverged( void *gmres_vdata, HYPRE_Int *converged)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESGetConverged_flt ( gmres_vdata, converged);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESGetConverged_dbl ( gmres_vdata, converged);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESGetConverged_ldbl ( gmres_vdata, converged);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
* hypre_GMRESGetFinalRelativeResidualNorm
*--------------------------------------------------------------------------*/
HYPRE_Int 
hypre_GMRESGetFinalRelativeResidualNorm( void *gmres_vdata, HYPRE_Real *relative_residual_norm)
{
   hypre_GMRESData *gmres_data = (hypre_GMRESData *)gmres_vdata;
   switch (gmres_data-> solver_precision)
   {
      case HYPRE_REAL_SINGLE:
         hypre_GMRESGetFinalRelativeResidualNorm_flt ( gmres_vdata, relative_residual_norm);
         break;
      case HYPRE_REAL_DOUBLE:
         hypre_GMRESGetFinalRelativeResidualNorm_dbl ( gmres_vdata, relative_residual_norm);
         break;
      case HYPRE_REAL_LONGDOUBLE:
         hypre_GMRESGetFinalRelativeResidualNorm_ldbl ( gmres_vdata, relative_residual_norm);
         break;
      default:
         hypre_printf("Unknown solver precision" );
   }
   return hypre_error_flag;
}
