//
//  GradientDescent.hpp
//  fnMath
//
//  Created by Steven Novak on 12/12/18.
//  Copyright © 2018 Steven Novak. All rights reserved.
//

#ifndef GRADIENTDESCENT_HPP
#define GRADIENTDESCENT_HPP

#include "../Function.hpp"
#include "../LinAlg/LU.hpp"
#include "../Calculus/Derivative.hpp"

namespace fnMath {
namespace Optimization {
	
class GradientDescent
{	
    // ------------------------- Public Method
	public:
	
	void FindMin(std::vector<double> initialConditions);
	
	void SetFunction(Function* f);
	
	void SetInitialConditions(std::vector<double> initialConditions);
	
	void SetFlags(std::vector<bool> flags);
	
	// ------------------------- Private Members
	private:
	Function* _f;
	std::vector<double> _initialConditions;
	std::vector<bool> _flags;

    // ------------------------- Private Methods
	void CalculateJacobian();
	
}; 	// End class GradientDescent 
	
}	// End fnMath Namespace
}	// End optimization Namespace

#endif