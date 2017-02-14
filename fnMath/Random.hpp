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

namespace fnMath{
    
class RandomNumber
{
public:
    RandomNumber();
    
    double GenerateDouble();
    float GenerateFloat();
    uint64_t GenerateInt64();
    uint32_t GenerateInt32();
    uint16_t GenerateInt16();
    
private:
    bool hardwareRNGPresent;
    
    void checkHardwareAvailability();
    
}; // End Random

}

#endif /* Random_hpp */
