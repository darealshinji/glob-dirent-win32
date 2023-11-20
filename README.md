This is a port of the POSIX C function glob(3) to Windows.
It can be compiled with MinGW and MSVC.
On MSVC `dirent.c` is needed as a dependency of glob(3).

The flag `GLOB_WIN32` was added and can be set to change the behavior
to a more Windows-like style:
 * the character `^` will be used as an escape character instead of `\`
 * forward `/` and backward `\` slash can both be used as path separators

`glob.c` and `glob.h` came from NetBSD:
https://github.com/NetBSD/src

`dirent.c` and `dirent.h` came from MinGW-w64:
https://github.com/mingw-w64/mingw-w64

