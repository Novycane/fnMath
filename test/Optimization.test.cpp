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
    double Evaluate(double x)
    {
        return x * x - 5;
    }

    double Evaluate(fnMath::LinAlg::MatrixD params)
    {
        return params[0][0] * params[0][0] - 5;
    }
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
	GradientDescent GD; 
	
	flags.push_back(true);
	
	GD.SetFunction(new Quadratic());
	GD.SetFlags(flags);
	
	return true;
}