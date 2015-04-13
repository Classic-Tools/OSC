#include "world.h"


/**************************************************************************/
/* GLOBAL **************         NameAlloc         ************************/
/**************************************************************************/
/* PURPOSE: ALLOCATE, INITIALIZE, AND RETURN A NAME NODE.                 */
/**************************************************************************/

PNAME NameAlloc( n, name, t )
PNODE  n;
char  *name;
PINFO  t;
{
  register PNAME p;

  p = (PNAME) MyAlloc( (int)sizeof(INFO) );

  p->name  = name;
  p->next  = NULL;
  p->usucc = NULL;
  p->info  = t;
  p->node  = n;

  p->mark = NULL;

  return( p );
}

/* $Log: NameAlloc.c,v $
 * Revision 1.1  1993/01/21  23:29:50  miller
 * Initial version of the IFX library.  It replaces the if[12]build.c
 * read.c timer.c util.c and write.c and if[12].h files from the
 * backend phases.
 * */
