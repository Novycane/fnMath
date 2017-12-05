//
//  Transforms.hpp
//  fnMath
//
//  Created by Steven Novak on 2/8/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#include "Matrix.cpp"

#ifndef Transforms_hpp
#define Transforms_hpp

namespace fnMath{
namespace LinAlg{
    
template <typename Numeric> bool HouseHolder(Matrix<Numeric> & v, Matrix<Numeric> & H, int offset);

    
} // End LinAlg namespace
} // End fnMath namespace

#endif /* Transforms_hpp */
