//
//  Integral.cpp
//  fnMath
//
//  Created by Steven Novak on 2/2/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#include "Integral.hpp"

namespace fnMath {
namespace Calculus{

#pragma mark Trapezoidal Integration
// ----------------------------------------
// ---------------------------------------- Trapezoidal
// ----------------------------------------
double Trapezoidal::Integrate(Function* F, double start, double end, int steps)
{
    double x = start;
    double h = (end - start) / steps;
    double sum = (F->Evaluate(end) + F->Evaluate(start)) / 2;
    
    
    for(int i=0; i<steps; i++)
    {
        x += h;
        sum += F->Evaluate(x);
    }
    
    return sum * h;
}
    
#pragma mark Rhomberg Integration
// ----------------------------------------
// ---------------------------------------- Rhomberg
// ----------------------------------------
double Rhomberg::Integrate(Function* F, double start, double end)
{
    double x = start;
    double h = (end - start);
    double sum = (F->Evaluate(end) + F->Evaluate(start)) / 2;
    const int arraySize = (1 << (MAXITER)) + 1;
    double evaluations[arraySize];
    double* thisEvaluation = (double*)malloc((MAXITER + 1) * sizeof(double));
    double* lastEvaluation = (double*)malloc((MAXITER + 1) * sizeof(double));
    double error;
    int maxIndex = 1;
    int steps = 1;
    int factor;
    
    evaluations[0] = end;
    evaluations[1] = start;
    
    lastEvaluation[0] = sum * h;
    
    for(int iterations=1; iterations <= MAXITER; iterations++)
    {
        //cout << "Iteration #" << iterations << " Sum= " << lastEvaluation [iterations-1] << endl;
        
        h/=2;
        for(int i=1; i<=maxIndex; i++)
        {
            evaluations[i + steps] = evaluations[i] + h;
            sum += F->Evaluate(evaluations[i + steps]);
        }
        maxIndex+= steps;
        steps *= 2;
        
        thisEvaluation[0] = sum * h;
        
        factor = 2;
        for(int k=1; k<=iterations; k++)
        {
            thisEvaluation[k] =  ( factor * thisEvaluation[k-1] - lastEvaluation[k - 1]) / (factor - 1) ;
            factor = factor << 1;
        }
        
        error = thisEvaluation[iterations] / lastEvaluation[iterations-1] - 1;
        if(error < 0)
            error *= -1;
        
        if(error <= err)
        {
            x = thisEvaluation[iterations];
            delete thisEvaluation;
            delete lastEvaluation;
            return x;
        }
        
        std::swap(lastEvaluation, thisEvaluation);
        
    }
    x = lastEvaluation[MAXITER];
    delete thisEvaluation;
    delete lastEvaluation;
    
    return x;
}
    
void Rhomberg::setError(double error) { err = error; }
void Rhomberg::setMaxIterations(int maxIterations) { MAXITER = maxIterations; }
double Rhomberg::getError() const { return err; }
int Rhomberg::getMaxIterations() const { return MAXITER; }
    
} // End Integral namespace
} // End fnMath namespace
