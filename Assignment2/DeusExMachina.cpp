#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::GetInstance()
	{
		static DeusExMachina* instance = NULL;

		if (instance == NULL)
		{
			instance = new DeusExMachina();
		}

		return instance;
	}

	void DeusExMachina::Travel() const
	{
		for (size_t i = 0; i < mVehicleCount; i++)
		{
			mVehicle[i]->Travel();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mVehicleCount == MAX_COUNT)
		{
			return false;
		}

		mVehicle[mVehicleCount] = vehicle;
		mVehicleCount++;

		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i >= mVehicleCount)
		{
			return false;
		}

		delete mVehicle[i];

		for (size_t j = i; j < mVehicleCount - 1; j++)
		{
			mVehicle[j] = mVehicle[j + 1];
		}

		mVehicleCount--;

		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mVehicleCount == 0)
		{
			return NULL;
		}

		Vehicle* vehicle = mVehicle[0];
		unsigned int maxSpeed = vehicle->GetTravelLength();

		for (size_t i = 1; i < mVehicleCount; i++)
		{
			if (maxSpeed < mVehicle[i]->GetTravelLength())
			{
				vehicle = mVehicle[i];
				maxSpeed = vehicle->GetTravelLength();
			}
		}

		return vehicle;
	}
	DeusExMachina::DeusExMachina()
		: mVehicleCount(0)
	{
	}
}