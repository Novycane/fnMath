//
//  BandedMatrix.test.cpp
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
#include "../src/LinAlg/BandedMatrix.hpp"
#include "../src/LinAlg/BandedMatrix.cpp"

using namespace std;
using namespace fnMath::LinAlg;

// ------------------------- globals
int FailedTests = 0;
int PassedTests = 0;

// ------------------------- Declarations

void TestPrint();

void RunTest(bool pass, const char* testName);

// ------------------------- Main

int main (int argCount, char** args)
{
    cout << endl << " ---------------   Testing Banded Matrix functions   ---------------" << endl;
	
	TestPrint();
	
	cout << " -------------- Done Testing Banded Matrix functions --------------" << endl << endl;
		
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

void TestPrint()
{
	
}