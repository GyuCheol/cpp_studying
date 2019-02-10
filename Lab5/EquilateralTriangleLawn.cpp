#include "EquilateralTriangleLawn.h"

namespace lab5
{

	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int length)
		: mLength(length)
	{

	}

	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		return (unsigned int) (mLength * mLength / 2);
	}

	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		unsigned int meter = (unsigned int)(GetMinimumFencesCount() * 0.25);

		return meter * (fenceType == lab5::RED_CEDAR ? 6 : 7);
	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		int lengthCount = GetSizeCountEachLengthByCm(mLength * 100, 30);

		return lengthCount * 3;
	}

}