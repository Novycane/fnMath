//
//  Matrix.test.cpp
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

#include "../src/LinAlg/LU.hpp"
#include "../src/LinAlg/LU.cpp"

using namespace fnMath::LinAlg;
using namespace std;

// ------------------------- Declarations

void RunTest(bool pass, const char* testName);
MatrixD InitTestMatrix();
MatrixD InitRandom(int n);

bool Upper();
bool Lower();
bool RecreateA();
bool Determinate();
bool Solve();

// ------------------------- Main

int main (int argCount, char** args)
{
    cout << endl << " ---------------   Testing LU functions   ---------------" << endl;

	RunTest(Upper(), "Upper Triangular Matrix");
	RunTest(Lower(), "Lower Triangular Matrix");
	RunTest(RecreateA(), "A = L * U");
	RunTest(Determinate(), "LU Determinate");
	RunTest(Solve(), "LU Solve");
	
	cout << " -------------- Done Testing LU functions --------------" << endl << endl;
		
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

	A[0][0] = 1.0;
	A[1][0] = 2.0;
	A[2][0] = 0.0;
	
	A[0][1] = -2.0;
	A[1][1] = -1.0;
	A[2][1] = 2.0;
	
	A[0][2] = 3.0;
	A[1][2] = 12.0;
	A[2][2] = -10.0;

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

bool Upper()
{
	LU<double> A(InitTestMatrix());
	auto B = A.Upper();
	
	if(B[0][0] != 1)
		return false;
	if(B[1][0] != 0)
		return false;
	if(B[2][0] != 0)
		return false;
	
	if(B[0][1] != -2)
		return false;
	if(B[1][1] != 3)
		return false;
	if(B[2][1] != 0)
		return false;
	
	if(B[0][2] != 3)
		return false;
	if(B[1][2] != 6)
		return false;
	if(B[2][2] != -14)
		return false;

	return true;
}

bool Lower()
{
	LU<double> A(InitTestMatrix());
	auto B = A.Lower();
	
	if(B[0][0] != 1)
		return false;
	if(B[1][0] != 2)
		return false;
	if(B[2][0] != 0)
		return false;
	
	if(B[0][1] != 0)
		return false;
	if(B[1][1] != 1)
		return false;
	if(B[2][1] != 2.0/3.0)
		return false;
	
	if(B[0][2] != 0)
		return false;
	if(B[1][2] != 0)
		return false;
	if(B[2][2] != 1)
		return false;
	
	return true;
}

bool RecreateA()
{
	int n = 5;
	auto A = InitRandom(n);
	LU<double> lu(A);
	auto B = lu.Lower() * lu.Upper();
		
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(abs(A[i][j] - B[i][j]) > 1e-8)
				return false;
		}
	}
	
	return true;	
}

bool Determinate()
{
	int n = 3;
	auto A = InitRandom(n);
	LU<double> lu(A);
	auto det = lu.Determinate();
	double actual;
	
	actual = A[0][0] * A[1][1] * A[2][2];
	actual -= A[0][0] * A[1][2] * A[2][1];
	actual += A[0][1] * A[1][2] * A[2][0];
	
	actual -= A[0][1] * A[1][0] * A[2][2];
	actual += A[0][2] * A[1][0] * A[2][1];
	actual -= A[0][2] * A[1][1] * A[2][0];

	if(abs(det - actual) < 1e-8)
		return true;
	else
		return false;
}

bool Solve()
{
	int n = 3;
	auto A = InitRandom(n);
	MatrixD b(0,3,1);
	LU<double> lu(A);
	
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
