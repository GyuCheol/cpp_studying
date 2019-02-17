#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}
	unsigned int Motorcycle::GetMaxSpeed()
	{
		return GetDriveSpeed();
	}
	unsigned int Motorcycle::GetDriveSpeed()
	{
		int a = (int)((-powf(((float)getAllPersonWeight() / 15.f), 3.f) + (2.f * (float)getAllPersonWeight()) + 400.f) + 0.5f);

		return Max(a, 0);
	}
	void Motorcycle::Travel()
	{
		if (mRestTime > 0)
		{
			mRestTime--;
			return;
		}

		mTravelIndex++;
		mTravelLength += GetMaxSpeed();

		if (mTravelIndex % 5 == 0)
		{
			mRestTime = 1;
		}
	}
}