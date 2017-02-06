//
//  QR.cpp
//  fnMath
//
//  Created by Steven Novak on 2/6/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//


#ifndef QR_cpp
#define QR_cpp

#include <cmath>
#include "QR.hpp"
#include "Matrix.hpp"
#include "Matrix.cpp"

namespace fnMath{
namespace LinAlg{
    
#pragma mark Constructors
// ---------------------------------------- Constructors
template <typename Numeric>
QR<Numeric>::QR(const Matrix<Numeric> & A)
{
    if(A.numRows() < A.numColumns())
        throw new ColumnMismatchException();
    
    Q.reset(new Matrix<Numeric>(0, A.numRows(), A.numColumns()));
    R.reset(new Matrix<Numeric>(0, A.numColumns(), A.numColumns()));
    DecomposeGrahmSchmidt(A);
}
    
template <typename Numeric>
QR<Numeric>::QR(Matrix<Numeric> && A)
{
    if(A.numRows() < A.numColumns())
        throw new ColumnMismatchException();
    
    Q.reset(new Matrix<Numeric>(0, A.numRows(), A.numColumns()));
    R.reset(new Matrix<Numeric>(0, A.numColumns(), A.numColumns()));
    DecomposeGrahmSchmidt(A);
}

    
#pragma mark Public Methods
// ---------------------------------------- Public Methods
    
template <typename Numeric>
void QR<Numeric>::print()
{
    cout << "--------Q\n";
    for(int i=0; i<Q->numRows(); i++)
    {
        for(int j=0; j<Q->numColumns(); j++)
            cout << (*Q)[i][j] << "\t";
        cout << "\n";
    }
    cout << "--------R\n";
    for(int i=0; i<R->numRows(); i++)
    {
        for(int j=0; j<R->numColumns(); j++)
            cout << (*R)[i][j] << "\t";
        cout << "\n";

    }
    cout << "--------Q * R\n";
    ((*Q) * (*R)).print();
}

    
#pragma mark Private Methods
// ---------------------------------------- Private Methods
template <typename Numeric>
void QR<Numeric>::DecomposeGrahmSchmidt(const Matrix<Numeric> & A)
{

    Numeric sum, norm;
    int rows = Q->numRows();
    int columns = Q->numColumns();
    
    for(int i=0; i<rows; i++)   // Normalize
    {
        for(int j=0; j<columns; j++)    // Initialaize ever other value of Q to A
            (*Q)[i][j] = A[i][j];
    }
    
    for(int j=0; j<columns; j++)
    {
        for(int k=j; k >0; k--)
        {
            sum = 0;

            for(int i=0; i<rows; i++)
                sum += (*Q)[i][k-1] * A[i][j]; // project V onto U

            (*R)[k-1][j] = sum;
            for(int i=0; i<rows; i++)
                (*Q)[i][j] -= sum * (*Q)[i][k-1]; // Subtract
        }
        norm = 0;
        for(int i=0; i<rows; i++)
            norm += (*Q)[i][j] * (*Q)[i][j];
        norm = sqrt(norm);
        
        (*R)[j][j] = norm;
        
        for(int i=0; i<rows; i++)
            (*Q)[i][j] /= norm;
    }
}

    
} // End LinAlg namespace
} // End fnMath namespace

#endif /* QR_cpp */

