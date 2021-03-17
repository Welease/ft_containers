//
// Created by Wynn Elease on 3/14/21.
//

#ifndef FT_CONTAINERS_FT_MAP_H
#define FT_CONTAINERS_FT_MAP_H

#include "ft.h"
#include <queue>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#  define RED_NODE_OUTPUT(x)  "\x1b[31;1m" + (x) + "\x1b[0m"

//template < class G, class U >
//std::ostream & operator<<(std::ostream & o, std::pair<G, U> p) {
//	o << "_" << p.first;
//	return o;
//}

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
	class map {

public:
	class iterator;

	class const_iterator;

	class reverse_iterator;

	class const_reverse_iterator;

	typedef Key 										key_type;
	typedef T 											mapped_type;
	typedef std::pair<const key_type, mapped_type> 		value_type;
	typedef Compare 									key_compare;
	typedef Alloc 										allocator_type;
	typedef value_type &								reference;
	typedef const value_type &							const_reference;
	typedef value_type *								pointer;
	typedef const value_type *							const_pointer;
	typedef size_t 										size_type;
	typedef ptrdiff_t 									difference_type;

	class value_compare : public std::binary_function<value_type, value_type, bool> {
	public:
		key_compare cmp;

		explicit value_compare(key_compare c) : cmp(c) {};
	public:

		bool operator()(const value_type &x, const value_type &y) const { return cmp(x.first, y.first); };
	};

private:
	typedef struct 	Node {
		Node *		left;
		Node *		right;
		Node *		parent;
		pointer 	data;
		bool 		color;
	} 				TreeNode;

	enum Side {
		right = 0,
		left
	};

	typedef typename allocator_type::template rebind<TreeNode>::other ptr_alloc;

	TreeNode *	_root;
	TreeNode *	_endNode;
	TreeNode *	_beginNode;
	size_type 	_size;
	key_compare	_cmp;

	ptr_alloc			 	_ptr_alloc;
	allocator_type 			_alloc;

	const static bool _black = false;
	const static bool _red = true;

	void _allocBeginNode() {
		_beginNode = _ptr_alloc.allocate(1);
		_beginNode->left = nullptr;
		_beginNode->right = nullptr;
		_beginNode->color = _black;
		_beginNode->data = nullptr;
	}

	void _allocEndNode() {
		_endNode = _ptr_alloc.allocate(1);
		_endNode->left = nullptr;
		_endNode->right = nullptr;
		_endNode->color = _black;
		_endNode->data = nullptr;
	}

	void _allocEmptyMap() {
		_allocBeginNode();
		_allocEndNode();
	}

	TreeNode * _newNode(Node *parent, const_reference value, bool color) {
		Node *newNode = _ptr_alloc.allocate(1);
		newNode->parent = parent;
		newNode->left = nullptr;
		newNode->right = nullptr;
		newNode->data = _alloc.allocate(1);
		_alloc.construct(newNode->data, value);
		newNode->color = color;
		++_size;
		return newNode;
	}

	void _destroyNode(TreeNode *node) {
		_alloc.destroy(node->data);
		_alloc.deallocate(node->data, 1);
		_ptr_alloc.deallocate(node, 1);
		--_size;
	}

	void _rotateLeft(TreeNode *oldRoot) {
		TreeNode *newRoot = oldRoot->right;
		if (oldRoot == _root)
			_root = newRoot;
		_lowNode(newRoot, oldRoot);
		oldRoot->right = newRoot->left;
		if (newRoot->left != NULL)
			newRoot->left->parent = oldRoot;
		newRoot->left = oldRoot;
	}

	void _rotateRight(TreeNode *oldRoot) {
		TreeNode *newRoot = oldRoot->left;
		if (oldRoot == _root)
			_root = newRoot;
		_lowNode(newRoot, oldRoot);
		oldRoot->left = newRoot->right;
		if (newRoot->right != NULL)
			newRoot->right->parent = oldRoot;
		newRoot->right = oldRoot;
	}

	TreeNode *_getUncleOfNode(TreeNode *node) {
		if (node->parent == NULL or node->parent->parent == NULL)
			return NULL;
		if (_isLeftNode(node->parent))
			return node->parent->parent->right;
		else
			return node->parent->parent->left;
	}

	bool _isLeftNode(TreeNode *node) { return node == node->parent->left; }

	TreeNode *_getBrother(TreeNode *node) {
		if (node->parent == NULL)
			return NULL;
		if (_isLeftNode(node))
			return node->parent->right;
		return node->parent->left;
	}

	void _lowNode(TreeNode *newRoot, TreeNode *oldRoot) {
		if (oldRoot->parent != NULL)
			_isLeftNode(oldRoot) ? oldRoot->parent->left = newRoot : oldRoot->parent->right = newRoot;
		newRoot->parent = oldRoot->parent;
		oldRoot->parent = newRoot;
	}

	bool _hasRedChild(TreeNode *x) {
		return (x->left != NULL && x->left->color == _red) || (x->right != NULL && x->right->color == _red);
	}


	void _colorSwap(TreeNode *node1, TreeNode *node2) {
		bool temp = node1->color;
		node1->color = node2->color;
		node2->color = temp;
	}

	TreeNode* _valueSwap(TreeNode *replNode, TreeNode *toDel) {
//		value_type  *tmp = toDel->data;
//		toDel->data = replNode->data;
//		replNode->data = tmp;
//		return replNode;

		std::cout << replNode->data->first << "       " << toDel->data->first << std::endl;

		TreeNode *tmp1 = toDel->right;
		TreeNode *tmp2 = toDel->left;
		TreeNode *tmp3 = toDel->parent;
		TreeNode *tmp4 = replNode->parent;

		Side s;
		bool ret = false;
		if (replNode->parent && replNode->parent != toDel)
			ret = true;

		if (tmp3)
			s = tmp3->left == toDel ? left : right;
		bool tmpColor = toDel->color;

		toDel->right = replNode->right;
		toDel->left = replNode->left;
		if (replNode->parent != toDel)
			toDel->parent = replNode->parent;
		else
			toDel->parent = replNode;
		toDel->color = replNode->color;

		if (tmp1->parent != toDel)
			tmp1->parent = replNode;
		else if (tmp3 != nullptr)
			tmp1->parent = tmp3;
		else
			link(replNode, tmp1, right);
		link(replNode, tmp2, left);
		if (tmp3)
			s == right ? tmp3->right = replNode : tmp3->left = replNode;
		replNode->color = tmpColor;
		if (tmp1 != replNode)
			replNode->right = tmp1;
		else
			replNode->right = toDel;
		if (ret)
			link(tmp4, toDel, left);
		replNode->parent = tmp3;
		if (toDel == _root)
			_root = replNode;
		return toDel;
	}

	void _leftSideBalance(TreeNode *node, TreeNode *parentNode, TreeNode *grandparent) {
		if (_isLeftNode(node))
			_colorSwap(parentNode, grandparent);
		else {
			_rotateLeft(parentNode);
			_colorSwap(node, grandparent);
		}
		_rotateRight(grandparent);
	}

	void _rightSideBalance(TreeNode *node, TreeNode *parentNode, TreeNode *grandparent) {
		if (_isLeftNode(node)) {
			_rotateRight(parentNode);
			_colorSwap(node, grandparent);
		}
		else
			_colorSwap(parentNode, grandparent);
		_rotateLeft(grandparent);
	}

	void _redRedNodesHandler(TreeNode *node) {
		if (node == _root) {
			node->color = _black;
			return;
		}
		TreeNode *parentNode = node->parent;
		TreeNode *grandparent = parentNode->parent;
		TreeNode *uncleOfNode = _getUncleOfNode(node);
		if (parentNode->color != _black) {
			if (uncleOfNode && uncleOfNode->color == _red) {
				parentNode->color = _black;
				uncleOfNode->color = _black;
				grandparent->color = _red;
				_redRedNodesHandler(grandparent);
			}
			else {
				_isLeftNode(parentNode)
					 ? _leftSideBalance(node, parentNode, grandparent)
					 : _rightSideBalance(node, parentNode, grandparent);
			}
		}
	}

	TreeNode *getReplacingForNode(TreeNode *x) {
		if (x->left && x->right) {
			TreeNode *temp = x->right;
			while (temp->left != nullptr)
				temp = temp->left;
			return temp;
		}
		if (!x->left && !x->right)
			return nullptr;
		return x->left ? x->left : x->right;
	}

	void _erase(TreeNode *toDelete) {
		TreeNode *replacingForNode = getReplacingForNode(toDelete);
		bool isBothNodesBlack = ((replacingForNode == nullptr || replacingForNode->color == _black) && (toDelete->color == _black));
		TreeNode *parent = toDelete->parent;
		if (!replacingForNode) {
			if (toDelete == _root)
				_root = nullptr;
			else {
				if (isBothNodesBlack)
					_blackBlackNodesHandler(toDelete);
				else
					_getBrother(toDelete) ? _getBrother(toDelete)->color = _red : 0;
				_isLeftNode(toDelete) ? parent->left = nullptr : parent->right = nullptr;
			}
			_destroyNode(toDelete);
			return;
		}

		if (!toDelete->left || !toDelete->right) {
			if (toDelete == _root) {
				_alloc.destroy(toDelete->data);
				_alloc.construct(toDelete->data, *(replacingForNode->data));
				toDelete->left = nullptr;
				toDelete->right = nullptr;
				_destroyNode(replacingForNode);
			} else {
				_isLeftNode(toDelete) ? parent->left = replacingForNode : parent->right = replacingForNode;
				_destroyNode(toDelete);
				replacingForNode->parent = parent;
				if (isBothNodesBlack)
					_blackBlackNodesHandler(replacingForNode);
				else
					replacingForNode->color = _black;
			}
			return;
		}
		replacingForNode = _valueSwap(replacingForNode, toDelete);
		_erase(replacingForNode);
	}

	void _doubleBlackWithRedChild(TreeNode *brotherNode, TreeNode *parent) {
		if (brotherNode->left && brotherNode->left->color == _red) {
			if (_isLeftNode(brotherNode)) {
				brotherNode->left->color = brotherNode->color;
				brotherNode->color = parent->color;
				_rotateRight(parent);
			}
			else {
				brotherNode->left->color = parent->color;
				_rotateRight(brotherNode);
				_rotateLeft(parent);
			}
		}
		else {
			if (_isLeftNode(brotherNode)) {
				brotherNode->right->color = parent->color;
				_rotateLeft(brotherNode);
				_rotateRight(parent);
			}
			else {
				brotherNode->right->color = brotherNode->color;
				brotherNode->color = parent->color;
				_rotateLeft(parent);
			}
		}
		parent->color = _black;
	}

	void _blackBlackNodesHandler(TreeNode *x) {
		if (x == _root)
			return;
		TreeNode *brotherNode = _getBrother(x);
		TreeNode * parent = x->parent;
		if (!brotherNode)
			_blackBlackNodesHandler(parent);
		else {
			if (brotherNode->color == _red) {
				parent->color = _red;
				brotherNode->color = _black;
				_isLeftNode(brotherNode) ? _rotateRight(parent) : _rotateLeft(parent);
				_blackBlackNodesHandler(x);
			}
			else {
				if (_hasRedChild(brotherNode))
					_doubleBlackWithRedChild(brotherNode, parent);
				else {
					brotherNode->color = _red;
					if (parent->color == _black)
						_blackBlackNodesHandler(parent);
					else
						parent->color = _black;
				}
			}
		}
	}

	TreeNode *_searchInTreeByKey(key_type key) {
		TreeNode *temp = _root;

		while (temp != nullptr) {
			if (key < temp->data->first) {
				if (temp->left == nullptr)
					break;
				else
					temp = temp->left;
			}
			else if (key == temp->data->first) {
				break;
			}
			else {
				if (!temp->right)
					break;
				else
					temp = temp->right;
			}
		}
		return temp;
	}

	void link(TreeNode *parent, TreeNode *node, Side side) {
		if (!parent)
			return;
		side == right ? parent->right = node : parent->left = node;
		if (node)
			node->parent = parent;
	}

	bool _insert(value_type key) {
		TreeNode *newNode = _newNode(nullptr, key, _red);
		if (_root == nullptr) {
			newNode->color = _black;
			_root = newNode;
		}
		else {
			TreeNode *temp = _searchInTreeByKey(key.first);
			if (temp->data->first == key.first) {
				_destroyNode(newNode);
				return false;
			}
			newNode->parent = temp;
			if (key < (*temp->data))
				temp->left = newNode;
			else
				temp->right = newNode;
			_redRedNodesHandler(newNode);
		}
		return true;
	}

	bool _eraseByKey(key_type key) {
		if (_root == nullptr)
			return false;
		TreeNode *v = _searchInTreeByKey(key);
		if (v->data->first != key) {
			return false;
		}
		_erase(v);
		return true;
	}

	TreeNode *getMinNode(TreeNode *node) {
		if (node && node->left)
				return getMinNode(node->left);
		return node;
	}

	TreeNode *getMaxNode(TreeNode *node) {
		if (node && node->right)
				return getMaxNode(node->right);
		return node;
	}


public:

	explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _root(nullptr), _cmp(comp), _alloc(alloc), _size(0){
		_allocEmptyMap();
	}

	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _cmp(comp), _root(nullptr), _size(0) {
		_allocEmptyMap();
		insert(first, last);
	}

	map (const map& x) : _alloc(x._alloc), _cmp(x._cmp), _root(nullptr), _size(0) {
		_allocEmptyMap();
		*this = x;
	}

	~map() {
		clear();
		_ptr_alloc.deallocate(_endNode, 1);
		_ptr_alloc.deallocate(_beginNode, 1);
	}


	map& operator= (const map& x) {
		if (this != &x) {
			const_iterator iter = x.begin();
			clear();
			while (iter != x.end())
				insert(*(iter)++);
		}
		return *this;
	}

	void clear() {
		while (_size)
			erase(begin());
	}

		void	_dPrintStrangeTreeLine(int width, TreeNode* curNode) {
			std::stringstream ss;
			std::string str;

			std::cout.width(width);
			if (curNode && curNode->data) {
				ss << *(curNode->data);
				str = ss.str();
				if (curNode->color) {
					str = RED_NODE_OUTPUT(ss.str());
					width += 11;
				}
				std::cout << std::setw(width) << str ;
			}
			else if (curNode)
				std::cout << "EN";
			else
				std::cout << "N";
		}

	void	_dPrintStrangeTree()
	{
		TreeNode *root = _root;
		typename std::queue<typename map<Key, T>::TreeNode*> q;
		typename map<Key, T>::TreeNode * curNode;
		bool printTime;
		int onLine = 1;
		int needToPrint = 1;
		int widthSt = 64; // CHANGE HERE 32 / 64 / 128 / 256 etc
		int width;

		q.push(root);
		while (!q.empty()) {
			curNode = q.front();
			q.pop();
			printTime = onLine == needToPrint;
			width = printTime ? (widthSt / onLine / 2) : (widthSt / onLine);
			_dPrintStrangeTreeLine(width, curNode);
			--needToPrint;
			if (curNode) {
				q.push(curNode->left);
				q.push(curNode->right);
			}
			else {
				q.push(nullptr);
				q.push(nullptr);
			}
			if (needToPrint == 0) {
				onLine *= 2;
				needToPrint = onLine;
				std::cout << std::endl;
			}
			if (onLine == widthSt / 2)
				break;
		}
		std::cout << std::endl;
		std::cout << std::setfill('.') << std::setw(widthSt) << " " << std::endl;
		std::cout.fill(' ');
		std::cout << std::endl;
	}

	iterator 					begin() {
		TreeNode *node;
		if (_size)
			node = _beginNode->parent;
		else
			node = _endNode;
		return iterator(node);
	}

	const_iterator 				begin() const { return _size ? const_iterator(_beginNode->parent) : const_iterator(_endNode); }

	iterator 					end() { return iterator(_endNode); }

	const_iterator 				end() const {  return const_iterator(_endNode); }

	reverse_iterator 			rbegin() { return _size ? reverse_iterator(_endNode->parent) : reverse_iterator(_beginNode); };

	const_reverse_iterator		rbegin() const { return const_reverse_iterator(rbegin()); };

	reverse_iterator 			rend() { return reverse_iterator(_beginNode); };

	const_reverse_iterator		rend() const { return const_reverse_iterator(_beginNode); };

	bool 						empty() const { return !_size; };

	size_type 					size() const { return _size; };

	size_type 					max_size() const { return std::numeric_limits<size_type>::max() / sizeof(_root); };

	iterator 					find (const key_type& k) {
		for (iterator i = begin(); i != end(); ++i)
			if (i.getNode()->data->first == k)
				return i;
		return end();
	}

	const_iterator find (const key_type& k) const {
		for (const_iterator i = begin(); i != end(); ++i)
			if (i.getNode()->data->first == k)
				return i;
		return end();
	}

	std::pair<iterator, bool> insert (const_reference val) {
		if (_size) {
			if (_beginNode->parent)
				_beginNode->parent->left = nullptr;
			if (_endNode->parent)
				_endNode->parent->right = nullptr;
		}
		bool ret = _insert(val);
		TreeNode *tmp = getMaxNode(_root);
		link(tmp, _endNode, right);
		tmp = getMinNode(_root);
		link(tmp, _beginNode, left);
		return std::make_pair(find(val.first), ret);
	};

	mapped_type& operator[] (const key_type& k) { return (*((this->insert(make_pair(k,mapped_type()))).first)).second; }

	iterator insert (iterator position, const value_type& val) {
		static_cast<void>(position);
		return insert(val).first;
	};

	template <class InputIterator> void insert (InputIterator first, InputIterator last) {
		while (first != last)
			insert(*first++);
	}

	size_type count (const key_type& k) const {
		const_iterator i = find(k);

		return i != end();
	}

	size_type erase (const key_type& k) {
		if (_size) {
			if (_beginNode->parent)
				_beginNode->parent->left = nullptr;
			if (_endNode->parent)
				_endNode->parent->right = nullptr;
		}
		bool ret = _eraseByKey(k);
		TreeNode *tmp = getMaxNode(_root);
		link(tmp, _endNode, right);
		tmp = getMinNode(_root);
		link(tmp, _beginNode, left);
		return ret;
	}

	void erase (iterator position) {
		if (position != iterator(_endNode))
			erase(position->first);
	};

	key_compare key_comp() const { return _cmp; }

	value_compare value_comp() const { return value_compare(_cmp); };

	iterator 		lower_bound (const key_type& k) {
		iterator beg = begin();
		iterator last = end();
		while (beg != last && _cmp(beg->first, k))
			++beg;
		return beg;
	};

	const_iterator	lower_bound (const key_type& k) const {
		iterator beg = begin();
		iterator last = end();
		while (beg != last && _cmp(beg->first, k))
			++beg;
		return beg;
	};

	iterator 		upper_bound (const key_type& k) {
		iterator iter = lower_bound(k);
		if (iter != end() && !_cmp(iter->first, k) && !_cmp(k, iter->first))
			++iter;
		return iter;
	};

	const_iterator	upper_bound (const key_type& k) const {
		const_iterator iter = lower_bound(k);
		if (iter != end() && !_cmp(iter->first, k) && !_cmp(k, iter->first))
			++iter;
		return iter;
	};

	std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const { return std::make_pair(lower_bound(k), upper_bound(k)); }

	std::pair<iterator,iterator>             equal_range (const key_type& k) { return std::make_pair(lower_bound(k), upper_bound(k)); }

	void swap (map& x) {
		TreeNode *temp = _root;
		_root = x._root;
		x._root = temp;

		size_type size = _size;
		_size = x._size;
		x._size = size;

		temp = _endNode;
		_endNode = x._endNode;
		x._endNode = temp;

		temp = _beginNode;
		_beginNode = x._beginNode;
		x._beginNode = temp;
	}

	void erase (iterator first, iterator last){
		while (first != last)
			erase(first++);
	};

	class iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
	private:
		TreeNode* _node;
	public:
		iterator(TreeNode* node = nullptr): _node(node) {};
		~iterator() {};
		iterator & operator=(const iterator &iter) {
			this->_node = iter._node;
			return *this;
		};
		iterator(const iterator &iter) { *this = iter; };
		iterator & operator++() {
			if (_node->right) {
				_node = getMinNode(_node->right);
				return *this;
			}
			else if (_node->parent && _node->parent->left == _node) {
				_node = _node->parent;
				return *this;
			}
			else if (_node->parent->right == _node)
				_node = _node->parent;
			TreeNode *temp = _node;
			while (temp->parent->right == temp) {
				temp = temp->parent;
				if (!temp) {
					_node = _node->right;
					return *this;
				}
			}
			_node = temp->parent;
			return *this;
		};
		iterator operator++(int) {
			iterator temp(_node);
			operator++();
			return temp;
		};
		iterator & operator--() {
			if (_node->left) {
				_node = getMaxNode(_node->left);
				return *this;
			}
			else if (_node->parent && _node->parent->right == _node) {
				_node = _node->parent;
				return *this;
			}
			TreeNode *temp = _node;
			while (temp->parent->left == temp) {
				temp = temp->parent;
				if (!temp) {
					_node = _node->left;
					return *this;
				}
			}
			_node = _node->parent;
			return *this;
		};
		iterator operator--(int) {
			iterator temp(_node);
			operator--();
			return temp;
		};
		bool operator==(const iterator &iter) const { return _node == iter._node; };
		bool operator!=(const iterator &iter) const { return _node != iter._node; };

		bool operator==(const const_iterator &iter) const { return _node == iter.getNode(); };
		bool operator!=(const const_iterator &iter) const { return _node != iter.getNode(); };

		reference operator*() const { return *(_node->data); }
		pointer operator->() const {
			return _node->data; }
		TreeNode *getNode() const { return _node; }

	private:
		TreeNode *getMinNode(TreeNode *node) {
			if (node->left)
				return getMinNode(node->left);
			return node;
		}

		TreeNode *getMaxNode(TreeNode *node) {
			if (node->right)
				return getMaxNode(node->right);
			return node;
		}
	};

	class const_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type const> {
	private:
		TreeNode *_node;
	public:
		const_iterator(TreeNode* node = nullptr) : _node(node) {};
		const_iterator(const const_iterator &iter) { *this = iter; };
		const_iterator(const iterator &iter) { *this = iter; };
		~const_iterator() {};

		const_iterator& operator=(const const_iterator &iter)  {
			_node = iter._node;
			return *this;
		};

		const_iterator& operator=(const iterator &it)  {
			_node = it.getNode();
			return *this;
		};

		const_iterator & operator++() {
			if (_node->right) {
				_node = getMinNode(_node->right);
				return *this;
			}
			else if (_node->parent && _node->parent->left == _node) {
				_node = _node->parent;
				return *this;
			}
			else if (_node->parent->right == _node)
				_node = _node->parent;
			TreeNode *temp = _node;
			while (temp->parent->right == temp) {
				temp = temp->parent;
				if (!temp) {
					_node = _node->right;
					return *this;
				}
			}
			_node = temp->parent;
			return *this;
		};
		const_iterator operator++(int) {
			const_iterator temp(_node);
			operator++();
			return temp;
		};
		const_iterator & operator--() {
			if (_node->left) {
				_node = getMaxNode(_node->left);
				return *this;
			}
			else if (_node->parent && _node->parent->right == _node) {
				_node = _node->parent;
				return *this;
			}
			TreeNode *temp = _node;
			while (temp->parent->left == temp) {
				temp = temp->parent;
				if (!temp) {
					_node = _node->left;
					return *this;
				}
			}
			_node = _node->parent;
			return *this;
		};
		const_iterator operator--(int) {
			const_iterator temp(_node);
			operator--();
			return temp;
		};
		bool operator==(const const_iterator &iter) const { return _node == iter._node; };
		bool operator!=(const const_iterator &iter) const { return _node != iter._node; };

		bool operator==(const iterator &iter) const { return _node == iter.getNode(); };
		bool operator!=(const iterator &iter) const { return _node != iter.getNode(); };

		const_reference operator*() const { return *(_node->data); };
		const_pointer operator->() const { return _node->data; }

		TreeNode *getNode() const { return _node; }
	private:

		TreeNode *getMinNode(TreeNode *node) {
			if (node->left)
				return getMinNode(node->left);
			return node;
		}

		TreeNode *getMaxNode(TreeNode *node) {
			if (node->right)
				return getMaxNode(node->right);
			return node;
		}
	};

	class reverse_iterator : public std::reverse_iterator<iterator> {
	private:
		TreeNode * _node;
	public:
		reverse_iterator(TreeNode * node = nullptr): _node(node) {};
		~reverse_iterator() {};
		reverse_iterator(const reverse_iterator &iter) { *this = iter; };

		reverse_iterator & operator=(const reverse_iterator &iter) {
			this->_node = iter._node;
			return *this;
		};

		reverse_iterator & operator++() {
			if (_node->left) {
				_node = getMaxNode(_node->left);
				return *this;
			}
			else if (_node->parent && _node->parent->right == _node) {
				_node = _node->parent;
				return *this;
			}
			TreeNode *temp = _node;
			while (temp->parent->left == temp)
				if ((temp = temp->parent) == nullptr) {
					_node = temp->left;
					return *this;
				}
			_node = temp->parent;
			return *this;
		};

		reverse_iterator operator++(int) {
			reverse_iterator temp(_node);
			operator++();
			return temp;

		};
		reverse_iterator & operator--() {
			if (_node->right) {
				_node = getMinNode(_node->right);
				return *this;
			}
			else if (_node->parent && _node->parent->left == _node) {
				_node = _node->parent;
				return *this;
			}
			else if (_node->parent->right == _node)
				_node = _node->parent;
			TreeNode *temp = _node;
			while (temp->parent->right == temp) {
				temp = temp->parent;
				if (!temp) {
					_node = _node->right;
					return *this;
				}
			}
			_node = temp->parent;
			return *this;
		};

		reverse_iterator operator--(int) {
			reverse_iterator temp(_node);
			operator--();
			return temp;
		};
		bool operator==(const reverse_iterator &iter) const { return _node == iter._node; };
		bool operator!=(const reverse_iterator &iter) const { return _node != iter._node; };

		bool operator==(const const_reverse_iterator &iter) const { return _node == iter.getNode(); };
		bool operator!=(const const_reverse_iterator &iter) const { return _node != iter.getNode(); };

		value_type & operator*() const { return *(_node->data); };
		value_type * operator->() const {
			return _node->data; }

		TreeNode *getNode() const { return _node; }
	private:
		TreeNode *getMinNode(TreeNode *node) {
			if (node->left)
				return getMinNode(node->left);
			return node;
		}

		TreeNode *getMaxNode(TreeNode *node) {
			if (node->right)
				return getMaxNode(node->right);
			return node;
		}
	};

	class const_reverse_iterator : public std::reverse_iterator<iterator> {
	private:
		TreeNode * _node;
	public:
		const_reverse_iterator(TreeNode* node = nullptr): _node(node) {};
		~const_reverse_iterator() {};

		const_reverse_iterator & operator=(const const_reverse_iterator &iter) {
			this->_node = iter._node;
			return *this;
		};

		const_reverse_iterator & operator=(const reverse_iterator &iter) {
			this->_node = iter.getNode();
			return *this;
		};

		const_reverse_iterator(const const_reverse_iterator &iter) { *this = iter; };
		const_reverse_iterator(const reverse_iterator &iter) { *this = iter; };

		const_reverse_iterator & operator++() {
			if (_node->left) {
				_node = getMaxNode(_node->left);
				return *this;
			}
			else if (_node->parent && _node->parent->right == _node) {
				_node = _node->parent;
				return *this;
			}
			TreeNode *temp = _node;
			while (temp->parent->left == temp)
				if ((temp = temp->parent) == nullptr) {
					_node = temp->left;
					return *this;
				}
			_node = temp->parent;
			return *this;
		};

		const_reverse_iterator operator++(int) {
			const_reverse_iterator tmp(_node);
			operator++();
			return tmp;
		};

		const_reverse_iterator & operator--() {
			if (_node->right) {
				_node = getMinNode(_node->right);
				return *this;
			}
			else if (_node->parent && _node->parent->left == _node) {
				_node = _node->parent;
				return *this;
			}
			else if (_node->parent->right == _node)
				_node = _node->parent;
			TreeNode *temp = _node;
			while (temp->parent->right == temp) {
				temp = temp->parent;
				if (!temp) {
					_node = _node->right;
					return *this;
				}
			}
			_node = temp->parent;
			return *this;
		};

		const_reverse_iterator operator--(int) {
			const_reverse_iterator tmp(_node);
			operator--();
			return tmp;
		};

		bool operator==(const const_reverse_iterator &iter) const { return _node == iter._node; };
		bool operator!=(const const_reverse_iterator &iter) const { return _node != iter._node; };

		bool operator==(const reverse_iterator &iter) const { return _node == iter.getNode(); };
		bool operator!=(const reverse_iterator &iter) const { return _node != iter.getNode(); };

		reference operator*() const { return *(this->_node->data); }
		pointer operator->() const { return this->it->data; }

		TreeNode *getNode() const { return _node; }
	private:
		TreeNode *getMinNode(TreeNode *node) {
			if (node->left)
				return getMinNode(node->left);
			return node;
		}

		TreeNode *getMaxNode(TreeNode *node) {
			if (node->right)
				return getMaxNode(node->right);
			return node;
		}
	};
	};
}

#endif //FT_CONTAINERS_FT_MAP_H
