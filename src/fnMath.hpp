/*
 *  fnMath.hpp
 *  fnMath
 *
 *  Created by Steven Novak on 2/1/17.
 *  Copyright © 2017 Steven Novak. All rights reserved.
 *
 */

#ifndef fnMath_
#define fnMath_

// ------------------------- Linear Algebra Headers
#include "./LinAlg/Matrix.hpp"
#include "./LinAlg/Matrix.cpp"
#include "./LinAlg/Tridiagonal.hpp"
#include "./LinAlg/Tridiagonal.cpp"
#include "./LinAlg/BandedMatrix.hpp"
#include "./LinAlg/BandedMatrix.cpp"
#include "./LinAlg/GaussSeidel.hpp"
#include "./LinAlg/GaussSeidel.cpp"
#include "./LinAlg/Jacobi.hpp"
#include "./LinAlg/Jacobi.cpp"
#include "./LinAlg/LU.hpp"
#include "./LinAlg/LU.cpp"
#include "./LinAlg/Eigen.hpp"
#include "./LinAlg/Eigen.cpp"
#include "./LinAlg/QR.hpp"
#include "./LinAlg/QR.cpp"
#include "./LinAlg/Cholesky.hpp"
#include "./LinAlg/Cholesky.cpp"

// ------------------------- Data Structure Headers
//#include "./DataStructs/BinaryTree.hpp"
//#include "./DataStructs/BinaryTree.cpp"

// ------------------------- Crypto Headers
//#include "./Crypto/Rijndael.hpp"

// ------------------------- Calculus Headers
#include "./Calculus/Integral.hpp"
#include "./Calculus/Derivative.hpp"
#include "./Calculus/Derivative.cpp"

// ------------------------- Function / Routines
#include "Function.hpp"
#include "./Stats/Random.hpp"
#include "./Stats/Factorial.hpp"



/* The classes below are exported */
#pragma GCC visibility push(default)

#pragma GCC visibility pop
#endif
