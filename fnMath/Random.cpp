//
//  Random.cpp
//  fnMath
//
//  Created by Steven Novak on 2/7/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#include "Random.hpp"
#include <iostream>

namespace fnMath{

#pragma mark Constructors
// ---------------------------------------- Constructors
RandomNumber::RandomNumber()
{
    checkHardwareAvailability();
}
    
double RandomNumber::GenerateDouble()
{
    unsigned char passed;
    uint64_t RandomInt;
    
    asm volatile ("rdrand %0\t\n"
                  "setc %1\t\n"
                  : "=r" (RandomInt), "=qm" (passed));
    if(!passed)
            std::cout << "Failed" << std::endl;
    
    return ((double)(RandomInt)) / UINT64_MAX;
}
    
float RandomNumber::GenerateFloat()
{
    unsigned char passed;
    uint32_t RandomInt;
    
    asm volatile ("rdrand %0\t\n"
                  "setc %1\t\n"
                  : "=r" (RandomInt), "=qm" (passed));
    if(!passed)
        std::cout << "Failed" << std::endl;
    
    return ((float)(RandomInt)) / UINT32_MAX;
}
    
uint64_t RandomNumber::GenerateInt64()
{
    unsigned char passed;
    uint64_t RandomInt;
    
    asm volatile ("rdrand %0\t\n"
                  "setc %1\t\n"
                  : "=r" (RandomInt), "=qm" (passed));
    if(!passed)
        std::cout << "Failed" << std::endl;
    
    return RandomInt;
}
    
uint32_t RandomNumber::GenerateInt32()
{
    unsigned char passed;
    uint32_t RandomInt;
    
    asm volatile ("rdrand %0\t\n"
                  "setc %1\t\n"
                  : "=r" (RandomInt), "=qm" (passed));
    if(!passed)
        std::cout << "Failed" << std::endl;
    
    return RandomInt;
}


uint16_t RandomNumber::GenerateInt16()
{
    unsigned char passed;
    uint16_t RandomInt;
    
    asm volatile ("rdrand %0\t\n"
                  "setc %1\t\n"
                  : "=r" (RandomInt), "=qm" (passed));
    if(!passed)
        std::cout << "Failed" << std::endl;
    
    return RandomInt;
}


    
#pragma mark Public Methods
// ---------------------------------------- Public Methods
    

#pragma mark Private Methods
// ---------------------------------------- Private Methods
void RandomNumber::checkHardwareAvailability()
{
    unsigned int ecx;
    unsigned int leaf = 1;
    unsigned int subleaf = 0;
    hardwareRNGPresent = true;
    
    asm volatile("cpuid"
                 : "=c" (ecx)
                 : "a" (leaf), "c" (subleaf));
    
    
    // Check for RDRAND Support
    if(ecx & 0x40000000 !=  0x40000000)
    {
        hardwareRNGPresent = false;
        return;
    }
    std::cout << "Harware Random Number Generation Supported!\n";
}




} // End fnMath namespace
