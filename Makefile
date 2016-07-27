CXX      = g++
DEBUG    = -g -O0
CXXFLAGS = $(shell fltk-config --use-images --cxxflags ) -I.
LDFLAGS  = $(shell fltk-config --use-images --ldflags )
LDSTATIC = $(shell fltk-config --use-images --ldstaticflags ) -lautils
LINK     = $(CXX)

TARGET = lblog
OBJS_LBLOG = $(OBJS_COMMON) Gui.o logic.o
SRCS = Gui.cxx logic.cxx

# this is a pattern rule
.SUFFIXES: .o .cxx
%.o: %.cxx
	$(CXX) $(CXXFLAGS) $(DEBUG) -c $<

all: lblog

lblog: $(OBJS_LBLOG) Makefile
	$(LINK) -o lblog $(LDDFLAGS) $(OBJS_LBLOG) $(LDSTATIC)

clean:
	rm -f *.o 2> /dev/null
	rm -f $(TARGET) 2> /dev/null

install:
	install ./lblog /usr/local/bin
