SHELL = /bin/sh
ARCH = Linux-gcc4
MYLCGPLATFORM = x86_64-slc5-gcc43-opt
SHAREDLIBS = no
FC = gfortran
CC = gcc
FFLAGS = -O2
CFLAGS = -O2
CXXFLAGS = -O2 -ansi -pedantic -W -Wall -Wshadow
FLIBS = -lgfortran -lgfortranbegin
LDFLAGSSHARED = -O2 -ansi -pedantic -W -Wall -Wshadow -fPIC -shared
LDFLAGLIBNAME = -Wl,-soname
SHAREDSUFFIX = so
INSTALLDIR = ../pythiabuild
DATADIR = ../pythiabuild
