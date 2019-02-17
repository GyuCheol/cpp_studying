#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
		, mTrailer(NULL)
		, mHasTrailer(false)
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
		if (mHasTrailer == true)
		{
			return false;
		}

		mTrailer = trailer;
		mHasTrailer = true;

		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mHasTrailer == false)
		{
			return false;
		}

		delete mTrailer;
		mHasTrailer = false;

		return true;
	}
	unsigned int Sedan::GetMaxSpeed()
	{
		return GetDriveSpeed();
	}
	unsigned int Sedan::GetDriveSpeed()
	{
		int weight = getAllPersonWeight();

		if (mHasTrailer == true)
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
			mRestTime = mHasTrailer ? 1 : 2;
		}
	}
}