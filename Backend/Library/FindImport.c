#include "world.h"


/**************************************************************************/
/* GLOBAL **************        FindImport         ************************/
/**************************************************************************/
/* PURPOSE: RETURN THE IMPORT OF NODE n WITH IMPORT PORT NUMBER iport. IF */
/*          NOT FOUND, RETURN NULL.                                       */
/**************************************************************************/

PEDGE FindImport( n, iport )
PNODE n;
register int iport;
{
  register PEDGE i;

  for ( i = n->imp; i != NULL; i = i->isucc )
    if ( i->iport == iport )
      return( i );

  return( NULL );
}

/* $Log: FindImport.c,v $co: warning: `/* $Log' is obsolescent; use ` * $Log'.

 * Revision 1.1.1.1  2000/12/31 10:48:02  patmiller
 * LLNL distribution with Dave Raymond pthread hacks
 * (otherwise looks remarkably like it did 4 years
 * ago)
 *
 * Pat
 *
 * Revision 1.1  1993/01/21  23:28:31  miller
 * Initial version of the IFX library.  It replaces the if[12]build.c
 * read.c timer.c util.c and write.c and if[12].h files from the
 * backend phases.
 * */
