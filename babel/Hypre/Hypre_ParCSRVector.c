
/******************************************************
 *
 *  File:  Hypre_ParCSRVector.c
 *
 *********************************************************/

#include "Hypre_ParCSRVector_Skel.h" 
#include "Hypre_ParCSRVector_Data.h" 

#include <assert.h>
#include "Hypre_MPI_Com_Skel.h"
#include "Hypre_MPI_Com_Data.h"
#include "HYPRE_IJ_mv.h"
#include "HYPRE_IJ_mv.h"
#include "IJ_matrix_vector.h"
#include "parcsr_matrix_vector.h"
#include "Hypre_ParCSRVectorBuilder.h"
#include "HYPRE.h"

/* *************************************************
 * Constructor
 *    Allocate Memory for private data
 *    and initialize here
 ***************************************************/
void Hypre_ParCSRVector_constructor(Hypre_ParCSRVector this) {
   this->d_table = (struct Hypre_ParCSRVector_private_type *)
      malloc( sizeof( struct Hypre_ParCSRVector_private_type ) );

   this->d_table->Hvec = (HYPRE_IJVector *)
      malloc( sizeof( HYPRE_IJVector ) );

} /* end constructor */

/* *************************************************
 *  Destructor
 *      deallocate memory for private data here.
 * As a ParCSRVector is reference-counted, this function will not normally
 * be called directly by the user.  Use deleteReference.
 ***************************************************/
void Hypre_ParCSRVector_destructor(Hypre_ParCSRVector this) {
   struct Hypre_ParCSRVector_private_type *Vp = this->d_table;
   HYPRE_IJVector *V = Vp->Hvec;

   HYPRE_IJVectorDestroy( *V );

   free(this->d_table);

} /* end destructor */

/* ********************************************************
 * impl_Hypre_ParCSRVectorClear
 *    int Clear ();                          // y <- 0 (where y=self)
 *       Note that this and most other vector operations are local (only
 * one processor involved).
 **********************************************************/
int  impl_Hypre_ParCSRVector_Clear(Hypre_ParCSRVector this) {
   struct Hypre_ParCSRVector_private_type *Vp = this->d_table;
   HYPRE_IJVector *V = Vp->Hvec;
   return HYPRE_IJVectorZeroLocalComponents( *V );
} /* end impl_Hypre_ParCSRVectorClear */

/* ********************************************************
 * impl_Hypre_ParCSRVectorCopy
 *    int Copy (in Vector x);                // y <- x
 * The data is copied; it is assumed (without checking) that the vectors already
 * have the same size, distribution, etc.
 **********************************************************/
int  impl_Hypre_ParCSRVector_Copy(Hypre_ParCSRVector this, Hypre_Vector x) {
   int ierr = 0;
   struct Hypre_ParCSRVector_private_type *HPy = this->d_table;
   HYPRE_IJVector *Hy = HPy->Hvec;
   hypre_IJVector *hy = (hypre_IJVector *) Hy;
   hypre_ParVector *y_par = hypre_IJVectorLocalStorage(hy);

   Hypre_ParCSRVector xin;
   struct Hypre_ParCSRVector_private_type *HPx;
   HYPRE_IJVector *Hx;
   hypre_IJVector *hx;
   hypre_ParVector *x_par;

   xin = (Hypre_ParCSRVector) Hypre_Vector_castTo( x, "Hypre_ParCSRVector" );
   if ( xin==NULL ) return 1;
   HPx = xin->d_table;
   Hx = HPx->Hvec;
   hx = (hypre_IJVector *) Hx;
   x_par = hypre_IJVectorLocalStorage(hx);

   ierr = hypre_ParVectorCopy( x_par, y_par );
   return ierr;

} /* end impl_Hypre_ParCSRVectorCopy */

/* ********************************************************
 * impl_Hypre_ParCSRVectorClone
 *    int Clone (out Vector x);              // create an x compatible with y
 * The data is not copied.
 **********************************************************/
int  impl_Hypre_ParCSRVector_Clone(Hypre_ParCSRVector this, Hypre_Vector* x) {
   int ierr = 0;
   int num_procs;
   struct Hypre_ParCSRVector_private_type *HPy = this->d_table;
   HYPRE_IJVector *Hy = HPy->Hvec;
   hypre_IJVector *hy = (hypre_IJVector *) Hy;
   int global_n = hypre_IJVectorN(hy); 

   Hypre_MPI_Com * comm = HPy->comm;
   MPI_Comm * MCp = (*comm)->d_table->hcom;

   /* To build the new x, we first need to build a builder...*/
   Hypre_ParCSRVectorBuilder Bldr = Hypre_ParCSRVectorBuilder_Constructor( *comm, 0 );

   array1int partitioning;

   ierr += impl_Hypre_ParCSRVectorBuilder_New( Bldr, *comm, global_n );

   /* copy partitioning from y to x ... */
   MPI_Comm_size( *MCp, &num_procs );
   partitioning.lower[0] = 0;
   partitioning.upper[0] = num_procs;
   partitioning.data = hypre_CTAlloc( int, num_procs );
   ierr +=  Hypre_ParCSRVector_GetPartitioning( this, partitioning );
   ierr +=  Hypre_ParCSRVectorBuilder_SetPartitioning( Bldr, partitioning );
   hypre_TFree( partitioning.data );

   ierr += Hypre_ParCSRVectorBuilder_Setup( Bldr );
   *x = Hypre_ParCSRVectorBuilder_GetConstructedObject( Bldr );

} /* end impl_Hypre_ParCSRVectorClone */

/* ********************************************************
 * impl_Hypre_ParCSRVectorScale
 *    int Scale (in double a);               // y <- a*y 
 **********************************************************/
int  impl_Hypre_ParCSRVector_Scale( Hypre_ParCSRVector this, double a ) {
   struct Hypre_ParCSRVector_private_type *HPy = this->d_table;
   HYPRE_IJVector *Hy = HPy->Hvec;
   return HYPRE_IJVectorScale( *Hy, a );
} /* end impl_Hypre_ParCSRVectorScale */

/* ********************************************************
 * impl_Hypre_ParCSRVectorDot
 *       Unlike most vector operations, this one is global (affects all processors).
 *    int Dot (in Vector x, out double d);   // d <- (y,x)
 **********************************************************/

double
HYPRE_IJVectorInnerProd( HYPRE_IJVector x, HYPRE_IJVector y );

int  impl_Hypre_ParCSRVector_Dot(Hypre_ParCSRVector this, Hypre_Vector x, double* d) {
   struct Hypre_ParCSRVector_private_type *HPy = this->d_table;
   HYPRE_IJVector *Hy = HPy->Hvec;

   Hypre_ParCSRVector xin;
   struct Hypre_ParCSRVector_private_type *HPx;
   HYPRE_IJVector *Hx;

   xin = (Hypre_ParCSRVector) Hypre_Vector_castTo( x, "Hypre_ParCSRVector" );
   if ( xin==NULL ) return 1;
   HPx = xin->d_table;
   Hx = HPx->Hvec;

   *d = HYPRE_IJVectorInnerProd( *Hx, *Hy );
   return 0;
} /* end impl_Hypre_ParCSRVectorDot */

/* ********************************************************
 * impl_Hypre_ParCSRVectorAxpy
 *    int Axpy (in double a, in Vector x);   // y <- a*x + y
 **********************************************************/
double
HYPRE_IJVectorAxpy( HYPRE_IJVector y, double a, HYPRE_IJVector x );

int  impl_Hypre_ParCSRVector_Axpy( Hypre_ParCSRVector this, double a,
                                   Hypre_Vector x)
{
   struct Hypre_ParCSRVector_private_type *HPy = this->d_table;
   HYPRE_IJVector *Hy = HPy->Hvec;

   Hypre_ParCSRVector xin;
   struct Hypre_ParCSRVector_private_type *HPx;
   HYPRE_IJVector *Hx;

   xin = (Hypre_ParCSRVector) Hypre_Vector_castTo( x, "Hypre_ParCSRVector" );
   if ( xin==NULL ) return 1;
   HPx = xin->d_table;
   Hx = HPx->Hvec;

   return HYPRE_IJVectorAxpy( *Hy, a, *Hx );

} /* end impl_Hypre_ParCSRVectorAxpy */



/* could be in hypre_IJVector_parcsr.c ... */
/******************************************************************************
 * hypre_IJVectorGetPartitioningPar
 * gets IJVectorPar ParVector partitioning
 *****************************************************************************/
int
hypre_IJVectorGetPartitioningPar(hypre_IJVector *vector,
                                 int      *partitioning )
{
   int ierr = 0;
   hypre_ParVector *par_vector = hypre_IJVectorLocalStorage(vector);

   if (!par_vector)
   {
      return 1;
   }
   else
      partitioning = hypre_ParVectorPartitioning(par_vector);

   return ierr;
}

/* could be in hypre_IJVector_parcsr.c ... */
/******************************************************************************
 * hypre_IJVectorAxpy
 * adds a*x to a vector y, where a is a scalar and x a vector
 *****************************************************************************/
double hypre_IJVectorAxpy( hypre_IJVector *y, double a, hypre_IJVector *x )
{
   hypre_ParVector *par_x = hypre_IJVectorLocalStorage( x );
   hypre_ParVector *par_y = hypre_IJVectorLocalStorage( y );
   assert( par_x );
   assert( par_y );
   return hypre_ParVectorAxpy( a, par_x, par_y );
}

/* could be in hypre_IJVector_parcsr.c ... */
/******************************************************************************
 * hypre_IJVectorInnerProd
 * inner product of two IJVector's
 *****************************************************************************/
double hypre_IJVectorInnerProd( hypre_IJVector *x, hypre_IJVector *y )
{
   hypre_ParVector *par_x = hypre_IJVectorLocalStorage( x );
   hypre_ParVector *par_y = hypre_IJVectorLocalStorage( y );
   assert( par_x );
   assert( par_y );
   return hypre_ParVectorInnerProd( par_x, par_y );
}

/* could be in hypre_IJVector_parcsr.c ... */
/******************************************************************************
 * hypre_IJVectorScalePar
 * multiplies all components in an IJVector by a scalar
 *****************************************************************************/
int
hypre_IJVectorScalePar( hypre_IJVector *vector, double ascale )
{
   hypre_ParVector *par_vector = hypre_IJVectorLocalStorage( vector );
   return hypre_ParVectorScale( ascale, par_vector );

   /* the following code would do the job too ...
   int ierr = 0;
   int my_id;
   int i, j, vec_start, vec_stop, local_n, local_start, local_stop;
   double *data;

   hypre_ParVector *par_vector = hypre_IJVectorLocalStorage( vector );
   MPI_Comm comm = hypre_IJVectorContext( vector );
   int *partitioning = hypre_ParVectorPartitioning( par_vector );
   hypre_Vector *local_vector = hypre_ParVectorLocalVector( par_vector );

   MPI_Comm_rank( comm, &my_id );

   assert(par_vector);
   assert(partitioning);
   assert(local_vector);

   vec_start = partitioning[my_id];
   vec_stop  = partitioning[my_id+1];
   data = hypre_VectorData( local_vector );
   for (i = 0; i < vec_stop - vec_start; i++)
      data[i] *= ascale;
  
   return ierr;
   */
}

/* could be in HYPRE_IJVector.c ... */
/*--------------------------------------------------------------------------
 * HYPRE_IJVectorAxpy
 *--------------------------------------------------------------------------*/
/** 
adds a*x to a vector y, where a is a scalar and x a vector

collective.

@return inner product
@param HYPRE_IJVector &y [INOUT]
vector
@param a
double
@param HYPRE_IJVector &x [IN]
vector

*/
double
HYPRE_IJVectorAxpy( HYPRE_IJVector y, double a, HYPRE_IJVector x )
{
   hypre_IJVector *hx = (hypre_IJVector *) x;
   hypre_IJVector *hy = (hypre_IJVector *) y;

   assert( hypre_IJVectorLocalStorageType( hx ) == HYPRE_PARCSR );
   assert( hypre_IJVectorLocalStorageType( hy ) == HYPRE_PARCSR );
   return hypre_IJVectorAxpy( hy, a, hx );
}

/* could be in HYPRE_IJVector.c ... */
/*--------------------------------------------------------------------------
 * HYPRE_IJVectorInnerProd
 *--------------------------------------------------------------------------*/
/** 
returns the inner product of two vecotrs

collective.

@return inner product
@param HYPRE_IJVector &x [IN]
vector
@param HYPRE_IJVector &y [IN]
vector

*/
double
HYPRE_IJVectorInnerProd( HYPRE_IJVector x, HYPRE_IJVector y )
{
   hypre_IJVector *hx = (hypre_IJVector *) x;
   hypre_IJVector *hy = (hypre_IJVector *) y;

   assert( hypre_IJVectorLocalStorageType( hx ) == HYPRE_PARCSR );
   assert( hypre_IJVectorLocalStorageType( hy ) == HYPRE_PARCSR );
   return hypre_IJVectorInnerProd( hx, hy );
}

/* could be in HYPRE_IJVector.c ... */
/*--------------------------------------------------------------------------
 * HYPRE_IJVectorScale
 *--------------------------------------------------------------------------*/
/** 
multiplies all of the local vector components by a scalar
all indexed coefficients.

Not collective.

@return integer error code
@param HYPRE_IJVector &vector
vector, local components to be rescaled
@param double ascale [IN]
value by which the local vector components are to be multiplied

*/
int 
HYPRE_IJVectorScale( HYPRE_IJVector  IJvector, double ascale )
{
   int ierr = 0;
   hypre_IJVector *vector = (hypre_IJVector *) IJvector;

   if ( hypre_IJVectorLocalStorageType(vector) == HYPRE_PARCSR )
      ierr = hypre_IJVectorScalePar( vector, ascale );
   else
      ierr = -1;

   return(ierr);
}

/* could be in HYPRE_IJVector.c ... */
/*--------------------------------------------------------------------------
 * HYPRE_IJVectorGetPartitioning
 *--------------------------------------------------------------------------*/
/**
@return integer error code
@param HYPRE_IJVector IJvector
vector for which partitioning is to be set
@param int *partitioning [IN]
pointer to array of integers specifying vector decomposition across processors
HYPRE_IJVectorSetLocalStorageType needs to be called before this function.

*/
int 
HYPRE_IJVectorGetPartitioning( HYPRE_IJVector  IJvector,
                               int      *partitioning )
{
   int ierr = 0;
   hypre_IJVector *vector = (hypre_IJVector *) IJvector;

   if ( hypre_IJVectorLocalStorageType(vector) == HYPRE_PARCSR )
   {
      if (!hypre_IJVectorLocalStorage(vector))
	 return 1;
      else
         ierr = hypre_IJVectorGetPartitioningPar(vector, partitioning);
   }
   else
      ++ierr;

   return(ierr);
}



/* Not in SIDL file yet, should be: */
int  impl_Hypre_ParCSRVector_GetPartitioning
( Hypre_ParCSRVector this, array1int partitioning )
{
   int i, p;
   HYPRE_IJVector * Hvec = this->d_table->Hvec;
   int * new_data;

   HYPRE_IJVectorGetPartitioning( *Hvec, new_data );

   i = 0;
   for ( p=*(partitioning.lower); p<*(partitioning.upper); ++p )
   {
      partitioning.data[p] = new_data[i];
      ++i;
   };

} /* end impl_Hypre_ParCSRVectorBuilderSetPartitioning */
