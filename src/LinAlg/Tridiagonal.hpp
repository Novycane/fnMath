//
//  Tridiagonal.hpp
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

#ifndef Tridiagonal_hpp
#define Tridiagonal_hpp

#include <vector>
#include "../Error.hpp"

using namespace std;

namespace fnMath {
namespace LinAlg{
    
template <typename Numeric>
class Tridiagonal
{
public:
    // -------------------- Constructors
    Tridiagonal();
    Tridiagonal(Numeric Value, int Rows);
    Tridiagonal(const Tridiagonal<Numeric> & rhs);
    Tridiagonal(Tridiagonal<Numeric> && rhs);
    
    // -------------------- Operators
    Tridiagonal<Numeric> & operator=(const Tridiagonal<Numeric> & rhs);
    Tridiagonal<Numeric> & operator=(Tridiagonal<Numeric> && rhs);
    const vector<Numeric> & operator[](int i) const;
    vector<Numeric> & operator[](int i);
    
	/*
    Tridiagonal<Numeric> operator+(const Tridiagonal<Numeric> & rhs);
    Tridiagonal<Numeric> operator-(const Tridiagonal<Numeric> & rhs);
	Tridiagonal<Numeric> operator*(const Tridiagonal<Numeric> & rhs);
    Tridiagonal<Numeric> operator~();
    Tridiagonal<Numeric> operator+(const Numeric & rhs);
    Tridiagonal<Numeric> operator-(const Numeric & rhs);
    Tridiagonal<Numeric> operator*(const Numeric & rhs);
    Tridiagonal<Numeric> operator/(const Numeric & rhs);
    */
    
    // -------------------- Methods
    void SetupMatrix(int Rows, Numeric Diagonal, Numeric Super, Numeric Sub);
    vector<Numeric> Solve(vector<Numeric> b);
    int numRows() const;
    int numColumns() const;
    
    // -------------------- Utility
    void print();
    
protected:
    vector<vector<Numeric>> data;
    int rows, columns;
    
}; // End Tridiagonal
    
        
} // End Namespace "Tridiagonal"
} // End Namespace "fnMath"


#endif /* Tridiagonal_hpp */
