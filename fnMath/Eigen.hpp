//
//  Eigen.hpp
//  fnMath
//
//  Created by Steven Novak on 2/5/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#ifndef Eigen_hpp
#define Eigen_hpp

#include "Error.hpp"
#include "Matrix.hpp"
#include "Matrix.cpp"

namespace fnMath{
namespace LinAlg{

template <typename Numeric>
class Eigen : public Matrix<Numeric>
{
public:
    // -------------------- Constructors
    Eigen();
    
    // -------------------- Public Methods
    Numeric PowerMethod(Matrix<Numeric> A);
    
    // -------------------- Accessors
    void setStepSize(double newStepSize);
    void setErrorLimit(double newErrorLimit);
    void setMaxIterations(int newMaxIterations);
    
    double getStepSize() const;
    double getErrorLimit() const;
    int getMaxIterations() const;
    
private:
    double err;
    int MAXITER;
    
    
}; // End Eigen Class

} // End LinAlg namespace
} // End fnMath namespace

#endif /* Eigen_hpp */
