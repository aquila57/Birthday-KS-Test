#!/bin/bash
make -f bdlib.mak clean
make -f bdspc.mak clean
make -f etausbd.mak clean
make -f fibobd.mak clean
make -f lfsrbd.mak clean
make -f randubd.mak clean
make -f sinebd.mak clean
make -f gslbd.mak clean
rm -f allgsl.out
