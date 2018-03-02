//
//  Rijndael.hpp
//  fnMath
//
//  Created by Steven Novak on 2/20/2018.
//  Copyright © 2018 Steven Novak. All rights reserved.
//
//
//
//
//
//
//
//
//

#ifndef PRIME_HPP
#define PRIME_HPP

#include <memory>
#include <iostream>
#include <cmath>
#include "../Stats/Random.hpp"

namespace fnMath {
namespace Crypto {

class Prime
{
    public:
    // ------------------------- Constructors

    // ------------------------- Accessors
    
    // ------------------------- Public Methods
    static unsigned long long GetPrime(unsigned long long maxNumber);

    static unsigned long long* RandomPrime1024();

    static unsigned long long* RandomPrime512();

    static unsigned long long* RandomPrime256();

    static unsigned long long* RandomPrime128();

    static unsigned long long RandomPrime64();

    static unsigned long RandomPrime32();

    static unsigned int RandomPrime16();

    static unsigned long long Segmented(unsigned long long maxNumber);

    static unsigned long long Naive (unsigned long long maxNumber);

    static unsigned long long NaiveSQ (unsigned long long maxNumber);

    private:
    // ------------------------- Private Members
    

    // ------------------------- Private Methods

}; // End Prime Class

} // End Crypto Namespace
} // End fnMath Namespace

#endif