#include "world.h"


/**************************************************************************/
/* MACRO  **************          WriteAde         ************************/
/**************************************************************************/
/* PURPOSE: WRITE ARITFICIAL DEPENDENCE EDGE x TO OUTPUT.                 */
/**************************************************************************/

#define WriteAde(x)    FPRINTF( output, "D %2d      %2d\n",                \
	                                (x)->src->label, (x)->dst->label )


/**************************************************************************/
/* MACRO  **************         WriteEdge         ************************/
/**************************************************************************/
/* PURPOSE: WRITE EDGE e TO output. THE PORT NUMBERS MAY BE NEGATIVE.     */
/**************************************************************************/

#define WriteEdge(e)   FPRINTF( output, "E %2d %2d   %2d %2d  %2d",        \
	                                e->src->label, abs( e->eport ),    \
                                        e->dst->label, abs( e->iport ),    \
					e->info->label               )


/**************************************************************************/
/* GLOBAL **************        WriteImports       ************************/
/**************************************************************************/
/* PURPOSE: WRITE NODE n's IMPORTS, BOTH DATA AND CONTROL, TO output.     */
/**************************************************************************/

void WriteImports( n )
PNODE n;
{
  register PEDGE  i;
  register PADE   a;

  for ( i  = n->imp; i != NULL; i = i->isucc ) {
    if ( IsConst( i ) )
      WriteConst( i );
    else
      WriteEdge( i );

    WritePragmas( i );
  }

  for ( a = n->aimp; a != NULL; a = a->isucc )
    WriteAde( a );
}

/* $Log: WriteImports.c,v $
 * Revision 1.1  1993/01/21  23:30:46  miller
 * Initial version of the IFX library.  It replaces the if[12]build.c
 * read.c timer.c util.c and write.c and if[12].h files from the
 * backend phases.
 * */