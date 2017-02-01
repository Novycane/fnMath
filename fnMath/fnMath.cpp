/*
 *  fnMath.cpp
 *  fnMath
 *
 *  Created by Steven Novak on 2/1/17.
 *  Copyright © 2017 Steven Novak. All rights reserved.
 *
 */

#include <iostream>
#include "fnMath.hpp"
#include "fnMathPriv.hpp"

void fnMath::HelloWorld(const char * s)
{
    fnMathPriv *theObj = new fnMathPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void fnMathPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

