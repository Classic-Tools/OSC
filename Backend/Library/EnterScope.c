#include "world.h"


/**************************************************************************/
/* GLOBAL **************        EnterScope         ************************/
/**************************************************************************/
/* PURPOSE: PUSH NEW GRAPH LIST AND NODE LIST HEADERS ON THE ASSOCIATED   */
/*          HEADER STACKS. THIS ROUTINE IS CALLED BEFORE A NEW COMPOUND   */
/*          NODE IS TO BE BUILT (WHEN } SEEN IN IF1 INPUT).               */
/**************************************************************************/

void EnterScope()
{
  PushGraphList();
  PushNodeList();
}

/* $Log: EnterScope.c,v $co: warning: `/* $Log' is obsolescent; use ` * $Log'.

 * Revision 1.1.1.1  2000/12/31 10:48:01  patmiller
 * LLNL distribution with Dave Raymond pthread hacks
 * (otherwise looks remarkably like it did 4 years
 * ago)
 *
 * Pat
 *
 * Revision 1.1  1993/01/21  23:28:23  miller
 * Initial version of the IFX library.  It replaces the if[12]build.c
 * read.c timer.c util.c and write.c and if[12].h files from the
 * backend phases.
 * */
