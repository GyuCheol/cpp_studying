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

	private:
		std::queue<std::stack<T>*> mQueueStack;
		std::stack<T> mMaxStack;
		std::stack<T> mMinStack;
		size_t mMaxSize;
	};

	template<typename T> QueueStack<T>::QueueStack(size_t maxSize)
		: SmartBase<T>()
		, mMaxSize(maxSize)
	{
	}

	template<typename T> QueueStack<T>::~QueueStack()
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
	T QueueStack<T>::Dequeue()
	{
		std::stack<T>* stack = mQueueStack.front();

		T value = stack->top();
		stack->pop();

		this->mSumSquare -= (value * value);
		this->mSum -= value;
		this->mCount--;

		if (stack->size() == 0)
		{
			delete stack;
			mQueueStack.pop();
		}

		if (this->mCount == 0)
		{
			this->mMin = std::numeric_limits<T>().max();
			this->mMax = std::numeric_limits<T>().lowest();
		}
		else
		{
			if (this->mMax == value)
			{
				mMaxStack.pop();
				this->mMax = mMaxStack.top();
			}

			if (this->mMin == value)
			{
				mMinStack.pop();
				this->mMin = mMaxStack.top();
			}
		}

		return value;
	}

	template<typename T>
	unsigned int QueueStack<T>::StackCount()
	{
		return mQueueStack.size();
	}

}
