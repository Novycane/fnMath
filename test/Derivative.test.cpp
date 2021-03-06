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

bool TestD_Forward_Partial();
bool TestD_For_One_Side_Partial();
bool TestD_Backward_Partial();
bool TestD_Back_One_Side_Partial();
bool TestD_Centered_Partial();
bool TestD2_Centered_Partial();
bool TestD1_Partial();
bool TestD2_Partial();

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

class Func2 : public fnMath::Function
{
public:
    double Evaluate(double x)
    {
        return 0;
    }

    double Evaluate(vector<double> params)
    {
        return 2 * params[0] + exp(params[1]);
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

    std::cout << "Testing Backward Derivative";
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

	// ----- Partial
	
	std::cout << "Testing Forward Partial Derivative";
    result = TestD_Forward_Partial();
    if(result)
        std::cout << "...ok" << std::endl;
    else 
        std::cout << "...Failed!";
	
	std::cout << "Testing One Sided Forward Partial Derivative";
    result = TestD_For_One_Side_Partial();
    if(result)
        std::cout << "...ok" << std::endl;
    else 
        std::cout << "...Failed!";
	
	std::cout << "Testing Backward Partial Derivative";
    result = TestD_Backward_Partial();
    if(result)
        std::cout << "...ok" << std::endl;
    else 
        std::cout << "...Failed!";
	
	std::cout << "Testing Backward One Side Partial Derivative";
    result = TestD_Back_One_Side_Partial();
    if(result)
        std::cout << "...ok" << std::endl;
    else 
        std::cout << "...Failed!";

	std::cout << "Testing Centered Partial Derivative";
    result = TestD_Centered_Partial();
    if(result)
        std::cout << "...ok" << std::endl;
    else 
        std::cout << "...Failed!";
	
	std::cout << "Testing Centered Partial Second Derivative";
    result = TestD2_Centered_Partial();
    if(result)
        std::cout << "...ok" << std::endl;
    else 
        std::cout << "...Failed!";

	std::cout << "Testing D1 Partial";
    result = TestD1_Partial();
    if(result)
        std::cout << "...ok" << std::endl;
    else 
        std::cout << "...Failed!";

	std::cout << "Testing D2 Partial";
    result = TestD2_Partial();
    if(result)
        std::cout << "...ok" << std::endl;
    else 
        std::cout << "...Failed!";

    return 0;
}

// ------------------------- Tests

bool TestD_Forward()
{
    std::shared_ptr<Exponential> e = make_shared<Exponential>();
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
    std::shared_ptr<Exponential> e = make_shared<Exponential>();
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
    std::shared_ptr<Exponential> e = make_shared<Exponential>();
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
    std::shared_ptr<Exponential> e = make_shared<Exponential>();
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
    std::shared_ptr<Exponential> e = make_shared<Exponential>();
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
    std::shared_ptr<Exponential> e = make_shared<Exponential>();
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
    std::shared_ptr<Exponential> e = make_shared<Exponential>();
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
    std::shared_ptr<Exponential> e = make_shared<Exponential>();
    Derivative D(e);
    const double actual = 22026.4657948067169579;
    double result;

    result = D.D2(10);
    if(abs(result - actual) / actual < 1e-5)
        return true;

    return false;
}

bool TestD_Forward_Partial()
{
	std::shared_ptr<Func2> f = make_shared<Func2>();
    Derivative D(f);
	vector<double> params;
	
    const double actual = 2;
	const double actual2 = 22026.4657948067169579;
    double result;
	double result2;
	
	bool pass, pass2;
	pass = pass2 = false;

	params.push_back(10);
	params.push_back(10);

    for(double i=1; i>1e-20; i/=2)
    {
        D.setStepSize(i);
        result = D.D_Forward_Partial(params, 0);
		result2 = D.D_Forward_Partial(params, 1);
        if(abs(result - actual) / actual < 1e-5)
            pass = true;
		if(abs(result2 - actual2) / actual2 < 1e-5)
            pass2 = true;
		
		if(pass & pass2)
			return true;
    }

    return false;
}

bool TestD_For_One_Side_Partial()
{
    std::shared_ptr<Func2> f = make_shared<Func2>();
    Derivative D(f);
	vector<double> params;
	
    const double actual = 2;
	const double actual2 = 22026.4657948067169579;
    double result;
	double result2;
	
	bool pass, pass2;
	pass = pass2 = false;

	params.push_back(10);
	params.push_back(10);

    for(double i=1; i>1e-20; i/=2)
    {
        D.setStepSize(i);
        result = D.D_For_One_Side_Partial(params, 0);
		result2 = D.D_For_One_Side_Partial(params, 1);
        if(abs(result - actual) / actual < 1e-5)
            pass = true;
		if(abs(result2 - actual2) / actual2 < 1e-5)
            pass2 = true;
		
		if(pass & pass2)
			return true;
    }

    return false;
}

bool TestD_Backward_Partial()
{
    std::shared_ptr<Func2> f = make_shared<Func2>();
    Derivative D(f);
	vector<double> params;
	
    const double actual = 2;
	const double actual2 = 22026.4657948067169579;
    double result;
	double result2;
	
	bool pass, pass2;
	pass = pass2 = false;

	params.push_back(10);
	params.push_back(10);

    for(double i=1; i>1e-20; i/=2)
    {
        D.setStepSize(i);
        result = D.D_Backward_Partial(params, 0);
		result2 = D.D_Backward_Partial(params, 1);
			
        if(abs(result - actual) / actual < 1e-5)
            pass = true;
		if(abs(result2 - actual2) / actual2 < 1e-5)
            pass2 = true;
		
		if(pass & pass2)
			return true;
    }

    return false;
}

bool TestD_Back_One_Side_Partial()
{
    std::shared_ptr<Func2> f = make_shared<Func2>();
    Derivative D(f);
	vector<double> params;
	
    const double actual = 2;
	const double actual2 = 22026.4657948067169579;
    double result;
	double result2;
	
	bool pass, pass2;
	pass = pass2 = false;

	params.push_back(10);
	params.push_back(10);

    for(double i=1; i>1e-20; i/=2)
    {
        D.setStepSize(i);
        result = D.D_Back_One_Side_Partial(params, 0);
		result2 = D.D_Back_One_Side_Partial(params, 1);
        if(abs(result - actual) / actual < 1e-5)
            pass = true;
		if(abs(result2 - actual2) / actual2 < 1e-5)
            pass2 = true;
		
		if(pass & pass2)
			return true;
    }
    return false;
}

bool TestD_Centered_Partial()
{
    std::shared_ptr<Func2> f = make_shared<Func2>();
    Derivative D(f);
	vector<double> params;
	
    const double actual = 2;
	const double actual2 = 22026.4657948067169579;
    double result;
	double result2;
	
	bool pass, pass2;
	pass = pass2 = false;

	params.push_back(10);
	params.push_back(10);

    for(double i=1; i>1e-20; i/=2)
    {
        D.setStepSize(i);
        result = D.D_Centered_Partial(params, 0);
		result2 = D.D_Centered_Partial(params, 1);
        if(abs(result - actual) / actual < 1e-5)
            pass = true;
		if(abs(result2 - actual2) / actual2 < 1e-5)
            pass2 = true;
		
		if(pass & pass2)
			return true;
    }
    return false;
}

bool TestD2_Centered_Partial()
{
    std::shared_ptr<Func2> f = make_shared<Func2>();
    Derivative D(f);
	vector<double> params;
	
    const double actual = 0;
	const double actual2 = 22026.4657948067169579;
    double result;
	double result2;
	
	bool pass, pass2;
	pass = pass2 = false;

	params.push_back(10);
	params.push_back(10);

    for(double i=1; i>1e-20; i/=2)
    {
        D.setStepSize(i);
        result = D.D2_Centered_Partial(params, 0);
		result2 = D.D2_Centered_Partial(params, 1);
			
        if(result == actual)
            pass = true;
		if(abs(result2 - actual2) / actual2 < 1e-5)
            pass2 = true;
		
		if(pass & pass2)
			return true;
    }
    return false;
}

bool TestD1_Partial()
{
    std::shared_ptr<Func2> f = make_shared<Func2>();
    Derivative D(f);
	vector<double> params;
	
    const double actual = 2;
	const double actual2 = 22026.4657948067169579;
    double result;
	double result2;
	
	bool pass, pass2;
	pass = pass2 = false;

	params.push_back(10);
	params.push_back(10);
	
    result = D.D1_Partial(params, 0);
	result2 = D.D1_Partial(params, 1);
		
    if(abs(result - actual) / actual < 1e-5)
		pass = true;
	if(abs(result2 - actual2) / actual2 < 1e-5)
        pass2 = true;
	
	if(pass & pass2)
		return true;
    return false;
}

bool TestD2_Partial()
{
    std::shared_ptr<Func2> f = make_shared<Func2>();
    Derivative D(f);
	vector<double> params;
	
    const double actual = 0.0;
	const double actual2 = 22026.4657948067169579;
    double result;
	double result2;
	
	bool pass, pass2;
	pass = pass2 = false;

	params.push_back(10);
	params.push_back(10);

    result = D.D2_Partial(params, 0);
	result2 = D.D2_Partial(params, 1);

    if(result == actual)
		pass = true;
	if(abs(result2 - actual2) / actual2 < 1e-5)
        pass2 = true;
	
	if(pass & pass2)
		return true;
    return false;
}