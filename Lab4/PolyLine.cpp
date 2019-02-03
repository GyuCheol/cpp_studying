#include <cstring>
#include <cmath>
#include <iostream>
#include "PolyLine.h"

#define Min(a, b) a < b ? a : b
#define Max(a, b) a > b ? a : b

namespace lab4
{
	
	PolyLine::PolyLine()
		: mPointCount(0)
	{
	}

	PolyLine::PolyLine(const PolyLine& other)
		: PolyLine()
	{
		for (size_t i = 0; i < other.mPointCount; i++)
		{
			AddPoint(other.mPointArray[i]->mX, other.mPointArray[i]->mY);
		}
	}

	PolyLine::~PolyLine()
	{
		for (size_t i = 0; i < mPointCount; i++)
		{
			delete mPointArray[i];
		}
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

		mPointArray[mPointCount] = point;
		mPointCount++;

		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mPointCount)
		{
			return false;
		}

		delete mPointArray[i];

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

		float minX = std::numeric_limits<float>().max();
		float minY = std::numeric_limits<float>().max();
		float maxX = std::numeric_limits<float>().lowest();
		float maxY = std::numeric_limits<float>().lowest();

		for (size_t i = 0; i < mPointCount; i++)
		{
			minX = Min(minX, mPointArray[i]->mX);
			minY = Min(minY, mPointArray[i]->mY);
			maxX = Max(maxX, mPointArray[i]->mX);
			maxY = Max(maxY, mPointArray[i]->mY);
		}

		outMin->mX = minX;
		outMin->mY = minY;
		outMax->mX = maxX;
		outMax->mY = maxY;

		return true;
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