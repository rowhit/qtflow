# This was needed to work around "number of sections exceeded object file format limit" linker error
win32:QMAKE_CXXFLAGS += /bigobj

FLEXSOURCES += $$PWD/vcd_scanner.ll
BISONSOURCES += $$PWD/vcd_parser.yy

SOURCES += \
	$$PWD/vcd_data.cpp \
	$$PWD/vcd_loader.cpp

HEADERS += \
	$$PWD/vcd_data_fwd.hpp \
	$$PWD/vcd_data.hpp \
	$$PWD/vcd_error.hpp \
	$$PWD/vcd_lexer.hpp \
	$$PWD/vcd_loader.hpp

