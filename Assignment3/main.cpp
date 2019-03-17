#include <cassert>
#include <iostream>
#include <limits>

#include "SmartStack.h"
#include "SmartQueue.h"
#include "QueueStack.h"

using namespace assignment3;

void test1()
{
	SmartStack<float> ss;

	ss.Push(3.4f);
	ss.Push(1.2f);
	ss.Push(4.6f);
	ss.Push(3.32f);
	ss.Push(10.2f);
	ss.Push(1.1f);
	ss.Push(-5.9f);
	ss.Push(1.1f);
	ss.Push(-12.4f);
	ss.Push(9.2f);

	assert(ss.Count() == 10U);
	assert(ss.Peek() == 9.2f);
	assert(ss.Max() == 10.2f);
	assert(ss.Min() == -12.4f);
	assert(ss.Sum() == 15.820f);
	assert(ss.Average() == 1.582);
	assert(ss.Variance() == 39.983);
	assert(ss.StandardDeviation() == 6.323);
	assert(ss.Peek() == 9.2f);

	float popped1 = ss.Pop();
	float popped2 = ss.Pop();

	assert(popped1 == 9.2f);
	assert(popped2 == -12.4f);

	size_t size = ss.Count();

	for (size_t i = 0; i < size; i++)
	{
		ss.Pop();
	}

	ss.Push(1.0f);
	ss.Push(5.0f);

	assert(ss.Peek() == 5.0f);
	assert(ss.Max() == 5.0f);
	assert(ss.Min() == 1.0f);

	assert(ss.Pop() == 5.0f);
	assert(ss.Max() == 1.0f);
	assert(ss.Min() == 1.0f);
}


void test2()
{
	SmartQueue<float> ss;

	ss.Enqueue(3.4f);
	ss.Enqueue(1.2f);
	ss.Enqueue(4.6f);
	ss.Enqueue(3.32f);
	ss.Enqueue(10.2f);
	ss.Enqueue(1.1f);
	ss.Enqueue(-5.9f);
	ss.Enqueue(1.1f);
	ss.Enqueue(-12.4f);
	ss.Enqueue(9.2f);

	assert(ss.Count() == 10U);
	assert(ss.Peek() == 3.4f);
	assert(ss.Max() == 10.2f);
	assert(ss.Min() == -12.4f);
	assert(ss.Sum() == 15.820f);
	assert(ss.Average() == 1.582);
	assert(ss.Variance() == 39.983);
	assert(ss.StandardDeviation() == 6.323);
	assert(ss.Peek() == 3.4f);

	float popped1 = ss.Dequeue();
	float popped2 = ss.Dequeue();

	assert(popped1 == 3.4f);
	assert(popped2 == 1.2f);

	size_t size = ss.Count();

	for (size_t i = 0; i < size; i++)
	{
		ss.Dequeue();
	}

	ss.Enqueue(1.0f);
	ss.Enqueue(5.0f);

	assert(ss.Peek() == 1.0f);
	assert(ss.Max() == 5.0f);
	assert(ss.Min() == 1.0f);

	assert(ss.Dequeue() == 1.0f);
	assert(ss.Max() == 5.0f);
	assert(ss.Min() == 5.0f);
}

void test3()
{
	QueueStack<float> qs(3);

	qs.Enqueue(3.4f);
	assert(qs.Peek() == 3.4f);
	qs.Enqueue(1.2f);
	assert(qs.Peek() == 1.2f);
	qs.Enqueue(4.6f);
	assert(qs.Peek() == 4.6f);
	qs.Enqueue(3.32f);
	qs.Enqueue(10.2f);
	qs.Enqueue(1.1f);
	qs.Enqueue(-5.9f);
	qs.Enqueue(1.1f);
	qs.Enqueue(-12.4f);
	qs.Enqueue(9.2f);

	assert(qs.Peek() == 4.6f);
	assert(qs.Count() == 10U);
	assert(qs.StackCount() == 4);
	assert(qs.Max() == 10.2f);
	assert(qs.Min() == -12.4f);
	assert(qs.Sum() == 15.820f);
	assert(qs.Average() == 1.582);
	assert(qs.Peek() == 4.6f);

	assert(qs.Dequeue() == 4.6f);
	qs.Enqueue(9.9f);
	assert(qs.Peek() == 9.9f);

	assert(qs.Dequeue() == 9.9f);
	assert(qs.Dequeue() == 1.2f);
	assert(qs.Dequeue() == 3.4f);

	assert(qs.Dequeue() == 1.1f);
	assert(qs.Dequeue() == 10.2f);
	assert(qs.Dequeue() == 3.32f);

	while (qs.Count() > 0)
	{
		qs.Dequeue();
	}

	assert(qs.Min() == std::numeric_limits<float>().max());
	assert(qs.Max() == std::numeric_limits<float>().min());

	qs.Enqueue(5.5f);
	assert(qs.Max() == 5.5f);

	qs.Enqueue(1.5f);
	assert(qs.Min() == 1.5f);

	qs.Dequeue();

	assert(qs.Min() == 5.5f);
	assert(qs.Max() == 5.5f);

}

int main()
{
	test1();
	test2();
	test3();

	return 0;
}
