//
//  Random.cpp
//  fnMath
//
//  Created by Steven Novak on 2/7/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#include "Random.hpp"
#include <iostream>
#include <cmath>

namespace fnMath{

#pragma mark Constructors
// ---------------------------------------- Constructors
RandomNumber::RandomNumber()
{
    CheckHardwareAvailability();
    SeedOffClock();
    if(hardwareRNGPresent)
    {
        RandomNumberGenerator = &RandomNumber::GetHardware64;
    }
    else
    {
        RandomNumberGenerator = &RandomNumber::GetPseudo64;
    }
    
    // Set default normal deviate pair generation routine
    NormalDeviates = &RandomNumber::GeneratePolarPair;
}
    
    
#pragma mark Public Methods
// ---------------------------------------- Public Methods

double RandomNumber::GenerateNormal()
{
    double x, y;

    GenerateNormals(&x, &y);
    
    return x;
}
    
double RandomNumber::GenerateDouble()
{
    (this->*RandomNumberGenerator)(&RandNum);
    return ((double)(RandNum)) / UINT64_MAX;
}
    
float RandomNumber::GenerateFloat()
{
    uint32_t RandomInt;
    (this->*RandomNumberGenerator)(&RandNum);
    RandomInt = (uint32_t) RandNum;
    return ((float)(RandomInt)) / UINT32_MAX;
}
    
uint64_t RandomNumber::GenerateInt64()
{
    (this->*RandomNumberGenerator)(&RandNum);
    return RandNum;
}

uint64_t RandomNumber::GenerateInt64(uint64_t lower, uint64_t upper)
{
    (this->*RandomNumberGenerator)(&RandNum);
    return (RandNum % (upper - lower) + lower);
}
    
uint32_t RandomNumber::GenerateInt32()
{
    uint32_t RandomInt;
    (this->*RandomNumberGenerator)(&RandNum);
    RandomInt = (uint32_t) RandNum;
    return RandomInt;
}

uint32_t RandomNumber::GenerateInt32(uint32_t lower, uint32_t upper)
{
    uint32_t RandomInt;
    (this->*RandomNumberGenerator)(&RandNum);
    RandomInt = (uint32_t) RandNum;
    return (RandomInt % (upper - lower) + lower);
}

uint16_t RandomNumber::GenerateInt16()
{
    uint16_t RandomInt;
    (this->*RandomNumberGenerator)(&RandNum);
    RandomInt = (uint16_t) RandNum;
    return RandomInt;
}

uint16_t RandomNumber::GenerateInt16(uint16_t lower, uint16_t upper)
{
    uint16_t RandomInt;
    (this->*RandomNumberGenerator)(&RandNum);
    RandomInt = (uint16_t) RandNum;
    return (RandomInt % (upper - lower) + lower);
}

void RandomNumber::SetSeed(uint64_t NewSeed)
{
    RandNum = Seed = NewSeed;
    GetPseudo64(&RandNum);
}

    
void RandomNumber::SeedOffClock()
{
    clock_t ticks = clock();
    RandNum = Seed = ticks;
    GetPseudo64(&RandNum);
}
    
void RandomNumber::ForcePseudoRand()
{
    RandomNumberGenerator = &RandomNumber::GetPseudo64;
}

void RandomNumber::ForceHardwareRand()
{
    RandomNumberGenerator = &RandomNumber::GetHardware64;
}

void RandomNumber::GenerateNormals(double* z0, double* z1)
{
    (this->*NormalDeviates)(z0, z1);
}
    
void RandomNumber::GenerateNormals(double mean, double stdev, double* z0, double* z1)
{
    (this->*NormalDeviates)(z0, z1);
    *z0 = *z0 * stdev + mean;
    *z1 = *z1 * stdev + mean;
}

double RandomNumber::GenerateExponential(double lambda)
{
    return -lambda * log(GenerateDouble());
}

double RandomNumber::GenerateExtremeValue(double a, double b)
{
    return a + b * log(log(GenerateDouble()));
}

double RandomNumber::GenerateGeometric(double p)
{
    return log(GenerateDouble()) / log(1-p);
}

double RandomNumber::GenerateLogistic(double mu, double b)
{
    return mu - b * log(1/GenerateDouble() - 1);
}

double RandomNumber::GenerateWeibull(double alpha, double beta)
{
    return alpha * pow(log(GenerateDouble()), 1/beta);
}
    
#pragma mark Private Methods
// ---------------------------------------- Private Methods
void RandomNumber::CheckHardwareAvailability()
{
    unsigned int ecx;
    unsigned int leaf = 1;
    unsigned int subleaf = 0;
    hardwareRNGPresent = true;
    
    asm volatile("cpuid"
                 : "=c" (ecx)
                 : "a" (leaf), "c" (subleaf));
    
    
    // Check for RDRAND Support
    if((ecx & 0x40000000) !=  0x40000000)
    {
        hardwareRNGPresent = false;
        return;
    }
    //std::cout << "Harware Random Number Generation Supported!\n";
}

void RandomNumber::GetHardware64(uint64_t *number)
{
    unsigned char passed;
        
    asm volatile ("rdrand %0\t\n"
                  "setc %1\t\n"
                  : "=r" (*number), "=qm" (passed));
    if(!passed)
        std::cout << "Failed" << std::endl;
}
    
void RandomNumber::GetPseudo64(uint64_t *number)
{    
    *number ^= *number >> shift1;
    *number ^= *number << shift2;
    *number ^= *number >> shift3;
}

void RandomNumber::GeneratePolarPair(double * z0, double * z1)
{
    double u, v, s = 0;
    
    while(s == 0 || s >= 1 )
    {
        v = GenerateDouble() * 2 - 1;
        u = GenerateDouble() * 2 - 1;
        s = (u * u) + (v * v);
    }
    s = sqrt(-2 * log(s) / s);
    *z0 = u * s;
    *z1 = v * s;
}



    

} // End fnMath namespace
