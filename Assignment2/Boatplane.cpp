#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boatplane::Boatplane(const Boatplane& boatplane)
		: Vehicle(boatplane.GetMaxPassengersCount())
	{
		Migrate((Boatplane&) boatplane);
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
		return (unsigned int)((150.f * powf(EulerNum, ((float)(getAllPersonWeight() * -1) + 500.f) / 300.f)) + 0.5f);
	}
	unsigned int Boatplane::GetSailSpeed()
	{
		return (unsigned int)(Max(800.f - 1.7 * getAllPersonWeight(), 20.f) + 0.5f);
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