//
//  main.cpp
//  Matrices
//
//  Created by Stephen Polcyn on 12/11/15.
//  Copyright © 2015 SPYN Enterprises. All rights reserved.
//

#include <iostream>
#include "Matrix.hpp"
#include "MatrixOperations.hpp"


using namespace std;

int main(int argc, const char * argv[]) {    
    
    Matrix* m = new Matrix(2, 2);

    m->editEntry(1, 1, 2);
    m->editEntry(1, 2, 7);
    m->editEntry(2, 1, 9);
    m->editEntry(2, 2, 16);

    // Matrix* n = new Matrix(5, 3);

    // n->editEntry(1, 1, 10);
    // n->editEntry(2, 2, 200);
    // n->editEntry(3, 3, 3);
    // n->editEntry(4, 3, 43.0);

    //cout << "M: \n\n" << *m << "\n\n";
    //cout << "N: \n\n" << *n << "\n\n";

	cout << MatrixOperations::multiply(MatrixOperations::invert(*m), *m);
}
