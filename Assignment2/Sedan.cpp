#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
		, mTrailer(NULL)
	{
	}

	Sedan::~Sedan()
	{
		if (mTrailer != NULL)
		{
			delete mTrailer;
		}
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (mTrailer != NULL && trailer != NULL)
		{
			return false;
		}

		mTrailer = trailer;

		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mTrailer == NULL)
		{
			return false;
		}

		delete mTrailer;
		mTrailer = NULL;

		return true;
	}
	unsigned int Sedan::GetMaxSpeed()
	{
		return GetDriveSpeed();
	}
	unsigned int Sedan::GetDriveSpeed()
	{
		int weight = getAllPersonWeight();

		if (mTrailer != NULL)
		{
			weight += mTrailer->GetWeight();
		}

		if (weight <= 80)
		{
			return 480;
		}
		else if (weight <= 160)
		{
			return 458;
		}
		else if (weight <= 260)
		{
			return 400;
		}
		else if (weight <= 350)
		{
			return 380;
		}
		else
		{
			return 300;
		}
	}
	void Sedan::Travel()
	{
		if (mRestTime > 0)
		{
			mRestTime--;
			return;
		}

		mTravelIndex++;
		mTravelLength += GetMaxSpeed();

		if (mTravelIndex % 5 == 0)
		{
			mRestTime = mTrailer == NULL ? 1 : 2;
		}
	}
}