/*
 * File:          Hypre_StructSMG_Impl.h
 * Symbol:        Hypre.StructSMG-v0.1.5
 * Symbol Type:   class
 * Babel Version: 0.6.1
 * SIDL Created:  20020104 15:27:10 PST
 * Generated:     20020104 15:27:19 PST
 * Description:   Server-side implementation for Hypre.StructSMG
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

#ifndef included_Hypre_StructSMG_Impl_h
#define included_Hypre_StructSMG_Impl_h

#ifndef included_SIDL_header_h
#include "SIDL_header.h"
#endif
#ifndef included_Hypre_Vector_h
#include "Hypre_Vector.h"
#endif
#ifndef included_Hypre_StructSMG_h
#include "Hypre_StructSMG.h"
#endif
#ifndef included_Hypre_Operator_h
#include "Hypre_Operator.h"
#endif

/* DO-NOT-DELETE splicer.begin(Hypre.StructSMG._includes) */
/* Put additional include files here... */
/* DO-NOT-DELETE splicer.end(Hypre.StructSMG._includes) */

/*
 * Private data for class Hypre.StructSMG
 */

struct Hypre_StructSMG__data {
  /* DO-NOT-DELETE splicer.begin(Hypre.StructSMG._data) */
  /* Put private data members here... */
  int ignore; /* dummy to force non-empty struct; remove if you add data */
  /* DO-NOT-DELETE splicer.end(Hypre.StructSMG._data) */
};

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Access functions for class private data and built-in methods
 */

extern struct Hypre_StructSMG__data*
Hypre_StructSMG__get_data(
  Hypre_StructSMG);

extern void
Hypre_StructSMG__set_data(
  Hypre_StructSMG,
  struct Hypre_StructSMG__data*);

extern void
impl_Hypre_StructSMG__ctor(
  Hypre_StructSMG);

extern void
impl_Hypre_StructSMG__dtor(
  Hypre_StructSMG);

/*
 * User-defined object methods
 */

extern int32_t
impl_Hypre_StructSMG_Apply(
  Hypre_StructSMG,
  Hypre_Vector,
  Hypre_Vector*);

extern int32_t
impl_Hypre_StructSMG_GetResidual(
  Hypre_StructSMG,
  Hypre_Vector*);

extern int32_t
impl_Hypre_StructSMG_SetCommunicator(
  Hypre_StructSMG,
  void*);

extern int32_t
impl_Hypre_StructSMG_SetOperator(
  Hypre_StructSMG,
  Hypre_Operator);

extern int32_t
impl_Hypre_StructSMG_SetParameter(
  Hypre_StructSMG,
  const char*,
  double);

extern int32_t
impl_Hypre_StructSMG_Setup(
  Hypre_StructSMG);

#ifdef __cplusplus
}
#endif
#endif
