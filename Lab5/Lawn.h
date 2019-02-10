#pragma once

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

	protected:
		unsigned int GetSizeCountEachLengthByCm(unsigned int size, unsigned int length) const;

	};
}