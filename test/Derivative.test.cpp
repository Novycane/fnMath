//
//  Derivative.test.cpp
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

bool TestD_Forward();
bool TestD_For_One_Side();
bool TestD_Backward();
bool TestD_Back_One_Side();
bool TestD_Centered();
bool TestD2_Centered();
bool TestD1();
bool TestD2();

class Exponential : public fnMath::Function
{
public:
    double Evaluate(double x)
    {
        return exp(x);
    }

    double Evaluate(double x, fnMath::LinAlg::MatrixD params)
    {
        return 0.0;
    }
};

// ------------------------- Main

int main (int argCount, char** args)
{
    bool result;
    std::cout << "\nTesting Forward Derivative";
    result = TestD_Forward();
    if(result)
        std::cout << "...ok" << std::endl;
    else 
        std::cout << "...Failed!";

    std::cout << "Testing Onesided Forward Derivative";
    result = TestD_For_One_Side();
    if(result)
        std::cout << "...ok" << std::endl;
    else 
        std::cout << "...Failed!";

    std::cout << "Testing Backaward Derivative";
    result = TestD_Backward();
    if(result)
        std::cout << "...ok" << std::endl;
    else 
        std::cout << "...Failed!";

    std::cout << "Testing Onesided Backward Derivative";
    result = TestD_Back_One_Side();
    if(result)
        std::cout << "...ok" << std::endl;
    else 
        std::cout << "...Failed!";

    std::cout << "Testing Centered Derivative";
    result = TestD_Centered();
    if(result)
        std::cout << "...ok" << std::endl;
    else 
        std::cout << "...Failed!";

    std::cout << "Testing Centered 2nd Derivative";
    result = TestD2_Centered();
    if(result)
        std::cout << "...ok" << std::endl;
    else 
        std::cout << "...Failed!";

    std::cout << "Testing D1";
    result = TestD1();
    if(result)
        std::cout << "...ok" << std::endl;
    else 
        std::cout << "...Failed!";

    std::cout << "Testing D2";
    result = TestD2();
    if(result)
        std::cout << "...ok" << std::endl;
    else 
        std::cout << "...Failed!";

    return 0;
}

// ------------------------- Tests

bool TestD_Forward()
{
    Exponential* e = new Exponential();
    Derivative D(e);
    const double actual = 22026.4657948067169579;
    double result;

    for(double i=1; i>1e-20; i/=2)
    {
        D.setStepSize(i);
        result = D.D_Forward(10);
        if(abs(result - actual) / actual < 1e-5)
            return true;
    }
    return false;
}

bool TestD_For_One_Side()
{
    Exponential* e = new Exponential();
    Derivative D(e);
    const double actual = 22026.4657948067169579;
    double result;

    for(double i=1; i>1e-20; i/=2)
    {
        D.setStepSize(i);
        result = D.D_Forward(10);
        if(abs(result - actual) / actual < 1e-5)
            return true;
    }
    return false;
}

bool TestD_Backward()
{
    Exponential* e = new Exponential();
    Derivative D(e);
    const double actual = 22026.4657948067169579;
    double result;

    for(double i=1; i>1e-20; i/=2)
    {
        D.setStepSize(i);
        result = D.D_Back_One_Side(10);
        if(abs(result - actual) / actual < 1e-5)
            return true;
    }
    return false;
}

bool TestD_Back_One_Side()
{
    Exponential* e = new Exponential();
    Derivative D(e);
    const double actual = 22026.4657948067169579;
    double result;

    for(double i=1; i>1e-20; i/=2)
    {
        D.setStepSize(i);
        result = D.D_Back_One_Side(10);
        if(abs(result - actual) / actual < 1e-5)
            return true;
    }
    return false;
}

bool TestD_Centered()
{
    Exponential* e = new Exponential();
    Derivative D(e);
    const double actual = 22026.4657948067169579;
    double result;

    for(double i=1; i>1e-20; i/=2)
    {
        D.setStepSize(i);
        result = D.D_Centered(10);
        if(abs(result - actual) / actual < 1e-5)
            return true;
    }
    return false;
}

bool TestD2_Centered()
{
    Exponential* e = new Exponential();
    Derivative D(e);
    const double actual = 22026.4657948067169579;
    double result;

    for(double i=1; i>1e-20; i/=2)
    {
        D.setStepSize(i);
        result = D.D2_Centered(10);
        if(abs(result - actual) / actual < 1e-5)
            return true;
    }
    return false;
}

bool TestD1()
{
    Exponential* e = new Exponential();
    Derivative D(e);
    const double actual = 22026.4657948067169579;
    double result;

    result = D.D1(10);
    if(abs(result - actual) / actual < 1e-5)
        return true;

    return false;
}

bool TestD2()
{
    Exponential* e = new Exponential();
    Derivative D(e);
    const double actual = 22026.4657948067169579;
    double result;

    result = D.D2(10);
    if(abs(result - actual) / actual < 1e-5)
        return true;

    return false;
}