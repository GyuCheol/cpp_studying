#include <cassert>
#include <sstream>

#include "Lab7.h"

int main()
{
	std::vector<int> emptyIntVector;
	std::vector<char> emptyCharVecor;
	std::map<char, int> emptyMap;

	std::vector<char> vectorLetter1;
	vectorLetter1.push_back('a');
	vectorLetter1.push_back('b');
	vectorLetter1.push_back('c');

	std::vector<char> vectorLetter2;
	vectorLetter2.push_back('a');
	vectorLetter2.push_back('b');
	vectorLetter2.push_back('c');
	vectorLetter2.push_back('a');

	std::vector<int> vectorInteger1;
	vectorInteger1.push_back(1);
	vectorInteger1.push_back(2);
	vectorInteger1.push_back(3);

	std::vector<int> vectorInteger2;
	vectorInteger2.push_back(1);
	vectorInteger2.push_back(2);
	vectorInteger2.push_back(3);
	vectorInteger2.push_back(4);

	std::vector<int> vectorInteger3;
	vectorInteger3.push_back(1);
	vectorInteger3.push_back(2);
	vectorInteger3.push_back(3);
	vectorInteger3.push_back(4);
	vectorInteger3.push_back(1);

	std::vector<int> vectorInteger4;
	vectorInteger4.push_back(2);
	vectorInteger4.push_back(6);
	vectorInteger4.push_back(5);
	vectorInteger4.push_back(4);
	vectorInteger4.push_back(7);
	vectorInteger4.push_back(5);

	std::map<char, int> map1;
	map1['a'] = 1;
	map1['b'] = 2;
	map1['c'] = 3;

	std::map<char, int> map2;
	map2['d'] = 4;
	map2['e'] = 5;
	map2['f'] = 6;

	std::map<char, int> map3;
	map3['a'] = 4;
	map3['b'] = 5;
	map3['f'] = 6;

	std::map<char, int> mapTest1 = lab7::ConvertVectorsToMap(vectorLetter1, vectorInteger1);
	{
		std::map<char, int>::const_iterator it = mapTest1.begin();
		assert(it->first == 'a');
		assert(it->second == 1);
		it++;
		assert(it->first == 'b');
		assert(it->second == 2);
		it++;
		assert(it->first == 'c');
		assert(it->second == 3);
	}
	std::cout << "Test ConvertVectorsToMap() - normal data: PASS" << std::endl;

	std::map<char, int> mapTest2 = lab7::ConvertVectorsToMap(emptyCharVecor, emptyIntVector);
	{
		std::map<char, int>::const_iterator it = mapTest2.begin();
		assert(it == mapTest2.end());
	}
	std::cout << "Test ConvertVectorsToMap() - empty vectors: PASS" << std::endl;

	std::map<char, int> mapTest3 = lab7::ConvertVectorsToMap(vectorLetter1, vectorInteger2);
	{
		std::map<char, int>::const_iterator it = mapTest3.begin();
		assert(it->first == 'a');
		assert(it->second == 1);
		it++;
		assert(it->first == 'b');
		assert(it->second == 2);
		it++;
		assert(it->first == 'c');
		assert(it->second == 3);
		it++;
		assert(it == mapTest3.end());
	}
	std::cout << "Test ConvertVectorsToMap() - vales are longger than keys: PASS" << std::endl;

	std::map<char, int> mapTest4 = lab7::ConvertVectorsToMap(vectorLetter2, vectorInteger2);
	{
		std::map<char, int>::const_iterator it = mapTest4.begin();
		assert(it->first == 'a');
		assert(it->second == 1);
		it++;
		assert(it->first == 'b');
		assert(it->second == 2);
		it++;
		assert(it->first == 'c');
		assert(it->second == 3);
		it++;
		assert(it == mapTest4.end());
	}
	std::cout << "Test ConvertVectorsToMap() - duplicated keys: PASS" << std::endl;

	std::vector<char> keysTest1 = lab7::GetKeys(map1);
	{
		std::vector<char>::const_iterator it = keysTest1.begin();

		assert(*it == 'a');
		it++;
		assert(*it == 'b');
		it++;
		assert(*it == 'c');
	}
	std::cout << "Test GetKeys() - normal data: PASS" << std::endl;

	std::vector<char> keysTest2 = lab7::GetKeys(emptyMap);
	{
		std::vector<char>::const_iterator it = keysTest2.begin();
		assert(it == keysTest2.end());
	}
	std::cout << "Test GetKeys() - empty map: PASS" << std::endl;

	std::vector<int> valuesTest1 = lab7::GetValues(map1);
	{
		std::vector<int>::const_iterator it = valuesTest1.begin();

		assert(*it == 1);
		it++;
		assert(*it == 2);
		it++;
		assert(*it == 3);
	}
	std::cout << "Test GetValues() - normal data: PASS" << std::endl;

	std::vector<int> valuesTest2 = lab7::GetValues(emptyMap);
	{
		std::vector<int>::const_iterator it = valuesTest2.begin();

		assert(it == valuesTest2.end());
	}
	std::cout << "Test GetValues() - empty map: PASS" << std::endl;

	std::vector<int> reversedV1 = lab7::Reverse(vectorInteger1);
	{
		assert(reversedV1[0] == vectorInteger1[2]);
		assert(reversedV1[1] == vectorInteger1[1]);
		assert(reversedV1[2] == vectorInteger1[0]);
	}
	std::cout << "Test Reverse() - normal data: PASS" << std::endl;

	std::vector<int> reversedV2 = lab7::Reverse(emptyIntVector);
	{
		assert(reversedV2.empty() == true);
	}
	std::cout << "Test Reverse() - empty vector: PASS" << std::endl;

	std::vector<int> combinedVector1 = vectorInteger3 + vectorInteger4;
	{
		assert(combinedVector1.size() == 7);
		assert(combinedVector1[0] == 1);
		assert(combinedVector1[1] == 2);
		assert(combinedVector1[2] == 3);
		assert(combinedVector1[3] == 4);
		assert(combinedVector1[4] == 6);
		assert(combinedVector1[5] == 5);
		assert(combinedVector1[6] == 7);
	}
	std::cout << "Test operator+(vector, vector) - normal data: PASS" << std::endl;

	std::vector<int> combinedVector2 = emptyIntVector + emptyIntVector;
	{
		assert(combinedVector2.empty() == true);
	}
	std::vector<int> combinedVector3 = vectorInteger1 + emptyIntVector;
	{
		assert(combinedVector3.size() == 3);
		assert(combinedVector3[0] == 1);
		assert(combinedVector3[1] == 2);
		assert(combinedVector3[2] == 3);
	}
	std::vector<int> combinedVector4 = emptyIntVector + vectorInteger2;
	{
		assert(combinedVector4.size() == 4);
		assert(combinedVector4[0] == 1);
		assert(combinedVector4[1] == 2);
		assert(combinedVector4[2] == 3);
		assert(combinedVector4[3] == 4);
	}
	std::cout << "Test operator+(vector, vector) - empty vectors: PASS" << std::endl;

	std::map<char, int> combinedMap1 = map1 + map2;
	{
		std::map<char, int>::const_iterator it = combinedMap1.begin();

		assert(combinedMap1.size() == 6);

		assert(it->first == 'a');
		assert(it->second == 1);
		it++;
		assert(it->first == 'b');
		assert(it->second == 2);
		it++;
		assert(it->first == 'c');
		assert(it->second == 3);
		it++;
		assert(it->first == 'd');
		assert(it->second == 4);
		it++;
		assert(it->first == 'e');
		assert(it->second == 5);
		it++;
		assert(it->first == 'f');
		assert(it->second == 6);
	}
	std::cout << "Test operator+(map, map) - normal data: PASS" << std::endl;

	std::map<char, int> combinedMap2 = emptyMap + emptyMap;
	{
		std::map<char, int>::const_iterator it = combinedMap2.begin();

		assert(combinedMap2.empty() == true);
	}
	std::map<char, int> combinedMap3 = map1 + emptyMap;
	{
		std::map<char, int>::const_iterator map3It = combinedMap3.begin();
		std::map<char, int>::const_iterator map1It = map1.begin();

		assert(combinedMap3.size() == map1.size());

		assert(map3It->first == map1It->first);
		assert(map3It->second == map1It->second);
		map3It++;
		map1It++;
		assert(map3It->first == map1It->first);
		assert(map3It->second == map1It->second);
		map3It++;
		map1It++;
		assert(map3It->first == map1It->first);
		assert(map3It->second == map1It->second);
		map3It++;
		map1It++;
		assert(map3It == combinedMap3.end());
		assert(map1It == map1.end());
	}
	std::map<char, int> combinedMap4 = emptyMap + map2;
	{
		std::map<char, int>::const_iterator map4It = combinedMap4.begin();
		std::map<char, int>::const_iterator map2It = map2.begin();

		assert(combinedMap4.size() == map2.size());

		assert(map4It->first == map2It->first);
		assert(map4It->second == map2It->second);
		map4It++;
		map2It++;
		assert(map4It->first == map2It->first);
		assert(map4It->second == map2It->second);
		map4It++;
		map2It++;
		assert(map4It->first == map2It->first);
		assert(map4It->second == map2It->second);
		map4It++;
		map2It++;
		assert(map4It == combinedMap4.end());
		assert(map2It == map2.end());
	}
	std::cout << "Test operator+(map, map) - empty map: PASS" << std::endl;

	std::map<char, int> combinedMap5 = map1 + map3;
	{
		std::map<char, int>::const_iterator it = combinedMap5.begin();

		assert(combinedMap5.size() == 4);

		assert(it->first == 'a');
		assert(it->second == 1);
		it++;
		assert(it->first == 'b');
		assert(it->second == 2);
		it++;
		assert(it->first == 'c');
		assert(it->second == 3);
		it++;
		assert(it->first == 'f');
		assert(it->second == 6);
	}
	std::cout << "Test operator+(map, map) - duplicated map: PASS" << std::endl;

	std::ostringstream oss1;
	oss1 << vectorInteger1;
	assert(oss1.str() == "1, 2, 3");
	std::cout << "Test operator<<(os, vector) - normal data: PASS" << std::endl;
	oss1 << emptyIntVector;
	assert(oss1.str() == "1, 2, 3");
	std::cout << "Test operator<<(os, vector) - empty vector: PASS" << std::endl;

	std::ostringstream oss2;
	oss2 << map1;
	assert(oss2.str() == "{ a, 1 }\n{ b, 2 }\n{ c, 3 }\n");
	std::cout << "Test operator<<(os, map) - normal data: PASS" << std::endl;
	oss2 << emptyMap;
	assert(oss2.str() == "{ a, 1 }\n{ b, 2 }\n{ c, 3 }\n");
	std::cout << "Test operator<<(os, map) - empty map: PASS" << std::endl;

	return 0;
}