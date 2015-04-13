#define FOR_NOTHING   0
#define FOR_SHUTDOWN  1

#define SPAWN_SIMPLE  0
#define SPAWN_COMPLEX 1

#ifdef RS6000
#define BANNER "IBM RS6000 SISAL 1.2"
#endif

#ifdef SUN
#define BANNER "SUN SISAL 1.2"
#endif

#ifdef SUNIX
#ifndef RS6000
#define BANNER "SISAL 1.2"
#endif
#endif

#ifdef CRAY
#define BANNER "CRAY SISAL 1.2"
#endif

#ifdef SGI
#define BANNER "SGI SISAL 1.2"
#endif

#ifdef ALLIANT
#define BANNER "ALLIANT SISAL 1.2"
#endif

#ifdef ENCORE 
#define BANNER "ENCORE SISAL 1.2"
#endif

#ifdef BALANCE 
#define BANNER "BALANCE SISAL 1.2"
#endif

#ifdef SYMMETRY
#define BANNER "SYMMETRY SISAL 1.2"
#endif

#define DEFAULT_NUM_WORKERS       1
#define DEFAULT_DSA_SIZE          2000000
#define DEFAULT_XFT_THRESHOLD     100
#define DEFAULT_LOOP_SLICES       1
#define DEFAULT_LOOP_FACTOR       2
#define DEFAULT_ARRAY_EXPANSION   100

#ifdef ALLIANT
#define GetProcId lib_processor_number()
#define GETPROCID(x) x = GetProcId
#else
#ifdef CRAY
extern int ProcessorId();
#define GetProcId ProcessorId()
#define GETPROCID(v) { int x; TSKVALUE(&x); v = x; }
#else
#ifdef SGI
#define GetProcId  *((int*)((PRDA->usr_prda.fill)))
#define GETPROCID(x) x = GetProcId
#else
#define GetProcId  p_procnum
#define GETPROCID(x) x = GetProcId
#endif
#endif
#endif


struct ActRec {
  POINTER ArgPointer;                     /* TASK ARGUMENT               */
  int     AuxArgument;                    /* AUXILIARY TASK ARGUMENT     */
  void    (*ChildCode)();                 /* TASK ADDRESS                */
  int     SliceBounds[3];                 /* LOOP SLICE CONTROL INFO     */
  struct  ActRec *NextAR;                 /* FORWARD QUEUE LINK          */
  int     Done;                           /* IS THIS TASK DONE YET?      */
  };

struct ActRecCache {
  struct ActRec *Head;                    /* HEAD OF QUEUE               */
  struct ActRec *Tail;                    /* TAIL OF QUEUE               */
  LOCK_TYPE      Mutex;                   /* QUEUE LOCK                  */
  };


#define MYINFO(x)  (&(AllWorkerInfo[(x)]))
#define MyInfo     (&(AllWorkerInfo[GetProcId]))

struct WorkerInfo {
  double FlopInfo;                      /* WAS FLOP INFORMATION GATHERED */
  double FlopCountA;                                    /* FLOP COUNTERS */
  double FlopCountL;
  double FlopCountI;

  double CopyInfo;                      /* WAS COPY INFORMATION GATHERED */
  double ATAttempts;                               /* DATA COPY COUNTERS */
  double ATCopies;
  double ANoOpAttempts;
  double ANoOpCopies;
  double RNoOpAttempts;
  double RNoOpCopies;
  double ADataCopies;
  double RBuilds;

  int    DsaHelp;                             /* COUNT OF DsaHelp CALLS  */

  int    StorageUsed;                         /* WANTED AND USED STORAGE */
  int    StorageWanted;

  struct timeval WallTimeBuffer;              /* WALL CLOCK START TIME   */
  double WallTime;                            /* ELAPSED WALL CLOCK TIME */
  double CpuTime;                             /* ELAPSED CPU TIME        */
  };

#ifdef GatherCopyInfo
#define SaveCopyInfo      { MyInfo->CopyInfo = 1.0;     }
#define IncRBuilds        { MyInfo->RBuilds++;          }
#define IncATAttempts     { MyInfo->ATAttempts++;       }
#define IncATCopies       { MyInfo->ATCopies++;         }
#define IncANoOpAttempts  { MyInfo->ANoOpAttempts++;    }
#define IncANoOpCopies    { MyInfo->ANoOpCopies++;      }
#define IncRNoOpAttempts  { MyInfo->RNoOpAttempts++;    }
#define IncRNoOpCopies    { MyInfo->RNoOpCopies++;      }
#define IncDataCopies(x)  { MyInfo->ADataCopies += (x); }
#else
#define SaveCopyInfo
#define IncRBuilds
#define IncATAttempts
#define IncATCopies
#define IncANoOpAttempts
#define IncANoOpCopies
#define IncRNoOpAttempts
#define IncRNoOpCopies
#define IncDataCopies(x)
#endif

#ifdef GatherFlopInfo
#define SaveFlopInfo       { MyInfo->FlopInfo = 1.0;      }
#define IncFlopCountA(x)   { MyInfo->FlopCountA += (x);   }
#define IncFlopCountL(x)   { MyInfo->FlopCountL += (x);   }
#define IncFlopCountI(x)   { MyInfo->FlopCountI += (x);   }
#else
#define SaveFlopInfo
#define IncFlopCountA(x)
#define IncFlopCountL(x)
#define IncFlopCountI(x)
#endif

#define IncStorageUsed(y,x)   { MYINFO(y)->StorageUsed   += x;   }
#define IncStorageWanted(y,x) { MYINFO(y)->StorageWanted += x;   }
#define IncDsaHelp(y)         { MYINFO(y)->DsaHelp += 1;         }


#define OPEN(f,n,m) if ( ((f) = fopen( (n), (m) )) == (FILE *) NULL )\
                      SisalError( "CAN'T OPEN", (n) )


#define SDBX_INT    0
#define SDBX_FPE    1
#define SDBX_ESTART 2
#define SDBX_ESTOP  3
#define SDBX_BDS    4
#define SDBX_DB0    5
#define SDBX_PUSH   6
#define SDBX_POP    7
#define SDBX_SENTER 8
#define SDBX_SEXIT  9
#define SDBX_NONE   10
#define SDBX_IERR   11
#define SDBX_ERR    12

#define SDBX_INT    0
#define SDBX_PTR    1
#define SDBX_DBL    2

struct SdbxValue {
  char          *Name;
  unsigned char  Kind;
  unsigned char  ArrayType;
  unsigned char  Active;
  void           (*PrintRoutine)();

  union {
    int     InT;
    POINTER PtR;
    double  DbL;
    } Value;
  };

struct SdbxInfo {
  int     Action;
  char   *File;
  char   *Function;
  int     Line;
  int     ScopeStackTop;
  int     ScopeSize;
  struct  SdbxValue **ScopeStack;
  char  **FunctionList;
  };

extern struct SdbxValue  *SdbxScope;
extern int                SdbxScopeSize;
extern struct SdbxValue  *SdbxCurrentScope;
extern struct SdbxInfo    SdbxState;
extern struct SdbxInfo    SdbxAction;
extern char             **SdbxCurrentFunctionList;

extern void SdbxMonitor();
extern void SdbxHandler();


extern int p_procnum;

extern struct ActRec  **RListFrontD;

extern int     Sequential;
extern int     UsingSdbx;

extern POINTER SharedMalloc();
extern void    AcquireSharedMemory();
extern void    ReleaseSharedMemory();
extern void    StartWorkers();
extern void    StopWorkers();
extern void    AbortParallel();

extern void    ParseCommandLine();
extern void    DumpRunTimeInfo();
extern void    InitSisalRunTime();

extern void    Wait();
extern void    Sync();

extern void    InitSpawn();
extern void    SpawnSlices();
extern void    OptSpawnSlices();
extern void    BuildSlices();

extern void    EnterWorker();
extern void    LeaveWorker();
extern void    InitWorkers();

extern void    SisalMain();

extern void           InitReadyList();
extern struct ActRec *RListDeQ();
extern void           RListEnQ();

extern void    StopTimer();
extern void    StartTimer();

extern int     NumWorkers;
extern int     DsaSize;
extern int     BindParallelWork;
extern int     UseGss;
extern int     UseStride;
extern int     DEFStride;
extern int     XftThreshold;
extern int     WstWindowSize;
extern int     LoopSlices;
extern int     GatherPerfInfo;
extern int     ArrayExpansion;
extern int     NoFibreOutput;
extern int     UsePrivateMemory;

extern void    InitErrorSystem();
extern int     SisalError();

extern void    DsaInit();
extern POINTER Alloc();
extern void    DeAlloc();
extern void    DeAllocToBt();

extern volatile int *SisalShutDown;

extern struct WorkerInfo *AllWorkerInfo;

extern void FreePointerSwapStorage();
extern POINTER AllocPointerSwapStorage();

extern LOCK_TYPE *UtilityLock;
extern LOCK_TYPE *SUtilityLock;

extern double TSECND();

extern char DefaultLoopStyle;
