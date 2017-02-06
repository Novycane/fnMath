//
//  Eigen.cpp
//  fnMath
//
//  Created by Steven Novak on 2/5/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#include "Eigen.hpp"

#ifndef EIGEN_CPP
#define EIGEN_CPP

namespace fnMath{
namespace LinAlg{

#pragma mark Constructors
// ---------------------------------------- Constructors
template <typename Numeric>
Eigen<Numeric>::Eigen() { err = 1e-10; MAXITER = 50; };

    
#pragma mark Public Methods
// ---------------------------------------- Public Methods
template <typename Numeric>
Numeric Eigen<Numeric>::PowerMethod(Matrix<Numeric> A)
{
    Numeric result = 0;
    Numeric previousResult;
    Numeric error;
    
    if(A.numRows() != A.numColumns())
        throw new DimensionMismatchException();
    
    Matrix<Numeric> EigenVector(1,A.numRows(), 1);
    
    for(int i=0; i<A.numRows(); i++)
        EigenVector[i][1] = A[i][i];
    
    for(int iteration=1; iteration < MAXITER; iteration++)
    {
        previousResult = result;
        
        EigenVector = A * EigenVector;
        
        result = EigenVector.Max();
        
        error = result - previousResult;
        if(error < 0)
            error *= -1;
                
        if(error <= err)
            return result;
        
        EigenVector = EigenVector / result;
        
    }
    
    return result;
}
    
#pragma mark Accessors
// ---------------------------------------- Accessors

template <typename Numeric>
void Eigen<Numeric>::setErrorLimit(double newErrorLimit) { err = newErrorLimit; };

template <typename Numeric>
void Eigen<Numeric>::setMaxIterations(int newMaxIterations) {MAXITER = newMaxIterations; };


template <typename Numeric>
double Eigen<Numeric>::getErrorLimit() const { return err; };

template <typename Numeric>
int Eigen<Numeric>::getMaxIterations() const { return MAXITER; };

    
} // End LinAlg Namespace
} // End fnMath Namespace
#endif
