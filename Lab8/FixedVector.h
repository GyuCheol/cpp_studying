#pragma once

namespace lab8 {

	template <typename T, size_t N>
	class FixedVector {
	public:
		bool Add(T value);
		bool Remove(T find);
		const T& Get(unsigned int index);
		int GetIndex(T find);
		size_t GetSize();
		size_t GetCapacity();

		T& operator[](int index);

	private:
		T mValues[N];
		size_t mSIze = 0;

	};

	template<typename T, size_t N>
	bool FixedVector<T, N>::Add(T value)
	{
		if (mSIze == N)
		{
			return false;
		}

		mValues[mSIze] = value;

		mSIze++;

		return true;
	}

	template<typename T, size_t N>
	bool FixedVector<T, N>::Remove(T find)
	{
		int id = GetIndex(find);

		if (id == -1)
		{
			return false;
		}

		for (size_t i = id; i < mSIze - 1; i++)
		{
			mValues[i] = mValues[i+1];
		}

		mSIze--;

		return true;
	}

	template<typename T, size_t N>
	const T& FixedVector<T, N>::Get(unsigned int index)
	{
		return mValues[index];
	}

	template<typename T, size_t N>
	int FixedVector<T, N>::GetIndex(T find)
	{
		for (size_t i = 0; i < mSIze; i++)
		{
			if (find == mValues[i])
			{
				return i;
			}
		}

		return -1;
	}

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetSize()
	{
		return mSIze;
	}

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity()
	{
		return N;
	}

	template<typename T, size_t N>
	T& FixedVector<T, N>::operator[](int index)
	{
		return mValues[index];
	}

}

