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
#include <vector>

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
    *Copy Constructor
    *@param d Dimension object
    */
    Dimension(const Dimension &d)
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
    
    /**
    *Validates the coordinate entered
    */
    void validate(int row, int column) const;

public:
    
    /**
    *Constructor
    *@param row Number of rows in the matrix
    *@param column Number of columns in the matrix
    */
    Matrix(int row, int column);

    /**
    *Constructor
    *@param d Dimensions for the 0-initialized matrix
    */
    Matrix(Dimension& d) : Matrix(d.columns, d.rows) {}
    
    /**
    *Constructor
    *@param d Dimensions for the matrix
    *@param entries Array with entries for the matrix of size r * c
    */
    Matrix(Dimension& d, double* entries);

    /**
    *Copy constructor
    *@param m Matrix to copy
    */
    Matrix(const Matrix& m);

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
    *Returns the value at the given coordinate, 1-indexed
    *@param row Row of the entry
    *@param column Column of the entry
    *@return Value of the entry at that coordinate
    */
    double getEntry(int row, int column) const;

    /**
    *Swaps the entry in (row, column) with (row, column)
    *@param i1 Row entry 1
    *@param j1 Column entry 1
    *@param i2 Row entry 2
    *@param j2 Column entry 2
    */
    void swapEntry(int i1, int j1, int i2, int j2);

    /**
    *Returns a row of a matrix as a row vector
    *@param row The row to retrieve
    *@return Specified row of the matrix
    */
    Matrix& getRow(int row) const;

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
