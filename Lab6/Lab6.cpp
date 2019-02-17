#include "Lab6.h"
#include <map>

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int total = 0;
		int size = v.size();

		for (int i = 0; i < size; i++)
		{
			total += v[i];
		}
		
		return total;
	}

	int Min(const std::vector<int>& v)
	{
		int min = INT32_MAX;
		int size = v.size();

		for (int i = 0; i < size; i++)
		{
			if (min > v[i])
			{
				min = v[i];
			}
		}

		return min;
	}

	int Max(const std::vector<int>& v)
	{
		int max = INT32_MIN;
		int size = v.size();

		for (int i = 0; i < size; i++)
		{
			if (max < v[i])
			{
				max = v[i];
			}
		}

		return max;
	}

	float Average(const std::vector<int>& v)
	{
		int size = v.size();

		if (size == 0)
		{
			return 0.f;
		}
		
		return (float)Sum(v) / size;
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		int size = v.size();
		int max = INT32_MIN;
		int maxKey;
		std::map<int, int> map;

		if (size == 0)
		{
			return 0;
		}

		for (int i = 0; i < size; i++)
		{
			if (map.find(v[i]) == map.end())
			{
				map[v[i]] = 1;
			}
			else
			{
				map[v[i]]++;
			}

			if (max < map[v[i]])
			{
				maxKey = v[i];
				max = map[v[i]];
			}
		}

		return maxKey;
	}

	void SortDescending(std::vector<int>& v)
	{
		int size = v.size();

		// selection sort
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i; j < size; j++)
			{
				if (v[i] < v[j])
				{
					int tmp = v[i];

					v[i] = v[j];
					v[j] = tmp;
				}
			}
		}
	}

}