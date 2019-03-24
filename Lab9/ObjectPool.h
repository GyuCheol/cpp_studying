#pragma once

#include <vector>

namespace lab9
{

	template<typename T>
	class ObjectPool
	{
	public:
		ObjectPool(size_t maxPoolSize);
		ObjectPool(const ObjectPool& pool) = delete;
		~ObjectPool();
		T* Get();
		void Return(T* ptr);
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();

	private:
		size_t mMaxPoolSize;
		std::vector<T*> mFreeObjects;
	};


	template<typename T> ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mMaxPoolSize(maxPoolSize)
	{
		mFreeObjects.reserve(maxPoolSize);
	}

	template<typename T>
	ObjectPool<T>::~ObjectPool()
	{
		for (auto it = mFreeObjects.begin(); it != mFreeObjects.end(); it++)
		{
			delete *it;
		}
	}

	template<typename T>
	T * ObjectPool<T>::Get()
	{
		if (GetFreeObjectCount() == 0)
		{
			return new T();
		}
		
		T* back = *mFreeObjects.rbegin();
		mFreeObjects.pop_back();

		return back;
	}

	template<typename T>
	void ObjectPool<T>::Return(T * ptr)
	{
		mFreeObjects.push_back(ptr);
	}

	template<typename T>
	size_t ObjectPool<T>::GetFreeObjectCount()
	{
		return mFreeObjects.size();
	}

	template<typename T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount()
	{
		return mMaxPoolSize;
	}

}