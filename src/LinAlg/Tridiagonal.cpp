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
    _rows = 0;
    _columns = 3;
}
    
template <typename Numeric>
Tridiagonal<Numeric>::Tridiagonal(Numeric Value, int Rows)
{
    _rows = Rows;
    _columns = 3;
        
    _data.resize(_rows);
    for(int i=0; i<_rows; i++)
    {
        _data[i].resize(3);
        for(int j=0; j<3; j++)
            _data[i][j] = Value;
    }
	
	_data[0][0] = 0.0;
	_data[Rows-1][2] = 0.0;

}

template <typename Numeric>
Tridiagonal<Numeric>::Tridiagonal(int Rows, Numeric Diagonal, Numeric Super, Numeric Sub)
{
	SetupMatrix(Rows, Diagonal, Super, Sub);
}

template <typename Numeric>
Tridiagonal<Numeric>::Tridiagonal(const Tridiagonal<Numeric> & rhs)
{
    
    _rows = rhs.rows;
    _columns = rhs.columns;
    
    
    _data.resize(_rows);
    for(int i=0; i<_rows; i++)
    {
        _data[i].resize(3);
        for(int j=0; j<_columns; j++)
            _data[i][j] = rhs[i][j];
    }
}

template <typename Numeric>
Tridiagonal<Numeric>::Tridiagonal(Tridiagonal<Numeric> && rhs)
{
    
    _rows = rhs.rows;
    _columns = rhs.columns;
    _data = std::move(rhs.data);
}


#pragma mark Operators
// ---------------------------------------- Operators

template <typename Numeric>
Tridiagonal<Numeric> & Tridiagonal<Numeric>::operator=(const Tridiagonal<Numeric> & rhs)
{
    _rows = rhs.rows;
    _columns = rhs.columns;
    _data = rhs.data;
    
    return *this;
}

template <typename Numeric>
Tridiagonal<Numeric> & Tridiagonal<Numeric>::operator=(Tridiagonal<Numeric> && rhs)
{
    _rows = rhs.rows;
    _columns = rhs.columns;
    
    _data = std::move(rhs.data);
    
    return *this;
}

template<typename Numeric>
const vector<Numeric>& Tridiagonal<Numeric>::operator[](int i) const
{
    return _data[i];
}

template<typename Numeric>
vector<Numeric>& Tridiagonal<Numeric>::operator[](int i)
{
    return _data[i];
}

/*
template<typename Numeric>
Tridiagonal<Numeric> Tridiagonal<Numeric>::operator+(const Tridiagonal<Numeric> & rhs)
{
	for(int i=0; i< 
}

template<typename Numeric>
Tridiagonal<Numeric> Tridiagonal<Numeric>::operator-(const Tridiagonal<Numeric> & rhs)
{
	
}
*/

#pragma mark Public Methods
// ---------------------------------------- Public Methods
template <typename Numeric>
void Tridiagonal<Numeric>::SetupMatrix(int Rows, Numeric Diagonal, Numeric Super, Numeric Sub)
{
    _rows = Rows;
    _columns = 3;
    _data.resize(Rows);
    _data[0].resize(3);
    _data[0][0] = 0;
    _data[0][1] = Diagonal;
    _data[0][2] = Super;
    
    for(int i=1; i<_rows-1; i++)
    {
        _data[i].resize(3);
        _data[i][0] = Sub;
        _data[i][1] = Diagonal;
        _data[i][2] = Super;
    }
    _data[_rows-1].resize(3);
    _data[_rows-1][0] = Sub;
    _data[_rows-1][1] = Diagonal;
    _data[_rows-1][2] = 0;
    
    return;
}
    
template <typename Numeric>
vector<Numeric> Tridiagonal<Numeric>::Solve(vector<Numeric> b)
{
    if(b.size() != _rows)
        throw new DimensionMismatchException();
    
    vector<Numeric> x;
    vector<Numeric> v;
    Numeric w = _data[0][1];

    x.resize(_rows);
    v.resize(_rows);
    
    // Begin Routine
    x[0] = b[0] / w;
    
    for(int i=1; i < _rows; i++)
    {
        v[i] = _data[i - 1][2] / w;
        w = _data[i][1] - (_data[i][0] * v[i]);
        x[i] = (b[i] - (_data[i][0] * x[i - 1])) / w;
    }
    
    for(int i = _rows - 2; i >= 0; i--)
    {
        x[i] = x[i] - v[i+1] * x[i+1];
    }
    
    return x;
}
    
template <typename Numeric>
int Tridiagonal<Numeric>::NumRows() const { return _rows; }

template <typename Numeric>
int Tridiagonal<Numeric>::NumColumns() const { return _columns; }



#pragma mark Utility Functions
// ---------------------------------------- Utility Functions

template<typename Numeric>
void Tridiagonal<Numeric>::Print()
{
    for(int i=0; i < _rows; i++)
    {
        for(int j=0; j < _rows; j++)
			if( j - i > -2 && j - i < 2)
				cout << _data[i][j - i+1] << "\t\t";
			else
				cout << "0.0\t\t";
        cout << endl;
    }
    cout << endl;
}


template<typename Numeric>
void Tridiagonal<Numeric>::PrintCompact()
{
    for(int i=0; i < _rows; i++)
    {
        for(int j=0; j < _columns; j++)
            cout << _data[i][j] << "\t\t";
        cout << endl;
    }
    cout << endl;
}
        
    
} // End Namespace "Tridiagonal"
} // End Namespace "fnMath"

#endif
