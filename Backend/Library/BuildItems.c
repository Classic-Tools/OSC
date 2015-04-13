#include "world.h"

int    tbase		= 0;	/* Label IF1 types from 0 (first file) */
/*int    tmax		= 0;	 Biggest type (not used) */

char  *stamps[128] =		/* STAMPS FOR ANY CHARACTER       */
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
      NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
      NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
      NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
      NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
      NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
      NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
      NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
      NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
      NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
      NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

char  *sfile  = NULL;		/* SISAL FILE BEING READ */
PNODE  cfunct = NULL;		/* FUNCTION BEING BUILT OR EXAMINED */

/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
PNODE nhash[MAX_HASH];
PNODE nprd		= NULL;
PNODE nlstop		= NULL;	/* NODE  LIST STACK TOP */
char  *sfunct		= NULL;
PINFO  ihead		= NULL;	/* SYMBOL TABLE HEAD POINTER */
PINFO  itail		= NULL;	/* SYMBOL TABLE TAIL POINTER */
PNODE  nhead		= NULL;	/* NODE LIST HEAD POINTER */
PNODE  ntail		= NULL;	/* NODE LIST TAIL POINTER */
PNODE  glstop		= NULL;

PINFO ptr_real		= NULL;	/* VARIOUS SYMBOL TABLE ENTRIES */
PINFO ptr_double	= NULL;
PINFO ptr_integer	= NULL;
PINFO ptr		= NULL;
PINFO integer		= NULL;

void BuildItems()
{
  int		i;

  tbase		= 0;
  /* tmax       = 0;*/
  LargestTypeLabelSoFar		= 0;
  for(i=0;i<128;i++) stamps[i] = NULL;
  sfile		= NULL;
  cfunct	= NULL;
  nprd		= NULL;
  nlstop	= NULL;
  sfunct	= NULL;
  ihead		= NULL;
  itail		= NULL;
  nhead		= NULL;
  ntail		= NULL;
  glstop	= NULL;

  ptr_real	= NULL;
  ptr_double	= NULL;
  ptr_integer	= NULL;
  ptr		= NULL;
  integer	= NULL;

}

/* $Log: BuildItems.c,v $
 * Revision 1.3  1994/05/25  23:35:00  solomon
 * Changed variable tmax to LargestTypeLabelSoFar.
 *
 * Revision 1.2  1993/06/14  20:43:59  miller
 * BuildItems/ReadItems/world  (reset for new IFx read operation)
 * IFX.h/ReadPragmas (new lazy pragma)
 *
 * Revision 1.1  1993/01/21  23:28:00  miller
 * Initial version of the IFX library.  It replaces the if[12]build.c
 * read.c timer.c util.c and write.c and if[12].h files from the
 * backend phases.
 * */
