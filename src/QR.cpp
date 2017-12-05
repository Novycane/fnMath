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
    DecomposeGrahmSchmidt(A);
    //DecomposeHouseholder(A);
}
    
template <typename Numeric>
QR<Numeric>::QR(Matrix<Numeric> && A)
{
    if(A.numRows() < A.numColumns())
        throw new ColumnMismatchException();

    DecomposeHouseholder(A);
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
    
template <typename Numeric>
Matrix<Numeric> QR<Numeric>::GetR()
{
    return *R;
}

template <typename Numeric>
Matrix<Numeric> QR<Numeric>::GetQ()
{
    return *Q;
}

    
#pragma mark Private Methods
// ---------------------------------------- Private Methods
template <typename Numeric>
void QR<Numeric>::DecomposeGrahmSchmidt(const Matrix<Numeric> & A)
{
    Q.reset(new Matrix<Numeric>(0, A.numRows(), A.numColumns()));
    R.reset(new Matrix<Numeric>(0, A.numColumns(), A.numColumns()));

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

template <typename Numeric>
void QR<Numeric>::DecomposeHouseholder(const Matrix<Numeric> & A)
{
    Matrix<Numeric> w(0,A.numRows(),1);
    Matrix<Numeric> v(0,A.numRows(),1);
    Q.reset(new Matrix<Numeric>(0, A.numRows(), A.numRows()));
    R.reset(new Matrix<Numeric>(A));
    Q->I();
    
    Numeric norm, val, sum;
    int rows = A.numRows();
    int columns = A.numColumns();
    
    for(int j=0; j<columns; j++)
    {
        norm = 0;
        for(int i=j; i<rows; i++)       // Find Vector Length
            norm = norm + (*R)[i][j] * (*R)[i][j];
        norm = sqrt(norm);
        
        if((*R)[j][j] < 0)
            norm = norm * -1;
        
        (*R)[j][j] = (*R)[j][j] - norm;
        
        val = sqrt(norm * (norm + ((*R)[j][j] < 0 ? (*R)[j][j] * -1 : (*R)[j][j])));
        
        for(int i=j; i<rows; i++)
            (*R)[i][j] = (*R)[i][j] / val;
        
        for(int i=j+1; i<columns; i++)
        {
            norm = 0;
            for(int k=j; j<rows; k++)
                norm = norm + (*R)[k][j] * (*R)[k][i];
            for(int k=j; k<rows; k++)
                (*R)[k][i] = (*R)[k][i] - (*R)[k][j] * norm;
        }
    }
    
    for(int j=0; j<columns; j++)
    {
        norm = 0;
        //for(int i=j; i<rows; i++)
            
    }
    
}

    
} // End LinAlg namespace
} // End fnMath namespace

#endif /* QR_cpp */

