#pragma once

#include <queue>
#include <stack>
#include <limits>
#include <cmath>

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
		std::queue<std::stack<T>*> mQueueStack;
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
	QueueStack<T>::~QueueStack()
	{
		while (mQueueStack.empty() == false)
		{
			std::stack<T>* item = mQueueStack.front();

			mQueueStack.pop();

			delete item;
		}
	}

	template<typename T>
	inline void QueueStack<T>::Enqueue(T number)
	{
	}

	template<typename T>
	inline T QueueStack<T>::Peek()
	{
		return T();
	}

	template<typename T>
	inline T QueueStack<T>::Dequeue()
	{
		return T();
	}

	template<typename T>
	inline T QueueStack<T>::Max()
	{
		return T();
	}

	template<typename T>
	inline T QueueStack<T>::Min()
	{
		return T();
	}

	template<typename T>
	double QueueStack<T>::Average()
	{
		return round((double)Sum() / Count());
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
