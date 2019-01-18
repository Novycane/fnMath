//
//  .test.cpp
//  
//
//  Created by Steven Novak on //19.
//
// --------------------------------------------------
//
//
//
//
// --------------------------------------------------

#include <iostream>

#include "../src/LinAlg/Tridiagonal.hpp"
#include "../src/LinAlg/Tridiagonal.cpp"

using namespace fnMath::LinAlg;
using namespace std;

// ------------------------- globals
int FailedTests = 0;
int PassedTests = 0;

// ------------------------- Declarations

bool SetupMatrix();
bool Accessors();
bool Solve();

void RunTest(bool pass, const char* testName);

// ------------------------- Main

int main (int argCount, char** args)
{
    cout << endl << " ---------------   Testing Tridiagonal functions   ---------------" << endl;

	RunTest(SetupMatrix(), "Initialize Tridiagonal System");
	RunTest(Accessors(), "Accessors");
	RunTest(Solve(), "Internal Solve Method");

	cout << " -------------- Done Testing Tridiagonal functions --------------" << endl << endl;
		
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


// ------------------------- Tests

bool SetupMatrix()
{
	Tridiagonal<double> t(5, 2.0, 1.0, 1.0);
	
	if(t[0][0] != 0)
		return false;
	if(t[0][1] != 2)
		return false;
	if(t[0][2] != 1)
		return false;
	
	if(t[1][0] != 1)
		return false;
	if(t[1][1] != 2)
		return false;
	if(t[1][2] != 1)
		return false;
	
	return true;
}

bool Accessors()
{
	Tridiagonal<double> t(6, -2.0, 1.0, 1.0);
	
	if(t.NumRows() != 6)
		return false;
	if(t.NumColumns() != 3)
		return false;
	
	return true;
}

bool Solve()
{
	Tridiagonal<double> t(6, -2.0, 1.0, 1.0);
	vector<double> b = {3, -5, 497, -998, 419, 168};
	auto x = t.Solve(b);
	
	if(abs(x[0] - 1) > 1e-5)
		return false;
	if(abs(x[1] - 5) > 1e-5)
		return false;
	if(abs(x[2] - 4) > 1e-5)
		return false;
	if(abs(x[3] - 500) > 1e-5)
		return false;
	if(abs(x[4] + 2) > 1e-5)
		return false;
	if(abs(x[5] + 85) > 1e-5)
		return false;
	
	return true;
}