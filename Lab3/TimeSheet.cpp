#include "Timesheet.h"
#include <math.h>

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		: mMaxEntries(maxEntries)
		, mTimeTotal(0)
		, mTimeIndex(0)
		, mName(name)
	{
		mTimeArray = new unsigned int[maxEntries];
	}

	TimeSheet::TimeSheet(const TimeSheet& other)
		: mMaxEntries(other.mMaxEntries)
		, mTimeIndex(other.mTimeIndex)
		, mTimeTotal(other.mTimeTotal)
		, mName(other.GetName())
	{
		mTimeArray = new unsigned int[mMaxEntries];
		memcpy(mTimeArray, other.mTimeArray, mMaxEntries * sizeof(int));
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mTimeArray;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours < 1 || timeInHours > 10 || mTimeIndex == mMaxEntries)
		{
			return;
		}

		mTimeTotal += timeInHours;
		mTimeArray[mTimeIndex] = timeInHours;
		mTimeIndex++;
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index >= mTimeIndex)
		{
			return -1;
		}

		return mTimeArray[index];
	}

	int TimeSheet::GetTotalTime() const
	{
		return mTimeTotal;
	}

	float TimeSheet::GetAverageTime() const
	{
		if (mTimeIndex == 0)
		{
			return 0.0f;
		}

		return (float) mTimeTotal / mTimeIndex;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		if (mTimeIndex == 0)
		{
			return 0.0f;
		}

		float avg = GetAverageTime();
		float total = .0f;

		for (unsigned int i = 0; i < mTimeIndex; i++)
		{
			float diff = mTimeArray[i] - avg;

			total += diff * diff;
		}

		return sqrt(total / mTimeIndex);
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}
}