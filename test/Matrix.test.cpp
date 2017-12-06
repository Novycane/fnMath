//
//  Matrix.test.cpp
//  
//
//  Created by Steven Novak on 12/5/17.
//
// --------------------------------------------------
//
//
//
//
// --------------------------------------------------

#include <iostream>
#include "Matrix.hpp"
#include "Matrix.cpp"

using namespace fnMath::LinAlg;

int main (int argCount, char** args)
{
    
    Matrix<double> aMatrix(1,2,2);
    
    aMatrix.print();
    
    std::cout << "Hello world Yo\n" << std::endl;
    
    return 1;
}
