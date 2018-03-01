//
//  Prime.test.cpp
//  
//
//  Created by Steven Novak on 02/20/2018.
//
// --------------------------------------------------
//
//
//
//
// --------------------------------------------------

#include <iostream>
#include <time.h>
#include "../src/Crypto/Prime.hpp"

using namespace fnMath;
using namespace Crypto;

bool TestPrime();
bool TestSegmentedPrime();
bool TestSQPrime();
void ComparePerformance();
void PrintTime(clock_t now);

int main (int argCount, char** args)
{
    TestPrime();
    TestSQPrime();
    ComparePerformance();
    TestSegmentedPrime();
}

bool TestPrime()
{
    std::cout << "Testing Prime Number Generator\n" << std::endl;
    
    Prime myPrime;
    clock_t  now;

    now = clock();
    unsigned long long result = myPrime.GetPrime(20);
    PrintTime(now);
    if(result != 19)
    {
        std::cout << "Highest Prime < 20 Found To Be: " << result << " : Expected 19 " << std::endl;
        return false;
    }

    now = clock();
    result = myPrime.GetPrime(100);
    PrintTime(now);
    if(result != 97)
    {
        std::cout << "Highest Prime < 100 Found To Be: " << result << " : Expected 97 " << std::endl;
        return false;
    }

    now = clock();
    result = myPrime.GetPrime(10000);
    PrintTime(now);
    if(result != 9973)
    {
        std::cout << "Highest Prime < 10,000 Found To Be: " << result << " : Expected 9,973 " << std::endl;
        return false;
    }

    now = clock();
    result = myPrime.GetPrime(100000);
    PrintTime(now);
    if(result != 99991)
    {
        std::cout << "Highest Prime < 100,000 Found To Be: " << result << " : Expected 99,991 " << std::endl;
        return false;
    }


    now = clock();
    result = myPrime.GetPrime(1000000);
    PrintTime(now);
    if(result != 999983)
    {
        std::cout << "Highest Prime < 1,000,000 Found To Be: " << result << " : Expected 999,983 " << std::endl;
        return false;
    }

    now = clock();
    result = myPrime.GetPrime(10000000);
    PrintTime(now);
    if(result != 9999991)
    {
        std::cout << "Highest Prime < 10,000,000 Found To Be: " << result << " : Expected 9,999,991 " << std::endl;
        return false;
    }

    return true;
}

bool TestSQPrime()
{
    std::cout << "Testing Odd Only Prime Number Generator\n" << std::endl;
    
    Prime myPrime;
    clock_t  now;

    now = clock();
    unsigned long long result = myPrime.NaiveSQ(20);
    PrintTime(now);
    if(result != 19)
    {
        std::cout << "Highest Prime < 20 Found To Be: " << result << " : Expected 19 " << std::endl;
        return false;
    }

    now = clock();
    result = myPrime.NaiveSQ(100);
    PrintTime(now);
    if(result != 97)
    {
        std::cout << "Highest Prime < 100 Found To Be: " << result << " : Expected 97 " << std::endl;
        return false;
    }

    now = clock();
    result = myPrime.NaiveSQ(10000);
    PrintTime(now);
    if(result != 9973)
    {
        std::cout << "Highest Prime < 10,000 Found To Be: " << result << " : Expected 9,973 " << std::endl;
        return false;
    }

    now = clock();
    result = myPrime.NaiveSQ(100000);
    PrintTime(now);
    if(result != 99991)
    {
        std::cout << "Highest Prime < 100,000 Found To Be: " << result << " : Expected 99,991 " << std::endl;
        return false;
    }


    now = clock();
    result = myPrime.NaiveSQ(1000000);
    PrintTime(now);
    if(result != 999983)
    {
        std::cout << "Highest Prime < 1,000,000 Found To Be: " << result << " : Expected 999,983 " << std::endl;
        return false;
    }

    now = clock();
    result = myPrime.NaiveSQ(10000000);
    PrintTime(now);
    if(result != 9999991)
    {
        std::cout << "Highest Prime < 10,000,000 Found To Be: " << result << " : Expected 9,999,991 " << std::endl;
        return false;
    }

    return true;
}

void ComparePerformance()
{
    std::cout << "Comparing Performance\n" << std::endl;
    Prime myPrime;
    clock_t  now;
    unsigned long long result;

    now = clock();
    result = myPrime.Naive(3000000000);
    PrintTime(now);
    std::cout << "Odd And Even " << result << std::endl;

    now = clock();
    result = myPrime.NaiveSQ(3000000000);
    PrintTime(now);
    std::cout << "Odd Only " << result << std::endl;

}

bool TestSegmentedPrime()
{
    std::cout << "Testing Segmented Prime Number Generator\n" << std::endl;
    
    Prime myPrime;
    clock_t  now;

    now = clock();
    unsigned long long result = myPrime.Segmented(20);
    PrintTime(now);
    if(result != 19)
    {
        std::cout << "Highest Prime < 20 Found To Be: " << result << " : Expected 19 " << std::endl;
        //return false;
    }

    now = clock();
    result = myPrime.Segmented(100);
    PrintTime(now);
    if(result != 97)
    {
        std::cout << "Highest Prime < 100 Found To Be: " << result << " : Expected 97 " << std::endl;
        //return false;
    }

    now = clock();
    result = myPrime.Segmented(10000);
    PrintTime(now);
    if(result != 9973)
    {
        std::cout << "Highest Prime < 10,000 Found To Be: " << result << " : Expected 9,973 " << std::endl;
        //return false;
    }

    return true;
}

void PrintTime(clock_t now)
{
    clock_t later = clock();
    std::cout << ((float)(later - now) / CLOCKS_PER_SEC) << " s elapsed" << std::endl;
}