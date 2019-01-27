#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
		: mLength(0)
		, mCapacity(32)
	{
		mCharArray = new char[mCapacity];
		mCharArray[0] = '\0';
		Append(s);
	}

	MyString::MyString(const MyString& other)
		: mLength(0)
		, mCapacity(other.mCapacity)
	{
		mCharArray = new char[mCapacity];
		Append(other.GetCString());
	}

	MyString::~MyString()
	{
		delete[] mCharArray;
	}

	unsigned int MyString::GetLength() const
	{
		return mLength;
	}

	const char* MyString::GetCString() const
	{
		return mCharArray;
	}

	size_t MyString::strLen(const char* s)
	{
		int len = 0;

		while (s[len] != '\0')
		{
			len++;
		}

		return len;
	}

	void MyString::strSet(char* src, const char val, size_t size)
	{
		for (size_t i = 0; i < size; i++)
		{
			src[i] = val;
		}
	}

	void MyString::strCopy(char* dst, const char* src, size_t size)
	{
		for (size_t i = 0; i < size; i++)
		{
			dst[i] = src[i];
		}
	}

	void MyString::Append(const char* s)
	{
		int len = strLen(s);

		if (len == 0)
		{
			return;
		}

		// 같아야 capacity를 가능한 허용치를 2배수로 늘림.
		// 맨 마지막 문자가 \0니깐.
		if ((mLength + len) >= mCapacity)
		{
			size_t tmpCapa = mCapacity * 2;

			while (tmpCapa < (mLength + len))
			{
				tmpCapa *= 2;
			}

			char* newMem = new char[tmpCapa];
			
			strCopy(newMem, mCharArray, mLength);
			strCopy(&newMem[mLength], s, len);

			delete[] mCharArray;

			mCharArray = newMem;
			mCapacity = tmpCapa;
		}
		else 
		{
			strCopy(&mCharArray[mLength], s, len);
		}

		mLength += len;
		mCharArray[mLength] = '\0';
	}

	MyString MyString::operator+(const MyString& other) const
	{
		MyString clone(*this);

		clone.Append(other.GetCString());
		
		return clone;
	}

	int MyString::IndexOf(const char* s)
	{
		size_t subLen = strLen(s);

		if (mLength < subLen)
		{
			return -1;
		}

		for (size_t i = 0; i <= mLength - subLen; i++)
		{
			int cLen = 0;

			for (size_t j = 0; j < subLen; j++)
			{
				if (mCharArray[i + j] == s[j])
				{
					cLen++;
				}
			}

			if (cLen == subLen)
			{
				return i;
			}
		}

		return -1;
	}

	int MyString::LastIndexOf(const char* s)
	{
		size_t subLen = strLen(s);

		if (mLength < subLen)
		{
			return -1;
		}

		for (int i = mLength - subLen; i >= 0; i--)
		{
			int cLen = 0;

			for (int j = 0; j < subLen; j++)
			{
				if (mCharArray[i + j] == s[j])
				{
					cLen++;
				}
			}

			if (cLen == subLen)
			{
				return i;
			}
		}

		return -1;
	}

	void MyString::clear()
	{
		mLength = 0;
		mCharArray[0] = '\0';
	}

	void MyString::Interleave(const char* s)
	{
		size_t subStrLen = strLen(s);

		if (subStrLen == 0)
		{
			return;
		}

		MyString clone(*this);
		const char* cloneCharArray = clone.GetCString();
		size_t strLen = clone.mLength;
		size_t subStrId = 0;
		size_t strId = 0;
		size_t id = 0;
		char* tmpArray = new char[subStrLen + strLen + 1];

		tmpArray[subStrLen + strLen] = '\0';

		clear();

		while (strId < strLen || subStrId < subStrLen)
		{
			if (strId < strLen)
			{
				tmpArray[id] = cloneCharArray[strId];
				strId++;
				id++;
			}

			if (subStrId < subStrLen)
			{
				tmpArray[id] = s[subStrId];
				subStrId++;
				id++;
			}
		}

		Append(tmpArray);
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		if (index >= mLength)
		{
			return false;
		}

		strCopy(&mCharArray[index], &mCharArray[index + 1], mLength - index);
		mLength--;

		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		PadLeft(totalLength, ' ');
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		int len = totalLength - mLength;
		MyString clone(*this);

		if (len < 0)
		{
			return;
		}

		char* pad = new char[len + 1];

		pad[len] = '\0';

		clear();

		strSet(pad, c, len);

		Append(pad);
		Append(clone.GetCString());
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		PadRight(totalLength, ' ');
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		int len = totalLength - mLength;
		MyString clone(*this);

		if (len < 0)
		{
			return;
		}

		char* pad = new char[len + 1];

		pad[len] = '\0';

		clear();

		strSet(pad, c, len);

		Append(clone.GetCString());
		Append(pad);
	}

	void MyString::Reverse()
	{
		if (mLength == 0)
		{
			return;
		}

		size_t left = 0;
		size_t right = mLength - 1;

		while (left < right)
		{
			char tmp = mCharArray[left];

			mCharArray[left] = mCharArray[right];
			mCharArray[right] = tmp;

			left++;
			right--;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		if (mLength != rhs.mLength)
		{
			return false;
		}

		for (size_t i = 0; i < mLength; i++)
		{
			if (mCharArray[i] != rhs.mCharArray[i])
			{
				return false;
			}
		}

		return true;
	}

	void MyString::ToLower()
	{
		for (size_t i = 0; i < mLength; i++)
		{
			if (mCharArray[i] >= 'A' && mCharArray[i] <= 'Z')
			{
				mCharArray[i] = mCharArray[i] + 32;
			}
		}
	}

	void MyString::ToUpper()
	{
		for (size_t i = 0; i < mLength; i++)
		{
			if (mCharArray[i] >= 'a' && mCharArray[i] <= 'z')
			{
				mCharArray[i] = mCharArray[i] - 32;
			}
		}
	}
}