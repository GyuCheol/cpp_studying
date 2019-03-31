#include <cassert>
#include "DoublyLinkedList.h"
#include "Node.h"

using namespace lab10;

void test1()
{
	DoublyLinkedList<int> list;

	assert(list[1] == nullptr);

	list.Insert(std::make_unique<int>(7));
	assert(*list[0]->Data == 7);

	list.Insert(std::make_unique<int>(6), 0);
	assert(*list[0]->Data == 6);

	list.Insert(std::make_unique<int>(5), 0);
	assert(*list[0]->Data == 5);

	list.Insert(std::make_unique<int>(4), 0);
	assert(*list[0]->Data == 4);

	list.Insert(std::make_unique<int>(3), 0);
	assert(*list[0]->Data == 3);

	list.Insert(std::make_unique<int>(2), 0);
	assert(*list[0]->Data == 2);

	list.Insert(std::make_unique<int>(1), 0);
	assert(*list[0]->Data == 1);

	list.Insert(std::make_unique<int>(8), 7);
	assert(*list[7]->Data == 8);

	assert(list.Delete(5));
	assert(list.Delete(4));
	assert(list.Delete(3));
	assert(list.Delete(2));
	assert(list.Delete(6));
	assert(list.Delete(7));
	assert(list.Delete(8));
	assert(list.Delete(1));

}

void test3()
{
	DoublyLinkedList<int> list;

	for (size_t i = 0; i < 8; i++)
	{
		list.Insert(std::make_unique<int>(i));
	}

	for (size_t i = 0; i < 8; i++)
	{
		assert(list.Delete(i));
	}

}

void test2()
{
	DoublyLinkedList<int> list;

	list.Insert(std::make_unique<int>(1));
	list.Insert(std::make_unique<int>(2), 5);
	list.Insert(std::make_unique<int>(3));
	list.Insert(std::make_unique<int>(4));
	list.Insert(std::make_unique<int>(5));
	list.Insert(std::make_unique<int>(6));
	list.Insert(std::make_unique<int>(7));

	assert(list.Search(1));
	assert(list.Search(2));
	assert(list.Search(3));
	assert(list.Search(4));
	assert(list.Search(111) == false);

	bool bSearched = list.Search(4);
	assert(bSearched);

	bSearched = list.Search(10);
	assert(!bSearched);

	unsigned int size = list.GetLength();
	assert(size == 7);

	bool bDeleted = list.Delete(3);
	assert(bDeleted);

	bDeleted = list.Delete(3);
	assert(!bDeleted);

	size = list.GetLength();
	assert(size == 6);

	std::shared_ptr<Node<int>> node = list[2];
	assert(*node->Data == 4);

	list.Insert(std::make_unique<int>(10), 2);

	node = list[2];
	assert(*node->Data == 10);
}

int main()
{
	test2();
	test1();
	test3();

	return 0;
}