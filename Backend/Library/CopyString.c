#include "world.h"


/**************************************************************************/
/* GLOBAL **************        CopyString         ************************/
/**************************************************************************/
/* PURPOSE: RETURN A COPY OF THE INPUT STRING s.                          */
/**************************************************************************/

char *CopyString( s ) 
char *s;
{
  return( strcpy( MyAlloc( (int)(strlen( s ) + 1) ), s ) );
}

/* $Log: CopyString.c,v $co: warning: `/* $Log' is obsolescent; use ` * $Log'.

 * Revision 1.1.1.1  2000/12/31 10:48:00  patmiller
 * LLNL distribution with Dave Raymond pthread hacks
 * (otherwise looks remarkably like it did 4 years
 * ago)
 *
 * Pat
 *
 * Revision 1.1  1993/01/21  23:28:13  miller
 * Initial version of the IFX library.  It replaces the if[12]build.c
 * read.c timer.c util.c and write.c and if[12].h files from the
 * backend phases.
 * */
