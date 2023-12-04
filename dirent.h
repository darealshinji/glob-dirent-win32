/*
 * DIRENT.H (formerly DIRLIB.H)
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within the package.
 *
 */

#ifndef _DIRENT_H_
#define _DIRENT_H_

#include <crtdefs.h>
#include <io.h>

#include <tchar.h>

#ifndef _TDIR
#ifdef _UNICODE
#define _TDIR _WDIR
#define _tdirent    _wdirent
#define _topendir   _wopendir
#define _tclosedir  _wclosedir
#define _treaddir   _wreaddir
#define _trewinddir _wrewinddir
#define _ttelldir   _wtelldir
#define _tseekdir   _wseekdir
#else
#define _TDIR DIR
#define _tdirent    dirent
#define _topendir   opendir
#define _tclosedir  closedir
#define _treaddir   readdir
#define _trewinddir rewinddir
#define _ttelldir   telldir
#define _tseekdir   seekdir
#endif
#endif


struct dirent
{
	long		d_ino;		/* Always zero. */
	unsigned short	d_reclen;	/* Always zero. */
	unsigned short	d_namlen;	/* Length of name in d_name. */
	char		d_name[260]; /* [FILENAME_MAX] */ /* File name. */
};

/*
 * This is an internal data structure. Good programmers will not use it
 * except as an argument to one of the functions below.
 * dd_stat field is now int (was short in older versions).
 */
typedef struct
{
	/* disk transfer area for this dir */
	struct _finddata_t	dd_dta;

	/* dirent struct to return from dir (NOTE: this makes this thread
	 * safe as long as only one thread uses a particular DIR struct at
	 * a time) */
	struct dirent		dd_dir;

	/* _findnext handle */
	intptr_t		dd_handle;

	/*
	 * Status of search:
	 *   0 = not started yet (next entry to read is first entry)
	 *  -1 = off the end
	 *   positive = 0 based index of next entry
	 */
	int			dd_stat;

	/* given path for dir with search pattern (struct is extended) */
	char			dd_name[1];
} DIR;

DIR* opendir (const char*);
struct dirent* readdir (DIR*);
int closedir (DIR*);
void rewinddir (DIR*);
long telldir (DIR*);
void seekdir (DIR*, long);


/* wide char versions */

struct _wdirent
{
	long		d_ino;		/* Always zero. */
	unsigned short	d_reclen;	/* Always zero. */
	unsigned short	d_namlen;	/* Length of name in d_name. */
	wchar_t		d_name[260]; /* [FILENAME_MAX] */ /* File name. */
};

/*
 * This is an internal data structure. Good programmers will not use it
 * except as an argument to one of the functions below.
 */
typedef struct
{
	/* disk transfer area for this dir */
	struct _wfinddata_t	dd_dta;

	/* dirent struct to return from dir (NOTE: this makes this thread
	 * safe as long as only one thread uses a particular DIR struct at
	 * a time) */
	struct _wdirent		dd_dir;

	/* _findnext handle */
	intptr_t		dd_handle;

	/*
	 * Status of search:
	 *   0 = not started yet (next entry to read is first entry)
	 *  -1 = off the end
	 *   positive = 0 based index of next entry
	 */
	int			dd_stat;

	/* given path for dir with search pattern (struct is extended) */
	wchar_t			dd_name[1];
} _WDIR;

_WDIR* _wopendir (const wchar_t*);
struct _wdirent* _wreaddir (_WDIR*);
int _wclosedir (_WDIR*);
void _wrewinddir (_WDIR*);
long _wtelldir (_WDIR*);
void _wseekdir (_WDIR*, long);

#endif	/* Not _DIRENT_H_ */

