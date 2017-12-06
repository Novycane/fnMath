//
//  Factorial.hpp
//  fnMath
//
//  Created by Steven Novak on 2/2/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#ifndef Factorial_hpp
#define Factorial_hpp

namespace fnMath{

class Factorial
{
public:
    Factorial();
    static double Compute(int n);
    static double ComputeLn(int n);

private:
    static double values[256];
    static int maxN;
    
}; // End Factorial Class

} // End fnMath namespace

#endif /* Factorial_hpp */
