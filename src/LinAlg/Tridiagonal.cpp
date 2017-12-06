//
//  Tridiagonal.cpp
//  fnMath
//
//  Created by Steven Novak on 2/1/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#ifndef Tridiagonal_CPP
#define Tridiagonal_CPP

#include "Tridiagonal.hpp"
#include <iostream>

namespace fnMath{
namespace LinAlg{
        
// ------------------------- Type Definitions
typedef Tridiagonal<double> TridiagonalD;
typedef Tridiagonal<float> TridiagonalF;
typedef Tridiagonal<int> TridiagonalI;


#pragma mark Constructors
// ---------------------------------------- Constructors

template <typename Numeric>
Tridiagonal<Numeric>::Tridiagonal()
{
    rows = 0;
    columns = 3;
}
    
template <typename Numeric>
Tridiagonal<Numeric>::Tridiagonal(Numeric Value, int Rows)
{
    rows = Rows;
    columns = 3;
    
    
    data.resize(rows);
    for(int i=0; i<rows; i++)
    {
        data[i].resize(3);
        for(int j=0; j<3; j++)
            data[i][j] = Value;
    }

}


template <typename Numeric>
Tridiagonal<Numeric>::Tridiagonal(const Tridiagonal<Numeric> & rhs)
{
    
    rows = rhs.rows;
    columns = rhs.columns;
    
    
    data.resize(rows);
    for(int i=0; i<rows; i++)
    {
        data[i].resize(3);
        for(int j=0; j<columns; j++)
            data[i][j] = rhs[i][j];
    }
}

template <typename Numeric>
Tridiagonal<Numeric>::Tridiagonal(Tridiagonal<Numeric> && rhs)
{
    
    rows = rhs.rows;
    columns = rhs.columns;
    data = std::move(rhs.data);
}


#pragma mark Operators
// ---------------------------------------- Operators

template <typename Numeric>
Tridiagonal<Numeric> & Tridiagonal<Numeric>::operator=(const Tridiagonal<Numeric> & rhs)
{
    rows = rhs.rows;
    columns = rhs.columns;
    data = rhs.data;
    
    return *this;
}

template <typename Numeric>
Tridiagonal<Numeric> & Tridiagonal<Numeric>::operator=(Tridiagonal<Numeric> && rhs)
{
    rows = rhs.rows;
    columns = rhs.columns;
    
    data = std::move(rhs.data);
    
    return *this;
}

template<typename Numeric>
const vector<Numeric>& Tridiagonal<Numeric>::operator[](int i) const
{
    return data[i];
}

template<typename Numeric>
vector<Numeric>& Tridiagonal<Numeric>::operator[](int i)
{
    return data[i];
}


#pragma mark Public Methods
// ---------------------------------------- Public Methods
template <typename Numeric>
void Tridiagonal<Numeric>::SetupMatrix(int Rows, Numeric Diagonal, Numeric Super, Numeric Sub)
{
    rows = Rows;
    columns = 3;
    data.resize(Rows);
    data[0].resize(3);
    data[0][0] = 0;
    data[0][1] = Diagonal;
    data[0][2] = Super;
    
    for(int i=1; i<rows-1; i++)
    {
        data[i].resize(3);
        data[i][0] = Sub;
        data[i][1] = Diagonal;
        data[i][2] = Super;
    }
    data[rows-1].resize(3);
    data[rows-1][0] = Sub;
    data[rows-1][1] = Diagonal;
    data[rows-1][2] = 0;
    
    return;
}
    
template <typename Numeric>
vector<Numeric> Tridiagonal<Numeric>::Solve(vector<Numeric> b)
{
    if(b.size() != rows)
        throw new DimensionMismatchException();
    
    vector<Numeric> x;
    vector<Numeric> v;
    Numeric w = data[0][1];

    x.resize(rows);
    v.resize(rows);
    
    // Begin Routine
    x[0] = b[0] / w;
    
    for(int i=1; i < rows; i++)
    {
        v[i] = data[i - 1][2] / w;
        w = data[i][1] - (data[i][0] * v[i]);
        x[i] = (b[i] - (data[i][0] * x[i - 1])) / w;
    }
    
    for(int i = rows - 2; i >= 0; i--)
    {
        x[i] = x[i] - v[i+1] * x[i+1];
    }
    
    return x;
}
    
template <typename Numeric>
int Tridiagonal<Numeric>::numRows() const { return rows; }

template <typename Numeric>
int Tridiagonal<Numeric>::numColumns() const { return columns; }



#pragma mark Utility Functions
// ---------------------------------------- Utility Functions

template<typename Numeric>
void Tridiagonal<Numeric>::print()
{
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < columns; j++)
            cout << data[i][j] << "\t\t";
        cout << endl;
    }
    cout << endl;
}
        
    
} // End Namespace "Tridiagonal"
} // End Namespace "fnMath"

#endif
