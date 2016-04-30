//
//  MatrixOperations.hpp
//  Matrices
//
//  Created by Stephen Polcyn on 4/29/16.
//  Copyright © 2016 SPYN Enterprises. All rights reserved.
//

#ifndef MatrixOperations_hpp
#define MatrixOperations_hpp

#include "Matrix.hpp"

Matrix& add(Matrix &m, Matrix& n);

Matrix& subtract(Matrix &m, Matrix& n);

Matrix& multiply(Matrix& m, Matrix& n);

Matrix& ref(Matrix& m);

Matrix& rref(Matrix& m);

Matrix& invert(Matrix& m);

Matrix& findBasis(Matrix& m);

#endif