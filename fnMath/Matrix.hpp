//
//  Matrix.hpp
//  fnMath
//
//  Created by Steven Novak on 2/1/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//
//
//
//
//
//
//
//
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <vector>
#include "Error.hpp"

using namespace std;

namespace fnMath {
namespace LinAlg{
        

template <typename Numeric>
class Matrix
{
public:
    // -------------------- Constructors
    Matrix();
    Matrix(Numeric value, int NumberOfRows, int NumberOfColumns);
    ~Matrix();
    Matrix(const Matrix<Numeric> & rhs);
    Matrix(Matrix<Numeric> && rhs);
    
    // -------------------- Operators
    Matrix<Numeric> & operator=(const Matrix<Numeric> & rhs);
    Matrix<Numeric> & operator=(Matrix<Numeric> && rhs);
    const vector<Numeric> & operator[](int i) const;
    vector<Numeric> & operator[](int i);
    
    Matrix<Numeric> operator+(const Matrix<Numeric> & rhs);
    Matrix<Numeric> operator-(const Matrix<Numeric> & rhs);
    Matrix<Numeric> operator*(const Matrix<Numeric> & rhs);
    Matrix<Numeric> operator~();
    Matrix<Numeric> operator+(const Numeric & rhs);
    Matrix<Numeric> operator-(const Numeric & rhs);
    Matrix<Numeric> operator*(const Numeric & rhs);
    Matrix<Numeric> operator/(const Numeric & rhs);

    
    // -------------------- Methods
    int numRows() const;
    int numColumns() const;
    Numeric Max();
    Numeric Min();
    Numeric absMax();
    Numeric absMin();
    
    // -------------------- Utility
    void print();
    
protected:
    vector<vector<Numeric>> data;
    int rows, columns;
    
}; // End Matrix

        
} // End Namespace "Matrix"
} // End Namespace "fnMath"


#endif /* Matrix_hpp */
