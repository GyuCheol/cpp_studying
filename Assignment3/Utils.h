#pragma once

#include <cmath>

namespace assignment3
{
	template<typename T>
	T round(T number)
	{
		return static_cast<T>(std::round((double)number * 1000.0) / 1000.0);
	}
}