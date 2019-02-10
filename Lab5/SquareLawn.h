#pragma once
#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{

	class SquareLawn : public Lawn, public IFenceable
	{
	public:
		SquareLawn(unsigned int length);
		unsigned int GetArea() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
		unsigned int GetMinimumFencesCount() const;

	private:
		unsigned int mLength;
	};

}