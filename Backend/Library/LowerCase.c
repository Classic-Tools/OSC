#include "world.h"


/**************************************************************************/
/* GLOBAL **************         LowerCase         ************************/
/**************************************************************************/
/* PURPOSE: CONVERT THE UPPER CASE LETTERS OF NAME n TO LOWER CASE. THIS  */
/*          ROUTINE APPEND A '_' PREFIX AND SUFFIX TO n IF underl AND     */
/*          underr ARE TRUE RESPECTIVELY.                                 */
/**************************************************************************/

char *LowerCase( n, underl, underr )
char *n;
int   underl;
int   underr;
{
  register char *p;
  char  buf[100];

  SPRINTF( buf, "%s%s%s",
	  (underl)? "_" : "", n, (underr)? "_" : "" );

  for ( p = buf; *p != '\0'; p++ )
    if ( (*p >= 'A') && (*p <= 'Z') )
      *p = 'a' + (*p - 'A'); 
    else if ( *p == '.' )
      *p = '_';

  return( CopyString( buf ) );
}

/* $Log: LowerCase.c,v $co: warning: `/* $Log' is obsolescent; use ` * $Log'.

 * Revision 1.1.1.1  2000/12/31 10:48:13  patmiller
 * LLNL distribution with Dave Raymond pthread hacks
 * (otherwise looks remarkably like it did 4 years
 * ago)
 *
 * Pat
 *
 * Revision 1.1  1993/01/21  23:29:31  miller
 * Initial version of the IFX library.  It replaces the if[12]build.c
 * read.c timer.c util.c and write.c and if[12].h files from the
 * backend phases.
 * */
