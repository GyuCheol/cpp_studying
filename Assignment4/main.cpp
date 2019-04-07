#include <memory>
#include <iostream>
#include <vector>
#include <cassert>

#include "BinarySearchTree.h"

using namespace assignment4;

template<typename T>
void printVector(const std::vector<T>& v)
{
	for (auto it : v)
	{
		std::cout << it << " ";
	}

	std::cout << std::endl;
}

void test1()
{
	BinarySearchTree<int> tree;

	tree.Insert(std::make_unique<int>(3));
	tree.Insert(std::make_unique<int>(1));
	tree.Insert(std::make_unique<int>(4));

	assert(tree.Search(1) == true);
	assert(tree.Search(2) == false);
	assert(tree.Search(3) == true);
	assert(tree.Search(4) == true);
	assert(tree.Search(5) == false);

	assert(tree.Delete(3) == true);

	assert(tree.GetRootNode().lock()->Parent.expired());

	auto v = tree.TraverseInOrder(tree.GetRootNode().lock());

	assert(v[0] == 1);
	assert(v[1] == 4);

	tree.Insert(std::make_unique<int>(5));
	tree.Insert(std::make_unique<int>(100));

	v = tree.TraverseInOrder(tree.GetRootNode().lock());

	assert(v.size() == 4);
	assert(v[0] == 1);
	assert(v[1] == 4);
	assert(v[2] == 5);
	assert(v[3] == 100);
}

void test3()
{
	BinarySearchTree<int> tree;

	tree.Insert(std::make_unique<int>(10));
	tree.Insert(std::make_unique<int>(15));
	tree.Insert(std::make_unique<int>(5));
	tree.Insert(std::make_unique<int>(6));
	tree.Insert(std::make_unique<int>(4));
	tree.Insert(std::make_unique<int>(19));
	tree.Insert(std::make_unique<int>(20));
	tree.Insert(std::make_unique<int>(17));
	tree.Insert(std::make_unique<int>(12));
	tree.Insert(std::make_unique<int>(11));
	tree.Insert(std::make_unique<int>(14));

	printVector(tree.TraverseInOrder(tree.GetRootNode().lock()));
	tree.Delete(10);
	printVector(tree.TraverseInOrder(tree.GetRootNode().lock()));
	tree.Delete(5);
	printVector(tree.TraverseInOrder(tree.GetRootNode().lock()));
	tree.Delete(15);
	printVector(tree.TraverseInOrder(tree.GetRootNode().lock()));

}

void test2()
{
	BinarySearchTree<int> tree;

	tree.Insert(std::make_unique<int>(10));
	tree.Insert(std::make_unique<int>(15));
	tree.Insert(std::make_unique<int>(5));
	tree.Insert(std::make_unique<int>(4));
	tree.Insert(std::make_unique<int>(19));
	tree.Insert(std::make_unique<int>(20));
	tree.Insert(std::make_unique<int>(17));
	tree.Insert(std::make_unique<int>(12));

	std::vector<int> v = tree.TraverseInOrder(tree.GetRootNode().lock());

	assert(v.size() == 8);
	assert(v[0] == 4);
	assert(v[1] == 5);
	assert(v[2] == 10);
	assert(v[3] == 12);
	assert(v[4] == 15);
	assert(v[5] == 17);
	assert(v[6] == 19);
	assert(v[7] == 20);

	bool bSearched = tree.Search(15);
	assert(bSearched);

	bool bDeleted = tree.Delete(6);
	assert(!bDeleted);

	bDeleted = tree.Delete(100);
	assert(!bDeleted);

	bDeleted = tree.Delete(15);
	assert(bDeleted);

	v = tree.TraverseInOrder(tree.GetRootNode().lock());

	assert(v.size() == 7);
	assert(v[0] == 4);
	assert(v[1] == 5);
	assert(v[2] == 10);
	assert(v[3] == 12);
	assert(v[4] == 17);
	assert(v[5] == 19);
	assert(v[6] == 20);

	bSearched = tree.Search(15);
	assert(!bSearched);
}

int main()
{
	test1();
	test2();
	test3();
}