#include <cstring>
#include <cmath>
#include <iostream>
#include "PolyLine.h"

namespace lab4
{
	
	PolyLine::PolyLine()
		: mPointCount(0)
	{
		mPointArray = new Point*[10];
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mPointCount(other.mPointCount)
	{
		mPointArray = new Point*[10];
		
		for (size_t i = 0; i < mPointCount; i++)
		{
			mPointArray[i] = new Point(other.mPointArray[i]->mX, other.mPointArray[i]->mY);
		}
	}

	PolyLine::~PolyLine()
	{
		for (size_t i = 0; i < mPointCount; i++)
		{
			delete mPointArray[i];
		}

		delete[] mPointArray;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mPointCount == MAX_COUNT)
		{
			return false;
		}

		mPointArray[mPointCount] = new Point(x, y);
		mPointCount++;

		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mPointCount == MAX_COUNT)
		{
			return false;
		}

		mPointArray[mPointCount] = (Point*) point;
		mPointCount++;

		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mPointCount)
		{
			return false;
		}

		for (size_t id = i; id < mPointCount - 1; id++)
		{
			mPointArray[id] = mPointArray[id + 1];
		}

		mPointCount--;

		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mPointCount == 0)
		{
			return false;
		}

		float minX = std::numeric_limits<float>::max();
		float minY = std::numeric_limits<float>::max();
		float maxX = std::numeric_limits<float>::lowest();
		float maxY = std::numeric_limits<float>::lowest();

		for (size_t i = 0; i < mPointCount; i++)
		{
			if (minX > mPointArray[i]->mX)
			{
				minX = mPointArray[i]->mX;
			}

			if (minY > mPointArray[i]->mY)
			{
				minY = mPointArray[i]->mY;
			}

			if (maxX < mPointArray[i]->mX)
			{
				maxX = mPointArray[i]->mX;
			}

			if (maxY < mPointArray[i]->mY)
			{
				maxY = mPointArray[i]->mY;
			}
		}

		outMin->mX = minX;
		outMin->mY = minY;

		outMax->mX = maxX;
		outMax->mY = maxY;

		return !((maxX - minX == 0) || (maxY - minY == 0));
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i >= mPointCount)
		{
			return NULL;
		}

		return mPointArray[i];
	}
}