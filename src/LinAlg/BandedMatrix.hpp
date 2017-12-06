//
//  BandedMatrix.hpp
//  fnMath
//
//  Created by Steven Novak on 2/23/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#ifndef BandedMatrix_hpp
#define BandedMatrix_hpp

#include <vector>

using namespace std;

namespace fnMath {
namespace LinAlg {

#pragma GCC visibility push(default)
    
template <typename Numeric>
class BandedMatrix
{
public:
    // -------------------- Constructors
    BandedMatrix();
    BandedMatrix(int Rows, int Bandwidth);
    
    BandedMatrix(const BandedMatrix<Numeric> & rhs);
    BandedMatrix(BandedMatrix<Numeric> && rhs);
    
    // -------------------- Operators
    BandedMatrix<Numeric> & operator=(const BandedMatrix<Numeric> & rhs);
    BandedMatrix<Numeric> & operator=(BandedMatrix<Numeric> && rhs);
    vector<Numeric> operator*(const vector<Numeric> & rhs);
    const vector<Numeric> & operator[](int i) const;
    vector<Numeric> & operator[](int i);
    
    // -------------------- Public Methods
    void SetupMatrix(Numeric Diagonal, Numeric OffDiag, Numeric Band);
    vector<Numeric> SolveCG(vector<Numeric> & b);
    
    // -------------------- Utility
    void Print();
    void PrintCompact();
    void PrintUltraCompact();
    
private:
    // -------------------- Private Members
    vector<vector<Numeric>> data;
    int rows;
    int bandwidth;
    
    // -------------------- Private Methods
    
    
}; // end BandedMatrix class

#pragma GCC visibility pop

} // end LinAlg namespace
} // end fnMath namespace



#endif /* BandedMatrix_hpp */
