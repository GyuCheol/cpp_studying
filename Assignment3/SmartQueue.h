#pragma once

#include <queue>
#include <limits>
#include <cmath>

#include "Utils.h"

namespace assignment3
{

	template<typename T>
	class SmartQueue
	{
	public:
		SmartQueue();

		void Enqueue(T number);
		T Max();
		T Min();
		T Sum();
		T Peek();
		T Dequeue();
		unsigned int Count();
		double Variance();
		double StandardDeviation();
		double Average();

	private:
		std::queue<T> mQueue;
		T mSum;
		double mSquareSum;
	};

	template<typename T> SmartQueue<T>::SmartQueue()
		: mSum(0)
		, mSquareSum(0)
	{
	}

	template<typename T>
	void SmartQueue<T>::Enqueue(T number)
	{
		mSum += number;
		mSquareSum += (number * number);
		mQueue.push(number);
	}

	template<typename T>
	T SmartQueue<T>::Max()
	{
		T max = std::numeric_limits<T>().lowest();

		if (Count() == 0)
		{
			return max;
		}

		std::queue<T> clone = mQueue;
		
		while (clone.empty() == false)
		{
			T value = clone.front();

			clone.pop();
			if (max < value)
			{
				max = value;
			}
		}

		return max;
	}

	template<typename T>
	T SmartQueue<T>::Min()
	{
		T min = std::numeric_limits<T>().max();

		if (Count() == 0)
		{
			return min;
		}

		std::queue<T> clone = mQueue;

		while (clone.empty() == false)
		{
			T value = clone.front();

			clone.pop();
			if (min > value)
			{
				min = value;
			}
		}

		return min;
	}

	template<typename T>
	T SmartQueue<T>::Sum()
	{
		return round(mSum);
	}

	template<typename T>
	T SmartQueue<T>::Peek()
	{
		return mQueue.front();
	}

	template<typename T>
	T SmartQueue<T>::Dequeue()
	{
		T value = mQueue.front();

		mQueue.pop();

		return value;
	}

	template<typename T>
	unsigned int SmartQueue<T>::Count()
	{
		return mQueue.size();
	}

	template<typename T>
	double SmartQueue<T>::Average()
	{
		return round((double)Sum() / Count());
	}

	template<typename T>
	double SmartQueue<T>::Variance()
	{
		double avgSquare = mSquareSum / Count();
		double avg = (double)Sum() / Count();

		return round(avgSquare - (avg * avg));
	}

	template<typename T>
	double SmartQueue<T>::StandardDeviation()
	{
		double avgSquare = mSquareSum / Count();
		double avg = (double)Sum() / Count();
		double var = avgSquare - (avg * avg);

		return round(sqrt(var));
	}

}
