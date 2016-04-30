//
//  Matrix.cpp
//  Matrices
//
//  Created by Stephen Polcyn on 12/11/15.
//  Copyright © 2015 SPYN Enterprises. All rights reserved.
//

#include "Matrix.hpp"

void Matrix::editEntry(Dimension d, double value)
{
    editEntry(d.rows, d.columns, value);
}

void Matrix::editEntry(int row, int column, double value)
{
    *(entryMatrix + (row - 1) * dimensions->rows + (column - 1)) = value;
}

double Matrix::getEntry(Dimension d) const
{
    return getEntry(d.rows, d.columns);
}

double Matrix::getEntry(int row, int column) const
{
    return *(entryMatrix + (row - 1) * dimensions->rows + (column - 1));
}

Matrix::Matrix(Dimension& d)
{
    dimensions = new Dimension(d);
    entryMatrix = new double[d.rows * d.columns];
    
    //initialize to 0
    for(int x = 0; x < d.rows * d.columns; x++)
    {
        entryMatrix[x] = 0.0;
    }
}

Matrix::Matrix(Dimension& d, double& entries)
{
    dimensions = new Dimension(d);
    
    entryMatrix = &entries;
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
            os << std::fixed << m.getEntry(row, column) << padding(m.getEntry(row, column), width) << " | ";
        }
        
        os << std::endl;
    }
    
    return os;
}
