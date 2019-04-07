#pragma once

#include <memory>
#include <vector>
#include <stack>

#include "TreeNode.h"

namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);

	private:
		std::shared_ptr<TreeNode<T>> mRoot;
		static void search(std::vector<T>& vector, const std::shared_ptr<TreeNode<T>>& node);

	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		
		if (mRoot == nullptr)
		{
			mRoot = std::make_shared<TreeNode<T>>(std::move(data));
			return;
		}

		std::shared_ptr<TreeNode<T>> tmp = mRoot;

		while (true)
		{
			if (*tmp->Data >= *data)
			{
				if (tmp->Left == nullptr)
				{
					tmp->Left = std::make_shared<TreeNode<T>>(tmp, std::move(data));
					return;
				}
				else
				{
					tmp = tmp->Left;
				}
			}
			else
			{
				if (tmp->Right == nullptr)
				{
					tmp->Right = std::make_shared<TreeNode<T>>(tmp, std::move(data));
					return;
				}
				else
				{
					tmp = tmp->Right;
				}
			}
		}
		
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return mRoot;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		std::shared_ptr<TreeNode<T>> tmp = mRoot;

		while (true)
		{
			if (tmp == nullptr)
			{
				return false;
			}

			if (*tmp->Data == data)
			{
				return true;
			}

			tmp = (*tmp->Data >= data) ? tmp->Left : tmp->Right;
		}
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		std::shared_ptr<TreeNode<T>> tmp = mRoot;

		while (true)
		{

			if (tmp == nullptr)
			{
				return false;
			}

			if (*tmp->Data == data)
			{
				break;
			}

			if (*tmp->Data >= data)
			{
				tmp = tmp->Left;
			}
			else
			{
				tmp = tmp->Right;
			}
		}

		std::shared_ptr<TreeNode<T>> parent = tmp->Parent.lock();

		// Leaf Node일때
		if (tmp->Left == nullptr && tmp->Right == nullptr)
		{
			if (tmp == mRoot)
			{
				mRoot = nullptr;
			}
			else
			{
				if (parent->Left == tmp)
				{
					parent->Left = nullptr;
				}
				else
				{
					parent->Right = nullptr;
				}
			}
		}
		// 자식을 2개 가지는 Node
		else if (tmp->Left != nullptr && tmp->Right != nullptr)
		{
			if (tmp == mRoot)
			{
				mRoot = tmp->Left;
			}
			else
			{
				if (parent->Left == tmp)
				{
					parent->Left = tmp->Left;
				}
				else
				{
					parent->Right = tmp->Left;
				}

				tmp->Left->Parent = parent;
			}

			std::shared_ptr<TreeNode<T>> tmp2 = tmp->Left;

			while (true)
			{
				if (tmp2->Right == nullptr)
				{
					tmp2->Right = tmp->Right;
					tmp->Right->Parent = tmp2;
					break;
				}

				tmp2 = tmp2->Right;
			}
		}
		// 왼쪽 노드만 있는 경우
		else if (tmp->Left != nullptr)
		{
			if (tmp == mRoot)
			{
				mRoot = tmp->Left;
			}
			else
			{
				if (parent->Left == tmp)
				{
					parent->Left = tmp->Left;
				}
				else
				{
					parent->Right = tmp->Left;
				}
				tmp->Left->Parent = parent;
			}
		}
		// 오른쪽 노드만 있는 경우
		else if (tmp->Right != nullptr)
		{
			if (tmp == mRoot)
			{
				mRoot = tmp->Right;
			}
			else
			{
				if (parent->Left == tmp)
				{
					parent->Left = tmp->Right;
				}
				else
				{
					parent->Right = tmp->Right;
				}
			}
		}

		return true;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;

		if (startNode != nullptr)
		{
			search(v, startNode);
		}

		return v;
	}

	template<typename T>
	void BinarySearchTree<T>::search(std::vector<T>& vector, const std::shared_ptr<TreeNode<T>>& node)
	{
		if (node->Left != nullptr)
		{
			search(vector, node->Left);
		}

		vector.push_back(*node->Data);

		if (node->Right != nullptr)
		{
			search(vector, node->Right);
		}
	}

}