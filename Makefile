CC=g++
CFLAGS=-std=c++11 -g
SRCDIR:=src
BUILDDIR:=build
TARGET:=bin/matrices

#CPP_FILES := $(wildcard $(SRCDIR)/*.cpp)
#OBJ_FILES := $(patsubst src/%.cpp,build/%.o,$(CPP_FILES))

#$(warning $(CPP_FILES))
#$(warning $(OBJ_FILES))
#$(warning $(BUILDDIR)/Matrix.o)

all: $(TARGET)

$(TARGET): $(BUILDDIR)/main.o $(BUILDDIR)/Matrix.o $(BUILDDIR)/MatrixOperations.o 
	$(CC) $(CFLAGS) -o $@ $^ 

$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp 
	$(CC) $(CFLAGS) -c -o $@ $^ 

$(BUILDDIR)/Matrix.o: $(SRCDIR)/Matrix.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILDDIR)/MatrixOperations.o: $(SRCDIR)/MatrixOperations.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

# TODO: Add docs target

clean:
	rm -f $(BUILDDIR)/*.o $(TARGET)
