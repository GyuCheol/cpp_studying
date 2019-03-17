#pragma once

#include <stack>
#include <limits>
#include <cmath>

#include "Utils.h"

namespace assignment3
{

	template<typename T>
	class SmartStack
	{
	public:
		SmartStack();
		void Push(T number);
		T Max();
		T Min();
		T Sum();
		T Pop();
		T Peek();
		unsigned int Count();
		double Variance();
		double StandardDeviation();
		double Average();

	private:
		std::stack<T> mStack;
		std::stack<T> mMaxStack;
		std::stack<T> mMinStack;

		T mSum;
		double mSquareSum;
	};

	template<typename T> SmartStack<T>::SmartStack()
		: mSum(0)
		, mSquareSum(0)
	{


	}

	template<typename T>
	void SmartStack<T>::Push(T number)
	{
		mSum += number;
		mSquareSum += (number * number);
		mStack.push(number);

		if (Max() <= number)
		{
			mMaxStack.push(number);
		}

		if (Min() >= number)
		{
			mMinStack.push(number);
		}

	}

	template<typename T>
	T SmartStack<T>::Max()
	{
		if (mMaxStack.empty() == true)
		{
			return std::numeric_limits<T>().lowest();
		}

		return mMaxStack.top();
	}

	template<typename T>
	T SmartStack<T>::Min()
	{
		if (mMinStack.empty() == true)
		{
			return std::numeric_limits<T>().max();
		}

		return mMinStack.top();
	}

	template<typename T>
	T SmartStack<T>::Sum()
	{
		return round(mSum);
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		T value = mStack.top();

		mSum -= value;
		mSquareSum -= (value * value);

		if (value == Max())
		{
			mMaxStack.pop();
		}

		if (value == Min())
		{
			mMinStack.pop();
		}

		mStack.pop();

		return value;
	}

	template<typename T>
	T SmartStack<T>::Peek()
	{
		return mStack.top();
	}

	template<typename T>
	unsigned int SmartStack<T>::Count()
	{
		return mStack.size();
	}

	template<typename T>
	double SmartStack<T>::Variance()
	{
		double avgSquare = mSquareSum / Count();
		double avg = (double)mSum / Count();

		return round(avgSquare - (avg * avg));
	}

	template<typename T>
	double SmartStack<T>::StandardDeviation()
	{
		double avgSquare = mSquareSum / Count();
		double avg = (double)mSum / Count();
		double var = avgSquare - (avg * avg);

		return round(sqrt(var));
	}

	template<typename T>
	double SmartStack<T>::Average()
	{
		return round((double)mSum / Count());
	}

}
