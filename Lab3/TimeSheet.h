#pragma once
#include <string>

namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet(const char* name, unsigned int maxEntries);
		TimeSheet(const TimeSheet& other);
		~TimeSheet();

		void AddTime(int timeInHours);
		int GetTimeEntry(unsigned int index) const;
		int GetTotalTime() const;
		float GetAverageTime() const;
		float GetStandardDeviation() const;
		const std::string& GetName() const;

	private:
		unsigned int* mTimeArray;
		unsigned int mTimeIndex;
		unsigned int mTimeTotal;
		unsigned int mMaxEntries;
		std::string mName;
	};
}