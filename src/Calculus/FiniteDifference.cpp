//
//  FiniteDifference.cpp
//  fnMath
//
//  Created by Steven Novak on 2/17/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#include "FiniteDifference.hpp"

namespace fnMath {
namespace Calculus{
        
    
    
#pragma mark Constructors
// ---------------------------------------- Constructors

FiniteDifference::FiniteDifference()
{
    err = 1e-10;
    MAXITER = 20;
}
    
FiniteDifference::FiniteDifference(std::shared_ptr<Function> F)
{
    err = 1e-10;
    MAXITER = 20;
    EvalFunction = &F;
}
    
#pragma mark Accessors
// ---------------------------------------- Accessors

void FiniteDifference::SetFunction(std::shared_ptr<Function> NewFunction) {EvalFunction = NewFunction;}
void FiniteDifference::SetError(double Error) { err = Error;}
void FiniteDifference::SetMaxIterations(int NewMaxIterations) {MAXITER = NewMaxIterations;}
double FiniteDifference::GetError() const {return err;}
int FiniteDifference::GetMaxIterations() const {return MAXITER;}
    

#pragma mark Public Methods
// ---------------------------------------- Public Methods

void FiniteDifference::Euler(double F0, double StepSize, VectorD & Evaluations)
{
    if(Evaluations.size() < 1)
        return;
    
    Evaluations[0] = F0;
    
    for(int i=1; i<Evaluations.size(); i++)
        Evaluations[i] = Evaluations[i-1] + StepSize * EvalFunction->Evaluate(Evaluations[i-1]);
}

void FiniteDifference::RungeKutta4(double & F0, double StepSize)
{
    double k1, k2, k3, k4;
    k1 = StepSize * EvalFunction->Evaluate(F0);
    k2 = StepSize * EvalFunction->Evaluate(F0 + k1/2);
    k3 = StepSize * EvalFunction->Evaluate(F0 + k2/2);
    k4 = StepSize * EvalFunction->Evaluate(F0 + k3);
    
    F0 = F0 + (k1 + 2 * (k2 + k3) + k4) / 6;
}
    
void FiniteDifference::RungeKutta4(double F0, double StepSize, VectorD & Evaluations)
{
    if(Evaluations.size() < 1)
        return;
    
    Evaluations[0] = F0;
    
    for(int i=1; i<Evaluations.size(); i++)
    {
        Evaluations[i] = Evaluations[i-1];
        RungeKutta4(Evaluations[i], StepSize);
    }
}
    
void FiniteDifference::RungeKutta4Coupled(double & Dependant, double Independant, double StepSize)
{
    double k1, k2, k3, k4;
    k1 = StepSize * EvalFunction->Evaluate(Independant);
    k2 = StepSize * EvalFunction->Evaluate(Independant + k1/2);
    k3 = StepSize * EvalFunction->Evaluate(Independant + k2/2);
    k4 = StepSize * EvalFunction->Evaluate(Independant + k3);
    
    Dependant = Dependant + (k1 + 2 * (k2 + k3) + k4) / 6;
}

    
VectorD FiniteDifference::CreateOutputVector(double a, double b, int steps)
{
    VectorD out(steps + 1);
    double h = (b-a) / steps;
    out[0] = a;
    
    for(int i=1; i<=steps; i++)
        out[i] = out[i-1] + h;
        
    return out;
}
        
} // End Calculus namespace
} // End fnMath namespace
