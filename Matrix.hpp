//
//  Matrix.hpp
//  Matrices
//
//  Created by Stephen Polcyn on 12/11/15.
//  Copyright © 2015 SPYN Enterprises. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <iostream>

/**
* 2-D Coordinate Class with row / column
*/
struct Dimension {
    int rows, columns;
    
    /**
    *Constructor
    *@param r Dimension row
    *@param c Dimension column
    */
    Dimension(int r, int c)
    {
        rows = r;
        columns = c;
    }
    
    /**
    *Constructor
    *@param d Dimension object
    */
    Dimension(Dimension &d)
    {
        rows = d.rows;
        columns = d.columns;
    }

    friend bool operator!=(const Dimension& d1, const Dimension& d2)
    {
        return (d1.rows != d2.rows) || (d1.columns != d2.columns);
    }
};

/**
*Represents an r x c matrix
*/
class Matrix {
    
    /**
    *The dimensions of the matrix
    */
    Dimension* dimensions;

    /**
    *The array storing the entries of the matrix
    */
    double* entryMatrix;
    
public:
    
    /**
    *Constructor
    *@param d Dimensions for the 0-initialized matrix
    */
    Matrix(Dimension& d);
    
    /**
    *Constructor
    *@param d Dimensions for the matrix
    *@param entries Array with entries for the matrix of size r * c
    */
    Matrix(Dimension& d, double& entries);

    /**
    *Edits the entry at {@code d}, replacing it with {@code value}
    *@param d Coordinate of the entry
    *@param value New value of entry
    */
    void editEntry(Dimension d, double value);

    /**
    *Edits the entry at {@code (row, column)}, replacing it with {@code value}
    *@param row Row of the entry
    *@param column Column of the entry
    *@param value New value of entry
    */
    void editEntry(int row, int column, double value);
    
    /**
    *Returns the value at the given coordinate
    *@param d Coordinate of the entry
    *@return Value of the entry at that coordinate
    */
    double getEntry(Dimension d) const;

    /**
    *Returns the value at the given coordinate
    *@param row Row of the entry
    *@param column Column of the entry
    *@return Value of the entry at that coordinate
    */
    double getEntry(int row, int column) const;

    /**
    *Returns the dimensions of the patrix
    *@return Dimensions of the matrix
    */
    Dimension& getDimensions() const;
    
    /**
    *Nicely outputs the matrix in text format
    *@param os An ostream object
    *@param matrix A matrix to output
    *@return The edited ostream object
    */
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

};
#endif /* Matrix_hpp */
