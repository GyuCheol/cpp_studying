#pragma once

#include <memory>
#include "Node.h"

namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;

	private:
		size_t mCount;
		std::shared_ptr<Node<T>> head;

	};

	template<typename T> DoublyLinkedList<T>::DoublyLinkedList()
		: mCount(0)
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		Insert(std::move(data), mCount);
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		if (head == nullptr)
		{
			head = std::make_shared<Node<T>>(std::move(data));
		}
		else
		{
			std::shared_ptr<Node<T>> node;

			if (index >= mCount)
			{
				node = DoublyLinkedList<T>::operator[](mCount - 1);
				auto newNode = std::make_shared<Node<T>>(std::move(data), node);

				node->Next = newNode;
			}
			else
			{
				node = DoublyLinkedList<T>::operator[](index);
				auto newNode = std::make_shared<Node<T>>(std::move(data), node->Previous.lock());

				if (node->Previous.expired() == false)
				{
					node->Previous.lock()->Next = newNode;
				}

				newNode->Next = node;
				node->Previous = newNode;

				if (index == 0)
				{
					head = newNode;
				}
			}
		}

		mCount++;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		std::shared_ptr<Node<T>> tmp = head;

		for (size_t i = 0; i < mCount; i++)
		{
			if (*tmp->Data == data)
			{
				if (tmp->Previous.expired() == false)
				{
					tmp->Previous.lock()->Next = tmp->Next;
				}
				
				if (tmp->Next != nullptr)
				{
					tmp->Next->Previous = tmp->Previous;
				}

				if (i == 0)
				{
					head = tmp->Next;
				}

				mCount--;
				return true;
			}

			tmp = tmp->Next;
		}

		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> tmp = head;

		for (size_t i = 0; i < mCount; i++)
		{
			if (*tmp->Data == data)
			{
				return true;
			}

			tmp = tmp->Next;
		}

		return false;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		if (index >= mCount)
		{
			return nullptr;
		}

		std::shared_ptr<Node<T>> tmp = head;

		for (size_t i = 0; i < index; i++)
		{
			tmp = tmp->Next;
		}

		return tmp;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mCount;
	}
}