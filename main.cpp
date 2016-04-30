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
    
    Matrix* m = new Matrix(*new Dimension(5,5));

    m->editEntry(1, 1, 50000);
    m->editEntry(5, 5, 10000);

    Matrix* n = new Matrix(*new Dimension(5, 5));

    n->editEntry(1, 1, 5);

    cout << *m;

    cout << MatrixOperations::subtract(*n, *m);
}
