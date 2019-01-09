//
//  Cholesky.test.cpp
//  
//
//  Created by Steven Novak on 12/5/17.
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

#include "../src/LinAlg/Cholesky.hpp"
#include "../src/LinAlg/Cholesky.cpp"

using namespace fnMath::LinAlg;
using namespace std;

// ------------------------- Declarations

void RunTest(bool pass, const char* testName);
MatrixD InitTestMatrix();
MatrixD InitRandom(int n);

bool Lower();
bool Upper();
bool RecreateA();
bool Solve();

// ------------------------- Main

int main (int argCount, char** args)
{
    cout << endl << " ---------------   Testing Cholesky functions   ---------------" << endl;

	RunTest(Lower(), "Lower Cholesky Matrix");
	RunTest(Upper(), "Upper Cholesky Matrix");
	RunTest(RecreateA(), "Cholesky A = L * U");
	//RunTest(Solve(), "LU Solve");
	
	cout << " -------------- Done Testing Cholesky functions --------------" << endl << endl;
		
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

bool Lower()
{
	auto M = InitTestMatrix();
	Cholesky<double> A(M);
	auto B = A.Lower();
	
	if(B[0][0] != 2)
		return false;
	if(B[1][0] != 6)
		return false;
	if(B[2][0] != -8)
		return false;
	
	if(B[0][1] != 0)
		return false;
	if(B[1][1] != 1)
		return false;
	if(B[2][1] != 5.0)
		return false;
	
	if(B[0][2] != 0)
		return false;
	if(B[1][2] != 0)
		return false;
	if(B[2][2] != 3)
		return false;
	
	return true;
}

bool Upper()
{
	auto M = InitTestMatrix();
	Cholesky<double> A(M);
	auto B = A.Upper();
	
	if(B[0][0] != 2)
		return false;
	if(B[1][0] != 0)
		return false;
	if(B[2][0] != 0)
		return false;
	
	if(B[0][1] != 6)
		return false;
	if(B[1][1] != 1)
		return false;
	if(B[2][1] != 0)
		return false;
	
	if(B[0][2] != -8)
		return false;
	if(B[1][2] != 5)
		return false;
	if(B[2][2] != 3)
		return false;
	
	return true;
}


bool RecreateA()
{
	auto A = InitTestMatrix();
	Cholesky<double> ch(A);
	auto B = ch.Lower() * ch.Upper();
	
	for(int i=0; i<A.numRows(); i++)
	{
		for(int j=0; j<A.numColumns(); j++)
		{
			if(abs(A[i][j] - B[i][j]) > 1e-8)
				return false;
		}
	}
	
	return true;	
}

bool Solve()
{
	int n = 3;
	auto A = InitRandom(n);
	MatrixD b(0,3,1);
	Cholesky<double> lu(A);
	
	b[0][0] = rand();
	b[1][0] = rand();
	b[2][0] = rand();
	
	auto y = A * b;
	auto c = lu.Solve(y);

	for(int i=0; i<n; i++)
		if(abs(c[i][0] - b[i][0]) > 1e-8)
			return false;
	return true;
}
