//
//  Prime.test.cpp
//  
//
//  Created by Steven Novak on 02/20/2018.
//
// --------------------------------------------------
//
//
//
//
// --------------------------------------------------

#include <iostream>
#include <time.h>
#include "../src/Crypto/Prime.hpp"

using namespace fnMath;
using namespace Crypto;

int main (int argCount, char** args)
{
    std::cout << "Testing Prime Number Generator\n" << std::endl;
    
    Prime myPrime;
    clock_t now, later;
    unsigned long long maxNumber = 1000000001;
    now = clock();
    unsigned long long result = myPrime.GetPrime(maxNumber);
    later = clock();

    std::cout << "The Largest Prime < " << maxNumber << " is: " << result << std::endl;
    std::cout << ((float)(later - now) / CLOCKS_PER_SEC) << " s elapsed" << std::endl;

    return 0;
}
