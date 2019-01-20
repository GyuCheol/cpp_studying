#include "Lab2.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace lab2;
using namespace std;

int main()
{
	ifstream fin;
	fin.open("int_input.txt");
	PrintIntegers(fin, cout);
	fin.close();

	ifstream fin2;
	fin2.open("float_input.txt");
	PrintMaxFloat(fin2, cout);
	fin2.close();

}