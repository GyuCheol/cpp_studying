#include <iostream>
#include "TimeSheet.h"

using namespace std;
using namespace lab3;

class Vector
{
public:
	int mX;
	int mY;

public:
	Vector() 
		: mX(0)
		, mY(0)
	{
	}

};

Vector AddVector() {
	Vector vector = Vector();

	vector.mX = 10;
	vector.mY = 10;

	cout << &vector.mX << " " << &vector.mY << endl;

	return vector;
}

int main() {
	TimeSheet p("Pope", 10);

	p.AddTime(4);
	p.AddTime(7);
	p.AddTime(6);
	p.AddTime(5);
	p.AddTime(1);
	p.AddTime(2);

	cout << p.GetStandardDeviation(); // 2.11476 ¹ÝÈ¯

	return 0;
}