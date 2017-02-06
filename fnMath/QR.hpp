//
//  QR.hpp
//  fnMath
//
//  Created by Steven Novak on 2/6/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#ifndef QR_hpp
#define QR_hpp

#include <Memory>
#include "Matrix.hpp"
#include "Matrix.cpp"

namespace fnMath{
namespace LinAlg{

template <typename Numeric>
class QR
{
public:
    // -------------------- Constructors
    QR(const Matrix<Numeric> & A);
    QR(Matrix<Numeric> && A);
    
    // -------------------- Public Methods
    void print();
    
    
private:
    // -------------------- Private Members
    std::unique_ptr<Matrix<Numeric>> Q;
    std::unique_ptr<Matrix<Numeric>> R;
    
    // -------------------- Private Methods
    void DecomposeGrahmSchmidt(const Matrix<Numeric> & A);    
    
}; // End QR Class
    
    
} // End LinAlg namespace
} // End fnMath namespace
#endif /* QR_hpp */
