#include "Lab2.h"
#include <iostream>
#include <iomanip>

using namespace lab2;
using namespace std;

int main()
{
	cout << setw(12) << "oct" << ' ';
	cout << setw(10) << "dec" << ' ';
	cout << setw(8) << "hex" << endl;
	cout << setw(12) << setfill('-') << "" << ' ' << setw(10) << "" << ' ' << setw(8) << "" << endl;

	PrintIntegers(cin, cout);
	PrintMaxFloat(cin, cout);
}