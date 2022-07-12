CC := g++
SRCDIR := src
TSTDIR := tests
OBJDIR := build
BINDIR := bin

TARGET := main
MAIN := program/main.cpp
TESTER := program/tester.cpp

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
TSTSOURCES := $(shell find $(TSTDIR) -type f -name *.$(SRCEXT))

CFLAGS := -g --coverage -Wall -O3 -std=c++17
INC := -I include/ -I third_party/

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

main: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(MAIN) $^ -o $(BINDIR)/main

tests: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(TESTER) $(TSTSOURCES) $^ -o $(BINDIR)/tester
	$(BINDIR)/tester

all: main

clean:
	$(RM) -r $(OBJDIR)/* $(BINDIR)/* coverage/* *.gcda *.gcno

check:
	./$(TARGET) --help

distcheck:
	$(RM) -r $(BUILDDIR)/*

test:
	./$(BINDIR)/$(TARGET) --test endereco && echo "OK" || exit "Erro!";
	./$(BINDIR)/$(TARGET) --test usuario && echo "OK" || exit "Erro!";
	./$(BINDIR)/$(TARGET) --test produtos && echo "OK" || exit "Erro!";
	./$(BINDIR)/$(TARGET) --test atributos && echo "OK" || exit "Erro!";
	./$(BINDIR)/$(TARGET) --test estoqueBase && echo "OK" || exit "Erro!";

.PHONY: clean