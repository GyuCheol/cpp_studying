#pragma once

#include <queue>
#include <limits>
#include <cmath>

#include "SmartStack.h"
#include "Utils.h"

namespace assignment3
{

	template<typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);

		void Enqueue(T number);
		T Peek();
		T Dequeue();
		T Max();
		T Min();
		double Average();
		T Sum();
		unsigned int Count();
		unsigned int StackCount();

	private:
		std::queue<SmartStack<T>> mQueueStack;
		unsigned int mMaxStackSize;
		T mSum;
		unsigned int mCount;
	};

	template<typename T> QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
		, mSum(0)
		, mCount(0)
	{
	}

	template<typename T>
	void QueueStack<T>::Enqueue(T number)
	{
		if (mCount == 0 || mQueueStack.back().Count() == mMaxStackSize)
		{
			mQueueStack.push(SmartStack<T>());
		}
		
		mSum += number;
		mCount++;
		mQueueStack.back().Push(number);
	}

	template<typename T>
	T QueueStack<T>::Peek()
	{
		return mQueueStack.front().Peek();
	}

	template<typename T>
	inline T QueueStack<T>::Dequeue()
	{
		T value = mQueueStack.front().Pop();

		mSum -= value;
		mCount--;

		if (mQueueStack.front().Count() == 0)
		{
			mQueueStack.pop();
		}

		return value;
	}

	template<typename T>
	inline T QueueStack<T>::Max()
	{
		T max = std::numeric_limits<T>().lowest();

		if (mCount == 0)
		{
			return max;
		}

		std::queue<SmartStack<T>> clone = mQueueStack;

		while (clone.empty() == false)
		{
			SmartStack<T> stack = clone.front();

			if (max < stack.Max())
			{
				max = stack.Max();
			}

			clone.pop();
		}

		return max;
	}

	template<typename T>
	T QueueStack<T>::Min()
	{
		T min = std::numeric_limits<T>().max();

		if (mCount == 0)
		{
			return min;
		}

		std::queue<SmartStack<T>> clone = mQueueStack;

		while (clone.empty() == false)
		{
			SmartStack<T> stack = clone.front();

			if (min > stack.Min())
			{
				min = stack.Min();
			}

			clone.pop();
		}

		return min;
	}

	template<typename T>
	double QueueStack<T>::Average()
	{
		return round((double)mSum / Count());
	}

	template<typename T>
	T QueueStack<T>::Sum()
	{
		return mSum;
	}

	template<typename T>
	unsigned int QueueStack<T>::Count()
	{
		return mCount;
	}

	template<typename T>
	unsigned int QueueStack<T>::StackCount()
	{
		return mQueueStack.size();
	}

}
