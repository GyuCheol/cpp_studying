#pragma once
#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{

	class RectangleLawn : public Lawn, public IFenceable
	{
	public:
		RectangleLawn(unsigned int width, unsigned height);

		unsigned int Lawn::GetArea() const;

		unsigned int IFenceable::GetMinimumFencesCount() const;
		unsigned int IFenceable::GetFencePrice(eFenceType fenceType) const;

	protected:
		unsigned int mWidth;
		unsigned int mHeight;

	};
}