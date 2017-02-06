//
//  Derivative.hpp
//  fnMath
//
//  Created by Steven Novak on 2/3/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#ifndef Derivative_hpp
#define Derivative_hpp

#include "Function.hpp"

namespace fnMath{
namespace Calculus{

class Derivative
{
public:
    // -------------------- Constructors
    Derivative(Function * & Fun);
    
    // -------------------- Public Methods
    double D_Forward(double x);
    double D_For_One_Side(double x);
    double D_Backward(double x);
    double D_Back_One_Side(double x);
    double D_Centered(double x);
    double D2_Centered(double x);
    double D(double x);
    double D2(double x);
    
    // -------------------- Accessors
    void setStepSize(double newStepSize);
    void setErrorLimit(double newErrorLimit);
    void setMaxIterations(int newMaxIterations);
    
    double getStepSize() const;
    double getErrorLimit() const;
    int getMaxIterations() const;
    
private:
    // -------------------- Private Members
    Function * F;
    int MAXITER;
    double stepSize;
    double err;
    
};
    
} // End Namespace Calculus
} // End Namespace fnMath

#endif /* Derivative_hpp */
