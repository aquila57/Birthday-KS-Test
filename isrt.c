/* isrt.c - Insert one node in tree  Version 0.1.0 */
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

/* duplicates allowed */

void isrt(treefmt *node, int indx, xxfmt *xx)
   {
   treefmt *newnode;
   if (indx < node->indx)
      {
      if (node->left != NULL) isrt(node->left,indx,xx);
      else
         {
	 newnode = (treefmt *) treeinit();
	 newnode->indx = indx;
	 node->left = (treefmt *) newnode;
	 } /* else leaf node */
      } /* if less than */
   else if (indx > node->indx)
      {
      if (node->rght != NULL) isrt(node->rght,indx,xx);
      else
         {
	 newnode = (treefmt *) treeinit();
	 newnode->indx = indx;
	 node->rght = (treefmt *) newnode;
	 } /* else leaf node */
      } /* if greater than */
   else        /* duplicate index */
      {
      newnode = (treefmt *) treeinit();
      newnode->indx = indx;
      node->rght = (treefmt *) newnode;
      xx->duplicates += 1.0;
      } /* duplicate index */
   } /* isrt */
