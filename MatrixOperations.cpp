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


class NonSquareMatrixException: public std::exception
{
	virtual const char* what() const throw()
	{
		return "The requested operation is not valid for a non-square matrix.\n";
	}
} NonSquareMatrixException;

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

Matrix& MatrixOperations::subsection(Matrx& m, Dimension& entryToExclude);
{
	Matrix* subsection = new Matrix(m.getDimensions().rows - 1, m.getDimensions().columns - 1);

	//create the minor sans the determinant
	for(int row = 1; row <= m.getDimensions().rows; row++)
	{
		if(row == entryToExclude.rows)
		{
			// skip
		}
		else
		{
			
				for(int column = 1; column < m.getDimensions().columns; column++)
				{
					if(column == entryToExclude.columns)
					{
						//skip
					}
					else
					{
						if(column > parentColumn)
							minor->editEntry(row - 1, column - 1, m.getEntry(row, column - 1));
						else if(column != parentColumn)
							minor->editEntry(row - 1, column, m.getEntry(row, column));
					}
				}
		}
	}
}

double MatrixOperations::determinant(Matrix &m)
{
	if(m.getDimensions().rows != m.getDimensions().columns)
		throw NonSquareMatrixException;

	if(m.getDimensions().rows == 2 && m.getDimensions().columns == 2)
	{
		return m.getEntry(1, 1) * m.getEntry(2, 2) - m.getEntry(1, 2) * m.getEntry(2, 1);
	}
	else
	{
		int startColumn = 1;

		for(int parentColumn = startColumn; parentColumn <= m.getDimensions().columns; parentColumn++)
		{
			Matrix* minor = new Matrix(m.getDimensions().rows - 1, m.getDimensions().columns - 1);

			//create the minor sans the determinant
			for(int row = 2; row <= m.getDimensions().rows; row++)
			{
				for(int column = 1; column < m.getDimensions().columns; column++)
				{
					if(column > parentColumn)
						minor->editEntry(row - 1, column - 1, m.getEntry(row, column - 1));
					else if(column != parentColumn)
						minor->editEntry(row - 1, column, m.getEntry(row, column));
				}
			}

			return ((-2) * (1 + parentColumn) % 2 + 1) * MatrixOperations::determinant(*minor);
		}
	}
}

// Matrix& MatrixOperations::invert(Matrix &m)
// {

// }


#endif