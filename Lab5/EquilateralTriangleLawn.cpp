#include "EquilateralTriangleLawn.h"

namespace lab5
{

	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int length)
		: mLength(length)
	{

	}

	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		double height = mLength * (std::sqrt(3) / 2);

		return (unsigned int) std::round(mLength * height / 2);
	}

	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		unsigned int meter = (unsigned int)(GetMinimumFencesCount() * 0.25);

		return meter * (fenceType == lab5::RED_CEDAR ? 6 : 7);
	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		return (unsigned int) std::ceil(mLength / 0.25) * 3;
	}

}