//
//  Gamma.hpp
//  fnMath
//
//  Created by Steven Novak on 2/15/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#ifndef Gamma_hpp
#define Gamma_hpp

#include "../Function.hpp"

namespace fnMath {
    
class Gamma: public Function
{
public:
    // -------------------- Constructors
    double Evaluate(double x);
    double Evaluate(double x, MatrixD params);
    
    // -------------------- Public Methods
    
private:
    // -------------------- Private Members
    
    
    // -------------------- Private Methods
    double StirlingGamma(double z);
    
    
    
};
    
} // End fnMath ammespace

#endif /* Gamma_hpp */
