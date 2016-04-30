//
//  MatrixOperations.cpp
//  Matrices
//
//  Created by Stephen Polcyn on 4/29/16.
//  Copyright © 2016 SPYN Enterprises. All rights reserved.
//

#ifndef MatrixOperations_cpp
#define MatrixOperations_cpp

#include "MatrixOperations.hpp"
#include <exception>

class MatrixDimensionException: public std::exception
{
  virtual const char* what() const throw()
  {
    return "The matrixes do not have compatible dimensions.\n";
  }
} MatrixDimensionException;

Matrix& MatrixOperations::add(Matrix &m, Matrix& n)
{
	if(m.getDimensions() != n.getDimensions())
		throw MatrixDimensionException;

	Matrix* o = new Matrix(m.getDimensions());

	for(int row = 1; row <= o->getDimensions().rows; row++)
	{
		for(int column = 1; column <= o->getDimensions().columns; column++)
		{
			o->editEntry(row, column, m.getEntry(row, column) + n.getEntry(row, column));
		}
	}

	return *o;
}

Matrix& MatrixOperations::subtract(Matrix &m, Matrix& n)
{
	if(m.getDimensions() != n.getDimensions())
		throw MatrixDimensionException;

	Matrix* o = new Matrix(m.getDimensions());

	for(int row = 1; row <= o->getDimensions().rows; row++)
	{
		for(int column = 1; column <= o->getDimensions().columns; column++)
		{
			o->editEntry(row, column, m.getEntry(row, column) - n.getEntry(row, column));
		}
	}

	return *o;
}

Matrix& MatrixOperations::multiply(Matrix &m, Matrix &n)
{
	if(m.getDimensions().columns != n.getDimensions().rows)
		throw MatrixDimensionException;

	Matrix* o = new Matrix(*new Dimension(m.getDimensions().rows, n.getDimensions().columns));

	double product = 0;

	for(int row = 1; row <= m.getDimensions().rows; row++)
	{
		for(int column = 1; column <= n.getDimensions().columns; column++)
		{
			for(int row2 = 1; row2 <= n.getDimensions().rows; row2++)
			{
				product += m.getEntry(row, row2) * n.getEntry(row2, column);
			}

			o->editEntry(row, column, product);

			product = 0;
		}
	}

	return *o;
}


#endif