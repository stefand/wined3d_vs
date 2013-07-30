/* Automatically generated file; DO NOT EDIT!! */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define STANDALONE
#include "wine/test.h"

extern void func_d3d9ex(void);
extern void func_device(void);
extern void func_stateblock(void);
extern void func_vertexdeclaration(void);
extern void func_visual(void);

const struct test winetest_testlist[] =
{
    { "d3d9ex", func_d3d9ex },
    { "device", func_device },
    { "stateblock", func_stateblock },
    { "vertexdeclaration", func_vertexdeclaration },
    { "visual", func_visual },
    { 0, 0 }
};
