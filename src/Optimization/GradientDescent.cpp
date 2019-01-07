//
//  GradientDescent.cpp
//  fnMath
//
//  Created by Steven Novak on 12/12/18.
//  Copyright © 2018 Steven Novak. All rights reserved.
//

#include "GradientDescent.hpp"

namespace fnMath {
namespace Optimization {

	// --------------------------------------------------
    // ----- Constructors

	GradientDescent::GradientDescent()
	{
		_freeParams = 0;
		MAXITER = 100;
		ERR = 1e-5;
		_damping = 0.5;
	}

    // --------------------------------------------------
    // ----- Public Methods

	double GradientDescent::FindMin(std::shared_ptr<std::vector<double>> initialConditions)
	{
		double error = 0;
		double step = 0;
		double lastStep = DBL_MAX;
		
		_derivative = make_shared<vector<double>>(initialConditions->size());
		
		for(int i=0; i<MAXITER; i++)
		{			
			step = CalculateDerivative(initialConditions);
			error = (lastStep - step);
			lastStep = step;
			
			if(abs(error) < ERR)
				break;
		}
		
		return error;
	}
	
	void GradientDescent::SetFunction(const std::shared_ptr<Function> f)
	{
		_f = f;
		_differentiator = std::make_shared<Calculus::Derivative>(_f);
	}
	
	void GradientDescent::SetInitialConditions(std::vector<double> initialConditions)
	{
		_initialConditions = make_shared<vector<double>>(initialConditions);
	}
	
	void GradientDescent::SetFlags(std::vector<bool> flags)
	{
		_flags = flags;
		for(int i=0; i< flags.size(); i++)
			if(flags[i])
				_freeParams++;
	}

    // --------------------------------------------------
    // ----- Private Methods

	double GradientDescent::CalculateDerivative(std::shared_ptr<std::vector<double>> iteration)
	{
		double error = 0;
		
		for(int i=0; i<_freeParams; i++)
			(*_derivative)[i] = _differentiator->D1_Partial(*iteration, i);

		for(int i=0; i<_freeParams; i++)
		{
			(*iteration)[i] = (*iteration)[i] - (*_derivative)[i] * _damping;
			error += (*iteration)[i];
		}

		return sqrt(error);
	}
	
	
}	// end fnMath Namespace
}	// end Optimization namespace