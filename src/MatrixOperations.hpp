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

	static Matrix& add(const Matrix &m, const Matrix& n);

	static Matrix& subtract(const Matrix &m, const Matrix& n);

	static void subtract(Matrix &subtractFrom, int mRow, const Matrix &toSubtract);

	static Matrix& multiply(const Matrix& m, const Matrix& n);

	static Matrix& multiply(const Matrix& m, double scalar);

	static Matrix& subsection(const Matrix& m, Dimension& entryToExclude);

	static void swapRow(Matrix& m, int from, int to);

	static void swapColumn(Matrix& m, int from, int to);

	static double determinant(const Matrix& m);

	static Matrix& transpose(const Matrix& m);

	static Matrix& ref(const Matrix& m);

	static Matrix& rref(const Matrix& m);

	static Matrix& invert(const Matrix& m);

	static Matrix& findBasis(const Matrix& m);

};

#endif
