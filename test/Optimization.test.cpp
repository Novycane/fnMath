//
//  Optimization.test.cpp
//  
//
//  Created by Steven Novak on 12/12/18.
//
// --------------------------------------------------
//
//
//
//
// --------------------------------------------------

#include <iostream>
#include <cmath>
#include "../src/fnMath.hpp"
#include "../src/Optimization/GradientDescent.hpp"

using namespace fnMath;
using namespace Optimization;
using namespace std;

// ------------------------- Declarations
bool TestGradientDescent();

// ------------------------- Functions

class Quadratic : public fnMath::Function
{
public:
	double x, y;
	
	Quadratic()
	{
		x = 76.0535;
		y = 0.168;
	}
	
    virtual double Evaluate(double x)
    {
        return x * x - 5;
    }

    virtual double Evaluate(vector<double> params)
    {
        return (params[0] - x) * (params[0] - x) + (params[1] - y) * (params[1] - y);
    }
private:
	

};

class Gaussian : public fnMath::Function
{
public:
	
    virtual double Evaluate(double x)
    {
        return _pre * exp(-(x-1.0)*(x-1.0)/(2));
    }

    virtual double Evaluate(vector<double> params)
    {
        return _pre / params[2] *exp(-(params[0]-params[1])*(params[0]-params[1])/(2 * params[2] * params[2]));
    }

private:
	const double _pre = 0.39894228;

};

// ------------------------- Main

int main (int argCount, char** args)
{   
    TestGradientDescent();
    return 0;
}

// ------------------------- Definitions

bool TestGradientDescent()
{
	std::cout << "Testing Gradient Descent Functions" << std::endl;
	vector<bool> flags;
	auto Q = make_shared<Quadratic>();
	auto guess = make_shared<vector<double>>();
	GradientDescent GD; 
	
	flags.push_back(true);
	flags.push_back(true);
	
	guess->push_back(100.0);
	guess->push_back(-512.0);
	
	GD.SetFunction(Q);
	GD.SetFlags(flags);
	
	double result = GD.FindMin(guess);
	
	cout << endl << "Result: " << result << endl;
	cout << "X: " << (*guess)[0] << "	Y: " << (*guess)[1] << endl;
	
	Q->x = -129.32;
	Q->y = 30.06;
	result = GD.FindMin(guess);
	
	
	cout << endl << "Result: " << result << endl;
	cout << "X: " << (*guess)[0] << "	Y: " << (*guess)[1] << endl;
	return true;
}