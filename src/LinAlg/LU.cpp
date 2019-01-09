//
//  LU.cpp
//  fnMath
//
//  Created by Steven Novak on 2/1/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//
//  Class representing a matrix decomposed into Lower (L)
//  and upper (U) usint CROUT factorization
//
//

#ifndef LU_CPP
#define LU_CPP

#include "LU.hpp"

namespace fnMath{
namespace LinAlg{
    
#pragma mark Constructors
// ---------------------------------------- Constructors

template <typename Numeric>
LU<Numeric>::LU(const Matrix<Numeric>& A): Matrix<Numeric>(1, A.numRows(), A.numColumns())
{
    Decompose(A);
}

template <typename Numeric>
LU<Numeric>::~LU() {}

    
#pragma mark Public Methods
// ---------------------------------------- Public Methods
template <typename Numeric>
Matrix<Numeric> LU<Numeric>::Upper()
{
    Matrix<Numeric> C (0, this->rows, this->columns);

    for(int j=0; j<this->columns; j++)
        for(int i=0; i<=j; i++)
            C[i][j] = this->data[i][j];
    
    return C;
}

template <typename Numeric>
Matrix<Numeric> LU<Numeric>::Lower()
{
    Matrix<Numeric> C (0, this->rows, this->columns);
    
    for(int j=0; j<this->columns; j++)
        for(int i=j; i<this->rows; i++)
			if(i==j)
                C[i][j] = 1;
            else
				C[i][j] = this->data[i][j];
    
    return C;
}

template <typename Numeric>
Matrix<Numeric> LU<Numeric>::Solve(const Matrix<Numeric> & b)
{
    if(b.numRows() != this-> rows || b.numColumns() != 1)
        throw new DimensionMismatchException();
    
    Matrix<Numeric> y(1,b.numRows(),1);
    
    for(int i=0; i< this->rows; i++)
    {
        y[i][0] = b[i][0];
        
        for(int j=0; j<i; j++)
        {
            y[i][0] -= y[j][0] * this->data[i][j];
        }
    }
    
    for(int i=this->rows - 1; i>=0; i--)
    {
        for(int j=this->columns - 1; j>i; j--)
        {
            y[i][0] -= y[j][0] * this->data[i][j];
        }
		y[i][0] = y[i][0] / this->data[i][i];
    }    
    return y;
}
    
template <typename Numeric>
Numeric LU<Numeric>::Determinate()
{
    Numeric det = this->data[0][0];
    for(int i=1; i<this->rows; i++)
        det *= this->data[i][i];
    return det;
}
    
#pragma mark Private Methods
// ---------------------------------------- Private Methods

template <typename Numeric>
void LU<Numeric>::Decompose(const Matrix<Numeric> &A)
{
    if(this->rows != this->columns)
        throw new DimensionMismatchException();
    
    for(int i=0; i<this->rows; i++)
        this->data.resize(this->columns);
      
	Numeric tempSum;  
	  
    for(int diag=0; diag<this->rows; diag++)
	{
		for(int col=diag; col < this->columns; col++)
		{
			tempSum = 0;
			for(int k=0; k < diag; k ++)
				tempSum = tempSum + this->data[diag][k] * this->data[k][col];
			this->data[diag][col] = A[diag][col] - tempSum;
		}
		for(int row=diag+1; row < this->rows; row++)
		{
			tempSum = 0;
			for(int k=0; k < diag; k++)
				tempSum = tempSum + this->data[row][k] * this->data[k][diag];
			this->data[row][diag] = (A[row][diag] - tempSum) / this->data[diag][diag];
		}
	}
}

template <typename Numeric>
Matrix<Numeric> LU<Numeric>::BackwardSub(const Matrix<Numeric> & b)
{
    if(b.numRows() != this-> rows || b.numColumns() != 1)
        throw new DimensionMismatchException();
    
    Matrix<Numeric> y(1,b.numRows(),1);
    
    for(int i=this->rows - 1; i>=0; i--)
    {
        y[i][0] = b[i][0];
        
        for(int j=this->columns - 1; j>i; j--)
        {
            y[i][0] -= y[j][0] * this->data[i][j];
        }
    }
    
    return y;
}

    
template <typename Numeric>
Matrix<Numeric> LU<Numeric>::ForwardSub(const Matrix<Numeric> & b)
{
    if(b.numRows() != this-> rows || b.numColumns() != 1)
        throw new DimensionMismatchException();

    Matrix<Numeric> y(1,b.numRows(),1);

    for(int i=0; i< this->rows; i++)
    {
        y[i][0] = b[i][0];
        
        for(int j=0; j<i; j++)
        {
            y[i][0] -= y[j][0] * this->data[i][j];
        }
        y[i][0] = y[i][0] / this->data[i][i];
    }
    
    return y;
}
    
} // End Namespace LU
} // End Namespace fnMath
#endif
