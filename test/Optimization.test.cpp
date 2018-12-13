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
#include "../src/Optimization/GradientDescent.hpp"

using namespace fnMath;
using namespace Optimization;

// ------------------------- Declarations
bool TestGradientDescent();

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
	
	return true;
}