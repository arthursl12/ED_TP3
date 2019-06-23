CC := g++
MYDIR := $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
BUILDDIR := build
TARGET := main

SRCEXT := cpp
CFLAGS := --coverage -g -Wall -Wno-unknown-pragmas -O3 -std=c++11
T_CFLAGS := --coverage -g -Wall -O3
INC := -I include


MODULES = arvore decodificador
SOURCES = $(addsuffix .cpp,$(MODULES))
OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))

SOURCEDIR = $(addprefix $(MYDIR),$(SOURCES))
OBJDIR = $(addprefix build/,$(OBJECTS))
TGTDIR = $(TARGET)

all: $(TGTDIR)

$(OBJDIR): build/%.o : %.cpp
	@echo ""
	@echo OBJETO: $@
	$(shell mkdir -p build)
	$(CC) $(INC) $(CFLAGS) -c $(patsubst build/%.o,%.cpp,$@) -o $@

$(TGTDIR): $(OBJDIR)
	@echo ""
	@echo COMPILANDO MAIN
	$(CC) $(INC) $(CFLAGS) $(OBJDIR) $(TARGET).cpp -o $(TGTDIR)
	$(RM) main.gcno

run:
	@main
	$(RM) main.gcno
	$(RM) main.gcda

clean:
	$(RM) -r build/* *.gcda *.gcno *.gcov *.o main

.PHONY: clean coverage



