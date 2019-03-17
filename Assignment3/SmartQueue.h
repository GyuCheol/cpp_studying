#pragma once

#include <queue>

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
		double Variance() override;

	private:
		std::queue<T> mQueue;
		
	};

	template<typename T>
	SmartQueue<T>::SmartQueue() : SmartBase<T>()
	{
	}

	template<typename T>
	inline void SmartQueue<T>::Enqueue(T value)
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
		mQueue.push(value);
	}

	template<typename T>
	inline T SmartQueue<T>::Dequeue()
	{
		T front = mQueue.front();
		mQueue.pop();

		this->mSum -= front;
		this->mCount--;

		std::queue<T> clone = mQueue;

		this->mMin = std::numeric_limits<T>().max();
		this->mMax = std::numeric_limits<T>().min();

		while (clone.empty() == false)
		{
			T front = clone.front();

			clone.pop();

			if (this->mMax < front)
			{
				this->mMax = front;
			}

			if (this->mMin > front)
			{
				this->mMin = front;
			}
		}

		return front;
	}

	template<typename T>
	T SmartQueue<T>::Peek()
	{
		return mQueue.front();
	}

	template<typename T>
	double SmartQueue<T>::Variance()
	{
		double varianceSum = 0;
		double avg = (double)this->mSum / this->mCount;
		std::queue<T> clone = mQueue;

		while (clone.empty() == false)
		{
			T front = clone.front();

			clone.pop();

			varianceSum += std::pow(front - avg, 2);
		}

		return utils::round<double>(varianceSum / this->mCount, 3.0);
	}



}
