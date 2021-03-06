#include "world.h"


/**************************************************************************/
/* GLOBAL **************       LinkAdeExport       ************************/
/**************************************************************************/
/* PURPOSE: ADD ADE EXPORT a TO THE HEAD OF src'S ADE EXPORT LIST. THE    */
/*          PEDECESSOR OF THE FIRST EXPORT IS ALWAYS NULL.                */
/**************************************************************************/


void LinkAdeExport( src, a )
PNODE src;
PADE  a;
{
  a->src = src;

  a->epred = NULL;
  a->esucc = src->aexp;

  if ( src->aexp != NULL )
    src->aexp->epred = a;

  src->aexp = a;
}

/* $Log: LinkAdeExport.c,v $co: warning: `/* $Log' is obsolescent; use ` * $Log'.

 * Revision 1.1.1.1  2000/12/31 10:48:12  patmiller
 * LLNL distribution with Dave Raymond pthread hacks
 * (otherwise looks remarkably like it did 4 years
 * ago)
 *
 * Pat
 *
 * Revision 1.1  1993/01/21  23:29:18  miller
 * Initial version of the IFX library.  It replaces the if[12]build.c
 * read.c timer.c util.c and write.c and if[12].h files from the
 * backend phases.
 * */
