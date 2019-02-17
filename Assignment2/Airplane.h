#pragma once

#include "Boatplane.h"
#include "Vehicle.h"
#include "IFlyable.h"
#include "IDrivable.h"

namespace assignment2
{
	class Boat;

	class Airplane : public Vehicle, public IFlyable, public IDrivable
	{
	public:
		Airplane(unsigned int maxPassengersCount);
		~Airplane();

		unsigned int GetMaxSpeed();
		unsigned int GetDriveSpeed();
		unsigned int GetFlySpeed();
		void Travel();

		Boatplane operator+(Boat& boat);
	};
}