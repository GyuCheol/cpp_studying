#include "MyString.h"

using namespace assignment1;
using namespace std;

int main()
{
	MyString s("Hello");
	MyString s2("Hello");
	
	s.RemoveAt(0);
	cout << s.GetCString() << endl;

	s.RemoveAt(2);
	cout << s.GetCString() << endl;

	s.RemoveAt(4);
	cout << s.GetCString() << endl;

	s.PadLeft(8, '-');
	cout << s.GetCString() << endl;

	s2.PadRight(8, '-');
	cout << s2.GetCString() << endl;
}