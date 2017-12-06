//
//  FiniteDifference.hpp
//  fnMath
//
//  Created by Steven Novak on 2/17/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#ifndef FiniteDifference_hpp
#define FiniteDifference_hpp

#include "Function.hpp"
#include <vector>
#include "Matrix.hpp"

namespace fnMath {
namespace Calculus{
    
class FiniteDifference
{
public:
    // -------------------- Constructors
    FiniteDifference();
    FiniteDifference(Function & F);
    
    // -------------------- Accessors
    void SetFunction(Function * & NewFunction);
    void SetError(double Error);
    void SetMaxIterations(int NewMaxIterations);
    double GetError() const;
    int GetMaxIterations() const;
    
    // -------------------- Public Methos
    void Euler(double F0, double StepSize, VectorD & Evaluations);
    
    void RungeKutta4(double & F0, double StepSize);
    void RungeKutta4(double F0, double StepSize, VectorD & Evaluations);
    
    void RungeKutta4Coupled(double & Dependant, double Independant, double StepSize);
    
    VectorD CreateOutputVector(double a, double b, int steps);
    
private:
    // -------------------- Private Members
    double err;
    int MAXITER;
    Function* EvalFunction;
    
    
    // -------------------- Private Methods
    
    
};
    
    
} // End Calculus namespace
} // End fnMath namespace



#endif /* FiniteDifference_hpp */
