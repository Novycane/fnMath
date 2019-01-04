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
	}

    // --------------------------------------------------
    // ----- Public Methods

	double GradientDescent::FindMin(std::vector<double> initialConditions)
	{
		std::vector<double> iteration = initialConditions;
		
		CalculateJacobian(&iteration);
		
		return 0.0;
	}

	void GradientDescent::SetFunction(const std::shared_ptr<Function> f)
	{
		_f = f;
		_differentiator = std::make_shared<Calculus::Derivative>(&_f);
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
	
		_jacobian = make_shared<MatrixD>(0.0, _freeParams, _freeParams);
	}

    // --------------------------------------------------
    // ----- Private Methods

	void GradientDescent::CalculateJacobian(std::vector<double>* iteration)
	{
		double d;
		std::vector<double> junk;
		for(int i=0; i<_freeParams; i++)
		{
			d = _differentiator->D1_Partial(junk, i);
			//(*_jacobian)[i][i] = d * d;
			for(int j=i+1; j < _freeParams; j++)
			{
				std::cout << i << "	" << j << std::endl;
			}
		}
		
		_jacobian->print();
	}
	
	
}	// end fnMath Namespace
}	// end Optimization namespace