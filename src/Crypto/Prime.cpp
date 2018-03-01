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

unsigned long long Prime::Segmented(unsigned long long maxNumber)
{
    double sqMax = sqrt(maxNumber);
    
    std::cout << "Max Number: " << maxNumber << std::endl;
    std::cout << "Initial Sieve: " << sqMax << std::endl;
    std::cout << "Number of segments: " << (maxNumber / sqMax) << std::endl;

    // Allocate that memory
    unsigned long long* primes = (unsigned long long*)malloc(sqMax * sizeof(unsigned long long));

    // Sieve to sqrt(n)
    bool* flags = (bool*)malloc(sqMax * sizeof(bool));
    int k=0;
    for(int i=0; i<sqMax; i++)
        flags[i] = true;
    for(unsigned long long i=2; i<sqMax; i++)
    {
        if(flags[i] == true)
        {
            primes[k++] = i;    
            for(unsigned long long p = i + i; p<sqMax; p+=i)
                flags[p] = false;
        }
    }
    delete flags;

    // Divide the total range into segments of size < sqrt(n)
    

    // for each segment of size x...
    // -- Create an array to store flags
    // -- Iterate through the primes in the initial sieve
    // -- Mark it's multiples in the segment

    delete primes;

    return 0;
}

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
            for(unsigned long long p = i + i; p < maxNumber; p += i)
            {
                flags[p] = false;
            }
        }
    }
    delete flags;
    return result;
}


unsigned long long Prime::NaiveSQ (unsigned long long maxNumber)
{
bool* flags = (bool*)malloc(maxNumber * sizeof(bool));

    for(int i=0; i<maxNumber; i++)
        if(i & 1) 
            flags[i] = true;
        else
            flags[i] = false;
 
    unsigned long long result;
    
    for(unsigned long long i=3; i < maxNumber; i++)
    {
        if(flags[i] == true)
        {
            result = i; 
            for(unsigned long long p = i + 2 * i; p<maxNumber; p += 2 * i)
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
