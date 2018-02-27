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

<<<<<<< Updated upstream
<<<<<<< Updated upstream
bool testNaivePrime();
bool testNaiveSQPrime();

int main (int argCount, char** args)
{
    testNaivePrime();
    testNaiveSQPrime();
}

bool testNaivePrime()
{
    std::cout << "Testing Naive Prime Number Generator\n" << std::endl;
=======
=======
>>>>>>> Stashed changes
bool TestPrime();
void PrintTime(clock_t now);

int main (int argCount, char** args)
{
    TestPrime();
}

bool TestPrime()
{
    std::cout << "Testing Prime Number Generator\n" << std::endl;
    
>>>>>>> Stashed changes
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
        std::cout << "Highest Prime < 10,000 Found To Be: " << result << " : Expected 9,973 " << std::endl;
        return false;
    }


    now = clock();
    result = myPrime.GetPrime(1000000);
    PrintTime(now);
    if(result != 999983)
    {
        std::cout << "Highest Prime < 10,000 Found To Be: " << result << " : Expected 9,973 " << std::endl;
        return false;
    }

    now = clock();
    result = myPrime.GetPrime(10000000);
    PrintTime(now);
    if(result != 9999991)
    {
        std::cout << "Highest Prime < 10,000 Found To Be: " << result << " : Expected 9,973 " << std::endl;
        return false;
    }


    return true;
}

<<<<<<< Updated upstream
bool testNaiveSQPrime()
{
    std::cout << "Testing NaiveSQ Prime Number Generator\n" << std::endl;
    Prime myPrime;
<<<<<<< Updated upstream
    clock_t now, later;
    unsigned long long maxNumber = 10000000001;
    now = clock();
    unsigned long long result = myPrime.Naive(maxNumber);
    later = clock();
=======
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
        std::cout << "Highest Prime < 10,000 Found To Be: " << result << " : Expected 9,973 " << std::endl;
        return false;
    }


    now = clock();
    result = myPrime.GetPrime(1000000);
    PrintTime(now);
    if(result != 999983)
    {
        std::cout << "Highest Prime < 10,000 Found To Be: " << result << " : Expected 9,973 " << std::endl;
        return false;
    }

    now = clock();
    result = myPrime.GetPrime(10000000);
    PrintTime(now);
    if(result != 9999991)
    {
        std::cout << "Highest Prime < 10,000 Found To Be: " << result << " : Expected 9,973 " << std::endl;
        return false;
    }
>>>>>>> Stashed changes


<<<<<<< Updated upstream
    return 0;
=======
=======
    return true;
}

>>>>>>> Stashed changes
void PrintTime(clock_t now)
{
    clock_t later = clock();
    std::cout << ((float)(later - now) / CLOCKS_PER_SEC) << " s elapsed" << std::endl;
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
}