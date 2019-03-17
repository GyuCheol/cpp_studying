#pragma once

#include <cmath>

namespace assignment3
{
	template<typename T>
	T round(T number)
	{
		return static_cast<T>(std::round(number * 1000) / 1000);
	}
}