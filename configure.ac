dnl Initialise autoconf

AC_INIT([Atlas-C++],[0.7.0],[erik@ogenvik.org],[Atlas-C++])
AC_CONFIG_SRCDIR([Atlas/Bridge.cpp])
AC_CONFIG_HEADERS([config.h])

AC_CONFIG_MACRO_DIR([m4])

dnl Detect the canonical host environment

AC_CANONICAL_HOST

dnl Initialise automake

AM_INIT_AUTOMAKE([nostdinc dist-bzip2 check-news])
AM_SILENT_RULES([yes])

dnl Initialise automake

ATLAS_CURRENT=2
ATLAS_REVISION=0
INTERFACE_VERSION="-version-info $ATLAS_CURRENT:$ATLAS_REVISION:0"

AC_SUBST(ATLAS_CURRENT)
AC_SUBST(INTERFACE_VERSION)

dnl Test for GNU libtool

AC_DISABLE_STATIC
AC_PROG_LIBTOOL

dnl Test for C++ compiler

AC_PROG_CXX

dnl Test for Python 2; our scripts don't yet work with Python 3 (perhaps they should?)
m4_define_default([_AM_PYTHON_INTERPRETER_LIST], [python2 python2.7 python2.6 python]) 
AM_PATH_PYTHON(2.6) 
if $PYTHON -c "import sys 
if (sys.hexversion >> 24) < 3: 
  sys.exit(1) 
else: 
  sys.exit(0) 
"; then 
  AC_MSG_FAILURE([You need to use Python 2; we don't support Python 3 yet.]) 
fi 

AC_SUBST(PYTHON)

AC_ARG_ENABLE(debug,
    [  --enable-debug          enable debug information [default=no]],
    [
        if test "$enableval" = "yes"; then
            CXXFLAGS="$CXXFLAGS -Wall -Werror -DDEBUG"
        else
            CXXFLAGS="$CXXFLAGS -Wall -Werror -DNDEBUG"
        fi
    ],[
        CXXFLAGS="$CXXFLAGS -Wall -Werror -DNDEBUG"
    ]
)

AC_LANG(C++)

AX_CXX_COMPILE_STDCXX_11

OTHER_LIBS=

dnl Test for gzip compression library

AC_ARG_WITH(zlib,
[  --with-zlib=DIR         gzip compression library (optional)],
[with_zlib="$withval"],
[with_zlib=""])

ac_save_CFLAGS="$CFLAGS"
ac_save_LIBS="$LIBS"
CFLAGS="$CFLAGS -I$with_zlib/include"
LIBS="$LIBS -L$with_zlib/lib"

AC_CHECK_LIB(z, inflate,
    [
        AC_DEFINE(HAVE_LIBZ, 1, ["True if zlib is available"])
        OTHER_LIBS="$OTHER_LIBS -lz"
    ])

AC_CHECK_HEADER(zlib.h)

CFLAGS="$ac_save_CFLAGS"
LIBS="$ac_save_LIBS"

dnl Test for bzip2 compression library

AC_ARG_WITH(bzlib,
[  --with-bzlib=DIR        bzip2 compression library (optional)],
[with_bzlib="$withval"],
[with_bzlib=""])

ac_save_CFLAGS="$CFLAGS"
ac_save_LIBS="$LIBS"
CFLAGS="$CFLAGS -I$with_bzlib/include"
LIBS="$LIBS -L$with_bzlib/lib"

AC_CHECK_LIB(bz2, BZ2_bzDecompressInit,
    [
        AC_DEFINE(HAVE_LIBBZ2, 1, ["True if libbz2 is available"])
        OTHER_LIBS="$OTHER_LIBS -lbz2"
    ])

AC_CHECK_HEADER(bzlib.h)

CFLAGS="$ac_save_CFLAGS"
LIBS="$ac_save_LIBS"

SYSTEM_LIBS="$SYSTEM_LIBS -lm"
ATLAS_CFLAGS=""
ATLAS_LIB_SUFFIX="-0.7"
ATLAS_LIBS="-lAtlasObjects$ATLAS_LIB_SUFFIX -lAtlasNet$ATLAS_LIB_SUFFIX -lAtlas$ATLAS_LIB_SUFFIX -lAtlasCodecs$ATLAS_LIB_SUFFIX -lAtlasMessage$ATLAS_LIB_SUFFIX -lAtlas$ATLAS_LIB_SUFFIX"

AC_SUBST(ATLAS_CFLAGS)
AC_SUBST(ATLAS_LIB_SUFFIX)
AC_SUBST(ATLAS_LIBS)
AC_SUBST(SYSTEM_LIBS)
AC_SUBST(OTHER_LIBS)

dnl Generate files

AC_CONFIG_FILES([
	Makefile
	Atlas/Makefile
	Atlas/Codecs/Makefile
	Atlas/Filters/Makefile
	Atlas/Funky/Makefile
	Atlas/Message/Makefile
	Atlas/Net/Makefile
	Atlas/Objects/Makefile
	tests/Makefile
	tests/Objects/Makefile
	tests/Codecs/Makefile
	tools/Makefile
	man/Makefile
	man/man1/Makefile
	benchmark/Makefile
	tutorial/Makefile
	atlas-cpp.spec
	mingw32-atlas-cpp.spec
	atlascpp-0.7.pc
])
AC_OUTPUT
