Visual Studio Build Setup for Wine's D3D libraries

This Visual Studio project is an independent build system for some of Wine's (www.winehq.org) DLLs and tests, most of them d3d-related. Its goal is to make it easy for a Windows developer to build them and to have debug symbols that are compatible with msvc and msvc-based tools.

Requirements:

*) Visual Studio 2019

No 'foreign' tools are required. No mingw, no msys, no perl, no python, etc.

Building:

The msvc project references source files from ..\wine\, so to build, clone this repository and the Wine sources next to each other:

1) git clone git://source.winehq.org/git/wine.git
2) git clone git://source.winehq.org/git/vkd3d.git
3) git clone https://github.com/stefand/wined3d_vs.git
4) Open wined3d_vs\wined3d.sln with MSVC 2019 and build the solution.

Tests and Wine-private DLLs will be placed in wined3d_vs\Debug, frontend DLLs replacing Windows ones can be found in wined3d_vs\Debug_dll.

To build d3d12, install the Vulkan SDK and make sure %VULKAN_SDK% is set and points to the right place - the installer should do this for you by default. Build the following projects in this order: vkd3d-common, vkd3d-shader, vkd3d, d3d12.

Running games:

Copy libwine.dll, wined3d.dll and whichever frontend dll (e.g. d3d11.dll) next to the game exectutable and run it. It should prefer the DLLs in its current directory over the system DLLs.

You can also include wined3d_vs\Debug in your %PATH% to eliminate the requirement to copy wined3d.dll and libwine.dll. These DLLs won't harm anything unless they are loaded explicitly.

Compiler Warnings:

There are plenty of warnings. Patches are welcome.

Things on the TODO list:

*) Improve warnings, disable those that Wine decides not to care about.
*) Add whatever other library is useful.
*) Compile WIDL instead of using a .exe blob.
*) Find a nicer way to handle DLL exports than listing them in the linker cmdline options.

WONTFIX items:

*) Building with the PSDK headers instead of Wine's.
*) Compile .idl files with MIDL - the results are incompatible due to the nameless union crap.
