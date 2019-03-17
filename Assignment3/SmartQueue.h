#pragma once

#include <queue>
#include <stack>

#include "SmartBase.h"

namespace assignment3
{

	template<typename T>
	class SmartQueue : public SmartBase<T>
	{
	public:
		SmartQueue();

		void Enqueue(T value);
		T Dequeue();
		T Peek() override;

	private:
		std::queue<T> mQueue;
		std::stack<T> mMaxStack;
		std::stack<T> mMinStack;
		
	};

	template<typename T> SmartQueue<T>::SmartQueue()
		: SmartBase<T>()
	{
	}

	template<typename T>
	void SmartQueue<T>::Enqueue(T value)
	{
		if (this->mMax <= value)
		{
			this->mMax = value;
			mMaxStack.push(value);
		}

		if (this->mMin >= value)
		{
			this->mMin = value;
			mMinStack.push(value);
		}

		this->mSum += value;
		this->mSumSquare += (value * value);
		this->mCount++;
		mQueue.push(value);
	}

	template<typename T>
	T SmartQueue<T>::Dequeue()
	{
		T front = mQueue.front();
		mQueue.pop();

		this->mSum -= front;
		this->mSumSquare -= (front * front);
		this->mCount--;

		if (this->mCount == 0)
		{
			this->mMin = std::numeric_limits<T>().max();
			this->mMax = std::numeric_limits<T>().lowest();
		}
		else
		{
			if (this->mMax == front)
			{
				mMaxStack.pop();
				this->mMax = mMaxStack.top();
			}

			if (this->mMin == front)
			{
				mMinStack.pop();
				this->mMin = mMaxStack.top();
			}
		}

		return front;
	}

	template<typename T>
	T SmartQueue<T>::Peek()
	{
		return mQueue.front();
	}

}
