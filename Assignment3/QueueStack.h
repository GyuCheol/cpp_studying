#pragma once

#include <queue>
#include <stack>

#include "SmartBase.h"

namespace assignment3
{

	template<typename T>
	class QueueStack : public SmartBase<T>
	{
	public:
		QueueStack(size_t maxSize);

		void Enqueue(T value);
		T Dequeue();
		unsigned int StackCount();

		T Peek() override;
		double Variance() override { return 0; };

	private:
		std::queue<std::stack<T>> mQueueStack;
		size_t mMaxSize;
	};

	template<typename T>
	QueueStack<T>::QueueStack(size_t maxSize)
		: SmartBase<T>()
		, mMaxSize(maxSize)
	{
	}

	template<typename T>
	void QueueStack<T>::Enqueue(T value)
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

		std::stack<T>* insertStack = nullptr;

		if (mQueueStack.empty() == true)
		{
			mQueueStack.push(std::stack<T>());
			insertStack = &mQueueStack.back();
		}
		else
		{
			insertStack = &mQueueStack.front();

			if (insertStack->size() == mMaxSize)
			{
				mQueueStack.push(std::stack<T>());
				insertStack = &mQueueStack.back();
			}
		}

		insertStack->push(value);
	}

	template<typename T>
	T QueueStack<T>::Peek()
	{
		std::stack<T>& stack = mQueueStack.front();

		return stack.top();
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		return T();
	}



	template<typename T>
	inline unsigned int QueueStack<T>::StackCount()
	{
		return mQueueStack.size();
	}

}
