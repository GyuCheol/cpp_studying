#pragma once

#include <queue>

namespace lab9
{

	template<typename T>
	class ObjectPool
	{
	public:
		ObjectPool(size_t maxPoolSize);
		ObjectPool(const ObjectPool& pool) = delete;
		ObjectPool& operator=(const ObjectPool&) = delete;
		~ObjectPool();
		T* Get();
		void Return(T* ptr);
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();

	private:
		size_t mMaxPoolSize;
		std::queue<T*> mFreeObjectQueue;
	};


	template<typename T> ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mMaxPoolSize(maxPoolSize)
	{
	}

	template<typename T> ObjectPool<T>::~ObjectPool()
	{
		while (mFreeObjectQueue.empty() == false)
		{
			delete mFreeObjectQueue.front();
			mFreeObjectQueue.pop();
		}
	}

	template<typename T>
	T* ObjectPool<T>::Get()
	{
		if (GetFreeObjectCount() == 0)
		{
			return new T();
		}
		
		T* back = mFreeObjectQueue.front();
		mFreeObjectQueue.pop();

		return back;
	}

	template<typename T>
	void ObjectPool<T>::Return(T* ptr)
	{
		if (GetFreeObjectCount() == mMaxPoolSize)
		{
			delete ptr;
			return;
		}

		mFreeObjectQueue.push(ptr);
	}

	template<typename T>
	size_t ObjectPool<T>::GetFreeObjectCount()
	{
		return mFreeObjectQueue.size();
	}

	template<typename T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount()
	{
		return mMaxPoolSize;
	}

}