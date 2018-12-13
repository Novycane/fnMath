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

	

    // --------------------------------------------------
    // ----- Public Methods


	void GradientDescent::SetFunction(Function* f)
	{
		_f = f;
	}
	
	void GradientDescent::SetInitialConditions(std::vector<double> initialConditions)
	{
		_initialConditions = initialConditions;
	}
	
	void GradientDescent::SetFlags(std::vector<bool> flags)
	{
		_flags = flags;
	}

    // --------------------------------------------------
    // ----- Private Methods

	void GradientDescent::CalculateJacobian()
	{
		
	}
	
	
}	// end fnMath Namespace
}	// end Optimization namespace