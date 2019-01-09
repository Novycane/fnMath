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
void RunTest(bool pass, const char* testName);

bool TestHWRandom();
bool TestRandomBetween();
bool TestFisherYates();
bool TestMetropolisHastings();
bool TestNormals();

// ------------------------- Functions
class Exponential : public fnMath::Function
{
public:
    double Evaluate(double x)
    {
        return exp(x);
    }

    double Evaluate(vector<double> params)
    {
        return 0.0;
    }
};

class Square : public fnMath::Function
{
public:
    double Evaluate(double x)
    {
        double b = x;
        return b * b;
    }

    double Evaluate(vector<double> params)
    {
        return 0.0;
    }
};

class Tri : public fnMath::Function
{
public:
    double Evaluate(double x)
    {
		/*
        if(x < 0)
            return 0.0;
        else if(x < 5 )
            return x * 0.5;
        else if(x < 10 )
            return x;
        else if(x < 15 )
            return 10 - (x - 10);
        else if(x < 20 )
            return(5 * x - 15);
        else
            return 0.0;
        */
		
		if(x < -10)
			return (0.0);
		else if(x <= 0)
			return (x + 10) * 5;
		else if(x <= 10)
			return (x - 10) * -5;
		else
			return 0.0;
    }

    double Evaluate(vector<double> params)
    {
        return 0.0;
    }
};

// ------------------------- Main

int main (int argCount, char** args)
{   
    //TestMetropolisHastings();
    //TestNormals();

   
    RunTest(TestHWRandom(), "Hardware RNG");  
    RunTest(TestRandomBetween(), "Random Int between 2 values");
    RunTest(TestFisherYates(), "Fisher-Yates Shuffle");
    
    return 0;
}


// ------------------------- Utility 

void RunTest(bool pass, const char* testName)
{
	cout << testName << " Test" ;
	if(pass)
		cout << "...Ok" << endl;
	else
		cout << "...Failed!" << endl;
}

// ------------------------- Tests

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
    MetropolisHastings MH(new Tri());

    MH.BurnIn(10000);

    for(int i=0; i<100000; i++)
        std::cout << MH.GetNext() << std::endl;
    
    return true;
}

bool TestNormals()
{
    
    RandomNumber rng;
    
    double x, y;
    double x1, y1;
    
    std::cout << "x, y, x1, y1"  << std::endl;
    for(int i=0; i<50000; i++)
    {
        rng.GenerateNormals(&x, &y);
        rng.GenerateNormals(10, 3, &x1, &y1);
        std::cout << x << "," << y << "," << x1 << "," << y1 << std::endl;
    }
    
    return true;
}