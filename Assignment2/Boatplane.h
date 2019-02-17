#pragma once

#include "Vehicle.h"
#include "IFlyable.h"
#include "ISailable.h"

namespace assignment2
{
	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		Boatplane(const Boatplane& boatplane);
		~Boatplane();

		unsigned int GetMaxSpeed();
		unsigned int GetFlySpeed();
		unsigned int GetSailSpeed();
		void Travel();

	};
}