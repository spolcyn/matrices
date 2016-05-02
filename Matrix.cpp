//
//  Matrix.cpp
//  Matrices
//
//  Created by Stephen Polcyn on 12/11/15.
//  Copyright © 2015 SPYN Enterprises. All rights reserved.
//

#include "Matrix.hpp"

class MatrixOutOfBoundsException: public std::exception
{
  virtual const char* what() const throw()
  {
    return "The requested coordinate is not within the matrix.\n";
  }
} MatrixOutOfBoundsException;

Matrix::Matrix(int row, int column)
{
    dimensions = new Dimension(row, column);
    entryMatrix = std::vector<double>(row * column);

    //initialize to 0
    for(int x = 0; x < row * column; x++)
    {
        entryMatrix[x] = 0;
    }
}

Matrix::Matrix(Dimension& d, std::vector<double>& entries)
{
    dimensions = new Dimension(d);
    
    entryMatrix = entries;
}

void Matrix::validate(int row, int column) const
{
    if(!(row - 1 >= 0 && row - 1 < dimensions->rows && column - 1 >= 0 && column - 1 < dimensions->columns))
        throw MatrixOutOfBoundsException;
}

void Matrix::editEntry(Dimension d, double value)
{
    editEntry(d.rows, d.columns, value);
}

void Matrix::editEntry(int row, int column, double value)
{
    try
    {
        validate(row, column);
        entryMatrix[(row - 1) * dimensions->rows + (column - 1)] = value;
    }   
    catch(std::exception& e)
    {
        std::cout << e.what() << " (" << row << ", " << column << ")\n";
    }
}

double Matrix::getEntry(Dimension d) const
{
    return getEntry(d.rows, d.columns);
}

double Matrix::getEntry(int row, int column) const
{
    validate(row, column);
    return entryMatrix[(row - 1) * dimensions->rows + (column - 1)];
}

Dimension& Matrix::getDimensions() const
{
    return *dimensions;
}

//pads the number with spaces to ensure proper output format
std::string padding(double entry, short width)
{
    short n = 1;
    if (entry >= 100000000){entry /= 100000000; n += 8;}
    if (entry >= 10000){entry /= 10000; n += 4;}
    if (entry >= 100){entry /= 100; n += 2;}
    if (entry >= 10){entry /= 10; n += 1;}

    return std::string(width - n, ' ');
}

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
    double largestValue = 0;

    for(int row = 1; row <= m.dimensions->rows; row++)
    {
        for(int column = 1; column <= m.dimensions->columns; column++)
        {
            if(m.getEntry(row, column) > largestValue)
                largestValue = m.getEntry(row, column);
        }
    }

    //get required length
    short n = 1;
    if (largestValue >= 100000000){largestValue /= 100000000; n += 8;}
    if (largestValue >= 10000){largestValue /= 10000; n += 4;}
    if (largestValue >= 100){largestValue /= 100; n += 2;}
    if (largestValue >= 10){largestValue /= 10; n += 1;}
    short width = n;

    for(int row = 1; row <= m.dimensions->rows; row++)
    {
        os << "| ";

        for(int column = 1; column <= m.dimensions->columns; column++)
        {
            os << std::fixed;
            os.precision(3);
            os << m.getEntry(row, column) << padding(m.getEntry(row, column), width) << " | ";
        }
        
        os << std::endl;
    }
    
    return os;
}
