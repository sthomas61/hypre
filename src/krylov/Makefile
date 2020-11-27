# Copyright 1998-2019 Lawrence Livermore National Security, LLC and other
# HYPRE Project Developers. See the top-level COPYRIGHT file for details.
#
# SPDX-License-Identifier: (Apache-2.0 OR MIT)

include ../config/Makefile.config

CINCLUDES = ${INCLUDES} ${MPIINCLUDE}
 
C_COMPILE_FLAGS = \
 -I..\
 -I$(srcdir)/..\
 -I$(srcdir)/../blas\
 -I$(srcdir)/../lapack\
 -I$(srcdir)/../multivector\
 -I$(srcdir)/../utilities\
 ${CINCLUDES}

HEADERS =\
 HYPRE_krylov.h\
 krylov.h\
 bicgstab.h\
 cgnr.h\
 gmres.h\
 cogmres.h\
 flexgmres.h\
 lgmres.h\
 pcg.h\
 HYPRE_lobpcg.h\
 HYPRE_MatvecFunctions.h\
 lobpcg.h

FILES =\
 bicgstab.c\
 cgnr.c\
 cogmres.c\
 flexgmres.c\
 lgmres.c\
 HYPRE_bicgstab.c\
 HYPRE_cgnr.c\
 HYPRE_gmres.c\
 HYPRE_cogmres.c\
 HYPRE_lgmres.c\
 HYPRE_flexgmres.c\
 HYPRE_pcg.c\
 HYPRE_lobpcg.c\
 lobpcg.c

#OBJS = ${FILES:.c=.o}

#######################
# Multiprecision "typed" files
#######################
 MP_FILES=\
  pcg.c \
  gmres.c
  
ifeq (${MP_BUILD}, 1) 

##########################
# Multiprecision *only* src files.
# Wrappers for "typed" files.
##########################
   MP_FILES_XTRA=\
    mp_pcg.c \
    mp_gmres.c
#
   OBJS = ${FILES:.c=.o} ${MP_FILES_XTRA:.c=.o} 
   MP_OBJS = ${MP_FILES:.c=.o} 
else
   OBJS = ${FILES:.c=.o} ${MP_FILES:.c=.o} 
endif

SONAME = libHYPRE_krylov-${HYPRE_RELEASE_VERSION}${HYPRE_LIB_SUFFIX}

##################################################################
# Targets
##################################################################

all: libHYPRE_krylov${HYPRE_LIB_SUFFIX} libHYPRE_krylov_mp${HYPRE_LIB_SUFFIX}
	cp -fR $(srcdir)/HYPRE_*.h $(HYPRE_BUILD_DIR)/include
	cp -fR $(srcdir)/krylov.h $(HYPRE_BUILD_DIR)/include
	cp -fR $(srcdir)/lobpcg.h $(HYPRE_BUILD_DIR)/include
#	cp -fR libHYPRE* $(HYPRE_BUILD_DIR)/lib

install: all
	cp -fR $(srcdir)/HYPRE_*.h $(HYPRE_INC_INSTALL)
	cp -fR $(srcdir)/krylov.h $(HYPRE_INC_INSTALL)
	cp -fR $(srcdir)/lobpcg.h $(HYPRE_INC_INSTALL)
#	cp -fR libHYPRE* $(HYPRE_LIB_INSTALL)

clean: clean_mp
	rm -f *.o libHYPRE*
	rm -rf pchdir tca.map *inslog*

distclean: clean

ifeq (${MP_BUILD}, 1) 
clean_mp:
	rm -rf ${MP_OBJDIR}	
else
clean_mp:
endif
##################################################################
# Rules
##################################################################

libHYPRE_krylov.a: ${OBJS}
	@echo  "Building $@ ... "
	${AR} $@ ${OBJS}
	${RANLIB} $@

libHYPRE_krylov.so libHYPRE_krylov.dylib: ${OBJS}
	@echo  "Building $@ ... "
	${BUILD_CC_SHARED} -o ${SONAME} ${OBJS} ${SHARED_SET_SONAME}${SONAME}
	ln -s ${SONAME} $@

${OBJS}: ${HEADERS}

##################################################################
# Multiprecision build Rules
##################################################################

ifeq (${MP_BUILD}, 1) 

MP_OBJDIR = mp.dir
MP_OBJDIR_single = mp.dir/single
MP_OBJDIR_double = mp.dir/double
MP_OBJDIR_longdouble = mp.dir/longdouble
#
MKDIR_P = mkdir -p
mkmpdir: 
	${MKDIR_P} ${MP_OBJDIR}
#
ADD_OBJS_single = ${addprefix ${MP_OBJDIR_single}/, ${MP_OBJS}}
${ADD_OBJS_single}: CFLAGS += -DMP_BUILD_SINGLE=1
${MP_OBJDIR_single}/%.o: %.c
	@echo  "processing C object $@ ..."
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -c -o $@ $<
#
ADD_OBJS_double = ${addprefix ${MP_OBJDIR_double}/, ${MP_OBJS}}
${ADD_OBJS_double}: CFLAGS += -DMP_BUILD_DOUBLE=1
${MP_OBJDIR_double}/%.o: %.c
	@echo  "processing C object $@ ..."
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -c -o $@ $<
#
ADD_OBJS_longdouble = ${addprefix ${MP_OBJDIR_longdouble}/, ${MP_OBJS}}
${ADD_OBJS_longdouble}: CFLAGS += -DMP_BUILD_LONGDOUBLE=1
${MP_OBJDIR_longdouble}/%.o: %.c
	@echo  "processing C object $@ ..."
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -c -o $@ $<
#
#
.SECONDEXPANSION:			
mplibs = libHYPRE_krylov_single.a libHYPRE_krylov_double.a libHYPRE_krylov_longdouble.a
${mplibs}: libHYPRE_krylov_%.a: $${ADD_OBJS_%}
	@echo  "Building $@ ... "
	${AR} $@ $^
	${RANLIB} $@

else
# Don't create mp.dir directory
mkmpdir:
endif

libHYPRE_krylov_mp.a: mkmpdir ${mplibs}
