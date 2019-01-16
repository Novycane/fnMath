//
//  GaussSeidel.hpp
//  fnMath
//
//  Created by Steven Novak on 1/16/19.
//  Copyright © 2019 Steven Novak. All rights reserved.
//
//	Class performs Gauss-Seidel iterative loving of matricies
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


private:
    // -------------------- Private Methods
    
    
}; // End GaussSeidel Class

} // End LinAlg Namespace
} // End fnMath Namespace
#endif /* GAUSS_SEIDEL_HPP */