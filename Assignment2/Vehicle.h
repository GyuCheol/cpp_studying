#pragma once

#define Max(a, b) a > b ? a : b

#include "Person.h"
#include <cmath>

namespace assignment2
{
	class Vehicle
	{
	public:
		const float EulerNum = 2.71828182845904523536f;

		Vehicle(unsigned int maxPassengersCount);
		virtual ~Vehicle();

		virtual unsigned int GetMaxSpeed() = 0;
		virtual void Travel() = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		void ClearPassenger();
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetTravelLength() const;
		void Migrate(Vehicle& vehicle);

	protected:
		int getAllPersonWeight() const;
		unsigned int mTravelIndex;
		unsigned int mRestTime;
		unsigned int mTravelLength;

	private:
		unsigned int mMaxPassengersCount;
		unsigned int mPassengersCount;
		const Person* mPersonArray[100];

	};
}