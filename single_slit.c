/* Automatically generated file. Do not edit. 
 * Format:     ANSI C source code
 * Creator:    McXtrace <http://www.mcxtrace.org>
 * Instrument: /Users/pengfei/github/Monte_Carlo/single_slit.instr (test)
 * Date:       Sat Dec 20 02:36:49 2014
 * File:       /Users/pengfei/github/Monte_Carlo/single_slit.c
 */


#define MCCODE_STRING "McXtrace 1.1 - May. 31, 2013"
#define FLAVOR "mcxtrace"
#define FLAVOR_UPPER "MCXTRACE"
#define MC_USE_DEFAULT_MAIN
#define MC_TRACE_ENABLED
#define MC_EMBEDDED_RUNTIME

#line 1 "mccode-r.h"
/*******************************************************************************
*
* McCode, neutron/xray ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/mcstas-r.h
*
* %Identification
* Written by: KN
* Date:    Aug 29, 1997
* Release: McXtrace 1.1
* Version: $Revision: 4382 $
*
* Runtime system header for McStas.
*
* In order to use this library as an external library, the following variables
* and macros must be declared (see details in the code)
*
*   struct mcinputtable_struct mcinputtable[];
*   int mcnumipar;
*   char mcinstrument_name[], mcinstrument_source[];
*   int mctraceenabled, mcdefaultmain;
*   extern MCNUM  mccomp_storein[];
*   extern MCNUM  mcAbsorbProp[];
*   extern MCNUM  mcScattered;
*   #define MCCODE_STRING "the McStas/McXtrace version"
*
* Usage: Automatically embbeded in the c code.
*
* $Id: mccode-r.h.in 4382 2013-05-14 16:08:05Z farhi $
*
*******************************************************************************/

#ifndef MCCODE_R_H
#define MCCODE_R_H "$Revision: 4382 $"

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <errno.h>
#include <time.h>
#include <float.h>

/* If the runtime is embedded in the simulation program, some definitions can
   be made static. */

#ifdef MC_EMBEDDED_RUNTIME
#define mcstatic static
#else
#define mcstatic
#endif

#ifdef __dest_os
#if (__dest_os == __mac_os)
#define MAC
#endif
#endif

#ifdef __FreeBSD__
#define NEED_STAT_H
#endif

#if defined(__APPLE__) && defined(__GNUC__)
#define NEED_STAT_H
#endif

#ifdef NEED_STAT_H
#include <sys/stat.h>
#endif

#ifndef MC_PATHSEP_C
#ifdef WIN32
#define MC_PATHSEP_C '\\'
#define MC_PATHSEP_S "\\"
#define random rand
#define srandom srand
#else  /* !WIN32 */
#ifdef MAC
#define MC_PATHSEP_C ':'
#define MC_PATHSEP_S ":"
#else  /* !MAC */
#define MC_PATHSEP_C '/'
#define MC_PATHSEP_S "/"
#endif /* !MAC */
#endif /* !WIN32 */
#endif /* MC_PATHSEP_C */

/* the version string is replaced when building distribution with mkdist */
#ifndef MCCODE_STRING
#define MCCODE_STRING "McXtrace 1.1 - May. 31, 2013"
#endif

#ifndef MCCODE_DATE
#define MCCODE_DATE "May. 31, 2013"
#endif

#ifndef MCCODE_VERSION
#define MCCODE_VERSION "1.1"
#endif

#ifndef MCCODE_NAME
#define MCCODE_NAME "McXtrace"
#endif

#ifndef MCCODE_PARTICULE
#define MCCODE_PARTICULE "xray"
#endif

#ifndef MCCODE_LIBENV
#define MCCODE_LIBENV "MCXTRACE"
#endif

#ifndef FLAVOR_UPPER
#define FLAVOR_UPPER MCCODE_NAME
#endif

#ifdef MC_PORTABLE
#ifndef NOSIGNALS
#define NOSIGNALS 1
#endif
#endif

#ifdef MAC
#ifndef NOSIGNALS
#define NOSIGNALS 1
#endif
#endif

#if (USE_MPI == 0)
#undef USE_MPI
#endif

#ifdef USE_MPI  /* default is to disable signals with MPI, as MPICH uses them to communicate */
#ifndef NOSIGNALS
#define NOSIGNALS 1
#endif
#endif

#if (NOSIGNALS == 0)
#undef NOSIGNALS
#endif

#if (USE_NEXUS == 0)
#undef USE_NEXUS
#endif

/* I/O section part ========================================================= */

/* Note: the enum instr_formal_types definition MUST be kept
   synchronized with the one in mcstas.h and with the
   instr_formal_type_names array in cogen.c. */
enum instr_formal_types
  {
    instr_type_double, instr_type_int, instr_type_string
  };
struct mcinputtable_struct { /* defines instrument parameters */
  char *name; /* name of parameter */
  void *par;  /* pointer to instrument parameter (variable) */
  enum instr_formal_types type;
  char *val;  /* default value */
};

typedef double MCNUM;
typedef struct {MCNUM x, y, z;} Coords;
typedef MCNUM Rotation[3][3];

/* the following variables are defined in the McStas generated C code
   but should be defined externally in case of independent library usage */
#ifndef DANSE
extern struct mcinputtable_struct mcinputtable[]; /* list of instrument parameters */
extern int    mcnumipar;                          /* number of instrument parameters */
extern char   mcinstrument_name[], mcinstrument_source[]; /* instrument name and filename */
extern MCNUM  mccomp_storein[]; /* 11 coords * number of components in instrument */
extern MCNUM  mcAbsorbProp[];
extern MCNUM  mcScattered;      /* number of SCATTER calls in current component */
#ifndef MC_ANCIENT_COMPATIBILITY
extern int mctraceenabled, mcdefaultmain;
#endif
#endif

/* file I/O definitions and function prototypes */

struct mcformats_struct {
  char *Name;       /* format name: may also specify: append, partial(hidden), binary */
  char *Extension;  /* file name extension set if not specified */
  char *Header;     /* to be written as header(begin) in output file */
  char *Footer;     /* to be written as foorter(end) in output file */
  char *BeginSection; /* defines how to start a new section */
  char *EndSection;   /* defines how to end a new section */
  char *AssignTag;    /* defines how to write e.g. 'par=value' */
  char *BeginData;    /* defines how to start a data block */
  char *EndData;      /* defines how to end a data block */
  char *BeginErrors;  /* defines how to start an error(statistical) block */
  char *EndErrors;    /* defines how to end an error(statistical) block */
  char *BeginNcount;  /* defines how to start an event (number of) block */
  char *EndNcount;    /* defines how to end an event (number of) block */
  };

#ifndef MC_EMBEDDED_RUNTIME /* the mcstatic variables (from mcstas-r.c) */
extern FILE * mcsiminfo_file;     /* handle to the output siminfo file */
extern int    mcgravitation;      /* flag to enable gravitation */
extern int    mcdotrace;          /* flag to print MCDISPLAY messages */
extern struct mcformats_struct mcformats[]; /* array of all possible formats */
extern struct mcformats_struct mcformat;    /* selected format to be used */
extern struct mcformats_struct mcformat_data; /* same as above, but may be different for data blocks */
#else
mcstatic FILE *mcsiminfo_file        = NULL;
#endif

/* Useful macros ============================================================ */

/* MPI stuff */

#ifdef USE_MPI
#include "mpi.h"

#ifdef OMPI_MPI_H  /* openmpi does not use signals: we may install our sighandler */
#undef NOSIGNALS
#endif

/*
 * MPI_MASTER(i):
 * execution of i only on master node
 */
#define MPI_MASTER(statement) { \
  if(mpi_node_rank == mpi_node_root)\
  { statement; } \
}

#ifndef MPI_REDUCE_BLOCKSIZE
#define MPI_REDUCE_BLOCKSIZE 1000
#endif

int mc_MPI_Sum(double* buf, long count);
int mc_MPI_Send(void *sbuf, long count, MPI_Datatype dtype, int dest);
int mc_MPI_Recv(void *rbuf, long count, MPI_Datatype dtype, int source);

/* MPI_Finalize exits gracefully and should be preferred to MPI_Abort */
#define exit(code) do {                                   \
    MPI_Finalize();                                       \
    exit(code);                                           \
  } while(0)

#else /* !USE_MPI */
#define MPI_MASTER(instr) instr
#endif /* USE_MPI */

#ifdef USE_MPI
static int mpi_node_count;
#endif

#ifdef USE_THREADS  /* user want threads */
#error Threading (USE_THREADS) support has been removed for very poor efficiency. Use MPI/SSH grid instead.
#endif

/* I/O function prototypes ================================================== */

#ifndef CHAR_BUF_LENGTH
#define CHAR_BUF_LENGTH 1024
#endif

/* main DETECTOR structure which stores most information to write to data files */
struct mcdetector_struct {
  char   prefix[CHAR_BUF_LENGTH];     /* prefix to prepend to format specifications */
  char   filename[CHAR_BUF_LENGTH];   /* file name of monitor */
  char   position[CHAR_BUF_LENGTH];   /* position of detector component */
  char   component[CHAR_BUF_LENGTH];  /* component instance name */
  char   instrument[CHAR_BUF_LENGTH]; /* instrument name */
  char   simulation[CHAR_BUF_LENGTH]; /* simulation name, e.g. directory */
  char   type[CHAR_BUF_LENGTH];       /* data type, e.g. 0d, 1d, 2d, 3d */
  char   user[CHAR_BUF_LENGTH];       /* user name, e.g. HOME */
  char   date[CHAR_BUF_LENGTH];       /* date of simulation end/write time */
  char   title[CHAR_BUF_LENGTH];      /* title of detector */
  char   xlabel[CHAR_BUF_LENGTH];     /* X axis label */
  char   ylabel[CHAR_BUF_LENGTH];     /* Y axis label */
  char   zlabel[CHAR_BUF_LENGTH];     /* Z axis label */
  char   xvar[CHAR_BUF_LENGTH];       /* X variable name */
  char   yvar[CHAR_BUF_LENGTH];       /* Y variable name */
  char   zvar[CHAR_BUF_LENGTH];       /* Z variable name */
  char   ncount[CHAR_BUF_LENGTH];     /* number of events initially generated */
  char   limits[CHAR_BUF_LENGTH];     /* X Y Z limits, e.g. [xmin xmax ymin ymax zmin zmax] */
  char   variables[CHAR_BUF_LENGTH];  /* variables written into data block */
  char   statistics[CHAR_BUF_LENGTH]; /* center, mean and half width along axis */
  char   signal[CHAR_BUF_LENGTH];     /* min max and mean of signal (data block) */
  char   values[CHAR_BUF_LENGTH];     /* integrated values e.g. [I I_err N] */
  double xmin,xmax;                   /* min max of axes */
  double ymin,ymax;
  double zmin,zmax;
  double intensity;                   /* integrated values for data block */
  double error;
  double events;
  double min;                         /* statistics for data block */
  double max;
  double mean;
  double centerX;                     /* statistics for axes */
  double halfwidthX;
  double centerY;
  double halfwidthY;
  int    rank;                        /* dimensionaly of monitor, e.g. 0 1 2 3 */
  char   istransposed;                /* flag to transpose matrix for some formats */

  long   m,n,p;                       /* dimensions of data block and along axes */
  long   date_l;                      /* same as date, but in sec since 1970 */

  double *p0, *p1, *p2;               /* pointers to saved data, NULL when freed */
  double *p0_orig,*p1_orig,*p2_orig;  /* initial pointer in case some post processing is done
                                         with e.g. lists and MPI handling */

  FILE   *file_handle;                /* file handle for detector file */
  struct mcformats_struct format;     /* format used for that detector */
};

typedef struct mcdetector_struct MCDETECTOR;

void   mcset_ncount(unsigned long long count);    /* wrapper to get mcncount */
unsigned long long int mcget_ncount(void);            /* wrapper to set mcncount */
unsigned long long mcget_run_num(void);           /* wrapper to get mcrun_num=0:mcncount */
char *mcfull_file(char *name, char *ext); /* builds "name+ext" */

/* Needed function signatures */
MCDETECTOR mcdetector_write_data(MCDETECTOR detector);

/* output functions */
MCDETECTOR mcdetector_out_0D(char *t, double p0, double p1, double p2, char *c, Coords pos);
MCDETECTOR mcdetector_out_1D(char *t, char *xl, char *yl,
                  char *xvar, double x1, double x2, int n,
                  double *p0, double *p1, double *p2, char *f, char *c, Coords pos);
MCDETECTOR mcdetector_out_2D(char *t, char *xl, char *yl,
                  double x1, double x2, double y1, double y2, int m,
                  int n, double *p0, double *p1, double *p2, char *f,
                  char *c, Coords pos);
MCDETECTOR mcdetector_out_3D(char *t, char *xl, char *yl, char *zl,
      char *xvar, char *yvar, char *zvar,
                  double x1, double x2, double y1, double y2, double z1, double z2, int m,
                  int n, int p, double *p0, double *p1, double *p2, char *f,
                  char *c, Coords pos);
/* wrappers to output functions, that automatically set NAME and POSITION */
#define DETECTOR_OUT(p0,p1,p2) mcdetector_out_0D(NAME_CURRENT_COMP,p0,p1,p2,NAME_CURRENT_COMP,POS_A_CURRENT_COMP)
#define DETECTOR_OUT_0D(t,p0,p1,p2) mcdetector_out_0D(t,p0,p1,p2,NAME_CURRENT_COMP,POS_A_CURRENT_COMP)
#define DETECTOR_OUT_1D(t,xl,yl,xvar,x1,x2,n,p0,p1,p2,f) \
     mcdetector_out_1D(t,xl,yl,xvar,x1,x2,n,p0,p1,p2,f,NAME_CURRENT_COMP,POS_A_CURRENT_COMP)
#define DETECTOR_OUT_2D(t,xl,yl,x1,x2,y1,y2,m,n,p0,p1,p2,f) \
     mcdetector_out_2D(t,xl,yl,x1,x2,y1,y2,m,n,p0,p1,p2,f,NAME_CURRENT_COMP,POS_A_CURRENT_COMP)
#define DETECTOR_OUT_3D(t,xl,yl,zl,xv,yv,zv,x1,x2,y1,y2,z1,z2,m,n,p,p0,p1,p2,f) \
     mcdetector_out_3D(t,xl,yl,zl,xv,yv,zv,x1,x2,y1,y2,z1,z2,m,n,p,p0,p1,p2,f,NAME_CURRENT_COMP,POS_A_CURRENT_COMP)
#define DETECTOR_CUSTOM_HEADER(t)  if (t && strlen(t)) { \
     mcDetectorCustomHeader=malloc(strlen(t)); \
     if (mcDetectorCustomHeader) strcpy(mcDetectorCustomHeader, t); }

/* Following part is only embedded when not redundent with mcstas.h ========= */

#ifndef MCCODE_H

#ifndef NOSIGNALS
#include <signal.h>
#define SIG_MESSAGE(msg) strcpy(mcsig_message, msg);
#else
#define SIG_MESSAGE(msg)
#endif /* !NOSIGNALS */



/* Useful macros and constants ============================================== */

#ifndef FLT_MAX
#define FLT_MAX         3.40282347E+38F /* max decimal value of a "float" */
#endif

#ifndef MIN
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#endif
#ifndef SQR
#define SQR(x) ( (x) * (x) )
#endif
#ifndef SIGN
#define SIGN(x) (((x)>0.0)?(1):(-1))
#endif

#define RAD2MIN  ((180*60)/PI)
#define MIN2RAD  (PI/(180*60))
#define DEG2RAD  (PI/180)
#define RAD2DEG  (180/PI)
#define FWHM2RMS 0.424660900144    /* Convert between full-width-half-max and */
#define RMS2FWHM 2.35482004503     /* root-mean-square (standard deviation) */
#define HBAR     1.05457168e-34    /* [Js] h bar Planck constant CODATA 2002 */
#define MNEUTRON 1.67492728e-27    /* [kg] mass of neutron CODATA 2002 */
#define GRAVITY  9.81              /* [m/s^2] gravitational acceleration */
#define NA       6.02214179e23     /* [#atoms/g .mole] Avogadro's number*/

#ifndef PI
# ifdef M_PI
#  define PI M_PI
# else
#  define PI 3.14159265358979323846
# endif
#endif

/* wrapper to get absolute and relative position of comp */
/* mccomp_posa and mccomp_posr are defined in McStas generated C code */
#define POS_A_COMP_INDEX(index) \
    (mccomp_posa[index])
#define POS_R_COMP_INDEX(index) \
    (mccomp_posr[index])
/* number of SCATTER calls in current comp: mcScattered defined in McStas generated C code */
#define SCATTERED mcScattered

/* Retrieve component information from the kernel */
/* Name, position and orientation (both absolute and relative)  */
/* Any component: For "redundancy", see comment by KN */
#define tmp_name_comp(comp) #comp
#define NAME_COMP(comp) tmp_name_comp(comp)
#define tmp_pos_a_comp(comp) (mcposa ## comp)
#define POS_A_COMP(comp) tmp_pos_a_comp(comp)
#define tmp_pos_r_comp(comp) (mcposr ## comp)
#define POS_R_COMP(comp) tmp_pos_r_comp(comp)
#define tmp_rot_a_comp(comp) (mcrota ## comp)
#define ROT_A_COMP(comp) tmp_rot_a_comp(comp)
#define tmp_rot_r_comp(comp) (mcrotr ## comp)
#define ROT_R_COMP(comp) tmp_rot_r_comp(comp)

/* Current component name, index, position and orientation */
#define NAME_CURRENT_COMP  NAME_COMP(mccompcurname)
#define INDEX_CURRENT_COMP mccompcurindex
#define POS_A_CURRENT_COMP POS_A_COMP(mccompcurname)
#define POS_R_CURRENT_COMP POS_R_COMP(mccompcurname)
#define ROT_A_CURRENT_COMP ROT_A_COMP(mccompcurname)
#define ROT_R_CURRENT_COMP ROT_R_COMP(mccompcurname)

/* Note: The two-stage approach to MC_GETPAR is NOT redundant; without it,
* after #define C sample, MC_GETPAR(C,x) would refer to component C, not to
* component sample. Such are the joys of ANSI C.

* Anyway the usage of MCGETPAR requires that we use sometimes bare names...
*/
#define MC_GETPAR2(comp, par) (mcc ## comp ## _ ## par)
#define MC_GETPAR(comp, par) MC_GETPAR2(comp,par)

/* MCDISPLAY/trace and debugging message sent to stdout */
#ifdef MC_TRACE_ENABLED
#define DEBUG
#endif

#ifdef DEBUG
#define mcDEBUG_INSTR() if(!mcdotrace); else { printf("INSTRUMENT:\n"); printf("Instrument '%s' (%s)\n", mcinstrument_name, mcinstrument_source); }
#define mcDEBUG_COMPONENT(name,c,t) if(!mcdotrace); else {\
  printf("COMPONENT: \"%s\"\n" \
         "POS: %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g\n", \
         name, c.x, c.y, c.z, t[0][0], t[0][1], t[0][2], \
         t[1][0], t[1][1], t[1][2], t[2][0], t[2][1], t[2][2]); \
  printf("Component %30s AT (%g,%g,%g)\n", name, c.x, c.y, c.z); \
  }
#define mcDEBUG_INSTR_END() if(!mcdotrace); else printf("INSTRUMENT END:\n");
#define mcDEBUG_ENTER() if(!mcdotrace); else printf("ENTER:\n");
#define mcDEBUG_COMP(c) if(!mcdotrace); else printf("COMP: \"%s\"\n", c);
#define mcDEBUG_LEAVE() if(!mcdotrace); else printf("LEAVE:\n");
#define mcDEBUG_ABSORB() if(!mcdotrace); else printf("ABSORB:\n");
#else
#define mcDEBUG_INSTR()
#define mcDEBUG_COMPONENT(name,c,t)
#define mcDEBUG_INSTR_END()
#define mcDEBUG_ENTER()
#define mcDEBUG_COMP(c)
#define mcDEBUG_LEAVE()
#define mcDEBUG_ABSORB()
#endif

// mcDEBUG_STATE and mcDEBUG_SCATTER are defined by mcstas-r.h and mcxtrace-r.h



#ifdef TEST
#define test_printf printf
#else
#define test_printf while(0) printf
#endif

/* send MCDISPLAY message to stdout to show gemoetry */
void mcdis_magnify(char *what);
void mcdis_line(double x1, double y1, double z1,
                double x2, double y2, double z2);
void mcdis_dashed_linemcdis_dashed_line(double x1, double y1, double z1,
		       double x2, double y2, double z2, int n);
void mcdis_multiline(int count, ...);
void mcdis_rectangle(char* plane, double x, double y, double z,
		     double width, double height);
void mcdis_box(double x, double y, double z,
	       double width, double height, double length);
void mcdis_circle(char *plane, double x, double y, double z, double r);

/* selection of random number generator. default is MT */
#ifndef MC_RAND_ALG
#define MC_RAND_ALG 1
#endif

#if MC_RAND_ALG == 0
   /* Use system random() (not recommended). */
#  define MC_RAND_MAX RAND_MAX
#elif MC_RAND_ALG == 1
   /* "Mersenne Twister", by Makoto Matsumoto and Takuji Nishimura. */
#  define MC_RAND_MAX ((unsigned long)0xffffffff)
#  define random mt_random
#  define srandom mt_srandom
#elif MC_RAND_ALG == 2
   /* Algorithm used in McStas CVS-080208 and earlier (not recommended). */
#  define MC_RAND_MAX 0x7fffffff
#  define random mc_random
#  define srandom mc_srandom
#else
#  error "Bad value for random number generator choice."
#endif

typedef int mc_int32_t;
mc_int32_t mc_random(void);
void mc_srandom (unsigned int x);
unsigned long mt_random(void);
void mt_srandom (unsigned long x);

double rand01();
double randpm1();
double rand0max(double max);
double randminmax(double min, double max);

double randnorm(void);
double randtriangle(void);

#ifndef DANSE
void mcinit(void);
void mcraytrace(void);
void mcsave(FILE *);
void mcfinally(void);
void mcdisplay(void);
#endif

/* simple vector algebra ==================================================== */
#define vec_prod(x, y, z, x1, y1, z1, x2, y2, z2) \
	vec_prod_func(&x, &y, &z, x1, y1, z1, x2, y2, z2)
mcstatic inline void vec_prod_func(double *x, double *y, double *z,
		double x1, double y1, double z1, double x2, double y2, double z2);

mcstatic inline double scalar_prod(
		double x1, double y1, double z1, double x2, double y2, double z2);

#define NORM(x,y,z) \
	norm_func(&x, &y, &z)
mcstatic inline void norm_func(double *x, double *y, double *z) {
	double temp = (*x * *x) + (*y * *y) + (*z * *z);
	if (temp != 0) {
		temp = sqrt(temp);
		*x /= temp;
		*y /= temp;
		*z /= temp;
	}
}

void normal_vec(double *nx, double *ny, double *nz,
    double x, double y, double z);

/**
 * Rotate the given xyz in a certain way. Used in pol-lib
 */
#define rotate(x, y, z, vx, vy, vz, phi, ax, ay, az) \
  do { \
    double mcrt_tmpx = (ax), mcrt_tmpy = (ay), mcrt_tmpz = (az); \
    double mcrt_vp, mcrt_vpx, mcrt_vpy, mcrt_vpz; \
    double mcrt_vnx, mcrt_vny, mcrt_vnz, mcrt_vn1x, mcrt_vn1y, mcrt_vn1z; \
    double mcrt_bx, mcrt_by, mcrt_bz; \
    double mcrt_cos, mcrt_sin; \
    NORM(mcrt_tmpx, mcrt_tmpy, mcrt_tmpz); \
    mcrt_vp = scalar_prod((vx), (vy), (vz), mcrt_tmpx, mcrt_tmpy, mcrt_tmpz); \
    mcrt_vpx = mcrt_vp*mcrt_tmpx; \
    mcrt_vpy = mcrt_vp*mcrt_tmpy; \
    mcrt_vpz = mcrt_vp*mcrt_tmpz; \
    mcrt_vnx = (vx) - mcrt_vpx; \
    mcrt_vny = (vy) - mcrt_vpy; \
    mcrt_vnz = (vz) - mcrt_vpz; \
    vec_prod(mcrt_bx, mcrt_by, mcrt_bz, \
             mcrt_tmpx, mcrt_tmpy, mcrt_tmpz, mcrt_vnx, mcrt_vny, mcrt_vnz); \
    mcrt_cos = cos((phi)); mcrt_sin = sin((phi)); \
    mcrt_vn1x = mcrt_vnx*mcrt_cos + mcrt_bx*mcrt_sin; \
    mcrt_vn1y = mcrt_vny*mcrt_cos + mcrt_by*mcrt_sin; \
    mcrt_vn1z = mcrt_vnz*mcrt_cos + mcrt_bz*mcrt_sin; \
    (x) = mcrt_vpx + mcrt_vn1x; \
    (y) = mcrt_vpy + mcrt_vn1y; \
    (z) = mcrt_vpz + mcrt_vn1z; \
  } while(0)

/**
 * Mirror (xyz) in the plane given by the point (rx,ry,rz) and normal (nx,ny,nz)
 *
 * TODO: This define is seemingly never used...
 */
#define mirror(x,y,z,rx,ry,rz,nx,ny,nz) \
  do { \
    double mcrt_tmpx= (nx), mcrt_tmpy = (ny), mcrt_tmpz = (nz); \
    double mcrt_tmpt; \
    NORM(mcrt_tmpx, mcrt_tmpy, mcrt_tmpz); \
    mcrt_tmpt=scalar_prod((rx),(ry),(rz),mcrt_tmpx,mcrt_tmpy,mcrt_tmpz); \
    (x) = rx -2 * mcrt_tmpt*mcrt_rmpx; \
    (y) = ry -2 * mcrt_tmpt*mcrt_rmpy; \
    (z) = rz -2 * mcrt_tmpt*mcrt_rmpz; \
  } while (0)

Coords coords_set(MCNUM x, MCNUM y, MCNUM z);
Coords coords_get(Coords a, MCNUM *x, MCNUM *y, MCNUM *z);
Coords coords_add(Coords a, Coords b);
Coords coords_sub(Coords a, Coords b);
Coords coords_neg(Coords a);
Coords coords_scale(Coords b, double scale);
double coords_sp(Coords a, Coords b);
Coords coords_xp(Coords b, Coords c);
void   coords_print(Coords a);
mcstatic inline void coords_norm(Coords* c);

void rot_set_rotation(Rotation t, double phx, double phy, double phz);
int  rot_test_identity(Rotation t);
void rot_mul(Rotation t1, Rotation t2, Rotation t3);
void rot_copy(Rotation dest, Rotation src);
void rot_transpose(Rotation src, Rotation dst);
Coords rot_apply(Rotation t, Coords a);

void mccoordschange(Coords a, Rotation t, double *x, double *y, double *z,
    double *vx, double *vy, double *vz, double *sx, double *sy, double *sz);
void
mccoordschange_polarisation(Rotation t, double *sx, double *sy, double *sz);

double mcestimate_error(double N, double p1, double p2);
void mcreadparams(void);

/* this is now in mcstas-r.h and mcxtrace-r.h as the number of state parameters is no longer equal*/
/* void mcsetstate(double x, double y, double z, double vx, double vy, double vz,
                double t, double sx, double sy, double sz, double p);
*/
void mcgenstate(void);

/* trajectory/shape intersection routines */
int inside_rectangle(double, double, double, double);
int box_intersect(double *dt_in, double *dt_out, double x, double y, double z,
    double vx, double vy, double vz, double dx, double dy, double dz);
int cylinder_intersect(double *t0, double *t1, double x, double y, double z,
    double vx, double vy, double vz, double r, double h);
int sphere_intersect(double *t0, double *t1, double x, double y, double z,
                 double vx, double vy, double vz, double r);
/* second order equation roots */
int solve_2nd_order(double *t1, double *t2,
    double A,  double B,  double C);

/* random vector generation to shape */
void randvec_target_circle(double *xo, double *yo, double *zo,
    double *solid_angle, double xi, double yi, double zi, double radius);
#define randvec_target_sphere randvec_target_circle
void randvec_target_rect_angular(double *xo, double *yo, double *zo,
    double *solid_angle,
               double xi, double yi, double zi, double height, double width, Rotation A);
#define randvec_target_rect(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9)  randvec_target_rect_real(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,0,0,0,1)
void randvec_target_rect_real(double *xo, double *yo, double *zo,
    double *solid_angle,
	       double xi, double yi, double zi, double height, double width, Rotation A,
			 double lx, double ly, double lz, int order);

/* this is the main() */
int mccode_main(int argc, char *argv[]);


#endif /* !MCCODE_H */

#endif /* MCCODE_R_H */
/* End of file "mccode-r.h". */

#line 694 "/Users/pengfei/github/Monte_Carlo/single_slit.c"

#line 1 "mcxtrace-r.h"
/*******************************************************************************
*
* McXtrace, X-ray ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/mcxtrace-r.h
*
* %Identification
* Written by: KN
* Date:    Aug 29, 1997
* Release: McXtrace X.Y
* Version: $Revision: 4382 $
*
* Runtime system header for McXtrace.
*
* In order to use this library as an external library, the following variables
* and macros must be declared (see details in the code)
*
*   struct mcinputtable_struct mcinputtable[];
*   int mcnumipar;
*   char mcinstrument_name[], mcinstrument_source[];
*   int mctraceenabled, mcdefaultmain;
*   extern MCNUM  mccomp_storein[];
*   extern MCNUM  mcAbsorbProp[];
*   extern MCNUM  mcScattered;
*   #define MCCODE_STRING "the McXtrace version"
*
* Usage: Automatically embbeded in the c code.
*
*******************************************************************************/

#ifndef MCXTRACE_R_H
#define MCXTRACE_R_H "$Revision: 4382 $"

/* Following part is only embedded when not redundant with mcstas.h ========= */

#ifndef MCCODE_H

#define CELE     1.602176487e-19   /* [C] Elementary charge CODATA 2006*/
#define M_C      299792458         /* [m/s] speed of light CODATA 2006*/
#define E2K      0.506773091264796 /* Convert k[1/AA] to E [keV] (CELE/(HBAR*M_C)*1e-10)*1e3 */
#define K2E      1.97326972808327  /*Convert E[keV] to k[1/AA] (1e10*M_C*HBAR/CELE)/1e3 */
#define RE       2.8179402894e-5   /*[AA] Thomson scattering length*/

#define SCATTER do {mcDEBUG_SCATTER(mcnlx, mcnly, mcnlz, mcnlkx, mcnlky, mcnlkz, \
    mcnlphi, mcnlt, mcnlEx,mcnlEy,mcnlEz, mcnlp); mcScattered++;} while(0)
#define ABSORB do {mcDEBUG_STATE(mcnlx, mcnly, mcnlz, mcnlkx, mcnlky, mcnlkz, \
    mcnlphi, mcnlt, mcnlEx,mcnlEy,mcnlEz, mcnlp); mcDEBUG_ABSORB(); goto mcabsorb;} while(0)

#define STORE_XRAY(index, x,y,z, kx,ky,kz, phi, t, Ex,Ey,Ez, p) \
  mcstore_xray(mccomp_storein,index, x,y,z, kx,ky,kz, phi, t, Ex,Ey,Ez, p);
#define RESTORE_XRAY(index, x,y,z, kx,ky,kz, phi, t, Ex,Ey,Ez, p) \
  mcrestore_xray(mccomp_storein,index, &x,&y,&z, &kx,&ky,&kz, &phi, &t, &Ex,&Ey,&Ez, &p);

/*magnet stuff is probably redundant*/
#define MAGNET_ON \
  do { \
    mcMagnet = 1; \
  } while(0)

#define MAGNET_OFF \
  do { \
    mcMagnet = 0; \
  } while(0)

#define ALLOW_BACKPROP \
  do { \
    mcallowbackprop = 1; \
  } while(0)

#define DISALLOW_BACKPROP \
  do { \
    mcallowbackprop = 0; \
  } while(0)

#define PROP_MAGNET(dt) \
  do { \
    /* change coordinates from local system to magnet system */ \
    Rotation rotLM, rotTemp; \
    Coords   posLM = coords_sub(POS_A_CURRENT_COMP, mcMagnetPos); \
    rot_transpose(ROT_A_CURRENT_COMP, rotTemp); \
    rot_mul(rotTemp, mcMagnetRot, rotLM); \
    mcMagnetPrecession(mcnlx, mcnly, mcnlz, mcnlt, mcnlvx, mcnlvy, mcnlvz, \
	   	       &mcnlsx, &mcnlsy, &mcnlsz, dt, posLM, rotLM); \
  } while(0)

#define mcPROP_DT(dt) \
  do { \
    if (mcMagnet && dt > 0) PROP_MAGNET(dt);\
    mcnlx += mcnlvx*(dt); \
    mcnly += mcnlvy*(dt); \
    mcnlz += mcnlvz*(dt); \
    mcnlt += (dt); \
    if (isnan(p) || isinf(p)) { mcAbsorbProp[INDEX_CURRENT_COMP]++; ABSORB; }\
  } while(0)

/*An interrupt a'la mcMagnet should be inserted below if there's non-zero permeability*/
/*perhaps some kind of PROP_POL*/

#define mcPROP_DL(dl) \
  do { \
    MCNUM k=sqrt( scalar_prod(mcnlkx,mcnlky,mcnlkz,mcnlkx,mcnlky,mcnlkz));\
    mcnlx += (dl)*mcnlkx/k;\
    mcnly += (dl)*mcnlky/k;\
    mcnlz += (dl)*mcnlkz/k;\
    mcnlphi += 1e10*k*(dl);\
    mcnlt += (dl)/((double)M_C);\
  }while (0)

/*gravity not an issue with x-rays*/
/* ADD: E. Farhi, Aug 6th, 2001 PROP_GRAV_DT propagation with acceleration. */
#define PROP_GRAV_DT(dt, Ax, Ay, Az) \
  do { \
    if(dt < 0 && mcallowbackprop == 0) { mcAbsorbProp[INDEX_CURRENT_COMP]++; ABSORB; }\
    if (mcMagnet) printf("Spin precession gravity\n"); \
    mcnlx  += mcnlvx*(dt) + (Ax)*(dt)*(dt)/2; \
    mcnly  += mcnlvy*(dt) + (Ay)*(dt)*(dt)/2; \
    mcnlz  += mcnlvz*(dt) + (Az)*(dt)*(dt)/2; \
    mcnlvx += (Ax)*(dt); \
    mcnlvy += (Ay)*(dt); \
    mcnlvz += (Az)*(dt); \
    mcnlt  += (dt); \
    DISALLOW_BACKPROP;\
  } while(0)

/*adapted from PROP_DT(dt)*//*{{{*/
#define PROP_DL(dl) \
  do{ \
    if( dl <0 && mcallowbackprop == 0) { (mcAbsorbProp[INDEX_CURRENT_COMP])++; ABSORB; }; \
    mcPROP_DL(dl); \
    DISALLOW_BACKPROP;\
  } while (0)

#define PROP_DT(dt) \
  do { \
    if(dt < 0 && mcallowbackprop == 0) { mcAbsorbProp[INDEX_CURRENT_COMP]++; ABSORB; }; \
    if (mcgravitation) { Coords mcLocG; double mc_gx, mc_gy, mc_gz; \
    mcLocG = rot_apply(ROT_A_CURRENT_COMP, coords_set(0,-GRAVITY,0)); \
    coords_get(mcLocG, &mc_gx, &mc_gy, &mc_gz); \
    PROP_GRAV_DT(dt, mc_gx, mc_gy, mc_gz); } \
    else mcPROP_DT(dt); \
    DISALLOW_BACKPROP;\
  } while(0)/*}}}*/

#define PROP_Z0 \
  mcPROP_P0(z)

#define PROP_X0 \
  mcPROP_P0(x)

#define PROP_Y0 \
  mcPROP_P0(y)

#define mcPROP_P0(P) \
  do { \
    MCNUM mc_dl,mc_k; \
    if(mcnlk ## P == 0) { mcAbsorbProp[INDEX_CURRENT_COMP]++; ABSORB; }; \
    mc_k=sqrt(scalar_prod(mcnlkx,mcnlky,mcnlkz,mcnlkx,mcnlky,mcnlkz));\
    mc_dl= -mcnl ## P * mc_k / mcnlk ## P;\
    if(mc_dl<0 && mcallowbackprop==0) { mcAbsorbProp[INDEX_CURRENT_COMP]++; ABSORB; };\
    PROP_DL(mc_dl);\
  } while(0)

void mcsetstate(double x, double y, double z, double kx, double ky, double kz,
    double phi, double t, double Ex, double Ey, double Ez, double p);


#endif /* !MCCODE_H */


#ifdef DEBUG

#define mcDEBUG_STATE(x,y,z,kx,ky,kz,phi,t,Ex,Ey,Ez,p) if(!mcdotrace); else \
  printf("STATE: %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g\n", \
      x,y,z,kx,ky,kz,phi,t,Ex,Ey,Ez,p);
#define mcDEBUG_SCATTER(x,y,z,kx,ky,kz,phi,t,Ex,Ey,Ez,p) if(!mcdotrace); else \
  printf("SCATTER: %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g\n", \
      x,y,z,kx,ky,kz,phi,t,Ex,Ey,Ez,p);

#else

#define mcDEBUG_STATE(x,y,z,kx,ky,kz,phi,t,Ex,Ey,Ez,p)
#define mcDEBUG_SCATTER(x,y,z,kx,ky,kz,phi,t,Ex,Ey,Ez,p)

#endif


#endif /* MCXTRACE_R_H */
/* End of file "mcxtrace-r.h". */

#line 889 "/Users/pengfei/github/Monte_Carlo/single_slit.c"

#line 1 "nexus-lib.h"
/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2008, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/nexus-lib.h
*
* %Identification
* Written by: EF
* Date:    Jan 17, 2007
* Release: McStas CVS-080208
* Version: $Revision: 4382 $
*
* NeXus Runtime system header for McStas.
* Overrides default mcstas runtime functions.
* Embedded within instrument in runtime mode.
*
* Usage: Automatically embbeded in the c code whenever required.
*
*******************************************************************************/

#ifdef USE_NEXUS

#include "napi.h"
#include <sys/stat.h>

#include <sys/types.h>
#include <ctype.h>

/* NeXus variables to be used in functions */
NXhandle mcnxHandle;
char    *mcnxFilename=NULL;
char     mcnxversion[128];       /* init in cogen_init: 4,5 xml and compress */

/* NeXus output functions that replace calls to pfprintf in mcstas-r */
int mcnxfile_init(char *name, char *ext, char *mode, NXhandle *nxhandle);
int mcnxfile_close(NXhandle *nxHandle);

/* header/footer. f=mcsiminfo_file, datafile */
/* creates Entry=valid_parent+file+timestamp */
int mcnxinfo_header(NXhandle nxhandle, char *part,
    char *pre,                  /* %1$s  PRE  */
    char *instrname,            /* %2$s  SRC  */
    char *file,                 /* %3$s  FIL  */
    char *format_name,          /* %4$s  FMT  */
    char *date,                 /* %5$s  DAT  */
    char *user,                 /* %6$s  USR  */
    char *valid_parent,         /* %7$s  PAR = file */
    long  date_l);               /* %8$li DATL */

/* tag=value */
int mcnxinfo_tag(NXhandle nxhandle,
    char *pre,          /* %1$s PRE */
    char *valid_section,/* %2$s SEC */
    char *name,         /* %3$s NAM */
    char *value);        /* %4$s VAL */

/* output instrument/description */
int mcnxfile_instrcode(NXhandle nxhandle, 
    char *name,
    char *parent);

/* begin/end section */
int mcnxfile_section(NXhandle nxhandle, char *part,
    char *pre,          /* %1$s  PRE  */
    char *type,         /* %2$s  TYP  */
    char *name,         /* %3$s  NAM  */
    char *valid_name,   /* %4$s  VNA  */
    char *parent,       /* %5$s  PAR  */
    char *valid_parent, /* %6$s  VPA  */
    int   level);        /* %7$i  LVL */

/* data block begin/end */
int mcnxfile_data(NXhandle nxhandle, MCDETECTOR detector, char *part,
  char *valid_parent, char *valid_xlabel, char *valid_ylabel, char *valid_zlabel);

/* Prototype for function in mccode-r.c only included when USE_NEXUS */
int mcnxfile_parameters(NXhandle nxhandle);

#endif
/* End of file "nexus-lib.h". */

#line 976 "/Users/pengfei/github/Monte_Carlo/single_slit.c"

#line 1 "nexus-lib.c"
/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2006, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/nexus-lib.c
*
* %Identification
* Written by: KN
* Date:    Jan 17, 2007
* Release: McStas 1.10
* Version: $Revision: 4382 $
*
* NeXus Runtime output functions for McStas.
* Overrides default mcstas runtime functions.
* Embedded within instrument in runtime mode.
*
* Usage: Automatically embbeded in the C code whenever required.
*
*******************************************************************************/

#ifdef USE_NEXUS

/*******************************************************************************
* mcnxfile_init: Initialize NeXus file (open it). handles NeXus 4/5 and compression
* Returns: NX_ERROR or NX_OK
*******************************************************************************/
int mcnxfile_init(char *name, char *ext, char *mode, NXhandle *nxhandle)
{
  int mcnxMode=NXACC_CREATE5;
  char mcnxExt[CHAR_BUF_LENGTH];
  strcpy(mcnxExt, ext);
  char nxversion[CHAR_BUF_LENGTH];
  int i;
  if (!mcnxversion || !strlen(mcnxversion)) strcpy(nxversion, "5 zip");
  else for (i=0; i< strlen(mcnxversion) && i < 128; nxversion[i]=tolower(mcnxversion[i++]));

  if    (strstr(nxversion,"xml")) { mcnxMode =NXACC_CREATEXML; strcpy(mcnxExt, "xml"); }
  else if (strstr(nxversion,"4")) { mcnxMode =NXACC_CREATE;    strcpy(mcnxExt, "h4"); }
  else if (strstr(nxversion,"5")) { mcnxMode =NXACC_CREATE5;   strcpy(mcnxExt, "h5"); }

  if (!strcmp(mode, "a"))    mcnxMode |= NXACC_RDWR;
  mcnxFilename = mcfull_file(name, mcnxExt);
  if (NXopen(mcnxFilename, mcnxMode, nxhandle) == NX_ERROR) {
    fprintf(stderr, "Warning: NeXus: could not open file %s\n", mcnxFilename);
    mcsiminfo_file = NULL;
  } else { mcsiminfo_file=(FILE*)mcnxFilename; }
  return(mcsiminfo_file != NULL);
}

/*******************************************************************************
* mcnxfile_close: Close NeXus file
* Returns: NX_ERROR or NX_OK
*******************************************************************************/
int mcnxfile_close(NXhandle *nxHandle)
{
  return(NXclose(nxHandle));
}

/*******************************************************************************
* mcnxinfo_header: Write general header/footer information tags (header/footer)
*                  into e.g. mcsiminfo_file, datafile
*                  Group and DataSet (information) must have been opened
* Returns: NX_ERROR or NX_OK
*******************************************************************************/
int mcnxinfo_header(NXhandle nxhandle, char *part,
    char *pre,                  /* %1$s  PRE  */
    char *instrname,            /* %2$s  SRC  */
    char *file,                 /* %3$s  FIL  */
    char *format_name,          /* %4$s  FMT  */
    char *date,                 /* %5$s  DAT  */
    char *user,                 /* %6$s  USR  */
    char *valid_parent,         /* %7$s  PAR = file */
    long  date_l)               /* %8$li DATL */
{
  if (!strcmp(part, "header")) {
    if (NXputattr(nxhandle, "user_name", user, strlen(user), NX_CHAR) == NX_ERROR) {
      fprintf(stderr, "Warning: NeXus: could not write header information in /%s/%s/%s\n", 
        file, instrname, valid_parent);
      return(NX_ERROR);
    }
    char creator[CHAR_BUF_LENGTH];
    sprintf(creator, "%s gerenated with " MCCODE_STRING " (" MCCODE_DATE ") [www.mccode.org]", instrname);
    NXputattr(nxhandle, "creator", creator, strlen(creator), NX_CHAR);
    NXputattr(nxhandle, "simulation_begin", date, strlen(date), NX_CHAR);
    char *url="http://www.nexusformat.org/";
    NXputattr(nxhandle, "URL", url, strlen(url), NX_CHAR);
    char *browser="hdfview or NXbrowse or HDFExplorer";
    NXputattr(nxhandle, "Browser", browser, strlen(browser), NX_CHAR);
#if defined (USE_MPI) 
    NXputattr (nxhandle, "number_of_nodes", &mpi_node_count, 1, NX_INT32);
#endif
    return(NXputattr(nxhandle, "Format", format_name, strlen(format_name), NX_CHAR));
  } else
    return(NXputattr(nxhandle, "simulation_end", date, strlen(date), NX_CHAR));
  
} /* mcnxinfo_header */

/*******************************************************************************
* mcnxinfo_tag: write a single tag
*               Group and DataSet (information) must have been opened
* Returns: NX_ERROR or NX_OK
*******************************************************************************/
int mcnxinfo_tag(NXhandle nxhandle,
    char *pre,          /* %1$s PRE */
    char *valid_section,/* %2$s SEC */
    char *name,         /* %3$s NAM */
    char *value)        /* %4$s VAL */
{
  return(NXputattr(nxhandle, name, value, strlen(value), NX_CHAR));
} /* mcnxinfo_tag */

/*******************************************************************************
* mcnxfile_instrcode: writes the instrument description file
*                   open/close a new 'description' Data Set in the current opened Group
* Returns: NX_ERROR or NX_OK
*******************************************************************************/
int mcnxfile_instrcode(NXhandle nxhandle, 
    char *name,
    char *parent)
{
  FILE *f;
  char *instr_code=NULL;
  char nxname[CHAR_BUF_LENGTH];
  int length;
  
  struct stat stfile;
  if (stat(name,&stfile) != 0) {
    instr_code = (char*)malloc(CHAR_BUF_LENGTH);
    if (instr_code) 
      sprintf(instr_code, "File %s not found (instrument description %s is missing)", 
        name, parent);
  } else {
    long filesize = stfile.st_size;
    f=fopen(name, "r");
    instr_code = (char*)malloc(filesize);
    if (instr_code && f) fread(instr_code, 1, filesize, f);
    if (f) fclose(f);
  }
  length = instr_code ? strlen(instr_code) : 0;
  if (length) {
    time_t t;
    NXmakedata(nxhandle, "description", NX_CHAR, 1, &length);
    if (NXopendata(nxhandle, "description") == NX_ERROR) {
      fprintf(stderr, "Warning: NeXus: could not write instrument description %s (%s)\n", 
        name, parent);
      free(instr_code);
      return(NX_ERROR);
    }
    NXputdata (nxhandle, instr_code);
    free(instr_code);
    NXputattr (nxhandle, "file_name", name, strlen(name), NX_CHAR);
    NXputattr (nxhandle, "file_size", &length, 1, NX_INT32);
    t=stfile.st_mtime; strncpy(nxname, ctime(&t), CHAR_BUF_LENGTH);
    NXputattr (nxhandle, "file_date", nxname, strlen(nxname), NX_CHAR);
    NXputattr (nxhandle, "MCCODE_STRING", MCCODE_STRING, strlen(MCCODE_STRING), NX_CHAR);
    NXputattr (nxhandle, "name", parent, strlen(parent), NX_CHAR);
    
    return(NXclosedata(nxhandle));
  } else
  return(NX_ERROR);
} /* mcnxfile_instrcode */

/*******************************************************************************
* mcnxfile_section: begin/end a section
*                   open a new 'section' Group and an 'information' Data Set
*                   close the current Group when part="end"
*                   the Data Set 'information' is not closed here
* Returns: NX_ERROR or NX_OK
*******************************************************************************/
int mcnxfile_section(NXhandle nxhandle, char *part,
    char *pre,          /* %1$s  PRE  */
    char *type,         /* %2$s  TYP  */
    char *name,         /* %3$s  NAM  */
    char *valid_name,   /* %4$s  VNA  */
    char *parent,       /* %5$s  PAR  */
    char *valid_parent, /* %6$s  VPA  */
    int   level)        /* %7$i  LVL */
{
  if (!strcmp(part, "end")) {
    int ret;
    ret = NXclosegroup(nxhandle);
    if (ret == NX_ERROR)
      fprintf(stderr, "Warning: NeXus: could not close group %s (%s)\n", 
          valid_name, type);
    return(ret);
  }
  
  if (!strcmp(part, "begin")) {
    int length;
    char nxtype[CHAR_BUF_LENGTH];
    char nxname[CHAR_BUF_LENGTH];
    
    if (!strcmp(type, "instrument"))      strcpy(nxname, "instrument");
    else if (!strcmp(type, "simulation")) strcpy(nxname, "simulation");
    else strcpy(nxname, valid_name);
    snprintf(nxtype, CHAR_BUF_LENGTH, "NX%s", type);
    
    NXMDisableErrorReporting(); /* unactivate NeXus error messages */
    NXmakegroup(nxhandle, nxname, nxtype);
    NXMEnableErrorReporting();  /* enable NeXus error messages */
    
    if (NXopengroup(nxhandle, nxname, nxtype) == NX_ERROR) {
      fprintf(stderr, "Warning: NeXus: could not open group %s (%s) to store 'information'\n", 
          nxname, nxtype);
      return(NX_ERROR);
    }
    /* open a SDS to store attributes */
    snprintf(nxname, CHAR_BUF_LENGTH, "Information about %s of type %s is stored in attributes", name, nxtype);
    length = strlen(nxname);
    
    NXMDisableErrorReporting(); /* unactivate NeXus error messages */
    NXmakedata(nxhandle, "information", NX_CHAR, 1, &length);
    NXMEnableErrorReporting();  /* enable NeXus error messages */
    if (NXopendata(nxhandle, "information") == NX_ERROR) {
      fprintf(stderr, "Warning: NeXus: could not open 'information' for %s (%s)\n", 
          name, nxtype);
      return(NX_ERROR);
    }
    NXputdata (nxhandle, nxname);
    NXputattr(nxhandle, "name", name, strlen(name), NX_CHAR);
    NXputattr(nxhandle, "parent", parent, strlen(parent), NX_CHAR);

  }
  return(NX_OK);
} /* mcnxfile_section */

/*******************************************************************************
* mcnxfile_section: begin/end a data block (data/errors/events)
*                   open/close a 'part' Data Set
*                   open/close Axes (except for lists)
*                   handles compressed Data Set
* Returns: NX_ERROR or NX_OK
*******************************************************************************/
/* mcnxfile_datablock: data block begin/end. Returns: NX_ERROR or NX_OK */
int mcnxfile_data(NXhandle nxhandle, MCDETECTOR detector, char *part,
  char *valid_parent, char *valid_xlabel, char *valid_ylabel, char *valid_zlabel)
{
  /* write axes, only for data */
  if (strstr(part, "data")) {
    int i;
    if (!strstr(detector.format.Name, "list")) {
    
      if (detector.m > 1) {       /* X axis */
        double axis[detector.m];
        int dim=(int)detector.m;
        for(i = 0; i < detector.m; i++)
          axis[i] = detector.xmin+(detector.xmax-detector.xmin)*(i+0.5)/detector.m;
        if (strstr(mcnxversion,"compress") || strstr(mcnxversion,"zip"))
          NXcompmakedata(nxhandle, valid_xlabel, NX_FLOAT64, 1, &dim, NX_COMP_LZW, &dim);
        else
          NXmakedata(nxhandle, valid_xlabel, NX_FLOAT64, 1, &dim);

        if (NXopendata(nxhandle, valid_xlabel) == NX_ERROR) {
          fprintf(stderr, "Warning: could not open X axis %s in %s\n",
            valid_xlabel, detector.filename);
          return(NX_ERROR);
        }
        NXputdata (nxhandle, axis);
        NXputattr (nxhandle, "long_name", detector.xlabel, strlen(detector.xlabel), NX_CHAR);
        NXputattr (nxhandle, "short_name", detector.xvar, strlen(detector.xvar), NX_CHAR);
        int naxis=1;
        NXputattr (nxhandle, "axis", &naxis, 1, NX_INT32);
        NXputattr (nxhandle, "units", detector.xvar, strlen(detector.xvar), NX_CHAR);
        int nprimary=1;
        NXputattr (nxhandle, "primary", &nprimary, 1, NX_INT32);
        NXclosedata(nxhandle);
      }
      
      if (detector.n >= 1) {      /* Y axis */
        double axis[detector.n];
        int dim=(int)detector.n;
        for(i = 0; i < detector.n; i++)
          axis[i] = detector.ymin+(detector.ymax-detector.ymin)*(i+0.5)/detector.n;
        if (strstr(mcnxversion,"compress") || strstr(mcnxversion,"zip"))
          NXcompmakedata(nxhandle, valid_ylabel, NX_FLOAT64, 1, &dim, NX_COMP_LZW, &dim);
        else
          NXmakedata(nxhandle, valid_ylabel, NX_FLOAT64, 1, &dim);

        if (NXopendata(nxhandle, valid_ylabel) == NX_ERROR) {
          fprintf(stderr, "Warning: could not open Y axis %s in %s\n",
            valid_ylabel, detector.filename);
          return(NX_ERROR);
        }
        NXputdata (nxhandle, axis);
        NXputattr (nxhandle, "long_name", detector.ylabel, strlen(detector.ylabel), NX_CHAR);
        NXputattr (nxhandle, "short_name", detector.yvar, strlen(detector.yvar), NX_CHAR);
        int naxis=2;
        NXputattr (nxhandle, "axis", &naxis, 1, NX_INT32);
        NXputattr (nxhandle, "units", detector.yvar, strlen(detector.yvar), NX_CHAR);
        int nprimary=1;
        NXputattr (nxhandle, "primary", &nprimary, 1, NX_INT32);
        NXclosedata(nxhandle);
      }
      
      if (detector.p > 1) {     /* Z axis */
        double axis[detector.p];
        int dim=(int)detector.p;
        for(i = 0; i < detector.p; i++)
          axis[i] = detector.zmin+(detector.zmax-detector.zmin)*(i+0.5)/detector.p;
        if (strstr(mcnxversion,"compress") || strstr(mcnxversion,"zip"))
          NXcompmakedata(nxhandle, valid_zlabel, NX_FLOAT64, 1, &dim, NX_COMP_LZW, &dim);
        else
          NXmakedata(nxhandle, valid_zlabel, NX_FLOAT64, 1, &dim);

        if (NXopendata(nxhandle, valid_zlabel) == NX_ERROR) {
          fprintf(stderr, "Warning: could not open Z axis %s in %s\n",
            valid_ylabel, detector.filename);
          return(NX_ERROR);
        }
        NXputdata (nxhandle, axis);
        NXputattr (nxhandle, "long_name", detector.zlabel, strlen(detector.zlabel), NX_CHAR);
        NXputattr (nxhandle, "short_name", detector.zvar, strlen(detector.zvar), NX_CHAR);
        int naxis=3;
        NXputattr (nxhandle, "axis", &naxis, 1, NX_INT32);
        NXputattr (nxhandle, "units", detector.zvar, strlen(detector.zvar), NX_CHAR);
        int nprimary=1;
        NXputattr (nxhandle, "primary", &nprimary, 1, NX_INT32);
        NXclosedata(nxhandle);
      }
    } /* !list */
  } /* end format != list for data */
  
  /* write data */
  int dims[3]={detector.m,detector.n,detector.p};  /* number of elements to write */
  char *nxname=part;
  double *data;
  if (strstr(part,"data"))         { data=detector.p1; }
  else if (strstr(part,"errors"))  { data=detector.p2; }
  else if (strstr(part,"ncount"))  { data=detector.p0; }
  /* ignore errors for making/opening data (in case this has already been done */
  if (strstr(mcnxversion,"compress") || strstr(mcnxversion,"zip"))
    NXmakedata(nxhandle, nxname, NX_FLOAT64, detector.rank, dims);
  else
    NXcompmakedata(nxhandle, nxname, NX_FLOAT64, detector.rank, dims, NX_COMP_LZW, dims);

  if (NXopendata(nxhandle, nxname) == NX_ERROR) {
        fprintf(stderr, "Warning: could not open DataSet '%s' in %s\n",
          nxname, detector.filename);
        return(NX_ERROR);
      }
  NXputdata (nxhandle, data);
  NXputattr(nxhandle, "parent", valid_parent, strlen(valid_parent), NX_CHAR);
  int signal=1;
  if (strstr(part,"data")) {
    NXputattr(nxhandle, "signal", &signal, 1, NX_INT32);
    NXputattr(nxhandle, "short_name", detector.filename, strlen(detector.filename), NX_CHAR);
  }
  char nxtitle[CHAR_BUF_LENGTH];
  sprintf(nxtitle, "%s '%s'", nxname, detector.title);
  NXputattr(nxhandle, "long_name", nxtitle, strlen(nxtitle), NX_CHAR);
  /* first write attributes */
  char creator[CHAR_BUF_LENGTH];
  sprintf(creator, "%s/%s", mcinstrument_name, valid_parent);
  NXputattr(nxhandle, "creator", creator, strlen(creator), NX_CHAR);
  return(NXclosedata(nxhandle));
} /* mcnxfile_datablock */


#endif /* USE_NEXUS */
/* End of file "nexus-lib.c". */

#line 1343 "/Users/pengfei/github/Monte_Carlo/single_slit.c"

#line 1 "mccode-r.c"
/*******************************************************************************
*
* McCode, neutron/xray ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/mcstas-r.c
*
* %Identification
* Written by: KN
* Date:    Aug 29, 1997
* Release: McStas X.Y/McXtrace X.Y
* Version: $Revision: 4382 $
*
* Runtime system for McStas and McXtrace.
* Embedded within instrument in runtime mode.
* Contains SECTIONS:
*   MPI handling (sum, send, recv)
*   format definitions
*   I/O
*   mcdisplay support
*   random numbers
*   coordinates handling
*   vectors math (solve 2nd order, normals, randvec...)
*   parameter handling
*   signal and main handlers
*
* Usage: Automatically embbeded in the c code whenever required.
*
* $Id: mccode-r.c 4382 2013-05-14 16:08:05Z farhi $
*
*******************************************************************************/

/*******************************************************************************
* The I/O format definitions and functions
*******************************************************************************/


/** Include header files to avoid implicit declarations (not allowed on LLVM) */
#include <ctype.h>
#include <sys/types.h>

// UNIX specific headers (non-Windows)
#if defined(__unix__) || defined(__APPLE__)
#include <unistd.h>
#include <sys/stat.h>
#endif


#ifndef DANSE
#ifdef MC_ANCIENT_COMPATIBILITY
int mctraceenabled = 0;
int mcdefaultmain  = 0;
#endif
/* else defined directly in the McStas generated C code */

static   long mcseed                 = 0; /* seed for random generator */
static   int  mcascii_only           = 0; /* flag for no header */
static   int  mcsingle_file          = 0; /* flag for storing all detectors into a single file */
static   long mcstartdate            = 0; /* start simulation time */
static   int  mcdisable_output_files = 0; /* --no-output-files */
mcstatic int  mcgravitation          = 0; /* use gravir=tation flag, for PROP macros */
int      mcMagnet                    = 0; /* megnet stack flag */
mcstatic int  mcdotrace              = 0; /* flag for --trace and messages for DISPLAY */
/* mcstatic FILE *mcsiminfo_file        = NULL; */
static   char *mcdirname             = NULL;      /* name of output directory */
static   char *mcsiminfo_name        = "mcstas";  /* default output sim file name */
int      mcallowbackprop             = 0;         /* flag to enable negative/backprop */
char*    mcDetectorCustomHeader      = NULL;      /* additional user output Tag in data files */
char*    mcopenedfiles               = "";        /* list of opened files (for append) */
long     mcopenedfiles_size          = 0;         /* size of that opened files list */
MCDETECTOR* mcDetectorArray          = NULL;      /* array of all opened detectors */
long     mcDetectorArray_size        = 0;         /* allocated detector array size */
long     mcDetectorArray_index       = 0;         /* current detector length (number of detectors so far) */

/* Number of particule histories to simulate. */
#ifdef NEUTRONICS
mcstatic unsigned long long int mcncount             = 1;
mcstatic unsigned long long int mcrun_num            = 0;
#else
mcstatic unsigned long long int mcncount             = 1e6;
mcstatic unsigned long long int mcrun_num            = 0;
#endif /* NEUTRONICS */

/* I/O structures */
mcstatic struct mcformats_struct mcformat;
mcstatic struct mcformats_struct mcformat_data;
#else
#include "mcstas-globals.h"
#endif /* !DANSE */

#ifndef MCSTAS_FORMAT
#define MCSTAS_FORMAT "McStas"  /* default format */
#endif

/* SECTION: parameters handling ============================================= */

/* Instrument input parameter type handling. */
/*******************************************************************************
* mcparm_double: extract double value from 's' into 'vptr'
*******************************************************************************/
static int
mcparm_double(char *s, void *vptr)
{
  char *p;
  double *v = (double *)vptr;

  if (!s) { *v = 0; return(1); }
  *v = strtod(s, &p);
  if(*s == '\0' || (p != NULL && *p != '\0') || errno == ERANGE)
    return 0;                        /* Failed */
  else
    return 1;                        /* Success */
}

/*******************************************************************************
* mcparminfo_double: display parameter type double
*******************************************************************************/
static char *
mcparminfo_double(char *parmname)
{
  return "double";
}

/*******************************************************************************
* mcparmerror_double: display error message when failed extract double
*******************************************************************************/
static void
mcparmerror_double(char *parm, char *val)
{
  fprintf(stderr, "Error: Invalid value '%s' for floating point parameter %s (mcparmerror_double)\n",
          val, parm);
}

/*******************************************************************************
* mcparmprinter_double: convert double to string
*******************************************************************************/
static void
mcparmprinter_double(char *f, void *vptr)
{
  double *v = (double *)vptr;
  sprintf(f, "%g", *v);
}

/*******************************************************************************
* mcparm_int: extract int value from 's' into 'vptr'
*******************************************************************************/
static int
mcparm_int(char *s, void *vptr)
{
  char *p;
  int *v = (int *)vptr;
  long x;

  if (!s) { *v = 0; return(1); }
  *v = 0;
  x = strtol(s, &p, 10);
  if(x < INT_MIN || x > INT_MAX)
    return 0;                        /* Under/overflow */
  *v = x;
  if(*s == '\0' || (p != NULL && *p != '\0') || errno == ERANGE)
    return 0;                        /* Failed */
  else
    return 1;                        /* Success */
}

/*******************************************************************************
* mcparminfo_int: display parameter type int
*******************************************************************************/
static char *
mcparminfo_int(char *parmname)
{
  return "int";
}

/*******************************************************************************
* mcparmerror_int: display error message when failed extract int
*******************************************************************************/
static void
mcparmerror_int(char *parm, char *val)
{
  fprintf(stderr, "Error: Invalid value '%s' for integer parameter %s (mcparmerror_int)\n",
          val, parm);
}

/*******************************************************************************
* mcparmprinter_int: convert int to string
*******************************************************************************/
static void
mcparmprinter_int(char *f, void *vptr)
{
  int *v = (int *)vptr;
  sprintf(f, "%d", *v);
}

/*******************************************************************************
* mcparm_string: extract char* value from 's' into 'vptr' (copy)
*******************************************************************************/
static int
mcparm_string(char *s, void *vptr)
{
  char **v = (char **)vptr;
  if (!s) { *v = NULL; return(1); }
  *v = (char *)malloc(strlen(s) + 1);
  if(*v == NULL)
  {
    exit(-fprintf(stderr, "Error: Out of memory %li (mcparm_string).\n", (long)strlen(s) + 1));
  }
  strcpy(*v, s);
  return 1;                        /* Success */
}

/*******************************************************************************
* mcparminfo_string: display parameter type string
*******************************************************************************/
static char *
mcparminfo_string(char *parmname)
{
  return "string";
}

/*******************************************************************************
* mcparmerror_string: display error message when failed extract string
*******************************************************************************/
static void
mcparmerror_string(char *parm, char *val)
{
  fprintf(stderr, "Error: Invalid value '%s' for string parameter %s (mcparmerror_string)\n",
          val, parm);
}

/*******************************************************************************
* mcparmprinter_string: convert string to string (including esc chars)
*******************************************************************************/
static void
mcparmprinter_string(char *f, void *vptr)
{
  char **v = (char **)vptr;
  char *p;

  if (!*v) { *f='\0'; return; }
  strcpy(f, "");
  for(p = *v; *p != '\0'; p++)
  {
    switch(*p)
    {
      case '\n':
        strcat(f, "\\n");
        break;
      case '\r':
        strcat(f, "\\r");
        break;
      case '"':
        strcat(f, "\\\"");
        break;
      case '\\':
        strcat(f, "\\\\");
        break;
      default:
        strncat(f, p, 1);
    }
  }
  /* strcat(f, "\""); */
} /* mcparmprinter_string */

/* now we may define the parameter structure, using previous functions */
static struct
  {
    int (*getparm)(char *, void *);
    char * (*parminfo)(char *);
    void (*error)(char *, char *);
    void (*printer)(char *, void *);
} mcinputtypes[] = {
  {
    mcparm_double, mcparminfo_double, mcparmerror_double,
    mcparmprinter_double
  }, {
    mcparm_int, mcparminfo_int, mcparmerror_int,
    mcparmprinter_int
  }, {
    mcparm_string, mcparminfo_string, mcparmerror_string,
    mcparmprinter_string
  }
};

/*******************************************************************************
* mcestimate_error: compute sigma from N,p,p2 in Gaussian large numbers approx
*******************************************************************************/
double mcestimate_error(double N, double p1, double p2)
{
  double pmean, n1;
  if(N <= 1)
    return p1;
  pmean = p1 / N;
  n1 = N - 1;
  /* Note: underflow may cause p2 to become zero; the fabs() below guards
     against this. */
  return sqrt((N/n1)*fabs(p2 - pmean*pmean));
}

double (*mcestimate_error_p)
  (double V2, double psum, double p2sum)=mcestimate_error;

/* SECTION: MPI handling ==================================================== */

#ifdef USE_MPI
/* MPI rank */
static int mpi_node_rank;
static int mpi_node_root = 0;


/*******************************************************************************
* mc_MPI_Reduce: Gathers arrays from MPI nodes using Reduce function.
*******************************************************************************/
int mc_MPI_Sum(double *sbuf, long count)
{
  if (!sbuf || count <= 0) return(MPI_SUCCESS); /* nothing to reduce */
  else {
    /* we must cut the buffer into blocks not exceeding the MPI max buffer size of 32000 */
    long   offset=0;
    double *rbuf=NULL;
    int    length=MPI_REDUCE_BLOCKSIZE; /* defined in mcstas.h */
    int    i=0;
    rbuf = calloc(count, sizeof(double));
    if (!rbuf)
      exit(-fprintf(stderr, "Error: Out of memory %li (mc_MPI_Sum)\n", count*sizeof(double)));
    while (offset < count) {
      if (!length || offset+length > count-1) length=count-offset;
      else length=MPI_REDUCE_BLOCKSIZE;
      if (MPI_Allreduce((double*)(sbuf+offset), (double*)(rbuf+offset),
              length, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD) != MPI_SUCCESS)
        return MPI_ERR_COUNT;
      offset += length;
    }

    for (i=0; i<count; i++) sbuf[i] = rbuf[i];
    free(rbuf);
  }
  return MPI_SUCCESS;
} /* mc_MPI_Sum */

/*******************************************************************************
* mc_MPI_Send: Send array to MPI node by blocks to avoid buffer limit
*******************************************************************************/
int mc_MPI_Send(void *sbuf,
                  long count, MPI_Datatype dtype,
                  int dest)
{
  int dsize;
  long offset=0;
  int  tag=1;
  int  length=MPI_REDUCE_BLOCKSIZE; /* defined in mcstas.h */

  if (!sbuf || count <= 0) return(MPI_SUCCESS); /* nothing to send */
  MPI_Type_size(dtype, &dsize);

  while (offset < count) {
    if (offset+length > count-1) length=count-offset;
    else length=MPI_REDUCE_BLOCKSIZE;
    if (MPI_Send((void*)(sbuf+offset*dsize), length, dtype, dest, tag++, MPI_COMM_WORLD) != MPI_SUCCESS)
      return MPI_ERR_COUNT;
    offset += length;
  }

  return MPI_SUCCESS;
} /* mc_MPI_Send */

/*******************************************************************************
* mc_MPI_Recv: Receives arrays from MPI nodes by blocks to avoid buffer limit
*             the buffer must have been allocated previously.
*******************************************************************************/
int mc_MPI_Recv(void *sbuf,
                  long count, MPI_Datatype dtype,
                  int source)
{
  int dsize;
  long offset=0;
  int  tag=1;
  int  length=MPI_REDUCE_BLOCKSIZE; /* defined in mcstas.h */

  if (!sbuf || count <= 0) return(MPI_SUCCESS); /* nothing to recv */
  MPI_Type_size(dtype, &dsize);

  while (offset < count) {
    if (offset+length > count-1) length=count-offset;
    else length=MPI_REDUCE_BLOCKSIZE;
    if (MPI_Recv((void*)(sbuf+offset*dsize), length, dtype, source, tag++,
            MPI_COMM_WORLD, MPI_STATUS_IGNORE) != MPI_SUCCESS)
      return MPI_ERR_COUNT;
    offset += length;
  }

  return MPI_SUCCESS;
} /* mc_MPI_Recv */

#endif /* USE_MPI */

/* SECTION: file i/o handling ================================================ */

/* Multiple output format support. ========================================== */
#ifdef USE_NEXUS
#define mcNUMFORMATS 10
#else
#define mcNUMFORMATS 9
#endif

/*******************************************************************************
* Definition of output formats. structure defined in mcstas-r.h
* Name aliases are defined in mcuse_format_* functions (below)
*******************************************************************************/

/* {Name, Extension, Header, Footer,
    BeginSection, EndSection, AssignTag;
    BeginData, EndData;
    BeginErrors, EndErrors;
    BeginNcount, EndNcount};
 */

mcstatic struct mcformats_struct mcformats[mcNUMFORMATS] = {
  { "McStas", "sim",
    "%PREFormat: %FMT file. Use mcplot/PGPLOT to view.\n"
      "%PREURL:    http://www.mccode.org/\n"
      "%PREEditor: %USR\n"
      "%PRECreator:%SRC simulation (" MCCODE_STRING ")\n"
      "%PREDate:   Simulation started (%DATL) %DAT\n"
      "%PREFile:   %FIL\n",
    "%PREEndDate:%DAT\n",
    "%PREbegin %TYP\n",
    "%PREend %TYP\n",
    "%PRE%NAM: %VAL\n",
    "%PREData [%PAR/%FIL] I: \n", "",
    "%PREErrors [%PAR/%FIL] E: \n", "",
    "%PREEvents [%PAR/%FIL] N: \n", "" },
  { "Scilab", "sci",
    "function mc_%VPA = get_%VPA(p)\n"
      "// %FMT function generated by McStas on %DAT\n"
      "// McStas simulation %SRC: %FIL %FMT\n"
      "// Import data using scilab> exec('%VPA.sci',-1); s=get_%VPA(); and s=get_%VPA('plot'); to plot\n\n"
      "mode(-1); //silent execution\n"
      "if argn(2) > 0, p=1; else p=0; end\n"
      "mc_%VPA = struct();\n"
      "mc_%VPA.Format ='%FMT';\n"
      "mc_%VPA.URL    ='http://www.mccode.org';\n"
      "mc_%VPA.Editor ='%USR';\n"
      "mc_%VPA.Creator='%SRC " MCCODE_STRING " simulation';\n"
      "mc_%VPA.Date   =%DATL; // for getdate\n"
      "mc_%VPA.File   ='%FIL';\n",
    "mc_%VPA.EndDate=%DATL; // for getdate\nendfunction\n"
    "function d=mcload_inline(d)\n"
      "// local inline func to load data\n"
      "execstr(['S=['+part(d.type,10:(length(d.type)-1))+'];']);\n"
      "if ~length(d.data)\n"
      " if ~length(strindex(d.format, 'binary'))\n"
      "  exec(d.filename,-1);p=d.parent;\n"
      "  if ~execstr('d2='+d.func+'();','errcatch'),d=d2; d.parent=p;end\n"
      " else\n"
      "  if length(strindex(d.format, 'float')), t='f';\n"
      "  elseif length(strindex(d.format, 'double')), t='d';\n"
      "  else return; end\n"
      "  fid=mopen(d.filename, 'rb');\n"
      "  pS = prod(S);\n"
      "  x = mget(3*pS, t, fid);\n"
      "  d.data  =matrix(x(1:pS), S);\n"
      "  if length(x) >= 3*pS,\n"
      "  d.errors=matrix(x((pS+1):(2*pS)), S);\n"
      "  d.events=matrix(x((2*pS+1):(3*pS)), S);end\n"
      "  mclose(fid);\n"
      "  return\n"
      " end\n"
      "end\n"
      "endfunction\n"
      "function d=mcplot_inline(d,p)\n"
      "// local inline func to plot data\n"
      "if ~length(strindex(d.type,'0d')), d=mcload_inline(d); end\n"
      "if ~p, return; end;\n"
      "execstr(['l=[',d.xylimits,'];']); S=size(d.data);\n"
      "t1=['['+d.parent+'] '+d.filename+': '+d.title];t = [t1;['  '+d.variables+'=['+d.values+']'];['  '+d.signal];['  '+d.statistics]];\n"
      "mprintf('%s\\n',t(:));\n"
      "if length(strindex(d.type,'0d')),return; end\n"
      "w=winsid();if length(w),w=w($)+1; else w=0; end\n"
      "xbasr(w); xset('window',w);\n"
      "if length(strindex(d.type,'2d'))\n"
      " if S(2) > 1, d.stepx=abs(l(1)-l(2))/(S(2)-1); else d.stepx=0; end\n"
      " if S(1) > 1, d.stepy=abs(l(3)-l(4))/(S(1)-1); else d.stepy=0; end\n"
      " d.x=linspace(l(1)+d.stepx/2,l(2)-d.stepx/2,S(2));\n"
      " d.y=linspace(l(3)+d.stepy/2,l(4)-d.stepy/2,S(1)); z=d.data;\n"
      " xlab=d.xlabel; ylab=d.ylabel; x=d.x; y=d.y;\n"
      " fz=max(abs(z));fx=max(abs(d.x));fy=max(abs(d.y));\n"
      " if fx>0,fx=round(log10(fx)); x=x/10^fx; xlab=xlab+' [*10^'+string(fx)+']'; end\n"
      " if fy>0,fy=round(log10(fy)); y=y/10^fy; ylab=ylab+' [*10^'+string(fy)+']'; end\n"
      " if fz>0,fz=round(log10(fz)); z=z/10^fz; t1=t1+' [*10^'+string(fz)+']'; end\n"
      " xset('colormap',hotcolormap(64));\n"
      " plot3d1(x,y,z',90,0,xlab+'@'+ylab+'@'+d.zlabel,[-1,2,4]); xtitle(t);\n"
      "else\n"
      " if max(S) > 1, d.stepx=abs(l(1)-l(2))/(max(S)-1); else d.stepx=0; end\n"
      " d.x=linspace(l(1)+d.stepx/2,l(2)-d.stepx/2,max(S));\n"
      " plot2d(d.x,d.data);xtitle(t,d.xlabel,d.ylabel);\n"
      "end\n"
      "xname(t1);\nendfunction\n"
    "mc_%VPA=get_%VPA();\n",
    "// Section %TYP [%NAM] (level %LVL)\n"
      "%PREt=[]; execstr('t=mc_%VNA.class','errcatch'); if ~length(t), mc_%VNA = struct(); end; mc_%VNA.class = '%TYP';",
    "%PREmc_%VPA.mc_%VNA = 0; mc_%VPA.mc_%VNA = mc_%VNA;\n",
    "%PREmc_%SEC.%NAM = '%VAL';\n",
    "%PREmc_%VPA.func='get_%VPA';\n%PREmc_%VPA.data = [ \n",
    " ]; // end of data\n%PREif length(mc_%VPA.data) == 0, single_file=0; else single_file=1; end\n%PREmc_%VPA=mcplot_inline(mc_%VPA,p);\n",
    "%PREerrors = [ \n",
    " ]; // end of errors\n%PREif single_file == 1, mc_%VPA.errors=errors; end\n",
    "%PREevents = [ \n",
    " ]; // end of events\n%PREif single_file == 1, mc_%VPA.events=events; end\n"},
  { "Matlab", "m",
    "function mc_%VPA = get_%VPA(p)\n"
      "%% %FMT function generated by McStas on %DAT\n"
      "%% McStas simulation %SRC: %FIL\n"
      "%% Import data using matlab> s=%VPA; and s=%VPA('plot'); to plot\n\n"
      "if nargout == 0 | nargin > 0, p=1; else p=0; end\n"
      "mc_%VPA.Format ='%FMT';\n"
      "mc_%VPA.URL    ='http://www.mccode.org';\n"
      "mc_%VPA.Editor ='%USR';\n"
      "mc_%VPA.Creator='%SRC " MCCODE_STRING " simulation';\n"
      "mc_%VPA.Date   =%DATL; %% for datestr\n"
      "mc_%VPA.File   ='%FIL';\n",
    "mc_%VPA.EndDate=%DATL; %% for datestr\n"
      "function d=mcload_inline(d)\n"
      "%% local inline function to load data\n"
      "S=d.type; eval(['S=[ ' S(10:(length(S)-1)) ' ];']);\n"
      "if isempty(d.data)\n"
      " if ~length(findstr(d.format, 'binary'))\n"
      "  if ~strcmp(d.filename,[d.func,'.m']) copyfile(d.filename,[d.func,'.m']); end\n"
      "  p=d.parent;path(path);\n"
      "  eval(['d=',d.func,';']);d.parent=p;\n"
      "  if ~strcmp(d.filename,[d.func,'.m']) delete([d.func,'.m']); end\n"
      " else\n"
      "  if length(findstr(d.format, 'float')), t='single';\n"
      "  elseif length(findstr(d.format, 'double')), t='double';\n"
      "  else return; end\n"
      "  if length(S) == 1, S=[S 1]; end\n"
      "  fid=fopen(d.filename, 'r');\n"
      "  pS = prod(S);\n"
      "  x = fread(fid, 3*pS, t);\n"
      "  d.data  =reshape(x(1:pS), S);\n"
      "  if prod(size(x)) >= 3*pS,\n"
      "  d.errors=reshape(x((pS+1):(2*pS)), S);\n"
      "  d.events=reshape(x((2*pS+1):(3*pS)), S);end\n"
      "  fclose(fid);\n"
      "  return\n"
      " end\n"
      "end\n"
      "return;\n"
      "function d=mcplot_inline(d,p)\n"
      "%% local inline function to plot data\n"
      "if isempty(findstr(d.type,'0d')), d=mcload_inline(d); end\nif ~p, return; end;\n"
      "eval(['l=[',d.xylimits,'];']); S=size(d.data);\n"
      "t1=['[',d.parent,'] ',d.filename,': ',d.title];t = strvcat(t1,['  ',d.variables,'=[',d.values,']'],['  ',d.signal],['  ',d.statistics]);\n"
      "disp(t);\n"
      "if ~isempty(findstr(d.type,'0d')), return; end\n"
      "figure; if ~isempty(findstr(d.type,'2d'))\n"
      " if S(2) > 1, d.stepx=abs(l(1)-l(2))/(S(2)-1); else d.stepx=0; end\n"
      " if S(1) > 1, d.stepy=abs(l(3)-l(4))/(S(1)-1); else d.stepy=0; end\n"
      " d.x=linspace(l(1)+d.stepx/2,l(2)-d.stepx/2,S(2));\n"
      " d.y=linspace(l(3)+d.stepy/2,l(4)-d.stepy/2,S(1));\n"
      " surface(d.x,d.y,d.data); xlim([l(1) l(2)]); ylim([l(3) l(4)]); shading flat;\n"
      "else\n"
      " if max(S) > 1, d.stepx=abs(l(1)-l(2))/(max(S)-1); else d.stepx=0; end\n"
      " d.x=linspace(l(1)+d.stepx/2,l(2)-d.stepx/2,max(S));\n"
      " plot(d.x,d.data); xlim([l(1) l(2)]);\n"
      "end\n"
      "xlabel(d.xlabel); ylabel(d.ylabel); title(t); \n"
      "set(gca,'position',[.18,.18,.7,.65]); set(gcf,'name',t1);grid on;\n"
      "if ~isempty(findstr(d.type,'2d')), colorbar; end\n",
    "%% Section %TYP [%NAM] (level %LVL)\n"
      "%PREmc_%VNA.class = '%TYP';",
    "mc_%VPA.mc_%VNA = mc_%VNA;\n",
    "%PREmc_%SEC.%NAM = '%VAL';\n",
    "%PREmc_%VPA.func='%VPA';\n%PREmc_%VPA.data = [ \n",
    " ]; %% end of data\nif length(mc_%VPA.data) == 0, single_file=0; else single_file=1; end\nmc_%VPA=mcplot_inline(mc_%VPA,p);\n",
    "%PREerrors = [ \n",
    " ]; %% end of errors\nif single_file, mc_%VPA.errors=errors; end\n",
    "%PREevents = [ \n",
    " ]; %% end of events\nif single_file, mc_%VPA.events=events; end\n"},
  { "IDL", "pro",
    "; %FMT function generated by McStas on %DAT\n"
      "; McStas simulation %SRC: %FIL\n"
      "; import using idl> s=%VPA() and s=%VPA(/plot) to plot\n\n"
      "function mcload_inline,d\n"
      "; local inline function to load external data\n"
      "S=d.type & a=execute('S=long(['+strmid(S,9,strlen(S)-10)+'])')\n"
      "if strpos(d.format, 'binary') lt 0 then begin\n"
      " p=d.parent\n"
      " x=read_binary(d.filename)\n"
      " get_lun, lun\n"
      " openw,lun,d.func+'.pro'\n"
      " writeu, lun,x\n"
      " free_lun,lun\n"
      " resolve_routine, d.func, /is_func, /no\n"
      " d=call_function(d.func)\n"
      "endif else begin\n"
      " if strpos(d.format, 'float') ge 0 then t=4 $\n"
      " else if strpos(d.format, 'double') ge 0 then t=5 $\n"
      " else return,d\n"
      " x=read_binary(d.filename, data_type=t)\n"
      " pS=n_elements(S)\nif pS eq 1 then pS=long(S) $\n"
      " else if pS eq 2 then pS=long(S(0)*S(1)) $\n"
      " else pS=long(S(0)*S(1)*S(2))\n"
      " pS=pS(0)\nstv,d,'data',reform(x(0:(pS-1)),S)\n"
      " d.data=transpose(d.data)\n"
      " if n_elements(x) ge long(3*pS) then begin\n"
      "  stv,d,'errors',reform(x(pS:(2*pS-1)),S)\n"
      "  stv,d,'events',reform(x((2*pS):(3*pS-1)),S)\n"
      "  d.errors=transpose(d.errors)\n"
      "  d.events=transpose(d.events)\n"
      " endif\n"
      "endelse\n"
      "return,d\nend ; FUN load\n"
    "function mcplot_inline,d,p\n"
      "; local inline function to plot data\n"
      "if size(d.data,/typ) eq 7 and strpos(d.type,'0d') lt 0 then d=mcload_inline(d)\n"
      "if p eq 0 or strpos(d.type,'0d') ge 0 then return, d\n"
      "S=d.type & a=execute('S=long(['+strmid(S,9,strlen(S)-10)+'])')\n"
      "stv,d,'data',reform(d.data,S,/over)\n"
      "if total(strpos(tag_names(d),'ERRORS')+1) gt 0 then begin\n"
      " stv,d,'errors',reform(d.errors,S,/over)\n"
      " stv,d,'events',reform(d.events,S,/over)\n"
      "endif\n"
      "d.xylimits=strjoin(strsplit(d.xylimits,' ',/extract),',') & a=execute('l=['+d.xylimits+']')\n"
      "t1='['+d.parent+'] '+d.filename+': '+d.title\n"
      "t=[t1,'  '+d.variables+'=['+d.values+']','  '+d.signal,'  '+d.statistics]\n"
      "print,t\n"
      "if strpos(d.type,'0d') ge 0 then return,d\n"
      "d.xlabel=strjoin(strsplit(d.xlabel,'`!\"^&*()-+=|\\,.<>/?@''~#{[}]',/extract),'_')\n"
      "d.ylabel=strjoin(strsplit(d.ylabel,'`!\"^&*()-+=|\\,.<>/?@''~#{[}]',/extract),'_')\n"
      "stv,d,'x',l(0)+indgen(S(0))*(l(1)-l(0))/S(0)\n"
      "if strpos(d.type,'2d') ge 0 then begin\n"
      "  name={DATA:d.func,IX:d.xlabel,IY:d.ylabel}\n"
      "  stv,d,'y',l(2)+indgen(S(1))*(l(3)-l(2))/S(1)\n"
      "  live_surface,d.data,xindependent=d.x,yindependent=d.y,name=name,reference_out=Win\n"
      "endif else begin\n"
      "  name={DATA:d.func,I:d.xlabel}\n"
      "  live_plot,d.data,independent=d.x,name=name,reference_out=Win\n"
      "endelse\n"
      "live_text,t,Window_In=Win.Win,location=[0.3,0.9]\n"
      "return,d\nend ; FUN plot\n"
    "pro stv,S,T,V\n"
      "; procedure set-tag-value that does S.T=V\n"
      "sv=size(V)\n"
      "T=strupcase(T)\n"
      "TL=strupcase(tag_names(S))\n"
      "id=where(TL eq T)\n"
      "sz=[0,0,0]\n"
      "vd=n_elements(sv)-2\n"
      "type=sv[vd]\n"
      "if id(0) ge 0 then d=execute('sz=SIZE(S.'+T+')')\n"
      "if (sz(sz(0)+1) ne sv(sv(0)+1)) or (sz(0) ne sv(0)) $\n"
      "  or (sz(sz(0)+2) ne sv(sv(0)+2)) $\n"
      "  or type eq 8 then begin\n"
      " ES = ''\n"
      " for k=0,n_elements(TL)-1 do begin\n"
      "  case TL(k) of\n"
      "   T:\n"
      "   else: ES=ES+','+TL(k)+':S.'+TL(k)\n"
      "  endcase\n"
      " endfor\n"
      " d=execute('S={'+T+':V'+ES+'}')\n"
      "endif else d=execute('S.'+T+'=V')\n"
      "end ; PRO stv\n"
    "function %VPA,plot=plot\n"
      "; %FMT function generated by McStas on %DAT\n"
      "; McStas simulation %SRC: %FIL\n"
      "; import using s=%VPA() and s=%VPA(/plot) to plot\n"
      "if keyword_set(plot) then p=1 else p=0\n"
      "%7$s={Format:'%FMT',URL:'http://www.mccode.org',"
      "Editor:'%USR',$\n"
      "Creator:'%SRC " MCCODE_STRING " simulation',$\n"
      "Date:%DATL,"
      "File:'%FIL'}\n",
    "stv,%VPA,'EndDate',%DATL ; for systime\nreturn, %VPA\nend\n",
    "; Section %TYP [%NAM] (level %LVL)\n"
      "%PRE%VNA={class:'%TYP'}\n",
    "%PREstv,%VPA,'%VNA',%VNA\n",
    "%PREstv,%SEC,'%NAM','%VAL'\n",
    "%PREstv,%VPA,'func','%VPA' & data=[ $\n",
    " ]\n%PREif size(data,/type) eq 7 then single_file=0 else single_file=1\n"
    "%PREstv,%VPA,'data',data & data=0 & %VPA=mcplot_inline(%VPA,p)\n",
    "%PREif single_file ne 0 then begin errors=[ ",
    " ]\n%PREstv,%VPA,'errors',reform(errors,%MDIM,%NDIM,/over) & errors=0\n%PREendif\n",
    "%PREif single_file ne 0 then begin events=[ ",
    " ]\n%PREstv,%VPA,'events',reform(events,%MDIM,%NDIM,/over) & events=0\n%PREendif\n\n"},
  { "XML", "xml",
    "<?xml version=\"1.0\" ?>\n<!--\n"
      "URL:    http://www.nexusformat.org/\n"
      "Editor: %USR\n"
      "Creator:%SRC " MCCODE_STRING " [www.mccode.org].\n"
      "Date:   Simulation started (%DATL) %DAT\n"
      "File:   %FIL\n"
      "View with Mozilla, InternetExplorer, gxmlviewer, kxmleditor\n-->\n"
      "<NX%PAR file_name=\"%FIL\" file_time=\"%DAT\" user=\"%USR\">\n"
        "<NXentry name=\"" MCCODE_STRING "\"><start_time>%DAT</start_time>\n",
    "<end_time>%DAT</end_time></NXentry></NX%PAR>\n<!-- EndDate:%DAT -->\n",
    "%PRE<NX%TYP name=\"%NAM\">\n",
    "%PRE</NX%TYP>\n",
    "%PRE<%NAM>%VAL</%NAM>\n",
    "%PRE<%XVL long_name=\"%XLA\" axis=\"1\" primary=\"1\" min=\"%XMIN\""
        " max=\"%XMAX\" dims=\"%MDIM\" range=\"1\"></%XVL>\n"
      "%PRE<%YVL long_name=\"%YLA\" axis=\"2\" primary=\"1\" min=\"%YMIN\""
        " max=\"%YMAX\" dims=\"%NDIM\" range=\"1\"></%YVL>\n"
      "%PRE<%ZVL long_name=\"%ZLA\" axis=\"3\" primary=\"1\" min=\"%ZMIN\""
        " max=\"%ZMAX\" dims=\"%PDIM\" range=\"1\"></%ZVL>\n"
      "%PRE<data long_name=\"%TITL\" signal=\"1\"  axis=\"[%XVL,%YVL,%ZVL]\" file_name=\"%FIL\">\n",
    "%PRE</data>\n",
    "%PRE<errors>\n", "%PRE</errors>\n",
    "%PRE<monitor>\n", "%PRE</monitor>\n"},
  { "HTML", "html",
    "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD %DAT//EN\"\n"
      "\"http://www.w3.org/TR/html4/strict.dtd\">\n"
      "<HTML><HEAD><META name=\"Author\" content=\"%PAR\">\n"
      "<META name=\"Creator\" content=\"%PAR (%SRC) " MCCODE_STRING " [www.mccode.org] simulation\">\n"
      "<META name=\"Date\" content=\"%DAT\">\n"
      "<TITLE>[McStas %PAR (%SRC)]%FIL</TITLE></HEAD>\n"
      "<BODY><center><h1><a name=\"%PAR\">"
        "McStas simulation %SRC (%SRC): Result file %FIL.html</a></h1></center><br>\n"
        "This simulation report was automatically created by"
        " <a href=\"http://www.mccode.org/\"><i>" MCCODE_STRING "</i></a><br>\n"
        "<pre>User:   %USR<br>\n"
        "%PRECreator: <a href=\"%SRC\">%SRC</a> %PAR McStas simulation<br>\n"
        "%PREFormat:  %FMT<br>\n"
        "%PREDate:    (%DATL) %DAT<br></pre>\n"
        "VRML viewers may be obtained at <a href=\"http://cic.nist.gov/vrml/vbdetect.html\">http://cic.nist.gov/vrml/vbdetect.html</a>\n",
    "<b>EndDate: </b>(%DATL) %DAT<br></BODY></HTML>\n",
    "%PRE<h%LVL><a name=\"%NAM\">%TYP %NAM</a></h%LVL> "
      "[child of <a href=\"#%PAR\">%PAR</a>]<br>\n",
    "[end of <a href=\"#%NAM\">%TYP %NAM</a>]<br>\n",
    "%PRE<b>%NAM: </b>%VAL<br>\n",
    "%PRE<b>DATA</b><br><center><embed src=\"%FIL\" type=\"model/vrml\" width=\"75%%\" height=\"50%%\"></embed><br>File <a href=\"%FIL\">%FIL [VRML format]</a></center><br>\n", "%PREEnd of DATA<br>\n",
    "%PRE<b>ERRORS</b><br>\n","%PREEnd of ERRORS<br>\n",
    "%PRE<b>EVENTS</b><br>\n", "%PREEnd of EVENTS<br>\n"},
  { "Octave", "m",
    "function mc_%VPA = get_%VPA(p)\n"
      "%% %FMT function generated by McStas on %DAT\n"
      "%% McStas simulation %SRC: %FIL\n"
      "%% Import data using octave> s=%VPA(); and plot with s=%VPA('plot');\n"
      "if nargin > 0, p=1; else p=0; end\n"
      "mc_%VPA.Format ='%FMT';\n"
      "mc_%VPA.URL    ='http://www.mccode.org';\n"
      "mc_%VPA.Editor ='%USR';\n"
      "mc_%VPA.Creator='%SRC " MCCODE_STRING " simulation';\n"
      "mc_%VPA.Date   =%DATL; %% for datestr\n"
      "mc_%VPA.File   ='%FIL';\n",
    "mc_%VPA.EndDate=%DATL; %% for datestr\nendfunction\n"
      "if exist('mcload_inline'), return; end\n"
      "function d=mcload_inline(d)\n"
      "%% local inline function to load data\n"
      "S=d.type; eval(['S=[ ' S(10:(length(S)-1)) ' ];']);\n"
      "if isempty(d.data)\n"
      " if ~length(findstr(d.format, 'binary'))\n"
      "  source(d.filename);p=d.parent;\n"
      "  eval(['d=get_',d.func,';']);d.parent=p;\n"
      " else\n"
      "  if length(findstr(d.format, 'float')), t='float';\n"
      "  elseif length(findstr(d.format, 'double')), t='double';\n"
      "  else return; end\n"
      "  if length(S) == 1, S=[S 1]; end\n"
      "  fid=fopen(d.filename, 'r');\n"
      "  pS = prod(S);\n"
      "  x = fread(fid, 3*pS, t);\n"
      "  d.data  =reshape(x(1:pS), S);\n"
      "  if prod(size(x)) >= 3*pS,\n"
      "  d.errors=reshape(x((pS+1):(2*pS)), S);\n"
      "  d.events=reshape(x((2*pS+1):(3*pS)), S);end\n"
      "  fclose(fid);\n"
      "  return\n"
      " end\n"
      "end\n"
      "return;\nendfunction\n\n"
      "function d=mcplot_inline(d,p)\n"
      "%% local inline function to plot data\n"
      "if isempty(findstr(d.type,'0d')), d=mcload_inline(d); end\nif ~p, return; end;\n"
      "eval(['l=[',d.xylimits,'];']); S=size(d.data);\n"
      "t1=['[',d.parent,'] ',d.filename,': ',d.title];t = strcat(t1,['  ',d.variables,'=[',d.values,']'],['  ',d.signal],['  ',d.statistics]);\n"
      "disp(t);\n"
      "if ~isempty(findstr(d.type,'0d')), return; end\n"
      "xlabel(d.xlabel); ylabel(d.ylabel); title(t);"
      "figure; if ~isempty(findstr(d.type,'2d'))\n"
      " if S(2) > 1, d.stepx=abs(l(1)-l(2))/(S(2)-1); else d.stepx=0; end\n"
      " if S(1) > 1, d.stepy=abs(l(3)-l(4))/(S(1)-1); else d.stepy=0; end\n"
      " d.x=linspace(l(1)+d.stepx/2,l(2)-d.stepx/2,S(2));\n"
      " d.y=linspace(l(3)+d.stepy/2,l(4)-d.stepy/2,S(1));\n"
      " mesh(d.x,d.y,d.data);\n"
      "else\n"
      " if max(S) > 1, d.stepx=abs(l(1)-l(2))/(max(S)-1); else d.stepx=0; end\n"
      " d.x=linspace(l(1)+d.stepx/2,l(2)-d.stepx/2,max(S));\n"
      " plot(d.x,d.data);\n"
      "end\nendfunction\n",
    "%% Section %TYP [%NAM] (level %LVL)\n"
      "mc_%VNA.class = '%TYP';",
    "mc_%VPA.mc_%VNA = mc_%VNA;\n",
    "mc_%SEC.%NAM = '%VAL';\n",
    "mc_%VPA.func='%VPA';\n%PREmc_%VPA.data = [ \n",
    " ]; %% end of data\nif length(mc_%VPA.data) == 0, single_file=0; else single_file=1; end\nmc_%VPA=mcplot_inline(mc_%VPA,p);\n",
    "errors = [ \n",
    " ]; %% end of errors\nif single_file, mc_%VPA.errors=errors; end\n",
    "events = [ \n",
    " ]; %% end of events\nif single_file, mc_%VPA.events=events; end\n"},
  { "VRML", "wrl",
    "#VRML V2.0 utf8\n# Format: %FMT file\n"
      "use freeWRL, openvrml, vrmlview, CosmoPlayer, Cortona, Octaga... to view file\n"
      "WorldInfo {\n"
      "title \"%SRC/%FIL simulation Data\"\n"
      "info [ \"URL:    http://www.mccode.org/\"\n"
      "       \"Editor: %USR\"\n"
      "       \"Creator:%SRC simulation (" MCCODE_STRING ")\"\n"
      "       \"Date:   Simulation started (%DATL) %DAT\"\n"
      "       \"File:   %FIL\" ]\n}\n"
      "Background { skyAngle [ 1.57 1.57] skyColor [0 0 1, 1 1 1, 0.1 0 0] }\n",
    "# EndDate:%DAT\n",
    "# begin %TYP %PAR\n",
    "# end %TYP %PAR\n",
    "%PRE%SEC.%NAM= '%VAL'\n",
    "# The Proto that contains data values and objects to plot these\n"
      "PROTO I_ERR_N_%VPA [\n"
      "# the PROTO parameters\n"
      "  field MFFloat Data [ ]\n"
      "  field MFFloat Errors [ ]\n"
      "  field MFFloat Ncounts [ ]\n"
      "] { # The plotting objects/methods in the Proto\n"
      "  # draw a small sphere at the origin\n"
      "  DEF Data_%VPA Group {\n"
      "  children [\n"
      "    DEF CoordinateOrigin Group {\n"
      "      children [\n"
      "        Transform { translation  0 0 0 }\n"
      "        Shape { \n"
      "          appearance Appearance { \n"
      "            material Material {\n"
      "              diffuseColor 1.0 1.0 0.0\n"
      "              transparency 0.5 } }\n"
      "          geometry Sphere { radius .01 } \n"
      "    } ] }\n"
      "    # defintion of the arrow allong Y axis\n"
      "    DEF ARROW Group {\n"
      "      children [\n"
      "        Transform {\n"
      "          translation 0 0.5 0\n"
      "          children [\n"
      "            Shape {\n"
      "              appearance DEF ARROW_APPEARANCE Appearance {\n"
      "                material Material {\n"
      "                  diffuseColor .3 .3 1\n"
      "                  emissiveColor .1 .1 .33\n"
      "                }\n"
      "              }\n"
      "              geometry Cylinder {\n"
      "                bottom FALSE\n"
      "                radius .005\n"
      "                height 1\n"
      "                top FALSE\n"
      "        } } ] }\n"
      "        Transform {\n"
      "          translation 0 1 0\n"
      "          children [\n"
      "            DEF ARROW_POINTER Shape {\n"
      "              geometry Cone {\n"
      "                bottomRadius .05\n"
      "                height .1\n"
      "              }\n"
      "              appearance USE ARROW_APPEARANCE\n"
      "    } ] } ] }\n"
      "    # the arrow along X axis\n"
      "    Transform {\n"
      "      translation 0 0 0\n"
      "      rotation 1 0 0 1.57\n"
      "      children [\n"
      "        Group {\n"
      "          children [ \n"
      "            USE ARROW\n"
      "    ] } ] }\n"
      "    # the arrow along Z axis\n"
      "    Transform {\n"
      "      translation 0 0 0\n"
      "      rotation 0 0 1 -1.57\n"
      "      children [\n"
      "        Group {\n"
      "          children [ \n"
      "            USE ARROW\n"
      "    ] } ] }\n"
      "    # the Y label (which is vertical)\n"
      "    DEF Y_Label Group {\n"
      "      children [\n"
      "        Transform {\n"
      "          translation 0 1 0\n"
      "          children [\n"
      "            Billboard {\n"
      "              children [\n"
      "                Shape {\n"
      "                  appearance DEF LABEL_APPEARANCE Appearance {\n"
      "                    material Material {\n"
      "                      diffuseColor 1 1 .3\n"
      "                      emissiveColor .33 .33 .1\n"
      "                    } }\n"
      "                  geometry Text { \n"
      "                    string [ \"%ZVAR: %ZLA\", \"%ZMIN:%ZMAX - %PDIM points\" ] \n"
      "                    fontStyle FontStyle {  size .2 }\n"
      "    } } ] } ] } ] }\n"
      "    # the X label\n"
      "    DEF X_Label Group {\n"
      "      children [\n"
      "        Transform {\n"
      "          translation 1 0 0\n"
      "          children [\n"
      "            Billboard {\n"
      "              children [\n"
      "                Shape {\n"
      "                  appearance DEF LABEL_APPEARANCE Appearance {\n"
      "                    material Material {\n"
      "                      diffuseColor 1 1 .3\n"
      "                      emissiveColor .33 .33 .1\n"
      "                    } }\n"
      "                  geometry Text { \n"
      "                    string [ \"%XVAR: %XLA\", \"%XMIN:%XMAX - %MDIM points\" ] \n"
      "                    fontStyle FontStyle {  size .2 }\n"
      "    } } ] } ] } ] }\n"
      "    # the Z label\n"
      "    DEF Z_Label Group {\n"
      "      children [\n"
      "        Transform {\n"
      "          translation 0 0 1\n"
      "          children [\n"
      "            Billboard {\n"
      "              children [\n"
      "                Shape {\n"
      "                  appearance DEF LABEL_APPEARANCE Appearance {\n"
      "                    material Material {\n"
      "                      diffuseColor 1 1 .3\n"
      "                      emissiveColor .33 .33 .1\n"
      "                    } }\n"
      "                  geometry Text { \n"
      "                    string [ \"%YVAR: %YLA\", \"%YMIN:%YMAX - %NDIM points\" ] \n"
      "                    fontStyle FontStyle {  size .2 }\n"
      "    } } ] } ] } ] }\n"
      "    # The text information (header data )\n"
      "    DEF Header Group {\n"
      "      children [\n"
      "        Transform {\n"
      "          translation 0 2 0\n"
      "          children [\n"
      "            Billboard {\n"
      "              children [\n"
      "                Shape {\n"
      "                  appearance Appearance {\n"
      "                    material Material { \n"
      "                      diffuseColor .9 0 0\n"
      "                      emissiveColor .9 0 0 }\n"
      "                  }\n"
      "                  geometry Text {\n"
      "                    string [ \"%PAR/%FIL\",\"%TITL\" ]\n"
      "                    fontStyle FontStyle {\n"
      "                        style \"BOLD\"\n"
      "                        size .2\n"
      "    } } } ] } ] } ] }\n"
      "    # The Data plot\n"
      "    DEF MonitorData Group {\n"
      "      children [\n"
      "        DEF TransformData Transform {\n"
      "          children [\n"
      "            Shape {\n"
      "              appearance Appearance {\n"
      "                material Material { emissiveColor 0 0.2 0 }\n"
      "              }\n"
      "              geometry ElevationGrid {\n"
      "                xDimension  %MDIM\n"
      "                zDimension  %NDIM\n"
      "                xSpacing    1\n"
      "                zSpacing    1\n"
      "                solid       FALSE\n"
      "                height IS Data\n"
      "    } } ] } ] }\n"
      "    # The VRMLScript that redimension x and z axis within 0:1\n"
      "    # and re-scale data within 0:1\n"
      "    DEF GetScale Script {\n"
      "      eventOut SFVec3f scale_vect\n"
      "      url \"javascript: \n"
      "        function initialize( ) {\n"
      "          scale_vect = new SFVec3f(1.0/%MDIM, 1.0/Math.abs(%ZMAX-%ZMIN), 1.0/%NDIM); }\" }\n"
      "  ] }\n"
      "ROUTE GetScale.scale_vect TO TransformData.scale\n} # end of PROTO\n"
      "# now we call the proto with Data values\n"
      "I_ERR_N_%VPA {\nData [\n",
    "] # End of Data\n",
    "Errors [\n",
    "] # End of Errors\n",
    "Ncounts [\n",
    "] # End of Ncounts\n}" },
    { "Python", "py",
    "from numpy import array\ndef %VPA(p):\n"
      "  '''\n  %PAR (%FIL) procedure generated from McStas on %DAT\n\n"
      "  McStas simulation %SRC: %FIL\n"
      "  import data using python> s=%VPA(p); with p=0/1 for no plot/plot\n  '''\n"
      "  %VPA={'Format':'%FMT','URL':'http://www.mccode.org',\\\n"
      "  'Editor':'%USR',\\\n"
      "  'Creator':'%SRC " MCCODE_STRING " [www.mccode.org]',\\\n"
      "  'Date':%DATL,\\\n"
      "  'File':'%FIL'}\n",
    "  %VPA['EndDate']=%DATL\nreturn %VPA\n",
    "  # Section Section %TYP [%NAM] (level %LVL)\n"
      "  %VNA['class'] = '%TYP'\n",
    "  %VPA['%VNA'] = %VNA\n  del %VNA\n",
    "  %SEC['%NAM'] = '%VAL'\n",
    "  %VPA['func'] ='%VPA'\n  %VPA['data'] = [ ",
    "  ] # end of data\n",
    "  %VPA['errors'] = [ ",
    "  ] # end of errors\n",
    "  %VPA['ncount'] = [ ",
    "  ] # end of ncount\n",
    }
#ifdef USE_NEXUS
    ,
    { "NeXus", "nxs",
    "%PREFormat: %FMT file. Use hdfview to view.\n"
      "%PREURL:    http://www.mccode.org/\n"
      "%PREEditor: %USR\n"
      "%PRECreator:%SRC simulation (" MCCODE_STRING ")\n"
      "%PREDate:   Simulation started (%DATL) %DAT\n"
      "%PREFile:   %FIL\n",
    "%PREEndDate:%DAT\n",
    "%PREbegin %TYP\n",
    "%PREend %TYP\n",
    "%PRE%NAM: %VAL\n",
    "", "",
    "%PREErrors [%PAR/%FIL]: \n", "",
    "%PREEvents [%PAR/%FIL]: \n", "" }
#endif
};

/*******************************************************************************
* mcfull_file: allocates a full file name=mcdirname+file. Catenate extension if missing.
*******************************************************************************/
char *mcfull_file(char *name, char *ext)
{
  int   dirlen=0;
  char *mem   =NULL;

  dirlen = mcdirname ? strlen(mcdirname) : 0;
  mem = malloc(dirlen + strlen(name) + CHAR_BUF_LENGTH);
  if(!mem) {
    exit(-fprintf(stderr, "Error: Out of memory %li (mcfull_file)\n", (long)(dirlen + strlen(name) + 256)));
  }
  strcpy(mem, "");

  /* prepend directory name to path if name does not contain a path */
  if (dirlen > 0 && !strchr(name, MC_PATHSEP_C)) {
    strcat(mem, mcdirname);
    strcat(mem, MC_PATHSEP_S);
  } /* dirlen */

  strcat(mem, name);
  if (!strchr(name, '.') && ext && strlen(ext))
  { /* add extension if not in file name already */
    strcat(mem, ".");
    strcat(mem, ext);
  }
  return(mem);
} /* mcfull_file */

/*******************************************************************************
* mcnew_file: opens a new file within mcdirname if non NULL
*             if mode is non 0, then mode is used, else mode is 'w'
*******************************************************************************/
FILE *mcnew_file(char *name, char *ext, char *mode)
{
  char *mem;
  FILE *file;

  if (!name || strlen(name) == 0 || mcdisable_output_files) return(NULL);

  mem = mcfull_file(name, ext);
  file = fopen(mem, (mode ? mode : "w"));
  if(!file)
    fprintf(stderr, "Warning: could not open output file '%s' in mode '%s' (mcnew_file)\n", mem, mode);
  else {
    if (!mcopenedfiles ||
        (mcopenedfiles && mcopenedfiles_size <= strlen(mcopenedfiles)+strlen(mem))) {
      mcopenedfiles_size+=CHAR_BUF_LENGTH;
      if (!mcopenedfiles || !strlen(mcopenedfiles))
        mcopenedfiles = calloc(1, mcopenedfiles_size);
      else
        mcopenedfiles = realloc(mcopenedfiles, mcopenedfiles_size);
    }
    strcat(mcopenedfiles, " ");
    strcat(mcopenedfiles, mem);
  }
  free(mem);

  return file;
} /* mcnew_file */

/*******************************************************************************
* str_rep: Replaces a token by an other (of SAME length) in a string
* This function modifies 'string'
*******************************************************************************/
char *str_rep(char *string, char *from, char *to)
{
  char *p;

  if (!string || !strlen(string)) return(string);
  if (strlen(from) != strlen(to)) return(string);

  p   = string;

  while (( p = strstr(p, from) ) != NULL) {
    long index;
    for (index=0; index<strlen(to); index++) p[index]=to[index];
  }
  return(string);
} /* str_rep */

#define VALID_NAME_LENGTH 64
/*******************************************************************************
* mcvalid_name: makes a valid string for variable names.
*   copy 'original' into 'valid', replacing invalid characters by '_'
*   char arrays must be pre-allocated. n can be 0, or the maximum number of
*   chars to be copied/checked
*******************************************************************************/
static char *mcvalid_name(char *valid, char *original, int n)
{
  long i;


  if (original == NULL || strlen(original) == 0)
  { strcpy(valid, "noname"); return(valid); }
  if (n <= 0) n = strlen(valid);

  if (n > strlen(original)) n = strlen(original);
  else original += strlen(original)-n;
  strncpy(valid, original, n);

  for (i=0; i < n; i++)
  {
    if ( (valid[i] > 122)
      || (valid[i] < 32)
      || (strchr("!\"#$%&'()*+,-.:;<=>?@[\\]^`/ \n\r\t", valid[i]) != NULL) )
    {
      if (i) valid[i] = '_'; else valid[i] = 'm';
    }
  }
  valid[i] = '\0';

  return(valid);
} /* mcvalid_name */

/*******************************************************************************
* pfprintf: just as fprintf with positional arguments %N$t,
*   but with (char *)fmt_args being the list of arg type 't'.
*   Needed as the vfprintf is not correctly handled on some platforms.
*   1- look for the maximum %d$ field in fmt
*   2- look for all %d$ fields up to max in fmt and set their type (next alpha)
*   3- retrieve va_arg up to max, and save pointer to arg in local arg array
*   4- use strchr to split around '%' chars, until all pieces are written
*   returns number of arguments written.
* Warning: this function is restricted to only handles types t=s,g,i,li
*          without additional field formating, e.g. %N$t
*******************************************************************************/
static int pfprintf(FILE *f, char *fmt, char *fmt_args, ...)
{
  #define MyNL_ARGMAX 50
  char  *fmt_pos;

  char *arg_char[MyNL_ARGMAX];
  int   arg_int[MyNL_ARGMAX];
  long  arg_long[MyNL_ARGMAX];
  double arg_double[MyNL_ARGMAX];

  char *arg_posB[MyNL_ARGMAX];  /* position of '%' */
  char *arg_posE[MyNL_ARGMAX];  /* position of '$' */
  char *arg_posT[MyNL_ARGMAX];  /* position of type */

  int   arg_num[MyNL_ARGMAX];   /* number of argument (between % and $) */
  int   this_arg=0;
  int   arg_max=0;
  va_list ap;

  if (!f || !fmt_args || !fmt) return(-1);
  for (this_arg=0; this_arg<MyNL_ARGMAX;  arg_num[this_arg++] =0); this_arg = 0;
  fmt_pos = fmt;
  while(1)  /* analyse the format string 'fmt' */
  {
    char *tmp;

    arg_posB[this_arg] = (char *)strchr(fmt_pos, '%');
    tmp = arg_posB[this_arg];
    if (tmp)	/* found a percent */
    {
      char  printf_formats[]="dliouxXeEfgGcs\0";
      arg_posE[this_arg] = (char *)strchr(tmp, '$');
      if (arg_posE[this_arg] && isdigit(tmp[1]))
      { /* found a dollar following a percent  and a digit after percent */
        char  this_arg_chr[10];


        /* extract positional argument index %*$ in fmt */
        strncpy(this_arg_chr, arg_posB[this_arg]+1, arg_posE[this_arg]-arg_posB[this_arg]-1 < 10 ? arg_posE[this_arg]-arg_posB[this_arg]-1 : 9);
        this_arg_chr[arg_posE[this_arg]-arg_posB[this_arg]-1] = '\0';
        arg_num[this_arg] = atoi(this_arg_chr);
        if (arg_num[this_arg] <=0 || arg_num[this_arg] >= MyNL_ARGMAX)
          return(-fprintf(stderr,"pfprintf: invalid positional argument number (%i is <=0 or >=%i) from '%s'.\n", arg_num[this_arg], MyNL_ARGMAX, this_arg_chr));
        /* get type of positional argument: follows '%' -> arg_posE[this_arg]+1 */
        fmt_pos = arg_posE[this_arg]+1;
        fmt_pos[0] = tolower(fmt_pos[0]);
        if (!strchr(printf_formats, fmt_pos[0]))
          return(-fprintf(stderr,"pfprintf: invalid positional argument type (%c != expected %c).\n", fmt_pos[0], fmt_args[arg_num[this_arg]-1]));
        if (fmt_pos[0] == 'l' && (fmt_pos[1] == 'i' || fmt_pos[1] == 'd')) fmt_pos++;
        arg_posT[this_arg] = fmt_pos;
        /* get next argument... */
        this_arg++;
      }
      else
      { /* no dollar or no digit */
        if  (tmp[1] == '%') {
          fmt_pos = arg_posB[this_arg]+2;  /* found %% */
        } else if (strchr(printf_formats,tmp[1])) {
          fmt_pos = arg_posB[this_arg]+1;  /* found %s */
        } else {
          return(-fprintf(stderr,"pfprintf: must use only positional arguments (%s).\n", arg_posB[this_arg]));
        }
      }
    } else
      break;  /* no more % argument */
  }
  arg_max = this_arg;
  /* get arguments from va_arg list, according to their type */
  va_start(ap, fmt_args);
  for (this_arg=0; this_arg<strlen(fmt_args); this_arg++)
  {

    switch(tolower(fmt_args[this_arg]))
    {
      case 's':                       /* string */
              arg_char[this_arg] = va_arg(ap, char *);
              break;
      case 'd':
      case 'i':
      case 'c':                      /* int */
              arg_int[this_arg] = va_arg(ap, int);
              break;
      case 'l':                       /* long int */
              arg_long[this_arg] = va_arg(ap, long int);
              break;
      case 'f':
      case 'g':
      case 'e':                      /* double */
              arg_double[this_arg] = va_arg(ap, double);
              break;
      default: fprintf(stderr,"pfprintf: argument type is not implemented (arg %%%i$ type %c).\n", this_arg+1, fmt_args[this_arg]);
    }
  }
  va_end(ap);
  /* split fmt string into bits containing only 1 argument */
  fmt_pos = fmt;
  for (this_arg=0; this_arg<arg_max; this_arg++)
  {
    char *fmt_bit;
    int   arg_n;

    if (arg_posB[this_arg]-fmt_pos>0)
    {
      fmt_bit = (char*)malloc(arg_posB[this_arg]-fmt_pos+10);
      if (!fmt_bit) return(-fprintf(stderr,"pfprintf: not enough memory.\n"));
      strncpy(fmt_bit, fmt_pos, arg_posB[this_arg]-fmt_pos);
      fmt_bit[arg_posB[this_arg]-fmt_pos] = '\0';
      fprintf(f, "%s", fmt_bit); /* fmt part without argument */
    } else
    {
      fmt_bit = (char*)malloc(10);
      if (!fmt_bit) return(-fprintf(stderr,"pfprintf: not enough memory.\n"));
    }
    arg_n = arg_num[this_arg]-1; /* must be >= 0 */
    strcpy(fmt_bit, "%");
    strncat(fmt_bit, arg_posE[this_arg]+1, arg_posT[this_arg]-arg_posE[this_arg]);
    fmt_bit[arg_posT[this_arg]-arg_posE[this_arg]+1] = '\0';

    switch(tolower(fmt_args[arg_n]))
    {
      case 's': fprintf(f, fmt_bit, arg_char[arg_n]);
                break;
      case 'd':
      case 'i':
      case 'c':                      /* int */
              fprintf(f, fmt_bit, arg_int[arg_n]);
              break;
      case 'l':                       /* long */
              fprintf(f, fmt_bit, arg_long[arg_n]);
              break;
      case 'f':
      case 'g':
      case 'e':                       /* double */
              fprintf(f, fmt_bit, arg_double[arg_n]);
              break;
    }
    fmt_pos = arg_posT[this_arg]+1;
    if (this_arg == arg_max-1)
    { /* add eventual leading characters for last parameter */
      if (fmt_pos < fmt+strlen(fmt))
        fprintf(f, "%s", fmt_pos);
    }
    if (fmt_bit) free(fmt_bit);

  }
  return(this_arg);
} /* pfprintf */

/*******************************************************************************
* mcinfo_header: output header/footer tags/info using specific file format.
*   the 'part' may be 'header' or 'footer' depending on part to write.
* RETURN: negative==error, positive=all went fine
* Used by: mcsiminfo_init, mcsiminfo_close
*******************************************************************************/
static int mcinfo_header(MCDETECTOR detector, char *part)
{
  char*HeadFoot;              /* format string */
  long date_l;                /* date as a long number */
  char date[CHAR_BUF_LENGTH]; /* date as a string */
  char valid_parent[VALID_NAME_LENGTH];     /* who generates that: the simulation or mcstas */

  if (mcdisable_output_files) return(-1);
  if (!detector.file_handle && !strstr(detector.format.Name,"NeXus")) return(-1);
  if (strcmp(part,"header") && strstr(detector.format.Name, "no header")) return (-2);
  if (strcmp(part,"footer") && strstr(detector.format.Name, "no footer")) return (-3);

  /* initiate date and format string ======================================== */

  date_l = detector.date_l;   /* use current write time (from import) by default */
  strncpy(date, detector.date, CHAR_BUF_LENGTH);

  if (part && !strcmp(part,"footer"))
    HeadFoot = detector.format.Footer; /* footer has always detector (current) write time */
  else {
    HeadFoot = detector.format.Header; /* SIM header has simulation start time */
    if (detector.file_handle == mcsiminfo_file
        && !strcmp(detector.filename, mcsiminfo_name)) {
      date_l = mcstartdate;
      time_t t = (time_t)date_l;
      strncpy(date, ctime(&t), CHAR_BUF_LENGTH);
      if (strlen(date)) date[strlen(date)-1] = '\0';
    }
  }

  mcvalid_name(valid_parent,
    strlen(detector.filename) && detector.file_handle!=mcsiminfo_file ?
      detector.filename : detector.simulation, VALID_NAME_LENGTH);

  /* output header ========================================================== */

#ifdef USE_NEXUS
  if (strstr(detector.format.Name, "NeXus")) {
    if(mcnxinfo_header(mcnxHandle, part,
      detector.prefix,                          /* %1$s  PRE  */
      detector.instrument,                      /* %2$s  SRC  */
      strlen(detector.filename) ?
        detector.filename: detector.simulation, /* %3$s  FIL  */
      detector.format.Name,                     /* %4$s  FMT  */
      detector.date,                            /* %5$s  DAT  */
      detector.user,                            /* %6$s  USR  */
      valid_parent,                             /* %7$s  PAR  */
      detector.date_l) == NX_ERROR) {           /* %8$li DATL */
        fprintf(stderr, "Error: writing NeXus header file %s (mcinfo_header)\n",
          strlen(detector.filename) ?
            detector.filename: detector.simulation);
        /* close information data set opened by mcnxfile_section */
      return(-1);
    }
    else return(1);
  }
  else
#endif
  return(pfprintf(detector.file_handle, HeadFoot, "sssssssl",
    detector.prefix,                          /* %1$s  PRE  */
    detector.instrument,                      /* %2$s  SRC  */
    strlen(detector.filename) ?
      detector.filename: detector.simulation, /* %3$s  FIL  */
    detector.format.Name,                     /* %4$s  FMT  */
    detector.date,                            /* %5$s  DAT  */
    detector.user,                            /* %6$s  USR  */
    valid_parent,                             /* %7$s  PAR  */
    detector.date_l));                        /* %8$li DATL */
} /* mcinfo_header */

/*******************************************************************************
* mcinfo_tag: output tag/value using specific file format.
*   outputs a tag/value pair e.g. section.name=value
* RETURN: negative==error, positive=all went fine
* Used by: mcfile_section, mcinfo_instrument, mcinfo_simulation, mcinfo_data
*******************************************************************************/
static int mcinfo_tag(MCDETECTOR detector, char *section, char *name, char *value)
{
  char valid_section[VALID_NAME_LENGTH];
  char valid_name[VALID_NAME_LENGTH];
  int i;

  if (!detector.file_handle && !strstr(detector.format.Name,"NeXus")) return(-1);
  if (!strlen(detector.format.AssignTag)
   || !name || !strlen(name)
   || mcdisable_output_files) return(-1);

  mcvalid_name(valid_section, section, VALID_NAME_LENGTH);
  mcvalid_name(valid_name,    name,    VALID_NAME_LENGTH);

  /* remove quote chars in values =========================================== */
  if (strstr(detector.format.Name, "Scilab")
   || strstr(detector.format.Name, "Matlab")
   || strstr(detector.format.Name, "IDL"))
    for(i = 0; i < strlen(value); i++) {
      if (value[i] == '"' || value[i] == '\'')   value[i] = ' ';
      if (value[i] == '\n'  || value[i] == '\r') value[i] = ';';
    }

  /* output tag ============================================================= */
#ifdef USE_NEXUS
  if (strstr(detector.format.Name, "NeXus")) {
    if(mcnxinfo_tag(mcnxHandle, detector.prefix, valid_section, name, value) == NX_ERROR) {
      fprintf(stderr, "Error: writing NeXus tag file %s/%s=%s (mcinfo_tag)\n", section, name, value);
      return(-1);
    } else return(1); }
  else
#endif
  return(pfprintf(detector.file_handle, detector.format.AssignTag, "ssss",
    detector.prefix,  /* %1$s PRE */
    valid_section,    /* %2$s SEC */
    valid_name,       /* %3$s NAM */
    value));          /* %4$s VAL */
} /* mcinfo_tag */

/*******************************************************************************
* mcfile_section: output section start/end using specific file format.
*   'part' may be 'begin' or 'end' depending on section part to write
*   'type' may be e.g. 'instrument','simulation','component','data'
*   the prefix is automatically indented/un-indented
* RETURN: detector structure with updated prefix (indentation)
* Used by: mcsiminfo_init, mcsiminfo_close, mcinfo_simulation, mcdetector_write_sim
*******************************************************************************/
MCDETECTOR mcfile_section(MCDETECTOR detector, char *part, char *parent, char *section, char *type, int level)
{
  char *Section;
  char valid_section[VALID_NAME_LENGTH];
  char valid_parent[VALID_NAME_LENGTH];

  if((!detector.file_handle && !strstr(detector.format.Name,"NeXus"))
   || !section || !strlen(section)
   || mcdisable_output_files) return(detector);
  if (strcmp(part,"begin") && strstr(detector.format.Name, "no header")) return (detector);
  if (strcmp(part,"end")   && strstr(detector.format.Name, "no footer")) return (detector);

  /* initiate format string and handle prefix-- ============================= */

  if (part && !strcmp(part,"end")) Section = detector.format.EndSection;
  else                             Section = detector.format.BeginSection;

  if (!strlen(Section)) return (detector);

  mcvalid_name(valid_section, section, VALID_NAME_LENGTH);
  if (parent && strlen(parent)) mcvalid_name(valid_parent, parent, VALID_NAME_LENGTH);
  else                                strcpy(valid_parent, "root");

  if (!strcmp(part,"end") && strlen(detector.prefix) >= 2)
    detector.prefix[strlen(detector.prefix)-2]='\0'; /* un-indent prefix */

  /* output section ========================================================= */

#ifdef USE_NEXUS
  if (strstr(detector.format.Name, "NeXus")) {
    if (mcnxfile_section(mcnxHandle,part,
      detector.prefix, type, section, valid_section, parent, valid_parent, level) == NX_ERROR) {
      fprintf(stderr, "Error: writing NeXus section %s/%s=NX%s (mcfile_section)\n", parent, section, type);
      return(detector);
    }
  }
  else
#endif
  pfprintf(detector.file_handle, Section, "ssssssi",
    detector.prefix,/* %1$s  PRE  */
    type,           /* %2$s  TYP  */
    section,        /* %3$s  NAM  */
    valid_section,  /* %4$s  VNA  */
    parent,         /* %5$s  PAR  */
    valid_parent,   /* %6$s  VPA  */
    level);         /* %7$i  LVL */

  /* handle prefix++ and write section start ID ============================= */

  if (!strcmp(part,"begin"))
  {
    if (strlen(detector.prefix) < CHAR_BUF_LENGTH-2) strcat(detector.prefix,"  ");  /* indent prefix */
    if (section && strlen(section))
      mcinfo_tag(detector, section, "name",   section);
    if (parent && strlen(parent))
      mcinfo_tag(detector, section, "parent", parent);
  }

  return(detector);
} /* mcfile_section */

/*******************************************************************************
* mcinfo_instrument: output instrument tags/info. Only written to SIM file
* RETURN: negative==error, positive=all went fine
* Used by: mcsiminfo_init, mcdetector_write_sim
*******************************************************************************/
static int mcinfo_instrument(MCDETECTOR detector, char *name)
{
  char Parameters[CHAR_BUF_LENGTH] = "";
  int  i;

  if (!detector.file_handle && !strstr(detector.format.Name,"NeXus")) return(-1);
  if (!name || !strlen(name)
   || mcdisable_output_files) return(-1);

  /* create parameter string ================================================ */

  for(i = 0; i < mcnumipar; i++)
  {
    char ThisParam[VALID_NAME_LENGTH];
    if (strlen(mcinputtable[i].name) > VALID_NAME_LENGTH) break;
    snprintf(ThisParam, VALID_NAME_LENGTH, " %s(%s)", mcinputtable[i].name,
            (*mcinputtypes[mcinputtable[i].type].parminfo)
                (mcinputtable[i].name));
    strcat(Parameters, ThisParam);
    if (strlen(Parameters) >= CHAR_BUF_LENGTH-VALID_NAME_LENGTH) break;
  }

  /* output data ============================================================ */
  mcinfo_tag(detector, name, "Parameters",    Parameters);
  mcinfo_tag(detector, name, "Source",        mcinstrument_source);
  mcinfo_tag(detector, name, "Trace_enabled", mctraceenabled ? "yes" : "no");
  mcinfo_tag(detector, name, "Default_main",  mcdefaultmain ? "yes" : "no");
  mcinfo_tag(detector, name, "Embedded_runtime",
#ifdef MC_EMBEDDED_RUNTIME
         "yes"
#else
         "no"
#endif
         );

  fflush(NULL);

  return(1);
} /* mcinfo_instrument */

/*******************************************************************************
* mcinfo_simulation: output simulation tags/info
* RETURN: detector structure with updated prefix (indentation)
* Used by: mcsiminfo_init, mcdetector_write_sim
*******************************************************************************/
MCDETECTOR mcinfo_simulation(MCDETECTOR detector, char *instr)
{
  int i;
  char Parameters[CHAR_BUF_LENGTH];

  if (!detector.file_handle && !strstr(detector.format.Name,"NeXus")) return(detector);
  if (!instr || !strlen(instr)
   || mcdisable_output_files) return(detector);

  mcinfo_tag(detector, instr, "Ncount",      detector.ncount);
  mcinfo_tag(detector, instr, "Trace",       mcdotrace ? "yes" : "no");
  mcinfo_tag(detector, instr, "Gravitation", mcgravitation ? "yes" : "no");
  snprintf(Parameters, CHAR_BUF_LENGTH, "%ld", mcseed);
  mcinfo_tag(detector, instr, "Seed", Parameters);

  /* output parameter string ================================================ */
  if (!strstr(detector.format.Name, "McStas")) {
#ifdef USE_NEXUS
    /* close simulation/information */
    if (strstr(detector.format.Name, "NeXus"))
    if (NXclosedata(mcnxHandle) == NX_ERROR)
      fprintf(stderr, "Warning: NeXus: could not close data set simulation/information in %s\n", detector.filename);
#endif
    detector = mcfile_section(detector, "begin", instr, "parameters", "parameters", 3);
  }

  for(i = 0; i < mcnumipar; i++) {
    if (mcget_run_num() || (mcinputtable[i].val && strlen(mcinputtable[i].val))) {
      if (mcinputtable[i].par == NULL)
        strncpy(Parameters, (mcinputtable[i].val ? mcinputtable[i].val : ""), CHAR_BUF_LENGTH);
      else
        (*mcinputtypes[mcinputtable[i].type].printer)(Parameters, mcinputtable[i].par);
      if (strstr(detector.format.Name, "McStas"))
        fprintf(detector.file_handle, "%sParam: %s=%s\n", detector.prefix, mcinputtable[i].name, Parameters);
      else
        mcinfo_tag(detector, "parameters", mcinputtable[i].name, Parameters);
    }
  }
#ifdef USE_NEXUS
  if (strstr(mcformat.Name, "NeXus")) {
    /* close information SDS opened with mcfile_section(detector, "parameters") */
    if (NXclosedata(mcnxHandle) == NX_ERROR)
      fprintf(stderr, "Warning: NeXus: could not close data set simulation/parameters/information in %s\n", detector.filename);
    /* in the parameter group, create one SDS per parameter */
    mcnxfile_parameters(mcnxHandle);

    /* this can not be included in nexus-lib as it requires mcinputtypes which
      is defined only in mccode-r.c (points to function that are defined here) */


    /* re-open the simulation/information dataset */
    if (NXopendata(mcnxHandle, "information") == NX_ERROR) {
      fprintf(stderr, "Warning: NeXus: could not re-open 'information' for simulation in %s\n", detector.filename);
    }
  }
#endif
  if (!strstr(detector.format.Name, "McStas"))
    detector = mcfile_section(detector, "end", instr, "parameters", "parameters", 3);

  fflush(NULL);

  return(detector);
} /* mcinfo_simulation */

/*******************************************************************************
* mcinfo_data: output data tags/info
*              mcinfo_data(detector, NULL)        writes data info to SIM file
*              mcinfo_data(detector, "data file") writes info to data file
* Used by: mcdetector_write_sim, mcdetector_write_data
*******************************************************************************/
void mcinfo_data(MCDETECTOR detector, char *filename)
{
  char parent[CHAR_BUF_LENGTH];

  if (!detector.m || mcdisable_output_files) return;

  /* access either SIM or Data file */
  if (!filename) {
    /* use SIM file which has already be opened with instrument/simulation info */
    detector.file_handle = mcsiminfo_file;
    if (strstr(detector.format.Name, "McStas") && strlen(detector.prefix)>1) detector.prefix[0]=' ';
  } else {
    if (!detector.file_handle) return;
  }

  /* parent must be a valid name */
  mcvalid_name(parent, detector.filename, VALID_NAME_LENGTH);

  /* output data ============================================================ */
  mcinfo_tag(detector, parent, "type",       detector.type);
  mcinfo_tag(detector, parent, "Source",     mcinstrument_source);
  mcinfo_tag(detector, parent, (strstr(detector.format.Name,"McStas") ?
        "component" : "parent"),             detector.component);
  mcinfo_tag(detector, parent, "position",   detector.position);

  mcinfo_tag(detector, parent, "title",      detector.title);
  mcinfo_tag(detector, parent, !mcget_run_num() || mcget_run_num() >= mcget_ncount() ?
      "Ncount" : "ratio",      detector.ncount);

  if (strlen(detector.filename)) {
    mcinfo_tag(detector, parent, "filename", detector.filename);
    mcinfo_tag(detector, parent, "format",   detector.format.Name);
  }

  mcinfo_tag(detector, parent, "statistics", detector.statistics);
  mcinfo_tag(detector, parent, strstr(detector.format.Name, "NeXus") ?
       "Signal" : "signal",                  detector.signal);
  mcinfo_tag(detector, parent, "values",     detector.values);

  if (detector.rank >= 1 || detector.rank == -1)
  {
    mcinfo_tag(detector, parent, (strstr(detector.format.Name," scan ") ?
          "xvars" : "xvar"),                 detector.xvar);
    mcinfo_tag(detector, parent, (strstr(detector.format.Name," scan ") ?
          "yvars" : "yvar"),                 detector.yvar);
    mcinfo_tag(detector, parent, "xlabel",   detector.xlabel);
    mcinfo_tag(detector, parent, "ylabel",   detector.ylabel);
    if (detector.rank > 1 || detector.rank == -1) {
      mcinfo_tag(detector, parent, "zvar",   detector.zvar);
      mcinfo_tag(detector, parent, "zlabel", detector.zlabel);
    }
  }

  mcinfo_tag(detector, parent, abs(detector.rank)==1 && strstr(detector.format.Name, "McStas") ?
                    "xlimits" : "xylimits", detector.limits);
  mcinfo_tag(detector, parent, "variables", detector.rank == -1 ?
                                            detector.zvar : detector.variables);

   if (mcDetectorCustomHeader && strlen(mcDetectorCustomHeader)) {
     mcinfo_tag(detector, parent, "custom",  mcDetectorCustomHeader);
   }

   fflush(NULL);
} /* mcinfo_data */

/*******************************************************************************
* mcdetector_import: build detector structure, merge non-lists from MPI
*                    compute basic stat, write "Detector:" line
*                    mcdetector_import(... filename=NULL ...) sets siminfo data
* RETURN:            detector structure. Invalid data if detector.p1 == NULL
*                    Invalid detector sets m=0 and filename=""
*                    Simulation data  sets m=0 and filename=mcsiminfo_name
* Used by: mcdetector_out_nD public functions, mcdetector_import_sim
*******************************************************************************/
MCDETECTOR mcdetector_import(struct mcformats_struct format,
  char *component, char *title,
  long m, long n,  long p,
  char *xlabel, char *ylabel, char *zlabel,
  char *xvar, char *yvar, char *zvar,
  double x1, double x2, double y1, double y2, double z1, double z2,
  char *filename,
  double *p0, double *p1, double *p2,
  Coords position)
{
  time_t t;       /* for detector.date */
  long   date_l;  /* date as a long number */
  char   istransposed=0;
  char   c[CHAR_BUF_LENGTH]; /* temp var for signal label */

  MCDETECTOR detector;

  /* build MCDETECTOR structure ============================================= */
  /* make sure we do not have NULL for char fields */

  /* these also apply to simfile */
  strncpy (detector.filename,  filename ? filename : "",    CHAR_BUF_LENGTH);
  /* add extension if missing */
  if (strlen(detector.filename) && !strchr(detector.filename, '.') && format.Extension)
  { /* add extension if not in file name already */
    strcat(detector.filename, ".");
    strcat(detector.filename, format.Extension);
  }
  strncpy (detector.component, component ? component : "McStas component", CHAR_BUF_LENGTH);
  snprintf(detector.simulation, CHAR_BUF_LENGTH, "%s%s%s",
      mcdirname && strlen(mcdirname) ? mcdirname : ".", MC_PATHSEP_S, mcsiminfo_name);
  detector.format=format;

  /* set prefix: # for McStas data files, VRML and Python */
  strcpy(detector.prefix,
      (strstr(format.Name, "McStas") && (strlen(detector.filename)) ?
      "# " : ""));

  snprintf(detector.instrument, CHAR_BUF_LENGTH, "%s (%s)", mcinstrument_name, mcinstrument_source);
  snprintf(detector.user, CHAR_BUF_LENGTH,      "%s on %s",
        getenv("USER") ? getenv("USER") : "mcstas",
        getenv("HOST") ? getenv("HOST") : "localhost");
  time(&t);         /* get current write time */
  date_l = (long)t; /* same but as a long */
  snprintf(detector.date, CHAR_BUF_LENGTH, "%s", ctime(&t));
  if (strlen(detector.date))   detector.date[strlen(detector.date)-1] = '\0'; /* remove last \n in date */
  detector.date_l = date_l;

  if (!mcget_run_num() || mcget_run_num() >= mcget_ncount())
    snprintf(detector.ncount, CHAR_BUF_LENGTH, "%g", (double)mcget_ncount());
  else
    snprintf(detector.ncount, CHAR_BUF_LENGTH, "%g/%g", (double)mcget_run_num(), (double)mcget_ncount());

  detector.p0         = p0; detector.p0_orig=p0;
  detector.p1         = p1; detector.p1_orig=p1;
  detector.p2         = p2; detector.p2_orig=p2;
  detector.file_handle= filename ? NULL : mcsiminfo_file;

  /* handle transposition */
  if (!strstr(format.Name, "NeXus")) {
    if (m<0 || n<0 || p<0)                istransposed = !istransposed;
    if (strstr(format.Name, "binary"))    istransposed = !istransposed;
    if (strstr(format.Name, "transpose")) istransposed = !istransposed;
    if (istransposed) { /* do the swap once for all */
      long i=m; m=abs(n); n=abs(i); p=abs(p);
    }
  }
  m=abs(m); n=abs(n); p=abs(p); /* make sure dimensions are positive */
  detector.istransposed = istransposed;

  /* determine detector rank (dimensionality) */
  if (!m || !n || !p || !p1) detector.rank = 4; /* invalid: exit with m=0 filename="" */
  else if (strstr(format.Name," scan ")) detector.rank=-1;  /* 1D scan: multiarray */
  else if (m*n*p == 1)       detector.rank = 0; /* 0D */
  else if (n == 1 || m == 1) detector.rank = 1; /* 1D */
  else if (p == 1)           detector.rank = 2; /* 2D */
  else                       detector.rank = 3; /* 3D */

  /* from rank, set type */
  switch (detector.rank) {
    case -1: sprintf(detector.type, "multiarray_1d(%ld)", n); p=1; break;
    case 0:  strcpy(detector.type,  "array_0d"); m=n=p=1; break;
    case 1:  sprintf(detector.type, "array_1d(%ld)", m*n*p); m *= n*p; n=p=1; break;
    case 2:  sprintf(detector.type, "array_2d(%ld, %ld)", m, n*p); n *= p; p=1; break;
    case 3:  sprintf(detector.type, "array_3d(%ld, %ld, %ld)", m, n, p); break;
    default: m=0; strcpy(detector.type, ""); strcpy(detector.filename, "");/* invalid */
  }

  detector.m    = m;
  detector.n    = n;
  detector.p    = p;

/* init default values for statistics */
  detector.intensity  = 0;
  detector.error      = 0;
  detector.events     = 0;
  detector.min        = 0;
  detector.max        = 0;
  detector.mean       = 0;
  detector.centerX    = 0;
  detector.halfwidthX = 0;
  detector.centerY    = 0;
  detector.halfwidthY = 0;

  /* these only apply to detector files ===================================== */

  snprintf(detector.position, CHAR_BUF_LENGTH, "%g %g %g", position.x, position.y, position.z);
  /* may also store actual detector orientation in the future */

  strncpy(detector.title,      title && strlen(title) ? title : component,       CHAR_BUF_LENGTH);
  strncpy(detector.xlabel,     xlabel && strlen(xlabel) ? xlabel : "X", CHAR_BUF_LENGTH); /* axis labels */
  strncpy(detector.ylabel,     ylabel && strlen(ylabel) ? ylabel : "Y", CHAR_BUF_LENGTH);
  strncpy(detector.zlabel,     zlabel && strlen(zlabel) ? zlabel : "Z", CHAR_BUF_LENGTH);
  strncpy(detector.xvar,       xvar && strlen(xvar) ? xvar :       "x", CHAR_BUF_LENGTH); /* axis variables */
  strncpy(detector.yvar,       yvar && strlen(yvar) ? yvar :       detector.xvar, CHAR_BUF_LENGTH);
  strncpy(detector.zvar,       zvar && strlen(zvar) ? zvar :       detector.yvar, CHAR_BUF_LENGTH);

  /* set "variables" as e.g. "I I_err N" */
  strcpy(c, "I ");
  if (strlen(detector.zvar))      strncpy(c, detector.zvar,32);
  else if (strlen(detector.yvar)) strncpy(c, detector.yvar,32);
  else if (strlen(detector.xvar)) strncpy(c, detector.xvar,32);

  if (detector.rank == 1)
    snprintf(detector.variables, CHAR_BUF_LENGTH, "%s %s %s_err N", detector.xvar, c, c);
  else
    snprintf(detector.variables, CHAR_BUF_LENGTH, "%s %s_err N", c, c);

  /* limits */
  detector.xmin = x1;
  detector.xmax = x2;
  detector.ymin = y1;
  detector.ymax = y2;
  detector.zmin = z1;
  detector.zmax = z2;
  if (abs(detector.rank) == 1 && strstr(format.Name, "McStas"))
    snprintf(detector.limits, CHAR_BUF_LENGTH, "%g %g", x1, x2);
  else if (detector.rank == 2)
    snprintf(detector.limits, CHAR_BUF_LENGTH, "%g %g %g %g", x1, x2, y1, y2);
  else
    snprintf(detector.limits, CHAR_BUF_LENGTH, "%g %g %g %g %g %g", x1, x2, y1, y2, z1, z2);

  if (!m || !n || !p) {
    return(detector);
  }

  /* if MPI and nodes_nb > 1: reduce data sets when using MPI =============== */
  /* not for scan steps/multiarray (only processed by root */
#ifdef USE_MPI
  if (!strstr(format.Name," list ") && mpi_node_count > 1 && detector.rank != -1) {
    /* we save additive data: reduce everything into mpi_node_root */
    if (p0) mc_MPI_Sum(p0, m*n*p);
    if (p1) mc_MPI_Sum(p1, m*n*p);
    if (p2) mc_MPI_Sum(p2, m*n*p);
    if (!p0) {  /* additive signal must be then divided by the number of nodes */
      int i;
      for (i=0; i<m*n*p; i++) {
        p1[i] /= mpi_node_count;
        if (p2) p2[i] /= mpi_node_count;
      }
    }
  }
#endif /* USE_MPI */

  /* compute statistics and update MCDETECTOR structure ===================== */
  double sum_z   = 0;
  double min_z   = 0;
  double max_z   = 0;
  double fmon_x=0, smon_x=0, fmon_y=0, smon_y=0, mean_z=0;
  double Nsum=0;
  double P2sum=0;

  double sum_xz  = 0;
  double sum_yz  = 0;
  double sum_x   = 0;
  double sum_y   = 0;
  double sum_x2z = 0;
  double sum_y2z = 0;
  int    i,j;
  char   hasnan=0;
  char   hasinf=0;
  char   israw = (strstr(detector.format.Name," raw") != NULL);
  double *this_p1=NULL; /* new 1D McStas array [x I E N]. Freed after writing data */

  /* if McStas/PGPLOT and rank==1 we create a new m*4 data block=[x I E N] */
  if (detector.rank == 1 && strstr(detector.format.Name,"McStas")) {
    this_p1 = (double *)calloc(detector.m*detector.n*detector.p*4, sizeof(double));
    if (!this_p1)
      exit(-fprintf(stderr, "Error: Out of memory creating %li 1D McStas data set for file '%s' (mcdetector_import)\n", detector.m*detector.n*detector.p*4*sizeof(double*), detector.filename));
  }

  max_z = min_z = p1[0];

  for(j = 0; j < n*p; j++)
  {
    for(i = 0; i < m; i++)
    {
      double x,y,z;
      double N, E;
      long   index= !detector.istransposed ? i*n*p + j : i+j*m;

      if (m) x = x1 + (i + 0.5)/m*(x2 - x1); else x = 0;
      if (n && p) y = y1 + (j + 0.5)/n/p*(y2 - y1); else y = 0;
      z = p1[index];
      N = p0 ? p0[index] : 1;
      E = p2 ? p2[index] : 0;
      if (p2 && !israw) p2[index] = (*mcestimate_error_p)(p0[index],p1[index],p2[index]); /* set sigma */

      /* compute stats integrals */
      sum_xz += x*z;
      sum_yz += y*z;
      sum_x += x;
      sum_y += y;
      sum_z += z;
      sum_x2z += x*x*z;
      sum_y2z += y*y*z;
      if (z > max_z) max_z = z;
      if (z < min_z) min_z = z;

      Nsum += N;
      P2sum += E;

      if (isnan(z) || isnan(E) || isnan(N)) hasnan=1;
      if (isinf(z) || isinf(E) || isinf(N)) hasinf=1;

      if (detector.rank == 1 && this_p1 && strstr(detector.format.Name,"McStas")) {
        /* fill-in 1D McStas array [x I E N] */
        this_p1[index*4]   = x;
        this_p1[index*4+1] = z;
        this_p1[index*4+2] = p2 ? p2[index] : 0;
        this_p1[index*4+3] = N;
      }
    }
  } /* for j */

  /* compute 1st and 2nd moments */
  if (sum_z && n*m*p)
  {
    fmon_x = sum_xz/sum_z;
    fmon_y = sum_yz/sum_z;
    smon_x = sum_x2z/sum_z-fmon_x*fmon_x; smon_x = smon_x > 0 ? sqrt(smon_x) : 0;
    smon_y = sum_y2z/sum_z-fmon_y*fmon_y; smon_y = smon_y > 0 ? sqrt(smon_y) : 0;
    mean_z = sum_z/n/m/p;
  }
  /* store statistics into detector */
  detector.intensity = sum_z;
  detector.error     = (*mcestimate_error_p)(Nsum, sum_z, P2sum);
  detector.events    = Nsum;
  detector.min       = min_z;
  detector.max       = max_z;
  detector.mean      = mean_z;
  detector.centerX   = fmon_x;
  detector.halfwidthX= smon_x;
  detector.centerY   = fmon_y;
  detector.halfwidthY= smon_y;

  /* if McStas/PGPLOT and rank==1 replace p1 with new m*4 1D McStas and clear others */
  if (detector.rank == 1 && this_p1 && strstr(detector.format.Name,"McStas")) {
    detector.p1 = this_p1;
    detector.n=detector.m; detector.m  = 4;
    detector.p0 = NULL;
    detector.p2 = NULL;
    detector.istransposed = 1;
  }

  if (n*m*p > 1)
    sprintf(detector.signal, "Min=%g; Max=%g; Mean=%g;", detector.min, detector.max, detector.mean);
  else
    strcpy(detector.signal, "");
  sprintf(detector.values, "%g %g %g", detector.intensity, detector.error, detector.events);

  switch (detector.rank) {
    case 0:  strcpy(detector.statistics, ""); break;
    case 1:  snprintf(detector.statistics, CHAR_BUF_LENGTH, "X0=%g; dX=%g;",
      detector.centerX, detector.halfwidthX); break;
    case 2:
    case 3:  snprintf(detector.statistics, CHAR_BUF_LENGTH, "X0=%g; dX=%g; Y0=%g; dY=%g;",
      detector.centerX, detector.halfwidthX, detector.centerY, detector.halfwidthY);
      break;
    default: strcpy(detector.statistics, "");
  }

#ifdef USE_MPI
  /* slaves are done */
  if(mpi_node_rank != mpi_node_root) {
    return detector;
  }
#endif
  /* output "Detector:" line ================================================ */
  /* when this is a detector written by a component (not the SAVE from instrument),
     not a multiarray nor event lists */
  if (detector.rank == -1 || strstr(format.Name," list ")) return(detector);

  if (!strcmp(detector.component, mcinstrument_name)) {
    if (strlen(detector.filename))  /* we name it from its filename, or from its title */
      mcvalid_name(c, detector.filename, CHAR_BUF_LENGTH);
    else
      mcvalid_name(c, detector.title, CHAR_BUF_LENGTH);
  } else
    strncpy(c, detector.component, CHAR_BUF_LENGTH);  /* usual detectors written by components */

  printf("Detector: %s_I=%g %s_ERR=%g %s_N=%g",
         c, detector.intensity,
         c, detector.error,
         c, detector.events);
  printf(" \"%s\"\n", strlen(detector.filename) ? detector.filename : detector.component);

  if (hasnan)
    printf("WARNING: Nan detected in component %s\n", detector.component);
  if (hasinf)
    printf("WARNING: Inf detected in component %s\n", detector.component);

  /* add warning in case of low statistics or large number of bins in text format mode */
  if (detector.error > detector.intensity/4)
    printf("WARNING: file '%s': Low Statistics\n",    detector.filename);
  else if (strlen(detector.filename)) {
    if (m*n*p > 1000 && Nsum < m*n*p && Nsum)
       printf(
        "WARNING: file '%s': Low Statistics (%g events in %ldx%ldx%ld bins).\n",
        detector.filename, Nsum, m,n,p);
    if ( !strstr(format.Name, "binary")
      && (strstr(format.Name, "Scilab") || strstr(format.Name, "Matlab"))
      && (n*m*p > 10000 || m > 1000) ) printf(
        "WARNING: file '%s' (%s format)\n"
        "         Large matrices (%ldx%ldx%ld) in text mode may be\n"
        "         slow or fail at import. Prefer binary mode e.g. --format='Matlab_binary'.\n",
        detector.filename, format.Name, m,n,p);
  }

  if (mcDetectorCustomHeader && strlen(mcDetectorCustomHeader)) {
   if (strstr(detector.format.Name, "Octave") || strstr(detector.format.Name, "Matlab"))
     str_rep(mcDetectorCustomHeader, "%PRE", "%   ");
   else if (strstr(detector.format.Name, "IDL"))    str_rep(mcDetectorCustomHeader, "%PRE", ";   ");
   else if (strstr(detector.format.Name, "Scilab")) str_rep(mcDetectorCustomHeader, "%PRE", "//  ");
   else if (strstr(detector.format.Name, "McStas")) str_rep(mcDetectorCustomHeader, "%PRE", "#   ");
   else str_rep(mcDetectorCustomHeader, "%PRE", "    ");
  }

  return(detector);
} /* mcdetector_import */

/*******************************************************************************
* mcdetector_register: adds detector to the detector array, for scans and sim abstract
* RETURN:            detector array pointer
* Used by: mcdetector_out_xD
*******************************************************************************/
MCDETECTOR* mcdetector_register(MCDETECTOR detector)
{
#ifdef USE_MPI
  /* only for Master */
  if(mpi_node_rank != mpi_node_root)                      return(NULL);
#endif

  if (detector.m) {
    /* add detector entry in the mcDetectorArray */
    if (!mcDetectorArray ||
        (mcDetectorArray && mcDetectorArray_size <= mcDetectorArray_index)) {
      mcDetectorArray_size+=CHAR_BUF_LENGTH;
      if (!mcDetectorArray || !mcDetectorArray_index)
        mcDetectorArray = (MCDETECTOR*)calloc(mcDetectorArray_size, sizeof(MCDETECTOR));
      else
        mcDetectorArray = (MCDETECTOR*)realloc(mcDetectorArray, mcDetectorArray_size*sizeof(MCDETECTOR));
    }
    mcDetectorArray[mcDetectorArray_index++]=detector;
  }

  return(mcDetectorArray);

} /* mcdetector_register */

MCDETECTOR mcdetector_init(void) {
  Coords zero={0.0,0.0,0.0};
  MCDETECTOR detector=mcdetector_import(mcformat, "mcstas", NULL,
    0,0,0,            /* mnp */
    NULL, NULL, NULL, /* labels */
    NULL, NULL, NULL, /* vars */
    0,0,0,0,0,0,      /* limits */
    NULL,             /* filename */
    NULL, NULL, NULL, /* p012 */
    zero);
  strncpy(detector.filename, mcsiminfo_name, CHAR_BUF_LENGTH);
  return(detector);
}

/*******************************************************************************
* mcdetector_import_sim: build detector structure as SIM data
* RETURN:            detector structure for SIM (m=0 and filename=mcsiminfo_name).
* Used by: mcsiminfo_init, mcsiminfo_close, mcdetector_write_sim
*******************************************************************************/
MCDETECTOR mcdetector_import_sim(void) {
  MCDETECTOR detector  = mcdetector_init();
  detector.file_handle = mcsiminfo_file;
  return(detector);
}

/*******************************************************************************
* mcsiminfo_init: writes simulation structured description file (mcstas.sim)
*                 f may be NULL or e.g. stdout
*                 opens NX file if this is NeXus format
* Used by: mcsave/mcfinally from code generation (cogen), mcinfo, mcstas_main
*******************************************************************************/
static int mcsiminfo_init(FILE *f)
{

#ifdef USE_MPI
  /* only for Master */
  if(mpi_node_rank != mpi_node_root)                      return(-1);
#endif
  if (mcdisable_output_files)                             return(-2);
  if (!f && (!mcsiminfo_name || !strlen(mcsiminfo_name))) return(-3);

  /* clear list of opened files to start new save session */
  if (mcopenedfiles && strlen(mcopenedfiles) > 0) strcpy(mcopenedfiles, "");

  /* open sim file ========================================================== */

#ifdef USE_NEXUS
  /* NeXus sim info is the NeXus root file. */
  if(strstr(mcformat.Name, "NeXus")) {
    mcsiminfo_file = NULL;
    if (mcnxfile_init(mcsiminfo_name, mcformat.Extension,
      strstr(mcformat.Name, "append") || strstr(mcformat.Name, "catenate") ? "a":"w",
      &mcnxHandle) == NX_ERROR) {
      return(-fprintf(stderr, "Error: opening NeXus file %s (mcsiminfo_init)\n", mcsiminfo_name));
    } else {
      mcsiminfo_file = (FILE*)mcnxHandle; /* make it non NULL */
    }
  } else /* not NX - includes next if+else */
#endif
  {
    if (!f || (!mcsiminfo_file && f != stdout))
      mcsiminfo_file = mcnew_file(mcsiminfo_name, mcformat.Extension, "w");
    else mcsiminfo_file = f;
  }

  if(!mcsiminfo_file)
    return(-fprintf(stderr,
            "Warning: could not open simulation description file '%s' (mcsiminfo_init)\n",
            mcsiminfo_name));

  /* initialize sim file information, sets detector.file_handle=mcsiminfo_file */
  MCDETECTOR mcsiminfo = mcdetector_import_sim();

  /* flag true for McStas or NX data format */
  int  ismcstas_nx= (strstr(mcformat.Name, "McStas") || strstr(mcformat.Name, "NeXus"));

  /* start to write meta data =============================================== */

#ifdef USE_NEXUS
  if (strstr(mcformat.Name, "NeXus")) {
    /* NXentry class */
    char file_time[CHAR_BUF_LENGTH];
    snprintf(file_time, CHAR_BUF_LENGTH, "%s_%li", mcinstrument_name, mcstartdate);
    mcsiminfo = mcfile_section(mcsiminfo, "begin", "mcstas", file_time, "entry", 1);
  }
#endif
  mcinfo_header(mcsiminfo, "header");
#ifdef USE_NEXUS
  /* close information SDS opened with mcfile_section(siminfo, "mcstas (header)") */
  if (strstr(mcformat.Name, "NeXus")) {
    if (NXclosedata(mcnxHandle) == NX_ERROR)
      fprintf(stderr, "Warning: NeXus: could not close data set mcstas/information (header)\n");
  }
#endif

  /* begin-end instrument =================================================== */
  mcsiminfo = mcfile_section(mcsiminfo, "begin", mcsiminfo.simulation, mcinstrument_name, "instrument", 1);
  mcinfo_instrument(mcsiminfo, mcinstrument_name);

#ifdef USE_NEXUS
  if (strstr(mcformat.Name, "NeXus")) {
    /* close information SDS opened with mcfile_section(siminfo, "instrument") */
    if (NXclosedata(mcnxHandle) == NX_ERROR)
      fprintf(stderr, "Warning: NeXus: could not close data set instrument/information\n");
    /* insert instrument source code */
    mcnxfile_instrcode(mcnxHandle, mcinstrument_source, mcinstrument_name);
  }
#endif
  if (ismcstas_nx)
    mcsiminfo = mcfile_section(mcsiminfo, "end", mcsiminfo.simulation, mcinstrument_name, "instrument", 1);

  /* begin-end simulation =================================================== */
  mcsiminfo = mcfile_section(mcsiminfo, "begin", mcsiminfo.simulation, mcsiminfo_name, "simulation", 2);
  mcsiminfo = mcinfo_simulation(mcsiminfo, mcsiminfo_name);

#ifdef USE_NEXUS
  /* close information SDS opened with mcfile_section(siminfo,"simulation") */
  if (strstr(mcformat.Name, "NeXus")) {
    if (NXclosedata(mcnxHandle) == NX_ERROR)
      fprintf(stderr, "Warning: NeXus: could not close data set simulation/information\n");
  }
#endif
  if (ismcstas_nx)
    mcsiminfo = mcfile_section(mcsiminfo, "end", mcsiminfo.simulation, mcsiminfo_name, "simulation", 2);

  return(1);
} /* mcsiminfo_init */

/*******************************************************************************
* mcdetector_write_content: write mcstas.dat, which has integrated intensities for all monitors
* Used by: mcsiminfo_close
*******************************************************************************/
int mcdetector_write_content(MCDETECTOR *DetectorArray, long DetectorArray_index)
{
#ifdef USE_MPI
  /* only for Master */
  if(mpi_node_rank != mpi_node_root)                      return(-1);
#endif
  if (mcdisable_output_files)                             return(-2);
  if (!mcsiminfo_name || !strlen(mcsiminfo_name))         return(-3);
  if (!DetectorArray_index)                               return(-4);

  /* build p1 array from all detector integrated counts */
  double *this_p1 = (double *)calloc(DetectorArray_index*2, sizeof(double));
  int i;

  if (this_p1 && DetectorArray) {
    char   *labels=NULL;
    long    labels_size=0;
    long    index=0;
    for (i=0; i < DetectorArray_index; i++) {
        char mem[CHAR_BUF_LENGTH];
        char valid[CHAR_BUF_LENGTH];
        /* store I I_err */
        this_p1[index++] = DetectorArray[i].intensity;
        this_p1[index++] = DetectorArray[i].error;
        /* add corresponding label */
        mcvalid_name(valid, DetectorArray[i].filename, CHAR_BUF_LENGTH);
        sprintf(mem, "%s_I %s_Err ", valid, valid);
        if (!labels ||
          (labels && labels_size <= strlen(labels)+strlen(mem))) {
          labels_size+=CHAR_BUF_LENGTH;
          if (!labels || !strlen(labels))
            labels = calloc(1, labels_size);
          else
            labels = realloc(labels, labels_size);
        }
        strcat(labels, " ");
        strcat(labels, mem);
    } /* for */

    struct mcformats_struct format=mcformat;
    strcat(format.Name, " scan step");
    Coords zero={0.0,0.0,0.0};

    /* now create detector and write 'abstract' file */
    MCDETECTOR detector = mcdetector_import(format,
      mcinstrument_name, "Monitor integrated counts",
      index, 1, 1,
      "Monitors", "I", "Integrated Signal",
      "Index", labels, "I",
      0, index-1, 0, 0, 0, 0, "content",  /* use name from OpenOffice content.xml description file */
      NULL, this_p1, NULL, zero);

    mcdetector_write_data(detector);

    free(labels); labels=NULL; labels_size=0;

    /* free DETECTOR array */
    free(this_p1); this_p1=NULL;
    free(mcDetectorArray); mcDetectorArray=NULL;
  } /* if this_p1 */

  return 0;

} /* mcdetector_write_content */


/*******************************************************************************
* mcsiminfo_close: close simulation file (mcstas.sim) and write mcstas.dat
* Used by: mcsave/mcfinally from code generation (cogen), mcinfo, mcstas_main
*******************************************************************************/
void mcsiminfo_close(void)
{
  int i;
#ifdef USE_MPI
  if(mpi_node_rank != mpi_node_root) return;
#endif
  if (mcdisable_output_files || !mcsiminfo_file) return;

  int  ismcstas_nx  = (strstr(mcformat.Name, "McStas") || strstr(mcformat.Name, "NeXus"));

  mcdetector_write_content(mcDetectorArray, mcDetectorArray_index);

  /* initialize sim file information, sets detector.file_handle=mcsiminfo_file */
  MCDETECTOR mcsiminfo = mcdetector_import_sim();

  /* close those sections which were opened in mcsiminfo_init =============== */
  if (!ismcstas_nx) {
    mcfile_section(mcsiminfo, "end", mcsiminfo.simulation, mcsiminfo_name, "simulation", 2);
    mcfile_section(mcsiminfo, "end", mcsiminfo.simulation, mcinstrument_name, "instrument", 1);
  }
#ifdef USE_NEXUS
  if (strstr(mcformat.Name, "NeXus")) {
    /* re-open the simulation/information dataset */
    if (NXopendata(mcnxHandle, "information") == NX_ERROR)
      fprintf(stderr, "Warning: NeXus: could not re-open 'information' for mcstas NXentry\n");
  }
#endif
  mcinfo_header(mcsiminfo, "footer");
#ifdef USE_NEXUS
  /* close information SDS opened with mcfile_section(siminfo, "mcstas(footer)" */
  if (strstr(mcformat.Name, "NeXus")) {
    if (NXclosedata(mcnxHandle) == NX_ERROR)
      fprintf(stderr, "Warning: NeXus: could not close data set mcstas/information (footer)\n");
    mcfile_section(mcsiminfo, "end", "mcstas", mcinstrument_name, "entry", 1);
  }
#endif

  /* close sim file ========================================================= */
#ifdef USE_NEXUS
  if (strstr(mcformat.Name, "NeXus")) mcnxfile_close(&mcnxHandle);
  else
#endif
  if (mcsiminfo_file != stdout && mcsiminfo_file) {
    fclose(mcsiminfo_file);
  }
  mcsiminfo_file = NULL;

} /* mcsiminfo_close */

/*******************************************************************************
* mcfile_data: output a single data block using specific file format, e.g. "part=[ array ]"
*   'part' can be 'data','errors','ncount'
* Used by: mcdetector_write_sim, mcdetector_write_data
*******************************************************************************/
int mcfile_data(MCDETECTOR detector, char *part)
{
  double *this_p1=NULL;
  char   *Begin  =NULL;
  char   *End    =NULL;
  char    valid_xlabel[VALID_NAME_LENGTH];
  char    valid_ylabel[VALID_NAME_LENGTH];
  char    valid_zlabel[VALID_NAME_LENGTH];
  char    valid_parent[VALID_NAME_LENGTH];

  if (strstr(part,"data"))
  { this_p1=detector.p1; Begin = detector.format.BeginData; End = detector.format.EndData; }
  if (strstr(part,"errors"))
  { this_p1=detector.p2;Begin = detector.format.BeginErrors; End = detector.format.EndErrors; }
  if (strstr(part,"ncount") || strstr(part,"events"))
  { this_p1=detector.p0;Begin = detector.format.BeginNcount; End = detector.format.EndNcount; }

  if (!this_p1 || mcdisable_output_files) return(-1);
  if (!detector.file_handle && !strstr(detector.format.Name,"NeXus")) return(-1);
  if (!detector.rank) return(-1);


  mcvalid_name(valid_xlabel, detector.xlabel, VALID_NAME_LENGTH);
  mcvalid_name(valid_ylabel, detector.ylabel, VALID_NAME_LENGTH);
  mcvalid_name(valid_zlabel, detector.zlabel, VALID_NAME_LENGTH);
  mcvalid_name(valid_parent, detector.filename, VALID_NAME_LENGTH);

  /* output Begin =========================================================== */
  if (!strstr(detector.format.Name,"NeXus")
   && (!strstr(detector.format.Name,"binary") || strstr(part,"empty array"))
   && !strstr(detector.format.Name,"no header"))
  pfprintf(detector.file_handle, Begin, "sssssssssssssiiigggggg",
      detector.prefix,       /* %1$s   PRE  */
      valid_parent,          /* %2$s   PAR  */
      detector.filename,     /* %3$s   FIL  */
      detector.xlabel,       /* %4$s   XLA  */
      valid_xlabel,          /* %5$s   XVL  */
      detector.ylabel,       /* %6$s   YLA  */
      valid_ylabel,          /* %7$s   YVL  */
      detector.zlabel,       /* %8$s   ZLA  */
      valid_zlabel,          /* %9$s   ZVL  */
      detector.title,        /* %10$s  TITL */
      detector.xvar,         /* %11$s  XVAR */
      detector.yvar,         /* %12$s  YVAR */
      detector.zvar,         /* %13$s  ZVAR */
      detector.m,            /* %14$i  MDIM */
      detector.n,            /* %15$i  NDIM */
      detector.p,            /* %16$i  PDIM */
      detector.xmin,         /* %17$g  XMIN */
      detector.xmax,         /* %18$g  XMAX */
      detector.ymin,         /* %19$g  YMIN */
      detector.ymax,         /* %20$g  YMAX */
      detector.zmin,         /* %21$g  ZMIN */
      detector.zmax);        /* %22$g  ZMAX */

  /* output array */
  if (strstr(part,"empty array")) {
    /* skip array output: set as empty */

    /* special case of IDL: can not have empty vectors. Init to 'external' */
    if (strstr(detector.format.Name, "IDL")) fprintf(detector.file_handle, "'external'");
  } else {
#ifdef USE_NEXUS
    /* array NeXus ========================================================== */
    if (strstr(detector.format.Name,"NeXus")) {
      if(mcnxfile_data(mcnxHandle, detector, part,
        valid_parent, valid_xlabel, valid_ylabel, valid_zlabel) == NX_ERROR) {
        fprintf(stderr, "Error: writing NeXus data %s/%s (mcfile_data)\n", valid_parent, detector.filename);
        return(-1);
      }
      return(1);
    } /* end if NeXus */
#endif
    /* array non binary (text) ============================================== */
    if (!strstr(detector.format.Name, "binary")
     && !strstr(detector.format.Name, "float") && !strstr(detector.format.Name, "double"))
    {
      char eol_char[3];
      int isIDL    = (strstr(detector.format.Name, "IDL") != NULL);
      int isPython = (strstr(detector.format.Name, "Python") != NULL);
      int i,j;
      if (isIDL) strcpy(eol_char,"$\n");
      else if (isPython) strcpy(eol_char,"\\\n");
      else strcpy(eol_char,"\n");

      for(j = 0; j < detector.n*detector.p; j++)  /* loop on rows (y) */
      {
        for(i = 0; i < detector.m; i++)  /* write all columns (x) */
        {
          long index   = !detector.istransposed ? i*detector.n*detector.p + j : i+j*detector.m;
          double value = this_p1[index];
          fprintf(detector.file_handle, "%.12g", value);
          fprintf(detector.file_handle, "%s",
            (isIDL || isPython) && ((i+1)*(j+1) < detector.m*detector.n*detector.p) ?
            "," : " ");
        }
        fprintf(detector.file_handle, "%s", eol_char);
      } /* end 2 loops if not Binary */
    } /* end if !Binary */

    /* array binary double =================================================== */
    if (strstr(detector.format.Name, "double"))
    {
      long count=0;
      count = fwrite(this_p1, sizeof(double), detector.m*detector.n*detector.p, detector.file_handle);
      if (count != detector.m*detector.n*detector.p)
        fprintf(stderr, "Error: writing double binary file '%s' (%li instead of %li, mcfile_data)\n", detector.filename,count, detector.m*detector.n*detector.p);
    } /* end if Binary double */

    /* array binary float =================================================== */
    if (strstr(detector.format.Name, "binary") || strstr(detector.format.Name, "float"))
    {
      float *s;
      s = (float*)malloc(detector.m*detector.n*detector.p*sizeof(float));
      if (s)
      {
        long    i, count=0;
        for (i=0; i<detector.m*detector.n*detector.p; i++) {
          s[i] = (float)this_p1[i]; }
        count = fwrite(s, sizeof(float), detector.m*detector.n*detector.p, detector.file_handle);
        if (count != detector.m*detector.n*detector.p)
          fprintf(stderr, "Error writing float binary file '%s' (%li instead of %li, mcfile_data)\n",
            detector.filename,count, detector.m*detector.n*detector.p);
        free(s);
      } else
      fprintf(stderr, "Error: Out of memory for writing %li float binary file '%s' (mcfile_data)\n",
        detector.m*detector.n*detector.p*sizeof(float), detector.filename);
    } /* end if Binary float */
  } /* end if not empty array */

  /* output End ============================================================= */
  if (!strstr(detector.format.Name,"NeXus")
   && (!strstr(detector.format.Name,"binary") || strstr(part,"empty array"))
   && !strstr(detector.format.Name,"no footer"))
  pfprintf(detector.file_handle, End, "sssssssssssssiiigggggg",
      detector.prefix,       /* %1$s   PRE  */
      valid_parent,          /* %2$s   PAR  */
      detector.filename,     /* %3$s   FIL  */
      detector.xlabel,       /* %4$s   XLA  */
      valid_xlabel,          /* %5$s   XVL  */
      detector.ylabel,       /* %6$s   YLA  */
      valid_ylabel,          /* %7$s   YVL  */
      detector.zlabel,       /* %8$s   ZLA  */
      valid_zlabel,          /* %9$s   ZVL  */
      detector.title,        /* %10$s  TITL */
      detector.xvar,         /* %11$s  XVAR */
      detector.yvar,         /* %12$s  YVAR */
      detector.zvar,         /* %13$s  ZVAR */
      detector.m,            /* %14$i  MDIM */
      detector.n,            /* %15$i  NDIM */
      detector.p,            /* %16$i  PDIM */
      detector.xmin,         /* %17$g  XMIN */
      detector.xmax,         /* %18$g  XMAX */
      detector.ymin,         /* %19$g  YMIN */
      detector.ymax,         /* %20$g  YMAX */
      detector.zmin,         /* %21$g  ZMIN */
      detector.zmax);        /* %22$g  ZMAX */

  return(2);
} /* mcfile_data */

/*******************************************************************************
* mcdetector_write_sim: write information to sim file
*******************************************************************************/
MCDETECTOR mcdetector_write_sim(MCDETECTOR detector)
{
  /* MPI: only write sim by Master ========================================== */
#ifdef USE_MPI
  if (mpi_node_rank != mpi_node_root) return(detector);
  if (mcdisable_output_files) return(detector);
#else
  /* skip invalid detectors */
  if (!detector.m || mcdisable_output_files) return(detector);
#endif
  

  /* sim file has been initialized when starting simulation and when calling
   * mcsave ; this defines mcsiminfo_file as the SIM file handle
   * and calls:
   *    mcinfo_header
   *    mcfile_section begin instrument
   *    mcinfo_instrument
   *    mcfile_section end instrument
   *    mcfile_section begin simulation
   *    mcinfo_simulation
   *    mcfile_section end simulation
   *    sets "mcopenedfiles" list to empty string
   * When using NeXus format, this information is stored into mcnxHandle NX
   *
   * The sim file (and mcnxHandle) is closed when ending mcsave
   */

  MCDETECTOR simfile = mcdetector_import_sim(); /* store reference structure to SIM file */

  /* add component and data section to SIM file */
  if (!strstr(detector.format.Name,"NeXus"))
    simfile = mcfile_section(simfile, "begin", detector.simulation, detector.component, "component", 3);
  simfile = mcfile_section(simfile, "begin", detector.component, detector.filename, "data", 4);

  /* handle indentation for simfile */
  char prefix[CHAR_BUF_LENGTH];
  strncpy(prefix, detector.prefix, CHAR_BUF_LENGTH);
  strncpy(detector.prefix, simfile.prefix, CHAR_BUF_LENGTH);

  /* WRITE detector information to sim file ================================= */
  mcinfo_data(detector, NULL);
#ifdef USE_NEXUS
  /* close information SDS opened with mcfile_section(siminfo,"data") */
  if (strstr(mcformat.Name, "NeXus"))
    if (NXclosedata(mcnxHandle) == NX_ERROR)
      fprintf(stderr, "Warning: NeXus: could not close data set %s/information\n",
        detector.filename);
#endif
  /* WRITE data link to SIM file */
  if (!strstr(detector.format.Name,"McStas") && !mcsingle_file) {
    FILE *file=detector.file_handle;
    detector.file_handle = mcsiminfo_file;
    mcfile_data(detector, "data (empty array)");
    if (detector.p2) mcfile_data(detector, "errors (empty array)");
    if (detector.p0) mcfile_data(detector, "events (empty array)");
    detector.file_handle = file;
  }

  /* close component and data sections in SIM file */
  simfile = mcfile_section(simfile, "end", detector.component, detector.filename, "data", 4);
  if (!strstr(detector.format.Name,"NeXus"))
    simfile = mcfile_section(simfile, "end", detector.simulation, detector.component, "component", 3);

  strncpy(detector.prefix, prefix, CHAR_BUF_LENGTH);

  return(detector);
} /* mcdetector_write_sim */

/*******************************************************************************
* mcdetector_write_data: write information to data file and catenate lists
*                        this is where we open/close data files
*                        also free detector.p1=this_p1 field which may hold
*                        1D McStas [x I Ierr N] array which is set in mcdetector_import
*******************************************************************************/
MCDETECTOR mcdetector_write_data(MCDETECTOR detector)
{
  /* skip if 0D or no filename (only stored in sim file) */
  if (!detector.rank) return(detector);

#ifdef USE_MPI
  /* only by MASTER for non lists (MPI reduce has been done in detector_import) */
  if (!strstr(detector.format.Name," list ") && mpi_node_rank != mpi_node_root) {
    if (detector.rank == 1 && detector.p1 && strstr(detector.format.Name,"McStas")) {
      free(detector.p1);  /* 'this_p1' allocated in mcdetector_import for 1D McStas data sets [x I E N] */
      detector.p0 = detector.p0_orig;
      detector.p1 = detector.p1_orig;
      detector.p2 = detector.p2_orig;
      detector.m = detector.n; detector.n=1; detector.istransposed=0;
    }
    return(detector);
  }
#else
  /* skip if no data */
  if (!detector.m || !strlen(detector.filename)) return(detector);
#endif

  /* OPEN data file (possibly appending if already opened) ================== */
  if (mcformat_data.Name && strlen(mcformat_data.Name) && !mcsingle_file)
    detector.format = mcformat_data;

  if (!strstr(detector.format.Name, "NeXus")) {
    /* explicitely open data file if not NeXus format */
    char mode[10];

    /* open or re-open file for write/append */
    strcpy(mode,
           (strstr(detector.format.Name, "no header")
            || strstr(detector.format.Name, "append") || strstr(detector.format.Name, "catenate")
            || strstr(mcopenedfiles, detector.filename) ?
           "a" : "w"));
    if (strstr(detector.format.Name, "binary")) strcat(mode, "b");
    detector.file_handle = mcnew_file(!mcsingle_file ?
      detector.filename : mcsiminfo_name,
      detector.format.Extension, mode);
  } else {
    /* NeXus file mcnxHandle has been opened in mcsiminfo_init */
    /* but we must open the proper Data Set group and write information */
    mcfile_section(detector, "begin", detector.component, detector.filename, "data", 4);
  }

  /* WRITE data header (except when in 'no header') */
  if (!strstr(detector.format.Name, "no header")) {
    if (!strstr(detector.format.Name, "binary") && !mcascii_only)  {
      /* skip in data-only mode or binary */
      mcinfo_header(detector, "header");
      mcinfo_simulation(detector, mcsiminfo_name);
      mcinfo_data(detector, detector.filename);
      /* mcinfo_simulation(detector, detector.filename); */
    }
  }
#ifdef USE_NEXUS
  /* close information SDS opened with mcfile_section(detector,"data") */
  if (strstr(mcformat.Name, "NeXus")) {
    mcinfo_header(detector, "footer");
    if (NXclosedata(mcnxHandle) == NX_ERROR)
      fprintf(stderr, "Warning: NeXus: could not close data set %s/information (footer)\n",
        detector.filename);
  }
  /* group remains opened for data to be written */
#endif

  /* case: list of events =================================================== */
  if (strstr(detector.format.Name," list ")) {

#ifdef USE_MPI
    if (mpi_node_rank != mpi_node_root) {
      /* MPI slave: all slaves send their data to master */
      /* m, n, p must be sent too, since all slaves do not have the same number of events */
      int mnp[3]={detector.m,detector.n,detector.p};

      if (mc_MPI_Send(mnp, 3, MPI_INT, mpi_node_root)!= MPI_SUCCESS)
        fprintf(stderr, "Warning: proc %i to master: MPI_Send mnp list error (mcdetector_write_data)\n", mpi_node_rank);
      if (!detector.p1
       || mc_MPI_Send(detector.p1, abs(mnp[0]*mnp[1]*mnp[2]), MPI_DOUBLE, mpi_node_root) != MPI_SUCCESS)
        fprintf(stderr, "Warning: proc %i to master: MPI_Send p1 list error: mnp=%i (mcdetector_write_data)\n", mpi_node_rank, abs(mnp[0]*mnp[1]*mnp[2]));
      /* slaves are done */
      return (detector);
    }
#endif

    /* master node or non-MPI list: store data block */
    int     master_mnp[3]={detector.m,detector.n,detector.p};

#ifdef USE_MPI
    int     node_i=0;
    /* MPI master: receive data from slaves */
    for(node_i=0; node_i<mpi_node_count; node_i++) {
      double *this_p1=NULL;                               /* buffer to hold the list to save */
      int     mnp[3]={detector.m,detector.m,detector.p};  /* size of this buffer */
      if (node_i != mpi_node_root) { /* get data from slaves */
        if (mc_MPI_Recv(mnp, 3, MPI_INT, node_i) != MPI_SUCCESS)
          fprintf(stderr, "Warning: master from proc %i: "
            "MPI_Recv mnp list error (mcdetector_write_data)\n", node_i);
        this_p1 = (double *)calloc(abs(mnp[0]*mnp[1]*mnp[2]), sizeof(double));
        if (!this_p1 || mc_MPI_Recv(this_p1, abs(mnp[0]*mnp[1]*mnp[2]), MPI_DOUBLE, node_i)!= MPI_SUCCESS)
          fprintf(stderr, "Warning: master from proc %i: "
            "MPI_Recv p1 list error: mnp=%i (mcdetector_write_data)\n", node_i, abs(mnp[0]*mnp[1]*mnp[2]));
        detector.p1 = this_p1;
        detector.m  = mnp[0]; detector.n  = mnp[1]; detector.p  = mnp[2];
      } else
#endif
      { /* MASTER/single node use its own detector structure */
        detector.p1 = detector.p1_orig;
        detector.m  = master_mnp[0]; detector.n  = master_mnp[1]; detector.p  = master_mnp[2];
      }

      /* WRITE list data (will be catenated in case of MPI as file is already opened) */
      mcfile_data(detector, "data");

#ifdef USE_MPI
      /* free temporary MPI block used for Recv from slaves */
      if (this_p1 && node_i != mpi_node_root)
        free(this_p1);
      detector.p0 = detector.p0_orig;
      detector.p1 = detector.p1_orig;
      detector.p2 = detector.p2_orig;
      detector.m  = master_mnp[0]; detector.n  = master_mnp[1]; detector.p  = master_mnp[2];

    } /* for node_i: end loop on nodes */
#endif

  } /* end list case */
  else
  {
  /* case: normal detector ================================================== */

    /* WRITE data */
    mcfile_data(detector, "data");

    /* write errors (not for lists) */
    if (detector.p2) mcfile_data(detector, "errors");

    /* write events (not for lists) */
    if (detector.p0) mcfile_data(detector, "events");

    if (detector.rank == 1 && detector.p1 && strstr(detector.format.Name,"McStas")) {
      free(detector.p1);  /* 'this_p1' allocated in mcdetector_write_sim for 1D McStas data sets [x I E N] */
      detector.p0 = detector.p0_orig;
      detector.p1 = detector.p1_orig;
      detector.p2 = detector.p2_orig;
      detector.m = detector.n; detector.n=1; detector.istransposed=0;
    }
  } /* end normal detector case */

  /* WRITE data footer (except when 'no footer') */
  if (!strstr(detector.format.Name, "no footer") && !strstr(mcformat.Name, "NeXus")) {
    /* skip in data-only mode or binary */
    if (!strstr(detector.format.Name, "binary") && !mcascii_only)
      mcinfo_header(detector, "footer");
  }

  /* close data file and free memory */
  if (mcDetectorCustomHeader && strlen(mcDetectorCustomHeader)) {
    free(mcDetectorCustomHeader); mcDetectorCustomHeader=NULL; }

  if (!strstr(mcformat.Name, "NeXus") && detector.file_handle != mcsiminfo_file
   && !mcdisable_output_files && detector.file_handle)
    fclose(detector.file_handle);
  else if (strstr(mcformat.Name, "NeXus")) {
    /* close data set group */
    mcfile_section(detector, "end", detector.component, detector.filename, "data", 4);
  }

  return(detector);
} /* mcdetector_write_data */

/*******************************************************************************
* mcdetector_out_0D: wrapper for 0D (single value).
*******************************************************************************/
MCDETECTOR mcdetector_out_0D(char *t, double p0, double p1, double p2,
                         char *c, Coords posa)
{
  /* import and perform basic detector analysis (and handle MPI reduce except for lists) */
  MCDETECTOR detector = mcdetector_import(mcformat,
    c, (t ? t : "McStas data"),
    1, 1, 1,
    "I", "", "",
    "I", "", "",
    0, 0, 0, 0, 0, 0, "",
    &p0, &p1, &p2, posa); /* write Detector: line */

  /* write detector to simulation file (incl custom header if any) */
  detector = mcdetector_write_sim(detector);
  mcdetector_register(detector);
  return(detector);
}

/*******************************************************************************
* mcdetector_out_1D: wrapper for 1D.
*******************************************************************************/
MCDETECTOR mcdetector_out_1D(char *t, char *xl, char *yl,
        char *xvar, double x1, double x2,
        int n,
        double *p0, double *p1, double *p2, char *f,
        char *c, Coords posa)
{
  /* import and perform basic detector analysis (and handle MPI_Reduce except for lists) */
  MCDETECTOR detector = mcdetector_import(mcformat,
    c, (t ? t : "McStas 1D data"),
    n, 1, 1,
    xl, yl, (n > 1 ? "Signal per bin" : " Signal"),
    xvar, "(I,I_err)", "I",
    x1, x2, 0, 0, 0, 0, f,
    p0, p1, p2, posa); /* write Detector: line */

  /* write detector to simulation and data file (incl custom header if any) */
  detector = mcdetector_write_sim(detector);
  detector = mcdetector_write_data(detector);  /* will also merge lists */
  mcdetector_register(detector);
  return(detector);
}

/*******************************************************************************
* mcdetector_out_2D: wrapper for 2D.
*******************************************************************************/
MCDETECTOR mcdetector_out_2D(char *t, char *xl, char *yl,
                  double x1, double x2, double y1, double y2,
                  int m, int n,
                  double *p0, double *p1, double *p2, char *f,
                  char *c, Coords posa)
{
  char xvar[CHAR_BUF_LENGTH];
  char yvar[CHAR_BUF_LENGTH];

  if (xl && strlen(xl)) { strncpy(xvar, xl, CHAR_BUF_LENGTH); xvar[2]='\0'; }
  else strcpy(xvar, "x");
  if (yl && strlen(yl)) { strncpy(yvar, yl, CHAR_BUF_LENGTH); yvar[2]='\0'; }
  else strcpy(yvar, "y");

  /* is it in fact a 1D call ? */
  if (m == 1)      return(mcdetector_out_1D(
                    t, yl, "I", yvar, y1, y2, n, p0, p1, p2, f, c, posa));
  else if (n == 1) return(mcdetector_out_1D(
                    t, xl, "I", xvar, x1, x2, m, p0, p1, p2, f, c, posa));

  /* import and perform basic detector analysis (and handle MPI_Reduce except for lists) */
  MCDETECTOR detector = mcdetector_import(mcformat,
    c, (t ? t : "McStas 2D data"),
    m, n, 1,
    xl, yl, "Signal per bin",
    xvar, yvar, "I",
    x1, x2, y1, y2, 0, 0, f,
    p0, p1, p2, posa); /* write Detector: line */

  /* write detector to simulation and data file (incl custom header if any) */
  detector = mcdetector_write_sim(detector);
  detector = mcdetector_write_data(detector); /* will also merge lists */
  mcdetector_register(detector);
  return(detector);
}

/*******************************************************************************
* mcdetector_out_3D: wrapper for 3D.
*   exported as a large 2D array, but the 3 dims are given in the header
*******************************************************************************/
MCDETECTOR mcdetector_out_3D(char *t, char *xl, char *yl, char *zl,
      char *xvar, char *yvar, char *zvar,
      double x1, double x2, double y1, double y2, double z1, double z2,
      int m, int n, int p,
      double *p0, double *p1, double *p2, char *f,
      char *c, Coords posa)
{
  /* import and perform basic detector analysis (and handle MPI_Reduce except for lists) */
  MCDETECTOR detector = mcdetector_import(mcformat,
    c, (t ? t : "McStas 3D data"),
    m, n, p,
    xl, yl, zl,
    xvar, yvar, zvar,
    x1, x2, y1, y2, z1, z2, f,
    p0, p1, p2, posa); /* write Detector: line */

  /* write detector to simulation and data file (incl custom header if any) */
  detector = mcdetector_write_sim(detector);
  detector = mcdetector_write_data(detector); /* will also merge lists */
  mcdetector_register(detector);
  return(detector);
}

/*******************************************************************************
* mcuse_format_header: Replaces aliases names in format fields (header part)
*******************************************************************************/
char *mcuse_format_header(char *format_const)
{ /* Header Footer */
  char *format=NULL;

  if (!format_const) return(NULL);
  format = (char *)malloc(strlen(format_const)+1);
  if (!format) exit(fprintf(stderr, "Error: insufficient memory (mcuse_format_header)\n"));
  strcpy(format, format_const);
  str_rep(format, "%PRE", "%1$s"); /* prefix */
  str_rep(format, "%SRC", "%2$s"); /* name of instrument source file */
  str_rep(format, "%FIL", "%3$s"); /* output file name (data) */
  str_rep(format, "%FMT", "%4$s"); /* format name */
  str_rep(format, "%DATL","%8$li");/* Time elapsed since Jan 1st 1970, in seconds */
  str_rep(format, "%DAT", "%5$s"); /* Date as a string */
  str_rep(format, "%USR", "%6$s"); /* User/machine name */
  str_rep(format, "%PAR", "%7$s"); /* Parent name (root/mcstas) valid_parent */
  str_rep(format, "%VPA", "%7$s");
  return(format);
}

/*******************************************************************************
* mcuse_format_tag: Replaces aliases names in format fields (tag part)
*******************************************************************************/
char *mcuse_format_tag(char *format_const)
{ /* AssignTag */
  char *format=NULL;

  if (!format_const) return(NULL);
  format = (char *)malloc(strlen(format_const)+1);
  if (!format) exit(fprintf(stderr, "Error: insufficient memory (mcuse_format_tag)\n"));
  strcpy(format, format_const);
  str_rep(format, "%PRE", "%1$s"); /* prefix */
  str_rep(format, "%SEC", "%2$s"); /* section/parent name valid_parent/section */
  str_rep(format, "%PAR", "%2$s");
  str_rep(format, "%VPA", "%2$s");
  str_rep(format, "%NAM", "%3$s"); /* name of field valid_name */
  str_rep(format, "%VNA", "%3$s");
  str_rep(format, "%VAL", "%4$s"); /* value of field */
  return(format);
}

/*******************************************************************************
* mcuse_format_section: Replaces aliases names in format fields (section part)
*******************************************************************************/
char *mcuse_format_section(char *format_const)
{ /* BeginSection EndSection */
  char *format=NULL;

  if (!format_const) return(NULL);
  format = (char *)malloc(strlen(format_const)+1);
  if (!format) exit(fprintf(stderr, "Error: insufficient memory (mcuse_format_section)\n"));
  strcpy(format, format_const);
  str_rep(format, "%PRE", "%1$s"); /* prefix */
  str_rep(format, "%TYP", "%2$s"); /* type/class of section */
  str_rep(format, "%NAM", "%3$s"); /* name of section */
  str_rep(format, "%SEC", "%3$s");
  str_rep(format, "%VNA", "%4$s"); /* valid name (letters/digits) of section */
  str_rep(format, "%PAR", "%5$s"); /* parent name (simulation) */
  str_rep(format, "%VPA", "%6$s"); /* valid parent name (letters/digits) */
  str_rep(format, "%LVL", "%7$i"); /* level index */
  return(format);
}

/*******************************************************************************
* mcuse_format_data: Replaces aliases names in format fields (data part)
*******************************************************************************/
char *mcuse_format_data(char *format_const)
{ /* BeginData EndData BeginErrors EndErrors BeginNcount EndNcount */
  char *format=NULL;

  if (!format_const) return(NULL);
  format = (char *)malloc(strlen(format_const)+1);
  if (!format) exit(fprintf(stderr, "Error: insufficient memory (mcuse_format_data)\n"));
  strcpy(format, format_const);
  str_rep(format, "%PRE", "%1$s"); /* prefix */
  str_rep(format, "%PAR", "%2$s"); /* parent name (component instance name) valid_parent */
  str_rep(format, "%VPA", "%2$s");
  str_rep(format, "%FIL", "%3$s"); /* output file name (data) */
  str_rep(format, "%XLA", "%4$s"); /* x axis label */
  str_rep(format, "%XVL", "%5$s"); /* x axis valid label (letters/digits) */
  str_rep(format, "%YLA", "%6$s"); /* y axis label */
  str_rep(format, "%YVL", "%7$s"); /* y axis valid label (letters/digits) */
  str_rep(format, "%ZLA", "%8$s"); /* z axis label */
  str_rep(format, "%ZVL", "%9$s"); /* z axis valid label (letters/digits) */
  str_rep(format, "%TITL", "%10$s"); /* data title */
  str_rep(format, "%XVAR", "%11$s"); /* x variables */
  str_rep(format, "%YVAR", "%12$s"); /* y variables */
  str_rep(format, "%ZVAR", "%13$s"); /* z variables */
  str_rep(format, "%MDIM", "%14$i"); /* m dimension of x axis */
  str_rep(format, "%NDIM", "%15$i"); /* n dimension of y axis */
  str_rep(format, "%PDIM", "%16$i"); /* p dimension of z axis */
  str_rep(format, "%XMIN", "%17$g"); /* x min axis value (m bins) */
  str_rep(format, "%XMAX", "%18$g"); /* x max axis value (m bins) */
  str_rep(format, "%YMIN", "%19$g"); /* y min axis value (n bins) */
  str_rep(format, "%YMAX", "%20$g"); /* y max axis value (n bins) */
  str_rep(format, "%ZMIN", "%21$g"); /* z min axis value (usually min of signal, p bins) */
  str_rep(format, "%ZMAX", "%22$g"); /* z max axis value (usually max of signal, p bins) */
  return(format);
}

/*******************************************************************************
* mcuse_format: selects an output format for sim and data files. returns format
*******************************************************************************/
struct mcformats_struct mcuse_format(char *format)
{
  int i,j;
  int i_format=-1;
  char *tmp;
  char low_format[256];
  struct mcformats_struct usedformat;

  usedformat.Name = NULL;
  /* get the format to lower case */
  if (!format) exit(fprintf(stderr, "Error: Invalid NULL format. Exiting (mcuse_format)\n"));
  strcpy(low_format, format);
  for (i=0; i<strlen(low_format); i++) low_format[i]=tolower(format[i]);
  /* handle format aliases */
  if (!strcmp(low_format, "pgplot")) strcpy(low_format, "mcstas");
  if (!strcmp(low_format, "hdf"))    strcpy(low_format, "nexus");
#ifndef USE_NEXUS
  if (!strcmp(low_format, "nexus"))
    fprintf(stderr, "WARNING: to enable NeXus format you must have the NeXus libs installed.\n"
                    "         You should then re-compile with the -DUSE_NEXUS define.\n");
#endif

  tmp = (char *)malloc(256);
  if(!tmp) exit(fprintf(stderr, "Error: insufficient memory (mcuse_format)\n"));

  /* look for a specific format in mcformats.Name table */
  for (i=0; i < mcNUMFORMATS; i++)
  {
    strcpy(tmp, mcformats[i].Name);
    for (j=0; j<strlen(tmp); j++) tmp[j] = tolower(tmp[j]);
    if (strstr(low_format, tmp))  i_format = i;
  }
  if (i_format < 0)
  {
    i_format = 0; /* default format is #0 McStas */
    fprintf(stderr, "Warning: unknown output format '%s'. Using default (%s, mcuse_format).\n", format, mcformats[i_format].Name);
  }

  usedformat = mcformats[i_format];
  strcpy(tmp, usedformat.Name);
  usedformat.Name = tmp;
  if (strstr(low_format,"raw")) strcat(usedformat.Name," raw");
  if (strstr(low_format,"binary"))
  {
    if (strstr(low_format,"double")) strcat(usedformat.Name," binary double data");
    else strcat(usedformat.Name," binary float data");
    mcascii_only = 1;
  }

  /* Replaces vfprintf parameter name aliases */
  /* Header Footer */
  usedformat.Header       = mcuse_format_header(usedformat.Header);
  usedformat.Footer       = mcuse_format_header(usedformat.Footer);
  /* AssignTag */
  usedformat.AssignTag    = mcuse_format_tag(usedformat.AssignTag);
  /* BeginSection EndSection */
  usedformat.BeginSection = mcuse_format_section(usedformat.BeginSection);
  usedformat.EndSection   = mcuse_format_section(usedformat.EndSection);
  /*  BeginData  EndData  BeginErrors  EndErrors  BeginNcount  EndNcount  */
  usedformat.BeginData    = mcuse_format_data(usedformat.BeginData  );
  usedformat.EndData      = mcuse_format_data(usedformat.EndData    );
  usedformat.BeginErrors  = mcuse_format_data(usedformat.BeginErrors);
  usedformat.EndErrors    = mcuse_format_data(usedformat.EndErrors  );
  usedformat.BeginNcount  = mcuse_format_data(usedformat.BeginNcount);
  usedformat.EndNcount    = mcuse_format_data(usedformat.EndNcount  );

  return(usedformat);
} /* mcuse_format */

/*******************************************************************************
* mcclear_format: free format structure
*******************************************************************************/
void mcclear_format(struct mcformats_struct usedformat)
{
/* free format specification strings */
  if (usedformat.Name        ) free(usedformat.Name        );
  else return;
  if (usedformat.Header      ) free(usedformat.Header      );
  if (usedformat.Footer      ) free(usedformat.Footer      );
  if (usedformat.AssignTag   ) free(usedformat.AssignTag   );
  if (usedformat.BeginSection) free(usedformat.BeginSection);
  if (usedformat.EndSection  ) free(usedformat.EndSection  );
  if (usedformat.BeginData   ) free(usedformat.BeginData   );
  if (usedformat.EndData     ) free(usedformat.EndData     );
  if (usedformat.BeginErrors ) free(usedformat.BeginErrors );
  if (usedformat.EndErrors   ) free(usedformat.EndErrors   );
  if (usedformat.BeginNcount ) free(usedformat.BeginNcount );
  if (usedformat.EndNcount   ) free(usedformat.EndNcount   );
} /* mcclear_format */

/*******************************************************************************
* mcuse_file: will save data/sim files
*******************************************************************************/
static void mcuse_file(char *file)
{
  if (file && strcmp(file, "NULL"))
    mcsiminfo_name = file;
  else {
    char *filename=(char*)malloc(CHAR_BUF_LENGTH);
    sprintf(filename, "%s_%li", mcinstrument_name, mcstartdate);
    mcsiminfo_name = filename;
  }
  mcsingle_file  = 1;
}

/*******************************************************************************
* mcset_ncount: set total number of rays to generate
*******************************************************************************/
void mcset_ncount(unsigned long long int count)
{
  mcncount = count;
}

/* mcget_ncount: get total number of rays to generate */
unsigned long long int mcget_ncount(void)
{
  return mcncount;
}

/* mcget_run_num: get curent number of rays in TRACE */
unsigned long long int mcget_run_num(void)
{
  return mcrun_num;
}

/* mcsetn_arg: get ncount from a string argument */
static void
mcsetn_arg(char *arg)
{
  mcset_ncount((long long int) strtod(arg, NULL));
}

/* mcsetseed: set the random generator seed from a string argument */
static void
mcsetseed(char *arg)
{
  mcseed = atol(arg);
  if(mcseed) {
#ifdef USE_MPI
    if (mpi_node_count > 1) srandom(mcseed+mpi_node_rank);
    else
#endif
    srandom(mcseed);
  } else {
    fprintf(stderr, "Error: seed must not be zero (mcsetseed)\n");
    exit(1);
  }
}

/* Following part is only embedded when not redundent with mcstas.h ========= */

#ifndef MCCODE_H

/* SECTION: MCDISPLAY support. =============================================== */

/*******************************************************************************
* Just output MCDISPLAY keywords to be caught by an external plotter client.
*******************************************************************************/

void mcdis_magnify(char *what){
  printf("MCDISPLAY: magnify('%s')\n", what);
}

void mcdis_line(double x1, double y1, double z1,
                double x2, double y2, double z2){
  printf("MCDISPLAY: multiline(2,%g,%g,%g,%g,%g,%g)\n",
         x1,y1,z1,x2,y2,z2);
}

void mcdis_dashed_line(double x1, double y1, double z1,
		       double x2, double y2, double z2, int n){
  int i;
  const double dx = (x2-x1)/(2*n+1);
  const double dy = (y2-y1)/(2*n+1);
  const double dz = (z2-z1)/(2*n+1);

  for(i = 0; i < n+1; i++)
    mcdis_line(x1 + 2*i*dx,     y1 + 2*i*dy,     z1 + 2*i*dz,
	       x1 + (2*i+1)*dx, y1 + (2*i+1)*dy, z1 + (2*i+1)*dz);
}

void mcdis_multiline(int count, ...){
  va_list ap;
  double x,y,z;

  printf("MCDISPLAY: multiline(%d", count);
  va_start(ap, count);
  while(count--)
    {
    x = va_arg(ap, double);
    y = va_arg(ap, double);
    z = va_arg(ap, double);
    printf(",%g,%g,%g", x, y, z);
    }
  va_end(ap);
  printf(")\n");
}

void mcdis_rectangle(char* plane, double x, double y, double z,
		     double width, double height){
  /* draws a rectangle in the plane           */
  /* x is ALWAYS width and y is ALWAYS height */
  if (strcmp("xy", plane)==0) {
    mcdis_multiline(5,
		    x - width/2, y - height/2, z,
		    x + width/2, y - height/2, z,
		    x + width/2, y + height/2, z,
		    x - width/2, y + height/2, z,
		    x - width/2, y - height/2, z);
  } else if (strcmp("xz", plane)==0) {
    mcdis_multiline(5,
		    x - width/2, y, z - height/2,
		    x + width/2, y, z - height/2,
		    x + width/2, y, z + height/2,
		    x - width/2, y, z + height/2,
		    x - width/2, y, z - height/2);
  } else if (strcmp("yz", plane)==0) {
    mcdis_multiline(5,
		    x, y - height/2, z - width/2,
		    x, y - height/2, z + width/2,
		    x, y + height/2, z + width/2,
		    x, y + height/2, z - width/2,
		    x, y - height/2, z - width/2);
  } else {

    fprintf(stderr, "Error: Definition of plane %s unknown\n", plane);
    exit(1);
  }
}

/*  draws a box with center at (x, y, z) and
    width (deltax), height (deltay), length (deltaz) */
void mcdis_box(double x, double y, double z,
	       double width, double height, double length){

  mcdis_rectangle("xy", x, y, z-length/2, width, height);
  mcdis_rectangle("xy", x, y, z+length/2, width, height);
  mcdis_line(x-width/2, y-height/2, z-length/2,
	     x-width/2, y-height/2, z+length/2);
  mcdis_line(x-width/2, y+height/2, z-length/2,
	     x-width/2, y+height/2, z+length/2);
  mcdis_line(x+width/2, y-height/2, z-length/2,
	     x+width/2, y-height/2, z+length/2);
  mcdis_line(x+width/2, y+height/2, z-length/2,
	     x+width/2, y+height/2, z+length/2);
}

void mcdis_circle(char *plane, double x, double y, double z, double r){
  printf("MCDISPLAY: circle('%s',%g,%g,%g,%g)\n", plane, x, y, z, r);
}

/* SECTION: coordinates handling ============================================ */

/*******************************************************************************
* Since we use a lot of geometric calculations using Cartesian coordinates,
* we collect some useful routines here. However, it is also permissible to
* work directly on the underlying struct coords whenever that is most
* convenient (that is, the type Coords is not abstract).
*
* Coordinates are also used to store rotation angles around x/y/z axis.
*
* Since coordinates are used much like a basic type (such as double), the
* structure itself is passed and returned, rather than a pointer.
*
* At compile-time, the values of the coordinates may be unknown (for example
* a motor position). Hence coordinates are general expressions and not simple
* numbers. For this we used the type Coords_exp which has three CExp
* fields. For runtime (or calculations possible at compile time), we use
* Coords which contains three double fields.
*******************************************************************************/

/* coords_set: Assign coordinates. */
Coords
coords_set(MCNUM x, MCNUM y, MCNUM z)
{
  Coords a;

  a.x = x;
  a.y = y;
  a.z = z;
  return a;
}

/* coords_get: get coordinates. Required when 'x','y','z' are #defined as ray pars */
Coords
coords_get(Coords a, MCNUM *x, MCNUM *y, MCNUM *z)
{
  *x = a.x;
  *y = a.y;
  *z = a.z;
  return a;
}

/* coords_add: Add two coordinates. */
Coords
coords_add(Coords a, Coords b)
{
  Coords c;

  c.x = a.x + b.x;
  c.y = a.y + b.y;
  c.z = a.z + b.z;
  if (fabs(c.z) < 1e-14) c.z=0.0;
  return c;
}

/* coords_sub: Subtract two coordinates. */
Coords
coords_sub(Coords a, Coords b)
{
  Coords c;

  c.x = a.x - b.x;
  c.y = a.y - b.y;
  c.z = a.z - b.z;
  if (fabs(c.z) < 1e-14) c.z=0.0;
  return c;
}

/* coords_neg: Negate coordinates. */
Coords
coords_neg(Coords a)
{
  Coords b;

  b.x = -a.x;
  b.y = -a.y;
  b.z = -a.z;
  return b;
}

/* coords_scale: Scale a vector. */
Coords coords_scale(Coords b, double scale) {
  Coords a;

  a.x = b.x*scale;
  a.y = b.y*scale;
  a.z = b.z*scale;
  return a;
}

/* coords_sp: Scalar product: a . b */
double coords_sp(Coords a, Coords b) {
  double value;

  value = a.x*b.x + a.y*b.y + a.z*b.z;
  return value;
}

/* coords_xp: Cross product: a = b x c. */
Coords coords_xp(Coords b, Coords c) {
  Coords a;

  a.x = b.y*c.z - c.y*b.z;
  a.y = b.z*c.x - c.z*b.x;
  a.z = b.x*c.y - c.x*b.y;
  return a;
}

/* coords_mirror: Mirror a in plane (through the origin) defined by normal n*/
Coords coords_mirror(Coords a, Coords n) {
  double t = scalar_prod(n.x, n.y, n.z, n.x, n.y, n.z);
  Coords b;
  if (t!=1) {
    t = sqrt(t);
    n.x /= t;
    n.y /= t;
    n.z /= t;
  }
  t=scalar_prod(a.x, a.y, a.z, n.x, n.y, n.z);
  b.x = a.x-2*t*n.x;
  b.y = a.y-2*t*n.y;
  b.z = a.z-2*t*n.z;
  return b;
}

/* coords_print: Print out vector values. */
void coords_print(Coords a) {

  fprintf(stdout, "(%f, %f, %f)\n", a.x, a.y, a.z);
  return;
}

mcstatic inline void coords_norm(Coords* c) {
	double temp = coords_sp(*c,*c);

	// Skip if we will end dividing by zero
	if (temp == 0) return;

	temp = sqrt(temp);

	c->x /= temp;
	c->y /= temp;
	c->z /= temp;
}

/*******************************************************************************
* The Rotation type implements a rotation transformation of a coordinate
* system in the form of a double[3][3] matrix.
*
* Contrary to the Coords type in coords.c, rotations are passed by
* reference. Functions that yield new rotations do so by writing to an
* explicit result parameter; rotations are not returned from functions. The
* reason for this is that arrays cannot by returned from functions (though
* structures can; thus an alternative would have been to wrap the
* double[3][3] array up in a struct). Such are the ways of C programming.
*
* A rotation represents the tranformation of the coordinates of a vector when
* changing between coordinate systems that are rotated with respect to each
* other. For example, suppose that coordinate system Q is rotated 45 degrees
* around the Z axis with respect to coordinate system P. Let T be the
* rotation transformation representing a 45 degree rotation around Z. Then to
* get the coordinates of a vector r in system Q, apply T to the coordinates
* of r in P. If r=(1,0,0) in P, it will be (sqrt(1/2),-sqrt(1/2),0) in
* Q. Thus we should be careful when interpreting the sign of rotation angles:
* they represent the rotation of the coordinate systems, not of the
* coordinates (which has opposite sign).
*******************************************************************************/

/*******************************************************************************
* rot_set_rotation: Get transformation for rotation first phx around x axis,
* then phy around y, then phz around z.
*******************************************************************************/
void
rot_set_rotation(Rotation t, double phx, double phy, double phz)
{
  if ((phx == 0) && (phy == 0) && (phz == 0)) {
    t[0][0] = 1.0;
    t[0][1] = 0.0;
    t[0][2] = 0.0;
    t[1][0] = 0.0;
    t[1][1] = 1.0;
    t[1][2] = 0.0;
    t[2][0] = 0.0;
    t[2][1] = 0.0;
    t[2][2] = 1.0;
  } else {
    double cx = cos(phx);
    double sx = sin(phx);
    double cy = cos(phy);
    double sy = sin(phy);
    double cz = cos(phz);
    double sz = sin(phz);

    t[0][0] = cy*cz;
    t[0][1] = sx*sy*cz + cx*sz;
    t[0][2] = sx*sz - cx*sy*cz;
    t[1][0] = -cy*sz;
    t[1][1] = cx*cz - sx*sy*sz;
    t[1][2] = sx*cz + cx*sy*sz;
    t[2][0] = sy;
    t[2][1] = -sx*cy;
    t[2][2] = cx*cy;
  }
}

/*******************************************************************************
* rot_test_identity: Test if rotation is identity
*******************************************************************************/
int
rot_test_identity(Rotation t)
{
  return (t[0][0] + t[1][1] + t[2][2] == 3);
}

/*******************************************************************************
* rot_mul: Matrix multiplication of transformations (this corresponds to
* combining transformations). After rot_mul(T1, T2, T3), doing T3 is
* equal to doing first T2, then T1.
* Note that T3 must not alias (use the same array as) T1 or T2.
*******************************************************************************/
void
rot_mul(Rotation t1, Rotation t2, Rotation t3)
{
  if (rot_test_identity(t1)) {
    rot_copy(t3, t2);
  } else if (rot_test_identity(t2)) {
    rot_copy(t3, t1);
  } else {
    int i,j;
    for(i = 0; i < 3; i++)
      for(j = 0; j < 3; j++)
	t3[i][j] = t1[i][0]*t2[0][j] + t1[i][1]*t2[1][j] + t1[i][2]*t2[2][j];
  }
}

/*******************************************************************************
* rot_copy: Copy a rotation transformation (arrays cannot be assigned in C).
*******************************************************************************/
void
rot_copy(Rotation dest, Rotation src)
{
  int i,j;
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++)
      dest[i][j] = src[i][j];
}

/*******************************************************************************
* rot_transpose: Matrix transposition, which is inversion for Rotation matrices
*******************************************************************************/
void
rot_transpose(Rotation src, Rotation dst)
{
  dst[0][0] = src[0][0];
  dst[0][1] = src[1][0];
  dst[0][2] = src[2][0];
  dst[1][0] = src[0][1];
  dst[1][1] = src[1][1];
  dst[1][2] = src[2][1];
  dst[2][0] = src[0][2];
  dst[2][1] = src[1][2];
  dst[2][2] = src[2][2];
}

/*******************************************************************************
* rot_apply: returns t*a
*******************************************************************************/
Coords
rot_apply(Rotation t, Coords a)
{
  Coords b;
  if (rot_test_identity(t)) {
    return a;
  } else {
    b.x = t[0][0]*a.x + t[0][1]*a.y + t[0][2]*a.z;
    b.y = t[1][0]*a.x + t[1][1]*a.y + t[1][2]*a.z;
    b.z = t[2][0]*a.x + t[2][1]*a.y + t[2][2]*a.z;
    return b;
  }
}

/**
 * Pretty-printing of rotation matrices.
 */
void rot_print(Rotation rot) {
	printf("[ %4.2f %4.2f %4.2f ]\n",
			rot[0][0], rot[0][1], rot[0][2]);
	printf("[ %4.2f %4.2f %4.2f ]\n",
			rot[1][0], rot[1][1], rot[1][2]);
	printf("[ %4.2f %4.2f %4.2f ]\n\n",
			rot[2][0], rot[2][1], rot[2][2]);
}

/**
 * Vector product: used by vec_prod (mccode-r.h). Use coords_xp for Coords.
 */
mcstatic inline void vec_prod_func(double *x, double *y, double *z,
		double x1, double y1, double z1,
		double x2, double y2, double z2) {
    *x = (y1)*(z2) - (y2)*(z1);
    *y = (z1)*(x2) - (z2)*(x1);
    *z = (x1)*(y2) - (x2)*(y1);
}

/**
 * Scalar product: use coords_sp for Coords.
 */
mcstatic inline double scalar_prod(
		double x1, double y1, double z1,
		double x2, double y2, double z2) {
	return ((x1 * x2) + (y1 * y2) + (z1 * z2));
}

/*******************************************************************************
* mccoordschange: applies rotation to (x y z) and (vx vy vz) and Spin (sx,sy,sz)
*******************************************************************************/
void
mccoordschange(Coords a, Rotation t, double *x, double *y, double *z,
               double *vx, double *vy, double *vz, double *sx, double *sy, double *sz)
{
  Coords b, c;

  if (x != NULL && y != NULL && z != NULL) {
    b.x = *x;
    b.y = *y;
    b.z = *z;
    c = rot_apply(t, b);
    b = coords_add(c, a);
    *x = b.x;
    *y = b.y;
    *z = b.z;
  }

  if (vx != NULL && vy != NULL && vz != NULL) mccoordschange_polarisation(t, vx, vy, vz);

  if (sx != NULL && sy != NULL && sz != NULL) mccoordschange_polarisation(t, sx, sy, sz);

}

/*******************************************************************************
* mccoordschange_polarisation: applies rotation to vector (sx sy sz)
*******************************************************************************/
void
mccoordschange_polarisation(Rotation t, double *sx, double *sy, double *sz)
{
  Coords b, c;

  b.x = *sx;
  b.y = *sy;
  b.z = *sz;
  c = rot_apply(t, b);
  *sx = c.x;
  *sy = c.y;
  *sz = c.z;
}

/* SECTION: vector math  ==================================================== */

/* normal_vec: Compute normal vector to (x,y,z). */
void normal_vec(double *nx, double *ny, double *nz,
                double x, double y, double z)
{
  double ax = fabs(x);
  double ay = fabs(y);
  double az = fabs(z);
  double l;
  if(x == 0 && y == 0 && z == 0)
  {
    *nx = 0;
    *ny = 0;
    *nz = 0;
    return;
  }
  if(ax < ay)
  {
    if(ax < az)
    {                           /* Use X axis */
      l = sqrt(z*z + y*y);
      *nx = 0;
      *ny = z/l;
      *nz = -y/l;
      return;
    }
  }
  else
  {
    if(ay < az)
    {                           /* Use Y axis */
      l = sqrt(z*z + x*x);
      *nx = z/l;
      *ny = 0;
      *nz = -x/l;
      return;
    }
  }
  /* Use Z axis */
  l = sqrt(y*y + x*x);
  *nx = y/l;
  *ny = -x/l;
  *nz = 0;
} /* normal_vec */

/*******************************************************************************
 * solve_2nd_order: second order equation solve: A*t^2 + B*t + C = 0
 * solve_2nd_order(&t1, NULL, A,B,C)
 *   returns 0 if no solution was found, or set 't1' to the smallest positive
 *   solution.
 * solve_2nd_order(&t1, &t2, A,B,C)
 *   same as with &t2=NULL, but also returns the second solution.
 * EXAMPLE usage for intersection of a trajectory with a plane in gravitation
 * field (gx,gy,gz):
 * The neutron starts at point r=(x,y,z) with velocityv=(vx vy vz). The plane
 * has a normal vector n=(nx,ny,nz) and contains the point W=(wx,wy,wz).
 * The problem consists in solving the 2nd order equation:
 *      1/2.n.g.t^2 + n.v.t + n.(r-W) = 0
 * so that A = 0.5 n.g; B = n.v; C = n.(r-W);
 * Without acceleration, t=-n.(r-W)/n.v
 ******************************************************************************/
int solve_2nd_order(double *t1, double *t2,
                  double A,  double B,  double C)
{
  int ret=0;

  if (!t1) return 0;
  *t1 = 0;
  if (t2) *t2=0;

  if (fabs(A) < 1E-10) /* approximate to linear equation: A ~ 0 */
  {
    if (B) {  *t1 = -C/B; ret=1; if (t2) *t2=*t1; }
    /* else no intersection: A=B=0 ret=0 */
  }
  else
  {
    double D;
    D = B*B - 4*A*C;
    if (D >= 0) /* Delta > 0: two solutions */
    {
      double sD, dt1, dt2;
      sD = sqrt(D);
      dt1 = (-B + sD)/2/A;
      dt2 = (-B - sD)/2/A;
      /* we identify very small values with zero */
      if (fabs(dt1) < 1e-10) dt1=0.0;
      if (fabs(dt2) < 1e-10) dt2=0.0;

      /* now we choose the smallest positive solution */
      if      (dt1<=0.0 && dt2>0.0) ret=2; /* dt2 positive */
      else if (dt2<=0.0 && dt1>0.0) ret=1; /* dt1 positive */
      else if (dt1> 0.0 && dt2>0.0)
      {  if (dt1 < dt2) ret=1; else ret=2; } /* all positive: min(dt1,dt2) */
      /* else two solutions are negative. ret=-1 */
      if (ret==1) { *t1 = dt1;  if (t2) *t2=dt2; }
      else        { *t1 = dt2;  if (t2) *t2=dt1; }
      ret=2;  /* found 2 solutions and t1 is the positive one */
    } /* else Delta <0: no intersection. ret=0 */
  }
  return(ret);
} /* solve_2nd_order */

/*******************************************************************************
 * randvec_target_circle: Choose random direction towards target at (x,y,z)
 * with given radius.
 * If radius is zero, choose random direction in full 4PI, no target.
 ******************************************************************************/
void
randvec_target_circle(double *xo, double *yo, double *zo, double *solid_angle,
               double xi, double yi, double zi, double radius)
{
  double l2, phi, theta, nx, ny, nz, xt, yt, zt, xu, yu, zu;

  if(radius == 0.0)
  {
    /* No target, choose uniformly a direction in full 4PI solid angle. */
    theta = acos (1 - rand0max(2));
    phi = rand0max(2 * PI);
    if(solid_angle)
      *solid_angle = 4*PI;
    nx = 1;
    ny = 0;
    nz = 0;
    yi = sqrt(xi*xi+yi*yi+zi*zi);
    zi = 0;
    xi = 0;
  }
  else
  {
    double costheta0;
    l2 = xi*xi + yi*yi + zi*zi; /* sqr Distance to target. */
    costheta0 = sqrt(l2/(radius*radius+l2));
    if (radius < 0) costheta0 *= -1;
    if(solid_angle)
    {
      /* Compute solid angle of target as seen from origin. */
        *solid_angle = 2*PI*(1 - costheta0);
    }

    /* Now choose point uniformly on circle surface within angle theta0 */
    theta = acos (1 - rand0max(1 - costheta0)); /* radius on circle */
    phi = rand0max(2 * PI); /* rotation on circle at given radius */
    /* Now, to obtain the desired vector rotate (xi,yi,zi) angle theta around a
       perpendicular axis u=i x n and then angle phi around i. */
    if(xi == 0 && zi == 0)
    {
      nx = 1;
      ny = 0;
      nz = 0;
    }
    else
    {
      nx = -zi;
      nz = xi;
      ny = 0;
    }
  }

  /* [xyz]u = [xyz]i x n[xyz] (usually vertical) */
  vec_prod(xu,  yu,  zu, xi, yi, zi,        nx, ny, nz);
  /* [xyz]t = [xyz]i rotated theta around [xyz]u */
  rotate  (xt,  yt,  zt, xi, yi, zi, theta, xu, yu, zu);
  /* [xyz]o = [xyz]t rotated phi around n[xyz] */
  rotate (*xo, *yo, *zo, xt, yt, zt, phi, xi, yi, zi);
} /* randvec_target_circle */

/*******************************************************************************
 * randvec_target_rect_angular: Choose random direction towards target at
 * (xi,yi,zi) with given ANGULAR dimension height x width. height=phi_x,
 * width=phi_y (radians)
 * If height or width is zero, choose random direction in full 4PI, no target.
 *******************************************************************************/
void
randvec_target_rect_angular(double *xo, double *yo, double *zo, double *solid_angle,
               double xi, double yi, double zi, double width, double height, Rotation A)
{
  double theta, phi, nx, ny, nz, xt, yt, zt, xu, yu, zu;
  Coords tmp;
  Rotation Ainverse;

  rot_transpose(A, Ainverse);

  if(height == 0.0 || width == 0.0)
  {
    randvec_target_circle(xo, yo, zo, solid_angle,
               xi, yi, zi, 0);
    return;
  }
  else
  {
    if(solid_angle)
    {
      /* Compute solid angle of target as seen from origin. */
      *solid_angle = 2*fabs(width*sin(height/2));
    }

    /* Go to global coordinate system */

    tmp = coords_set(xi, yi, zi);
    tmp = rot_apply(Ainverse, tmp);
    coords_get(tmp, &xi, &yi, &zi);

    /* Now choose point uniformly on quadrant within angle theta0/phi0 */
    theta = width*randpm1()/2.0;
    phi   = height*randpm1()/2.0;
    /* Now, to obtain the desired vector rotate (xi,yi,zi) angle phi around
       n, and then theta around u. */
    if(xi == 0 && zi == 0)
    {
      nx = 1;
      ny = 0;
      nz = 0;
    }
    else
    {
      nx = -zi;
      nz = xi;
      ny = 0;
    }
  }

  /* [xyz]u = [xyz]i x n[xyz] (usually vertical) */
  vec_prod(xu,  yu,  zu, xi, yi, zi,        nx, ny, nz);
  /* [xyz]t = [xyz]i rotated theta around [xyz]u */
  rotate  (xt,  yt,  zt, xi, yi, zi, phi, nx, ny, nz);
  /* [xyz]o = [xyz]t rotated phi around n[xyz] */
  rotate (*xo, *yo, *zo, xt, yt, zt, theta, xu,  yu,  zu);

  /* Go back to local coordinate system */
  tmp = coords_set(*xo, *yo, *zo);
  tmp = rot_apply(A, tmp);
  coords_get(tmp, &*xo, &*yo, &*zo);

} /* randvec_target_rect_angular */

/*******************************************************************************
 * randvec_target_rect_real: Choose random direction towards target at (xi,yi,zi)
 * with given dimension height x width (in meters !).
 *
 * Local emission coordinate is taken into account and corrected for 'order' times.
 * (See remarks posted to mcstas-users by George Apostolopoulus <gapost@ipta.demokritos.gr>)
 *
 * If height or width is zero, choose random direction in full 4PI, no target.
 *
 * Traditionally, this routine had the name randvec_target_rect - this is now a
 * a define (see mcstas-r.h) pointing here. If you use the old rouine, you are NOT
 * taking the local emmission coordinate into account.
*******************************************************************************/

void
randvec_target_rect_real(double *xo, double *yo, double *zo, double *solid_angle,
               double xi, double yi, double zi,
               double width, double height, Rotation A,
               double lx, double ly, double lz, int order)
{
  double dx, dy, dist, dist_p, nx, ny, nz, mx, my, mz, n_norm, m_norm;
  double cos_theta;
  Coords tmp;
  Rotation Ainverse;

  rot_transpose(A, Ainverse);

  if(height == 0.0 || width == 0.0)
  {
    randvec_target_circle(xo, yo, zo, solid_angle,
               xi, yi, zi, 0);
    return;
  }
  else
  {

    /* Now choose point uniformly on rectangle within width x height */
    dx = width*randpm1()/2.0;
    dy = height*randpm1()/2.0;

    /* Determine distance to target plane*/
    dist = sqrt(xi*xi + yi*yi + zi*zi);
    /* Go to global coordinate system */

    tmp = coords_set(xi, yi, zi);
    tmp = rot_apply(Ainverse, tmp);
    coords_get(tmp, &xi, &yi, &zi);

    /* Determine vector normal to trajectory axis (z) and gravity [0 1 0] */
    vec_prod(nx, ny, nz, xi, yi, zi, 0, 1, 0);

    /* This now defines the x-axis, normalize: */
    n_norm=sqrt(nx*nx + ny*ny + nz*nz);
    nx = nx/n_norm;
    ny = ny/n_norm;
    nz = nz/n_norm;

    /* Now, determine our y-axis (vertical in many cases...) */
    vec_prod(mx, my, mz, xi, yi, zi, nx, ny, nz);
    m_norm=sqrt(mx*mx + my*my + mz*mz);
    mx = mx/m_norm;
    my = my/m_norm;
    mz = mz/m_norm;

    /* Our output, random vector can now be defined by linear combination: */

    *xo = xi + dx * nx + dy * mx;
    *yo = yi + dx * ny + dy * my;
    *zo = zi + dx * nz + dy * mz;

    /* Go back to local coordinate system */
    tmp = coords_set(*xo, *yo, *zo);
    tmp = rot_apply(A, tmp);
    coords_get(tmp, &*xo, &*yo, &*zo);

    /* Go back to local coordinate system */
    tmp = coords_set(xi, yi, zi);
    tmp = rot_apply(A, tmp);
    coords_get(tmp, &xi, &yi, &zi);

    if (solid_angle) {
      /* Calculate vector from local point to remote random point */
      lx = *xo - lx;
      ly = *yo - ly;
      lz = *zo - lz;
      dist_p = sqrt(lx*lx + ly*ly + lz*lz);

      /* Adjust the 'solid angle' */
      /* 1/r^2 to the chosen point times cos(\theta) between the normal */
      /* vector of the target rectangle and direction vector of the chosen point. */
      cos_theta = (xi * lx + yi * ly + zi * lz) / (dist * dist_p);
      *solid_angle = width * height / (dist_p * dist_p);
      int counter;
      for (counter = 0; counter < order; counter++) {
	*solid_angle = *solid_angle * cos_theta;
      }
    }
  }
} /* randvec_target_rect_real */

/* SECTION: random numbers ================================================== */

/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/*
 * This is derived from the Berkeley source:
 *        @(#)random.c        5.5 (Berkeley) 7/6/88
 * It was reworked for the GNU C Library by Roland McGrath.
 * Rewritten to use reentrant functions by Ulrich Drepper, 1995.
 */

/*******************************************************************************
* Modified for McStas from glibc 2.0.7pre1 stdlib/random.c and
* stdlib/random_r.c.
*
* This way random() is more than four times faster compared to calling
* standard glibc random() on ix86 Linux, probably due to multithread support,
* ELF shared library overhead, etc. It also makes McStas generated
* simulations more portable (more likely to behave identically across
* platforms, important for parrallel computations).
*******************************************************************************/


#define        TYPE_3                3
#define        BREAK_3                128
#define        DEG_3                31
#define        SEP_3                3

static mc_int32_t randtbl[DEG_3 + 1] =
  {
    TYPE_3,

    -1726662223, 379960547, 1735697613, 1040273694, 1313901226,
    1627687941, -179304937, -2073333483, 1780058412, -1989503057,
    -615974602, 344556628, 939512070, -1249116260, 1507946756,
    -812545463, 154635395, 1388815473, -1926676823, 525320961,
    -1009028674, 968117788, -123449607, 1284210865, 435012392,
    -2017506339, -911064859, -370259173, 1132637927, 1398500161,
    -205601318,
  };

static mc_int32_t *fptr = &randtbl[SEP_3 + 1];
static mc_int32_t *rptr = &randtbl[1];
static mc_int32_t *state = &randtbl[1];
#define rand_deg DEG_3
#define rand_sep SEP_3
static mc_int32_t *end_ptr = &randtbl[sizeof (randtbl) / sizeof (randtbl[0])];

mc_int32_t
mc_random (void)
{
  mc_int32_t result;

  *fptr += *rptr;
  /* Chucking least random bit.  */
  result = (*fptr >> 1) & 0x7fffffff;
  ++fptr;
  if (fptr >= end_ptr)
  {
    fptr = state;
    ++rptr;
  }
  else
  {
    ++rptr;
    if (rptr >= end_ptr)
      rptr = state;
  }
  return result;
}

void
mc_srandom (unsigned int x)
{
  /* We must make sure the seed is not 0.  Take arbitrarily 1 in this case.  */
  state[0] = x ? x : 1;
  {
    long int i;
    for (i = 1; i < rand_deg; ++i)
    {
      /* This does:
         state[i] = (16807 * state[i - 1]) % 2147483647;
         but avoids overflowing 31 bits.  */
      long int hi = state[i - 1] / 127773;
      long int lo = state[i - 1] % 127773;
      long int test = 16807 * lo - 2836 * hi;
      state[i] = test + (test < 0 ? 2147483647 : 0);
    }
    fptr = &state[rand_sep];
    rptr = &state[0];
    for (i = 0; i < 10 * rand_deg; ++i)
      random ();
  }
}

/* "Mersenne Twister", by Makoto Matsumoto and Takuji Nishimura. */
/* See http://www.math.keio.ac.jp/~matumoto/emt.html for original source. */


/*
   A C-program for MT19937, with initialization improved 2002/1/26.
   Coded by Takuji Nishimura and Makoto Matsumoto.

   Before using, initialize the state by using mt_srandom(seed)
   or init_by_array(init_key, key_length).

   Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

     1. Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.

     2. Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.

     3. The names of its contributors may not be used to endorse or promote
        products derived from this software without specific prior written
        permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


   Any feedback is very welcome.
   http://www.math.keio.ac.jp/matumoto/emt.html
   email: matumoto@math.keio.ac.jp
*/

#include <stdio.h>

/* Period parameters */
#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */

static unsigned long mt[N]; /* the array for the state vector  */
static int mti=N+1; /* mti==N+1 means mt[N] is not initialized */

/* initializes mt[N] with a seed */
void mt_srandom(unsigned long s)
{
    mt[0]= s & 0xffffffffUL;
    for (mti=1; mti<N; mti++) {
        mt[mti] =
            (1812433253UL * (mt[mti-1] ^ (mt[mti-1] >> 30)) + mti);
        /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
        /* In the previous versions, MSBs of the seed affect   */
        /* only MSBs of the array mt[].                        */
        /* 2002/01/09 modified by Makoto Matsumoto             */
        mt[mti] &= 0xffffffffUL;
        /* for >32 bit machines */
    }
}

/* initialize by an array with array-length */
/* init_key is the array for initializing keys */
/* key_length is its length */
void init_by_array(init_key, key_length)
unsigned long init_key[], key_length;
{
    int i, j, k;
    mt_srandom(19650218UL);
    i=1; j=0;
    k = (N>key_length ? N : key_length);
    for (; k; k--) {
        mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1664525UL))
          + init_key[j] + j; /* non linear */
        mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++; j++;
        if (i>=N) { mt[0] = mt[N-1]; i=1; }
        if (j>=key_length) j=0;
    }
    for (k=N-1; k; k--) {
        mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1566083941UL))
          - i; /* non linear */
        mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++;
        if (i>=N) { mt[0] = mt[N-1]; i=1; }
    }

    mt[0] = 0x80000000UL; /* MSB is 1; assuring non-zero initial array */
}

/* generates a random number on [0,0xffffffff]-interval */
unsigned long mt_random(void)
{
    unsigned long y;
    static unsigned long mag01[2]={0x0UL, MATRIX_A};
    /* mag01[x] = x * MATRIX_A  for x=0,1 */

    if (mti >= N) { /* generate N words at one time */
        int kk;

        if (mti == N+1)   /* if mt_srandom() has not been called, */
            mt_srandom(5489UL); /* a default initial seed is used */

        for (kk=0;kk<N-M;kk++) {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+M] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        for (;kk<N-1;kk++) {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+(M-N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        y = (mt[N-1]&UPPER_MASK)|(mt[0]&LOWER_MASK);
        mt[N-1] = mt[M-1] ^ (y >> 1) ^ mag01[y & 0x1UL];

        mti = 0;
    }

    y = mt[mti++];

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return y;
}

#undef N
#undef M
#undef MATRIX_A
#undef UPPER_MASK
#undef LOWER_MASK

/* End of "Mersenne Twister". */

/* End of McStas random number routine. */

/* randnorm: generate a random number from normal law */
double
randnorm(void)
{
  static double v1, v2, s;
  static int phase = 0;
  double X, u1, u2;

  if(phase == 0)
  {
    do
    {
      u1 = rand01();
      u2 = rand01();
      v1 = 2*u1 - 1;
      v2 = 2*u2 - 1;
      s = v1*v1 + v2*v2;
    } while(s >= 1 || s == 0);

    X = v1*sqrt(-2*log(s)/s);
  }
  else
  {
    X = v2*sqrt(-2*log(s)/s);
  }

  phase = 1 - phase;
  return X;
}

/**
 * Generate a random number from -1 to 1 with triangle distribution
 */
double randtriangle(void) {
	double randnum = rand01();
	if (randnum>0.5) return(1-sqrt(2*(randnum-0.5)));
	else return(sqrt(2*randnum)-1);
}

/**
 * Random number between 0.0 and 1.0 (including?)
 */
double rand01() {
	double rand;
	rand = (double) random();
	rand /= (double) MC_RAND_MAX + 1;
	return rand;
}

/**
 * Return a random number between 1 and -1
 */
double randpm1() {
	double rand;
	rand = (double) random();
	rand /= ((double) MC_RAND_MAX + 1) / 2;
	rand -= 1;
	return rand;
}

/**
 * Return a random number between 0 and max.
 */
double rand0max(double max) {
	double rand;
	rand = (double) random();
	rand /= ((double) MC_RAND_MAX + 1) / max;
	return rand;
}

/**
 * Return a random number between min and max.
 */
double randminmax(double min, double max) {
	return rand0max(max - min) + max;
}

/* SECTION: main and signal handlers ======================================== */

/*******************************************************************************
* mchelp: displays instrument executable help with possible options
*******************************************************************************/
static void
mchelp(char *pgmname)
{
  int i;

  fprintf(stderr, "%s (%s) instrument simulation, generated with " MCCODE_STRING " (" MCCODE_DATE ")\n", mcinstrument_name, mcinstrument_source);
  fprintf(stderr, "Usage: %s [options] [parm=value ...]\n", pgmname);
  fprintf(stderr,
"Options are:\n"
"  -s SEED   --seed=SEED      Set random seed (must be != 0)\n"
"  -n COUNT  --ncount=COUNT   Set number of @MCCODE_PARTICULE@s to simulate.\n"
"  -d DIR    --dir=DIR        Put all data files in directory DIR.\n"
"  -f FILE   --file=FILE      Put all data in a single file.\n"
"  -t        --trace          Enable trace of @MCCODE_PARTICULE@s through instrument.\n"
"  -g        --gravitation    Enable gravitation for all trajectories.\n"
"  -a        --data-only      Do not put any headers in the data files.\n"
"  --no-output-files          Do not write any data files.\n"
"  -h        --help           Show this help message.\n"
"  -i        --info           Detailed instrument information.\n"
"  --format=FORMAT            Output data files using format FORMAT\n"
"                             (use option +a to include text header in files\n"
#ifdef USE_MPI
"This instrument has been compiled with MPI support. Use 'mpirun'.\n"
#endif
"\n"
);
  if(mcnumipar > 0)
  {
    fprintf(stderr, "Instrument parameters are:\n");
    for(i = 0; i < mcnumipar; i++)
      if (mcinputtable[i].val && strlen(mcinputtable[i].val))
        fprintf(stderr, "  %-16s(%s) [default='%s']\n", mcinputtable[i].name,
        (*mcinputtypes[mcinputtable[i].type].parminfo)(mcinputtable[i].name),
        mcinputtable[i].val);
      else
        fprintf(stderr, "  %-16s(%s)\n", mcinputtable[i].name,
        (*mcinputtypes[mcinputtable[i].type].parminfo)(mcinputtable[i].name));
  }
  fprintf(stderr, "Available output formats are (default is %s):\n  ", mcformat.Name);
  for (i=0; i < mcNUMFORMATS; fprintf(stderr,"\"%s\" " , mcformats[i++].Name) );
  fprintf(stderr, "\n  Format modifiers: FORMAT may be followed by 'binary float' or \n");
  fprintf(stderr, "  'binary double' to save data blocks as binary. This removes text headers.\n");
  fprintf(stderr, "  The " FLAVOR_UPPER "_FORMAT environment variable may set the default FORMAT to use.\n");
#ifndef NOSIGNALS
  fprintf(stderr, "Known signals are: "
#ifdef SIGUSR1
  "USR1 (status) "
#endif
#ifdef SIGUSR2
  "USR2 (save) "
#endif
#ifdef SIGBREAK
  "BREAK (save) "
#endif
#ifdef SIGTERM
  "TERM (save and exit)"
#endif
  "\n");
#endif /* !NOSIGNALS */
} /* mchelp */


/* mcshowhelp: show help and exit with 0 */
static void
mcshowhelp(char *pgmname)
{
  mchelp(pgmname);
  exit(0);
}

/* mcusage: display usage when error in input arguments and exit with 1 */
static void
mcusage(char *pgmname)
{
  fprintf(stderr, "Error: incorrect command line arguments\n");
  mchelp(pgmname);
  exit(1);
}

/* mcenabletrace: enable trace/mcdisplay or error if requires recompile */
static void
mcenabletrace(void)
{
 if(mctraceenabled)
  mcdotrace = 1;
 else
 {
   fprintf(stderr,
           "Error: trace not enabled (mcenabletrace)\n"
           "Please re-run the McStas compiler "
                   "with the --trace option, or rerun the\n"
           "C compiler with the MC_TRACE_ENABLED macro defined.\n");
   exit(1);
 }
}

/*******************************************************************************
 * mcuse_dir: set data/sim storage directory and create it,
 * or exit with error if exists
 ******************************************************************************/
static void
mcuse_dir(char *dir)
{
  if (!dir || !strlen(dir)) return;
#ifdef MC_PORTABLE
  fprintf(stderr, "Error: "
          "Directory output cannot be used with portable simulation (mcuse_dir)\n");
  exit(1);
#else  /* !MC_PORTABLE */
#ifdef USE_MPI
  if(mpi_node_rank == mpi_node_root)
  {
#endif
    if(mkdir(dir, 0777)) {
#ifndef DANSE
      fprintf(stderr, "Error: unable to create directory '%s' (mcuse_dir)\n", dir);
      fprintf(stderr, "(Maybe the directory already exists?)\n");
      exit(1);
#endif
    }
#ifdef USE_MPI
  }
#endif
  /* handle file://directory URL type */
  if (strncmp(dir, "file:/", strlen("file:/")))
    mcdirname = dir;
  else
    mcdirname = dir+strlen("file:/");

  /* remove trailing PATHSEP (if any) */
  while (strlen(mcdirname) && mcdirname[strlen(mcdirname) - 1] == MC_PATHSEP_C)
    mcdirname[strlen(mcdirname) - 1]='\0';
#endif /* !MC_PORTABLE */
} /* mcuse_dir */

/*******************************************************************************
* mcinfo: display instrument simulation info to stdout and exit
*******************************************************************************/
static void
mcinfo(void)
{
  if(strstr(mcformat.Name,"NeXus"))
    exit(fprintf(stderr,"Error: Can not display instrument information in NeXus binary format\n"));
  mcsiminfo_init(stdout);
  mcsiminfo_close();
  exit(0); /* includes MPI_Finalize in MPI mode */
} /* mcinfo */

/*******************************************************************************
* mcreadparams: request parameters from the prompt (or use default)
*******************************************************************************/
void
mcreadparams(void)
{
  int i,j,status;
  static char buf[CHAR_BUF_LENGTH];
  char *p;
  int len;

  MPI_MASTER(printf("Instrument parameters for %s (%s)\n",
                    mcinstrument_name, mcinstrument_source));

  for(i = 0; mcinputtable[i].name != 0; i++)
  {
    do
    {
      MPI_MASTER(
                 if (mcinputtable[i].val && strlen(mcinputtable[i].val))
                   printf("Set value of instrument parameter %s (%s) [default='%s']:\n",
                          mcinputtable[i].name,
                          (*mcinputtypes[mcinputtable[i].type].parminfo)
                          (mcinputtable[i].name), mcinputtable[i].val);
                 else
                   printf("Set value of instrument parameter %s (%s):\n",
                          mcinputtable[i].name,
                          (*mcinputtypes[mcinputtable[i].type].parminfo)
                          (mcinputtable[i].name));
                 fflush(stdout);
                 );
#ifdef USE_MPI
      if(mpi_node_rank == mpi_node_root)
        {
          p = fgets(buf, CHAR_BUF_LENGTH, stdin);
          if(p == NULL)
            {
              fprintf(stderr, "Error: empty input for paramater %s (mcreadparams)\n", mcinputtable[i].name);
              exit(1);
            }
        }
      else
        p = buf;
      MPI_Bcast(buf, CHAR_BUF_LENGTH, MPI_CHAR, mpi_node_root, MPI_COMM_WORLD);
#else /* !USE_MPI */
      p = fgets(buf, CHAR_BUF_LENGTH, stdin);
      if(p == NULL)
        {
          fprintf(stderr, "Error: empty input for paramater %s (mcreadparams)\n", mcinputtable[i].name);
          exit(1);
        }
#endif /* USE_MPI */
      len = strlen(buf);
      if (!len || (len == 1 && (buf[0] == '\n' || buf[0] == '\r')))
      {
        if (mcinputtable[i].val && strlen(mcinputtable[i].val)) {
          strncpy(buf, mcinputtable[i].val, CHAR_BUF_LENGTH);  /* use default value */
          len = strlen(buf);
        }
      }
      for(j = 0; j < 2; j++)
      {
        if(len > 0 && (buf[len - 1] == '\n' || buf[len - 1] == '\r'))
        {
          len--;
          buf[len] = '\0';
        }
      }

      status = (*mcinputtypes[mcinputtable[i].type].getparm)
                   (buf, mcinputtable[i].par);
      if(!status)
      {
        (*mcinputtypes[mcinputtable[i].type].error)(mcinputtable[i].name, buf);
        if (!mcinputtable[i].val || strlen(mcinputtable[i].val)) {
          fprintf(stderr, "       Change %s default value in instrument definition.\n", mcinputtable[i].name);
          exit(1);
        }
      }
    } while(!status);
  }
} /* mcreadparams */

/*******************************************************************************
* mcparseoptions: parse command line arguments (options, parameters)
*******************************************************************************/
void
mcparseoptions(int argc, char *argv[])
{
  int i, j;
  char *p;
  int paramset = 0, *paramsetarray;
  char *usedir=NULL;

  /* Add one to mcnumipar to avoid allocating zero size memory block. */
  paramsetarray = malloc((mcnumipar + 1)*sizeof(*paramsetarray));
  if(paramsetarray == NULL)
  {
    fprintf(stderr, "Error: insufficient memory (mcparseoptions)\n");
    exit(1);
  }
  for(j = 0; j < mcnumipar; j++)
    {
      paramsetarray[j] = 0;
      if (mcinputtable[j].val != NULL && strlen(mcinputtable[j].val))
      {
        int  status;
        char buf[CHAR_BUF_LENGTH];
        strncpy(buf, mcinputtable[j].val, CHAR_BUF_LENGTH);
        status = (*mcinputtypes[mcinputtable[j].type].getparm)
                   (buf, mcinputtable[j].par);
        if(!status) fprintf(stderr, "Invalid '%s' default value %s in instrument definition (mcparseoptions)\n", mcinputtable[j].name, buf);
        else paramsetarray[j] = 1;
      } else {
        (*mcinputtypes[mcinputtable[j].type].getparm)
          (NULL, mcinputtable[j].par);
        paramsetarray[j] = 0;
      }
    }
  for(i = 1; i < argc; i++)
  {
    if(!strcmp("-s", argv[i]) && (i + 1) < argc)
      mcsetseed(argv[++i]);
    else if(!strncmp("-s", argv[i], 2))
      mcsetseed(&argv[i][2]);
    else if(!strcmp("--seed", argv[i]) && (i + 1) < argc)
      mcsetseed(argv[++i]);
    else if(!strncmp("--seed=", argv[i], 7))
      mcsetseed(&argv[i][7]);
    else if(!strcmp("-n", argv[i]) && (i + 1) < argc)
      mcsetn_arg(argv[++i]);
    else if(!strncmp("-n", argv[i], 2))
      mcsetn_arg(&argv[i][2]);
    else if(!strcmp("--ncount", argv[i]) && (i + 1) < argc)
      mcsetn_arg(argv[++i]);
    else if(!strncmp("--ncount=", argv[i], 9))
      mcsetn_arg(&argv[i][9]);
    else if(!strcmp("-d", argv[i]) && (i + 1) < argc)
      usedir=argv[++i];  /* will create directory after parsing all arguments (end of this function) */
    else if(!strncmp("-d", argv[i], 2))
      usedir=&argv[i][2];
    else if(!strcmp("--dir", argv[i]) && (i + 1) < argc)
      usedir=argv[++i];
    else if(!strncmp("--dir=", argv[i], 6))
      usedir=&argv[i][6];
    else if(!strcmp("-f", argv[i]) && (i + 1) < argc)
      mcuse_file(argv[++i]);
    else if(!strncmp("-f", argv[i], 2))
      mcuse_file(&argv[i][2]);
    else if(!strcmp("--file", argv[i]) && (i + 1) < argc)
      mcuse_file(argv[++i]);
    else if(!strncmp("--file=", argv[i], 7))
      mcuse_file(&argv[i][7]);
    else if(!strcmp("-h", argv[i]))
      mcshowhelp(argv[0]);
    else if(!strcmp("--help", argv[i]))
      mcshowhelp(argv[0]);
    else if(!strcmp("-i", argv[i])) {
      mcformat=mcuse_format(MCSTAS_FORMAT);
      mcinfo();
    }
    else if(!strcmp("--info", argv[i]))
      mcinfo();
    else if(!strcmp("-t", argv[i]))
      mcenabletrace();
    else if(!strcmp("--trace", argv[i]))
      mcenabletrace();
    else if(!strcmp("-a", argv[i]))
      mcascii_only = 1;
    else if(!strcmp("+a", argv[i]))
      mcascii_only = 0;
    else if(!strcmp("--data-only", argv[i]))
      mcascii_only = 1;
    else if(!strcmp("--gravitation", argv[i]))
      mcgravitation = 1;
    else if(!strcmp("-g", argv[i]))
      mcgravitation = 1;
    else if(!strncmp("--format=", argv[i], 9)) {
      mcascii_only = 0;
      mcformat=mcuse_format(&argv[i][9]);
    }
    else if(!strcmp("--format", argv[i]) && (i + 1) < argc) {
      mcascii_only = 0;
      mcformat=mcuse_format(argv[++i]);
    }
    else if(!strncmp("--format_data=", argv[i], 14) || !strncmp("--format-data=", argv[i], 14)) {
      mcascii_only = 0;
      mcformat_data=mcuse_format(&argv[i][14]);
    }
    else if((!strcmp("--format_data", argv[i]) || !strcmp("--format-data", argv[i])) && (i + 1) < argc) {
      mcascii_only = 0;
      mcformat_data=mcuse_format(argv[++i]);
    }
    else if(!strcmp("--no-output-files", argv[i]))
      mcdisable_output_files = 1;
    else if(argv[i][0] != '-' && (p = strchr(argv[i], '=')) != NULL)
    {
      *p++ = '\0';

      for(j = 0; j < mcnumipar; j++)
        if(!strcmp(mcinputtable[j].name, argv[i]))
        {
          int status;
          status = (*mcinputtypes[mcinputtable[j].type].getparm)(p,
                        mcinputtable[j].par);
          if(!status || !strlen(p))
          {
            (*mcinputtypes[mcinputtable[j].type].error)
              (mcinputtable[j].name, p);
            exit(1);
          }
          paramsetarray[j] = 1;
          paramset = 1;
          break;
        }
      if(j == mcnumipar)
      {                                /* Unrecognized parameter name */
        fprintf(stderr, "Error: unrecognized parameter %s (mcparseoptions)\n", argv[i]);
        exit(1);
      }
    }
    else if(argv[i][0] == '-') {
      fprintf(stderr, "Error: unrecognized option argument %s (mcparseoptions). Ignored.\n", argv[i++]);
    }
    else {
      fprintf(stderr, "Error: unrecognized argument %s (mcparseoptions). Aborting.\n", argv[i]);
      mcusage(argv[0]);
    }
  }
  if (!mcascii_only) {
    if (strstr(mcformat.Name,"binary")) fprintf(stderr, "Warning: %s files will contain text headers.\n         Use -a option to clean up.\n", mcformat.Name);
    strcat(mcformat.Name, " with text headers");
  }
  if(!paramset)
    mcreadparams();                /* Prompt for parameters if not specified. */
  else
  {
    for(j = 0; j < mcnumipar; j++)
      if(!paramsetarray[j])
      {
        fprintf(stderr, "Error: Instrument parameter %s left unset (mcparseoptions)\n",
                mcinputtable[j].name);
        exit(1);
      }
  }
  free(paramsetarray);
#ifdef USE_MPI
  if (mcdotrace) mpi_node_count=1; /* disable threading when in trace mode */
#endif
  if (usedir && strlen(usedir)) mcuse_dir(usedir);
} /* mcparseoptions */

#ifndef NOSIGNALS
mcstatic char  mcsig_message[256];


/*******************************************************************************
* sighandler: signal handler that makes simulation stop, and save results
*******************************************************************************/
void sighandler(int sig)
{
  /* MOD: E. Farhi, Sep 20th 2001: give more info */
  time_t t1, t0;
#define SIG_SAVE 0
#define SIG_TERM 1
#define SIG_STAT 2
#define SIG_ABRT 3

  printf("\n# McStas: [pid %i] Signal %i detected", getpid(), sig);
#ifdef USE_MPI
  printf(" [proc %i]", mpi_node_rank);
#endif
#if defined(SIGUSR1) && defined(SIGUSR2) && defined(SIGKILL)
  if (!strcmp(mcsig_message, "sighandler") && (sig != SIGUSR1) && (sig != SIGUSR2))
  {
    printf("\n# Fatal : unrecoverable loop ! Suicide (naughty boy).\n");
    kill(0, SIGKILL); /* kill myself if error occurs within sighandler: loops */
  }
#endif
  switch (sig) {
#ifdef SIGINT
    case SIGINT : printf(" SIGINT (interrupt from terminal, Ctrl-C)"); sig = SIG_TERM; break;
#endif
#ifdef SIGILL
    case SIGILL  : printf(" SIGILL (Illegal instruction)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGFPE
    case SIGFPE  : printf(" SIGFPE (Math Error)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGSEGV
    case SIGSEGV : printf(" SIGSEGV (Mem Error)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGTERM
    case SIGTERM : printf(" SIGTERM (Termination)"); sig = SIG_TERM; break;
#endif
#ifdef SIGABRT
    case SIGABRT : printf(" SIGABRT (Abort)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGQUIT
    case SIGQUIT : printf(" SIGQUIT (Quit from terminal)"); sig = SIG_TERM; break;
#endif
#ifdef SIGTRAP
    case SIGTRAP : printf(" SIGTRAP (Trace trap)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGPIPE
    case SIGPIPE : printf(" SIGPIPE (Broken pipe)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGUSR1
    case SIGUSR1 : printf(" SIGUSR1 (Display info)"); sig = SIG_STAT; break;
#endif
#ifdef SIGUSR2
    case SIGUSR2 : printf(" SIGUSR2 (Save simulation)"); sig = SIG_SAVE; break;
#endif
#ifdef SIGHUP
    case SIGHUP  : printf(" SIGHUP (Hangup/update)"); sig = SIG_SAVE; break;
#endif
#ifdef SIGBUS
    case SIGBUS  : printf(" SIGBUS (Bus error)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGURG
    case SIGURG  : printf(" SIGURG (Urgent socket condition)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGBREAK
    case SIGBREAK: printf(" SIGBREAK (Break signal, Ctrl-Break)"); sig = SIG_SAVE; break;
#endif
    default : printf(" (look at signal list for signification)"); sig = SIG_ABRT; break;
  }
  printf("\n");
  printf("# Simulation: %s (%s) \n", mcinstrument_name, mcinstrument_source);
  printf("# Breakpoint: %s ", mcsig_message);
  if (strstr(mcsig_message, "Save") && (sig == SIG_SAVE))
    sig = SIG_STAT;
  SIG_MESSAGE("sighandler");
  if (mcget_ncount() == 0)
    printf("(0 %%)\n" );
  else
  {
    printf("%.2f %% (%10.1f/%10.1f)\n", 100.0*mcget_run_num()/mcget_ncount(), 1.0*mcget_run_num(), 1.0*mcget_ncount());
  }
  t0 = (time_t)mcstartdate;
  t1 = time(NULL);
  printf("# Date:      %s", ctime(&t1));
  printf("# Started:   %s", ctime(&t0));

  if (sig == SIG_STAT)
  {
    printf("# McStas: Resuming simulation (continue)\n");
    fflush(stdout);
    return;
  }
  else
  if (sig == SIG_SAVE)
  {
    printf("# McStas: Saving data and resume simulation (continue)\n");
    mcsave(NULL);
    fflush(stdout);
    return;
  }
  else
  if (sig == SIG_TERM)
  {
    printf("# McStas: Finishing simulation (save results and exit)\n");
    mcfinally();
    exit(0);
  }
  else
  {
    fflush(stdout);
    perror("# Last I/O Error");
    printf("# McStas: Simulation stop (abort)\n");
    exit(-1);
  }
#undef SIG_SAVE
#undef SIG_TERM
#undef SIG_STAT
#undef SIG_ABRT

} /* sighandler */
#endif /* !NOSIGNALS */

/*******************************************************************************
* mccode_main: McCode main() function.
*******************************************************************************/
int mccode_main(int argc, char *argv[])
{
/*  double run_num = 0; */
  time_t t;
#ifdef USE_MPI
  char mpi_node_name[MPI_MAX_PROCESSOR_NAME];
  int  mpi_node_name_len;
#endif /* USE_MPI */

#ifdef MAC
  argc = ccommand(&argv);
#endif

#ifdef USE_MPI
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &mpi_node_count); /* get number of nodes */
  MPI_Comm_rank(MPI_COMM_WORLD, &mpi_node_rank);
  MPI_Get_processor_name(mpi_node_name, &mpi_node_name_len);
#endif /* USE_MPI */

#ifdef USE_MPI
/* *** print number of nodes *********************************************** */
  if (mpi_node_count > 1) {
    MPI_MASTER(
    printf("Simulation '%s' (%s): running on %i nodes (master is '%s', MPI version %i.%i).\n",
      mcinstrument_name, mcinstrument_source, mpi_node_count, mpi_node_name, MPI_VERSION, MPI_SUBVERSION);
    );
    /* adapt random seed for each node */
    mcseed=(long)(time(&t) + mpi_node_rank);
    srandom(mcseed);
    t += mpi_node_rank;
  } else
#else /* !USE_MPI */
  mcseed=(long)time(&t);
  srandom(mcseed);
#endif /* USE_MPI */
  mcstartdate = (long)t;  /* set start date before parsing options and creating sim file */

/* *** parse options ******************************************************* */
  SIG_MESSAGE("main (Start)");
  mcformat=mcuse_format(getenv(FLAVOR_UPPER "_FORMAT") ?
                        getenv(FLAVOR_UPPER "_FORMAT") : MCSTAS_FORMAT);
  /* default is to output as McStas format */
  mcformat_data.Name=NULL;
  /* read simulation parameters and options */
  mcparseoptions(argc, argv); /* sets output dir and format */
  if (strstr(mcformat.Name, "NeXus")) {
    if (mcformat_data.Name) mcclear_format(mcformat_data);
    mcformat_data.Name=NULL;
  }
  if (!mcformat_data.Name && strstr(mcformat.Name, "HTML"))
    mcformat_data = mcuse_format("VRML");

/* *** install sig handler, but only once !! after parameters parsing ******* */
#ifndef NOSIGNALS
#ifdef SIGQUIT
  if (signal( SIGQUIT ,sighandler) == SIG_IGN)
    signal( SIGQUIT,SIG_IGN);   /* quit (ASCII FS) */
#endif
#ifdef SIGABRT
  if (signal( SIGABRT ,sighandler) == SIG_IGN)
    signal( SIGABRT,SIG_IGN);   /* used by abort, replace SIGIOT in the future */
#endif
#ifdef SIGTERM
  if (signal( SIGTERM ,sighandler) == SIG_IGN)
    signal( SIGTERM,SIG_IGN);   /* software termination signal from kill */
#endif
#ifdef SIGUSR1
  if (signal( SIGUSR1 ,sighandler) == SIG_IGN)
    signal( SIGUSR1,SIG_IGN);   /* display simulation status */
#endif
#ifdef SIGUSR2
  if (signal( SIGUSR2 ,sighandler) == SIG_IGN)
    signal( SIGUSR2,SIG_IGN);
#endif
#ifdef SIGHUP
  if (signal( SIGHUP ,sighandler) == SIG_IGN)
    signal( SIGHUP,SIG_IGN);
#endif
#ifdef SIGILL
  if (signal( SIGILL ,sighandler) == SIG_IGN)
    signal( SIGILL,SIG_IGN);    /* illegal instruction (not reset when caught) */
#endif
#ifdef SIGFPE
  if (signal( SIGFPE ,sighandler) == SIG_IGN)
    signal( SIGSEGV,SIG_IGN);    /* floating point exception */
#endif
#ifdef SIGBUS
  if (signal( SIGBUS ,sighandler) == SIG_IGN)
    signal( SIGSEGV,SIG_IGN);    /* bus error */
#endif
#ifdef SIGSEGV
  if (signal( SIGSEGV ,sighandler) == SIG_IGN)
    signal( SIGSEGV,SIG_IGN);   /* segmentation violation */
#endif
#endif /* !NOSIGNALS */
  if (!strstr(mcformat.Name,"NeXus")) {
    mcsiminfo_init(NULL); mcsiminfo_close();  /* makes sure we can do that */
  }
  SIG_MESSAGE("main (Init)");
  mcinit();
#ifndef NOSIGNALS
#ifdef SIGINT
  if (signal( SIGINT ,sighandler) == SIG_IGN)
    signal( SIGINT,SIG_IGN);    /* interrupt (rubout) only after INIT */
#endif
#endif /* !NOSIGNALS */

/* ================ main particule generation/propagation loop ================ */
#if defined (USE_MPI)
  /* sliced Ncount on each MPI node */
  mcncount = mpi_node_count > 1 ?
    floor(mcncount / mpi_node_count) :
    mcncount; /* number of rays per node */
#endif

/* main particule event loop */
while(mcrun_num < mcncount || mcrun_num < mcget_ncount())
  {
#ifndef NEUTRONICS
    mcgenstate();
#endif
    /* old init: mcsetstate(0, 0, 0, 0, 0, 1, 0, sx=0, sy=1, sz=0, 1); */
    mcraytrace();
    mcrun_num++;
  }

#ifdef USE_MPI
 /* merge run_num from MPI nodes */
  if (mpi_node_count > 1) {
  double mcrun_num_double = (double)mcrun_num;
  mc_MPI_Sum(&mcrun_num_double, 1);
  mcrun_num = (unsigned long long)mcrun_num_double;
  }
#endif

/* save/finally executed by master node/thread */
  mcfinally();
  mcclear_format(mcformat);
  if (mcformat_data.Name) mcclear_format(mcformat_data);

#ifdef USE_MPI
  MPI_Finalize();
#endif /* USE_MPI */

  return 0;
} /* mccode_main */

#ifdef NEUTRONICS
/*Main neutronics function steers the McStas calls, initializes parameters etc */
/* Only called in case NEUTRONICS = TRUE */
void neutronics_main_(float *inx, float *iny, float *inz, float *invx, float *invy, float *invz, float *intime, float *insx, float *insy, float *insz, float *inw, float *outx, float *outy, float *outz, float *outvx, float *outvy, float *outvz, float *outtime, float *outsx, float *outsy, float *outsz, float *outwgt)
{

  extern double mcnx, mcny, mcnz, mcnvx, mcnvy, mcnvz;
  extern double mcnt, mcnsx, mcnsy, mcnsz, mcnp;

  /* External code governs iteration - McStas is iterated once per call to neutronics_main. I.e. below counter must be initiancated for each call to neutronics_main*/
  mcrun_num=0;

  time_t t;
  t = (time_t)mcstartdate;
  mcstartdate = t;  /* set start date before parsing options and creating sim file */
  mcinit();

  /* *** parse options *** */
  SIG_MESSAGE("main (Start)");
  mcformat=mcuse_format(getenv(FLAVOR_UPPER "_FORMAT") ?
                        getenv(FLAVOR_UPPER "_FORMAT") : MCSTAS_FORMAT);
  /* default is to output as McStas format */
  mcformat_data.Name=NULL;
  /* read simulation parameters and options */
  if (strstr(mcformat.Name, "NeXus")) {
    if (mcformat_data.Name) mcclear_format(mcformat_data);
    mcformat_data.Name=NULL;
  }
  if (!mcformat_data.Name && strstr(mcformat.Name, "HTML"))
    mcformat_data = mcuse_format("VRML");

  /* Set neutron state based on input from neutronics code */
  mcsetstate(*inx,*iny,*inz,*invx,*invy,*invz,*intime,*insx,*insy,*insz,*inw);

  /* main neutron event loop - runs only one iteration */

  //mcstas_raytrace(&mcncount); /* prior to McStas 1.12 */

  mcallowbackprop = 1; //avoid absorbtion from negative dt
  int argc=1;
  char *argv[0];
  int dummy = mccode_main(argc, argv);

  /*  save/finally executed by master node/thread. Needed for McStas 1.12 and older */
  /*  mcfinally(); */
  /*  mcclear_format(mcformat); */

  if (mcformat_data.Name) mcclear_format(mcformat_data);

  *outx =  mcnx;
  *outy =  mcny;
  *outz =  mcnz;
  *outvx =  mcnvx;
  *outvy =  mcnvy;
  *outvz =  mcnvz;
  *outtime =  mcnt;
  *outsx =  mcnsx;
  *outsy =  mcnsy;
  *outsz =  mcnsz;
  *outwgt =  mcnp;

  return;
} /* neutronics_main */

#endif /*NEUTRONICS*/

#ifdef USE_NEXUS
/*******************************************************************************
* mcnxfile_parameters: writes the simulation parameters
*                   open/close a new Data Set per parameter in the current simulation Group
* NOTE: this function can not be included in nexus-lib as it depends on mcinputtypes
*       and mcinputtable are defined at compile time in here.
* Returns: NX_OK
*******************************************************************************/
int mcnxfile_parameters(NXhandle nxhandle)
{
  int i;
  char Parameters[CHAR_BUF_LENGTH];
  /* in the parameter group, create one SDS per parameter */
  for(i = 0; i < mcnumipar; i++) {
    if (mcget_run_num() || (mcinputtable[i].val && strlen(mcinputtable[i].val))) {
      char nxname[CHAR_BUF_LENGTH];
      int length;
      if (mcinputtable[i].par == NULL)
        strncpy(Parameters, (mcinputtable[i].val ? mcinputtable[i].val : ""), CHAR_BUF_LENGTH);
      else
        (*mcinputtypes[mcinputtable[i].type].printer)(Parameters, mcinputtable[i].par);
      sprintf(nxname, "%s", Parameters);
      length = strlen(nxname);
      NXmakedata(mcnxHandle, mcinputtable[i].name, NX_CHAR, 1, &length);
      NXopendata(mcnxHandle, mcinputtable[i].name);
      NXputdata (mcnxHandle, nxname);
      strcpy(nxname, (*mcinputtypes[mcinputtable[i].type].parminfo)(mcinputtable[i].name));
      NXputattr (mcnxHandle, "type", nxname, strlen(nxname), NX_CHAR);
      strcpy(nxname, mcinputtable[i].val ? mcinputtable[i].val : "");
      NXputattr (mcnxHandle, "default_value", nxname, strlen(nxname), NX_CHAR);
      NXputattr (mcnxHandle, "name", mcinputtable[i].name, strlen(mcinputtable[i].name), NX_CHAR);
      NXclosedata(mcnxHandle);
    }
  }
  return(NX_OK);
} /* mcnxfile_parameters */
#endif /* USE_NEXUS */

#endif /* !MCCODE_H */
/* End of file "mccode-r.c". */
/* End of file "mccode-r.c". */

#line 6369 "/Users/pengfei/github/Monte_Carlo/single_slit.c"

#line 1 "mcxtrace-r.c"
/*******************************************************************************
*
* McXtrace, X-ray tracing package
*           Copyright (C) 1997-2009, All rights reserved
*           Risoe National Laboratory, Roskilde, Denmark
*           Institut Laue Langevin, Grenoble, France
*
* Runtime: share/mcxtrace-r.c
*
* %Identification
* Edited by: EK
* Date:    May 29, 2009
* Release: McXtrace X.Y
* Version: $Revision: 4382 $
*
* Runtime system for McXtrace.
* Embedded within instrument in runtime mode.
*
* Usage: Automatically embedded in the c code whenever required.
*
*******************************************************************************/

#ifndef MCXTRACE_H

/*******************************************************************************
* mcstore_xray: stores neutron coodinates into global array (per component)
*******************************************************************************/
void
mcstore_xray(MCNUM *s, int index, double x, double y, double z,
               double kx, double ky, double kz, double phi, double t,
               double Ex, double Ey, double Ez, double p)
{
    double *dptr = &s[11*index];
    *dptr++  = x;
    *dptr++  = y ;
    *dptr++  = z ;
    *dptr++  = kx;
    *dptr++  = ky;
    *dptr++  = kz;
    *dptr++  = phi;
    *dptr++  = t;
    *dptr++  = Ex;
    *dptr++  = Ey;
    *dptr++  = Ez;
    *dptr    = p ;
}

/*******************************************************************************
* mcrestore_xray: restores neutron coodinates from global array
*******************************************************************************/
void
mcrestore_xray(MCNUM *s, int index, double *x, double *y, double *z,
               double *kx, double *ky, double *kz, double *phi, double *t,
               double *Ex, double *Ey, double *Ez, double *p)
{
    double *dptr = &s[11*index];
    *x  =  *dptr++;
    *y  =  *dptr++;
    *z  =  *dptr++;
    *kx =  *dptr++;
    *ky =  *dptr++;
    *kz =  *dptr++;
    *phi=  *dptr++;
    *t  =  *dptr++;
    *Ex =  *dptr++;
    *Ey =  *dptr++;
    *Ez =  *dptr++;
    *p  =  *dptr;
} /* mcrestore_xray */

/*******************************************************************************
* mcsetstate: transfer parameters into global McXtrace variables 
*******************************************************************************/
void
mcsetstate(double x, double y, double z, double kx, double ky, double kz,
           double phi, double t, double Ex, double Ey, double Ez, double p)
{
  extern double mcnx, mcny, mcnz, mcnkx, mcnky, mcnkz;
  extern double mcnphi, mcnt, mcnEx, mcnEy, mcnEz, mcnp;

  mcnx = x;
  mcny = y;
  mcnz = z;
  mcnkx = kx;
  mcnky = ky;
  mcnkz = kz;
  mcnphi = phi;
  mcnt = t;
  mcnEx = Ex;
  mcnEy = Ey;
  mcnEz = Ez;
  mcnp = p;
} /* mcsetstate */

/*******************************************************************************
* mcgenstate: set default xray parameters 
*******************************************************************************/
void
mcgenstate(void)
{
  mcsetstate(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1);
  /* old initialisation: mcsetstate(0, 0, 0, 0, 0, 1, 0, sx=0, sy=1, sz=0, 1); */
}

/* intersection routines ==================================================== */

/*******************************************************************************
* inside_rectangle: Check if (x,y) is inside rectangle (xwidth, yheight) 
* return 0 if outside and 1 if inside 
*******************************************************************************/
int inside_rectangle(double x, double y, double xwidth, double yheight)
{
  if (x>-xwidth/2 && x<xwidth/2 && y>-yheight/2 && y<yheight/2)
    return 1;
  else
    return 0;
}

/*******************************************************************************
 * box_intersect: compute length intersection with a box
 * returns 0 when no intersection is found
 *      or 1 in case of intersection with resulting travelling lengths dl_in and dl_out
*******************************************************************************/
int box_intersect(double *dl_in, double *dl_out,
                  double x, double y, double z,
                  double kx, double ky, double kz,
                  double dx, double dy, double dz)
{

  double k, l,xf,yf,zf, l_[6],dx_2,dy_2,dz_2;
  double ab[2];
  unsigned int count=0;
  k=sqrt(scalar_prod(kx,ky,kz,kx,ky,kz));
  dx_2=dx/2.0;dy_2=dy/2.0;dz_2=dz/2.0; 
  /*we really don't need to store the 6 intersects as only two are possible. i.e. should remove that.*/
  if (kx) {
    l=(-dx_2-x)/kx*k;
    yf=l*ky/k+y;zf=l*kz/k+z;
    if(yf > -dy_2 && yf<dy_2 && zf > -dz_2 && zf<dz_2){
      l_[0]=l;
      ab[count++]=l_[0];
    }else{
      l_[0]=0;
    }
    l=(dx_2-x)/kx*k;
    yf=l*ky/k+y;zf=l*kz/k+z;
    if(yf > -dy_2 && yf<dy_2 && zf > -dz_2 && zf<dz_2){
      l_[1]=l;
      ab[count++]=l_[1];
    }else{
      l_[1]=0;
    }
  }
  if (ky) {
    l=(-dy_2-y)/ky*k;
    xf=l*kx/k+x;zf=l*kz/k+z;
    if(xf > -dx_2 && xf<dx_2 && zf > -dz_2 && zf<dz_2){
      l_[2]=l;
      ab[count++]=l_[2];
    }else{
      l_[2]=0;
    } 
    l=(dy_2-y)/ky*k;
    xf=l*kx/k+x;zf=l*kz/k+z;
    if(xf > -dx_2 && xf<dx_2 && zf > -dz_2 && zf<dz_2){
      l_[3]=l;
      ab[count++]=l_[3];
    }else{
      l_[3]=0;
    }
  }
  if (kz) {
    l=(-dz_2-z)/kz*k;
    xf=l*kx/k+x; yf=l*ky/k+y;
    if(xf > -dx_2 && xf<dx_2 && yf > -dy_2 && yf<dy_2){
      l_[4]=l;
      ab[count++]=l_[4];
    }else{
      l_[4]=0;
    }
    l=(dz_2-z)/kz*k;
    xf=l*kx/k+x; yf=l*ky/k+y;
    if(xf > -dx_2 && xf<dx_2 && yf > -dy_2 && yf<dy_2){
      l_[5]=l;
      ab[count++]=l_[5];
    }else{
      l_[5]=0;
    }
  }
  /*check validity of intersects*/
  if (count>2){
    fprintf(stderr,"box_instersect: xray hitting box more than twice\n");
  }
  if (!count){
    *dl_in=0;*dl_out=0;
    return 0;
  }

  if (ab[0]<ab[1]){
    *dl_in=ab[0];*dl_out=ab[1];
    return 1;
  }else{
    *dl_in=ab[1];*dl_out=ab[0];
    return 1;
  }
} /* box_intersect */

/*******************************************************************************
 * cylinder_intersect: compute intersection with a cylinder
 * returns 0 when no intersection is found
 *      or 1/2/4/8/16 bits depending on intersection,
 *     and resulting times l0 and l1
 * Written by: EK 11.6.09 
 *******************************************************************************/
int
cylinder_intersect(double *l0, double *l1, double x, double y, double z,
                   double kx, double ky, double kz, double r, double h)
{
  double A,B,C,D,k2,k;
  double dl1p=0,dl0p=0,dl1c=0,dl0c=0,y0,y1;
  int ret=1,stat=0,plane_stat=0;
  enum {HIT_CYL=01,ENTER_TOP=02,ENTER_BOT=04,EXIT_TOP=010,EXIT_BOT=020,ENTER_MASK=060,EXIT_MASK=030};
  k2=(kx*kx + ky*ky + kz*kz);
  k=sqrt(k2);

  /*check for prop. vector 0*/
  if(!k2) return 0;

  A= (k2 - ky*ky);
  B= 2*(x*kx + z*kz);
  C=(x*x + z*z - r*r);
  D=B*B-4*A*C;
  if(D>=0){
    if (kx || kz){
      stat|=HIT_CYL;
    /*propagation not parallel to y-axis*/
    /*hit infinitely high cylinder?*/
      D=sqrt(D);
      dl0c=k*(-B-D)/(2*A);
      dl1c=k*(-B+D)/(2*A);
      y0=dl0c*ky/k+y;
      y1=dl1c*ky/k+y;
      if ( (y0<-h/2 && y1<-h/2) || (y0>h/2 && y1>h/2) ){
        /*ray passes above or below cylinder*/
        return 0;
      }
    }
    /*now check top and bottom planes*/
    if (ky){
      dl0p = k*(-h/2-y)/ky;
      dl1p = k*(h/2-y)/ky;
      /*switch solutions?*/
      if (dl0p<dl1p){
        plane_stat|=(ENTER_BOT|EXIT_TOP);
      }else{
        double tmp=dl1p;
        dl1p=dl0p;dl0p=tmp;
        plane_stat|=(ENTER_TOP|EXIT_BOT);
      }
    }
  }
  if (stat & HIT_CYL){
    if (ky && dl0p>dl0c){
      *l0=dl0p;/*1st top/bottom plane intersection happens after 1st cylinder intersect*/
      stat|= plane_stat & ENTER_MASK;
    } else
      *l0=dl0c;
    if(ky && dl1p<dl1c){
      *l1=dl1p;/*2nd top/bottom plane intersection happens before 2nd cylinder intersect*/
      stat|= plane_stat & EXIT_MASK;
    }else
      *l1=dl1c;
  }
  return stat;
} /* cylinder_intersect */

/*******************************************************************************
 * sphere_intersect: Calculate intersection between a line and a sphere.
 * returns 0 when no intersection is found
 *      or 1 in case of intersection with resulting lengths l0 and l1 
 *******************************************************************************/
int
sphere_intersect(double *l0, double *l1, double x, double y, double z,
                 double kx, double ky, double kz, double r)
{
  double B, C, D, k;

  k = kx*kx + ky*ky + kz*kz;
  B = (x*kx + y*ky + z*kz);
  C = x*x + y*y + z*z - r*r;
  D = B*B - k*C;
  if(D < 0)
    return 0;
  D = sqrt(D);
  *l0 = (-B - D) / sqrt(k);
  *l1 = (-B + D) / sqrt(k);
  return 1;
} /* sphere_intersect */

/******************************************************************************
 * elliosoid_intersect: Calculate intersection between a line and an ellipsoid.
 * They ellisoid is fixed by a set of half-axis (a,b,c) and a matrix Q, with the
 * columns of Q being the (orthogonal) vectors along which the half-axis lie.
 * This allows for complete freedom in orienting th eellipsoid.
 * returns 0 when no intersection is found
 *      or 1 when they are found with resulting lemngths l0 and l1.
 *****************************************************************************/
int
ellipsoid_intersect(double *l0, double *l1, double x, double y, double z,
    double kx, double ky, double kz, double a, double b, double c,
    Rotation Q)
{
  Rotation A,Gamma,Q_t,Tmp;
  double u,v,w;

  Gamma[0][0]=Gamma[0][1]=Gamma[0][2]=0;
  Gamma[1][1]=Gamma[1][0]=Gamma[1][2]=0;
  Gamma[2][2]=Gamma[2][0]=Gamma[2][1]=0;
  /*now set diagonal to ellipsoid half axis if non-zero.
   * This way a zero value mean the sllipsoid extends infinitely along that axis,
   * which is useful for objects only curved in one direction*/ 
  if (a!=0){
    Gamma[0][0]=1/(a*a);
  }
  if (b!=0){
    Gamma[1][1]=1/(b*b);
  }
  if (c!=0){
    Gamma[2][2]=1/(c*c);
  }

  if (Q!=NULL){
    rot_transpose(Q,Q_t);
    rot_mul(Gamma,Q_t,Tmp);
    rot_mul(Q,Tmp,A);
  }else{
    rot_copy(A,Gamma);
  }

  /*to get the solutions as lengths in m use unit vector along k*/
  double ex,ey,ez,k;
  k=sqrt(kx*kx+ky*ky+kz*kz);
  ex=kx/k;
  ey=ky/k;
  ez=kz/k;

  u=ex*(A[0][0]*ex + A[1][0]*ey + A[2][0]*ez) + ey*( A[0][1]*ex + A[1][1]*ey + A[2][1]*ez) + ez*(A[0][2]*ex + A[1][2]*ey + A[2][2]*ez);
  v=x *(A[0][0]*ex + A[1][0]*ey + A[2][0]*ez) + ex*(A[0][0]*x + A[1][0]*y + A[2][0]*z) +
    y *(A[0][1]*ex + A[1][1]*ey + A[2][1]*ez) + ey*(A[0][1]*x + A[1][1]*y + A[2][1]*z) +
    z *(A[0][2]*ex + A[1][2]*ey + A[2][2]*ez) + ez*(A[0][2]*x + A[1][2]*y + A[2][2]*z);
  w=x*(A[0][0]*x + A[1][0]*y + A[2][0]*z) + y*(A[0][1]*x + A[1][1]*y + A[2][1]*z) + z*(A[0][2]*x + A[1][2]*y + A[2][2]*z);

  double D=v*v-4*u*w+4*u;
  if (D<0) return 0;

  D=sqrt(D);

  *l0=(-v-D) / (2*u);
  *l1=(-v+D) / (2*u);
  return 1;
}


/*******************************************************************************
 * plane_intersect: Calculate intersection between a plane (with normal n including the point w)
 * and a line thourhg x along the direction k.
 * returns 0 when no intersection is found (i.e. line is parallel to the plane)
 * returns 1 or -1 when intersection length is positive and negative, respectively
 *******************************************************************************/
int
plane_intersect(double *l, double x, double y, double z,
                 double kx, double ky, double kz, double nx, double ny, double nz, double wx, double wy, double wz)
{
  double s,k2;
  k2=scalar_prod(kx,ky,kz,kx,ky,kz);
  s=scalar_prod(kx,ky,kz,nx,ny,nz);
  if (k2<FLT_EPSILON || fabs(s)<FLT_EPSILON) return 0;
  *l = - sqrt(k2)*scalar_prod(nx,ny,nz,x-wx,y-wy,z-wz)/s;
  if (*l<0) return -1;
  else return 1;
} /* plane_intersect */

#endif /* !MCXTRACE_H */
/* End of file "mcxtrace-r.c". */

#line 6757 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
#ifdef MC_TRACE_ENABLED
int mctraceenabled = 1;
#else
int mctraceenabled = 0;
#endif
#define MCSTAS "/usr/local/lib/mcxtrace-1.1/"
int mcdefaultmain = 1;
char mcinstrument_name[] = "test";
char mcinstrument_source[] = "/Users/pengfei/github/Monte_Carlo/single_slit.instr";
int main(int argc, char *argv[]){return mccode_main(argc, argv);}
void mcinit(void);
void mcraytrace(void);
void mcsave(FILE *);
void mcfinally(void);
void mcdisplay(void);

/* Shared user declarations for all components 'Source_pt'. */
#line 51 "/usr/local/lib/mcxtrace-1.1/sources/Source_pt.comp"
/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright 1997-2002, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Library: share/read_table-lib.h
*
* %Identification
* Written by: EF
* Date: Aug 28, 2002
* Origin: ILL
* Release: McStas 1.6
* Version: $Revision: 4382 $
*
* This file is to be imported by components that may read data from table files
* It handles some shared functions.
*
* This library may be used directly as an external library. It has no dependency
*
* Usage: within SHARE
* %include "read_table-lib"
*
*******************************************************************************/

#ifndef READ_TABLE_LIB_H
#define READ_TABLE_LIB_H "$Revision: 4382 $"

#define READ_TABLE_STEPTOL  0.04 /* tolerancy for constant step approx */

#ifndef MC_PATHSEP_C
#ifdef WIN32
#define MC_PATHSEP_C '\\'
#define MC_PATHSEP_S "\\"
#else  /* !WIN32 */
#ifdef MAC
#define MC_PATHSEP_C ':'
#define MC_PATHSEP_S ":"
#else  /* !MAC */
#define MC_PATHSEP_C '/'
#define MC_PATHSEP_S "/"
#endif /* !MAC */
#endif /* !WIN32 */
#endif /* !MC_PATHSEP_C */

#ifndef MCSTAS
#ifdef WIN32
#define MCSTAS "C:\\mcstas\\lib"
#else  /* !WIN32 */
#ifdef MAC
#define MCSTAS ":mcstas:lib" /* ToDo: What to put here? */
#else  /* !MAC */
#define MCSTAS "/usr/local/lib/mcstas"
#endif /* !MAC */
#endif /* !WIN32 */
#endif /* !MCSTAS */

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

  typedef struct struct_table
  {
    char    filename[256];
    long    filesize;
    char   *header;  /* text header, e.g. comments */
    double *data;    /* vector { x[0], y[0], ... x[n-1], y[n-1]... } */
    double  min_x;   /* min value of first column */
    double  max_x;   /* max value of first column */
    double  step_x;  /* minimal step value of first column */
    long    rows;    /* number of rows in matrix block */
    long    columns; /* number of columns in matrix block */

    long    begin;   /* start fseek index of block */
    long    end;     /* stop  fseek index of block */
    long    block_number;  /* block index. 0 is catenation of all */
    long    array_length;  /* number of elements in the t_Table array */
    char    monotonic;     /* true when 1st column/vector data is monotonic */
    char    constantstep;  /* true when 1st column/vector data has constant step */
    char    method[32];    /* interpolation method: nearest, linear */
  } t_Table;

/* read_table-lib function prototypes */
/* ========================================================================= */

/* 'public' functions */
long     Table_Read              (t_Table *Table, char *File, long block_number);
long     Table_Read_Offset       (t_Table *Table, char *File, long block_number,
                                  long *offset, long max_lines);
long     Table_Read_Offset_Binary(t_Table *Table, char *File, char *Type,
                                  long *Offset, long Rows, long Columns);
long     Table_Rebin(t_Table *Table); /* rebin table with regular 1st column and interpolate all columns 2:end */
long     Table_Info (t_Table Table);
double   Table_Index(t_Table Table,   long i, long j); /* get indexed value */
double   Table_Value(t_Table Table, double X, long j); /* search X in 1st column and return interpolated value in j-column */
t_Table *Table_Read_Array(char *File, long *blocks);
void     Table_Free_Array(t_Table *Table);
long     Table_Info_Array(t_Table *Table);
int      Table_SetElement(t_Table *Table, long i, long j, double value);
long     Table_Init(t_Table *Table, long rows, long columns); /* create a Table */
double   Table_Value2d(t_Table Table, double X, double Y);    /* same as Table_Index with non-integer indices and 2d interpolation */
MCDETECTOR Table_Write(t_Table Table, char*file, char*xl, char*yl, 
           double x1, double x2, double y1, double y2); /* write Table to disk */

#define Table_ParseHeader(header, ...) \
  Table_ParseHeader_backend(header,__VA_ARGS__,NULL);

char **Table_ParseHeader_backend(char *header, ...);

/* private functions */
void Table_Free(t_Table *Table);
long Table_Read_Handle(t_Table *Table, FILE *fid, long block_number, long max_lines, char *name);
static void Table_Stat(t_Table *Table);
double Table_Interp1d(double x, double x1, double y1, double x2, double y2);
double Table_Interp1d_nearest(double x, double x1, double y1, double x2, double y2);
double Table_Interp2d(double x, double y, double x1, double y1, double x2, double y2,
  double z11, double z12, double z21, double z22);

#endif

/* end of read_table-lib.h */
/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Library: share/read_table-lib.c
*
* %Identification
* Written by: EF
* Date: Aug 28, 2002
* Origin: ILL
* Release: McStas CVS_090504
* Version: $Revision: 4382 $
*
* This file is to be imported by components that may read data from table files
* It handles some shared functions. Embedded within instrument in runtime mode.
*
* Usage: within SHARE
* %include "read_table-lib"
*
*******************************************************************************/

#ifndef READ_TABLE_LIB_H
#include "read_table-lib.h"
#endif

/*******************************************************************************
* long Read_Table(t_Table *Table, char *name, int block_number)
*   ACTION: read a single Table from a text file
*   input   Table: pointer to a t_Table structure
*           name:  file name from which table should be extracted
*           block_number: if the file does contain more than one
*                 data block, then indicates which one to get (from index 1)
*                 a 0 value means append/catenate all
*   return  initialized single Table t_Table structure containing data, header, ...
*           number of read elements (-1: error, 0:header only)
* The routine stores any line starting with '#', '%' and ';' into the header
* File is opened, read and closed
* Other lines are interpreted as numerical data, and stored.
* Data block should be a rectangular matrix or vector.
* Data block may be rebined with Table_Rebin (also sort in ascending order)
*******************************************************************************/
  long Table_Read(t_Table *Table, char *File, long block_number)
  { /* reads all or a single data block from 'file' and returns a Table structure  */
    return(Table_Read_Offset(Table, File, block_number, NULL, 0));
  } /* end Table_Read */

/*******************************************************************************
* long Table_Read_Offset(t_Table *Table, char *name, int block_number, long *offset
*                        long max_rows)
*   ACTION: read a single Table from a text file, starting at offset
*     Same as Table_Read(..) except:
*   input   offset:    pointer to an offset (*offset should be 0 at start)
*           max_rows: max number of data rows to read from file (0 means all)
*   return  initialized single Table t_Table structure containing data, header, ...
*           number of read elements (-1: error, 0:header only)
*           updated *offset position (where end of reading occured)
*******************************************************************************/
  long Table_Read_Offset(t_Table *Table, char *File,
                         long block_number, long *offset,
                         long max_rows)
  { /* reads all/a data block in 'file' and returns a Table structure  */
    FILE *hfile;
    long  nelements;
    long  begin;
    long  filesize=0;
    char  name[256];
    char  path[1024];
    struct stat stfile;

    if (!Table) return(-1);
    Table_Init(Table, 0, 0);
    if (!File || File[0]=='\0')  return(-1);
    if (!strcmp(File,"NULL") || !strcmp(File,"0"))  return(-1);
    strncpy(path, File, 1024);
    hfile = fopen(path, "r");
    if(!hfile)
    {
      char dir[1024];

      if (!hfile) /* search in instrument location */
      {
        char *path_pos   = NULL;
        /* extract path: searches for last file separator */
        path_pos    = strrchr(mcinstrument_source, MC_PATHSEP_C);  /* last PATHSEP */
        if (path_pos) {
          long path_length = path_pos +1 - mcinstrument_source;  /* from start to path+sep */
          if (path_length) {
            strncpy(dir, mcinstrument_source, path_length);
            sprintf(path, "%s%c%s", dir, MC_PATHSEP_C, File);
            hfile = fopen(path, "r");
          }
        }
      }
      if (!hfile) /* search in HOME */
      {
        strcpy(dir, getenv("HOME") ? getenv("HOME") : ".");
        sprintf(path, "%s%c%s", dir, MC_PATHSEP_C, File);
        hfile = fopen(path, "r");
      }
      if (!hfile) /* search in MCSTAS data */
      {
        strcpy(dir, getenv(FLAVOR_UPPER) ? getenv(FLAVOR_UPPER) : MCSTAS);
        sprintf(path, "%s%c%s%c%s", dir, MC_PATHSEP_C, "data", MC_PATHSEP_C, File);
        hfile = fopen(path, "r");
      }
      if (!hfile) /* search in MVCSTAS/contrib */
      {
        strcpy(dir, getenv(FLAVOR_UPPER) ? getenv(FLAVOR_UPPER) : MCSTAS);
        sprintf(path, "%s%c%s%c%s", dir, MC_PATHSEP_C, "contrib", MC_PATHSEP_C, File);
        hfile = fopen(path, "r");
      }
      if(!hfile)
      {
        fprintf(stderr, "Error: Could not open input file '%s' (Table_Read_Offset_Binary)\n", File);
        return (-1);
      } else if (!offset || (offset && !*offset))
        printf("Opening input file '%s' (Table_Read)\n", path);
    }
    stat(path,&stfile); filesize = stfile.st_size;
    if (offset && *offset) fseek(hfile, *offset, SEEK_SET);
    begin     = ftell(hfile);
    if (offset && *offset) sprintf(name, "%s@%li", File, *offset);
    else                   strncpy(name, File, 128);
    nelements = Table_Read_Handle(Table, hfile, block_number, max_rows, name);
    Table->begin = begin;
    Table->end   = ftell(hfile);
    Table->filesize = (filesize>0 ? filesize : 0);
    Table_Stat(Table);
    if (offset) *offset=Table->end;
    fclose(hfile);
    return(nelements);

  } /* end Table_Read_Offset */

/*******************************************************************************
* long Table_Read_Offset_Binary(t_Table *Table, char *File, char *type,
*                               long *offset, long rows, long columns)
*   ACTION: read a single Table from a binary file, starting at offset
*     Same as Table_Read_Offset(..) except that it handles binary files.
*   input   type: may be "float"/NULL or "double"
*           offset: pointer to an offset (*offset should be 0 at start)
*           rows   : number of rows (0 means read all)
*           columns: number of columns
*   return  initialized single Table t_Table structure containing data, header, ...
*           number of read elements (-1: error, 0:header only)
*           updated *offset position (where end of reading occured)
*******************************************************************************/
  long Table_Read_Offset_Binary(t_Table *Table, char *File, char *type,
                                long *offset, long rows, long columns)
  { /* reads all/a data block in binary 'file' and returns a Table structure  */
    long    nelements, sizeofelement;
    long    filesize;
    FILE   *hfile;
    struct stat stfile;
    double *data;
    long    i;
    long    begin;

    if (!Table) return(-1);

    Table_Init(Table, 0, 0);
    if (!File || File[0]=='\0')  return(-1);
    if (!strcmp(File,"NULL") || !strcmp(File,"0"))  return(-1);

    hfile = fopen(File, "r");
    if(!hfile)
    {
      char path[1024];
      char dir[1024];

      if (!hfile) /* search in instrument location */
      {
        char *path_pos   = NULL;
        /* extract path: searches for last file separator */
        path_pos    = strrchr(mcinstrument_source, MC_PATHSEP_C);  /* last PATHSEP */
        if (path_pos) {
          long path_length = path_pos +1 - mcinstrument_source;  /* from start to path+sep */
          if (path_length) {
            strncpy(dir, mcinstrument_source, path_length);
            sprintf(path, "%s%c%s", dir, MC_PATHSEP_C, File);
            hfile = fopen(path, "r");
          }
        }
      }
      if (!hfile) /* search in HOME */
      {
        strcpy(dir, getenv("HOME") ? getenv("HOME") : ".");
        sprintf(path, "%s%c%s", dir, MC_PATHSEP_C, File);
        hfile = fopen(path, "r");
      }
      if (!hfile) /* search in MCSTAS data */
      {
        strcpy(dir, getenv(FLAVOR_UPPER) ? getenv(FLAVOR_UPPER) : MCSTAS);
        sprintf(path, "%s%c%s%c%s", dir, MC_PATHSEP_C, "data", MC_PATHSEP_C, File);
        hfile = fopen(path, "r");
      }
      if (!hfile) /* search in MVCSTAS/contrib */
      {
        strcpy(dir, getenv(FLAVOR_UPPER) ? getenv(FLAVOR_UPPER) : MCSTAS);
        sprintf(path, "%s%c%s%c%s", dir, MC_PATHSEP_C, "contrib", MC_PATHSEP_C, File);
        hfile = fopen(path, "r");
      }
      if(!hfile)
      {
        fprintf(stderr, "Error: Could not open input file '%s' (Table_Read_Offset_Binary)\n", File);
        return (-1);
      } else
        printf("Opening input file '%s' (Table_Read)\n", path);
    }
    stat(File,&stfile);
    filesize = stfile.st_size;
    Table->filesize=filesize;
    if (type && !strcmp(type,"double")) sizeofelement = sizeof(double);
    else  sizeofelement = sizeof(float);
    if (offset && *offset) fseek(hfile, *offset, SEEK_SET);
    begin     = ftell(hfile);
    if (rows && filesize > sizeofelement*columns*rows)
      nelements = columns*rows;
    else nelements = (long)(filesize/sizeofelement);
    if (!nelements || filesize <= *offset) return(0);
    data    = (double*)malloc(nelements*sizeofelement);
    if (!data) {
      fprintf(stderr,"Error: allocating %ld elements for %s file '%s'. Too big (Table_Read_Offset_Binary).\n", nelements, type, File);
      exit(-1);
    }
    nelements = fread(data, sizeofelement, nelements, hfile);

    if (!data || !nelements)
    {
      fprintf(stderr,"Error: reading %ld elements from %s file '%s' (Table_Read_Offset_Binary)\n", nelements, type, File);
      exit(-1);
    }
    Table->begin   = begin;
    Table->end     = ftell(hfile);
    if (offset) *offset=Table->end;
    fclose(hfile);
    data = (double*)realloc(data, (double)nelements*sizeofelement);
    /* copy file data into Table */
    if (type && !strcmp(type,"double")) Table->data = data;
    else {
      float  *s;
      double *dataf;
      s     = (float*)data;
      dataf = (double*)malloc(sizeof(double)*nelements);
      for (i=0; i<nelements; i++)
        dataf[i]=s[i];
      free(data);
      Table->data = dataf;
    }
    strcpy(Table->filename, File);
    Table->rows    = nelements/columns;
    Table->columns = columns;
    Table->array_length = 1;
    Table->block_number = 1;

    Table_Stat(Table);

    return(nelements);
  } /* end Table_Read_Offset_Binary */

/*******************************************************************************
* long Table_Read_Handle(t_Table *Table, FILE *fid, int block_number, long max_rows, char *name)
*   ACTION: read a single Table from a text file handle (private)
*   input   Table:pointer to a t_Table structure
*           fid:  pointer to FILE handle
*           block_number: if the file does contain more than one
*                 data block, then indicates which one to get (from index 1)
*                 a 0 value means append/catenate all
*           max_rows: if non 0, only reads that number of lines
*   return  initialized single Table t_Table structure containing data, header, ...
*           modified Table t_Table structure containing data, header, ...
*           number of read elements (-1: error, 0:header only)
* The routine stores any line starting with '#', '%' and ';' into the header
* Other lines are interpreted as numerical data, and stored.
* Data block should be a rectangular matrix or vector.
* Data block may be rebined with Table_Rebin (also sort in ascending order)
*******************************************************************************/
  long Table_Read_Handle(t_Table *Table, FILE *hfile,
                         long block_number, long max_rows, char *name)
  { /* reads all/a data block from 'file' handle and returns a Table structure  */
    double *Data;
    char *Header              = NULL;
    long  malloc_size         = CHAR_BUF_LENGTH;
    long  malloc_size_h       = 4096;
    long  Rows = 0,   Columns = 0;
    long  count_in_array      = 0;
    long  count_in_header     = 0;
    long  block_Current_index = 0;
    char  flag_End_row_loop   = 0;

    if (!Table) return(-1);
    Table_Init(Table, 0, 0);
    if (name && name[0]!='\0') strcpy(Table->filename, name);

    if(!hfile) {
       fprintf(stderr, "Error: File handle is NULL (Table_Read_Handle).\n");
       return (-1);
    }
    Header = (char*)  calloc(malloc_size_h, sizeof(char));
    Data   = (double*)calloc(malloc_size,   sizeof(double));
    if ((Header == NULL) || (Data == NULL)) {
       fprintf(stderr, "Error: Could not allocate Table and Header (Table_Read_Handle).\n");
       return (-1);
    }

    int flag_In_array = 0;
    do { /* while (!flag_End_row_loop) */
      char  line[1024*CHAR_BUF_LENGTH];
      long  back_pos=0;   /* ftell start of line */

      back_pos = ftell(hfile);
      if (fgets(line, 1024*CHAR_BUF_LENGTH, hfile) != NULL) { /* analyse line */
        /* first skip blank and tabulation characters */
        int i = strspn(line, " \t");

        /* handle comments: stored in header */
        if (NULL != strchr("#%;/", line[i]))
        { /* line is a comment */
          count_in_header += strlen(line);
          if (count_in_header >= malloc_size_h) {
            /* if succeed and in array : add (and realloc if necessary) */
            malloc_size_h = count_in_header+4096;
            Header        = (char*)realloc(Header, malloc_size_h*sizeof(char));
          }
          strncat(Header, line, 4096);
          flag_In_array=0;
          /* exit line and file if passed desired block */
          if (block_number > 0 && block_number == block_Current_index) {
            flag_End_row_loop = 1;
          }

          /* Continue with next line */
          continue;
        }

        /* get the number of columns splitting line with strtok */
        char  *lexeme;
        char  flag_End_Line = 0;
        long  block_Num_Columns = 0;
        const char seps[] = " ,;\t\n\r";

        lexeme = strtok(line, seps);
        while (!flag_End_Line) {
          if ((lexeme != NULL) && (lexeme[0] != '\0')) {
            /* reading line: the token is not empty */
            double X;
            int    count=1;
            /* test if we have 'NaN','Inf' */
            if (!strncasecmp(lexeme,"NaN",3))
              X = 0;
            else if (!strncasecmp(lexeme,"Inf",3) || !strncasecmp(lexeme,"+Inf",4))
              X = FLT_MAX;
            else if (!strncasecmp(lexeme,"-Inf",3))
              X = -FLT_MAX;
            else
              count = sscanf(lexeme,"%lg",&X);
            if (count == 1) {
              /* reading line: the token is a number in the line */
              if (!flag_In_array) {
                /* reading num: not already in a block: starts a new data block */
                block_Current_index++;
                flag_In_array    = 1;
                block_Num_Columns= 0;
                if (block_number > 0) {
                  /* initialise a new data block */
                  Rows = 0;
                  count_in_array = 0;
                } /* else append */
              }
              /* reading num: all blocks or selected block */
              if (flag_In_array && (block_number == 0 ||
                  block_number == block_Current_index)) {
                /* starting block: already the desired number of rows ? */
                if (block_Num_Columns == 0 &&
                    max_rows > 0 && Rows >= max_rows) {
                  flag_End_Line      = 1;
                  flag_End_row_loop  = 1;
                  flag_In_array      = 0;
                  /* reposition to begining of line (ignore line) */
                  fseek(hfile, back_pos, SEEK_SET);
                } else { /* store into data array */
                  if (count_in_array >= malloc_size) {
                    /* realloc data buffer if necessary */
                    malloc_size = count_in_array+CHAR_BUF_LENGTH;
                    Data = (double*) realloc(Data, malloc_size*sizeof(double));
                    if (Data == NULL) {
                      fprintf(stderr, "Error: Can not re-allocate memory %li (Table_Read_Handle).\n",
                              malloc_size*sizeof(double));
                      return (-1);
                    }
                  }
                  if (0 == block_Num_Columns) Rows++;
                  Data[count_in_array] = X;
                  count_in_array++;
                  block_Num_Columns++;
                }
              } /* reading num: end if flag_In_array */
            } /* end reading num: end if sscanf lexeme -> numerical */
            else {
              /* reading line: the token is not numerical in that line. end block */
              if (block_Current_index == block_number) {
                flag_End_Line = 1;
                flag_End_row_loop = 1;
              } else {
                flag_In_array = 0;
                flag_End_Line = 1;
              }
            }
          }
          else {
            /* no more tokens in line */
            flag_End_Line = 1;
            if (block_Num_Columns > 0) Columns = block_Num_Columns;
          }

          // parse next token
          lexeme = strtok(NULL, seps);

        } /* while (!flag_End_Line) */
      } /* end: if fgets */
      else flag_End_row_loop = 1; /* else fgets : end of file */

    } while (!flag_End_row_loop); /* end while flag_End_row_loop */

    Table->block_number = block_number;
    Table->array_length = 1;

    // shrink header to actual size (plus terminating 0-byte)
    if (count_in_header) {
      Header = (char*)realloc(Header, count_in_header*sizeof(char) + 1);
    }
    Table->header = Header;

    if (count_in_array*Rows*Columns == 0)
    {
      Table->rows         = 0;
      Table->columns      = 0;
      free(Data);
      return (0);
    }
    if (Rows * Columns != count_in_array)
    {
      fprintf(stderr, "Warning: Read_Table :%s %s Data has %li values that should be %li x %li\n",
        (Table->filename ? Table->filename : ""),
        (!block_number ? " catenated" : ""),
        count_in_array, Rows, Columns);
      Columns = count_in_array; Rows = 1;
    }
    Data     = (double*)realloc(Data, count_in_array*sizeof(double));
    Table->data         = Data;
    Table->rows         = Rows;
    Table->columns      = Columns;

    return (count_in_array);

  } /* end Table_Read_Handle */

/*******************************************************************************
* long Table_Rebin(t_Table *Table)
*   ACTION: rebin a single Table, sorting 1st column in ascending order
*   input   Table: single table containing data.
*                  The data block is reallocated in this process
*   return  updated Table with increasing, evenly spaced first column (index 0)
*           number of data elements (-1: error, 0:empty data)
*******************************************************************************/
  long Table_Rebin(t_Table *Table)
  {
    double new_step=0;
    long   i;
    /* performs linear interpolation on X axis (0-th column) */

    if (!Table) return(-1);
    if (!Table->data
    || Table->rows*Table->columns == 0 || !Table->step_x)
      return(0);
    Table_Stat(Table); /* recompute statitstics and minimal step */
    new_step = Table->step_x; /* minimal step in 1st column */

    if (!(Table->constantstep)) /* not already evenly spaced */
    {
      long Length_Table;
      double *New_Table;

      Length_Table = ceil(fabs(Table->max_x - Table->min_x)/new_step);
      New_Table    = (double*)malloc(Length_Table*Table->columns*sizeof(double));

      for (i=0; i < Length_Table; i++)
      {
        long   j;
        double X;
        X = Table->min_x + i*new_step;
        New_Table[i*Table->columns] = X;
        for (j=1; j < Table->columns; j++)
          New_Table[i*Table->columns+j]
                = Table_Value(*Table, X, j);
      } /* end for i */

      Table->rows = Length_Table;
      Table->step_x = new_step;
      free(Table->data);
      Table->data = New_Table;
    } /* end else (!constantstep) */
    return (Table->rows*Table->columns);
  } /* end Table_Rebin */

/*******************************************************************************
* double Table_Index(t_Table Table, long i, long j)
*   ACTION: read an element [i,j] of a single Table
*   input   Table: table containing data
*           i : index of row      (0:Rows-1)
*           j : index of column   (0:Columns-1)
*   return  Value = data[i][j]
* Returns Value from the i-th row, j-th column of Table
* Tests are performed on indexes i,j to avoid errors
*******************************************************************************/

#ifndef MIN
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#endif

double Table_Index(t_Table Table, long i, long j)
{
  long AbsIndex;

  if (Table.rows == 1 || Table.columns == 1) {
    /* vector */
    j = MIN(MAX(0, i+j), Table.columns*Table.rows - 1);
    i = 0;
  } else {
    /* matrix */
    i = MIN(MAX(0, i), Table.rows - 1);
    j = MIN(MAX(0, j), Table.columns - 1);
  }

  /* handle vectors specifically */
  AbsIndex = i*(Table.columns)+j;

  if (Table.data != NULL)
    return (Table.data[AbsIndex]);
  else
    return 0;
} /* end Table_Index */

/*******************************************************************************
* void Table_SetElement(t_Table *Table, long i, long j, double value)
*   ACTION: set an element [i,j] of a single Table
*   input   Table: table containing data
*           i : index of row      (0:Rows-1)
*           j : index of column   (0:Columns-1)
*           value = data[i][j]
* Returns 0 in case of error
* Tests are performed on indexes i,j to avoid errors
*******************************************************************************/
int Table_SetElement(t_Table *Table, long i, long j,
                     double value)
{
  long AbsIndex;

  if (Table->rows == 1 || Table->columns == 1) {
    /* vector */
    j = MIN(MAX(0, i+j), Table->columns*Table->rows - 1); i=0;
  } else {
    /* matrix */
    i = MIN(MAX(0, i), Table->rows - 1);
    j = MIN(MAX(0, j), Table->columns - 1);
  }

  AbsIndex = i*(Table->columns)+j;
  if (Table->data != NULL) {
    Table->data[AbsIndex] = value;
    return 1;
  }

  return 0;
} /* end Table_SetElement */

/*******************************************************************************
* double Table_Value(t_Table Table, double X, long j)
*   ACTION: read column [j] of a single Table at row which 1st column is X
*   input   Table: table containing data.
*           X : data value in the first column (index 0)
*           j : index of column from which is extracted the Value (0:Columns-1)
*   return  Value = data[index for X][j] with linear interpolation
* Returns Value from the j-th column of Table corresponding to the
* X value for the 1st column (index 0)
* Tests are performed (within Table_Index) on indexes i,j to avoid errors
* NOTE: data should rather be monotonic, and evenly sampled.
*******************************************************************************/
double Table_Value(t_Table Table, double X, long j)
{
  long   Index = -1;
  double X1=0, Y1=0, X2=0, Y2=0;
  double ret=0;

  if (X > Table.max_x) return Table_Index(Table,Table.rows-1  ,j);
  if (X < Table.min_x) return Table_Index(Table,0  ,j);

  // Use constant-time lookup when possible
  if(Table.constantstep) {
    Index = (long)floor(
              (X - Table.min_x) / (Table.max_x - Table.min_x) * Table.rows);
    X1 = Table_Index(Table,Index  ,0);
    X2 = Table_Index(Table,Index+1,0);
  }
  // Use binary search on large, monotonic tables
  else if(Table.monotonic && Table.rows > 100) {
    long left = Table.min_x;
    long right = Table.max_x;

    while (!((X1 <= X) && (X < X2)) && (right - left > 1)) {
      Index = (left + right) / 2;

      X1 = Table_Index(Table, Index-1, 0);
      X2 = Table_Index(Table, Index,   0);

      if (X < X1) {
        right = Index;
      } else {
        left  = Index;
      }
    }
  }

  // Fall back to linear search, if no-one else has set X1, X2 correctly
  if (!((X1 <= X) && (X < X2))) {
    /* look for index surrounding X in the table -> Index */
    for (Index=1; Index < Table.rows-1; Index++) {
        X1 = Table_Index(Table, Index-1,0);
        X2 = Table_Index(Table, Index  ,0);
        if ((X1 <= X) && (X < X2)) break;
      } /* end for Index */
  }

  Y1 = Table_Index(Table,Index-1,j);
  Y2 = Table_Index(Table,Index  ,j);

  if (!strcmp(Table.method,"linear")) {
    ret = Table_Interp1d(X, X1,Y1, X2,Y2);
  }
  else if (!strcmp(Table.method,"nearest")) {
    ret = Table_Interp1d_nearest(X, X1,Y1, X2,Y2);
  }

  return ret;
} /* end Table_Value */

/*******************************************************************************
* double Table_Value2d(t_Table Table, double X, double Y)
*   ACTION: read element [X,Y] of a matrix Table
*   input   Table: table containing data.
*           X : row index, may be non integer
*           Y : column index, may be non integer
*   return  Value = data[index X][index Y] with bi-linear interpolation
* Returns Value for the indices [X,Y]
* Tests are performed (within Table_Index) on indexes i,j to avoid errors
* NOTE: data should rather be monotonic, and evenly sampled.
*******************************************************************************/
  double Table_Value2d(t_Table Table, double X, double Y)
  {
    long   x1,x2,y1,y2;
    double z11,z12,z21,z22;
    double ret=0;

    x1 = (long)floor(X);
    y1 = (long)floor(Y);

    if (x1 > Table.rows-1 || x1 < 0) {
      x2 = x1;
    } else {
      x2 = x1 + 1;
    }

    if (y1 > Table.columns-1 || y1 < 0) {
      y2 = y1;
    } else {
      y2 = y1 + 1;
    }

    z11 = Table_Index(Table, x1, y1);

    if (y2 != y1) z12=Table_Index(Table, x1, y2); else z12 = z11;
    if (x2 != x1) z21=Table_Index(Table, x2, y1); else z21 = z11;
    if (y2 != y1) z22=Table_Index(Table, x2, y2); else z22 = z21;

    if (!strcmp(Table.method,"linear"))
      ret = Table_Interp2d(X,Y, x1,y1,x2,y2, z11,z12,z21,z22);
    else {
      if (fabs(X-x1) < fabs(X-x2)) {
        if (fabs(Y-y1) < fabs(Y-y2)) ret = z11; else ret = z12;
      } else {
        if (fabs(Y-y1) < fabs(Y-y2)) ret = z21; else ret = z22;
      }
    }
    return ret;
  } /* end Table_Value2d */


/*******************************************************************************
* void Table_Free(t_Table *Table)
*   ACTION: free a single Table
*   return: empty Table
*******************************************************************************/
  void Table_Free(t_Table *Table)
  {
    if (!Table) return;
    if (Table->data   != NULL) free(Table->data);
    if (Table->header != NULL) free(Table->header);
    Table->data   = NULL;
    Table->header = NULL;
  } /* end Table_Free */

/******************************************************************************
* void Table_Info(t_Table Table)
*    ACTION: print informations about a single Table
*******************************************************************************/
  long Table_Info(t_Table Table)
  {
    char buffer[256];
    long ret=0;

    if (!Table.block_number) strcpy(buffer, "catenated");
    else sprintf(buffer, "block %li", Table.block_number);
    printf("Table from file '%s' (%s)",
      Table.filename && strlen(Table.filename) ? Table.filename : "", buffer);
    if ((Table.data != NULL) && (Table.rows*Table.columns))
    {
      printf(" is %li x %li ", Table.rows, Table.columns);
      if (Table.rows*Table.columns > 1)
        printf("(x=%g:%g)", Table.min_x, Table.max_x);
      else printf("(x=%g) ", Table.min_x);
      ret = Table.rows*Table.columns;
      if (Table.monotonic)    printf(", monotonic");
      if (Table.constantstep) printf(", constant step");
      printf(". interpolation: %s\n", Table.method);
    }
    else printf(" is empty.\n");

    if (Table.header && strlen(Table.header)) {
      char *header;
      int  i;
      header = malloc(80);
      if (!header) return(ret);
      for (i=0; i<80; header[i++]=0);
      strncpy(header, Table.header, 75);
      if (strlen(Table.header) > 75) {
        strcat( header, " ...");
      }
      for (i=0; i<strlen(header); i++)
        if (header[i] == '\n' || header[i] == '\r') header[i] = ';';
      printf("  '%s'\n", header);
      free(header);
    }
    return(ret);
  } /* end Table_Info */

/******************************************************************************
* long Table_Init(t_Table *Table, m, n)
*   ACTION: initialise a Table to empty m by n table
*   return: empty Table
******************************************************************************/
long Table_Init(t_Table *Table, long rows, long columns)
{
  double *data=NULL;
  long   i;

  if (!Table) return(0);

  Table->header  = NULL;
  Table->filename[0]= '\0';
  Table->filesize= 0;
  Table->min_x   = 0;
  Table->max_x   = 0;
  Table->step_x  = 0;
  Table->block_number = 0;
  Table->array_length = 0;
  Table->monotonic    = 0;
  Table->constantstep = 0;
  Table->begin   = 0;
  Table->end     = 0;
  strcpy(Table->method,"linear");

  if (rows*columns >= 1) {
    data    = (double*)malloc(rows*columns*sizeof(double));
    if (data) for (i=0; i < rows*columns; data[i++]=0);
    else {
      fprintf(stderr,"Error: allocating %ld double elements."
                     "Too big (Table_Init).\n", rows*columns);
      rows = columns = 0;
    }
  }
  Table->rows    = (rows >= 1 ? rows : 0);
  Table->columns = (columns >= 1 ? columns : 0);
  Table->data    = data;
  return(Table->rows*Table->columns);
} /* end Table_Init */

/******************************************************************************
* long Table_Write(t_Table Table, char *file, x1,x2, y1,y2)
*   ACTION: write a Table to disk (ascii).
*     when x1=x2=0 or y1=y2=0, the table default limits are used.
*   return: 0=all is fine, non-0: error
*******************************************************************************/
MCDETECTOR Table_Write(t_Table Table, char *file, char *xl, char *yl, 
  double x1, double x2, double y1, double y2)
{
  long    i =0;
  MCDETECTOR detector;

  if ((Table.data == NULL) && (Table.rows*Table.columns)) {
    detector.m = 0;
    return(detector); /* Table is empty - nothing to do */
  }
  if (!x1 && !x2) {
    x1 = Table.min_x;
    x2 = Table.max_x;
  }
  if (!y1 && !y2) {
    y1 = 1;
    y2 = Table.columns;
  }

  /* transfer content of the Table into a 2D detector */
  Coords coords = { 0, 0, 0};

  if (Table.rows == 1 || Table.columns == 1) {
    detector = mcdetector_out_1D(Table.filename,
                      xl ? xl : "", yl ? yl : "",
                      "x", x1, x2,
                      Table.rows * Table.columns,
                      NULL, Table.data, NULL,
                      file, file, coords);
  } else {
    detector = mcdetector_out_2D(Table.filename,
                      xl ? xl : "", yl ? yl : "",
                      x1, x2, y1, y2,
                      Table.rows, Table.columns,
                      NULL, Table.data, NULL,
                      file, file, coords);
  }
  return(detector);
}

/******************************************************************************
* void Table_Stat(t_Table *Table)
*   ACTION: computes min/max/mean step of 1st column for a single table (private)
*   return: updated Table
*******************************************************************************/
  static void Table_Stat(t_Table *Table)
  {
    long   i;
    double max_x, min_x;
    double row=1;
    char   monotonic=1;
    char   constantstep=1;
    double step=0;
    double n;

    if (!Table) return;
    if (!Table->rows || !Table->columns) return;
    if (Table->rows == 1) row=0;
    max_x = -FLT_MAX;
    min_x =  FLT_MAX;
    n     = (row ? Table->rows : Table->columns);
    /* get min and max of first column/vector */
    for (i=0; i < n; i++)
    {
      double X;
      X = (row ? Table_Index(*Table,i  ,0)
                               : Table_Index(*Table,0, i));
      if (X < min_x) min_x = X;
      if (X > max_x) max_x = X;
    } /* for */
    /* test for monotonicity and constant step if the table is an XY or single vector */
    if (n > 1) {
      /* mean step */
      step = (max_x - min_x)/(n-1);
      /* now test if table is monotonic on first column, and get minimal step size */
      for (i=0; i < n-1; i++) {
        double X, diff;;
        X    = (row ? Table_Index(*Table,i  ,0)
                    : Table_Index(*Table,0,  i));
        diff = (row ? Table_Index(*Table,i+1,0)
                    : Table_Index(*Table,0,  i+1)) - X;
        if (fabs(diff) < fabs(step)) step = diff;
        /* change sign ? */
        if ((max_x - min_x)*diff < 0 && monotonic)
          monotonic = 0;
      } /* end for */
      /* now test if steps are constant within READ_TABLE_STEPTOL */
      if(!step){
        /*means there's a disconitnuity -> not constantstep*/
        constantstep=0;
      }else if (monotonic) {
        for (i=0; i < n-1; i++) {
          double X, diff;
          X    = (row ? Table_Index(*Table,i  ,0)
              : Table_Index(*Table,0,  i));
          diff = (row ? Table_Index(*Table,i+1,0)
              : Table_Index(*Table,0,  i+1)) - X;
          if ( fabs(step)*(1+READ_TABLE_STEPTOL) < fabs(diff) ||
                fabs(diff) < fabs(step)*(1-READ_TABLE_STEPTOL) )
          { constantstep = 0; break; }
        }
      }
    }
    Table->step_x= step;
    Table->max_x = max_x;
    Table->min_x = min_x;
    Table->monotonic = monotonic;
    Table->constantstep = constantstep;
  } /* end Table_Stat */

/******************************************************************************
* t_Table *Table_Read_Array(char *File, long *blocks)
*   ACTION: read as many data blocks as available, iteratively from file
*   return: initialized t_Table array, last element is an empty Table.
*           the number of extracted blocks in non NULL pointer *blocks
*******************************************************************************/
  t_Table *Table_Read_Array(char *File, long *blocks)
  {
    t_Table *Table_Array=NULL;
    long offset=0;
    long block_number=0;
    long allocated=256;
    long nelements=1;

    /* fisrt allocate an initial empty t_Table array */
    Table_Array = (t_Table *)malloc(allocated*sizeof(t_Table));
    if (!Table_Array) {
      fprintf(stderr, "Error: Can not allocate memory %li (Table_Read_Array).\n",
         allocated*sizeof(t_Table));
      *blocks = 0;
      return (NULL);
    }

    while (nelements > 0)
    {
      t_Table Table;

      /* access file at offset and get following block */
      nelements = Table_Read_Offset(&Table, File, 1, &offset,0);
      /* if ok, set t_Table block number else exit loop */
      block_number++;
      Table.block_number = block_number;
      /* if t_Table array is not long enough, expand and realocate */
      if (block_number >= allocated-1) {
        allocated += 256;
        Table_Array = (t_Table *)realloc(Table_Array,
           allocated*sizeof(t_Table));
        if (!Table_Array) {
          fprintf(stderr, "Error: Can not re-allocate memory %li (Table_Read_Array).\n",
              allocated*sizeof(t_Table));
          *blocks = 0;
          return (NULL);
        }
      }
      /* store it into t_Table array */
      sprintf(Table.filename, "%s#%li", File, block_number-1);
      Table_Array[block_number-1] = Table;
      /* continues until we find an empty block */
    }
    /* send back number of extracted blocks */
    if (blocks) *blocks = block_number-1;

    /* now store total number of elements in Table array */
    for (offset=0; offset < block_number;
      Table_Array[offset++].array_length = block_number-1);

    return(Table_Array);
  } /* end Table_Read_Array */
/*******************************************************************************
* void Table_Free_Array(t_Table *Table)
*   ACTION: free a Table array
*******************************************************************************/
  void Table_Free_Array(t_Table *Table)
  {
    long index=0;
    if (!Table) return;
    do {
        if (Table[index].data || Table[index].header)
          Table_Free(&Table[index]);
        else index=-1;
    } while (index>= 0);
    free(Table);
  } /* end Table_Free_Array */

/******************************************************************************
* long Table_Info_Array(t_Table *Table)
*    ACTION: print informations about a Table array
*    return: number of elements in the Table array
*******************************************************************************/
  long Table_Info_Array(t_Table *Table)
  {
    long index=0;

    if (!Table) return(-1);
    while (index < Table[index].array_length
       && (Table[index].data || Table[index].header)
       && (Table[index].rows*Table[index].columns) ) {
      Table_Info(Table[index]);
      index++;
    }
    printf("This Table array contains %li elements\n", index);
    return(index);
  } /* end Table_Info_Array */

/******************************************************************************
* char **Table_ParseHeader(char *header, symbol1, symbol2, ..., NULL)
*    ACTION: search for char* symbols in header and return their value or NULL
*            Last argument MUST be NULL
*    return: array of char* with line following each symbol, or NULL if not found
*******************************************************************************/
#ifndef MyNL_ARGMAX
#define MyNL_ARGMAX 50
#endif

char **Table_ParseHeader_backend(char *header, ...){
  va_list ap;
  char exit_flag=0;
  int counter   =0;
  char **ret    =NULL;
  if (!header || header[0]=='\0') return(NULL);

  ret = (char**)calloc(MyNL_ARGMAX, sizeof(char*));
  if (!ret) {
    printf("Table_ParseHeader: Cannot allocate %i values array for Parser (Table_ParseHeader).\n",
      MyNL_ARGMAX);
    return(NULL);
  }
  for (counter=0; counter < MyNL_ARGMAX; ret[counter++] = NULL);
  counter=0;

  va_start(ap, header);
  while(!exit_flag && counter < MyNL_ARGMAX-1)
  {
    char *arg_char=NULL;
    char *pos     =NULL;
    /* get variable argument value as a char */
    arg_char = va_arg(ap, char *);
    if (!arg_char || arg_char[0]=='\0'){
      exit_flag = 1; break;
    }
    /* search for the symbol in the header */
    pos = strstr(header, arg_char);
    if (pos) {
      char *eol_pos;
      eol_pos = strchr(pos+strlen(arg_char), '\n');
      if (!eol_pos)
        eol_pos = strchr(pos+strlen(arg_char), '\r');
      if (!eol_pos)
        eol_pos = pos+strlen(pos)-1;
      ret[counter] = (char*)malloc(eol_pos - pos);
      if (!ret[counter]) {
        printf("Table_ParseHeader: Cannot allocate value[%i] array for Parser searching for %s (Table_ParseHeader).\n",
          counter, arg_char);
        exit_flag = 1; break;
      }
      strncpy(ret[counter], pos+strlen(arg_char), eol_pos - pos - strlen(arg_char));
      ret[counter][eol_pos - pos - strlen(arg_char)]='\0';
    }
    counter++;
  }
  va_end(ap);
  return(ret);
} /* Table_ParseHeader */

/******************************************************************************
* double Table_Interp1d(x, x1, y1, x2, y2)
*    ACTION: interpolates linearly at x between y1=f(x1) and y2=f(x2)
*    return: y=f(x) value
*******************************************************************************/
double Table_Interp1d(double x,
  double x1, double y1,
  double x2, double y2)
{
  double slope;
  if (x2 == x1) return (y1+y2)/2;
  if (y1 == y2) return  y1;
  slope = (y2 - y1)/(x2 - x1);
  return y1+slope*(x - x1);
} /* Table_Interp1d */

/******************************************************************************
* double Table_Interp1d_nearest(x, x1, y1, x2, y2)
*    ACTION: table lookup with nearest method at x between y1=f(x1) and y2=f(x2)
*    return: y=f(x) value
*******************************************************************************/
double Table_Interp1d_nearest(double x,
  double x1, double y1,
  double x2, double y2)
{
  if (fabs(x-x1) < fabs(x-x2)) return (y1);
  else return(y2);
} /* Table_Interp1d_nearest */

/******************************************************************************
* double Table_Interp2d(x,y, x1,y1, x2,y2, z11,z12,z21,z22)
*    ACTION: interpolates bi-linearly at (x,y) between z1=f(x1,y1) and z2=f(x2,y2)
*    return: z=f(x,y) value
*    x,y |   x1   x2
*    ----------------
*     y1 |   z11  z21
*     y2 |   z12  z22
*******************************************************************************/
double Table_Interp2d(double x, double y,
  double x1, double y1,
  double x2, double y2,
  double z11, double z12, double z21, double z22)
{
  double ratio_x, ratio_y;
  if (x2 == x1) return Table_Interp1d(y, y1,z11, y2,z12);
  if (y1 == y2) return Table_Interp1d(x, x1,z11, x2,z21);

  ratio_y = (y - y1)/(y2 - y1);
  ratio_x = (x - x1)/(x2 - x1);
  return (1-ratio_x)*(1-ratio_y)*z11 + ratio_x*(1-ratio_y)*z21
    + ratio_x*ratio_y*z22         + (1-ratio_x)*ratio_y*z12;
} /* Table_Interp2d */

/* end of read_table-lib.c */

#line 8025 "/Users/pengfei/github/Monte_Carlo/single_slit.c"

/* Instrument parameters. */
MCNUM mcipPar1;

#define mcNUMIPAR 1
int mcnumipar = 1;
struct mcinputtable_struct mcinputtable[mcNUMIPAR+1] = {
  "Par1", &mcipPar1, instr_type_double, "1", 
  NULL, NULL, instr_type_double, ""
};

/* User declarations from instrument definition. */
#define mccompcurname  test
#define mccompcurtype  INSTRUMENT
#define mccompcurindex 0
#define mcposatest coords_set(0,0,0)
#define Par1 mcipPar1
#undef Par1
#undef mcposatest
#undef mccompcurindex
#undef mccompcurtype
#undef mccompcurname

/* xray state table at each component input (local coords) */
/* [x, y, z, kx, ky, kz, phi, t, Ex, Ey, Ez, p] */
MCNUM mccomp_storein[12*6];
/* Components position table (absolute and relative coords) */
Coords mccomp_posa[6];
Coords mccomp_posr[6];
/* Counter for each comp to check for inactive ones */
MCNUM  mcNCounter[6];
MCNUM  mcPCounter[6];
MCNUM  mcP2Counter[6];
#define mcNUMCOMP 5 /* number of components */
/* Counter for PROP ABSORB */
MCNUM  mcAbsorbProp[6];
/* Flag true when previous component acted on the xray (SCATTER) */
MCNUM mcScattered=0;
/* Declarations of component definition and setting parameters. */

/* Definition parameters for component 'Origin' [1]. */
#define mccOrigin_profile 0 /* declared as a string. May produce warnings at compile */
/* Setting parameters for component 'Origin' [1]. */
MCNUM mccOrigin_percent;
MCNUM mccOrigin_flag_save;
MCNUM mccOrigin_minutes;

/* Definition parameters for component 'point1' [2]. */
#define mccpoint1_spectrum_file NULL /* declared as a string. May produce warnings at compile */
/* Setting parameters for component 'point1' [2]. */
MCNUM mccpoint1_focus_xw;
MCNUM mccpoint1_focus_yh;
MCNUM mccpoint1_flux;
MCNUM mccpoint1_dist;
MCNUM mccpoint1_gamma;
MCNUM mccpoint1_E0;
MCNUM mccpoint1_dE;
MCNUM mccpoint1_lambda0;
MCNUM mccpoint1_dlambda;
MCNUM mccpoint1_phase;
MCNUM mccpoint1_randomphase;
MCNUM mccpoint1_gauss;

/* Setting parameters for component 'slit' [3]. */
MCNUM mccslit_xmin;
MCNUM mccslit_xmax;
MCNUM mccslit_ymin;
MCNUM mccslit_ymax;
MCNUM mccslit_radius;
MCNUM mccslit_cut;
MCNUM mccslit_xwidth;
MCNUM mccslit_yheight;
MCNUM mccslit_dist;
MCNUM mccslit_focus_xw;
MCNUM mccslit_focus_yh;
MCNUM mccslit_focus_x0;
MCNUM mccslit_focus_y0;

/* Definition parameters for component 'cor' [4]. */
#define mcccor_nx 700
#define mcccor_ny 700
/* Setting parameters for component 'cor' [4]. */
char mcccor_filename[16384];
MCNUM mcccor_restore_xray;
MCNUM mcccor_xmin;
MCNUM mcccor_xmax;
MCNUM mcccor_ymin;
MCNUM mcccor_ymax;
MCNUM mcccor_xwidth;
MCNUM mcccor_yheight;

/* User component declarations. */

/* User declarations for component 'Origin' [1]. */
#define mccompcurname  Origin
#define mccompcurtype  Progress_bar
#define mccompcurindex 1
#define profile mccOrigin_profile
#define IntermediateCnts mccOrigin_IntermediateCnts
#define StartTime mccOrigin_StartTime
#define EndTime mccOrigin_EndTime
#define percent mccOrigin_percent
#define flag_save mccOrigin_flag_save
#define minutes mccOrigin_minutes
#line 50 "/usr/local/lib/mcxtrace-1.1/misc/Progress_bar.comp"
#ifndef PROGRESS_BAR
#define PROGRESS_BAR
#else
#error Only one Progress_bar component may be used in an instrument definition.
#endif

  double IntermediateCnts=0;
  time_t StartTime       =0;
  time_t EndTime         =0;
  time_t CurrentTime     =0;
#line 8141 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
#undef minutes
#undef flag_save
#undef percent
#undef EndTime
#undef StartTime
#undef IntermediateCnts
#undef profile
#undef mccompcurname
#undef mccompcurtype
#undef mccompcurindex

/* User declarations for component 'point1' [2]. */
#define mccompcurname  point1
#define mccompcurtype  Source_pt
#define mccompcurindex 2
#define spectrum_file mccpoint1_spectrum_file
#define prms mccpoint1_prms
#define focus_xw mccpoint1_focus_xw
#define focus_yh mccpoint1_focus_yh
#define flux mccpoint1_flux
#define dist mccpoint1_dist
#define gamma mccpoint1_gamma
#define E0 mccpoint1_E0
#define dE mccpoint1_dE
#define lambda0 mccpoint1_lambda0
#define dlambda mccpoint1_dlambda
#define phase mccpoint1_phase
#define randomphase mccpoint1_randomphase
#define gauss mccpoint1_gauss
#line 57 "/usr/local/lib/mcxtrace-1.1/sources/Source_pt.comp"
  double e,l;
  struct {
    double l0,dl;
    double pmul,pint;
    t_Table T;
  } prms;

#line 8179 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
#undef gauss
#undef randomphase
#undef phase
#undef dlambda
#undef lambda0
#undef dE
#undef E0
#undef gamma
#undef dist
#undef flux
#undef focus_yh
#undef focus_xw
#undef prms
#undef spectrum_file
#undef mccompcurname
#undef mccompcurtype
#undef mccompcurindex

/* User declarations for component 'slit' [3]. */
#define mccompcurname  slit
#define mccompcurtype  Slit
#define mccompcurindex 3
#define xmin mccslit_xmin
#define xmax mccslit_xmax
#define ymin mccslit_ymin
#define ymax mccslit_ymax
#define radius mccslit_radius
#define cut mccslit_cut
#define xwidth mccslit_xwidth
#define yheight mccslit_yheight
#define dist mccslit_dist
#define focus_xw mccslit_focus_xw
#define focus_yh mccslit_focus_yh
#define focus_x0 mccslit_focus_x0
#define focus_y0 mccslit_focus_y0
#undef focus_y0
#undef focus_x0
#undef focus_yh
#undef focus_xw
#undef dist
#undef yheight
#undef xwidth
#undef cut
#undef radius
#undef ymax
#undef ymin
#undef xmax
#undef xmin
#undef mccompcurname
#undef mccompcurtype
#undef mccompcurindex

/* User declarations for component 'cor' [4]. */
#define mccompcurname  cor
#define mccompcurtype  PSD_monitor_coh
#define mccompcurindex 4
#define nx mcccor_nx
#define ny mcccor_ny
#define PSD_N mcccor_PSD_N
#define PSD_p mcccor_PSD_p
#define PSD_p2 mcccor_PSD_p2
#define PSD_phi mcccor_PSD_phi
#define filename mcccor_filename
#define restore_xray mcccor_restore_xray
#define xmin mcccor_xmin
#define xmax mcccor_xmax
#define ymin mcccor_ymin
#define ymax mcccor_ymax
#define xwidth mcccor_xwidth
#define yheight mcccor_yheight
#line 56 "/usr/local/lib/mcxtrace-1.1/monitors/PSD_monitor_coh.comp"
#include <complex.h>
    double PSD_N[nx][ny];
    complex double PSD_phi[nx][ny];
    double PSD_p[nx][ny];
    double PSD_p2[nx][ny];
#line 8256 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
#undef yheight
#undef xwidth
#undef ymax
#undef ymin
#undef xmax
#undef xmin
#undef restore_xray
#undef filename
#undef PSD_phi
#undef PSD_p2
#undef PSD_p
#undef PSD_N
#undef ny
#undef nx
#undef mccompcurname
#undef mccompcurtype
#undef mccompcurindex

Coords mcposaOrigin, mcposrOrigin;
Rotation mcrotaOrigin, mcrotrOrigin;
Coords mcposapoint1, mcposrpoint1;
Rotation mcrotapoint1, mcrotrpoint1;
Coords mcposaslit, mcposrslit;
Rotation mcrotaslit, mcrotrslit;
Coords mcposacor, mcposrcor;
Rotation mcrotacor, mcrotrcor;

MCNUM mcnx, mcny, mcnz, mcnkx, mcnky, mcnkz, mcnphi, mcnt, mcnEx, mcnEy, mcnEz, mcnp;

/* end declare */

void mcinit(void) {
#define mccompcurname  test
#define mccompcurtype  INSTRUMENT
#define mccompcurindex 0
#define mcposatest coords_set(0,0,0)
#define Par1 mcipPar1
#undef Par1
#undef mcposatest
#undef mccompcurindex
#undef mccompcurtype
#undef mccompcurname
  /* Computation of coordinate transformations. */
  {
    Coords mctc1, mctc2;
    Rotation mctr1;

    mcDEBUG_INSTR()
  /* Component initializations. */
    /* Component Origin. */
    SIG_MESSAGE("Origin (Init:Place/Rotate)");
    rot_set_rotation(mcrotaOrigin,
      (0.0)*DEG2RAD,
      (0.0)*DEG2RAD,
      (0.0)*DEG2RAD);
#line 8312 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
    rot_copy(mcrotrOrigin, mcrotaOrigin);
    mcposaOrigin = coords_set(
#line 50 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
      0,
#line 50 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
      0,
#line 50 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
      0);
#line 8321 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
    mctc1 = coords_neg(mcposaOrigin);
    mcposrOrigin = rot_apply(mcrotaOrigin, mctc1);
    mcDEBUG_COMPONENT("Origin", mcposaOrigin, mcrotaOrigin)
    mccomp_posa[1] = mcposaOrigin;
    mccomp_posr[1] = mcposrOrigin;
    mcNCounter[1]  = mcPCounter[1] = mcP2Counter[1] = 0;
    mcAbsorbProp[1]= 0;
  /* Setting parameters for component Origin. */
  SIG_MESSAGE("Origin (Init:SetPar)");
#line 44 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccOrigin_percent = 10;
#line 44 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccOrigin_flag_save = 0;
#line 44 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccOrigin_minutes = 0;
#line 8337 "/Users/pengfei/github/Monte_Carlo/single_slit.c"

    /* Component point1. */
    SIG_MESSAGE("point1 (Init:Place/Rotate)");
    rot_set_rotation(mctr1,
      (0.0)*DEG2RAD,
      (0.0)*DEG2RAD,
      (0.0)*DEG2RAD);
#line 8345 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
    rot_mul(mctr1, mcrotaOrigin, mcrotapoint1);
    rot_transpose(mcrotaOrigin, mctr1);
    rot_mul(mcrotapoint1, mctr1, mcrotrpoint1);
    mctc1 = coords_set(
#line 56 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
      0,
#line 56 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
      0,
#line 56 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
      0);
#line 8356 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
    rot_transpose(mcrotaOrigin, mctr1);
    mctc2 = rot_apply(mctr1, mctc1);
    mcposapoint1 = coords_add(mcposaOrigin, mctc2);
    mctc1 = coords_sub(mcposaOrigin, mcposapoint1);
    mcposrpoint1 = rot_apply(mcrotapoint1, mctc1);
    mcDEBUG_COMPONENT("point1", mcposapoint1, mcrotapoint1)
    mccomp_posa[2] = mcposapoint1;
    mccomp_posr[2] = mcposrpoint1;
    mcNCounter[2]  = mcPCounter[2] = mcP2Counter[2] = 0;
    mcAbsorbProp[2]= 0;
  /* Setting parameters for component point1. */
  SIG_MESSAGE("point1 (Init:SetPar)");
#line 55 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccpoint1_focus_xw = 0.01;
#line 55 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccpoint1_focus_yh = 0.01;
#line 45 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccpoint1_flux = 0;
#line 55 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccpoint1_dist = 0.024;
#line 45 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccpoint1_gamma = 0;
#line 55 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccpoint1_E0 = 0.0025;
#line 45 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccpoint1_dE = 0;
#line 45 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccpoint1_lambda0 = 0;
#line 45 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccpoint1_dlambda = 0;
#line 45 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccpoint1_phase = -1;
#line 45 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccpoint1_randomphase = 0;
#line 45 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccpoint1_gauss = 0;
#line 8393 "/Users/pengfei/github/Monte_Carlo/single_slit.c"

    /* Component slit. */
    SIG_MESSAGE("slit (Init:Place/Rotate)");
    rot_set_rotation(mctr1,
      (0.0)*DEG2RAD,
      (0.0)*DEG2RAD,
      (0.0)*DEG2RAD);
#line 8401 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
    rot_mul(mctr1, mcrotaOrigin, mcrotaslit);
    rot_transpose(mcrotapoint1, mctr1);
    rot_mul(mcrotaslit, mctr1, mcrotrslit);
    mctc1 = coords_set(
#line 61 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
      0,
#line 61 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
      0,
#line 61 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
      0.002);
#line 8412 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
    rot_transpose(mcrotaOrigin, mctr1);
    mctc2 = rot_apply(mctr1, mctc1);
    mcposaslit = coords_add(mcposaOrigin, mctc2);
    mctc1 = coords_sub(mcposapoint1, mcposaslit);
    mcposrslit = rot_apply(mcrotaslit, mctc1);
    mcDEBUG_COMPONENT("slit", mcposaslit, mcrotaslit)
    mccomp_posa[3] = mcposaslit;
    mccomp_posr[3] = mcposrslit;
    mcNCounter[3]  = mcPCounter[3] = mcP2Counter[3] = 0;
    mcAbsorbProp[3]= 0;
  /* Setting parameters for component slit. */
  SIG_MESSAGE("slit (Init:SetPar)");
#line 50 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccslit_xmin = -0.01;
#line 50 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccslit_xmax = 0.01;
#line 50 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccslit_ymin = -0.01;
#line 50 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccslit_ymax = 0.01;
#line 50 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccslit_radius = 0;
#line 51 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccslit_cut = 0;
#line 60 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccslit_xwidth = 0.1;
#line 60 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccslit_yheight = 0.1;
#line 51 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccslit_dist = 0;
#line 51 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccslit_focus_xw = 0;
#line 51 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccslit_focus_yh = 0;
#line 51 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccslit_focus_x0 = 0;
#line 51 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mccslit_focus_y0 = 0;
#line 8451 "/Users/pengfei/github/Monte_Carlo/single_slit.c"

    /* Component cor. */
    SIG_MESSAGE("cor (Init:Place/Rotate)");
    rot_set_rotation(mctr1,
      (0.0)*DEG2RAD,
      (0.0)*DEG2RAD,
      (0.0)*DEG2RAD);
#line 8459 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
    rot_mul(mctr1, mcrotaslit, mcrotacor);
    rot_transpose(mcrotaslit, mctr1);
    rot_mul(mcrotacor, mctr1, mcrotrcor);
    mctc1 = coords_set(
#line 66 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
      0,
#line 66 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
      0,
#line 66 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
      0.02);
#line 8470 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
    rot_transpose(mcrotaslit, mctr1);
    mctc2 = rot_apply(mctr1, mctc1);
    mcposacor = coords_add(mcposaslit, mctc2);
    mctc1 = coords_sub(mcposaslit, mcposacor);
    mcposrcor = rot_apply(mcrotacor, mctc1);
    mcDEBUG_COMPONENT("cor", mcposacor, mcrotacor)
    mccomp_posa[4] = mcposacor;
    mccomp_posr[4] = mcposrcor;
    mcNCounter[4]  = mcPCounter[4] = mcP2Counter[4] = 0;
    mcAbsorbProp[4]= 0;
  /* Setting parameters for component cor. */
  SIG_MESSAGE("cor (Init:SetPar)");
#line 64 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  if("corhen") strncpy(mcccor_filename,"corhen", 16384); else mcccor_filename[0]='\0';
#line 50 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mcccor_restore_xray = 0;
#line 50 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mcccor_xmin = -0.05;
#line 50 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mcccor_xmax = 0.05;
#line 50 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mcccor_ymin = -0.05;
#line 50 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mcccor_ymax = 0.05;
#line 64 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mcccor_xwidth = 0.008;
#line 65 "/Users/pengfei/github/Monte_Carlo/single_slit.instr"
  mcccor_yheight = 0.008;
#line 8499 "/Users/pengfei/github/Monte_Carlo/single_slit.c"

  /* Component initializations. */
  /* Initializations for component Origin. */
  SIG_MESSAGE("Origin (Init)");
#define mccompcurname  Origin
#define mccompcurtype  Progress_bar
#define mccompcurindex 1
#define profile mccOrigin_profile
#define IntermediateCnts mccOrigin_IntermediateCnts
#define StartTime mccOrigin_StartTime
#define EndTime mccOrigin_EndTime
#define percent mccOrigin_percent
#define flag_save mccOrigin_flag_save
#define minutes mccOrigin_minutes
#line 63 "/usr/local/lib/mcxtrace-1.1/misc/Progress_bar.comp"
{
  fprintf(stdout, "[%s] Initialize\n", mcinstrument_name);
  if (percent*mcget_ncount()/100 < 1e5) {
    percent=1e5*100.0/mcget_ncount();
  }
}
#line 8521 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
#undef minutes
#undef flag_save
#undef percent
#undef EndTime
#undef StartTime
#undef IntermediateCnts
#undef profile
#undef mccompcurname
#undef mccompcurtype
#undef mccompcurindex

  /* Initializations for component point1. */
  SIG_MESSAGE("point1 (Init)");
#define mccompcurname  point1
#define mccompcurtype  Source_pt
#define mccompcurindex 2
#define spectrum_file mccpoint1_spectrum_file
#define prms mccpoint1_prms
#define focus_xw mccpoint1_focus_xw
#define focus_yh mccpoint1_focus_yh
#define flux mccpoint1_flux
#define dist mccpoint1_dist
#define gamma mccpoint1_gamma
#define E0 mccpoint1_E0
#define dE mccpoint1_dE
#define lambda0 mccpoint1_lambda0
#define dlambda mccpoint1_dlambda
#define phase mccpoint1_phase
#define randomphase mccpoint1_randomphase
#define gauss mccpoint1_gauss
#line 67 "/usr/local/lib/mcxtrace-1.1/sources/Source_pt.comp"
{
  double fi_x,fi_y,t_ome;
  /*input logic*/
  if(dist<=0 || focus_yh<=0 || focus_xw<=0){
    fprintf(stderr,"Source_pt (%s): Error: Target area unmeaningful! (negative dist / focus_xw / focus_yh)\n",
           NAME_CURRENT_COMP);
    exit(0);
  }
  fi_x=atan(focus_xw/2.0/dist);
  fi_y=atan(focus_yh/2.0/dist);
  
  /*fractional solid angle subtended by the target*/
  t_ome=asin(sin(fi_y)*sin(fi_x))/M_PI;
  
  if (spectrum_file){
    /*read spectrum from file*/
    int status=0;
    if ( (status=Table_Read(&(prms.T),spectrum_file,0))==-1){
      fprintf(stderr,"Source_pt(%s) Error: Could not parse file \"%s\"\n",NAME_CURRENT_COMP,spectrum_file?spectrum_file:"");
      exit(-1);
    }
    /*data is now in table prms.T*/
    /*integrate to get total flux, assuming numbers have been corrected for measuring aperture*/
    int i;
    prms.pint=0;
    t_Table *T=&(prms.T);
    for (i=0;i<prms.T.rows-1;i++){
      prms.pint+=((T->data[i*T->columns+1]+T->data[(i+1)*T->columns+1])/2.0)*(T->data[(i+1)*T->columns]-T->data[i*T->columns]); 
    }
    printf("Source_pt(%s) Integrated intensity radiated is %g pht/s\n",NAME_CURRENT_COMP,prms.pint);
    if(E0) printf("Source_pt(%s) E0!=0 -> assuming intensity spectrum is parametrized by energy [keV]\n",NAME_CURRENT_COMP);
  } else if (!E0 && !lambda0){
    fprintf(stderr,"Error(%s): Must specify either wavelength or energy distribution\n",NAME_CURRENT_COMP);
    exit(1);
  }

  if(phase) printf("got phase %g from outside\n",phase);
  /*calculate the X-ray weight from the flux*/
  if (flux){
    prms.pmul=flux;
  }else{
    prms.pmul=1;
  }
  prms.pmul*=t_ome/(double)mcget_ncount();
}
#line 8598 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
#undef gauss
#undef randomphase
#undef phase
#undef dlambda
#undef lambda0
#undef dE
#undef E0
#undef gamma
#undef dist
#undef flux
#undef focus_yh
#undef focus_xw
#undef prms
#undef spectrum_file
#undef mccompcurname
#undef mccompcurtype
#undef mccompcurindex

  /* Initializations for component slit. */
  SIG_MESSAGE("slit (Init)");
#define mccompcurname  slit
#define mccompcurtype  Slit
#define mccompcurindex 3
#define xmin mccslit_xmin
#define xmax mccslit_xmax
#define ymin mccslit_ymin
#define ymax mccslit_ymax
#define radius mccslit_radius
#define cut mccslit_cut
#define xwidth mccslit_xwidth
#define yheight mccslit_yheight
#define dist mccslit_dist
#define focus_xw mccslit_focus_xw
#define focus_yh mccslit_focus_yh
#define focus_x0 mccslit_focus_x0
#define focus_y0 mccslit_focus_y0
#line 57 "/usr/local/lib/mcxtrace-1.1/optics/Slit.comp"
{
  if (xwidth)  { xmax=xwidth/2;  xmin=-xmax; }
  if (yheight) { ymax=yheight/2; ymin=-ymax; }
  if (xmin == 0 && xmax == 0 && ymin == 0 && ymax == 0 && radius == 0)
    { fprintf(stderr,"Slit: %s: Error: give geometry\n", NAME_CURRENT_COMP); exit(-1); }

  if ( (focus_xw || focus_yh || dist) && !( focus_xw && focus_yh && dist) ){
    fprintf(stderr,"Error (%s): Inconsistent target definition\n",NAME_CURRENT_COMP);
    exit(-1);
  }

}
#line 8648 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
#undef focus_y0
#undef focus_x0
#undef focus_yh
#undef focus_xw
#undef dist
#undef yheight
#undef xwidth
#undef cut
#undef radius
#undef ymax
#undef ymin
#undef xmax
#undef xmin
#undef mccompcurname
#undef mccompcurtype
#undef mccompcurindex

  /* Initializations for component cor. */
  SIG_MESSAGE("cor (Init)");
#define mccompcurname  cor
#define mccompcurtype  PSD_monitor_coh
#define mccompcurindex 4
#define nx mcccor_nx
#define ny mcccor_ny
#define PSD_N mcccor_PSD_N
#define PSD_p mcccor_PSD_p
#define PSD_p2 mcccor_PSD_p2
#define PSD_phi mcccor_PSD_phi
#define filename mcccor_filename
#define restore_xray mcccor_restore_xray
#define xmin mcccor_xmin
#define xmax mcccor_xmax
#define ymin mcccor_ymin
#define ymax mcccor_ymax
#define xwidth mcccor_xwidth
#define yheight mcccor_yheight
#line 63 "/usr/local/lib/mcxtrace-1.1/monitors/PSD_monitor_coh.comp"
{
    int i,j;

    if (xwidth  > 0) { xmax = xwidth/2;  xmin = -xmax; }
    if (yheight > 0) { ymax = yheight/2; ymin = -ymax; }

    if ((xmin >= xmax) || (ymin >= ymax)) {
            printf("PSD_monitor: %s: Null detection area !\n"
                   "ERROR        (xwidth,yheight,xmin,xmax,ymin,ymax). Exiting",
           NAME_CURRENT_COMP);
      exit(0);
    }

    for (i=0; i<nx; i++){
      memset(PSD_N[i],0,sizeof(long long)*ny);
      memset(PSD_phi[i],0,sizeof(complex double)*ny);
      memset(PSD_p[i],0,sizeof(double)*ny);
      memset(PSD_p2[i],0,sizeof(double)*ny);
    }

}
#line 8707 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
#undef yheight
#undef xwidth
#undef ymax
#undef ymin
#undef xmax
#undef xmin
#undef restore_xray
#undef filename
#undef PSD_phi
#undef PSD_p2
#undef PSD_p
#undef PSD_N
#undef ny
#undef nx
#undef mccompcurname
#undef mccompcurtype
#undef mccompcurindex

    if(mcdotrace) mcdisplay();
    mcDEBUG_INSTR_END()
  }

/* NeXus support */

#ifdef USE_NEXUS

strncmp(mcnxversion,"5 zip",128);

#endif

} /* end init */

void mcraytrace(void) {
  /* Copy xray state to local variables. */
  MCNUM mcnlx = mcnx;
  MCNUM mcnly = mcny;
  MCNUM mcnlz = mcnz;
  MCNUM mcnlkx = mcnkx;
  MCNUM mcnlky = mcnky;
  MCNUM mcnlkz = mcnkz;
  MCNUM mcnlphi = mcnphi;
  MCNUM mcnlt = mcnt;
  MCNUM mcnlEx = mcnEx;
  MCNUM mcnlEy = mcnEy;
  MCNUM mcnlEz = mcnEz;
  MCNUM mcnlp = mcnp;

  mcDEBUG_ENTER()
  mcDEBUG_STATE(
    mcnlx,
    mcnly,
    mcnlz,
    mcnlkx,
    mcnlky,
    mcnlkz,
    mcnlphi,
    mcnlt,
    mcnlEx,
    mcnlEy,
    mcnlEz,
    mcnlp)
#define mcabsorb mcabsorbAll
  /* TRACE Component Origin [1] */
  mccoordschange(mcposrOrigin, mcrotrOrigin,
    &mcnlx,
    &mcnly,
    &mcnlz,
    &mcnlkx,
    &mcnlky,
    &mcnlkz,
    &mcnlEx,
    &mcnlEy,
    &mcnlEz);
  /* define label inside component Origin (without coords transformations) */
  mcJumpTrace_Origin:
  SIG_MESSAGE("Origin (Trace)");
  mcDEBUG_COMP("Origin")
  mcDEBUG_STATE(
    mcnlx,
    mcnly,
    mcnlz,
    mcnlkx,
    mcnlky,
    mcnlkz,
    mcnlphi,
    mcnlt,
    mcnlEx,
    mcnlEy,
    mcnlEz,
    mcnlp)
#define x mcnlx
#define y mcnly
#define z mcnlz
#define kx mcnlkx
#define ky mcnlky
#define kz mcnlkz
#define phi mcnlphi
#define t mcnlt
#define Ex mcnlEx
#define Ey mcnlEy
#define Ez mcnlEz
#define p mcnlp
  STORE_XRAY(1,
    mcnlx,
    mcnly,
    mcnlz,
    mcnlkx,
    mcnlky,
    mcnlkz,
    mcnlphi,
    mcnlt,
    mcnlEx,
    mcnlEy,
    mcnlEz,
    mcnlp);
  mcScattered=0;
  mcNCounter[1]++;
  mcPCounter[1] += p;
  mcP2Counter[1] += p*p;
#define mccompcurname  Origin
#define mccompcurtype  Progress_bar
#define mccompcurindex 1
#define profile mccOrigin_profile
#define IntermediateCnts mccOrigin_IntermediateCnts
#define StartTime mccOrigin_StartTime
#define EndTime mccOrigin_EndTime
{   /* Declarations of Origin=Progress_bar() SETTING parameters. */
MCNUM percent = mccOrigin_percent;
MCNUM flag_save = mccOrigin_flag_save;
MCNUM minutes = mccOrigin_minutes;
#line 71 "/usr/local/lib/mcxtrace-1.1/misc/Progress_bar.comp"
{
  double ncount;
  ncount = mcget_run_num();
  if (!StartTime) {
    time(&StartTime); /* compute starting time */
    IntermediateCnts = 1e3;
  }
  time_t NowTime;
  time(&NowTime);
  if (!EndTime && ncount >= IntermediateCnts) {
    CurrentTime = NowTime;
    if (difftime(NowTime,StartTime) > 10) { /* wait 10 sec before writing ETA */
      EndTime = StartTime + (time_t)(difftime(NowTime,StartTime)
				     *(double)mcget_ncount()/ncount);
      IntermediateCnts = 0;
      fprintf(stdout, "\nTrace ETA ");
      if (difftime(EndTime,StartTime) < 60.0)
        fprintf(stdout, "%g [s] %% ", difftime(EndTime,StartTime));
      else if (difftime(EndTime,StartTime) > 3600.0)
        fprintf(stdout, "%g [h] %% ", difftime(EndTime,StartTime)/3600.0);
      else
        fprintf(stdout, "%g [min] %% ", difftime(EndTime,StartTime)/60.0);
    } else IntermediateCnts += 1e3;
    fflush(stdout);
  }

  if (EndTime &&
    (    (minutes && difftime(NowTime,CurrentTime) > minutes*60)
      || (percent && !minutes && ncount >= IntermediateCnts))   )
  {
    fprintf(stdout, "%d ", (int)(ncount*100/mcget_ncount())); fflush(stdout);
    CurrentTime = NowTime;
    IntermediateCnts = ncount + percent*mcget_ncount()/100;
    if (IntermediateCnts >= mcget_ncount()) fprintf(stdout, "\n");
    if (flag_save) mcsave(NULL);
  }
}
#line 8872 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
}   /* End of Origin=Progress_bar() SETTING parameter declarations. */
#undef EndTime
#undef StartTime
#undef IntermediateCnts
#undef profile
#undef mccompcurname
#undef mccompcurtype
#undef mccompcurindex
#undef p
#undef Ez
#undef Ey
#undef Ex
#undef t
#undef phi
#undef kz
#undef ky
#undef kx
#undef z
#undef y
#undef x
  mcDEBUG_STATE(
mcnlx,
mcnly,
mcnlz,
mcnlkx,
mcnlky,
mcnlkz,
mcnlphi,
mcnlt,
mcnlEx,
mcnlEy,
mcnlEz,
mcnlp)

  /* TRACE Component point1 [2] */
  mccoordschange(mcposrpoint1, mcrotrpoint1,
    &mcnlx,
    &mcnly,
    &mcnlz,
    &mcnlkx,
    &mcnlky,
    &mcnlkz,
    &mcnlEx,
    &mcnlEy,
    &mcnlEz);
  /* define label inside component point1 (without coords transformations) */
  mcJumpTrace_point1:
  SIG_MESSAGE("point1 (Trace)");
  mcDEBUG_COMP("point1")
  mcDEBUG_STATE(
    mcnlx,
    mcnly,
    mcnlz,
    mcnlkx,
    mcnlky,
    mcnlkz,
    mcnlphi,
    mcnlt,
    mcnlEx,
    mcnlEy,
    mcnlEz,
    mcnlp)
#define x mcnlx
#define y mcnly
#define z mcnlz
#define kx mcnlkx
#define ky mcnlky
#define kz mcnlkz
#define phi mcnlphi
#define t mcnlt
#define Ex mcnlEx
#define Ey mcnlEy
#define Ez mcnlEz
#define p mcnlp
  STORE_XRAY(2,
    mcnlx,
    mcnly,
    mcnlz,
    mcnlkx,
    mcnlky,
    mcnlkz,
    mcnlphi,
    mcnlt,
    mcnlEx,
    mcnlEy,
    mcnlEz,
    mcnlp);
  mcScattered=0;
  mcNCounter[2]++;
  mcPCounter[2] += p;
  mcP2Counter[2] += p*p;
#define mccompcurname  point1
#define mccompcurtype  Source_pt
#define mccompcurindex 2
#define spectrum_file mccpoint1_spectrum_file
#define prms mccpoint1_prms
{   /* Declarations of point1=Source_pt() SETTING parameters. */
MCNUM focus_xw = mccpoint1_focus_xw;
MCNUM focus_yh = mccpoint1_focus_yh;
MCNUM flux = mccpoint1_flux;
MCNUM dist = mccpoint1_dist;
MCNUM gamma = mccpoint1_gamma;
MCNUM E0 = mccpoint1_E0;
MCNUM dE = mccpoint1_dE;
MCNUM lambda0 = mccpoint1_lambda0;
MCNUM dlambda = mccpoint1_dlambda;
MCNUM phase = mccpoint1_phase;
MCNUM randomphase = mccpoint1_randomphase;
MCNUM gauss = mccpoint1_gauss;
#line 114 "/usr/local/lib/mcxtrace-1.1/sources/Source_pt.comp"
{
  double k,l,e;
  /*point source*/
  p=prms.pmul;
  x=0;y=0;z=0;
 
  /*draw random coordinates in the acceptance window*/
  kx= (focus_xw/2.0 * randpm1());
  ky= (focus_yh/2.0 * randpm1());
  kz= dist;
  NORM(kx,ky,kz);  
  /*sample wavelength*/
  if (spectrum_file){
    double pp=0;
    //while (pp<=0){ 
    l=prms.T.data[0]+ (prms.T.data[(prms.T.rows-1)*prms.T.columns] -prms.T.data[0])*rand01();
    pp=Table_Value(prms.T,l,1);
    //}
    p*=pp;
    /*if E0!=0 the tabled value is assumed to be energy in keV*/
    if (E0!=0){
      k=E2K*l;
    }else{
      k=(2*M_PI/l);
    }
  }else if (E0){
    if(!dE){
      e=E0;
    }else if (gauss){
      e=E0+dE*randnorm();
    }else{
      e=randpm1()*dE*0.5 + E0;
    }
    k=E2K*e;
  }else if (lambda0){
    if (!dlambda){
      l=lambda0;
    }else if (gauss){
      l=lambda0+dlambda*randnorm();
    }else{
      l=randpm1()*dlambda*0.5 + lambda0;
    }
    k=(2*M_PI/l);
  }
  kx*=k;
  ky*=k;
  kz*=k;
  
  /*randomly pick phase or set to something real*/
  if (randomphase){
    phi=rand01()*2*M_PI;
  }else{
    phi=phase;
  }

  /*set polarization vector*/
  Ex=0;Ey=0;Ez=0;

}
#line 9042 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
}   /* End of point1=Source_pt() SETTING parameter declarations. */
#undef prms
#undef spectrum_file
#undef mccompcurname
#undef mccompcurtype
#undef mccompcurindex
#undef p
#undef Ez
#undef Ey
#undef Ex
#undef t
#undef phi
#undef kz
#undef ky
#undef kx
#undef z
#undef y
#undef x
  mcDEBUG_STATE(
mcnlx,
mcnly,
mcnlz,
mcnlkx,
mcnlky,
mcnlkz,
mcnlphi,
mcnlt,
mcnlEx,
mcnlEy,
mcnlEz,
mcnlp)

  /* TRACE Component slit [3] */
  mccoordschange(mcposrslit, mcrotrslit,
    &mcnlx,
    &mcnly,
    &mcnlz,
    &mcnlkx,
    &mcnlky,
    &mcnlkz,
    &mcnlEx,
    &mcnlEy,
    &mcnlEz);
  /* define label inside component slit (without coords transformations) */
  mcJumpTrace_slit:
  SIG_MESSAGE("slit (Trace)");
  mcDEBUG_COMP("slit")
  mcDEBUG_STATE(
    mcnlx,
    mcnly,
    mcnlz,
    mcnlkx,
    mcnlky,
    mcnlkz,
    mcnlphi,
    mcnlt,
    mcnlEx,
    mcnlEy,
    mcnlEz,
    mcnlp)
#define x mcnlx
#define y mcnly
#define z mcnlz
#define kx mcnlkx
#define ky mcnlky
#define kz mcnlkz
#define phi mcnlphi
#define t mcnlt
#define Ex mcnlEx
#define Ey mcnlEy
#define Ez mcnlEz
#define p mcnlp
  STORE_XRAY(3,
    mcnlx,
    mcnly,
    mcnlz,
    mcnlkx,
    mcnlky,
    mcnlkz,
    mcnlphi,
    mcnlt,
    mcnlEx,
    mcnlEy,
    mcnlEz,
    mcnlp);
  mcScattered=0;
  mcNCounter[3]++;
  mcPCounter[3] += p;
  mcP2Counter[3] += p*p;
#define mccompcurname  slit
#define mccompcurtype  Slit
#define mccompcurindex 3
{   /* Declarations of slit=Slit() SETTING parameters. */
MCNUM xmin = mccslit_xmin;
MCNUM xmax = mccslit_xmax;
MCNUM ymin = mccslit_ymin;
MCNUM ymax = mccslit_ymax;
MCNUM radius = mccslit_radius;
MCNUM cut = mccslit_cut;
MCNUM xwidth = mccslit_xwidth;
MCNUM yheight = mccslit_yheight;
MCNUM dist = mccslit_dist;
MCNUM focus_xw = mccslit_focus_xw;
MCNUM focus_yh = mccslit_focus_yh;
MCNUM focus_x0 = mccslit_focus_x0;
MCNUM focus_y0 = mccslit_focus_y0;
#line 71 "/usr/local/lib/mcxtrace-1.1/optics/Slit.comp"
{
    PROP_Z0;
    if (((radius == 0) && (x<xmin || x>xmax || y<ymin || y>ymax))
    || ((radius != 0) && (x*x + y*y > radius*radius))){
      ABSORB;
    }else{
      if (p < cut)
        ABSORB;
      else{
        SCATTER;
        if ( focus_xw ){
          double posx,posy,posz,pdir,k;
          coords_get(POS_A_CURRENT_COMP,&posx,&posy,&posz);

          /*we have a target behind the slit - so we now consider the ray a Huygens wavelet.*/
          double xf,yf,zf;
          randvec_target_rect_real(&xf, &yf, &zf, &pdir,
              focus_x0-posx,focus_y0-posy,dist, focus_xw, focus_yh, ROT_A_CURRENT_COMP, x, y, z, 0);
          //printf("%g %g %g %g %g    %g %g %g   %g %g\n",xf,yf,zf,pdir,p,x,y,z,focus_x0,focus_y0);
          //p*=pdir;
          k=sqrt(scalar_prod(kx,ky,kz,kx,ky,kz));
          kx=(xf-x); ky=(yf-y); kz=(zf-z);
          NORM(kx,ky,kz);
          kx*=k;ky*=k;kz*=k;
        }
      }

    }
}
#line 9179 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
}   /* End of slit=Slit() SETTING parameter declarations. */
#undef mccompcurname
#undef mccompcurtype
#undef mccompcurindex
#undef p
#undef Ez
#undef Ey
#undef Ex
#undef t
#undef phi
#undef kz
#undef ky
#undef kx
#undef z
#undef y
#undef x
  mcDEBUG_STATE(
mcnlx,
mcnly,
mcnlz,
mcnlkx,
mcnlky,
mcnlkz,
mcnlphi,
mcnlt,
mcnlEx,
mcnlEy,
mcnlEz,
mcnlp)

  /* TRACE Component cor [4] */
  mccoordschange(mcposrcor, mcrotrcor,
    &mcnlx,
    &mcnly,
    &mcnlz,
    &mcnlkx,
    &mcnlky,
    &mcnlkz,
    &mcnlEx,
    &mcnlEy,
    &mcnlEz);
  /* define label inside component cor (without coords transformations) */
  mcJumpTrace_cor:
  SIG_MESSAGE("cor (Trace)");
  mcDEBUG_COMP("cor")
  mcDEBUG_STATE(
    mcnlx,
    mcnly,
    mcnlz,
    mcnlkx,
    mcnlky,
    mcnlkz,
    mcnlphi,
    mcnlt,
    mcnlEx,
    mcnlEy,
    mcnlEz,
    mcnlp)
#define x mcnlx
#define y mcnly
#define z mcnlz
#define kx mcnlkx
#define ky mcnlky
#define kz mcnlkz
#define phi mcnlphi
#define t mcnlt
#define Ex mcnlEx
#define Ey mcnlEy
#define Ez mcnlEz
#define p mcnlp
  STORE_XRAY(4,
    mcnlx,
    mcnly,
    mcnlz,
    mcnlkx,
    mcnlky,
    mcnlkz,
    mcnlphi,
    mcnlt,
    mcnlEx,
    mcnlEy,
    mcnlEz,
    mcnlp);
  mcScattered=0;
  mcNCounter[4]++;
  mcPCounter[4] += p;
  mcP2Counter[4] += p*p;
#define mccompcurname  cor
#define mccompcurtype  PSD_monitor_coh
#define mccompcurindex 4
#define nx mcccor_nx
#define ny mcccor_ny
#define PSD_N mcccor_PSD_N
#define PSD_p mcccor_PSD_p
#define PSD_p2 mcccor_PSD_p2
#define PSD_phi mcccor_PSD_phi
{   /* Declarations of cor=PSD_monitor_coh() SETTING parameters. */
char* filename = mcccor_filename;
MCNUM restore_xray = mcccor_restore_xray;
MCNUM xmin = mcccor_xmin;
MCNUM xmax = mcccor_xmax;
MCNUM ymin = mcccor_ymin;
MCNUM ymax = mcccor_ymax;
MCNUM xwidth = mcccor_xwidth;
MCNUM yheight = mcccor_yheight;
#line 85 "/usr/local/lib/mcxtrace-1.1/monitors/PSD_monitor_coh.comp"
{
    int i,j;
    double k,x_o,y_o,z_o,phi_o;

    x_o=x;y_o=y;z_o=z;phi_o=phi;
    k=sqrt(kx*kx+ky*ky+kz*kz);
    //printf("%g %g\n",p,phi);
    PROP_Z0;
    if (x>xmin && x<xmax && y>ymin && y<ymax)
    {
/*      distribute phase among the pixels*/
/*      for (i=0;i<nx;i++){*/
/*        double dx;*/
/*        dx=xwidth*(-0.5 + (i+0.5)/nx) - x_o;*/
/*        for(j=0;j<ny;j++){*/
/*          double dy,dl;*/
/*          dy=yheight*(-0.5 + (j+0.5)/ny) - y_o;*/
/*          dl=sqrt( dx*dx + dy*dy + z_o*z_o);*/
/*          double nu;*/
/*          nu=dl*k;*/
/*          //printf("(i,j,dx,dy,dz,dl,nu,nu+phi)=(%d %d %g %g %g %g %g %g)\n",i,j,dx,dy,z_o,dl,nu, nu+phi_o);*/
/*        }*/
/*      }*/


      double dl,nu;
      dl=sqrt( (x-x_o)*(x-x_o) + (y*y_o)*(y-y_o) + z_o*z_o);
      nu=dl*k;

      i = floor((x - xmin)*nx/(xmax - xmin));
      j = floor((y - ymin)*ny/(ymax - ymin));
      PSD_N[i][j]++;
      PSD_phi[i][j]+=p*cexp(I*phi);//I*fmod(phi,2*M_PI));
      //printf("%d %d %g %g, %g +i %g\n",i,j,p,phi,cabs(PSD_phi[i][j]),carg(PSD_phi[i][j]));
      //PSD_p[i][j] += p;
      PSD_p2[i][j] += p*p;
      SCATTER;
    }
    if (restore_xray) {
      RESTORE_XRAY(INDEX_CURRENT_COMP, x, y, z, kx, ky, kz, phi, t,  Ex, Ey, Ez, p);
    }
}
#line 9328 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
}   /* End of cor=PSD_monitor_coh() SETTING parameter declarations. */
#undef PSD_phi
#undef PSD_p2
#undef PSD_p
#undef PSD_N
#undef ny
#undef nx
#undef mccompcurname
#undef mccompcurtype
#undef mccompcurindex
#undef p
#undef Ez
#undef Ey
#undef Ex
#undef t
#undef phi
#undef kz
#undef ky
#undef kx
#undef z
#undef y
#undef x
  mcDEBUG_STATE(
mcnlx,
mcnly,
mcnlz,
mcnlkx,
mcnlky,
mcnlkz,
mcnlphi,
mcnlt,
mcnlEx,
mcnlEy,
mcnlEz,
mcnlp)

  mcabsorbAll:
  mcDEBUG_LEAVE()
  mcDEBUG_STATE(
mcnlx,
mcnly,
mcnlz,
mcnlkx,
mcnlky,
mcnlkz,
mcnlphi,
mcnlt,
mcnlEx,
mcnlEy,
mcnlEz,
mcnlp)
  /* Copy xray state to global variables. */
  mcnx = mcnlx;
  mcny = mcnly;
  mcnz = mcnlz;
  mcnkx = mcnlkx;
  mcnky = mcnlky;
  mcnkz = mcnlkz;
  mcnphi = mcnlphi;
  mcnt = mcnlt;
  mcnEx = mcnlEx;
  mcnEy = mcnlEy;
  mcnEz = mcnlEz;
  mcnp = mcnlp;

} /* end trace */

void mcsave(FILE *handle) {
  if (!handle) mcsiminfo_init(NULL);
  /* User component SAVE code. */

  /* User SAVE code for component 'Origin'. */
  SIG_MESSAGE("Origin (Save)");
#define mccompcurname  Origin
#define mccompcurtype  Progress_bar
#define mccompcurindex 1
#define profile mccOrigin_profile
#define IntermediateCnts mccOrigin_IntermediateCnts
#define StartTime mccOrigin_StartTime
#define EndTime mccOrigin_EndTime
{   /* Declarations of Origin=Progress_bar() SETTING parameters. */
MCNUM percent = mccOrigin_percent;
MCNUM flag_save = mccOrigin_flag_save;
MCNUM minutes = mccOrigin_minutes;
#line 110 "/usr/local/lib/mcxtrace-1.1/misc/Progress_bar.comp"
{
  MPI_MASTER(fprintf(stdout, "\nSave [%s]\n", mcinstrument_name););
  if (profile && strlen(profile)) {
    char filename[256];
    if (!strlen(profile)) strcpy(filename, mcinstrument_name);
    else strcpy(filename, profile);
    DETECTOR_OUT_1D(
        "Intensity profiler",
        "Component index [1]",
        "Intensity",
        "prof", 1, mcNUMCOMP, mcNUMCOMP-1,
        &mcNCounter[1],&mcPCounter[1],&mcP2Counter[1],
        filename);

  }
}
#line 9430 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
}   /* End of Origin=Progress_bar() SETTING parameter declarations. */
#undef EndTime
#undef StartTime
#undef IntermediateCnts
#undef profile
#undef mccompcurname
#undef mccompcurtype
#undef mccompcurindex

  /* User SAVE code for component 'cor'. */
  SIG_MESSAGE("cor (Save)");
#define mccompcurname  cor
#define mccompcurtype  PSD_monitor_coh
#define mccompcurindex 4
#define nx mcccor_nx
#define ny mcccor_ny
#define PSD_N mcccor_PSD_N
#define PSD_p mcccor_PSD_p
#define PSD_p2 mcccor_PSD_p2
#define PSD_phi mcccor_PSD_phi
{   /* Declarations of cor=PSD_monitor_coh() SETTING parameters. */
char* filename = mcccor_filename;
MCNUM restore_xray = mcccor_restore_xray;
MCNUM xmin = mcccor_xmin;
MCNUM xmax = mcccor_xmax;
MCNUM ymin = mcccor_ymin;
MCNUM ymax = mcccor_ymax;
MCNUM xwidth = mcccor_xwidth;
MCNUM yheight = mcccor_yheight;
#line 128 "/usr/local/lib/mcxtrace-1.1/monitors/PSD_monitor_coh.comp"
{
    double PSD_p_abs[nx][ny];
    int i,j;
    
    char filename_abs[255],filename_arg[255];

    snprintf(filename_abs,255,"%s.abs",filename);
    for (i=0;i<nx;i++){
      for (j=0;j<ny;j++){
        PSD_p_abs[i][j]=cabs(PSD_phi[i][j]);
      }
    }
    DETECTOR_OUT_2D(
        "PSD monitor",
        "X position [m]",
        "Y position [m]",
        xmin, xmax, ymin, ymax,
        nx, ny,
        &PSD_N[0][0],&PSD_p_abs[0][0],&PSD_p2[0][0],
        filename_abs);
    
    double PSD_p_arg[nx][ny];
    snprintf(filename_arg,255,"%s.arg",filename);
    for (i=0;i<nx;i++){
      for (j=0;j<ny;j++){
        PSD_p_arg[i][j]=carg(PSD_phi[i][j]);
      }
    }
    DETECTOR_OUT_2D(
        "PSD monitor",
        "X position [m]",
        "Y position [m]",
        xmin, xmax, ymin, ymax,
        nx, ny,
        &PSD_N[0][0],&PSD_p_arg[0][0],&PSD_p[0][0],
        filename_arg);
}
#line 9498 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
}   /* End of cor=PSD_monitor_coh() SETTING parameter declarations. */
#undef PSD_phi
#undef PSD_p2
#undef PSD_p
#undef PSD_N
#undef ny
#undef nx
#undef mccompcurname
#undef mccompcurtype
#undef mccompcurindex

  if (!handle) mcsiminfo_close(); 
} /* end save */
void mcfinally(void) {
  /* User component FINALLY code. */
  mcsiminfo_init(NULL);
  mcsave(mcsiminfo_file); /* save data when simulation ends */

  /* User FINALLY code for component 'Origin'. */
  SIG_MESSAGE("Origin (Finally)");
#define mccompcurname  Origin
#define mccompcurtype  Progress_bar
#define mccompcurindex 1
#define profile mccOrigin_profile
#define IntermediateCnts mccOrigin_IntermediateCnts
#define StartTime mccOrigin_StartTime
#define EndTime mccOrigin_EndTime
{   /* Declarations of Origin=Progress_bar() SETTING parameters. */
MCNUM percent = mccOrigin_percent;
MCNUM flag_save = mccOrigin_flag_save;
MCNUM minutes = mccOrigin_minutes;
#line 128 "/usr/local/lib/mcxtrace-1.1/misc/Progress_bar.comp"
{
  time_t NowTime;
  time(&NowTime);
  fprintf(stdout, "\nFinally [%s/%s]. Time: ", mcinstrument_name, mcdirname ? mcdirname : ".");
  if (difftime(NowTime,StartTime) < 60.0)
    fprintf(stdout, "%g [s] ", difftime(NowTime,StartTime));
  else if (difftime(NowTime,StartTime) > 3600.0)
    fprintf(stdout, "%g [h] ", difftime(NowTime,StartTime)/3660.0);
  else
    fprintf(stdout, "%g [min] ", difftime(NowTime,StartTime)/60.0);
  fprintf(stdout, "\n");
}
#line 9543 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
}   /* End of Origin=Progress_bar() SETTING parameter declarations. */
#undef EndTime
#undef StartTime
#undef IntermediateCnts
#undef profile
#undef mccompcurname
#undef mccompcurtype
#undef mccompcurindex

    if (!mcNCounter[1]) fprintf(stderr, "Warning: No xray could reach Component[1] Origin\n");
    if (mcAbsorbProp[1]) fprintf(stderr, "Warning: %g events were removed in Component[1] Origin=Progress_bar()\n"
"         (negative time, miss next components, rounding errors, Nan, Inf).\n", mcAbsorbProp[1]);
  /* User FINALLY code for component 'point1'. */
  SIG_MESSAGE("point1 (Finally)");
#define mccompcurname  point1
#define mccompcurtype  Source_pt
#define mccompcurindex 2
#define spectrum_file mccpoint1_spectrum_file
#define prms mccpoint1_prms
{   /* Declarations of point1=Source_pt() SETTING parameters. */
MCNUM focus_xw = mccpoint1_focus_xw;
MCNUM focus_yh = mccpoint1_focus_yh;
MCNUM flux = mccpoint1_flux;
MCNUM dist = mccpoint1_dist;
MCNUM gamma = mccpoint1_gamma;
MCNUM E0 = mccpoint1_E0;
MCNUM dE = mccpoint1_dE;
MCNUM lambda0 = mccpoint1_lambda0;
MCNUM dlambda = mccpoint1_dlambda;
MCNUM phase = mccpoint1_phase;
MCNUM randomphase = mccpoint1_randomphase;
MCNUM gauss = mccpoint1_gauss;
#line 175 "/usr/local/lib/mcxtrace-1.1/sources/Source_pt.comp"
{
  Table_Free(&(prms.T));
}
#line 9579 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
}   /* End of point1=Source_pt() SETTING parameter declarations. */
#undef prms
#undef spectrum_file
#undef mccompcurname
#undef mccompcurtype
#undef mccompcurindex

    if (!mcNCounter[2]) fprintf(stderr, "Warning: No xray could reach Component[2] point1\n");
    if (mcAbsorbProp[2]) fprintf(stderr, "Warning: %g events were removed in Component[2] point1=Source_pt()\n"
"         (negative time, miss next components, rounding errors, Nan, Inf).\n", mcAbsorbProp[2]);
    if (!mcNCounter[3]) fprintf(stderr, "Warning: No xray could reach Component[3] slit\n");
    if (mcAbsorbProp[3]) fprintf(stderr, "Warning: %g events were removed in Component[3] slit=Slit()\n"
"         (negative time, miss next components, rounding errors, Nan, Inf).\n", mcAbsorbProp[3]);
    if (!mcNCounter[4]) fprintf(stderr, "Warning: No xray could reach Component[4] cor\n");
    if (mcAbsorbProp[4]) fprintf(stderr, "Warning: %g events were removed in Component[4] cor=PSD_monitor_coh()\n"
"         (negative time, miss next components, rounding errors, Nan, Inf).\n", mcAbsorbProp[4]);
  mcsiminfo_close(); 
} /* end finally */
#define magnify mcdis_magnify
#define line mcdis_line
#define dashed_line mcdis_dashed_line
#define multiline mcdis_multiline
#define rectangle mcdis_rectangle
#define box mcdis_box
#define circle mcdis_circle
void mcdisplay(void) {
  printf("MCDISPLAY: start\n");
  /* Components MCDISPLAY code. */

  /* MCDISPLAY code for component 'point1'. */
  SIG_MESSAGE("point1 (McDisplay)");
  printf("MCDISPLAY: component %s\n", "point1");
#define mccompcurname  point1
#define mccompcurtype  Source_pt
#define mccompcurindex 2
#define spectrum_file mccpoint1_spectrum_file
#define prms mccpoint1_prms
{   /* Declarations of point1=Source_pt() SETTING parameters. */
MCNUM focus_xw = mccpoint1_focus_xw;
MCNUM focus_yh = mccpoint1_focus_yh;
MCNUM flux = mccpoint1_flux;
MCNUM dist = mccpoint1_dist;
MCNUM gamma = mccpoint1_gamma;
MCNUM E0 = mccpoint1_E0;
MCNUM dE = mccpoint1_dE;
MCNUM lambda0 = mccpoint1_lambda0;
MCNUM dlambda = mccpoint1_dlambda;
MCNUM phase = mccpoint1_phase;
MCNUM randomphase = mccpoint1_randomphase;
MCNUM gauss = mccpoint1_gauss;
#line 180 "/usr/local/lib/mcxtrace-1.1/sources/Source_pt.comp"
{
  double radius=0.05;
  magnify("xy");
  circle("xy",0,0,0,radius);
  circle("xz",0,0,0,radius);
  circle("yz",0,0,0,radius);
}
#line 9635 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
}   /* End of point1=Source_pt() SETTING parameter declarations. */
#undef prms
#undef spectrum_file
#undef mccompcurname
#undef mccompcurtype
#undef mccompcurindex

  /* MCDISPLAY code for component 'slit'. */
  SIG_MESSAGE("slit (McDisplay)");
  printf("MCDISPLAY: component %s\n", "slit");
#define mccompcurname  slit
#define mccompcurtype  Slit
#define mccompcurindex 3
{   /* Declarations of slit=Slit() SETTING parameters. */
MCNUM xmin = mccslit_xmin;
MCNUM xmax = mccslit_xmax;
MCNUM ymin = mccslit_ymin;
MCNUM ymax = mccslit_ymax;
MCNUM radius = mccslit_radius;
MCNUM cut = mccslit_cut;
MCNUM xwidth = mccslit_xwidth;
MCNUM yheight = mccslit_yheight;
MCNUM dist = mccslit_dist;
MCNUM focus_xw = mccslit_focus_xw;
MCNUM focus_yh = mccslit_focus_yh;
MCNUM focus_x0 = mccslit_focus_x0;
MCNUM focus_y0 = mccslit_focus_y0;
#line 103 "/usr/local/lib/mcxtrace-1.1/optics/Slit.comp"
{
  magnify("xy");
  if (radius == 0) {
    double xw, yh;
    xw = (xmax - xmin)/2.0;
    yh = (ymax - ymin)/2.0;
    multiline(3, xmin-xw, (double)ymax, 0.0,
              (double)xmin, (double)ymax, 0.0,
              (double)xmin, ymax+yh, 0.0);
    multiline(3, xmax+xw, (double)ymax, 0.0,
              (double)xmax, (double)ymax, 0.0,
              (double)xmax, ymax+yh, 0.0);
    multiline(3, xmin-xw, (double)ymin, 0.0,
              (double)xmin, (double)ymin, 0.0,
              (double)xmin, ymin-yh, 0.0);
    multiline(3, xmax+xw, (double)ymin, 0.0,
              (double)xmax, (double)ymin, 0.0,
              (double)xmax, ymin-yh, 0.0);
  } else {
    circle("xy",0,0,0,radius);
  }
}
#line 9686 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
}   /* End of slit=Slit() SETTING parameter declarations. */
#undef mccompcurname
#undef mccompcurtype
#undef mccompcurindex

  /* MCDISPLAY code for component 'cor'. */
  SIG_MESSAGE("cor (McDisplay)");
  printf("MCDISPLAY: component %s\n", "cor");
#define mccompcurname  cor
#define mccompcurtype  PSD_monitor_coh
#define mccompcurindex 4
#define nx mcccor_nx
#define ny mcccor_ny
#define PSD_N mcccor_PSD_N
#define PSD_p mcccor_PSD_p
#define PSD_p2 mcccor_PSD_p2
#define PSD_phi mcccor_PSD_phi
{   /* Declarations of cor=PSD_monitor_coh() SETTING parameters. */
char* filename = mcccor_filename;
MCNUM restore_xray = mcccor_restore_xray;
MCNUM xmin = mcccor_xmin;
MCNUM xmax = mcccor_xmax;
MCNUM ymin = mcccor_ymin;
MCNUM ymax = mcccor_ymax;
MCNUM xwidth = mcccor_xwidth;
MCNUM yheight = mcccor_yheight;
#line 167 "/usr/local/lib/mcxtrace-1.1/monitors/PSD_monitor_coh.comp"
{
  magnify("xy");
  multiline(5, (double)xmin, (double)ymin, 0.0,
               (double)xmax, (double)ymin, 0.0,
               (double)xmax, (double)ymax, 0.0,
               (double)xmin, (double)ymax, 0.0,
               (double)xmin, (double)ymin, 0.0);
}
#line 9722 "/Users/pengfei/github/Monte_Carlo/single_slit.c"
}   /* End of cor=PSD_monitor_coh() SETTING parameter declarations. */
#undef PSD_phi
#undef PSD_p2
#undef PSD_p
#undef PSD_N
#undef ny
#undef nx
#undef mccompcurname
#undef mccompcurtype
#undef mccompcurindex

  printf("MCDISPLAY: end\n");
} /* end display */
#undef magnify
#undef line
#undef dashed_line
#undef multiline
#undef rectangle
#undef box
#undef circle
/* end of generated C code /Users/pengfei/github/Monte_Carlo/single_slit.c */
