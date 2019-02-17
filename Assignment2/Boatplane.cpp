#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boatplane::~Boatplane()
	{
	}
	unsigned int Boatplane::GetMaxSpeed()
	{
		unsigned int a = GetFlySpeed();
		unsigned int b = GetSailSpeed();

		return Max(a, b);
	}
	unsigned int Boatplane::GetFlySpeed()
	{
		return (unsigned int)((150.f * powf(EULER_NUM, (float)(-GetAllPersonWeight() + 500) / 300)) + 0.5f);
	}
	unsigned int Boatplane::GetSailSpeed()
	{
		return (unsigned int)Max((int)(800.f - (1.7f * GetAllPersonWeight())), 20);
	}
	void Boatplane::Travel()
	{
		if (mRestTime > 0)
		{
			mRestTime--;
			return;
		}

		mTravelIndex++;
		mTravelLength += GetMaxSpeed();
		mRestTime = 3;
	}
}