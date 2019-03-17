#pragma once

#include <limits>

namespace assignment3
{

	template<typename T>
	class SmartBase
	{
	public:
		SmartBase();

		T Max();
		T Min();
		T Sum();
		unsigned int Count();
		double Average();
		double StandardDeviation();
		virtual T Peek() = 0;
		virtual double Variance() = 0;

	protected:
		T mMin;
		T mMax;
		T mSum;
		unsigned int mCount;
	};

	template<typename T>
	SmartBase<T>::SmartBase()
		: mMin(std::numeric_limits<T>().max())
		, mMax(std::numeric_limits<T>().min())
		, mSum(0)
		, mCount(0)
	{
	}

	template<typename T>
	T SmartBase<T>::Max()
	{
		return mMax;
	}

	template<typename T>
	T SmartBase<T>::Min()
	{
		return mMin;
	}

	template<typename T>
	T SmartBase<T>::Sum()
	{
		return utils::round<T>(mSum, 3);
	}

	template<typename T>
	unsigned int SmartBase<T>::Count()
	{
		return mCount;
	}

	template<typename T>
	double SmartBase<T>::Average()
	{
		return utils::round<double>((double)mSum / mCount, 3.0);
	}

	template<typename T>
	double SmartBase<T>::StandardDeviation()
	{
		return utils::round(std::sqrt(Variance()), 3.0);
	}

}
