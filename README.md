# Birthday Kolmogorov-Smirnov Test

The birthday Kolmogorov-Smirnov test is based on the Diehard
birthday spacings test by the late Professor George Marsaglia.
A year contains 16777216 days.  There are 512 people in a room.
The programs in this repository test how evenly distributed their
birthdays are throughout the year.  Because the year is so long,
the chances of two people having the same birthday is very slight.
If two people had their birthdays on the same day, the Kolmogorov-
Smirnov test would show a large maximum difference.  A birthday is
a 24 bit number from zero to 16777215.  Each birthday is divided by
16777216 to give a number from zero to one.  All 512 of those
birthdays are sorted and applied to a Kolmogorov-Smirnov test.

The tests in this repository are applied against a variety
of random number generators, some weak and some strong.
The purpose of this repository is to show how the birthday
test is calculated, and what types of generators pass the test
with an adjusted Dmax score less than 1.96.

Random number generators used in this test.

eegl64

The eegl64 random number generator is explained in the repository
"eegl64".  That is a random number generator based on a 64 bit
LFSR with a Bays Durham shuffle.  The period length of the eegl64
generator approximates 1.2 * 10^61036 generations.  That is a long
period length, that never terminates, or wraps around.  The eegl64
generator passes this test.

----------------

etaus

The eetaus random number generator is explained in the repository
"etaus".  That is a random number generator based on the Tausworthe
algorithm by Pierre L'Ecuyer at the University of Montreal.
Etaus uses the Bays-Durham shuffle.  The period length of this
generator approximates 1.2 * 10^61036 generations.  That is a
long period length, that never terminates, or wraps around.  The
etaus generator passes this test.

----------------

Fibonacci

The fibonacci random number generator illustrates how a weak
random number generator passes this test.

fibonum1 = fibonum2
fibonum2 = fibonum3
fibonum3 = fibonum1 + fibonum2
fraction = fibonum3 / maxint

fraction is a pseudo random number with a uniform distribution
ranging from zero to one.

----------------

LFSR

The LFSR random number generator illustrates how a weak
random number generator fails this test.

See the macro MYLFSR at the beginning of the program for the
algorithm used in the LFSR generator.  The LFSR generator used
is a 64 bit linear feedback shift register with a period length
of 2^64.

MYLFSR;
fraction = lfsr / maxint

fraction is a pseudo random number with a uniform distribution
ranging from zero to one.

----------------

RANDU

The RANDU random number generator illustrates how a weak
random number generator is able to pass this test.

RANDU is a 32 bit generator with a period length of 2^30.

seed *= 65539;
fraction = seed / maxint

fraction is a pseudo random number with a uniform distribution
ranging from zero to one.

----------------

Sine Wave Generator

The sine random number generator illustrates how a weak
random number generator fails this test.

/* generate a uniform number between zero and PI */
theta = eeglunif(ee) * M_PI;
sinx = sin(theta);

sinx is a pseudo random number with a sine distribution
ranging from zero to one.

----------------

GNU Scientific Library Generators

The GSL generators illustrate how a variety of strong random
number generators perform well in this test.

fraction = gsl_rng_uniform(rng);

fraction is a strong random number with a uniform distribution
ranging from zero to one.

----------------

The following subroutines are used in the birthday test.

treeinit.c - initialize a binary tree.

isrt.c - insert a birthday in the binary tree.

rmtree.c - de-allocate the binary tree.

traverse.c - traverse the binary tree in ascending sequence.

Eegl64 subroutines.

eeglabt.c - print copyright and a summary of the GNU Public License.

eeglbit.c - output a random bit

eegl.c - core randomizer, outputs a 32 bit unsigned integer.

eeglcrc.c - calculate the crc for the initial seed.

eegldspl.c - display the internal state of the generator.

eeglfrac.c - generate a 53 bit fraction between zero and one.

eeglinit.c - initialize the generator based on date, time, and
number of ticks since the machine was booted.

eeglint.c - generate a random integer between zero and a limit
minus one.

eeglpwr.c - generate from 1 to 32 random bits.

eeglsd.c - generate a random seed based on a crc calculation.

eeglstrt.c - initialize the generator based on three seed parameters.

eeglunif.c - generate a 32 bit fraction between zero and one.

Etaus generator.  Each subroutine corresponds to the eegl64
subroutine, above, with the same name and features.

etausabt.c

etausbit.c

etaus.c

etausdspl.c

etausfrac.c

etausinit.c

etausint.c

etauspwr.c

etausstrt.c

etausunif.c

--------------------------------------------------------------

If you have a random number generator that you want to include
in this repository, you are welcome to submit your generator for
inclusion.

Read the INSTALL and TESTING documents for more information
about how to use this repository.

