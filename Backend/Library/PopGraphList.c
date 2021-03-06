#include "world.h"


/**************************************************************************/
/* GLOBAL **************       PopGraphList        ************************/
/**************************************************************************/
/* PURPOSE: REMOVE THE TOP GRAPH LIST HEADER FROM GRAPH LIST HEADER STACK */
/*          IF IT IS NOT ALREADY EMPTY. WHEN DONE, glstop WILL ADDRESS THE*/
/*          PREVIOUS GRAPH LIST HEADER.  THE REMOVED HEADER NODE IS FREED.*/
/**************************************************************************/

void PopGraphList() 
{ 
  if ( glstop == NULL ) return;
  glstop = UnlinkNode( glstop );
}

/* $Log: PopGraphList.c,v $co: warning: `/* $Log' is obsolescent; use ` * $Log'.

 * Revision 1.1.1.1  2000/12/31 10:48:18  patmiller
 * LLNL distribution with Dave Raymond pthread hacks
 * (otherwise looks remarkably like it did 4 years
 * ago)
 *
 * Pat
 *
 * Revision 1.1  1993/01/21  23:29:59  miller
 * Initial version of the IFX library.  It replaces the if[12]build.c
 * read.c timer.c util.c and write.c and if[12].h files from the
 * backend phases.
 * */
