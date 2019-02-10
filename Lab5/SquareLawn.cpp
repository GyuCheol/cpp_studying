#include "SquareLawn.h"

namespace lab5
{

	SquareLawn::SquareLawn(unsigned int length)
		: mLength(length)
	{

	}

	unsigned int SquareLawn::GetArea() const
	{
		return mLength * mLength;
	}

	unsigned int SquareLawn::GetFencePrice(eFenceType fenceType) const
	{
		unsigned int meter = (unsigned int)(GetMinimumFencesCount() * 0.25);

		return meter * (fenceType == lab5::RED_CEDAR ? 6 : 7);
	}

	unsigned int SquareLawn::GetMinimumFencesCount() const
	{
		return std::ceil(mLength / 0.25) * 4;
	}



}
