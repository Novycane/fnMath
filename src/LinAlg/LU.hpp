//
//  LU.hpp
//  fnMath
//
//  Created by Steven Novak on 2/1/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#ifndef LU_hpp
#define LU_hpp

#include "Matrix.hpp"
#include "Matrix.cpp"

namespace fnMath {
namespace LinAlg {



template <typename Numeric>
class LU : public Matrix<Numeric>
{
public:
    // -------------------- Constructors
    LU(const Matrix<Numeric>& A);
    ~LU();
    
    // -------------------- Methods
    Matrix<Numeric> Upper();
    Matrix<Numeric> Lower();
    Matrix<Numeric> Inverse();
    Numeric Determinate();
    Matrix<Numeric> Solve(const Matrix<Numeric>& b);

private:
    // -------------------- Methods
    void Decompose(const Matrix<Numeric>& A);
    Matrix<Numeric> BackwardSub(const Matrix<Numeric> & b);
    Matrix<Numeric> ForwardSub(const Matrix<Numeric> & b);
    
}; // End LU Class

} // End LU Namespace
} // End fnMath Namespace
#endif /* LU_hpp */
