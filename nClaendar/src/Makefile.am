## Process this file with automake to produce Makefile.in

## Created by Anjuta - will be overwritten
## If you don't want it to overwrite it,
## 	Please disable it in the Anjuta project configuration

INCLUDES = \
	$(WX_CXXFLAGS)

AM_CXXFLAGS =\
	-march=athlon-xp -fomit-frame-pointer -pipe -falign-functions=64\
	 -Wall\
	 -O3\
	 -g

bin_PROGRAMS = nclaendar

nclaendar_SOURCES = \
	ncal.h\
	ncal.cpp\
	tipi.cpp\
	tipi.h\
	profMan.cpp\
	profMan.h\
	smllDlgs.h\
	smllDlgs.cpp\
	hdCtrl.h\
	hdCtrl.cpp\
	prefDlg.h\
	prefDlg.cpp

nclaendar_LDFLAGS = 

nclaendar_LDADD =  \
	$(WX_LIBS)

