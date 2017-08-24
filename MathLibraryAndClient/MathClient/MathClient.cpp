// MathClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"  
#include <iostream>  
#include "MathLibrary.h"  

using namespace std;

int main()
{
	double a = 7.4;
	int b = 99;

	cout << "a + b = " <<
		Add(a, b) << endl;
	cout << "a * b = " <<
		Multiply(a, b) << endl;
	cout << "a + (a * b) = " <<
		AddMultiply(a, b) << endl;

	return 0;
}
