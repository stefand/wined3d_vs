#define __WINE_CONFIG_H

#define HAVE_STRERROR
#define HAVE_MEMMOVE
#define HAVE_FLOAT_H

#undef inline
#define inline __inline

#define HAVE_STRING_H
#define HAVE_SPAWNVP
#define HAVE__SPAWNVP
#define HAVE_IO_H
#define HAVE_POLL
#define HAVE_PROCESS_H
#define DECLSPEC_HOTPATCH
#define HAVE__ISNAN 1
#define HAVE__FINITE 1
#define HAVE__STRICMP 1
#define HAVE_ISFINITE 1
#define HAVE_ISINF 1
#define HAVE_ISNAN 1
#define HAVE_LRINT 1
#define HAVE_LLRINT 1
#define HAVE_LRINTF 1
#define HAVE_LLRINTF 1
#define HAVE_RINT 1
#define HAVE_RINTF 1
#define HAVE_INTF 1
#define HAVE_STRNLEN 1

#include <direct.h>

static const char wine_build[] = "msvc_hack";

struct timeval
{
	long tv_sec;
	long tv_usec;
};

/* Called by mkstemps.c to get semi-random data. Ignore security for this hacky build. */
static inline int gettimeofday(struct timeval *tv, struct timezone *tz)
{
	tv->tv_sec = 0;
	tv->tv_usec = 0;
	return 0;
}

#define HAVE_FFS
static __inline int ffs(int x) {
	int i = 0;
	if (_BitScanForward(&i, x) == 0)
		return 0;
	return i + 1;
}

#pragma warning(disable:4756)

#define PACKAGE_VERSION "4.9"
