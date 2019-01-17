//
//  Jacobi.test.cpp
//  
//
//  Created by Steven Novak on 12/17/17.
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

#include "../src/LinAlg/Jacobi.hpp"
#include "../src/LinAlg/Jacobi.cpp"

using namespace fnMath::LinAlg;
using namespace std;

// ------------------------- globals
int FailedTests = 0;
int PassedTests = 0;

// ------------------------- Declarations

bool Solve();
bool SolveWithIterations();
bool DiagonallyDominant();

void RunTest(bool pass, const char* testName);
MatrixD InitTestMatrix();
MatrixD InitRandom(int n);


// ------------------------- Main

int main (int argCount, char** args)
{
    cout << endl << " ---------------   Testing Jacobi functions   ---------------" << endl;

	RunTest(Solve(), "Matrix Solve"); 
	RunTest(SolveWithIterations(), "Solve With Various Iterations"); 
	RunTest(DiagonallyDominant(), "Diagonally Dominance"); 
	
	cout << " -------------- Done Testing Jacobi functions --------------" << endl << endl;
		
    return 0;
}

// ------------------------- Utility

void RunTest(bool pass, const char* testName)
{
	cout << testName << " Test" ;
	if(pass)
	{
		cout << "...Ok" << endl;
		PassedTests++;
	}
	else
	{
		cout << "...Failed!" << endl;
		FailedTests++;
	}
}

MatrixD InitTestMatrix()
{
	MatrixD A(0,3,3);

	A[0][0] = 100.0;
	A[1][0] = 2.0;
	A[2][0] = 0.0;
	
	A[0][1] = -2.0;
	A[1][1] = 80.0;
	A[2][1] = 2.0;
	
	A[0][2] = 3.0;
	A[1][2] = 12.0;
	A[2][2] = -160.0;

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

bool Solve()
{
	auto A = InitTestMatrix();
	Jacobi<double> J(A);
	vector<double> y = {409,572,-1108};
	
	auto b = J.Solve(y);
	
	if(b[0] - 4.0 > 1e-5 || b[1] - 6.0 > 1e-5 || b[2] - 7.0 > 1e-5 )
		return false;
	else
		return true;
}

bool SolveWithIterations()
{
	auto A = InitTestMatrix();
	int iteration, lastIteration = 0;
	double err = 1;
	Jacobi<double> J(A);
	vector<double> y = {409,572,-1108};
	
	for(int i=0; i<10; i++)
	{
		J.SetMaxError(err);
		J.Solve(y);
		iteration = J.Iterations();
		if(iteration < lastIteration)
			return false;
		lastIteration = iteration;
		err /= 10.0;	
	}
	
	return true;
}

bool DiagonallyDominant()
{
	auto A = InitTestMatrix();
	auto B = InitRandom(5);
	
	for(int i=0; i<B.numRows(); i++)
		B[i][i]=1e-200;
	
	Jacobi<double> J(A);
	if(J.IsDiagonallyDominant() == false)
		return false;
	
	if(J.IsDiagonallyDominant(make_shared<MatrixD>(B)) == true)
		return false;
	
	return true;
}
