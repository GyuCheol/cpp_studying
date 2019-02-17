#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)
	{
	}

	UBoat::~UBoat()
	{
	}
	unsigned int UBoat::GetMaxSpeed()
	{
		unsigned int a = GetDiveSpeed();
		unsigned int b = GetSailSpeed();

		return Max(a, b);
	}
	unsigned int UBoat::GetDiveSpeed()
	{
		return (unsigned int)((500.f * log(((float)getAllPersonWeight() + 150.f) / 150.f) + 30.f) + 0.5f);
	}
	unsigned int UBoat::GetSailSpeed()
	{
		int a = 550 - (getAllPersonWeight() / 10);

		return Max(a, 200);
	}
	void UBoat::Travel()
	{
		if (mRestTime > 0)
		{
			mRestTime--;
			return;
		}

		mTravelIndex++;
		mTravelLength += GetMaxSpeed();

		if (mTravelIndex % 2 == 0)
		{
			mRestTime = 4;
		}
	}
}