//
//  GradientDescent.hpp
//  fnMath
//
//  Created by Steven Novak on 12/12/18.
//  Copyright © 2018 Steven Novak. All rights reserved.
//

#ifndef GRADIENTDESCENT_HPP
#define GRADIENTDESCENT_HPP

#include <memory>
#include "../Function.hpp"
#include "../LinAlg/LU.hpp"
#include "../Calculus/Derivative.hpp"

namespace fnMath {
namespace Optimization {
	
class GradientDescent
{	
    public:
	// ------------------------- Constructors

	GradientDescent();
	
	// ------------------------- Public Method
	double FindMin(std::vector<double> initialConditions);
	
	void SetFunction(const std::shared_ptr<Function> f);
	
	void SetInitialConditions(std::vector<double> initialConditions);
	
	void SetFlags(std::vector<bool> flags);
	
	// ------------------------- Private Members
	private:
	int _freeParams;
	
	std::shared_ptr<Calculus::Derivative> _differentiator;	
	std::shared_ptr<Function> _f;
	std::shared_ptr<vector<double>> _initialConditions; 
	std::shared_ptr<MatrixD> _jacobian;
	std::vector<bool> _flags;

    // ------------------------- Private Methods
	void CalculateJacobian(std::vector<double>* iteration);
	
}; 	// End class GradientDescent 
	
}	// End fnMath Namespace
}	// End optimization Namespace

#endif