/* Automatically generated file; DO NOT EDIT!! */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define STANDALONE
#include "wine/test.h"

extern void func_d3drm(void);
extern void func_vector(void);
extern void func_stateblock(void);
extern void func_visual(void);

const struct test winetest_testlist[] =
{
    { "d3drm", func_d3drm },
    { "vector", func_vector },
    { 0, 0 }
};
