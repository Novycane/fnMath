//
//  GaussSeidel.cpp
//  fnMath
//
//  Created by Steven Novak on 1/16/19.
//  Copyright © 2019 Steven Novak. All rights reserved.
//
//	Class performs Gauss-Seidel iterative loving of matricies
//
//

#ifndef GAUSS_SEIDEL_CPP
#define GAUSS_SEIDEL_CPP

#include "GaussSeidel.hpp"

namespace fnMath{
namespace LinAlg{
    
#pragma mark Constructors
// ---------------------------------------- Constructors
template <typename Numeric>
GaussSeidel<Numeric>::GaussSeidel(const Matrix<Numeric>& A)
{
	_MAXITERATIONS = 100;
	_MAXERROR = 1e-5;
	_solved = false;
	_data = make_shared<Matrix<Numeric>>(A);
}
    
template <typename Numeric>
vector<Numeric> GaussSeidel<Numeric>::Solve(vector<Numeric> y)
{
	int n = _data->numRows();
	Numeric sum;
	if(y.size() != n)
		throw new DimensionMismatchException();
	
	vector<Numeric> x = y;
	_error = std::numeric_limits<double>::max();
	
	for(int i=0; i<y.size(); i++)
		x[i] = 1.0;
	
	for(_iterations =0; _iterations < _MAXITERATIONS; _iterations++)
	{
		_error = 0;
		for(int i=0; i<n; i++)	// rows
		{
			sum = 0;
			for(int j=0; j<n; j++) // Columns
			{
				if(i != j)
					sum = sum + (*_data)[i][j] * x[j];
			}
			sum = (y[i] - sum) / (*_data)[i][i];
			_error = _error + abs(sum - x[i]);
			x[i] = sum;
		}
			
		if(abs(_error) < _MAXERROR)
			break;
	}
	
	return x;
}

template <typename Numeric>
bool GaussSeidel<Numeric>::IsDiagonallyDominant()
{
	return IsDiagonallyDominant(_data);
}

template <typename Numeric>
bool GaussSeidel<Numeric>::IsDiagonallyDominant(std::shared_ptr<Matrix<Numeric>> A)
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
