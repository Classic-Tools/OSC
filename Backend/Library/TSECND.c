#include "world.h"


#ifndef CRAY
/**************************************************************************/
/* GLOBAL **************          TSECND           ************************/
/**************************************************************************/
/* PURPOSE: RETURN THE ELAPSED CPU TIME SINCE THE START OF THE PROGRAM.   */
/*          NOTE THAT TSECND IS A CRAY INTRINSIC!                         */
/**************************************************************************/

double TSECND()
{
  register double CurrentCpuTime;

#ifdef USE_TIMES
  struct tms         StopTimeNow;

  (void)times(&StopTimeNow);
  CurrentCpuTime  = ((double) (StopTimeNow.tms_utime + StopTimeNow.tms_stime));
  CurrentCpuTime /= CLK_TCK;

#else
  struct rusage StartTimerInfo;
  struct rusage StopTimerInfo;

  (void) getrusage( RUSAGE_SELF, &StopTimerInfo );

  StartTimerInfo.ru_utime.tv_sec  = 0;
  StartTimerInfo.ru_utime.tv_usec = 0;
  StartTimerInfo.ru_stime.tv_sec  = 0;
  StartTimerInfo.ru_stime.tv_usec = 0;

  CurrentCpuTime = 
    ElapsedTime( &StartTimerInfo.ru_utime, &StopTimerInfo.ru_utime ) +
      ElapsedTime( &StartTimerInfo.ru_stime, &StopTimerInfo.ru_stime );
#endif

  return( CurrentCpuTime );
}
#endif

/* $Log: TSECND.c,v $co: warning: `/* $Log' is obsolescent; use ` * $Log'.

 * Revision 1.1.1.1  2000/12/31 10:48:21  patmiller
 * LLNL distribution with Dave Raymond pthread hacks
 * (otherwise looks remarkably like it did 4 years
 * ago)
 *
 * Pat
 *
 * Revision 1.2  1994/06/20  21:50:52  denton
 * Added CLK_TCK.
 *
 * Revision 1.1  1993/01/21  23:30:28  miller
 * Initial version of the IFX library.  It replaces the if[12]build.c
 * read.c timer.c util.c and write.c and if[12].h files from the
 * backend phases.
 * */
