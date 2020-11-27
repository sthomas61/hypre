#!/bin/sh
# Copyright 1998-2019 Lawrence Livermore National Security, LLC and other
# HYPRE Project Developers. See the top-level COPYRIGHT file for details.
#
# SPDX-License-Identifier: (Apache-2.0 OR MIT)

# Generate multiprecision type protos

FNAME=$1
ROOTNAME=$2

# replicate matched string twice 
# match functions beginning with void, HYPRE_Int, and HYPRE_Real (FNAME = krylov.h)
#gsed "s/.*\(void.*hypre_$ROOTNAME.*\)\;/&\n&\n&/" $FNAME |
#gsed "s/.*\(HYPRE_Int.*hypre_$ROOTNAME.*\)\;/&\n&\n&/" |
#gsed "s/.*\(HYPRE_Real.*hypre_$ROOTNAME.*\)\;/&\n&\n&/" |
# Now modify names with correct extensions _flt, _dbl and _ldbl. Assumes that there is 1 space between 
# function name and open braces for arguments. (FNAME = krylov.h)
awk '$1$2 ~ /void.*hypre_'"$ROOTNAME"'/ {f=$2;print;sub($2, f"_flt");print;sub($2, f"_dbl");print;sub($2, f"_ldbl")} {print}' $FNAME |
awk '$1$2 ~ /HYPRE_Int.*hypre_'"$ROOTNAME"'/ {f=$2;print;sub($2, f"_flt");print;sub($2, f"_dbl");print;sub($2, f"_ldbl")} {print}' |
awk '$1$2 ~ /HYPRE_Real.*hypre_'"$ROOTNAME"'/ {f=$2;print;sub($2, f"_flt");print;sub($2, f"_dbl");print;sub($2, f"_ldbl")} {print}' > $FNAME.tmp
#
#Using sed: Below is a 1-line example of how to do this for functions beginning with void (*). Actual code is split into lines each for readability.
#gsed '/.*\(void.*hypre_PCG.*\)/ {s/\(hypre_PCG.*\)[[:blank:]](/\1_flt (/}; {n;s/\(hypre_PCG.*\)[[:blank:]](/\1_dbl (/}; {n;s/\(hypre_PCG.*\)[[:blank:]](/\1_ldbl (/}' $FNAME 
#
#gsed -e "/.*\(void.*hypre_$ROOTNAME.*\)/ {{s/\(hypre_$ROOTNAME.*\)[[:blank:]](/\1_flt (/}"\
#	 -e "{n;s/\(hypre_$ROOTNAME.*\)[[:blank:]](/\1_dbl (/}"\
#	 -e "{n;s/\(hypre_$ROOTNAME.*\)[[:blank:]](/\1_ldbl (/}}" |
#gsed -e "/.*\(HYPRE_Int.*hypre_$ROOTNAME.*\)/ {{s/\(hypre_$ROOTNAME.*\)[[:blank:]](/\1_flt (/}"\
#	 -e "{n;s/\(hypre_$ROOTNAME.*\)[[:blank:]](/\1_dbl (/}"\
#	 -e "{n;s/\(hypre_$ROOTNAME.*\)[[:blank:]](/\1_ldbl (/}}" |
#gsed -e "/.*\(HYPRE_Real.*hypre_PCG.*\)/ {{s/\(hypre_$ROOTNAME.*\)[[:blank:]](/\1_flt (/}"\
#	 -e "{n;s/\(hypre_$ROOTNAME.*\)[[:blank:]](/\1_dbl (/}"\
#	 -e "{n;s/\(hypre_$ROOTNAME.*\)[[:blank:]](/\1_ldbl (/}}" # > $FNAME.tmp
	 
# overwrite FNAME
mv $FNAME.tmp $FNAME
