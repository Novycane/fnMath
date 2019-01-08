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

bool Upper();
bool Lower();

// ------------------------- Main

int main (int argCount, char** args)
{
    cout << endl << " ---------------   Testing LU functions   ---------------" << endl;

	RunTest(Upper(), "Upper Triangular Matrix");
	RunTest(Lower(), "Lower Triangular Matrix");
	
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
	
	if(B[0][0] != -2)
		return false;
	if(B[1][0] != -1)
		return false;
	if(B[2][0] != 0)
		return false;
	
	if(B[0][0] != 3)
		return false;
	if(B[1][0] != 6)
		return false;
	if(B[2][0] != 2)
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
	
	if(B[0][0] != 0)
		return false;
	if(B[1][0] != 1)
		return false;
	if(B[2][0] != -2)
		return false;
	
	if(B[0][0] != 0)
		return false;
	if(B[1][0] != 0)
		return false;
	if(B[2][0] != 1)
		return false;
	
	return true;
}