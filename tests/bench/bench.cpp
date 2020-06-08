#include <cstdlib>
#include <chrono>
#include "../src/MatrixOperations.hpp"
#include "../src/Matrix.hpp"
#include <iostream>

int main() 
{
    int MATRIX_ROW = 5;
    int MATRIX_COL = 5;

    Matrix* m = new Matrix(MATRIX_ROW, MATRIX_COL);
    
    for(int i = 1; i <= MATRIX_ROW; i++) {
        for(int j = 1; j <= MATRIX_COL; j++) {
            m->editEntry(i, j, rand());
        }
    }

    auto start = std::chrono::steady_clock::now();

    // this throughput test is probably semi non-realistic given that it'll 
    // likely always cache hit
    int MAX_TRIALS = 1000000;
    for(int i = 0; i < MAX_TRIALS; i++) {
        MatrixOperations::add(*m, *m);
    }

    auto end = std::chrono::steady_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

	std::cout << elapsed;

}
