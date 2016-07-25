CC=g++
CFLAGS=-std=c++11 -g
SRCDIR := src
BUILDDIR := build 
TARGET := bin/matrices

_OBJ = main.o Matrix.o MatrixOperations.o
OBJ = $(patsubst %, $(BUILDDIR)/%, $(_OBJ))

all: matrices

matrices: $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c -o $@ $< $(CFGLAGS)

clean:
	rm -f $(BUILDDIR)/*.o $(TARGET)
