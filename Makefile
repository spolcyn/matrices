CC=g++

all: matrices

matrices: main.o Matrix.o MatrixOperations.o
	$(CC) main.o Matrix.o MatrixOperations.o -o matrices

main.o: main.cpp Matrix.o
	$(CC) -c main.cpp

Matrix.o: Matrix.cpp Matrix.hpp
	$(CC) -c Matrix.cpp

MatrixOperations.o: Matrix.o MatrixOperations.hpp MatrixOperations.cpp
	$(CC) -c MatrixOperations.cpp

clean:
	rm *.o matrices