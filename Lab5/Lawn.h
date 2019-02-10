#pragma once
#include <cmath>
#include "eGrassType.h"

namespace lab5
{
	const double PI = 3.14;

	class Lawn
	{

	public:
		Lawn();
		virtual ~Lawn();

		virtual unsigned int GetArea() const = 0;

		unsigned int GetGrassPrice(eGrassType grassType) const;
		unsigned int GetMinimumSodRollsCount() const;

	};
}