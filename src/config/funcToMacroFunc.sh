#!/bin/sh
# Copyright 1998-2019 Lawrence Livermore National Security, LLC and other
# HYPRE Project Developers. See the top-level COPYRIGHT file for details.
#
# SPDX-License-Identifier: (Apache-2.0 OR MIT)

# Transform functions names to use macro definition

FNAME=$1
ROOTNAME=$2

# match and replace "hypre_*(" excluding strings with "=" (FNAME = pcg.c, ROOTNAME = PCG)
# Skip hypre_{ROOTNAME}FunctionsCreate() for now.
gsed -i "/\(hypre_.*$ROOTNAME.*FunctionsCreate\)/ n; /\(hypre_.*\)=/!s/\(hypre_$ROOTNAME.*\)(/HYPRE_TYPED_FUNC ( \1 ) ( /" $FNAME
