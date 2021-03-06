#include "world.h"
/**************************************************************************/
/* GLOBAL **************           Count           ************************/
/**************************************************************************/
/* PURPOSE: COUNT NODES, LITERALS, AND EDGES IN GRAPH g, PRODUCING A PER- */
/*          LEVEL SUMMARY AND TOTALS.                                     */
/**************************************************************************/

void Count( g )
PNODE g;
{
  register PNODE n;
  register PEDGE i;

  if ( (++topl) >= MaxLevel )
    Error1( "Count: LEVEL STACK OVERFLOW" );

  if ( topl > maxl )
    maxl = topl;

  levels[topl].graphs++;

  gnodes[ g->type - IFSGraph ]++; graphs++;

  for ( i = g->imp; i != NULL; i = i->isucc )
    if ( IsConst( i ) ) {
      lits++;
      levels[topl].lits++;
    } else {
      edges++;
      levels[topl].edges++;
    }

  for ( n = g->G_NODES; n != NULL; n = n->nsucc ) {
    for ( i = n->imp; i != NULL; i = i->isucc )
      if ( IsConst( i ) ) {
	lits++;
	levels[topl].lits++;
      } else {
	edges++;
	levels[topl].edges++;
      }

    if ( IsSimple( n ) ) {
      if ( IsPeek( n ) ) 
	continue;

      snodes[ n->type - IFAAddH ]++; simples++; levels[topl].simples++;
	    
      if ( IsReduction( n ) )
	switch ( n->imp->CoNsT[0] ) {
	 case REDUCE_SUM:
	  rsum++;
	  break;

	 case REDUCE_PRODUCT:
	  rprod++;
	  break;

	 case REDUCE_LEAST:
	  rleast++;
	  break;

	 case REDUCE_GREATEST:
	  rgreat++;
	  break;

	 case REDUCE_CATENATE:
	  rcat++;
	  break;

	 case REDUCE_USER:
	  break;

	 default:
	  Error1( "ILLEGAL REDUCTION FUNCTION" );
	}

      continue;
    }

    if ( IsAtNode( n ) ) {
      atnodes[ n->type - IFAAddLAT ]++; ats++; levels[topl].ats++;
      continue;
    }

    if ( IsCompound( n ) ) {
      cnodes[ n->type - IFForall ]++; 
      comps++; 
      levels[topl].comps++;

      for ( g = n->C_SUBS; g != NULL; g = g->gsucc )
	Count( g );
    }
  }

  topl--;
}


/* $Log: Count.c,v $co: warning: `/* $Log' is obsolescent; use ` * $Log'.

 * Revision 1.1.1.1  2000/12/31 10:48:00  patmiller
 * LLNL distribution with Dave Raymond pthread hacks
 * (otherwise looks remarkably like it did 4 years
 * ago)
 *
 * Pat
 *
 * Revision 1.2  1994/03/09  01:12:33  denton
 * Fix -info1-32 for reductions
 *
 * Revision 1.1  1993/01/21  23:28:14  miller
 * Initial version of the IFX library.  It replaces the if[12]build.c
 * read.c timer.c util.c and write.c and if[12].h files from the
 * backend phases.
 * */
