/*
 * File:          Hypre_GMRES_IOR.c
 * Symbol:        Hypre.GMRES-v0.1.5
 * Symbol Type:   class
 * Babel Version: 0.6.1
 * SIDL Created:  20020104 15:27:10 PST
 * Generated:     20020104 15:27:14 PST
 * Description:   Intermediate Object Representation for Hypre.GMRES
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "Hypre_GMRES_IOR.h"

#ifndef NULL
#define NULL 0
#endif

/*
 * Static variables for managing EPV initialization.
 */

static int s_method_initialized = 0;
static int s_remote_initialized = 0;

static struct Hypre_GMRES__epv s_new__hypre_gmres;
static struct Hypre_GMRES__epv s_rem__hypre_gmres;

static struct Hypre_Operator__epv s_new__hypre_operator;
static struct Hypre_Operator__epv s_rem__hypre_operator;

static struct Hypre_PreconditionedSolver__epv s_new__hypre_preconditionedsolver;
static struct Hypre_PreconditionedSolver__epv s_rem__hypre_preconditionedsolver;

static struct Hypre_Solver__epv s_new__hypre_solver;
static struct Hypre_Solver__epv s_rem__hypre_solver;

static struct SIDL_BaseClass__epv  s_new__sidl_baseclass;
static struct SIDL_BaseClass__epv* s_old__sidl_baseclass;
static struct SIDL_BaseClass__epv  s_rem__sidl_baseclass;

static struct SIDL_BaseInterface__epv  s_new__sidl_baseinterface;
static struct SIDL_BaseInterface__epv* s_old__sidl_baseinterface;
static struct SIDL_BaseInterface__epv  s_rem__sidl_baseinterface;

/*
 * Declare EPV routines defined in the skeleton file.
 */

extern void Hypre_GMRES__set_epv(
  struct Hypre_GMRES__epv* epv);

/*
 * CAST: dynamic type casting support.
 */

static void* Hypre_GMRES__cast(
  struct Hypre_GMRES__object* self,
  const char* name)
{
  void* cast = NULL;

  struct Hypre_GMRES__object*    s0 = self;
  struct SIDL_BaseClass__object* s1 = &s0->d_sidl_baseclass;

  if (!strcmp(name, "Hypre.GMRES")) {
    cast = (void*) s0;
  } else if (!strcmp(name, "Hypre.Operator")) {
    cast = (void*) &s0->d_hypre_operator;
  } else if (!strcmp(name, "Hypre.PreconditionedSolver")) {
    cast = (void*) &s0->d_hypre_preconditionedsolver;
  } else if (!strcmp(name, "Hypre.Solver")) {
    cast = (void*) &s0->d_hypre_solver;
  } else if (!strcmp(name, "SIDL.BaseClass")) {
    cast = (void*) s1;
  } else if (!strcmp(name, "SIDL.BaseInterface")) {
    cast = (void*) &s1->d_sidl_baseinterface;
  }

  return cast;
}

/*
 * DELETE: call destructor and free object memory.
 */

static void Hypre_GMRES__delete(
  struct Hypre_GMRES__object* self)
{
  Hypre_GMRES__fini(self);
  memset((void*)self, 0, sizeof(struct Hypre_GMRES__object));
  free((void*) self);
}

/*
 * EPV: create method entry point vector (EPV) structure.
 */

static void Hypre_GMRES__init_epv(
  struct Hypre_GMRES__object* self)
{
  struct Hypre_GMRES__object*    s0 = self;
  struct SIDL_BaseClass__object* s1 = &s0->d_sidl_baseclass;

  struct Hypre_GMRES__epv*                epv = &s_new__hypre_gmres;
  struct Hypre_Operator__epv*             e0  = &s_new__hypre_operator;
  struct Hypre_PreconditionedSolver__epv* e1  = 
    &s_new__hypre_preconditionedsolver;
  struct Hypre_Solver__epv*               e2  = &s_new__hypre_solver;
  struct SIDL_BaseClass__epv*             e3  = &s_new__sidl_baseclass;
  struct SIDL_BaseInterface__epv*         e4  = &s_new__sidl_baseinterface;

  s_old__sidl_baseinterface = s1->d_sidl_baseinterface.d_epv;
  s_old__sidl_baseclass     = s1->d_epv;

  epv->f__cast                     = Hypre_GMRES__cast;
  epv->f__delete                   = Hypre_GMRES__delete;
  epv->f__ctor                     = NULL;
  epv->f__dtor                     = NULL;
  epv->f_Apply                     = NULL;
  epv->f_GetPreconditionedResidual = NULL;
  epv->f_GetResidual               = NULL;
  epv->f_SetCommunicator           = NULL;
  epv->f_SetOperator               = NULL;
  epv->f_SetParameter              = NULL;
  epv->f_SetPreconditioner         = NULL;
  epv->f_Setup                     = NULL;
  epv->f_addReference              = (void (*)(struct Hypre_GMRES__object*)) 
    s1->d_epv->f_addReference;
  epv->f_deleteReference           = (void (*)(struct Hypre_GMRES__object*)) 
    s1->d_epv->f_deleteReference;
  epv->f_isInstanceOf              = (SIDL_bool (*)(struct Hypre_GMRES__object*,
    const char*)) s1->d_epv->f_isInstanceOf;
  epv->f_isSame                    = (SIDL_bool (*)(struct Hypre_GMRES__object*,
    struct SIDL_BaseInterface__object*)) s1->d_epv->f_isSame;
  epv->f_queryInterface            = (struct SIDL_BaseInterface__object* 
    (*)(struct Hypre_GMRES__object*,const char*)) s1->d_epv->f_queryInterface;

  Hypre_GMRES__set_epv(epv);

  e0->f__cast           = (void* (*)(void*,const char*)) epv->f__cast;
  e0->f__delete         = (void (*)(void*)) epv->f__delete;
  e0->f_Apply           = (int32_t (*)(void*,struct Hypre_Vector__object*,
    struct Hypre_Vector__object**)) epv->f_Apply;
  e0->f_SetCommunicator = (int32_t (*)(void*,void*)) epv->f_SetCommunicator;
  e0->f_SetParameter    = (int32_t (*)(void*,const char*,
    double)) epv->f_SetParameter;
  e0->f_Setup           = (int32_t (*)(void*)) epv->f_Setup;
  e0->f_addReference    = (void (*)(void*)) epv->f_addReference;
  e0->f_deleteReference = (void (*)(void*)) epv->f_deleteReference;
  e0->f_isInstanceOf    = (SIDL_bool (*)(void*,
    const char*)) epv->f_isInstanceOf;
  e0->f_isSame          = (SIDL_bool (*)(void*,
    struct SIDL_BaseInterface__object*)) epv->f_isSame;
  e0->f_queryInterface  = (struct SIDL_BaseInterface__object* (*)(void*,
    const char*)) epv->f_queryInterface;

  e1->f__cast                     = (void* (*)(void*,const char*)) epv->f__cast;
  e1->f__delete                   = (void (*)(void*)) epv->f__delete;
  e1->f_Apply                     = (int32_t (*)(void*,
    struct Hypre_Vector__object*,struct Hypre_Vector__object**)) epv->f_Apply;
  e1->f_GetPreconditionedResidual = (int32_t (*)(void*,
    struct Hypre_Vector__object**)) epv->f_GetPreconditionedResidual;
  e1->f_GetResidual               = (int32_t (*)(void*,
    struct Hypre_Vector__object**)) epv->f_GetResidual;
  e1->f_SetCommunicator           = (int32_t (*)(void*,
    void*)) epv->f_SetCommunicator;
  e1->f_SetOperator               = (int32_t (*)(void*,
    struct Hypre_Operator__object*)) epv->f_SetOperator;
  e1->f_SetParameter              = (int32_t (*)(void*,const char*,
    double)) epv->f_SetParameter;
  e1->f_SetPreconditioner         = (int32_t (*)(void*,
    struct Hypre_Solver__object*)) epv->f_SetPreconditioner;
  e1->f_Setup                     = (int32_t (*)(void*)) epv->f_Setup;
  e1->f_addReference              = (void (*)(void*)) epv->f_addReference;
  e1->f_deleteReference           = (void (*)(void*)) epv->f_deleteReference;
  e1->f_isInstanceOf              = (SIDL_bool (*)(void*,
    const char*)) epv->f_isInstanceOf;
  e1->f_isSame                    = (SIDL_bool (*)(void*,
    struct SIDL_BaseInterface__object*)) epv->f_isSame;
  e1->f_queryInterface            = (struct SIDL_BaseInterface__object* 
    (*)(void*,const char*)) epv->f_queryInterface;

  e2->f__cast           = (void* (*)(void*,const char*)) epv->f__cast;
  e2->f__delete         = (void (*)(void*)) epv->f__delete;
  e2->f_Apply           = (int32_t (*)(void*,struct Hypre_Vector__object*,
    struct Hypre_Vector__object**)) epv->f_Apply;
  e2->f_GetResidual     = (int32_t (*)(void*,
    struct Hypre_Vector__object**)) epv->f_GetResidual;
  e2->f_SetCommunicator = (int32_t (*)(void*,void*)) epv->f_SetCommunicator;
  e2->f_SetOperator     = (int32_t (*)(void*,
    struct Hypre_Operator__object*)) epv->f_SetOperator;
  e2->f_SetParameter    = (int32_t (*)(void*,const char*,
    double)) epv->f_SetParameter;
  e2->f_Setup           = (int32_t (*)(void*)) epv->f_Setup;
  e2->f_addReference    = (void (*)(void*)) epv->f_addReference;
  e2->f_deleteReference = (void (*)(void*)) epv->f_deleteReference;
  e2->f_isInstanceOf    = (SIDL_bool (*)(void*,
    const char*)) epv->f_isInstanceOf;
  e2->f_isSame          = (SIDL_bool (*)(void*,
    struct SIDL_BaseInterface__object*)) epv->f_isSame;
  e2->f_queryInterface  = (struct SIDL_BaseInterface__object* (*)(void*,
    const char*)) epv->f_queryInterface;

  e3->f__cast           = (void* (*)(struct SIDL_BaseClass__object*,
    const char*)) epv->f__cast;
  e3->f__delete         = (void (*)(struct SIDL_BaseClass__object*)) 
    epv->f__delete;
  e3->f_addReference    = (void (*)(struct SIDL_BaseClass__object*)) 
    epv->f_addReference;
  e3->f_deleteReference = (void (*)(struct SIDL_BaseClass__object*)) 
    epv->f_deleteReference;
  e3->f_isInstanceOf    = (SIDL_bool (*)(struct SIDL_BaseClass__object*,
    const char*)) epv->f_isInstanceOf;
  e3->f_isSame          = (SIDL_bool (*)(struct SIDL_BaseClass__object*,
    struct SIDL_BaseInterface__object*)) epv->f_isSame;
  e3->f_queryInterface  = (struct SIDL_BaseInterface__object* (*)(struct 
    SIDL_BaseClass__object*,const char*)) epv->f_queryInterface;

  e4->f__cast           = (void* (*)(void*,const char*)) epv->f__cast;
  e4->f__delete         = (void (*)(void*)) epv->f__delete;
  e4->f_addReference    = (void (*)(void*)) epv->f_addReference;
  e4->f_deleteReference = (void (*)(void*)) epv->f_deleteReference;
  e4->f_isInstanceOf    = (SIDL_bool (*)(void*,
    const char*)) epv->f_isInstanceOf;
  e4->f_isSame          = (SIDL_bool (*)(void*,
    struct SIDL_BaseInterface__object*)) epv->f_isSame;
  e4->f_queryInterface  = (struct SIDL_BaseInterface__object* (*)(void*,
    const char*)) epv->f_queryInterface;

  s_method_initialized = 1;
}

/*
 * NEW: allocate object and initialize it.
 */

struct Hypre_GMRES__object*
Hypre_GMRES__new(void)
{
  struct Hypre_GMRES__object* self =
    (struct Hypre_GMRES__object*) malloc(
      sizeof(struct Hypre_GMRES__object));
  Hypre_GMRES__init(self);
  return self;
}

/*
 * INIT: initialize a new instance of the class object.
 */

void Hypre_GMRES__init(
  struct Hypre_GMRES__object* self)
{
  struct Hypre_GMRES__object*    s0 = self;
  struct SIDL_BaseClass__object* s1 = &s0->d_sidl_baseclass;

  SIDL_BaseClass__init(s1);

  if (!s_method_initialized) {
    Hypre_GMRES__init_epv(s0);
  }

  s1->d_sidl_baseinterface.d_epv = &s_new__sidl_baseinterface;
  s1->d_epv                      = &s_new__sidl_baseclass;

  s0->d_hypre_operator.d_epv             = &s_new__hypre_operator;
  s0->d_hypre_preconditionedsolver.d_epv = &s_new__hypre_preconditionedsolver;
  s0->d_hypre_solver.d_epv               = &s_new__hypre_solver;
  s0->d_epv                              = &s_new__hypre_gmres;

  s0->d_hypre_operator.d_object = self;

  s0->d_hypre_preconditionedsolver.d_object = self;

  s0->d_hypre_solver.d_object = self;

  s0->d_data = NULL;

  (*(self->d_epv->f__ctor))(self);
}

/*
 * FINI: deallocate a class instance (destructor).
 */

void Hypre_GMRES__fini(
  struct Hypre_GMRES__object* self)
{
  struct Hypre_GMRES__object*    s0 = self;
  struct SIDL_BaseClass__object* s1 = &s0->d_sidl_baseclass;

  (*(s0->d_epv->f__dtor))(s0);

  s1->d_sidl_baseinterface.d_epv = s_old__sidl_baseinterface;
  s1->d_epv                      = s_old__sidl_baseclass;

  SIDL_BaseClass__fini(s1);
}

/*
 * Define the IOR array structure.
 * Macros to read this are defined in SIDLArray.h
 */

struct Hypre_GMRES__array {
  struct Hypre_GMRES__object** d_firstElement;
  int32_t                      *d_lower;
  int32_t                      *d_upper;
  int32_t                      *d_stride;
  SIDL_bool                    d_borrowed;
  int32_t                      d_dimen;
};

static struct Hypre_GMRES__array*
newArray(int32_t dimen, const int32_t lower[], const int32_t upper[]) {
  static const size_t arraySize = sizeof(struct Hypre_GMRES__array)
    + (sizeof(int32_t) - (sizeof(struct Hypre_GMRES__array)
    % sizeof(int32_t))) % sizeof(int32_t);
  struct Hypre_GMRES__array *result =
    (struct Hypre_GMRES__array *)
    malloc(arraySize + 3 * sizeof(int32_t) * dimen);
  result->d_dimen = dimen;
  result->d_borrowed = 0;
  result->d_lower = (int32_t *)((char *)result + arraySize);
  result->d_upper = result->d_lower + dimen;
  result->d_stride = result->d_upper + dimen;
  memcpy(result->d_lower, lower, sizeof(int32_t)*dimen);
  memcpy(result->d_upper, upper, sizeof(int32_t)*dimen);
  return result;
}

/*
 * Create a dense array of the given dimension with specified
 * index bounds.  This array owns and manages its data.
 * All object pointers are initialized to NULL.
 */

struct Hypre_GMRES__array*
Hypre_GMRES__iorarray_create(
  int32_t       dimen,
  const int32_t lower[],
  const int32_t upper[])
{
  int32_t size=1, i;
  struct Hypre_GMRES__array *result = newArray(dimen, lower, upper);
  for(i = 0; i < dimen; ++i) {
    result->d_stride[i] = size;
    size *= (1 + upper[i] - lower[i]);
  }
  size *= sizeof(struct Hypre_GMRES__object*);
  result->d_firstElement = (struct Hypre_GMRES__object**)
    malloc(size);
  memset(result->d_firstElement, 0, size);
  return result;
}

/*
 * Create an array that uses data memory from another source.
 * This initial contents are determined by the data being
 * borrowed.
 */

struct Hypre_GMRES__array*
Hypre_GMRES__iorarray_borrow(
  struct Hypre_GMRES__object** firstElement,
  int32_t                      dimen,
  const int32_t                lower[],
  const int32_t                upper[],
  const int32_t                stride[])
{
  struct Hypre_GMRES__array *result = newArray(dimen, lower, upper);
  memcpy(result->d_stride, stride, sizeof(int32_t)*dimen);
  result->d_firstElement = firstElement;
  result->d_borrowed = 1;
  return result;
}

/*
 * Destroy the given array. Trying to destroy a NULL array is a
 * noop.
 */

void
Hypre_GMRES__iorarray_destroy(
  struct Hypre_GMRES__array* array)
{
  if (array) {
    const int32_t dimen = array->d_dimen;
    if (!(array->d_borrowed)) {
      if (dimen > 0) {
        int32_t size = 1;
        struct Hypre_GMRES__object** start = array->d_firstElement;
        struct Hypre_GMRES__object** end;
        if (dimen > 1) {
          size = array->d_stride[dimen-1];
        }
        size *= (1 + array->d_upper[dimen-1] - array->d_lower[dimen-1]);
        end = start + size;
        while (start < end) {
          if (*start) {
            (*((*start)->d_epv->f_deleteReference))((*start));
            *start = NULL;
          }
          ++start;
        }
      }
      free(array->d_firstElement);
    }
    memset(array, 0, sizeof(struct Hypre_GMRES__array)
      + 3 * dimen * sizeof(int32_t));
    free(array);
  }
}

/*
 * Get an element of a multi-dimensional array. This will use
 * the indices provided up to the actual dimension of the array.
 * The values of excess indices are ignored.
 * 
 * If the return value is non-NULL, the client owns one
 * reference to the object/interface. The client must
 * decrement the reference count when done with the reference.
 */

struct Hypre_GMRES__object*
Hypre_GMRES__iorarray_get(
  const struct Hypre_GMRES__array* array,
  const int32_t                    indices[])
{
  struct Hypre_GMRES__object** result = NULL;
  if (array && (array->d_dimen > 0)) {
    int32_t i;
    result = array->d_firstElement;
    for(i = 0;i < array->d_dimen; ++i) {
      if ((indices[i] >= array->d_lower[i]) &&
        (indices[i] <= array->d_upper[i]))
      {
        result += (array->d_stride[i]*(indices[i] - array->d_lower[i]));
      }
      else {
        result = NULL;
        break;
      }
    }
  }
  if (result) {
    if (*result) {
      (*((*result)->d_epv->f_addReference))((*result));
    }
    return *result;
  }
  else {
    return NULL;
  }
}

/*
 * Set an element of a multi-dimensional array. This will use
 * the indices provided up to the actual dimension of the array.
 * The values of excess indices are ignored.
 * 
 * If the incoming value is non-NULL, this function will increment
 * the reference code of the object/interface. If it is
 * overwriting a non-NULL pointer, the reference count of the
 * object/interface being overwritten will be decremented.
 */

void
Hypre_GMRES__iorarray_set(
  struct Hypre_GMRES__array*  array,
  const int32_t               indices[],
  struct Hypre_GMRES__object* value)
{
  struct Hypre_GMRES__object** result = NULL;
  if (array && (array->d_dimen > 0)) {
    int32_t i;
    result = array->d_firstElement;
    for(i = 0;i < array->d_dimen; ++i) {
      if ((indices[i] >= array->d_lower[i]) &&
        (indices[i] <= array->d_upper[i]))
      {
        result += (array->d_stride[i]*(indices[i] - array->d_lower[i]));
      }
      else {
        result = NULL;
        break;
      }
    }
    if (result) {
      if (value) {
        (*(value->d_epv->f_addReference))(value);
      }
      if (*result) {
        (*((*result)->d_epv->f_deleteReference))((*result));
      }
      *result = value;
    }
  }
}

/*
 * Get an element of a multi-dimensional array. This will use
 * the indices provided up to the actual dimension of the array.
 * The values of excess indices are ignored.
 * 
 * If the return value is non-NULL, the client owns one
 * reference to the object/interface. The client must
 * decrement the reference count when done with the reference.
 */

struct Hypre_GMRES__object*
Hypre_GMRES__iorarray_get4(
  const struct Hypre_GMRES__array* array,
  int32_t                          i1,
  int32_t                          i2,
  int32_t                          i3,
  int32_t                          i4)
{
  struct Hypre_GMRES__object** result = NULL;
  if (array) {
    result = array->d_firstElement;
    switch (array->d_dimen) {
    case 4:
      if ((i4 >= array->d_lower[3]) && (i4 <= array->d_upper[3])) {
        result += (array->d_stride[3]*(i4 - array->d_lower[3]));
      }
      else {
        result = NULL;
        break;
      }
      /* fall through */
    case 3:
      if ((i3 >= array->d_lower[2]) && (i3 <= array->d_upper[2])) {
        result += (array->d_stride[2]*(i3 - array->d_lower[2]));
      }
      else {
        result = NULL;
        break;
      }
      /* fall through */
    case 2:
      if ((i2 >= array->d_lower[1]) && (i2 <= array->d_upper[1])) {
        result += (array->d_stride[1]*(i2 - array->d_lower[1]));
      }
      else {
        result = NULL;
        break;
      }
      /* fall through */
    case 1:
      if ((i1 >= array->d_lower[0]) && (i1 <= array->d_upper[0])) {
        result += (array->d_stride[0]*(i1 - array->d_lower[0]));
      }
      else {
        result = NULL;
        break;
      }
      break;
    default:
      result = NULL;
      break;
    }
  }
  if (result) {
    if (*result) {
      (*((*result)->d_epv->f_addReference))((*result));
    }
    return *result;
  }
  else {
    return NULL;
  }
}

/*
 * Set an element of a multi-dimensional array. This will use
 * the indices provided up to the actual dimension of the array.
 * The values of excess indices are ignored.
 * 
 * If the incoming value is non-NULL, this function will increment
 * the reference code of the object/interface. If it is
 * overwriting a non-NULL pointer, the reference count of the
 * object/interface being overwritten will be decremented.
 */

void
Hypre_GMRES__iorarray_set4(
  struct Hypre_GMRES__array*  array,
  int32_t                     i1,
  int32_t                     i2,
  int32_t                     i3,
  int32_t                     i4,
  struct Hypre_GMRES__object* value)
{
  struct Hypre_GMRES__object** result = NULL;
  if (array) {
    result = array->d_firstElement;
    switch (array->d_dimen) {
    case 4:
      if ((i4 >= array->d_lower[3]) && (i4 <= array->d_upper[3])) {
        result += (array->d_stride[3]*(i4 - array->d_lower[3]));
      }
      else {
        result = NULL;
        break;
      }
      /* fall through */
    case 3:
      if ((i3 >= array->d_lower[2]) && (i3 <= array->d_upper[2])) {
        result += (array->d_stride[2]*(i3 - array->d_lower[2]));
      }
      else {
        result = NULL;
        break;
      }
      /* fall through */
    case 2:
      if ((i2 >= array->d_lower[1]) && (i2 <= array->d_upper[1])) {
        result += (array->d_stride[1]*(i2 - array->d_lower[1]));
      }
      else {
        result = NULL;
        break;
      }
      /* fall through */
    case 1:
      if ((i1 >= array->d_lower[0]) && (i1 <= array->d_upper[0])) {
        result += (array->d_stride[0]*(i1 - array->d_lower[0]));
      }
      else {
        result = NULL;
        break;
      }
      break;
    default:
      result = NULL;
      break;
    }
  }
  if (result) {
    if (value) {
      (*(value->d_epv->f_addReference))(value);
    }
    if (*result) {
      (*((*result)->d_epv->f_deleteReference))((*result));
    }
    *result = value;
  }
}

/*
 * Return the number of dimensions in the array. If the
 * array pointer is NULL, zero is returned.
 */

int32_t
Hypre_GMRES__iorarray_dimen(const struct Hypre_GMRES__array *array)
{
  return array ? array->d_dimen : 0;
}

/*
 * Return the lower bound on dimension ind. If ind is not
 * a valid dimension, zero is returned.
 */

int32_t
Hypre_GMRES__iorarray_lower(const struct Hypre_GMRES__array *array, int32_t ind)
{
  return (array && (ind < array->d_dimen) && (ind >= 0))
  ? array->d_lower[ind] : 0;
}

/*
 * Return the upper bound on dimension ind. If ind is not
 * a valid dimension, negative one is returned.
 */

int32_t
Hypre_GMRES__iorarray_upper(const struct Hypre_GMRES__array *array, int32_t ind)
{
  return (array && (ind < array->d_dimen) && (ind >= 0))
    ? array->d_upper[ind] : -1;
}

static const struct Hypre_GMRES__external
s_externalEntryPoints = {
  Hypre_GMRES__new,
  Hypre_GMRES__remote,
  Hypre_GMRES__iorarray_create,
  Hypre_GMRES__iorarray_borrow,
  Hypre_GMRES__iorarray_destroy,
  Hypre_GMRES__iorarray_dimen,
  Hypre_GMRES__iorarray_lower,
  Hypre_GMRES__iorarray_upper,
  Hypre_GMRES__iorarray_get,
  Hypre_GMRES__iorarray_get4,
  Hypre_GMRES__iorarray_set,
  Hypre_GMRES__iorarray_set4
};

/*
 * This function returns a pointer to a static structure of
 * pointers to function entry points.  Its purpose is to provide
 * one-stop shopping for loading DLLs.
 * loading DLLs
 */

const struct Hypre_GMRES__external*
Hypre_GMRES__externals(void)
{
  return &s_externalEntryPoints;
}

/*
 * REMOTE CAST: dynamic type casting for remote objects.
 */

static void* remote_Hypre_GMRES__cast(
  struct Hypre_GMRES__object* self,
  const char* name)
{
  return NULL;
}

/*
 * REMOTE DELETE: call the remote destructor for the object.
 */

static void remote_Hypre_GMRES__delete(
  struct Hypre_GMRES__object* self)
{
  free((void*) self);
}

/*
 * REMOTE METHOD STUB:Apply
 */

static int32_t
remote_Hypre_GMRES_Apply(
  struct Hypre_GMRES__object* self,
  struct Hypre_Vector__object* x,
  struct Hypre_Vector__object** y)
{
  return 0;
}

/*
 * REMOTE METHOD STUB:GetPreconditionedResidual
 */

static int32_t
remote_Hypre_GMRES_GetPreconditionedResidual(
  struct Hypre_GMRES__object* self,
  struct Hypre_Vector__object** r)
{
  return 0;
}

/*
 * REMOTE METHOD STUB:GetResidual
 */

static int32_t
remote_Hypre_GMRES_GetResidual(
  struct Hypre_GMRES__object* self,
  struct Hypre_Vector__object** r)
{
  return 0;
}

/*
 * REMOTE METHOD STUB:SetCommunicator
 */

static int32_t
remote_Hypre_GMRES_SetCommunicator(
  struct Hypre_GMRES__object* self,
  void* comm)
{
  return 0;
}

/*
 * REMOTE METHOD STUB:SetOperator
 */

static int32_t
remote_Hypre_GMRES_SetOperator(
  struct Hypre_GMRES__object* self,
  struct Hypre_Operator__object* A)
{
  return 0;
}

/*
 * REMOTE METHOD STUB:SetParameter
 */

static int32_t
remote_Hypre_GMRES_SetParameter(
  struct Hypre_GMRES__object* self,
  const char* name,
  double value)
{
  return 0;
}

/*
 * REMOTE METHOD STUB:SetPreconditioner
 */

static int32_t
remote_Hypre_GMRES_SetPreconditioner(
  struct Hypre_GMRES__object* self,
  struct Hypre_Solver__object* s)
{
  return 0;
}

/*
 * REMOTE METHOD STUB:Setup
 */

static int32_t
remote_Hypre_GMRES_Setup(
  struct Hypre_GMRES__object* self)
{
  return 0;
}

/*
 * REMOTE METHOD STUB:addReference
 */

static void
remote_Hypre_GMRES_addReference(
  struct Hypre_GMRES__object* self)
{
}

/*
 * REMOTE METHOD STUB:deleteReference
 */

static void
remote_Hypre_GMRES_deleteReference(
  struct Hypre_GMRES__object* self)
{
}

/*
 * REMOTE METHOD STUB:isInstanceOf
 */

static SIDL_bool
remote_Hypre_GMRES_isInstanceOf(
  struct Hypre_GMRES__object* self,
  const char* name)
{
  return 0;
}

/*
 * REMOTE METHOD STUB:isSame
 */

static SIDL_bool
remote_Hypre_GMRES_isSame(
  struct Hypre_GMRES__object* self,
  struct SIDL_BaseInterface__object* iobj)
{
  return 0;
}

/*
 * REMOTE METHOD STUB:queryInterface
 */

static struct SIDL_BaseInterface__object*
remote_Hypre_GMRES_queryInterface(
  struct Hypre_GMRES__object* self,
  const char* name)
{
  return (struct SIDL_BaseInterface__object*) 0;
}

/*
 * REMOTE EPV: create remote entry point vectors (EPVs).
 */

static void Hypre_GMRES__init_remote_epv(void)
{
  struct Hypre_GMRES__epv*                epv = &s_rem__hypre_gmres;
  struct Hypre_Operator__epv*             e0  = &s_rem__hypre_operator;
  struct Hypre_PreconditionedSolver__epv* e1  = 
    &s_rem__hypre_preconditionedsolver;
  struct Hypre_Solver__epv*               e2  = &s_rem__hypre_solver;
  struct SIDL_BaseClass__epv*             e3  = &s_rem__sidl_baseclass;
  struct SIDL_BaseInterface__epv*         e4  = &s_rem__sidl_baseinterface;

  epv->f__cast                     = remote_Hypre_GMRES__cast;
  epv->f__delete                   = remote_Hypre_GMRES__delete;
  epv->f__ctor                     = NULL;
  epv->f__dtor                     = NULL;
  epv->f_Apply                     = remote_Hypre_GMRES_Apply;
  epv->f_GetPreconditionedResidual = 
    remote_Hypre_GMRES_GetPreconditionedResidual;
  epv->f_GetResidual               = remote_Hypre_GMRES_GetResidual;
  epv->f_SetCommunicator           = remote_Hypre_GMRES_SetCommunicator;
  epv->f_SetOperator               = remote_Hypre_GMRES_SetOperator;
  epv->f_SetParameter              = remote_Hypre_GMRES_SetParameter;
  epv->f_SetPreconditioner         = remote_Hypre_GMRES_SetPreconditioner;
  epv->f_Setup                     = remote_Hypre_GMRES_Setup;
  epv->f_addReference              = remote_Hypre_GMRES_addReference;
  epv->f_deleteReference           = remote_Hypre_GMRES_deleteReference;
  epv->f_isInstanceOf              = remote_Hypre_GMRES_isInstanceOf;
  epv->f_isSame                    = remote_Hypre_GMRES_isSame;
  epv->f_queryInterface            = remote_Hypre_GMRES_queryInterface;

  e0->f__cast           = (void* (*)(void*,const char*)) epv->f__cast;
  e0->f__delete         = (void (*)(void*)) epv->f__delete;
  e0->f_Apply           = (int32_t (*)(void*,struct Hypre_Vector__object*,
    struct Hypre_Vector__object**)) epv->f_Apply;
  e0->f_SetCommunicator = (int32_t (*)(void*,void*)) epv->f_SetCommunicator;
  e0->f_SetParameter    = (int32_t (*)(void*,const char*,
    double)) epv->f_SetParameter;
  e0->f_Setup           = (int32_t (*)(void*)) epv->f_Setup;
  e0->f_addReference    = (void (*)(void*)) epv->f_addReference;
  e0->f_deleteReference = (void (*)(void*)) epv->f_deleteReference;
  e0->f_isInstanceOf    = (SIDL_bool (*)(void*,
    const char*)) epv->f_isInstanceOf;
  e0->f_isSame          = (SIDL_bool (*)(void*,
    struct SIDL_BaseInterface__object*)) epv->f_isSame;
  e0->f_queryInterface  = (struct SIDL_BaseInterface__object* (*)(void*,
    const char*)) epv->f_queryInterface;

  e1->f__cast                     = (void* (*)(void*,const char*)) epv->f__cast;
  e1->f__delete                   = (void (*)(void*)) epv->f__delete;
  e1->f_Apply                     = (int32_t (*)(void*,
    struct Hypre_Vector__object*,struct Hypre_Vector__object**)) epv->f_Apply;
  e1->f_GetPreconditionedResidual = (int32_t (*)(void*,
    struct Hypre_Vector__object**)) epv->f_GetPreconditionedResidual;
  e1->f_GetResidual               = (int32_t (*)(void*,
    struct Hypre_Vector__object**)) epv->f_GetResidual;
  e1->f_SetCommunicator           = (int32_t (*)(void*,
    void*)) epv->f_SetCommunicator;
  e1->f_SetOperator               = (int32_t (*)(void*,
    struct Hypre_Operator__object*)) epv->f_SetOperator;
  e1->f_SetParameter              = (int32_t (*)(void*,const char*,
    double)) epv->f_SetParameter;
  e1->f_SetPreconditioner         = (int32_t (*)(void*,
    struct Hypre_Solver__object*)) epv->f_SetPreconditioner;
  e1->f_Setup                     = (int32_t (*)(void*)) epv->f_Setup;
  e1->f_addReference              = (void (*)(void*)) epv->f_addReference;
  e1->f_deleteReference           = (void (*)(void*)) epv->f_deleteReference;
  e1->f_isInstanceOf              = (SIDL_bool (*)(void*,
    const char*)) epv->f_isInstanceOf;
  e1->f_isSame                    = (SIDL_bool (*)(void*,
    struct SIDL_BaseInterface__object*)) epv->f_isSame;
  e1->f_queryInterface            = (struct SIDL_BaseInterface__object* 
    (*)(void*,const char*)) epv->f_queryInterface;

  e2->f__cast           = (void* (*)(void*,const char*)) epv->f__cast;
  e2->f__delete         = (void (*)(void*)) epv->f__delete;
  e2->f_Apply           = (int32_t (*)(void*,struct Hypre_Vector__object*,
    struct Hypre_Vector__object**)) epv->f_Apply;
  e2->f_GetResidual     = (int32_t (*)(void*,
    struct Hypre_Vector__object**)) epv->f_GetResidual;
  e2->f_SetCommunicator = (int32_t (*)(void*,void*)) epv->f_SetCommunicator;
  e2->f_SetOperator     = (int32_t (*)(void*,
    struct Hypre_Operator__object*)) epv->f_SetOperator;
  e2->f_SetParameter    = (int32_t (*)(void*,const char*,
    double)) epv->f_SetParameter;
  e2->f_Setup           = (int32_t (*)(void*)) epv->f_Setup;
  e2->f_addReference    = (void (*)(void*)) epv->f_addReference;
  e2->f_deleteReference = (void (*)(void*)) epv->f_deleteReference;
  e2->f_isInstanceOf    = (SIDL_bool (*)(void*,
    const char*)) epv->f_isInstanceOf;
  e2->f_isSame          = (SIDL_bool (*)(void*,
    struct SIDL_BaseInterface__object*)) epv->f_isSame;
  e2->f_queryInterface  = (struct SIDL_BaseInterface__object* (*)(void*,
    const char*)) epv->f_queryInterface;

  e3->f__cast           = (void* (*)(struct SIDL_BaseClass__object*,
    const char*)) epv->f__cast;
  e3->f__delete         = (void (*)(struct SIDL_BaseClass__object*)) 
    epv->f__delete;
  e3->f_addReference    = (void (*)(struct SIDL_BaseClass__object*)) 
    epv->f_addReference;
  e3->f_deleteReference = (void (*)(struct SIDL_BaseClass__object*)) 
    epv->f_deleteReference;
  e3->f_isInstanceOf    = (SIDL_bool (*)(struct SIDL_BaseClass__object*,
    const char*)) epv->f_isInstanceOf;
  e3->f_isSame          = (SIDL_bool (*)(struct SIDL_BaseClass__object*,
    struct SIDL_BaseInterface__object*)) epv->f_isSame;
  e3->f_queryInterface  = (struct SIDL_BaseInterface__object* (*)(struct 
    SIDL_BaseClass__object*,const char*)) epv->f_queryInterface;

  e4->f__cast           = (void* (*)(void*,const char*)) epv->f__cast;
  e4->f__delete         = (void (*)(void*)) epv->f__delete;
  e4->f_addReference    = (void (*)(void*)) epv->f_addReference;
  e4->f_deleteReference = (void (*)(void*)) epv->f_deleteReference;
  e4->f_isInstanceOf    = (SIDL_bool (*)(void*,
    const char*)) epv->f_isInstanceOf;
  e4->f_isSame          = (SIDL_bool (*)(void*,
    struct SIDL_BaseInterface__object*)) epv->f_isSame;
  e4->f_queryInterface  = (struct SIDL_BaseInterface__object* (*)(void*,
    const char*)) epv->f_queryInterface;

  s_remote_initialized = 1;
}

/*
 * REMOTE: generate remote instance given URL string.
 */

struct Hypre_GMRES__object*
Hypre_GMRES__remote(const char *url)
{
  struct Hypre_GMRES__object* self =
    (struct Hypre_GMRES__object*) malloc(
      sizeof(struct Hypre_GMRES__object));

  struct Hypre_GMRES__object*    s0 = self;
  struct SIDL_BaseClass__object* s1 = &s0->d_sidl_baseclass;

  if (!s_remote_initialized) {
    Hypre_GMRES__init_remote_epv();
  }

  s1->d_sidl_baseinterface.d_epv    = &s_rem__sidl_baseinterface;
  s1->d_sidl_baseinterface.d_object = NULL; /* FIXME */

  s1->d_data = NULL; /* FIXME */
  s1->d_epv  = &s_rem__sidl_baseclass;

  s0->d_hypre_operator.d_epv    = &s_rem__hypre_operator;
  s0->d_hypre_operator.d_object = NULL; /* FIXME */

  s0->d_hypre_preconditionedsolver.d_epv    = 
    &s_rem__hypre_preconditionedsolver;
  s0->d_hypre_preconditionedsolver.d_object = NULL; /* FIXME */

  s0->d_hypre_solver.d_epv    = &s_rem__hypre_solver;
  s0->d_hypre_solver.d_object = NULL; /* FIXME */

  s0->d_data = NULL; /* FIXME */
  s0->d_epv  = &s_rem__hypre_gmres;

  return self;
}
