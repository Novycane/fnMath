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

/*
template <typename Numeric>
Matrix<Numeric>::~Matrix() {}
*/
    
template <typename Numeric>
Matrix<Numeric>::Matrix(const Matrix<Numeric> & rhs)
{
    #ifdef __DEBUG__
        cout << "Copy Constructor\n";
    #endif
    
    rows = rhs.rows;
    columns = rhs.columns;
    
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
    columns = rhs.columns;
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

template <typename Numeric>
Matrix<Numeric> Matrix<Numeric>::operator+(const Numeric & rhs)
{
    Matrix<Numeric> C(0,rows, columns);
    
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            C[i][j] = data[i][j] + rhs;
    return C;
}
    
template <typename Numeric>
Matrix<Numeric> Matrix<Numeric>::operator-(const Numeric & rhs)
{
    Matrix<Numeric> C(0,rows, columns);
    
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            C[i][j] = data[i][j] - rhs;
    return C;
}
    
template <typename Numeric>
Matrix<Numeric> Matrix<Numeric>::operator*(const Numeric & rhs)
{
    Matrix<Numeric> C(0,rows, columns);
    
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            C[i][j] = data[i][j] * rhs;
    return C;
}

template <typename Numeric>
Matrix<Numeric> Matrix<Numeric>::operator/(const Numeric & rhs)
{
    Matrix<Numeric> C(0,rows, columns);
    
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            C[i][j] = data[i][j] / rhs;
    return C;
}
    
#pragma mark Public Methods
// ---------------------------------------- Public Methods
template <typename Numeric>
int Matrix<Numeric>::numRows() const { return rows; }

template <typename Numeric>
int Matrix<Numeric>::numColumns() const { return columns; }
    
template <typename Numeric>
Numeric Matrix<Numeric>::Max()
{
    Numeric maxValue = data[0][0];
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            if(data[i][j] > maxValue)
                maxValue = data[i][j];
    return maxValue;
}

template <typename Numeric>
Numeric Matrix<Numeric>::Min()
{
    Numeric minValue = data[0][0];
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            if(data[i][j] < minValue)
                minValue = data[i][j];
    return minValue;
}
    
template <typename Numeric>
Numeric Matrix<Numeric>::absMax()
{
    Numeric maxValue = data[0][0];
    Numeric absVal;
    
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
        {
            absVal = data[i][j] > 0 ? data[i][j] : data[i][j] * -1;
            if( absVal > maxValue)
                maxValue = absVal;
        }
    return maxValue;
}
    
template <typename Numeric>
Numeric Matrix<Numeric>::absMin()
{
    Numeric minValue = data[0][0];
    Numeric absVal;
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
        {
            absVal = data[i][j] > 0 ? data[i][j] : data[i][j] * -1;
            if( absVal < minValue)
                minValue = absVal;
        }
    return minValue;
}

template <typename Numeric>
Numeric Matrix<Numeric>::MaxMag()
{
    Numeric maxValue = data[0][0];
    Numeric absMax = data[0][0] > 0 ? data[0][0] : data[0][0] * -1;
    Numeric absVal;
    
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
        {
            absVal = data[i][j] > 0 ? data[i][j] : data[i][j] * -1;
            if( absVal > absMax)
            {
                maxValue = data[i][j];
                absMax = data[0][0] > 0 ? data[0][0] : data[0][0] * -1;
            }
        }
    return maxValue;
}
    
template <typename Numeric>
Numeric Matrix<Numeric>::MinMag()
{
    Numeric maxValue = data[0][0];
    Numeric absMin = data[0][0] > 0 ? data[0][0] : data[0][0] * -1;
    Numeric absVal;
    
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
        {
            absVal = data[i][j] > 0 ? data[i][j] : data[i][j] * -1;
            if( absVal < absMin)
            {
                maxValue = data[i][j];
                absMin = data[0][0] > 0 ? data[0][0] : data[0][0] * -1;
            }
        }
    return maxValue;
}
    
template <typename Numeric>
void Matrix<Numeric>::I()
{
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
        {
            if(i==j)
                data[i][j] = 1;
            else
                data[i][j] = 0;
        }
}

    
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
