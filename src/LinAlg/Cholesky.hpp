//
//  Cholesky.hpp
//  fnMath
//
//  Created by Steven Novak on 1/8/19.
//  Copyright © 2019 Steven Novak. All rights reserved.
//

#ifndef CHOLESKY_hpp
#define CHOLESKY_hpp

#include "Matrix.hpp"
#include "Matrix.cpp"

namespace fnMath {
namespace LinAlg {


template <typename Numeric>
class Cholesky : public Matrix<Numeric>
{
public:
    // -------------------- Constructors
    Cholesky(const Matrix<Numeric>& A);
    ~Cholesky();
    
    // -------------------- Methods
    Matrix<Numeric> Lower();
	Matrix<Numeric> Upper();
    Matrix<Numeric> Solve(const Matrix<Numeric>& b);

private:
    // -------------------- Methods
    void Decompose(const Matrix<Numeric>& A);
    
}; // End Cholesky Class

} // End LinAlg Namespace
} // End fnMath Namespace
#endif /* CHOLESKY_hpp_hpp */