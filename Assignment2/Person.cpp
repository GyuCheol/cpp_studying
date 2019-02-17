#include "Person.h"

namespace assignment2
{
	Person::Person(const char* name, unsigned int weight)
		: mWeight(weight)
		, mName(std::string(name))
	{
	}

	Person::Person(const Person& person)
		: mWeight(person.GetWeight())
		, mName(std::string(person.GetName()))
	{
	}

	Person::~Person()
	{
	}

	const std::string& Person::GetName() const
	{
		return mName;
	}

	unsigned int Person::GetWeight() const
	{
		return mWeight;
	}
}