#include "world.h"


/**************************************************************************/
/* GLOBAL **************       FindFunction        ************************/
/**************************************************************************/
/* PURPOSE: RETURN THE FUNCTION GRAPH WITH NAME nm.  IF THE FUNCTION IS   */
/*          NOT FOUND, AN ERROR MESSAGE IS PRINTED.  NOTE: THIS ROUTINE   */
/*          WILL NOT WORK CORRECTLY UNTIL AFTER THE CALL GRAPH HAS BEEN   */
/*          BUILT AND THE FUNCTION GRAPHS HAVE BEEN SORTED.               */
/*	    RETURN THE GRAPH NODE REPRESENTING FUNCTION nm.  IF IT ISN'T  */
/*          FOUND, AN ERROR MESSAGE IS PRINTED.                           */
/**************************************************************************/

PNODE FindFunction( nm )
char *nm;
{
  register PNODE f;

  for ( f = (fhead)?(fhead):(glstop->gsucc); f != NULL; f = f->gsucc ) {
    if ( strcmp( f->G_NAME, nm ) == 0 ) return( f );
  }

  Error2( "FindFunction: CAN'T FIND", nm );
  return NULL;
}

/* $Log: FindFunction.c,v $co: warning: `/* $Log' is obsolescent; use ` * $Log'.

 * Revision 1.1.1.1  2000/12/31 10:48:02  patmiller
 * LLNL distribution with Dave Raymond pthread hacks
 * (otherwise looks remarkably like it did 4 years
 * ago)
 *
 * Pat
 *
 * Revision 1.2  1993/11/12  19:55:54  miller
 * Cosmetic change
 *
 * Revision 1.1  1993/01/21  23:28:28  miller
 * Initial version of the IFX library.  It replaces the if[12]build.c
 * read.c timer.c util.c and write.c and if[12].h files from the
 * backend phases.
 * */
