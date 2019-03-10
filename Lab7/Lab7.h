#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <set>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;

		typename std::vector<K>::const_iterator itKey = keys.begin();
		typename std::vector<V>::const_iterator itValue = values.begin();

		while (itKey != keys.end() && itValue != values.end())
		{
			if (m.find(*itKey) == m.end())
			{
				m.insert(std::pair<K, V>(*itKey, *itValue));
			}

			itKey++;
			itValue++;
		}

		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;
		typename std::map<K, V>::const_iterator it = m.begin();
		
		while (it != m.end())
		{
			v.push_back(it->first);

			it++;
		}

		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;
		typename std::map<K, V>::const_iterator it = m.begin();

		while (it != m.end())
		{
			v.push_back(it->second);

			it++;
		}

		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;
		typename std::vector<T>::const_reverse_iterator it = v.rbegin();

		while (it != v.rend())
		{
			rv.push_back(*it);
			it++;
		}

		return rv;
	}
}

template <typename T>
std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
{
	std::vector<T> combined;
	std::set<T> set;
	const std::vector<T>* vectorArray[2] = { &v1, &v2};
	
	for (size_t i = 0; i < 2; i++)
	{
		const std::vector<T>* v = vectorArray[i];
		typename std::vector<T>::const_iterator it = v->begin();

		while (it != v->end())
		{
			if (set.find(*it) == set.end())
			{
				set.insert(*it);
				combined.push_back(*it);
			}

			it++;
		}

	}

	return combined;
}

template <typename K, class V>
std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
{
	std::map<K, V> combined;
	const std::map<K, V>* mapArray[] = { &m1, &m2 };

	for (size_t i = 0; i < 2; i++)
	{
		const std::map<K, V>* map = mapArray[i];
		typename std::map<K, V>::const_iterator it = map->begin();

		while (it != map->end())
		{
			if (combined.find(it->first) == combined.end())
			{
				combined.insert(*it);
			}

			it++;
		}
	}

	return combined;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
	typename std::vector<T>::const_iterator it = v.begin();

	if (it == v.end())
	{
		return os;
	}

	while (true)
	{
		os << *it;

		it++;

		if (it == v.end())
		{
			break;
		}

		os << ", ";
	}


	return os;
}

template <typename K, class V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
{
	typename std::map<K, V>::const_iterator it = m.begin();

	while (it != m.end())
	{
		os << "{ " << it->first << ", " << it->second << " }" << std::endl;

		it++;
	}

	return os;
}