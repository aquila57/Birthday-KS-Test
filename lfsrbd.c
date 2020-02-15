/* lfsrbd.c - Birthday KS Test, LFSR generator  Version 0.1.0 */
/* Copyright (C) 2020 aquila57 at github.com */

/* This program is free software; you can redistribute it and/or     */
/* modify it under the terms of the GNU General Public License as    */
/* published by the Free Software Foundation; either version 2 of    */
/* the License, or (at your option) any later version.               */

/* This program is distributed in the hope that it will be useful,   */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of    */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the      */
/* GNU General Public License for more details.                      */

/* You should have received a copy of the GNU General Public License */
/* along with this program; if not, write to:                        */

   /* Free Software Foundation, Inc.                                 */
   /* 59 Temple Place - Suite 330                                    */
   /* Boston, MA 02111-1307, USA.                                    */

#include "bdspc.h"

#define MYLFSROUT (out = (((lfsr >> 4) \
   ^ (lfsr >> 3) \
   ^ (lfsr >> 1) \
   ^ (lfsr >> 0)) & 1))

#define MYLFSRLOWBIT (lowbit = major & 1)

#define MYLFSRROLL (lfsr0 = major = \
(major >> 1) | (out << 31))

#define MYLFSRCARRY (lfsr = minor = \
(minor >> 1) | (lowbit << 31))

#define MYLFSR (MYLFSROUT,MYLFSRLOWBIT,MYLFSRROLL,MYLFSRCARRY)

int main(void)
   {
   int i;
   unsigned int lfsr0;
   unsigned int lfsr;
   unsigned int major;
   unsigned int minor;
   int out;
   int lowbit;
   unsigned char *p,*q;
   unsigned char *yr;
   eefmt *ee;
   xxfmt *xx;
   yr = (unsigned char *) malloc(YRLEN);
   if (yr == NULL)
      {
      fprintf(stderr,"main: out of memory "
         "allocating yr\n");
      exit(1);
      } /* out of memory */
   p = (unsigned char *) yr;
   q = (unsigned char *) yr + YRLEN;
   while (p < q) *p++ = '\0';
   /****************************************************************/
   ee = (eefmt *) eeglinit();
   lfsr0 = eegl(ee);
   major = lfsr0;
   lfsr  = minor = eegl(ee);
   out = lowbit = 0;
   free (ee->state);
   free (ee);
   i = 512;
   while (i--)
      {
      int j;
      MYLFSR;
      j = lfsr >> 8;
      yr[j]++;
      } /* for each person's birthday */
   /****************************************************************/
   xx = (xxfmt *) malloc(sizeof(xxfmt));
   if (xx == NULL)
      {
      fprintf(stderr,"main: out of memory "
         "allocating xx structure\n");
      exit(1);
      } /* out of memory */
   xx->root = (treefmt *) treeinit();
   xx->duplicates = 0.0;
   i = 0;
   p = (unsigned char *) yr;
   q = (unsigned char *) yr + YRLEN;
   while (p < q)
      {
      if (*p > 0) isrt(xx->root,i,xx);
      i++;
      p++;
      } /* for each day in year */
   /****************************************************************/
   xx->yrlen = (double) YRLEN;
   xx->x = xx->dltx = DLTX;
   xx->maxdiff = xx->prevx = 0.0;
   if (xx->root->rght != NULL) traverse(xx->root->rght,xx);
   if (xx->root->rght != NULL) rmtree(xx->root->rght);
   printf("Birthday Kolmogorov-Smirnov Test\n");
   printf("       LFSR Generator\n");
   printf("Maximum difference %f\n", xx->maxdiff);
   printf("Times sqrt(N)      %f\n",
      xx->maxdiff * sqrt(SMPLS));
   printf("Days in year       %.0f\n", xx->yrlen);
   printf("#birthdays         %.0f\n", 512.0);
   printf("Duplicate bdays    %.0f\n", xx->duplicates);
   printf("\n");
   printf("Since number of samples is over 50,\n");
   printf("Probability    D-Max\n");
   printf("  0.001        1.94947\n");
   printf("  0.01         1.62762\n");
   printf("  0.02         1.51743\n");
   printf("  0.05         1.35810\n");
   free(yr);
   free(xx);
   return(0);
   } /* main */
