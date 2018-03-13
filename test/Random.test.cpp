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
#include <cmath>
#include "../src/Function.hpp"
#include "../src/Stats/Random.hpp"
#include "../src/Stats/FisherYates.hpp"
#include "../src/Stats/FisherYates.cpp"
#include "../src/Stats/MetropolisHastings.hpp"

using namespace fnMath;
using namespace Stats;

// ------------------------- Declarations
bool TestHWRandom();
bool TestRandomBetween();
bool TestFisherYates();
bool TestMetropolisHastings();

class Exponential : public fnMath::Function
{
public:
    double Evaluate(double x)
    {
        return exp(x);
    }

    double Evaluate(double x, fnMath::LinAlg::MatrixD params)
    {
        return 0.0;
    }
};

class Square : public fnMath::Function
{
public:
    double Evaluate(double x)
    {
        return x * x;
    }

    double Evaluate(double x, fnMath::LinAlg::MatrixD params)
    {
        return 0.0;
    }
};

// ------------------------- Main

int main (int argCount, char** args)
{   
    TestMetropolisHastings();

    /*
    if(!TestHWRandom())
    {
        std::cout << "Error in HW RNG:\n ";
        return -1;
    }
    else
        std::cout << "...ok" << std::endl;

    
    if(!TestRandomBetween())
    {
        std::cout << "Error in Random Int Between RNG:\n ";
        return -1;
    }
    else
        std::cout << "...ok" << std::endl;

    if(!TestFisherYates())
    {
        std::cout << "Error in Fisher-Yates Shuffle:\n ";
        return -1;
    }
    else
        std::cout << "...ok" << std::endl;
    */
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

    double err = abs(num / 25000000 - 0.5);
    if(err > 0.0001)
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

bool TestFisherYates()
{
    int j = 200;
    uint16_t nums[j];
    for(int i=0; i<j; i++)
        nums[i] = i;
    FisherYates<uint16_t> fy;

    fy.ShuffleInPlace(nums, j);

    return true;
}

bool TestMetropolisHastings()
{
    MetropolisHastings MH(new Square());

    MH.BurnIn(100000);

    for(int i=0; i<1000000; i++)
        std::cout << MH.GetNext() << std::endl;

    return true;
}