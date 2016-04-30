CC=g++

all: matrices

matrices: main.o Matrix.o 
	$(CC) main.o Matrix.o -o matrices

main.o: main.cpp Matrix.o
	$(CC) -c main.cpp

Matrix.o: Matrix.cpp Matrix.hpp
	$(CC) -c Matrix.cpp

clean:
	rm *.o matrices