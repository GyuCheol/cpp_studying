#pragma once

#include <cmath>

namespace utils
{
	template<typename T>
	T round(T number, T point)
	{
		T pow = static_cast<T>(std::pow(10, point));

		return std::round(number * pow) / pow;
	}
}