#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengersCount(maxPassengersCount)
		, mPassengersCount(0)
		, mTravelIndex(0)
		, mRestTime(0)
	{
	}

	Vehicle::~Vehicle()
	{
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mPassengersCount == mMaxPassengersCount)
		{
			return false;
		}

		mPersonArray[mPassengersCount] = person;
		mPassengersCount++;

		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i >= mPassengersCount)
		{
			return false;
		}

		delete mPersonArray[i];
		
		for (size_t j = i; j < (mPassengersCount - 1); j++)
		{
			mPersonArray[j] = mPersonArray[j + 1];
		}

		mPassengersCount--;

		return true;
	}

	void Vehicle::ClearPassenger()
	{
		for (size_t i = 0; i < mPassengersCount; i++)
		{
			mPersonArray[i] = NULL;
		}

		mPassengersCount = 0;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mPassengersCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	unsigned int Vehicle::GetTravelLength() const
	{
		return mTravelLength;
	}

	int Vehicle::GetAllPersonWeight() const
	{
		int total = 0;

		for (unsigned int i = 0; i < mPassengersCount; i++)
		{
			total += mPersonArray[i]->GetWeight();
		}

		return total;
	}

	void Vehicle::MovePassengersToAnotherVehicle(Vehicle & vehicle)
	{
		for (unsigned int i = 0; i < mPassengersCount; i++)
		{
			vehicle.AddPassenger(GetPassenger(i));
		}

		ClearPassenger();
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i >= mPassengersCount)
		{
			return NULL;
		}

		return mPersonArray[i];
	}
}