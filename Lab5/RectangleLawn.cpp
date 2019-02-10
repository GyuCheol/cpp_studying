#include "RectangleLawn.h"

namespace lab5
{

	unsigned int RectangleLawn::GetArea() const
	{
		return mHeight * mWidth;
	}

	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		unsigned int widthCount = (unsigned int) std::ceil(mWidth / 0.25);
		unsigned int heightCount = (unsigned int) std::ceil(mHeight / 0.25);

		return (widthCount * 2) + (heightCount * 2);
	}

	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		double meter = GetMinimumFencesCount() * 0.25;
		unsigned int price = fenceType == lab5::RED_CEDAR ? 6 : 7;

		return (unsigned int)meter * price;
	}

	RectangleLawn::RectangleLawn(unsigned int width, unsigned height)
		: mWidth(width)
		, mHeight(height)
	{
	}

}
