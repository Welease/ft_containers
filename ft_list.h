#ifndef FT_CONTAINERS_FT_LIST_H
#define FT_CONTAINERS_FT_LIST_H
#include <iostream>
#include <memory>
template<typename value_type> struct ListNode {
	struct ListNode *prev;
	struct ListNode *next;
	value_type *content;
};

namespace ft
{
	template<bool Cond, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };

	template<class T, class Alloc = std::allocator<T> >
	class list
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;

		class iterator;

		class const_iterator;

		class reverse_iterator;

		class const_reverse_iterator;

		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		explicit list(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _size(0){
			createAbstractNode();
		};

		explicit list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()){
			createAbstractNode();
			_alloc = alloc;
			for (size_t i = 0; i < n; ++i){
				this->push_front(val);
			}
		};

		template<class InputIterator>
		list(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
			 typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0){
			createAbstractNode();
			while (first != last){
				push_back(*first);
				++first;
			}
		};

		list(const list &x) : _size(0){
			createAbstractNode();
			*this = x;
		};

		~list(){
			clearList();
			_alloc.deallocate(_abstractNode->content, 1);
			_ptr_alloc.deallocate(_abstractNode, 1);
		};

		list &operator=(const list &x){
			if (this != &x){
				clearList();
				_size = x._size;
				size_type s = x._size;
				t_node *tmp = x._abstractNode->next;
				for (; s > 0; s--){
					push_back(*tmp->content);
				}
			}
			return *this;
		}

		iterator begin(){return iterator(_abstractNode->next);};

		const_iterator begin() const {return const_iterator(_abstractNode->next);};

		iterator end(){return iterator(_abstractNode);};

		const_iterator end() const {return const_iterator(_abstractNode);};

		reverse_iterator rbegin() {return reverse_iterator(_abstractNode->next);};

		const_reverse_iterator rbegin() const {return const_reverse_iterator(_abstractNode->next);};

		reverse_iterator rend(){return reverse_iterator(_abstractNode);};

		const_reverse_iterator rend() const {return const_reverse_iterator(_abstractNode);}

		bool empty() const {return _size == 0;};

		size_type size() const { return _size;};

		size_type max_size() const {std::numeric_limits<value_type>::max() / sizeof(value_type) / (sizeof(value_type) == 1 ? 2 : 1);};
		
		reference front(){return *(this->begin());};

		const_reference front() const {return *(this->begin());};

		reference back(){return *(--(this->end()));};

		const_reference back() const{return *(--(this->end()));};

		template<class InputIterator>
		void assign(InputIterator first, InputIterator last,
			  typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0){
			clearList();
			while (first != last){
				push_back(*first);
				++first;
			}
		};

		void assign(size_type n, const value_type &val){
			clearList();
			while (n--){
				push_back(val);
			}
		};

		void push_front(const value_type &val){
			t_node *tmp = _abstractNode->next;
			t_node *newNode = addNode();
			_abstractNode->next = newNode;
			tmp->prev = newNode;
			fillContent(newNode, val, tmp, _abstractNode);
			_size++;
		};

		void pop_front(){
			t_node *oldBegin = this->begin().getNode();
			t_node *newBegin = oldBegin->next;
			_abstractNode->next = newBegin;
			newBegin->prev = _abstractNode;
			deleteNode(oldBegin);
			_size--;
		};

		void push_back (const value_type& val){
			t_node *tmp = _abstractNode->prev;
			t_node *newNode = addNode();
			_abstractNode->prev = newNode;
			tmp->next = newNode;
			fillContent(newNode, val, _abstractNode, tmp);
			this->_size++;
		};

		void pop_back(){
			t_node *tmp = _abstractNode->prev;
			tmp->prev->next = _abstractNode;
			_abstractNode->prev = tmp->prev;
			deleteNode(tmp);
			_size--;
		};

		iterator insert(iterator position, const value_type &val){
			iterator tmp = this->begin();
			while (tmp != position && tmp != this->end()){
				tmp++;
			}
			if (tmp == this->end()){
				*position = val;
				return position;
			}
			t_node *newNode = addNode();
			t_node *nextNode = tmp.getNode();
			t_node *prevNode = nextNode->prev;
			nextNode->prev = newNode;
			prevNode->next = newNode;
			fillContent(newNode, val, nextNode, prevNode);
			_size++;
			return iterator(newNode);
		};

		void insert(iterator position, size_type n, const value_type &val){
			while (n--){
				insert(position, val);
			}
		};

		template<class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0){
			InputIterator i = first;
			iterator tmp = position;
			while (i != last){
				tmp = insert(tmp, *i);
				i++;
			}
		};

		iterator erase(iterator position){
			iterator tmp = this->begin();
			while (tmp != position && tmp != this->end()){
				tmp++;
			}
			if (tmp == this->end()){
				return position;
			}
			t_node *prevNode = tmp.getNode()->prev;
			t_node *nextNode = prevNode->next->next;
			prevNode->next = nextNode;
			nextNode->prev = prevNode;
			deleteNode(tmp.getNode());
			return iterator(nextNode);
		};

		iterator erase(iterator first, iterator last){
			iterator tmp = first;
			iterator i;
			if (tmp == last)
				return (iterator(tmp));
			while (tmp != last){
				i = erase(tmp);
				tmp++;
			}
			return i;
		};

		void swap(list &x){
			t_node *tmp = x._abstractNode;
			x._abstractNode = this->_abstractNode;
			this->_abstractNode = tmp;
		};

		void resize(size_type n, value_type val = value_type()){
			if (n > _size){
				while (_size != n){
					push_back(val);
				}
			}
			else {
				while (_size != n){
					pop_back();
				}
			}
		};

		void clear(){
			clearList();
		};

		void splice(iterator position, list &x);

		void splice(iterator position, list &x, iterator i);

		void splice(iterator position, list &x, iterator first, iterator last);

		void remove(const value_type &val);

		template<class Predicate>
		void remove_if(Predicate pred);

		void unique();

		template<class BinaryPredicate>
		void unique(BinaryPredicate binary_pred);

		void merge(list &x);

		template<class Compare>
		void merge(list &x, Compare comp);

		void sort();

		template<class Compare>
		void sort(Compare comp);

		void reverse();

		class iterator : public std::iterator<std::bidirectional_iterator_tag, value_type>
		{
		protected:
			ListNode<value_type> *_node;
		public:
			iterator(){ _node = nullptr; }

			iterator &operator=(iterator const &iterator1){
				if (this != &iterator1){
					_node = iterator1._node;
				}
				return *this;
			}

			iterator(iterator const &iterator1){*this = iterator1;};

			iterator(ListNode<value_type> *el){_node = el;};

			~iterator(){};

			bool operator==(iterator const &iterator) const {return iterator.getNode() == this->_node;}
			bool operator==(const_iterator const &constIterator) const {return constIterator._node == this->_node;}
			bool operator!=(iterator const &iterator) const {return iterator.getNode() != this->_node;}
			bool operator!=(const_iterator const &constIterator) const {return constIterator._node != this->_node;}

			virtual iterator &operator++(){ //pref
				_node = _node->next;
				return *this;
			}

			virtual iterator operator++(int){ //post
				iterator tmp(*this);
				_node = _node->next;
				return tmp;
			}

			virtual iterator &operator--(){ //pref
				_node = _node->prev;
				return *this;
			}

			virtual iterator operator--(int){ //post
				iterator tmp(*this);
				_node = _node->prev;
				return tmp;
			}

			value_type &operator*(){return *this->_node->content;}

			value_type *operator->(){return this->_node->content;}

			ListNode<value_type> *getNode() const {return this->_node;}
		};

		class const_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type>
		{
		protected:
			ListNode<value_type> *_node;
		public:
			const_iterator(){ _node = nullptr; }

			const_iterator &operator=(iterator const &iterator1){
				_node = iterator1.getNode();
				return *this;
			}

			const_iterator &operator=(const_iterator const &iterator1){
				if (this != &iterator1){
					_node = iterator1._node;
				}
				return *this;
			}

			const_iterator(iterator const &iterator1){*this = iterator1;};

			const_iterator(const_iterator const &iterator1){*this = iterator1;}

			const_iterator(ListNode<value_type> *el){_node = el;};

			~const_iterator(){};

			bool operator==(iterator const &iterator) const{return iterator.getNode() == this->_node;}
			bool operator==(const_iterator const &constIterator) const{return constIterator._node == this->_node;}
			bool operator!=(iterator const &iterator){return iterator.getNode() == this->_node;}
			bool operator!=(const_iterator const &constIterator){return constIterator._node == this->_node;}

			virtual const_iterator &operator++(){ //pref
				_node = _node->next;
				return *this;
			}
			virtual const_iterator operator++(int){ //post
				iterator tmp(this->_node);
				_node = _node->next;
				return tmp;
			}
			virtual const_iterator &operator--(){ //pref
				_node = _node->prev;
				return *this;
			}
			virtual const_iterator operator--(int){ //post
				iterator tmp(this->_node);
				_node = _node->prev;
				return tmp;
			}

			value_type &operator*(){return *(this->_node->content);}

			value_type *operator->(){return this->_node->content;}
		};

		class reverse_iterator : public ft::list<value_type>::iterator{
		public:
			reverse_iterator &operator++(){ //pref
				this->_node = this->_node->next;
				return *this;
			}
			reverse_iterator operator++(int){ //post
				iterator tmp(*this);
				this->_node = this->_node->next;
				return tmp;
			}
			reverse_iterator &operator--(){ //pref
				this->_node = this->_node->prev;
				return *this;
			}
			reverse_iterator operator--(int){ //post
				iterator tmp(*this);
				this->_node = this->_node->prev;
				return tmp;
			}
		};

		class const_reverse_iterator : public ft::list<value_type>::const_iterator{
		public:
			const_reverse_iterator &operator++(){ //pref
				this->_node = this->_node->next;
				return *this;
			}
			const_reverse_iterator operator++(int){ //post
				iterator tmp(*this);
				this->_node = this->_node->next;
				return tmp;
			}
			const_reverse_iterator &operator--(){ //pref
				this->_node = this->_node->prev;
				return *this;
			}
			const_reverse_iterator operator--(int){ //post
				iterator tmp(*this);
				this->_node = this->_node->prev;
				return tmp;
			}
		};

	private:
		typedef ListNode<value_type> t_node;
		t_node *_abstractNode;
		size_type _size;

		typedef typename allocator_type::template rebind<ListNode<value_type> >::other PtrAllocator;

		allocator_type _alloc;        // Распределитель для значений типа T
		PtrAllocator _ptr_alloc;  // Распределитель для значений типа T*

		t_node *addNode(){
			t_node *node = _ptr_alloc.allocate(1);
			node->content = _alloc.allocate(1);
 			return node;
		}

		void fillContent(t_node *node, value_type const & value, t_node *next, t_node *prev){
			node->next = next;
			node->prev = prev;
			_alloc.construct(node->content, value);
		}

		void deleteNode(t_node *node){
			_alloc.destroy(node->content);
			_alloc.deallocate(node->content, 1);
			_ptr_alloc.deallocate(node, 1);
		}

		void changeConnection(t_node *nodePrev, t_node *nodeNext){
			nodeNext->prev = nodePrev;
		}

		value_type getContent(t_node *node){return node->content;}

		void clearList(){
			t_node *tmp = _abstractNode->next;
			t_node *t;
			for (; _size > 0; --_size){
				t = tmp->next;
				deleteNode(tmp);
				tmp = t;
			}
		}

		void createAbstractNode(){
			_abstractNode = addNode();
			_abstractNode->content = nullptr;
			_abstractNode->next = _abstractNode;
			_abstractNode->prev = _abstractNode;
		}
	};

}
#endif //FT_CONTAINERS_FT_LIST_H
