#pragma once

#include "Vehicle.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		const int MaxCount = 10;

		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;

		~DeusExMachina() {

			for (size_t i = 0; i < mVehicleCount; i++)
			{
				delete mVehicle[i];
			}
		};

	private:
		DeusExMachina();
		
		unsigned int mVehicleCount;
		Vehicle* mVehicle[10];

	};
}