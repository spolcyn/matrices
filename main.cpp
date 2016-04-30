//
//  main.cpp
//  Matrices
//
//  Created by Stephen Polcyn on 12/11/15.
//  Copyright © 2015 SPYN Enterprises. All rights reserved.
//

#include <iostream>
#include "Matrix.hpp"


using namespace std;

int main(int argc, const char * argv[]) {    
    
    Matrix* m = new Matrix(*new Dimension(5,5));

    m->editEntry(1, 1, 5000000);
    m->editEntry(5, 5, 10000);

    cout << *m;
}
