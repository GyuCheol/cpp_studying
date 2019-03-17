#pragma once

#include <limits>
#include <cmath>

namespace assignment3
{
	template<typename T>
	T round(T number)
	{
		return static_cast<T>(std::round((double)number * 1000.0) / 1000.0);
	}

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
		double Variance();
		virtual T Peek() = 0;
		virtual double CalculateVariance() = 0;

	protected:
		T mMin;
		T mMax;
		T mSum;
		double mVariance;
		unsigned int mCount;
	};

	template<typename T> SmartBase<T>::SmartBase()
		: mMin(std::numeric_limits<T>().max())
		, mMax(std::numeric_limits<T>().lowest())
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
		return round<T>(mSum);
	}

	template<typename T>
	unsigned int SmartBase<T>::Count()
	{
		return mCount;
	}

	template<typename T>
	double SmartBase<T>::Average()
	{
		return round<double>((double)mSum / mCount);
	}

	template<typename T>
	double SmartBase<T>::StandardDeviation()
	{
		return round(std::sqrt(mVariance));
	}

	template<typename T>
	double SmartBase<T>::Variance()
	{
		return round(mVariance);
	}

}
