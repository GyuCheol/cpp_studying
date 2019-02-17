#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}

	unsigned int Airplane::GetMaxSpeed()
	{
		unsigned int a = GetDriveSpeed();
		unsigned int b = GetFlySpeed();

		return Max(a, b);
	}

	unsigned int Airplane::GetDriveSpeed()
	{
		return (unsigned int)((4.f * powf(EulerNum, ((float)-getAllPersonWeight() + 400.f) / 70.f)) + 0.5f);
	}

	unsigned int Airplane::GetFlySpeed()
	{
		return (unsigned int)((200.f * powf(EulerNum, ((float)-getAllPersonWeight() + 800.f) / 500.f)) + 0.5f);
	}

	void Airplane::Travel()
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

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane bp(GetMaxPassengersCount() + boat.GetMaxPassengersCount());

		MovePassengersToAnotherVehicle(bp);
		boat.MovePassengersToAnotherVehicle(bp);

		return bp;
	}
}