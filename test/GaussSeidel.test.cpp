//
//  GaussSeidel.test.cpp
//  
//
//  Created by Steven Novak on 12/16/17.
//
// --------------------------------------------------
//
//
//
//
// --------------------------------------------------

#include <iostream>
#include "../src/LinAlg/Matrix.hpp"
#include "../src/LinAlg/Matrix.cpp"

#include "../src/LinAlg/GaussSeidel.hpp"

using namespace fnMath::LinAlg;
using namespace std;

// ------------------------- Declarations

void RunTest(bool pass, const char* testName);
MatrixD InitTestMatrix();
MatrixD InitRandom(int n);


// ------------------------- Main

int main (int argCount, char** args)
{
    cout << endl << " ---------------   Testing Gauss-Seidel functions   ---------------" << endl;

	
	cout << " -------------- Done Testing Gauss-Seidel functions --------------" << endl << endl;
		
    return 0;
}

// ------------------------- Utility

void RunTest(bool pass, const char* testName)
{
	cout << testName << " Test" ;
	if(pass)
		cout << "...Ok" << endl;
	else
		cout << "...Failed!" << endl;
}

MatrixD InitTestMatrix()
{
	MatrixD A(0,3,3);

	A[0][0] = 4.0;
	A[1][0] = 12.0;
	A[2][0] = -16.0;
	
	A[0][1] = 12.0;
	A[1][1] = 37.0;
	A[2][1] = -43.0;
	
	A[0][2] = -16.0;
	A[1][2] = -43.0;
	A[2][2] = 98.0;

	return A;
}

MatrixD InitRandom(int n)
{
	MatrixD A(0,n,n);
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			A[i][j] = rand();
	
	return A;
}

// ------------------------- Tests