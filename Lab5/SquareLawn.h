#pragma once
#include "RectangleLawn.h"
#include "IFenceable.h"

namespace lab5
{

	class SquareLawn : public RectangleLawn
	{
	public:
		SquareLawn(unsigned int length);

	};

}