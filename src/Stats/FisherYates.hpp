//
//  FisherYates.hpp
//  fnMath
//
//  Created by Steven Novak on 03/05/2018.
//  Copyright © 2018 Steven Novak. All rights reserved.
//

#ifndef FISHERYATES_HPP
#define FISHERYATES_HPP

#include "FisherYates.cpp"

namespace fnMath{

template <typename T>
class FisherYates
{
public:
    static void ShuffleInPlace(T* array, int count);
};  // End FisherYates Class

} // End fnMath Namespace

#endif