//
//  Gamma.cpp
//  fnMath
//
//  Created by Steven Novak on 2/15/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#include "Gamma.hpp"
#include "Constants.h"
#include <cmath>

namespace fnMath {


    
#pragma mark Constructors
// ---------------------------------------- Constructors
double Gamma::Evaluate(double x)
{
    return StirlingGamma(x);
}
    
    
double Gamma::Evaluate(double x, MatrixD params)
{
    return 0;
}
    

#pragma mark Private Methods
// ---------------------------------------- Private Methods
    
double Gamma::StirlingGamma(double z)
{
    double gam;
    
    gam = sqrt(PI_2 / z) * pow( 0.367879441171442321595523770161460867445811131031767834507 * (z + 1 / (12 * z - 1 / (10 * z))), z);
    
    return gam;
}
    
} // End fnMath namespace
