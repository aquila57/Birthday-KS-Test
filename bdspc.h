#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <gsl/gsl_cdf.h>
#include <gsl/gsl_rng.h>
#include "eegl.h"
#include "etaus.h"

/* 2^24 = 16777216 */

#define YRLEN (1 << 24)

/* 2^9 = 512 */

#define SMPLS (512.0)

#define DLTX (1.0 / SMPLS)

typedef struct treestruct {
   struct treestruct *left;
   struct treestruct *rght;
   int indx;
   } treefmt;

typedef struct xxstruct {
   treefmt *root;
   int prev;
   int i;
   double yrlen;
   double dltx;
   double x;
   double prevx;
   double maxdiff;
   double duplicates;
   } xxfmt;

treefmt *treeinit(void);
void isrt(treefmt *node, int indx, xxfmt *xx);
void rmtree(treefmt *node);
void traverse(treefmt *node, xxfmt *xx);
