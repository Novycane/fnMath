//
//  Factorial.cpp
//  fnMath
//
//  Created by Steven Novak on 2/2/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#include "Factorial.hpp"
#include <cmath>
#include <iostream>

namespace fnMath{
    
int Factorial::maxN = 0;
double Factorial::values[256] = {0};

Factorial::Factorial()
{
}
    
double Factorial::Compute(int n)
{
    return exp(ComputeLn(n));
}

double Factorial::ComputeLn(int n)
{
    if(n <= maxN)
        return Factorial::values[n];
    
    for(int i=maxN+1; i<=n; i++)
    {
        Factorial::values[i] = Factorial::values[i-1] + log(i);
        //std::cout << i << " " << exp(values[i]) << std::endl;
    }
    
    return Factorial::values[n];
}
    
} // End fnMath Namespace
