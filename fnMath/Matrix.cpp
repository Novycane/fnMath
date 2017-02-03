//
//  Matrix.cpp
//  fnMath
//
//  Created by Steven Novak on 2/1/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#ifndef MATRIX_CPP
#define MATRIX_CPP

#include "Matrix.hpp"
#include <iostream>

namespace fnMath{
namespace LinAlg{


#pragma mark Constructors
// ---------------------------------------- Constructors

template <typename Numeric>
Matrix<Numeric>::Matrix()
{
    cout << "Generic Constructor\n";
    rows = 0;
    columns = 0;
}
    
    
template <typename Numeric>
Matrix<Numeric>::Matrix(Numeric value, int NumberOfRows, int NumberOfColumns)
{
    
    #ifdef __DEBUG__
        cout << "Value Constructor\n";
    #endif
    
    rows = NumberOfRows;
    columns = NumberOfColumns;
    
    data.resize(rows);
    for(int i=0; i < rows; i++)
    {
        data[i].resize(columns);
        for(int j=0; j<columns; j++)
            data[i][j] = value;
    }
}

template <typename Numeric>
Matrix<Numeric>::~Matrix() {}

template <typename Numeric>
Matrix<Numeric>::Matrix(const Matrix<Numeric> & rhs)
{
    #ifdef __DEBUG__
        cout << "Copy Constructor\n";
    #endif
    
    rows = rhs.rows;
    columns = rhs.rows;
    
    data.resize(rows);
    for(int i=0; i<rows; i++)
    {
        data[i].resize(columns);
        for(int j=0; j<columns; j++)
            data[i][j] = rhs[i][j];
    }
}

template <typename Numeric>
Matrix<Numeric>::Matrix(Matrix<Numeric> && rhs)
{
    #ifdef __DEBUG__
        cout << "Move Constructor\n";
    #endif
    
    rows = rhs.rows;
    columns = rhs.rows;
    data = std::move(rhs.data);
}

    
#pragma mark Operators
// ---------------------------------------- Operators
    
template <typename Numeric>
Matrix<Numeric> & Matrix<Numeric>::operator=(const Matrix<Numeric> & rhs)
{
    #ifdef __DEBUG__
        cout << "Copy\n";
    #endif
    
    rows = rhs.rows;
    columns = rhs.columns;
    data = rhs.data;
    
    return *this;
}

template <typename Numeric>
Matrix<Numeric> & Matrix<Numeric>::operator=(Matrix<Numeric> && rhs)
{
    #ifdef __DEBUG__
        cout << "Move\n";
    #endif
    
    rows = rhs.rows;
    columns = rhs.columns;

    data = std::move(rhs.data);

    return *this;
}

template<typename Numeric>
const vector<Numeric>& Matrix<Numeric>::operator[](int i) const
{
    return data[i];
}

template<typename Numeric>
vector<Numeric>& Matrix<Numeric>::operator[](int i)
{
    return data[i];
}

template <typename Numeric>
Matrix<Numeric> Matrix<Numeric>::operator+(const Matrix<Numeric> & rhs)
{
    if(rhs.rows != rows || rhs.columns != columns)
        throw new DimensionMismatchException();
    
    Matrix<Numeric> result(0,rows,columns);
    
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            result[i][j] = data[i][j] + rhs[i][j];
        
    return result;
}

template <typename Numeric>
Matrix<Numeric> Matrix<Numeric>::operator-(const Matrix<Numeric> & rhs)
{
    if(rhs.rows != rows || rhs.columns != columns)
        throw new DimensionMismatchException();
    
    Matrix<Numeric> result(0,rows,columns);
    
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            result[i][j] = data[i][j] - rhs[i][j];
    
    return result;
}

template <typename Numeric>
Matrix<Numeric> Matrix<Numeric>::operator*(const Matrix<Numeric> & rhs)
{
    if(columns != rhs.rows)
        throw new DimensionMismatchException();
    
    Matrix<Numeric> C(0, rows, rhs.columns);
    
    for(int i=0; i<C.rows; i++)
        for(int j=0; j<C.columns; j++)
            for(int k=0; k< columns; k++)
                C[i][j] += rhs[k][j] * data[i][k];
    return C;
}

template <typename Numeric>
Matrix<Numeric> Matrix<Numeric>::operator~()
{
    Matrix<Numeric> C(0,columns, rows);
    
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            C[j][i] = data[i][j];
    return C;

}


#pragma mark Public Methods
// ---------------------------------------- Public Methods
template <typename Numeric>
int Matrix<Numeric>::numRows() const { return rows; }

template <typename Numeric>
int Matrix<Numeric>::numColumns() const { return columns; }
    
#pragma mark Utility Functions
// ---------------------------------------- Utility Functions

template<typename Numeric>
void Matrix<Numeric>::print()
{
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < columns; j++)
            cout << data[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}


} // End Namespace "Matrix"
} // End Namespace "fnMath"

#endif
