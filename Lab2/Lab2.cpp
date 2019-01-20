#include "Lab2.h"
#include <iomanip>
#include <string>

using namespace std;

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		// Header
		out << setw(12) << "oct" << ' ';
		out << setw(10) << "dec" << ' ';
		out << setw(8) << "hex" << endl;
		out << setw(12) << setfill('-') << "" << ' ' << setw(10) << "" << ' ' << setw(8) << "" << endl;

		int number;
		string trash;

		while (true)
		{
			in >> number;

			if (in.eof())
			{
				in.clear();
				break;
			}

			if (in.fail())
			{
				in.clear();
				in >> trash;
				continue;
			}
		
			out << setfill(' ');
			out << setw(12) << oct << number << ' ';
			out << setw(10) << dec << number << ' ';
			out << setw(8) << uppercase << hex << number;
			out << endl;
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		float number;
		float max = -FLT_MAX;
		string trash;

		while (true)
		{
			in >> number;

			if (in.eof())
			{
				in.clear();

				out << setfill(' ');
				out << setw(5) << left << "max:";
				out << setw(15) << showpos << showpoint << internal << fixed << setprecision(3) << max;

				break;
			}

			if (in.fail())
			{
				in.clear();
				in >> trash;
				continue;
			}

			if (max < number)
			{
				max = number;
			}

			out << setfill(' ');
			out << setw(5) << "";
			out << setw(15) << showpos << showpoint << internal << fixed << setprecision(3) << number;
			out << endl;
		}
	}
}