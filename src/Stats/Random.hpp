//
//  Random.hpp
//  fnMath
//
//  Created by Steven Novak on 2/7/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#ifndef Random_hpp
#define Random_hpp

#include <stdint.h>
#include <time.h>

namespace fnMath{
    
class RandomNumber
{
public:
    // -------------------- Constructors
    RandomNumber();
    
    // -------------------- Public Methods
    // Normal Deviates
    double GenerateNormal();
    void GenerateNormals(double & z0, double & z1);
    void GenerateNormals(double mean, double stdev, double & z0, double & z1);
    double GenerateGaussian(double Mean, double StDev);
    
    // Exponential Deviates
    double GenerateExponential(double lambda);
    
    // Extreme Value
    double GenerateExtremeValue(double a, double b);

    // Geometric
    double GenerateGeometric(double p);
    
    // Logistic
    double GenerateLogistic(double mu, double b);
        
    // Weibull
    double GenerateWeibull(double alpha, double beta);
    
    // Uniform Deviates
    double GenerateDouble();
    float GenerateFloat();
    uint64_t GenerateInt64();
    uint64_t GenerateInt64(uint64_t lower, uint64_t upper);
    uint32_t GenerateInt32();
    uint32_t GenerateInt32(uint32_t lower, uint32_t upper);
    uint16_t GenerateInt16();
    uint16_t GenerateInt16(uint16_t lower, uint16_t upper);
    
    // Utility Functions
    void SetSeed(uint64_t NewSeed);
    void SeedOffClock();
    void ForcePseudoRand();
    void ForceHardwareRand();
    
    // -------------------- Accessors
    
private:
    // -------------------- Private Members
    const int shift1 = 11;
    const int shift2 = 29;
    const int shift3 = 14;
    uint64_t Seed;
    uint64_t RandNum;
    bool hardwareRNGPresent;
    void (RandomNumber::*RandomNumberGenerator)(uint64_t *number);
    void (RandomNumber::*NormalDeviates)(double & z0, double & z1);
    
    // -------------------- Private Methods
    void CheckHardwareAvailability();
    void GetHardware64(uint64_t *number);
    void GetPseudo64(uint64_t *number);
    void GeneratePolarPair(double & z0, double & z1);

    
    
}; // End Random

}

#endif /* Random_hpp */
