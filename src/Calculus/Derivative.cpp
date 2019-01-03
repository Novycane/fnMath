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

#pragma mark Constructors
// ---------------------------------------- Constructors
Derivative::Derivative(Function * Fun)
{
    F = Fun;
    stepSize = 1;
    err = 1e-5;
    MAXITER = 50;
}

#pragma mark Public Methods
// ---------------------------------------- Public Methods
double Derivative::D_Forward(double x)
{
    double yPlus = F->Evaluate(x + stepSize);
    double y = F->Evaluate(x);
    return (yPlus - y) / stepSize;
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

double Derivative::D1(double x)
{
    double yPlus;
    double yMinus;
    double h = x/2;
    double* thisEvaluation = (double*)malloc((MAXITER + 1) * sizeof(double));
    double* lastEvaluation = (double*)malloc((MAXITER + 1) * sizeof(double));
    double error;

    yPlus = F->Evaluate(x + h);
    yMinus = F->Evaluate(x - h);
    lastEvaluation[0] = (yPlus - yMinus) / (2 * stepSize);
    
    for(int iterations=1; iterations <= MAXITER; iterations++)
    {
        //cout << "Iteration #" << iterations << " Sum= " << lastEvaluation [iterations-1] << endl;
        h /= 2;
        yPlus = F->Evaluate(x + h);
        yMinus = F->Evaluate(x - h);
        thisEvaluation[iterations]  = (yPlus - yMinus) / (2 * h);
        
        error = thisEvaluation[iterations] / lastEvaluation[iterations-1] - 1 ;
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
    
    delete thisEvaluation;
    delete lastEvaluation;
    return thisEvaluation[MAXITER];
}

double Derivative::D2(double x)
{
    double y;
    double yPlus;
    double yMinus;
    double h = x/2;
    double* thisEvaluation = (double*)malloc((MAXITER + 1) * sizeof(double));
    double* lastEvaluation = (double*)malloc((MAXITER + 1) * sizeof(double));
    double error, lastError=0;
    
    y = F->Evaluate(x);
    yPlus = F->Evaluate(x + h);
    yMinus = F->Evaluate(x - h);
    lastEvaluation[0] = (yPlus - 2 * y + yMinus) / (h * h);
    
    for(int iterations=1; iterations <= MAXITER; iterations++)
    {
        h /= 2;
        yPlus = F->Evaluate(x + h);
        yMinus = F->Evaluate(x - h);
        thisEvaluation[iterations]  = (yPlus - 2 * y + yMinus) / (h * h);
        
        error = thisEvaluation[iterations] / lastEvaluation[iterations-1] - 1 ;
        if(error < 0)
            error *= -1;
                
        if(error <= err)
        {
            x = thisEvaluation[iterations];
            delete thisEvaluation;
            delete lastEvaluation;
            return x;
        }
        
        lastError = error;
        std::swap(lastEvaluation, thisEvaluation);
    }
    
    delete thisEvaluation;
    delete lastEvaluation;
    return thisEvaluation[MAXITER];
}

// ----------------------------------------
// ----------------------------------------    
	
double Derivative::D_Forward_Partial(LinAlg::MatrixD params, int index)
{
	MatrixD paramPrime = params;
	paramPrime[index][0] = paramPrime[index][0] + stepSize;
	double yPlus = F->Evaluate(paramPrime);
    double y = F->Evaluate(params);
    return (yPlus - y) / stepSize ;
}

double Derivative::D_For_One_Side_Partial(LinAlg::MatrixD params, int index)
{
	double y = F->Evaluate(params);
	params[index][0] = params[index][0] + stepSize;
    double yPlus = F->Evaluate(params);
	params[index][0] = params[index][0] + stepSize;
    double yPlus2 = F->Evaluate(params);
	
    return (4 * yPlus - yPlus2 - 3 * y) / (2 * stepSize);
}

double Derivative::D_Backward_Partial(LinAlg::MatrixD params, int index)
{
	double y = F->Evaluate(params);
	params[index][0] = params[index][0] - stepSize;
    double yMin = F->Evaluate(params);
    
    return (y - yMin) / stepSize;
}

double Derivative::D_Back_One_Side_Partial(LinAlg::MatrixD params, int index)
{
    double y = F->Evaluate(params);
	params[index][0] = params[index][0] - stepSize;
    double yMinus = F->Evaluate(params);
	params[index][0] = params[index][0] - stepSize;
    double yMinus2 = F->Evaluate(params);
    return ((3 * y - 4 * yMinus + yMinus2) / (2 * stepSize));
} 
	
double Derivative::D_Centered_Partial(LinAlg::MatrixD params, int index)
{
	params[index][0] = params[index][0] + stepSize;
    double yPlus = F->Evaluate(params);
	params[index][0] = params[index][0] - 2 * stepSize;
    double yMinus = F->Evaluate(params);
    return (yPlus - yMinus) / (2 * stepSize);
}


double Derivative::D2_Centered_Partial(LinAlg::MatrixD params, int index)
{
    double y = F->Evaluate(params);
	
	params[index][0] = params[index][0] - stepSize;
    double yMinus = F->Evaluate(params);
	
	params[index][0] = params[index][0] + 2 * stepSize;
    double yPlus = F->Evaluate(params);
    return (yPlus - 2 * y + yMinus) / (stepSize * stepSize);
}


#pragma mark Accessors
// ---------------------------------------- Accessors
void Derivative::setStepSize(double newStepSize) { stepSize = newStepSize; };
void Derivative::setErrorLimit(double newErrorLimit) { err = newErrorLimit; };
void Derivative::setMaxIterations(int newMaxIterations) { MAXITER = newMaxIterations; };

double Derivative::getStepSize() const { return stepSize; };
double Derivative::getErrorLimit() const { return err; };
int Derivative::getMaxIterations() const { return MAXITER; };

    
    
    
} // End Namespace Calculus
} // End Namespace fnMath
