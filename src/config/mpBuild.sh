#!/bin/sh
# Copyright 1998-2019 Lawrence Livermore National Security, LLC and other
# HYPRE Project Developers. See the top-level COPYRIGHT file for details.
#
# SPDX-License-Identifier: (Apache-2.0 OR MIT)

# Generate multiprecision functions, prototypes, and files needed for multiprecision build
# Assumes script will be called from directory within src folder. eg. krylov directory
SRCFILENAME=$1
HDRFILENAME=$2
ROOTNAME=$3

# step 1: Transform functions names to use macro definition
../config/funcToMacroFunc.sh $SRCFILENAME $ROOTNAME

# step 2: Generate intermediate file used to generate C code for switching between types
## Do this before step 3 to avoid replicated functions.
../config/genIntFile.sh $HDRFILENAME $ROOTNAME

# step 3: Generate multiprecision type protos.
## NOTE: This overwrites $HDRFILENAME !
../config/genMPProtos.sh $HDRFILENAME $ROOTNAME

# step 4: Generate C code from intermediate file containing function prototypes
MPSRC=$(awk -v root=$ROOTNAME 'BEGIN{ print "mp_"tolower(root)".c"}')
INTFILE=$HDRFILENAME.int
../config/genCodeFromProtos.sh $INTFILE $MPSRC $ROOTNAME 2>/dev/null

# step 5: Delete intermediate file
rm -rf $INTFILE

