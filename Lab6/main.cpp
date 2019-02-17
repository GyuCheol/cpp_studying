#include <iostream>
#include <vector>

int main()
{
	std::vector<int> scores;

	scores.reserve(2);

	scores.push_back(30);
	scores.push_back(50);

	scores.pop_back();

	std::cout << scores.capacity();
	std::cout << std::endl;
	std::cout << scores.size();

}