# This was needed to work around "number of sections exceeded object file format limit" linker error
win32:QMAKE_CXXFLAGS += /bigobj

FLEXSOURCES += $$PWD/symbol_scanner.ll
BISONSOURCES += $$PWD/symbol_parser.yy

SOURCES += \
	$$PWD/symboldata.cpp \
	$$PWD/symbolscanner.cpp
 
HEADERS += \
	$$PWD/symboldata.h \
	$$PWD/symbolscanner.h

