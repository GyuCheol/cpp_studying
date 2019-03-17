#pragma once

#include <stack>

#include "SmartBase.h"

namespace assignment3
{

	template<typename T>
	class SmartStack : public SmartBase<T>
	{
	public:
		SmartStack();

		void Push(const T& value);
		T Pop();
		T Peek() override;

	private:
		std::stack<T> mStack;
		std::stack<T> mMaxStack;
		std::stack<T> mMinStack;
	};

	template<typename T> SmartStack<T>::SmartStack() 
		: SmartBase<T>()
	{
	}

	template<typename T>
	void SmartStack<T>::Push(const T& value)
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
		mStack.push(value);
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		T top = mStack.top();
		mStack.pop();

		this->mSum -= top;
		this->mSumSquare -= (top * top);
		this->mCount--;

		if (this->mCount == 0)
		{
			this->mMin = std::numeric_limits<T>().max();
			this->mMax = std::numeric_limits<T>().lowest();
		}
		else
		{
			if (this->mMax == top)
			{
				mMaxStack.pop();
				this->mMax = mMaxStack.top();
			}

			if (this->mMin == top)
			{
				mMinStack.pop();
				this->mMin = mMaxStack.top();
			}
		}

		return top;
	}

	template<typename T>
	T SmartStack<T>::Peek()
	{
		return mStack.top();
	}

}
