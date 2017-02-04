//
//  Derivative.cpp
//  fnMath
//
//  Created by Steven Novak on 2/3/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#include "Derivative.hpp"

namespace fnMath{
namespace Calculus{
    
// ---------------------------------------- Constructor
Derivative::Derivative(Function * & Fun)
{
    F = Fun;
}
    
// ---------------------------------------- Methods
    double Derivative::D_Forward(double x)
    {
        double yPlus = F->Evaluate(x + stepSize);
        double y = F->Evaluate(x);
        return (yPlus - y) / stepSize ;

    }
    
    double Derivative::D_For_One_Side(double x)
    {
        double y = F->Evaluate(x);
        double yPlus = F->Evaluate(x + stepSize);
        double yPlus2 = F->Evaluate(x + 2 * stepSize);
        return (4 * yPlus - yPlus2 - 3 * y) / (2 * stepSize);
    }
    
    double Derivative::D_Backward(double x)
    {
        double yMin = F->Evaluate(x - stepSize);
        double y = F->Evaluate(x);
        return (y - yMin) / stepSize;
    }
    
    double Derivative::D_Centered(double x)
    {
        double yPlus = F->Evaluate(x + stepSize);
        double yMinus = F->Evaluate(x - stepSize);
        return (yPlus - yMinus) / (2 * stepSize);
    }
    
    double Derivative::D_Back_One_Side(double x)
    {
        double y = F->Evaluate(x);
        double yMinus = F->Evaluate(x - stepSize);
        double yMinus2 = F->Evaluate(x - 2 * stepSize);
        return ((3 * y - 4 * yMinus + yMinus2) / (2 * stepSize));
    }
    
    double Derivative::D2_Centered(double x)
    {
        double y = F->Evaluate(x);
        double yMinus = F->Evaluate(x - stepSize);
        double yPlus = F->Evaluate(x + stepSize);
        return (yPlus - 2 * y + yMinus) / (stepSize * stepSize);
    }
    
    double Derivative::D(double x)
    {
        return 0;
    }
    
    double Derivative::D2(double x)
    {
        return 0;
    }
    
    
    
// ---------------------------------------- Accessors
void Derivative::setStepSize(double newStepSize) { stepSize = newStepSize; };
void Derivative::setErrorLimit(double newErrorLimit) { err = newErrorLimit; };
void Derivative::setMaxIterations(int newMaxIterations) { MAXITER = newMaxIterations; };

double Derivative::getStepSize() const { return stepSize; };
double Derivative::getErrorLimit() const { return err; };
int Derivative::getMaxIterations() const { return MAXITER; };

    
    
    
} // End Namespace Calculus
} // End Namespace fnMath
