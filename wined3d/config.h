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

#include <direct.h>
#define snprintf _snprintf

static const char wine_build[] = "msvc_hack";
