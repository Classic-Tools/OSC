#include "world.h"


/**************************************************************************/
/* GLOBAL **************        FindInfo           ************************/
/**************************************************************************/
/* PURPOSE: LOCATE AND RETURN THE INFO NODE WITH LABEL label + tbase IN   */
/*          THE INFO LIST HEADED BY ihead.  IF THE NODE DOES NOT EXIST,   */
/*          IT IS ALLOCATED AND INSERTED INFO THE LIST. NULL IS RETURNED  */
/*          IF THE REQUESTED LABEL IS 0. Tbase IS ADDED TO ALL LABELS TO  */
/*          MAKE THEM UNIQUE ACROSS ALL FILES.  Tmax  IS USED  TO DEFINE  */
/*          tbase FOR THE NEXT READ FILE (IF1LD only)                     */
/**************************************************************************/

PINFO FindInfo( label, type )
int label;
int type;
{
  if ( label <= 0 )
    return( NULL );

  label += tbase;

  if ( tmax < label )
    tmax = label;

  if ( ihead == NULL )
    return( ihead = itail = InfoAlloc( label, type ) );

  return( LookupInfo( label, type ) );
}

/* $Log: FindInfo.c,v $
 * Revision 1.1  1993/01/21  23:28:32  miller
 * Initial version of the IFX library.  It replaces the if[12]build.c
 * read.c timer.c util.c and write.c and if[12].h files from the
 * backend phases.
 * */