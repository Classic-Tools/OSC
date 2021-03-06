#include "world.h"


/**************************************************************************/
/* GLOBAL **************        IntToAscii         ************************/
/**************************************************************************/
/* PURPOSE: BUILD AND RETURN THE ASCII REPRESENTATION OF INTEGER val.     */
/**************************************************************************/

char *IntToAscii( val )
int val;
{
  char buf[BUFFER_SIZE];

  SPRINTF( buf, "%d", val );

  return( CopyString( buf ) );
}

/* $Log: IntToAscii.c,v $co: warning: `/* $Log' is obsolescent; use ` * $Log'.

 * Revision 1.1.1.1  2000/12/31 10:48:11  patmiller
 * LLNL distribution with Dave Raymond pthread hacks
 * (otherwise looks remarkably like it did 4 years
 * ago)
 *
 * Pat
 *
 * Revision 1.1  1993/01/21  23:28:58  miller
 * Initial version of the IFX library.  It replaces the if[12]build.c
 * read.c timer.c util.c and write.c and if[12].h files from the
 * backend phases.
 * */
