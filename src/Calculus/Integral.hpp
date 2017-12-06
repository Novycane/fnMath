//
//  Integral.hpp
//  fnMath
//
//  Created by Steven Novak on 2/2/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#ifndef Integral_hpp
#define Integral_hpp

#include "../Function.hpp"

namespace fnMath{
namespace Calculus{
    
    
class Trapezoidal
{
public:
    // -------------------- Public Methods
    double Integrate(Function* F, double start, double end, int steps);
    
}; // end trapezoidal

class Rhomberg
{
public:
    // -------------------- Public Methods
    double Integrate(Function* F, double start, double end);
    
    // -------------------- Accessors
    void setError(double error);
    void setMaxIterations(int maxIterations);
    int getMaxIterations() const;
    double getError() const;
    
protected:
    // -------------------- Private Memebers
    int MAXITER = 10;
    double err = 1e-10;
    
}; // end trapezoidal

    
        
} // End Integral namespace
} // End fnMath namespace
        
#endif /* Integral_hpp */
