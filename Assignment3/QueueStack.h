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
		~QueueStack();

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
		std::queue<SmartStack<T>*> mQueueStack;
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

	template<typename T> QueueStack<T>::~QueueStack()
	{
		while (mQueueStack.empty() == false)
		{
			SmartStack<T>* item = mQueueStack.front();

			mQueueStack.pop();

			delete item;
		}
	}

	template<typename T>
	void QueueStack<T>::Enqueue(T number)
	{
		SmartStack<T>* stack = nullptr;

		if (mCount == 0)
		{
			stack = new SmartStack<T>();

			mQueueStack.push(stack);
		}
		else
		{
			stack = mQueueStack.front();

			if (stack->Count() == mMaxStackSize)
			{
				stack = mQueueStack.back();

				if (stack->Count() == mMaxStackSize)
				{
					stack = new SmartStack<T>();

					mQueueStack.push(stack);
				}
			}
		}

		mCount++;
		mSum += number;
		stack->Push(number);
	}

	template<typename T>
	T QueueStack<T>::Peek()
	{
		SmartStack<T>* stack = mQueueStack.front();

		return stack->Peek();
	}

	template<typename T>
	inline T QueueStack<T>::Dequeue()
	{
		SmartStack<T>* stack = mQueueStack.front();
		T value = stack->Pop();

		mSum -= value;
		mCount--;

		if (stack->Count() == 0)
		{
			mQueueStack.pop();
			delete stack;
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

		std::queue<SmartStack<T>*> clone = mQueueStack;

		while (clone.empty() == false)
		{
			SmartStack<T>* stack = clone.front();

			if (max < stack->Max())
			{
				max = stack->Max();
			}

			clone.pop();
		}

		return max;
	}

	template<typename T>
	inline T QueueStack<T>::Min()
	{
		T min = std::numeric_limits<T>().max();

		if (mCount == 0)
		{
			return min;
		}

		std::queue<SmartStack<T>*> clone = mQueueStack;

		while (clone.empty() == false)
		{
			SmartStack<T>* stack = clone.front();

			if (min > stack->Min())
			{
				min = stack->Min();
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
		return round(mSum);
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
