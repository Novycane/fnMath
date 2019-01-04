//
//  Integral.test.cpp
//  
//
//  Created by Steven Novak on 02/28/2018.
//
// --------------------------------------------------
//
//
//
//
// --------------------------------------------------

#include <iostream>
#include "../src/fnMath.hpp"

using namespace fnMath::Calculus;

// ------------------------- Declarations

bool TestSetMAXITER();
bool TestTrapezoidal();
bool TestRhomberg();

class Exponential : public fnMath::Function
{
public:
    double Evaluate(double x)
    {
        return exp(x);
    }

    double Evaluate(vector<double> params)
    {
        return 0.0;
    }
};

// ------------------------- Main

int main (int argCount, char** args)
{
    bool result;
    std::cout << "\nTesting Trapezoidal Integration";
    result = TestTrapezoidal();
    if(result)
        std::cout << "...ok" << std::endl;
    else 
        std::cout << "...Failed!";

    std::cout << "Testing Rhomberg Integration";
    result = TestRhomberg();
    if(result)
        std::cout << "...ok" << std::endl;
    else 
        std::cout << "...Failed!";

    return 0;
}

// ------------------------- Tests

bool TestTrapezoidal()
{
    Trapezoidal T;
    Exponential* e = new Exponential();
    const double actual = 19.08553692318766774;
    double result;

    result = T.Integrate(e, 0, 3, 10000000);
    
    if(abs(result - actual) > 1e-5)
        return false;

    return true;
}

bool TestRhomberg()
{
    Rhomberg R;
    Exponential* e = new Exponential();
    const double actual = 19.08553692318766774;
    double result;

    result = R.Integrate(e, 0, 3);
    
    if(abs(result - actual) > R.getError())
        return false;

    return true;

    return true;
}