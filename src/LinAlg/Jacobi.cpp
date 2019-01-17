//
//  Jacobi.cpp
//  fnMath
//
//  Created by Steven Novak on 1/17/19.
//  Copyright © 2019 Steven Novak. All rights reserved.
//
//	Class performs Gauss-Seidel iterative loving of matricies
//
//

#ifndef JACOBI_CPP
#define JACOBI_CPP

#include "Jacobi.hpp"

namespace fnMath{
namespace LinAlg{
    
#pragma mark Constructors
// ---------------------------------------- Constructors
template <typename Numeric>
Jacobi<Numeric>::Jacobi(const Matrix<Numeric>& A)
{
	_MAXITERATIONS = 100;
	_MAXERROR = 1e-5;
	_solved = false;
	_data = make_shared<Matrix<Numeric>>(A);
}
    
#pragma mark Public Methods
// ---------------------------------------- Public Methods
template <typename Numeric>
vector<Numeric> Jacobi<Numeric>::Solve(vector<Numeric> y)
{
	int n = _data->numRows();
	if(y.size() != n)
		throw new DimensionMismatchException();
	
	vector<Numeric> x = y;
	vector<Numeric> newX = x;
	_error = std::numeric_limits<double>::max();
	
	for(int i=0; i<y.size(); i++)
		x[i] = 1.0;
	
	for(_iterations =0; _iterations < _MAXITERATIONS; _iterations++)
	{
		for(int i=0; i<n; i++)	// rows
		{
			newX[i] = 0;
			for(int j=0; j<n; j++) // Columns
			{
				if(i != j)
					newX[i] = newX[i] + (*_data)[i][j] * x[j];
			}
			newX[i] = (y[i] - newX[i]) / (*_data)[i][i];
		}
		
		_error = 0;
		for(int i=0; i<n; i++)
		{
			_error = _error + newX[i] - x[i];
			x[i] = newX[i];
		}
	
		if(abs(_error) < _MAXERROR)
			break;
	}
	
	return x;
}

template <typename Numeric>
bool Jacobi<Numeric>::IsDiagonallyDominant()
{
	return IsDiagonallyDominant(_data);
}

template <typename Numeric>
bool Jacobi<Numeric>::IsDiagonallyDominant(std::shared_ptr<Matrix<Numeric>> A)
{
	Numeric sum = 0;
	
	for(int i=0; i<A->numRows(); i++)
		for(int j=0; j < A->numColumns(); j++)
			if(i != j)
				sum = sum + (*A)[i][j];
	sum = abs(sum);		
	
	for(int i=0; i<A->numRows(); i++)
		for(int j=0; j < A->numColumns(); j++)
			if(i == j)
				if(abs((*A)[i][j]) < sum)
					return false;
	return true;
}

       
#pragma mark Private Methods
// ---------------------------------------- Private Methods
   
} // End Namespace LinAlg
} // End Namespace fnMath
#endif
