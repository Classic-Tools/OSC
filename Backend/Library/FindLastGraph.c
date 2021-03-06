#include "world.h"


/**************************************************************************/
/* GLOBAL **************       FindLastGraph       ************************/
/**************************************************************************/
/* PURPOSE: RETURN THE LAST GRAPH NODE IN THE GRAPH LIST HEADED BY n;     */
/*          NOTE: n ITSELF MIGHT BE RETURNED.                             */
/**************************************************************************/

PNODE FindLastGraph( n )
register PNODE n;
{
  while ( n->gsucc != NULL )
    n = n->gsucc;

  return( n );
}

/* $Log: FindLastGraph.c,v $co: warning: `/* $Log' is obsolescent; use ` * $Log'.

 * Revision 1.1.1.1  2000/12/31 10:48:03  patmiller
 * LLNL distribution with Dave Raymond pthread hacks
 * (otherwise looks remarkably like it did 4 years
 * ago)
 *
 * Pat
 *
 * Revision 1.1  1993/01/21  23:28:33  miller
 * Initial version of the IFX library.  It replaces the if[12]build.c
 * read.c timer.c util.c and write.c and if[12].h files from the
 * backend phases.
 * */
