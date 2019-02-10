#include "RectangleLawn.h"

namespace lab5
{

	unsigned int RectangleLawn::GetArea() const
	{
		return mHeight * mWidth;
	}

	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		return (unsigned int) (std::ceil(mWidth / 0.25) * 2) + (std::ceil(mHeight / 0.25) * 2);
	}

	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		return (unsigned int) (GetMinimumFencesCount() * 0.25) * (fenceType == lab5::RED_CEDAR ? 6 : 7);
	}

	RectangleLawn::RectangleLawn(unsigned int width, unsigned height)
		: mWidth(width)
		, mHeight(height)
	{
	}

}
