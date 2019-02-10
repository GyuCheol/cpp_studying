#include "Lawn.h"

namespace lab5
{
	Lawn::Lawn()
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		int cent = 0;

		switch (grassType)
		{
		case lab5::BERMUDA:
			cent = 800;
			break;
		case lab5::BAHIA:
			cent = 500;
			break;
		case lab5::BENTGRASS:
			cent = 300;
			break;
		case lab5::PERENNIAL_RYEGRASS:
			cent = 250;
			break;
		case lab5::ST_AUGUSTINE:
			cent = 450;
			break;
		}

		return (GetArea() * cent) / 100;
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		return GetSizeCountEachLengthByCm(GetArea() * 100, 30);
	}

	unsigned int Lawn::GetSizeCountEachLengthByCm(unsigned int size, unsigned int length) const
	{
		return (unsigned int) (size / length) + (size % length == 0 ? 0 : 1);
	}

}