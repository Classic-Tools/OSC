#include "world.h"

/**************************************************************************/
/* GLOBAL **************        StopProfiler       ************************/
/**************************************************************************/
/* PURPOSE: PRINT THE CPU TIME SINCE THE LAST CALL TO StartProfiler ALONG */
/*          WITH msg TO stderr.                                           */
/**************************************************************************/

void StopProfiler( msg )
char *msg;
{
  if ( prof )
    FPRINTF( stderr, "PROFILE [%s,%s] = %f seconds\n",
	    program, msg, TSECND() - StartTime );
}

/* $Log: StopProfiler.c,v $co: warning: `/* $Log' is obsolescent; use ` * $Log'.

 * Revision 1.1.1.1  2000/12/31 10:48:21  patmiller
 * LLNL distribution with Dave Raymond pthread hacks
 * (otherwise looks remarkably like it did 4 years
 * ago)
 *
 * Pat
 *
 * Revision 1.2  1994/04/15  15:51:55  denton
 * Added config.h to centralize machine specific header files.
 * Fixed gcc warings.
 *
 * Revision 1.1  1993/01/21  23:30:27  miller
 * Initial version of the IFX library.  It replaces the if[12]build.c
 * read.c timer.c util.c and write.c and if[12].h files from the
 * backend phases.
 * */
