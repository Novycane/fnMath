//
//  Cholesky.cpp
//  fnMath
//
//  Created by Steven Novak on 1/8/19.
//  Copyright © 2019 Steven Novak. All rights reserved.
//
//  Class representing a matrix decomposed into Lower (L)
//  and upper (U) usint CROUT factorization
//
//

#ifndef CHOLESKY_CPP
#define CHOLESKY_CPP

#include "Cholesky.hpp"

namespace fnMath{
namespace LinAlg{
    
#pragma mark Constructors
// ---------------------------------------- Constructors

template <typename Numeric>
Cholesky<Numeric>::Cholesky(const Matrix<Numeric>& A): Matrix<Numeric>(1, A.numRows(), A.numColumns())
{
    Decompose(A);
}

template <typename Numeric>
Cholesky<Numeric>::~Cholesky() {}

    
#pragma mark Public Methods
// ---------------------------------------- Public Methods


template <typename Numeric>
Matrix<Numeric> Cholesky<Numeric>::Lower()
{
    Matrix<Numeric> C (0, this->rows, this->columns);
    
    for(int j=0; j<this->columns; j++)
        for(int i=j; i<this->rows; i++)
			C[i][j] = this->data[i][j];
    
    return C;
}

template <typename Numeric>
Matrix<Numeric> Cholesky<Numeric>::Upper()
{
    Matrix<Numeric> C (0, this->rows, this->columns);

    for(int j=0; j<this->columns; j++)
        for(int i=0; i<=j; i++)
            C[i][j] = this->data[i][j];
    
    return C;
}

template <typename Numeric>
Matrix<Numeric> Cholesky<Numeric>::Solve(const Matrix<Numeric> & b)
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
       
#pragma mark Private Methods
// ---------------------------------------- Private Methods

template <typename Numeric>
void Cholesky<Numeric>::Decompose(const Matrix<Numeric> &A)
{
    if(this->rows != this->columns)
        throw new DimensionMismatchException();
    
    for(int i=0; i<this->rows; i++)
        this->data.resize(this->columns);
	
	Numeric tempSum;

	for(int diag=0; diag < this->columns; diag++)
	{
		tempSum = 0;
		for(int j=0; j<diag; j++)
			tempSum = tempSum + this->data[diag][j] * this->data[diag][j];
		this->data[diag][diag] = sqrt(A[diag][diag] - tempSum);
		
		tempSum = 0;
		for(int i=diag + 1; i < this->rows; i++)
		{
			for(int k=0; k < diag; k++)
				tempSum = tempSum + this->data[i][k] * this->data[diag][k];
			this->data[i][diag] = (A[i][diag] - tempSum) / this->data[diag][diag];
			this->data[diag][i] = this->data[i][diag];
		}
	}
}

   
} // End Namespace LinAlg
} // End Namespace fnMath
#endif
