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

class MatrixOperations 
{

public:

	static Matrix& add(Matrix &m, Matrix& n);

	static Matrix& subtract(Matrix &m, Matrix& n);

	static void subtract(Matrix &m, int mRow, Matrix &n);

	static Matrix& multiply(Matrix& m, Matrix& n);

	static Matrix& multiply(Matrix& m, double scalar);

	static Matrix& subsection(Matrix& m, Dimension& entryToExclude);

	static void swapRow(Matrix& m, int from, int to);

	static void swapColumn(Matrix& m, int from, int to);

	static double determinant(Matrix& m);

	static Matrix& transpose(Matrix& m);

	static Matrix& ref(Matrix& m);

	static Matrix& rref(const Matrix& m);

	static Matrix& invert(Matrix& m);

	static Matrix& findBasis(Matrix& m);

};

#endif