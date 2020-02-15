#include "bdspc.h"

int main(void)
   {
   int i;
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
   xx = (xxfmt *) malloc(sizeof(xxfmt));
   if (xx == NULL)
      {
      fprintf(stderr,"main: out of memory "
         "allocating xx structure\n");
      exit(1);
      } /* out of memory */
   /****************************************************************/
   ee = (eefmt *) eeglinit();
   xx->yrlen = (double) YRLEN;
   i = 512;
   while (i--)
      {
      double theta;
      double sinx;
      int j;
      theta = eeglunif(ee);
      sinx = sin(theta);
      j = (int) floor(sinx * xx->yrlen);
      yr[j]++;
      } /* for each person's birthday */
   free (ee->state);
   free (ee);
   /****************************************************************/
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
   xx->x = xx->dltx = DLTX;
   xx->maxdiff = xx->prevx = 0.0;
   if (xx->root->rght != NULL) traverse(xx->root->rght,xx);
   if (xx->root->rght != NULL) rmtree(xx->root->rght);
   printf("Birthday Kolmogorov-Smirnov Test\n");
   printf("     sine wave Generator\n");
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
