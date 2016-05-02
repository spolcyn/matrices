CC=g++
CFLAGS=-std=c++11

all: matrices

matrices: main.o Matrix.o MatrixOperations.o
	$(CC) $(CFLAGS) main.o Matrix.o MatrixOperations.o -o matrices

main.o: main.cpp Matrix.o
	$(CC) $(CFLAGS) -c main.cpp

Matrix.o: Matrix.cpp Matrix.hpp
	$(CC) $(CFLAGS) -c Matrix.cpp

MatrixOperations.o: Matrix.o MatrixOperations.hpp MatrixOperations.cpp
	$(CC) $(CFLAGS) -c MatrixOperations.cpp

clean:
	rm *.o matrices