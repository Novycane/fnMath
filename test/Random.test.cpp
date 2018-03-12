//
//  Random.test.cpp
//  
//
//  Created by Steven Novak on 12/6/17.
//
// --------------------------------------------------
//
//
//
//
// --------------------------------------------------

#include <iostream>
#include "../src/Stats/Random.hpp"

using namespace fnMath;

// ------------------------- Declarations
bool TestHWRandom();
bool TestRandomBetween();

// ------------------------- Main

int main (int argCount, char** args)
{   
    if(!TestHWRandom())
    {
        std::cout << "Error in HW RNG:\n ";
        return -1;
    }
    else
        std::cout << "...ok" << std::endl;

    
    if(!TestRandomBetween())
    {
        std::cout << "Error in HW RNG:\n ";
        return -1;
    }
    else
        std::cout << "...ok" << std::endl;

    return 0;
}

// ------------------------- Definitions

bool TestHWRandom()
{
    std::cout << "Testing HRNG...";

    RandomNumber r;
    double num = 0.0;

    for(int i=0; i<25000000; i++)
        num += r.GenerateDouble();

    if(abs(num / 25000000 - 0.5) > 0.0001)
    {
        std::cout << "Mean deviation larger than expected!!" << std::endl;
        return false;
    }

    return true;
}

bool TestRandomBetween()
{
    std::cout << "Testing Random Int Between...";

    RandomNumber r;

    for(int i=0; i<20000; i++)
    {
        uint16_t num = r.GenerateInt16(783,15624);
        if(num >= 15624 || num < 783)
        {
            std::cout << "GenInt16 Iteration " << i << " failed: " << num << "  !!" << std::endl;
            return false;
        }
    }

    for(int i=0; i<20000; i++)
    {
        uint32_t num = r.GenerateInt32(2097152, 1073741824);
        if(num >= 1073741824 || num < 2097152)
        {
            std::cout << "GenInt32 Iteration " << i << " failed: " << num << " !!" << std::endl;
            return false;
        }
    }

    for(int i=0; i<20000; i++)
    {
        uint64_t num = r.GenerateInt64(4294967296, 576460752303423488);
        if(num >= 576460752303423488 || num < 4294967296)
        {
            std::cout << "GenInt64 Iteration " << i << " failed: " << num << " !!" << std::endl;
            return false;
        }
    }

    return true;
}