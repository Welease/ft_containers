//
// Created by Wynn Elease on 3/14/21.
//

#ifndef FT_CONTAINERS_FT_MAP_H
#define FT_CONTAINERS_FT_MAP_H
#include <queue>
#include "ft.h"

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

	class value_compare : public std::binary_function<value_type, value_type, bool>
	{
	public:
		key_compare cmp;

		explicit value_compare(key_compare c) : cmp(c)
		{};
	public:

		bool operator()(const value_type &x, const value_type &y) const
		{ return cmp(x.first, y.first); };
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

	void link(TreeNode *parent, TreeNode *node, Side side) {
		side == right ? parent->right = node : parent->left = node;
		if (node)
			node->parent = parent;
	}

	bool _isRed(TreeNode *node) {
		if (!node)
			return _black;
		return node->color == _red;
	}

	void _colorFlip(TreeNode *node) {
		node->right ? node->right->color = !node->right->color : 0;
		node->left ? node->left->color = !node->left->color : 0;
		node->color = !node->color;
		if (node == _root)
			_root->color = _black;
	}

	void _lowNode(TreeNode *h, Side s) {
		TreeNode *tmp = s == left ? h->right->left : h->left->right;
		s == left ? h->right->left  = h : h->left->right = h;
		s == left ? h->right = tmp : h->left = tmp;
	}

	TreeNode	*_leftRotate(TreeNode* node) {
		node->right->parent = node->parent;
		node->parent = node->right;
		if (node->right->left)
			node->right->left->parent = node;
		_lowNode(node, left);
		node->parent->color = node->color;
		node->color = _red;
		if (node == _root)
			_root = node->parent;
		return node->parent;
	}

	TreeNode	*_rightRotate(TreeNode* node) {
		node->left->parent = node->parent;
		node->parent = node->left;
		if (node->left->right)
			node->left->right->parent = node;
		_lowNode(node, right);
		node->parent->color = node->color;
		node->color = _red;
		if (node == _root)
			_root = node->parent;
		return node->parent;
	}

	TreeNode *_balancing(TreeNode *node) {
		if (_isRed(node->right))
			node = _leftRotate(node);
		if (_isRed(node->left) && _isRed(node->left->left))
			node = _rightRotate(node);
		if (_isRed(node->left) && _isRed(node->right))
			_colorFlip(node);
		return node;
	}

	void _allocRoot(value_type val) {
		_root = _newNode(nullptr, val, _black);
		_root->left = _beginNode;
		_root->right = _endNode;
		_beginNode->parent = _root;
		_endNode->parent = _root;
	}

	std::pair<iterator, bool> _insert(TreeNode **rootOfSubtree, const value_type & val) {
		int cmpResult = _cmp(val.first, (*rootOfSubtree)->data->first) + 2 * _cmp((*rootOfSubtree)->data->first, val.first);

		if (!cmpResult)
			return std::make_pair((*rootOfSubtree), false);

		if (cmpResult == 1 && ((*rootOfSubtree)->left == nullptr || (*rootOfSubtree)->left == _beginNode)) {
			TreeNode *toInsert = _newNode((*rootOfSubtree), val, _red);
			if ((*rootOfSubtree)->left == _beginNode)
				link(toInsert, _beginNode, left);
			link((*rootOfSubtree), toInsert, left);
			*rootOfSubtree = _balancing(*rootOfSubtree);
			return std::make_pair(iterator(toInsert), true);
		}
		else if (cmpResult == 2 && ((*rootOfSubtree)->right == nullptr || (*rootOfSubtree)->right == _endNode)) {
			TreeNode *toInsert = _newNode((*rootOfSubtree), val, _red);
			if ((*rootOfSubtree)->right == _endNode)
				link(toInsert, _endNode, right);
			link((*rootOfSubtree), toInsert, right);
			*rootOfSubtree = _balancing(*rootOfSubtree);
			return std::make_pair(iterator(toInsert), true);
		}
		else if (cmpResult == 1)
			return _insert(&((*rootOfSubtree)->left), val);
		return _insert(&((*rootOfSubtree)->right), val);
	}

		TreeNode *uncle(TreeNode * node) {
			if (node->parent == NULL or node->parent->parent == NULL)
				return NULL;
			if (node->parent->isOnLeft())
				return node->parent->parent->right;
			else
				return node->parent->parent->left;
		}
		bool isOnLeft(TreeNode * node) { return node == node->parent->left; }

		TreeNode *_sibling(TreeNode *node) {
			if (node->parent == NULL)
				return NULL;

			if (isOnLeft(node))
				return node->parent->right;
			return node->parent->left;
		}


		bool hasRedChild(TreeNode * node) {
			return (node->left != NULL and node->left->color == _red) or
				   (node->right != NULL and node->right->color == _red);
		}

		void swapValues(TreeNode *u, TreeNode *v) {
			value_type *temp = u->data;
			u->data = v->data;
			v->data = temp;
		}

		TreeNode *successor(TreeNode *x) {
			TreeNode *temp = x;
			while (temp->left != _beginNode)
				temp = temp->left;
			return temp;
		}


		TreeNode *BSTreplace(TreeNode *x) {
			if (x->left != NULL and x->right != NULL)
				return successor(x->right);
			if (x->left == NULL and x->right == NULL)
				return NULL;
			if (x->left != NULL && x->left != _beginNode)
				return x->left;
			else
				return x->right;
		}

		void deleteNode(Node *v) {
			TreeNode *u = BSTreplace(v);
			if (u == _beginNode) {
				std::cout << std::endl;
				u = _beginNode->parent;
			}
			bool uvBlack = ((u == NULL or u->color == _black) and (v->color == _black));
			TreeNode *parent = v->parent;

			if (u == NULL) {
				if (v == _root)
					_root = NULL;
				else {
					if (uvBlack)
						fixDoubleBlack(v);
					else
						if (_sibling(v) != NULL)
							_sibling(v)->color = _red;
					if (isOnLeft(v))
						parent->left = NULL;
					else
						parent->right = NULL;
				}
				_destroyNode(v);
				return;
			}

			if (v->left == NULL or v->right == NULL) {
				if (v == _root) {
					v->data = u->data;
					v->left = v->right = NULL;
					_destroyNode(u);
				} else {
					if (isOnLeft(v)) {
						parent->left = u;
					} else {
						parent->right = u;
					}
					_destroyNode(v);
					u->parent = parent;
					if (uvBlack) {
						fixDoubleBlack(u);
					} else {
						u->color = _black;
					}
				}
				return;
			}
			swapValues(u, v);
			deleteNode(u);
		}

		void _erase(key_type key) {
			if (_root == NULL)
				return;
			TreeNode *v = find(key).getNode(), *u;

			if (v == _root && _size == 1) {
				_destroyNode(_root);
				//_endNode->right = _beginNode;
				_beginNode->right = _endNode;
				_endNode->left = _beginNode;
				return;
			}
			if (v == _endNode) {
				return;
			}

			deleteNode(v);
		}

		void fixDoubleBlack(Node *x) {
			if (x == _root)
				return;

			TreeNode *sibling = _sibling(x);
			TreeNode *parent = x->parent;
			if (sibling == NULL) {
				fixDoubleBlack(parent);
			} else {
				if (sibling->color == _red) {
					parent->color = _red;
					sibling->color = _black;
					if (isOnLeft(sibling)) {
						_rightRotate(parent);
					} else {
						_leftRotate(parent);
					}
					fixDoubleBlack(x);
				} else {
					if (hasRedChild(sibling)) {
						if (sibling->left != NULL and sibling->left->color == _red) {
							if (isOnLeft(sibling)) {
								sibling->left->color = sibling->color;
								sibling->color = parent->color;
								_rightRotate(parent);
							} else {
								sibling->left->color = parent->color;
								_balancing(sibling);
							}
						} else {
							if (isOnLeft(sibling)) {
								sibling->right->color = parent->color;
								_balancing(sibling);
							} else {
								sibling->right->color = sibling->color;
								sibling->color = parent->color;
								_leftRotate(parent);
							}
						}
						parent->color = _black;
					} else {
						sibling->color = _red;
						if (parent->color == _black)
							fixDoubleBlack(parent);
						else
							parent->color = _black;
					}
				}
			}
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
		//clear();
		//_ptr_alloc.deallocate(_endNode, 1);
		//_ptr_alloc.deallocate(_endNode, 1);
	}

	map& operator= (const map& x) {
		if (this != &x) {
			//clear();
			this->insert(x.begin(), x.end());
		}
		return *this;
	}

	void clear() {;
		//while (_size)
		//	erase(begin());
	}

	iterator 					begin() { return _size ? iterator(_beginNode->parent) : iterator(_endNode); }

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

	mapped_type& operator[] (const key_type& k) { return (*((this->insert(make_pair(k,mapped_type()))).first)).second; }

	std::pair<iterator,bool> insert (const value_type& val) {
		if (_size == 0) {
			_allocRoot(val);
			return std::make_pair(iterator(_root), true);
		}
		return _insert(&_root, val);
	}

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

	key_compare key_comp() const { return _cmp; }

	value_compare value_comp() const { return value_compare(_cmp); };

	iterator lower_bound (const key_type& k) { return  begin(); }// _treeBound(_root, k, true); }

	const_iterator lower_bound (const key_type& k) const { return const_iterator(_root); }//_treeBound(_root, k, true); }

	iterator upper_bound (const key_type& k) { return  begin(); }// _treeBound(_root, k, false); }

	const_iterator upper_bound (const key_type& k) const { return const_iterator(_root); }//_treeBound(_root, k, false); }

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

	void erase (iterator position) {};

	size_type erase (const key_type& k){
		_erase(k);
		return 1;
	};

	void erase (iterator first, iterator last){};




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
