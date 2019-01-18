//
//  GaussSeidel.hpp
//  fnMath
//
//  Created by Steven Novak on 1/16/19.
//  Copyright © 2019 Steven Novak. All rights reserved.
//
//	Class performs Gauss-Seidel iterative solving of matricies
//
//

#ifndef GAUSS_SEIDEL_HPP
#define GAUSS_SEIDEL_HPP

#include "Matrix.hpp"
#include "Matrix.cpp"

namespace fnMath {
namespace LinAlg {

template <typename Numeric>
class GaussSeidel 
{
public:
    // -------------------- Constructors
    GaussSeidel(const Matrix<Numeric>& A);

    // -------------------- Public Methods
	vector<Numeric> Solve(vector<Numeric> y);
	
	bool IsDiagonallyDominant();
	static bool IsDiagonallyDominant(std::shared_ptr<Matrix<Numeric>> A);

	// -------------------- Accessors
	bool Solved() { return _solved; }
	
	int Iterations() { return _iterations; }
	void SetMaxIterations (int MaxIterations) { _MAXITERATIONS = MaxIterations;}
	int MaxIterations () { return _MAXITERATIONS;}
	
	void SetMaxError( Numeric Error) { _MAXERROR = Error; }
	Numeric MaxError() { return _MAXERROR; }
	Numeric Error() { return _error; }

private:
	// -------------------- Private Members
	bool _solved;
	std::shared_ptr<Matrix<Numeric>> _data;
	int _MAXITERATIONS, _iterations;
	Numeric _MAXERROR, _error;
	
    // -------------------- Private Methods
    
}; // End GaussSeidel Class

} // End LinAlg Namespace
} // End fnMath Namespace
#endif /* GAUSS_SEIDEL_HPP */