#include "Boat.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	unsigned int Boat::GetSailSpeed()
	{
		return Max(800 - (10 * getAllPersonWeight()), 20);
	}

	unsigned int Boat::GetMaxSpeed()
	{
		return GetSailSpeed();
	}

	void Boat::Travel()
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
			mRestTime = 1;
		}
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane bp(GetMaxPassengersCount() + plane.GetMaxPassengersCount());

		plane.MovePassengersToAnotherVehicle(bp);
		MovePassengersToAnotherVehicle(bp);
		return bp;
	}
}