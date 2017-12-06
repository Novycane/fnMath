//
//  BandedMatrix.cpp
//  fnMath
//
//  Created by Steven Novak on 2/23/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#include "BandedMatrix.hpp"
#include "Error.hpp"
#include <iostream>

namespace fnMath{
namespace LinAlg{
        

#pragma mark Constructors
// ---------------------------------------- Constructors

template <typename Numeric>
BandedMatrix<Numeric>::BandedMatrix()
{

}
    
template <typename Numeric>
BandedMatrix<Numeric>::BandedMatrix(int Rows, int Bandwidth)
{
    bandwidth = Bandwidth;
    rows = Rows;
    
    data.resize(rows);
    for(int i=0; i<rows; i++)
        data[i].resize(3);
}
    
template <typename Numeric>
BandedMatrix<Numeric>::BandedMatrix(const BandedMatrix<Numeric> & rhs)
{
    bandwidth = rhs.bandwidth;
    rows = rhs.rows;
    data = std::copy(rhs.data);
}
    
template <typename Numeric>
BandedMatrix<Numeric>::BandedMatrix(BandedMatrix<Numeric> && rhs)
{
    bandwidth = rhs.bandwidth;
    rows = rhs.rows;
    data = std::move(rhs.data);
}

#pragma mark Operators
// ---------------------------------------- Operators
    
template <typename Numeric>
vector<Numeric> BandedMatrix<Numeric>::operator*(const vector<Numeric> & rhs)
{
    double r, d;
    vector<Numeric> out;
    out.resize(rhs.size());
    // Cover the diagonal
    for(int i=0; i<rows; i++)
        out[i] = data[i][0] * rhs[i];
    
    // Super and Sub Diagoanal
    for(int i=1; i<rows; i++)
    {
        out[i - 1] += rhs[i] * data[i-1][1];
        out[i] += rhs[i - 1] * data[i-1][1];
    }
    
    // Bands
    for(int i=0; i<rows - bandwidth; i++)
    {
        r = rhs[i + bandwidth];
        d = data[i][2];
        out[i] += rhs[i + bandwidth] * data[i][2];
        
        r = rhs[i];
        d = data[i][2];
        out[i + bandwidth] += rhs[i] * data[i][2];
    }

    
    
    return out;
}
    
template <typename Numeric>
BandedMatrix<Numeric> & BandedMatrix<Numeric>::operator=(const BandedMatrix<Numeric> & rhs)
{
    bandwidth = rhs.bandwidth;
    rows = rhs.rows;
    data = rhs.data;
    
    return *this;
}
    
template <typename Numeric>
BandedMatrix<Numeric> & BandedMatrix<Numeric>::operator=(BandedMatrix<Numeric> && rhs)
{
    bandwidth = rhs.bandwidth;
    rows = rhs.rows;
    data = std::move(rhs.data);
    
    return *this;
}
    
template <typename Numeric>
const vector<Numeric> & BandedMatrix<Numeric>::operator[](int i) const
{
    return data[i];
}

template <typename Numeric>
    vector<Numeric> & BandedMatrix<Numeric>::operator[](int i)
{
    return data[i];
}
    
#pragma mark Public Methods
// ---------------------------------------- Public Methods
    
template <typename Numeric>
vector<Numeric> BandedMatrix<Numeric>::SolveCG(vector<Numeric> & b)
{
    int maxIterations = 100;
    auto n = b.size();
    Numeric alpha, beta, num, denom, err = 1000;
    vector<Numeric> r, d, q;
    vector<Numeric> out, out2;
    out.resize(n);
    out2.resize(n);
    
    for(int i=0; i<n; i++)
        out[i] = 1;
    
    r = (*this) * out;
    
    for(int i=0; i<n; i++)
        r[i] = b[i] - r[i];
    d = r;
    
    for(int i=0; i<maxIterations; i++)
    {
        num = 0.0;
        denom = 0.0;
        q = (*this) * d;
        
        for(int j=0; j<n; j++)
        {
            num = num + r[j] * r[j];
            denom = denom + d[j] * q[j];
        }
        alpha = num / denom;
        
        denom = 0;
        err = 0;
        for(int j=0; j<n; j++)
        {
            out2[j] = out[j] + alpha * d[j];
            if(abs(out2[j] - out[j]) > err)
               err  = abs(out2[j] - out[j]);
            r[j] = r[j] - alpha * q[j];
            denom = denom + r[j] * r[j];       // Numerator is r[j] * r[j]... denom is r[j+1] * r[j+1]
        }
        std::swap(out2, out);
        
        if(err < 1e-4)
        {
            cout << "Converged! " << err << " " << i << "\n";
            return out;
        }
        
        beta = denom / num;
        
        for(int j=0; j<n; j++)
            d[j] = r[j] + beta * d[j];
    }
    cout << "no convergy.... :( " << err << "\n";
    return out;
}
    
#pragma mark Public Methods
// ---------------------------------------- Public Methods

template <typename Numeric>
void BandedMatrix<Numeric>::SetupMatrix(Numeric Diagonal, Numeric OffDiag, Numeric Band)
{
    for(int i=0; i<rows;  i++)
    {
        data[i][0] = Diagonal;
        if((i + 1) % bandwidth)
            data[i][1] = OffDiag;
        if(i + bandwidth < rows)
            data[i][2] = Band;
    }
}

#pragma mark Utility
// ---------------------------------------- Utility
    
template <typename Numeric>
void BandedMatrix<Numeric>::Print()
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<rows; j++)
        {
            if(i == j)
                cout << data[i][0] << "\t\t";
            else if ( (j % bandwidth && j == i+1) || ((j-1) % bandwidth && j == i-1))
                cout << data[i][1] << "\t\t";
            else if (j + 1 == i + bandwidth && (i + bandwidth) <= rows)
                cout << data[i][2] << "\t\t";
            else
                cout << "0" << "\t\t";
                
        }
        cout << endl;
    }
    cout << endl;
}
    
template <typename Numeric>
void BandedMatrix<Numeric>::PrintCompact()
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<3; j++)
            cout << data[i][j] << "\t\t";
        cout << endl;
    }
    cout << endl;
}
    
    
template <typename Numeric>
void BandedMatrix<Numeric>::PrintUltraCompact()
{
    for(int i=0; i<3; i++)
        cout << data[0][i] << "\t\t";
    cout << "\n\n";
}
    
#pragma mark Private Methods
// ---------------------------------------- Private Methods


} // End namespace LinAlg
} // End namespace fnMath
