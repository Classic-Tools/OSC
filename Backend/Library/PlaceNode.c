#include "world.h"


/**************************************************************************/
/* GLOBAL **************         PlaceNode         ************************/
/**************************************************************************/
/* PURPOSE: PLACE A NEW NODE IN THE NODE LIST ADDRESSED BY nlstop IN      */
/*          LABEL ORDER (n->label).                                       */
/**************************************************************************/

void PlaceNode( n )
register PNODE n;
{
  register PNODE nd;

  if ( nprd != NULL )
    if ( nprd->label < n->label ) {
      LinkNode( nprd, n );
      nprd = n;
      return;
    }

  for ( nd = nlstop; nd->nsucc != NULL; nd = nd->nsucc ) /* WHERE? */
    if ( nd->nsucc->label > n->label )
      break;

  LinkNode( nd, n );

  if ( nprd == NULL || nd == nprd )
    nprd = n;
}

/* $Log: PlaceNode.c,v $co: warning: `/* $Log' is obsolescent; use ` * $Log'.

 * Revision 1.1.1.1  2000/12/31 10:48:17  patmiller
 * LLNL distribution with Dave Raymond pthread hacks
 * (otherwise looks remarkably like it did 4 years
 * ago)
 *
 * Pat
 *
 * Revision 1.1  1993/01/21  23:29:56  miller
 * Initial version of the IFX library.  It replaces the if[12]build.c
 * read.c timer.c util.c and write.c and if[12].h files from the
 * backend phases.
 * */
