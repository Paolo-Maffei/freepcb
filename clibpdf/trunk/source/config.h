/* config.h -- platform and local configuration file
 * Copyright (C) 1998, 1999 FastIO Systems, All Rights Reserved.
 * For conditions of use, license, and distribution, see LICENSE.pdf.
 *  or http://www.fastio.com/LICENSE.pdf

    - ZLIB_COMPRESS_PATH has to be present but the content string does not matter
	because zlib/flate compression is now internal to the library.
*/
/* ==== Adobe 39 PS Fonts option: enable here or in Makefile ====================================== */
#define PS_FONTS39			1 		/* compile in Adobe 39 PS font support */
							/* if not defined, Base 14 fonts are supported */

/* ==== IMAGE FORMAT options: enable here or in Makefile ================================================ */
/* #define USE_ENCRYPTION		1 */		/* compile in encryption support */
/* #define USE_LIBTIFF			1 */		/* compile in LIBTIFF support */
/* #define USE_LINEARIZER		1 */		/* compile in linearization support */
/* #define USE_PDFIMG			1 */		/* compile in PDFIMG support */

/* ==== PLATFORM DEFINE: ========================================================================== */
/* Generally, you do not have to touch below, as platform defines are done in Makefile.* or relies
   on predefined symbols of preprocessor/compiler/environment.
*/

/* #define NEXTSTEP			1 */		/* NEXTSTEP and OPENSTEP */
/* #define BSDI				1 */		/* BSDI BSD/OS 3.1/gcc 2.7.2.1 */
/* #define FreeBSD			1 */		/* FreeBSD 2.2.7-STABLE/gcc 2.7.2.1 */
/* #define Linux			1 */		/* Linux 2.0.34 (Red Hat 5.1)/gcc 2.7.2.3 */
/* #define SolarisSunCC			1 */		/* Sun Solaris 2.6 or 7 / Sun CC  */
/* #define SolarisGCC			1 */		/* Sun Solaris 2.6 or 7 / GCC 2.95.1  */
/* #define SunOS5x			1 */		/* SunOS 5.4 / (SUNWspro/SC4.0) */
/* #define MacOS8			1 */		/* MacOS 8._ or earlier with CodeWarrier */
/* #define MacOSX			1 */		/* MacOS X Server, MacOS X */
/* #define Windows			1 */		/* Not Used -- We now use _WIN32 */
/* #define Cygwin          		1 */        	/* Cygwin b20.1/gcc egcs-2.91.57 */
/* #define AIX_42          		1 */        	/* AIX 4.2 */
/* #define HPUX          		1 */        	/* HP-UX B.11.00 */
/* #define UNIX				1 */
/* ================================================================================================ */

/* #define EXT_ZLIBCOMP			1 */	/* enable if you use external zlibcomp command */


#ifdef UNIX
#define PLATFORM_NAME			"Unix Generic"
#define PDF_VIEWER_COMMAND		"/usr/local/Acrobat4/bin/acroread"
#define ZLIB_COMPRESS_PATH		"/usr/local/bin/zlibcomp"
#define TEMP_DIRECTORY			"/tmp/"
#define BINARY_WRITE			"w"
#define BINARY_READ			"r"
#define DIR_SEPARATOR			'/'
#define DEF_FONTMAPFILE			"fontmap.lst"
#define DEF_PFM_DIR			"/usr/local/font/pfm"
#define DEF_PFB_DIR			"/usr/local/font/pfb"
#endif

#ifdef HPUX
#define PLATFORM_NAME			"HP-UX B.11.00"
#define PDF_VIEWER_COMMAND		"/usr/local/Acrobat4/bin/acroread"
#define ZLIB_COMPRESS_PATH		"/usr/local/bin/zlibcomp"
#define TEMP_DIRECTORY			"/tmp/"
#define BINARY_WRITE			"w"
#define BINARY_READ			"r"
#define DIR_SEPARATOR			'/'
#define UNIX				1
#define DEF_FONTMAPFILE			"fontmap.lst"
#define DEF_PFM_DIR			"/usr/local/font/pfm"
#define DEF_PFB_DIR			"/usr/local/font/pfb"
#endif


/* MacOS 9.x and earlier with Metrowerks CodeWarrier IDE (tested with 1.7.4) */
#if defined(__MWERKS__) || defined(THINK_C)
  #define MacOS8
#endif

#ifdef MacOS8
#define PLATFORM_NAME			"MacOS 9 or earlier"
#define PDF_VIEWER_COMMAND		""
#define ZLIB_COMPRESS_PATH		""
#define TEMP_DIRECTORY			""
#define BINARY_WRITE			"wb"
#define BINARY_READ			"rb"
#define DIR_SEPARATOR			':'
#define DEF_FONTMAPFILE			"fontmap.lst"
#define DEF_PFM_DIR			":usr:local:font:pfm"
#define DEF_PFB_DIR			":usr:local:font:pfb"
#endif

/* NEXTSTEP 3.2, 3.3, and OPENSTEP 4.2 */
#ifdef NEXTSTEP
#define PLATFORM_NAME			"NEXTSTEP or OPENSTEP"
#define PDF_VIEWER_COMMAND		"/usr/bin/open"
#define TEMP_DIRECTORY			"/tmp/"
#define ZLIB_COMPRESS_PATH		"/usr/local/bin/zlibcomp"
#define BINARY_WRITE			"w"
#define BINARY_READ			"r"
#define DIR_SEPARATOR			'/'
#define UNIX				1
#define DEF_FONTMAPFILE			"fontmap.lst"
#define DEF_PFM_DIR			"/usr/local/font/pfm"
#define DEF_PFB_DIR			"/usr/local/font/pfb"
#endif

/* BSDI BSD/OS 3.1/gcc 2.7.2.1 */
#ifdef BSDI
#define PLATFORM_NAME			"BSDI BSD/OS 3.1"
#define PDF_VIEWER_COMMAND		"/usr/contrib/bin/gs"
#define TEMP_DIRECTORY			"/tmp/"
#define ZLIB_COMPRESS_PATH		"/usr/local/bin/zlibcomp"
#define BINARY_WRITE			"w"
#define BINARY_READ			"r"
#define DIR_SEPARATOR			'/'
#define UNIX				1
#define DEF_FONTMAPFILE			"fontmap.lst"
#define DEF_PFM_DIR			"/usr/local/font/pfm"
#define DEF_PFB_DIR			"/usr/local/font/pfb"
#endif

/* Sun Solaris 2.6 or 7 / Sun CC  */
#ifdef SolarisSunCC
#define PLATFORM_NAME			"Solaris SunCC"
#define PDF_VIEWER_COMMAND		"/opt/Acrobat4/bin/acroread"
#define TEMP_DIRECTORY			"/tmp/"
#define ZLIB_COMPRESS_PATH		"/usr/local/bin/zlibcomp"
#define BINARY_WRITE			"w"
#define BINARY_READ			"r"
#define DIR_SEPARATOR			'/'
#define UNIX				1
#define DEF_FONTMAPFILE			"fontmap.lst"
#define DEF_PFM_DIR			"/usr/local/font/pfm"
#define DEF_PFB_DIR			"/usr/local/font/pfb"
#endif

/* Sun Solaris 2.6 or 7 / GCC 2.95.1  */
#ifdef SolarisGCC
#define PLATFORM_NAME			"Solaris GCC"
#define PDF_VIEWER_COMMAND		"/opt/Acrobat4/bin/acroread"
#define TEMP_DIRECTORY			"/tmp/"
#define ZLIB_COMPRESS_PATH		"/usr/local/bin/zlibcomp"
#define BINARY_WRITE			"w"
#define BINARY_READ			"r"
#define DIR_SEPARATOR			'/'
#define UNIX				1
#define DEF_FONTMAPFILE			"fontmap.lst"
#define DEF_PFM_DIR			"/usr/local/font/pfm"
#define DEF_PFB_DIR			"/usr/local/font/pfb"
#endif

/* SunOS 5.4 / (SUNWspro/SC4.0) */
#ifdef SunOS5x
#define PLATFORM_NAME			"SunOS5.x"
#define PDF_VIEWER_COMMAND		"/usr/local/Acrobat4/bin/acroread"
#define TEMP_DIRECTORY			"/tmp/"
#define ZLIB_COMPRESS_PATH		"/usr/local/bin/zlibcomp"
#define BINARY_WRITE			"w"
#define BINARY_READ			"r"
#define DIR_SEPARATOR			'/'
#define UNIX				1
#define DEF_FONTMAPFILE			"fontmap.lst"
#define DEF_PFM_DIR			"/usr/local/font/pfm"
#define DEF_PFB_DIR			"/usr/local/font/pfb"
#endif


/* NetBSD 1.4.1/gcc 2.91.60 */
#ifdef NetBSD
#define PLATFORM_NAME			"NetBSD"
#define PDF_VIEWER_COMMAND		"/usr/pkg/bin/gs"
#define TEMP_DIRECTORY			"/tmp/"
#define ZLIB_COMPRESS_PATH		"/usr/local/bin/zlibcomp"
#define BINARY_WRITE			"w"
#define BINARY_READ			"r"
#define DIR_SEPARATOR			'/'
#define UNIX				1
#define DEF_FONTMAPFILE			"fontmap.lst"
#define DEF_PFM_DIR			"/usr/local/font/pfm"
#define DEF_PFB_DIR			"/usr/local/font/pfb"
#endif

/* FreeBSD 2.2.7/gcc 2.7.2.1 */
#ifdef FreeBSD
#define PLATFORM_NAME			"FreeBSD"
#define PDF_VIEWER_COMMAND		"/usr/local/bin/gs"
#define TEMP_DIRECTORY			"/tmp/"
#define ZLIB_COMPRESS_PATH		"/usr/local/bin/zlibcomp"
#define BINARY_WRITE			"w"
#define BINARY_READ			"r"
#define DIR_SEPARATOR			'/'
#define UNIX				1
#define DEF_FONTMAPFILE			"fontmap.lst"
#define DEF_PFM_DIR			"/usr/local/font/pfm"
#define DEF_PFB_DIR			"/usr/local/font/pfb"
#endif

/* Linux  (Red Hat 6.1)/gcc 2.95.1 */
/* Acrobat Reader 3.0x for Linux works beautifully. */
#ifdef Linux
#define PLATFORM_NAME			"Linux"
#define PDF_VIEWER_COMMAND		"/usr/local/Acrobat4/bin/acroread"
#define TEMP_DIRECTORY			"/tmp/"
#define ZLIB_COMPRESS_PATH		"/usr/local/bin/zlibcomp"
#define BINARY_WRITE			"w"
#define BINARY_READ			"r"
#define DIR_SEPARATOR			'/'
#define UNIX				1
#define DEF_FONTMAPFILE			"fontmap.lst"
#define DEF_PFM_DIR			"/usr/share/fonts/default/Type1"
#define DEF_PFB_DIR			"/usr/share/fonts/default/Type1"
#endif

/* MacOS X (Server) is Unix */
#ifdef MacOSX
#define PLATFORM_NAME			"MacOS X (Server)"
#define PDF_VIEWER_COMMAND		"/usr/bin/open"
#define TEMP_DIRECTORY			"/tmp/"
#define ZLIB_COMPRESS_PATH		"/usr/local/bin/zlibcomp"
#define BINARY_WRITE			"w"
#define BINARY_READ			"r"
#define DIR_SEPARATOR			'/'
#define UNIX				1
#define DEF_FONTMAPFILE			"fontmap.lst"
#define DEF_PFM_DIR			"/usr/local/font/pfm"
#define DEF_PFB_DIR			"/usr/local/font/pfb"
#endif

/* Cygwin b20.1/gcc egcs-2.91.57 */
#ifdef Cygwin
#define PLATFORM_NAME           	"Cygwin"
#define PDF_VIEWER_COMMAND		"/usr/local/bin/gs"
#define TEMP_DIRECTORY			"/tmp/"
#define ZLIB_COMPRESS_PATH		"/usr/local/bin/zlibcomp"
#define BINARY_WRITE            	"wb"
#define BINARY_READ         		"rb"
#define DIR_SEPARATOR			'/'
#define UNIX				1
#define DEF_FONTMAPFILE			"fontmap.lst"
#define DEF_PFM_DIR			"/usr/local/font/pfm"
#define DEF_PFB_DIR			"/usr/local/font/pfb"
#undef  _WIN32
#endif

/* Windows NT/95/98 (VC++ 6.0) */
#if defined(_WIN32) || defined(WIN32)
#define PLATFORM_NAME			"Windows 9x/NT"
#define PDF_VIEWER_COMMAND		"open"		/* with YB/Windows -- Not used. */
#define TEMP_DIRECTORY			"\\Temp\\"
#define ZLIB_COMPRESS_PATH		"\\Bin\\zlibcomp"
#define BINARY_WRITE			"wb"
#define BINARY_READ			"rb"
#define DIR_SEPARATOR			'\\'
#define DEF_FONTMAPFILE			"fontmap.lst"
#define DEF_PFM_DIR			"\\usr\\local\\font\\pfm"
#define DEF_PFB_DIR			"\\usr\\local\\font\\pfb"
#define __LITTLE_ENDIAN__		1	/* VC++ is not going to use Makefile/endian.h */
#endif


#ifdef AIX_42
#define PLATFORM_NAME			"AIX 4.2"
#define PDF_VIEWER_COMMAND		"/usr/local/Acrobat4/bin/acroread"
#define ZLIB_COMPRESS_PATH		"/usr/local/bin/zlibcomp"
#define TEMP_DIRECTORY			"/tmp/"
#define BINARY_WRITE			"w"
#define BINARY_READ			"r"
#define DIR_SEPARATOR			'/'
#define UNIX				1
#define DEF_FONTMAPFILE			"fontmap.lst"
#define DEF_PFM_DIR			"/usr/local/font/pfm"
#define DEF_PFB_DIR			"/usr/local/font/pfb"
#endif


/* -------------------------------------------------------------------------- */

