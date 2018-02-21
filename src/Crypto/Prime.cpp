//
//  Prime.cpp
//  fnMath
//
//  Created by Steven Novak on 2/20/2018.
//  Copyright © 2018 Steven Novak. All rights reserved.
//

#include "Prime.hpp"

namespace fnMath {
namespace Crypto {

#pragma mark Constructors
// ---------------------------------------- Constructors

#pragma mark Accessors
// ---------------------------------------- Accessors

#pragma mark Public Methods
// ---------------------------------------- Public Methods
unsigned long long Prime::GetPrime(unsigned long long maxNumber)
{
    return Naive(maxNumber);
}

#pragma mark Private Methods
// ---------------------------------------- Private Methods
unsigned long long Prime::Naive (unsigned long long maxNumber)
{
    bool* flags = (bool*)malloc(maxNumber * sizeof(bool));

    for(int i=0; i<maxNumber; i++)
        flags[i] = true;
 
    unsigned long long result;
    for(unsigned long long i=2; i<maxNumber; i++)
    {
        if(flags[i] == true)
        {
            result = i; 
            for(unsigned long long p = i + i; p<maxNumber; p+=i)
            {
                flags[p] = false;
            }
        }
    }

    delete flags;

    return result;
}


} // End Crypto Namespace
} // End fnMath Namespace
