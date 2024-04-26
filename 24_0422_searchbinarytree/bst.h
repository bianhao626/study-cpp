#pragma once
namespace KV
{
	template<class K, class V>
	//BinarySearchTreeNode
	struct BSTreeNode
	{
		K _key;
		V _value;
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;

		BSTreeNode(const K& key, const V& value)
			:_key(key)
			,_value(value)
			, _left(nullptr)
			, _right(nullptr)
		{}
	};
	template<class K, class V>
	class BSTree
	{
		typedef BSTreeNode<K, V> Node;
	public:
		bool Insert(const K& key, const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key, value);
				return true;
			}
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}
			cur = new Node(key, value);
			if (key > parent->_key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			return true;
		}

		Node* FindNode(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (key > cur->_key)
				{
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}
			return nullptr;
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		//删除
		bool erase(const K& key)
		{
			//先找到对应的节点
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					// 执行删除
					// 左右都为空不需要单独判断
					// 左为空
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
					}
					// 右为空
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					//左右都不为空的情况
					else
					{
						// 左子树的最大节点或者是右子树的最小节点
						// 右子树
						Node* rightminparent = cur;
						Node* rightmin = cur->_right;
						while (rightmin->_left)
						{
							rightminparent = rightmin;
							rightmin = rightmin->_left;
						}
						swap(cur->_key, rightmin->_key);
						if (rightminparent->_left == rightmin)
						{
							rightminparent->_left = rightmin->_right;
						}
						else
						{
							rightminparent->_right = rightmin->_right;
						}
						delete rightmin;
					}
					return true;
				}
			}
			return false;
		}
	private:
		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_InOrder(root->_left);
			cout << root->_key << ":" << root->_value << endl;
			_InOrder(root->_right);
		}
	private:
		Node* _root = nullptr;
	};
}


namespace K
{
	template<class K>
	//BinarySearchTreeNode
	struct BSTreeNode
	{
		K _key;
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;

		BSTreeNode(const K& key)
			:_key(key)
			, _left(nullptr)
			, _right(nullptr)
		{}
	};
	template<class K>
	class BSTree
	{
		typedef BSTreeNode<K> Node;
	public:
		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}
			cur = new Node(key);
			if (key > parent->_key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			return true;
		}

		bool FindNode(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (key > cur->_key)
				{
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					cur = cur->_left;
				}
				else
				{
					return true;
				}
			}
			return false;
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		//删除
		bool erase(const K& key)
		{
			//先找到对应的节点
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					// 执行删除
					// 左右都为空不需要单独判断
					// 左为空
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
					}
					// 右为空
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					//左右都不为空的情况
					else
					{
						// 左子树的最大节点或者是右子树的最小节点
						// 右子树
						Node* rightminparent = cur;
						Node* rightmin = cur->_right;
						while (rightmin->_left)
						{
							rightminparent = rightmin;
							rightmin = rightmin->_left;
						}
						swap(cur->_key, rightmin->_key);
						if (rightminparent->_left == rightmin)
						{
							rightminparent->_left = rightmin->_right;
						}
						else
						{
							rightminparent->_right = rightmin->_right;
						}
						delete rightmin;
					}
					return true;
				}
			}
			return false;
		}
	private:
		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}
	private:
		Node* _root = nullptr;
	};
}