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

#define DEBUG_RREF


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

class MatrixNotInvertibleException: public std::exception
{
	virtual const char* what() const throw()
	{
		return "The matrix is not invertible.\n";
	}
} MatrixNotInvertibleException;

class NotVectorException: public std::exception
{
	virtual const char* what() const throw()
	{
		return "The provided matrix is not a vector.\n";
	}
} NotVectorException;

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

void MatrixOperations::subtract(Matrix &m, int mRow, Matrix &n)
{
	if(n.getDimensions().rows != 1 && n.getDimensions().columns != 1)
		throw NotVectorException;


	if(n.getDimensions().rows == 1)
	{
		for(int column = 1; column <= n.getDimensions().columns; column++)
		{
			m.editEntry(mRow, column, m.getEntry(mRow, column) - n.getEntry(1, column));
		}
	}
	else
	{
		for(int row = 1; row <= n.getDimensions().rows; row++)
		{
			m.editEntry(mRow, row, m.getEntry(mRow, row) - n.getEntry(1, row));
		}
	}
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

Matrix& MatrixOperations::multiply(Matrix &m, double scalar)
{
	Matrix* o = new Matrix(m.getDimensions());

	for(int row = 1; row <= m.getDimensions().rows; row++)
	{
		for(int column = 1; column <= m.getDimensions().columns; column++)
		{
			o->editEntry(row, column, m.getEntry(row, column) * scalar);
		}
	}

	return *o;
}


Matrix& MatrixOperations::subsection(Matrix& m, Dimension& entryToExclude)
{
	if(m.getDimensions().rows == 1 && m.getDimensions().columns == 1)
		return m;

	Matrix* subsection = new Matrix(m.getDimensions().rows - 1, m.getDimensions().columns - 1);

	int rowDifferential = 0, columnDifferential = 0;

	//create the minor sans the determinant
	for(int row = 1; row <= m.getDimensions().rows; row++)
	{
		if(row == entryToExclude.rows)
		{
			rowDifferential = -1;
		}
		else
		{
			
				for(int column = 1; column <= m.getDimensions().columns; column++)
				{
					if(column == entryToExclude.columns)
					{
						columnDifferential = -1;
					}
					else
					{
							subsection->editEntry(row + rowDifferential, column + columnDifferential, m.getEntry(row, column));
					}
				}
		}
	}

	return *subsection;
}

void MatrixOperations::swapRow(Matrix &m, int from, int to)
{
	for(int column = 1; column <= m.getDimensions().columns; column++)
	{
		m.swapEntry(from, column, to, column);
	}
}

void MatrixOperations::swapColumn(Matrix &m, int from, int to)
{
	for(int row = 1; row <= m.getDimensions().rows; row++)
	{
		m.swapEntry(row, from, row, to);
	}
}

double MatrixOperations::determinant(Matrix &m)
{
	if(m.getDimensions().rows != m.getDimensions().columns)
		throw NonSquareMatrixException;

	if(m.getDimensions().rows == 2) //will be square, don't have to check columns
	{
		return m.getEntry(1, 1) * m.getEntry(2, 2) - m.getEntry(1, 2) * m.getEntry(2, 1);
	}
	else if(m.getDimensions().rows == 1) //will be square, don't have to check columns
	{
		return m.getEntry(1, 1);
	}
	else
	{
		int startColumn = 1;
		int row = 1;

		for(int parentColumn = startColumn; parentColumn <= m.getDimensions().columns; parentColumn++)
		{
			return ((-2) * (1 + parentColumn) % 2 + 1) * MatrixOperations::determinant(MatrixOperations::subsection(m, *new Dimension(row, parentColumn)));
		}
	}

	//this should never happen
	return -0;
}

Matrix& MatrixOperations::transpose(Matrix& m)
{
	Matrix* transpose = new Matrix(m.getDimensions());

	for(int row = 1; row <= m.getDimensions().rows; row++)
	{
		for(int column = 1; column <= m.getDimensions().columns; column++)
		{
			transpose->editEntry(row, column, m.getEntry(column, row));
		}
	}

	return *transpose;
}


Matrix& MatrixOperations::invert(Matrix &m)
{
	if(MatrixOperations::determinant(m) == 0)
		throw MatrixNotInvertibleException;

	//create minor matrix & cofactor at same time
	Matrix* cofactor = new Matrix(m.getDimensions());

	for(int row = 1; row <= m.getDimensions().rows; row++)
	{
		for(int column = 1; column <= m.getDimensions().columns; column++)
		{
			cofactor->editEntry(row, column, (-2 * ((row + column) % 2) + 1) * MatrixOperations::determinant(MatrixOperations::subsection(m, *new Dimension(row, column))));
		}
	}

	//create adjoint
	Matrix* adjoint = &MatrixOperations::transpose(*cofactor);
	#ifdef DEBUG_INVERSE
	std::cout << "Original: \n" << m << std::endl;
	std::cout << "Cofactor: \n" << *cofactor << std::endl;
	std::cout << "Adjoint: \n" << *adjoint << std::endl;
	#else
	delete cofactor;
	#endif


	//multiply by one over the determinant
	Matrix* inverse = &MatrixOperations::multiply(*adjoint, 1.0 / MatrixOperations::determinant(m));
	#ifdef DEBUG_INVERSE
	std::cout << "Inverse: \n" << *inverse << std::endl;
	#else
	delete adjoint;
	#endif

	return *inverse;

}

// Matrix& MatrixOperations::ref(Matrix& m)

Matrix& MatrixOperations::rref(const Matrix& m)
{
	Matrix* returnM = new Matrix(m);

	#ifdef DEBUG_RREF
	std::cout << "returnM: " << returnM << std::endl;
	std::cout << "*returnM: \n" << *returnM;
	#endif

	//https://www.csun.edu/~panferov/math262/262_rref.pdf
	int i = 1, j = 1;

	while(i <= m.getDimensions().rows && j <= m.getDimensions().columns)
	{
		//Step 1
		while(m.getEntry(i, j) == 0)
		{
			//find a row that does not start with 0
			for(row = i; row <= m.getDimensions().rows; row++)
			{
				if(m.getEntry(row, j) = 0)
					break;	
			}

			
		}	

		//Step 2
	}

	return *returnM;
}        
	

// Matrix& MatrixOperations::findBasis(Matrix& m)



#endif
