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

    std::cout << (MatrixOperations::rref(*m));

}
