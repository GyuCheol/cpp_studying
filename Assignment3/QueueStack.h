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
		~QueueStack();

		void Enqueue(T value);
		T Dequeue();
		unsigned int StackCount();

		T Peek() override;
		double Variance() override;

	private:
		std::queue<std::stack<T>*> mQueueStack;
		size_t mMaxSize;
	};

	template<typename T>
	QueueStack<T>::QueueStack(size_t maxSize)
		: SmartBase<T>()
		, mMaxSize(maxSize)
	{
	}

	template<typename T>
	QueueStack<T>::~QueueStack()
	{
		while (mQueueStack.empty() == false)
		{
			std::stack<T>* front = mQueueStack.front();

			mQueueStack.pop();
			delete front;
		}
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
			insertStack = new std::stack<T>();

			mQueueStack.push(insertStack);
		}
		else
		{
			std::queue<std::stack<T>*> clone = mQueueStack;

			insertStack = clone.front();

			while (insertStack->size() == mMaxSize)
			{
				clone.pop();

				if (clone.empty() == true)
				{
					insertStack = new std::stack<T>();

					mQueueStack.push(insertStack);
					break;
				}

				insertStack = clone.front();
			}
		}

		insertStack->push(value);
	}

	template<typename T>
	T QueueStack<T>::Peek()
	{
		std::stack<T>* stack = mQueueStack.front();

		return stack->top();
	}

	template<typename T>
	double QueueStack<T>::Variance()
	{
		return 0.0;
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		std::stack<T>* stack = mQueueStack.front();

		T value = stack->top();
		stack->pop();

		if (stack->size() == 0)
		{
			delete stack;
			mQueueStack.pop();
		}

		this->mMin = std::numeric_limits<T>().max();
		this->mMax = std::numeric_limits<T>().min();

		if (mQueueStack.empty() == false)
		{
			std::queue<std::stack<T>*> clone = mQueueStack;

			while (clone.empty() == false)
			{
				std::stack<T> tmp = *clone.front();
				clone.pop();

				while (tmp.empty() == false)
				{
					T top = tmp.top();
					tmp.pop();

					if (this->mMin > top)
					{
						this->mMin = top;
					}

					if (this->mMax < top)
					{
						this->mMax = top;
					}
				}
			}
		}

		this->mCount--;

		return value;
	}

	template<typename T>
	inline unsigned int QueueStack<T>::StackCount()
	{
		return mQueueStack.size();
	}

}
