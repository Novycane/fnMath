//
//  Transforms.cpp
//  fnMath
//
//  Created by Steven Novak on 2/8/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#include "Transforms.hpp"

#ifndef Transforms_cpp
#define Transforms_cpp

namespace fnMath{
namespace LinAlg{
    

template <typename Numeric> bool HouseHolder(Matrix<Numeric> & v, Matrix<Numeric> & H, int offset)
{
 
    H[0][0] = 100;
    
    return true;
}
    
        
} // End LinAlg namespace
} // End fnMath namespace

#endif
