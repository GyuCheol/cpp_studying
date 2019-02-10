#include "RectangleLawn.h"

namespace lab5
{

	unsigned int RectangleLawn::GetArea() const
	{
		return mHeight * mWidth;
	}

	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		int widthCount = GetSizeCountEachLengthByCm(mWidth * 100, 25);
		int heightCount = GetSizeCountEachLengthByCm(mHeight * 100, 25);

		return (widthCount * 2) + (heightCount * 2);
	}

	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		unsigned int meter = (unsigned int) (GetMinimumFencesCount() * 0.25);

		return meter * (fenceType == lab5::RED_CEDAR ? 6 : 7);
	}

	RectangleLawn::RectangleLawn(unsigned int width, unsigned height)
		: mWidth(width)
		, mHeight(height)
	{
	}

}
