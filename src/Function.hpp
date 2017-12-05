//
//  Function.hpp
//  fnMath
//
//  Created by Steven Novak on 2/2/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#ifndef Function_hpp
#define Function_hpp

#include "Matrix.hpp"
#include "Matrix.cpp"

namespace fnMath{
    using namespace LinAlg;
    
class Function
{
public:
    double virtual Evaluate(double x) = 0;
    double virtual Evaluate(double x, MatrixD params) = 0;
    
}; // End function Interface


} // End fnMath Namespace

#endif /* Function_hpp */
