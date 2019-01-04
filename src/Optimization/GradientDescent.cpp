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

	double GradientDescent::FindMin(std::vector<double> initialConditions)
	{
		double error = 0;
		double step = 0;
		double lastStep = DBL_MAX;
		std::vector<double> iteration = initialConditions;
		
		for(int i=0; i<MAXITER; i++)
		{			
			step = CalculateDerivative(&iteration);
			
			/*
			if(step < lastStep)
				_damping *= 2.0;
			else
				_damping /= 2.0;
			*/
			error = (lastStep - step);
			lastStep = step;
			cout << "Step: " << step << "	Error: " << error << endl;
			
			for(int j=0; j<iteration.size(); j++)
				cout << "	" << iteration[j];
			
			cout << endl;
			
			if(abs(error) < ERR)
				break;
		}
		
		return 0.0;
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
	
		_jacobian = make_shared<MatrixD>(0.0, _freeParams, _freeParams);
	}

    // --------------------------------------------------
    // ----- Private Methods

	double GradientDescent::CalculateDerivative(std::vector<double>* iteration)
	{
		std::vector<double> results; 
		double error = 0;
		
		for(int i=0; i<_freeParams; i++)
			results.push_back(_differentiator->D1_Partial(*iteration, i));

		for(int i=0; i<_freeParams; i++)
		{
			cout << "D: " << results[i] << " I: " << (*iteration)[i] << endl;
			(*iteration)[i] = (*iteration)[i] - results[i] * _damping;
			error += (*iteration)[i];
		}
		cout << endl;
		return sqrt(error);
	}
	
	
}	// end fnMath Namespace
}	// end Optimization namespace