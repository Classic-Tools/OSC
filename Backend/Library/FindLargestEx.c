#include "world.h"

/**************************************************************************/
/* GLOBAL **************      FindLargestExport     ***********************/
/**************************************************************************/
/* PURPOSE: RETURN THE LARGEST EXPORT TO NODE node.                       */
/**************************************************************************/

int FindLargestExport( node )
PNODE node;
{
  register PEDGE edge;
  int largest_port = 0;

  if ( IsCompound ( node ) ) {
    PNODE       subgraph;
    int         sub_largest_port = 0;
    for (subgraph = node->C_SUBS; subgraph!=NULL; subgraph = subgraph->gsucc) {
      sub_largest_port = FindLargestExport( subgraph );
      if ( sub_largest_port > largest_port )
        largest_port = sub_largest_port;
    }
  }

  for ( edge = node->exp; edge != NULL; edge = edge->esucc ) {
    if ( edge->eport > largest_port )
        largest_port = edge->eport;
    if ( edge->esucc == NULL )
      break;
  }

  return largest_port;
}

/* $Log: FindLargestEx.c,v $co: warning: `/* $Log' is obsolescent; use ` * $Log'.

 * Revision 1.1.1.1  2000/12/31 10:48:02  patmiller
 * LLNL distribution with Dave Raymond pthread hacks
 * (otherwise looks remarkably like it did 4 years
 * ago)
 *
 * Pat
 *
 * Revision 1.1  1994/01/28  00:09:33  miller
 * new man pages and new helper functions for library
 *
 * */
