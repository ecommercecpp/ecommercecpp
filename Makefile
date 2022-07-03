CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -std=c++17 -g -Wall -O3
INC := -I include/ -I third_party/

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)

check:
	./$(TARGET) --help

distcheck:
	$(RM) -r $(BUILDDIR)/*

test:
	./$(TARGET) --test endereco && echo "OK" || exit "Erro!";
	./$(TARGET) --test usuario && echo "OK" || exit "Erro!";
	./$(TARGET) --test produtos && echo "OK" || exit "Erro!";
	./$(TARGET) --test atributos && echo "OK" || exit "Erro!";
	./$(TARGET) --test estoqueBase && echo "OK" || exit "Erro!";