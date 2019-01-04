//
//  Derivative.hpp
//  fnMath
//
//  Created by Steven Novak on 2/3/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#ifndef Derivative_hpp
#define Derivative_hpp

#include "../Function.hpp"

namespace fnMath{
namespace Calculus{

class Derivative
{
public:
    // -------------------- Constructors
    Derivative(std::shared_ptr<Function> Fun);
    
    // -------------------- Public Methods
    double D_Forward(double x);
    double D_For_One_Side(double x);
    double D_Backward(double x);
    double D_Back_One_Side(double x);
    double D_Centered(double x);
    double D2_Centered(double x);
    double D1(double x);
    double D2(double x);
    
	double D_Forward_Partial(vector<double> params, int index);
	double D_For_One_Side_Partial(vector<double> params, int index);
    double D_Backward_Partial(vector<double> params, int index);
    double D_Back_One_Side_Partial(vector<double> params, int index);
	double D_Centered_Partial(vector<double> params, int index);
    double D2_Centered_Partial(vector<double> params, int index);
    double D1_Partial(vector<double> params, int index);
    double D2_Partial(vector<double> params, int index);
	
    // -------------------- Accessors
    void setStepSize(double newStepSize);
    void setErrorLimit(double newErrorLimit);
    void setMaxIterations(int newMaxIterations);
    
    double getStepSize() const;
    double getErrorLimit() const;
    int getMaxIterations() const;
    
private:
    // -------------------- Private Members
    std::shared_ptr<Function> F;
    int MAXITER;
    double stepSize;
    double err;
    
};
    
} // End Namespace Calculus
} // End Namespace fnMath

#endif /* Derivative_hpp */
