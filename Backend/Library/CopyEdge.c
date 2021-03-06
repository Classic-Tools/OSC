#include "world.h"


/**************************************************************************/
/* GLOBAL **************          CopyEdge         ************************/
/**************************************************************************/
/* PURPOSE: RETURN A COPY OF EDGE e WITH SOURCE NODE src AND DESTINATION  */
/*          NODE dst.  THE PORT NUMBERS ARE TAKEN FROM e.                 */
/**************************************************************************/

PEDGE CopyEdge( e, src, dst )
PEDGE e;
PNODE src;
PNODE dst;
{
  register PEDGE ee;

  ee = EdgeAlloc( src, e->eport, dst, e->iport );  

  CopyPragmas( e, ee );

  ee->CoNsT   = e->CoNsT;
  ee->info    = e->info;
  ee->if1line = e->if1line;

  return( ee );
}

/* $Log: CopyEdge.c,v $co: warning: `/* $Log' is obsolescent; use ` * $Log'.

 * Revision 1.1.1.1  2000/12/31 10:48:00  patmiller
 * LLNL distribution with Dave Raymond pthread hacks
 * (otherwise looks remarkably like it did 4 years
 * ago)
 *
 * Pat
 *
 * Revision 1.1  1993/01/21  23:28:10  miller
 * Initial version of the IFX library.  It replaces the if[12]build.c
 * read.c timer.c util.c and write.c and if[12].h files from the
 * backend phases.
 * */
