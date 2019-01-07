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

using namespace fnMath::LinAlg;
using namespace std;

// ------------------------- Declarations

void RunTest(bool pass, const char* testName);
MatrixD InitSequential(int n);

bool MTranspose();

bool MMAddition();
bool MMSubtraction();
bool MMMultiplication();

bool MCAddition();
bool MCSubtraction();
bool MCMultiplication();
bool MCDivision();


// ------------------------- Main

int main (int argCount, char** args)
{
    cout << endl << " --------------- Testing Matrix functions ---------------" << endl;
	RunTest(MTranspose(), "Maxtrix Transpose");
	RunTest(MMAddition(), "Maxtrix-Matrix Addition");
	RunTest(MMSubtraction(), "Maxtrix-Matrix Subtraction");
	RunTest(MMMultiplication(), "Maxtrix-Matrix Multiplication");
	
    RunTest(MCAddition(), "Maxtrix-Constant Addition");
	RunTest(MCSubtraction(), "Maxtrix-Constant Subtraction");
	RunTest(MCMultiplication(), "Maxtrix-Constant Multiplication");
	RunTest(MCDivision(), "Maxtrix-Constant Division");
	
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

MatrixD InitSequential(int n)
{
	MatrixD A(0,n,n);
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			A[i][j] = i * n + j;
	
	return A;
}

// ------------------------- Tests

bool MTranspose()
{
	const int n = 6;
	bool pass = true;
	
	MatrixD A = InitSequential(n);
	MatrixD B = ~A;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(A[i][j] != B[j][i])
				pass = true;
	
	return pass;
}

bool MMAddition()
{
	const int n = 2;
	bool pass = true;
	
	MatrixD A = InitSequential(n);
	MatrixD B = A + A;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(B[i][j] != A[i][j] + A[i][j])
				pass = false;
	
	return pass;
}

bool MMSubtraction()
{
	const int n = 2;
	bool pass = true;
	
	MatrixD A = InitSequential(n);
	MatrixD B = A - A;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(abs(B[i][j]) > 0.00001)
				pass = false;
	
	return pass;
}

bool MMMultiplication()
{
	const int n = 2;
	bool pass = true;
	
	MatrixD A = InitSequential(n);
	MatrixD B = A * A;
	
	if(B[0][0] != 2)
		pass = false;
	if(B[0][1] != 3)
		pass = false;
	if(B[1][0] != 6)
		pass = false;
	if(B[1][1] != 11)
		pass = false;
	
	return pass;
}

bool MCAddition()
{
	const int n = 5;
	bool pass = true;
	
	MatrixD A = InitSequential(n);
	MatrixD B = A + 5.0;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(B[i][j] != A[i][j] + 5.0)
				pass = false;
	
	return pass;
}

bool MCSubtraction()
{
	const int n = 5;
	bool pass = true;
	
	MatrixD A = InitSequential(n);
	MatrixD B = A - 5.0;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(B[i][j] != A[i][j] - 5.0)
				pass = false;
	
	return pass;
}

bool MCMultiplication()
{
	const int n = 5;
	bool pass = true;
	
	MatrixD A = InitSequential(n);
	MatrixD B = A * 5.0;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(B[i][j] != A[i][j] * 5.0)
				pass = false;
	
	return pass;
}

bool MCDivision()
{
	const int n = 5;
	bool pass = true;
	
	MatrixD A = InitSequential(n);
	MatrixD B = A / 5.0;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(B[i][j] != A[i][j] / 5.0)
				pass = false;
	
	return pass;
}