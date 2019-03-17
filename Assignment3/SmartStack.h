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
		double Variance() override;

	private:
		std::stack<T> mStack;
	};

	template<typename T>
	SmartStack<T>::SmartStack() 
		: SmartBase<T>()
	{
	}

	template<typename T>
	void SmartStack<T>::Push(const T& value)
	{
		if (this->mMax < value)
		{
			this->mMax = value;
		}

		if (this->mMin > value)
		{
			this->mMin = value;
		}

		this->mSum += value;
		this->mCount++;
		mStack.push(value);
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		T top = mStack.top();
		mStack.pop();

		this->mSum -= top;
		this->mCount--;

		std::stack<T> clone = mStack;

		this->mMin = std::numeric_limits<T>().max();
		this->mMax = std::numeric_limits<T>().min();

		while (clone.empty() == false)
		{
			T top = clone.top();

			clone.pop();

			if (this->mMax < top)
			{
				this->mMax = top;
			}

			if (this->mMin > top)
			{
				this->mMin = top;
			}
		}

		return top;
	}

	template<typename T>
	T SmartStack<T>::Peek()
	{
		return mStack.top();
	}

	template<typename T>
	double SmartStack<T>::Variance()
	{
		double varianceSum = 0;
		double avg = (double)this->mSum / this->mCount;
		std::stack<T> clone = mStack;

		while (clone.empty() == false)
		{
			T top = clone.top();

			clone.pop();

			varianceSum += std::pow(top - avg, 2);
		}

		return round<double>(varianceSum / this->mCount, 3.0);
	}

}
