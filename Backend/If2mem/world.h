/* $Log: world.h,v $
 * Revision 1.11  1994/06/16  21:31:02  mivory
 * info format and option changes M. Y. I.
 *
 * Revision 1.10  1994/04/15  15:51:14  denton
 * Added config.h to centralize machine specific header files.
 * Fixed gcc warings.
 *
 * Revision 1.9  1993/03/23  22:35:46  miller
 * date problem
 *
 * Revision 1.8  1994/03/11  23:09:35  miller
 * Moved IFX.h into Backend/Library and added support for Minimal
 * installation (removing source as compiled).
 *
 * Revision 1.7  1993/01/15  22:25:59  miller
 * Moved the definition for info up into IFX.h
 *
 * Revision 1.6  1993/01/14  22:28:00  miller
 * Carry along work to propagate the new pragmas.
 *
 * Revision 1.5  1993/01/07  00:39:12  miller
 * Make changes for LINT and combined files.
 * */

#include "../../config.h"
#include "../Library/IFX.h"


extern int    noopt;		/* ARE CSE AND CONSTANT FOLDING DESIRED? */

extern int   invar;		/* GRAPH CLEANUP DISABLE FLAGS */
extern int   cse;
extern int   gcse;
extern int   fold;

extern int   minopt;		/* ONLY PERFORM MINIMAL OPTIMIZATION? */
extern int   fover;		/* OVERRIDE AGather FILTERS? */
extern int   Oinvar;

extern int   paddh;		/* COUNT OF AAddH PREFERENCES */

extern FILE *infoptr;
extern int agg;

/* ------------------------------------------------------------ */
/* if2mem.c */
extern void	PushAtNode();
extern PNODE	PopAtNode();
extern PNODE	ReferencePoint();
extern PNODE	MaxNodeInDFO();
extern PNODE	MaxSourceInDFO();
extern void	If2Mem();

/* if2level.c */
extern void	AssignLevelNumbers();

/* if2size.c */
extern void	AssignSizes();

/* if2alloc.c */
extern void	AllocIf2Nodes();

/* if2clean.c */
extern void	If2Clean();

/* if2pic.c */
extern void	CountNodesAndEdges();
extern void	TraceBuffer();
extern void	WriteIf2memPicture();
extern void	WriteIf2memWarnings();

