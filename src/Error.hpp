//
//  Error.hpp
//  fnMath
//
//  Created by Steven Novak on 2/1/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#ifndef Error_h
#define Error_h

#include <exception>
using namespace std;


class DimensionMismatchException: public exception
{
    virtual const char* what() const throw()
    {
        return "Dimensions Must Agree";
    }
};

class ColumnMismatchException: public exception
{
    virtual const char* what() const throw()
    {
        return "Matrix must have numer of rows >= number of columns";
    }
};

#endif /* Error_h */
