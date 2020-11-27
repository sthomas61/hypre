#!/bin/sh
# Copyright 1998-2019 Lawrence Livermore National Security, LLC and other
# HYPRE Project Developers. See the top-level COPYRIGHT file for details.
#
# SPDX-License-Identifier: (Apache-2.0 OR MIT)

# Generate intermediate file used to generate C code for switching between types
FNAME=$1
ROOTNAME=$2

gsed -n -e "/.*\(void.*hypre_$ROOTNAME.*\)/ {s/^[[:blank:]]//; s/(/ /; s/,/ /g; s/\(.*\))/\1/; s/;/ /g; p} " $FNAME\
            -e "/.*\(HYPRE_Int.*hypre_$ROOTNAME.*\)/ {s/^[[:blank:]]//; s/(/ /; s/,/ /g; s/\(.*\))/\1/; s/;/ /g; p} " > $FNAME.int


