#!/bin/bash
if [ -z $1 ]
then
echo "Usage: $0 GSL_RNG_TYPE"
echo "Example: $0 taus2"
echo "To see a list of GSL generators, type"
echo "$0 ?"
exit 1
fi
GSL_RNG_TYPE="$1"
export GSL_RNG_TYPE
gslbd $1
