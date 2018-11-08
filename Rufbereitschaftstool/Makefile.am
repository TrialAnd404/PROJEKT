ACLOCAL_AMFLAGS = -I m4
AUTOMAKE_OPTIONS = subdir-objects
AM_CPPFLAGS = -I$(top_srcdir)/include

bin_PROGRAMS = Rufbereitschaftstool

ecppSources = \
	actionmain.ecpp \
	json/example.ecpp \
	json/getnumbers.ecpp \
	json/dbaccess.ecpp \
	html/rufbereitschaftstable.ecpp \
	action/insertdata.ecpp \
	action/myaction.ecpp \
	webmain.ecpp

staticSources = \
    resources/app/actions.js \
    resources/app/json.js \
    resources/app/main.js \
    resources/app/dbaccess.js \
    resources/app/dbinsert.js \
    resources/app/rufbereitschaftstool.js \
    resources/css/noty/themes/nest.css \
    resources/css/noty/themes/relax.css \
    resources/css/noty/themes/mint.css \
    resources/css/noty/themes/semanticui.css \
    resources/css/noty/themes/light.css \
    resources/css/noty/themes/metroui.css \
    resources/css/noty/themes/sunset.css \
    resources/css/noty/themes/bootstrap-v4.css \
    resources/css/noty/themes/bootstrap-v3.css \
    resources/css/Rufbereitschaftstool.css \
    resources/css/statusbar.css \
    resources/css/noty.css.map \
    resources/css/noty.css \
    resources/css/datatables.css \
    resources/css/dropdown.css \
    resources/html/json.html \
    resources/html/day.html \
    resources/html/dbaccess.html \
    resources/html/dbinsert.html \
    resources/html/actions.html \
    resources/html/rufbereitschaftstool.html \
    resources/js/require.js \
    resources/js/main.js \
    resources/js/jquery-3.3.1.min.js \
    resources/js/noty.min.js \
    resources/js/tntnet.js \
    resources/js/datatables.js \
    resources/js/noty.js

noinst_HEADERS = \
	action.ecpp \
	include/actionreply.h \
	include/noty.h \
     	include/Rufbereitschaftstool/config.h \ 
        include/RufbereitschaftsData/rufbereitschaftsdata.h \
        include/PersonalInfo/personalinfo.h \
        include/MonthInfo/monthinfo.h

Rufbereitschaftstool_SOURCES = \
	src/Rufbereitschaftstool/config.cpp \
	src/main.cpp \
        src/RufbereitschaftsData/rufbereitschaftsdata.cpp \
        src/MonthInfo/monthinfo.cpp \
        src/PersonalInfo/personalinfo.cpp \
	$(ecppSources)

nodist_Rufbereitschaftstool_SOURCES = \
	resources.cpp

Rufbereitschaftstool_LDADD = -lcxxtools -ltntnet -ltntdb

nobase_dist_noinst_DATA = $(staticSources) Rufbereitschaftstool.xml

CLEANFILES = $(ecppSources:.ecpp=.cpp) $(ecppSources:.ecpp=.deps) resources.cpp

#
# Rules for tntnet applications
#
ECPPFLAGS=-I$(srcdir)

resources.cpp: $(staticSources) Makefile.am
	$(AM_V_GEN)$(ECPPC) -bb -z -n resources -p -o resources.cpp $(ECPPFLAGS) $(staticSources)

SUFFIXES=.ecpp .cpp

.ecpp.cpp:
	$(AM_V_GEN)$(ECPPC) -n `echo $<|$(SED) 's|^$(srcdir)/||; s|\.ecpp$$||'` $(ECPPFLAGS) -o $@ $<
.ecpp.deps:
	$(AM_V_GEN)$(ECPPC) -M $(ECPPFLAGS) $< | $(SED) '1s|\(.*\).cpp:|\1.cpp $@:|' > $@

-include $(ecppSources:.ecpp=.deps)
