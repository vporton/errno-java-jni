## Process this file with automake to produce Makefile.in

## Created by Anjuta

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\"

AM_CFLAGS =\
	 -Wall\
	 -g

lib_LTLIBRARIES = liberrno_java_jni.la


liberrno_java_jni_la_SOURCES = \
	Java_Errno.c

liberrno_java_jni_la_LDFLAGS = 

liberrno_java_jni_la_LIBADD = 


if PLATFORM_WIN32
liberrno_java_jni_la_LDFLAGS += -no-undefined
endif

if NATIVE_WIN32
liberrno_java_jni_la_LDFLAGS += -export-dynamic
endif

include_HEADERS = \
	Java_Errno.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = errno_java_jni-0.1.pc

EXTRA_DIST = \
	errno_java_jni-0.1.pc.in
