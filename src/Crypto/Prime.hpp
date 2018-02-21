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

#include <memory>
#include <iostream>

namespace fnMath {
namespace Crypto {

class Prime
{
    public:
    // ------------------------- Constructors

    // ------------------------- Accessors
    
    // ------------------------- Public Methods
    static unsigned long long GetPrime(unsigned long long maxNumber);

    private:
    // ------------------------- Private Members
    static unsigned long long Naive (unsigned long long maxNumber);

    // ------------------------- Private Methods

}; // End Prime Class

} // End Crypto Namespace
} // End fnMath Namespace