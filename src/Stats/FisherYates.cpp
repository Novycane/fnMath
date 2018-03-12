//
//  FisherYates.cpp
//  fnMath
//
//  Created by Steven Novak on 03/05/2018.
//  Copyright © 2018 Steven Novak. All rights reserved.
//

#include "FisherYates.hpp"

#ifndef FISHERYATES_CPP
#define FISHERYATES_CPP

namespace fnMath{

#pragma mark Public Methods
// ---------------------------------------- Public Methods

template <typename T>
void FisherYates<T>::ShuffleInPlace(T* array, uint16_t count)
{
    RandomNumber r;
    for(int i=count - 1; i > 0; i--)
    {
        int index = r.GenerateInt16(0, i);
        std::cout << i << " - " << array[i] << " - " << index;
        T temp = array[index];
        array[index] = array[i];
        array[i] = temp;
        std::cout << " : " << array[i] << std::endl;
    }
    std::cout << 0 << " - " << array[0] << " -   : " << array[0] << std::endl;
}

} // End fnMath NameSpace

#endif