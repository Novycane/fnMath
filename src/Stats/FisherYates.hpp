//
//  FisherYates.hpp
//  fnMath
//
//  Created by Steven Novak on 03/05/2018.
//  Copyright © 2018 Steven Novak. All rights reserved.
//

#ifndef FISHERYATES_HPP
#define FISHERYATES_HPP

#include "Random.hpp"

namespace fnMath{

template <typename T>
class FisherYates
{
public:
    void ShuffleInPlace(T* array, uint16_t count);

};  // End FisherYates Class

} // End fnMath Namespace

#endif