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
			_abstractNode = addNode(_abstractNode, _abstractNode);
			_abstractNode->content = nullptr;
		};

		explicit list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()){
			//*this = list(alloc);
			_abstractNode = addNode(_abstractNode, _abstractNode);
			_abstractNode->content = nullptr;
			_size = n;
			_alloc = alloc;
			t_node *tmp = _abstractNode;
			for (size_t i = 0; i < n; ++i){
				tmp->next = addNode(_abstractNode, tmp);
				fillContent(tmp->next, val);
				tmp = tmp->next;
			}
		};
		template<class InputIterator>
		list(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
			 typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0){

		};

		list(const list &x);

		~list(){
		//	for (iterator = *this->begin(); )
		};

		list &operator=(const list &x){
			if (*this != x){
				iterator i = this->begin();
				while (i != this->end()){
					deleteNode(i._node);
					i++;
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

		bool empty() const { _size != 0;};

		size_type size() const { _size;};

		size_type max_size() const {std::numeric_limits<value_type>::max() / sizeof(value_type) / (sizeof(value_type) == 1 ? 2 : 1);};
		
		reference front(){return *(this->begin());}; //todo maybe is not correct

		const_reference front() const {return *(this->begin());}; //todo maybe too

		reference back(){return ;};

		const_reference back() const;

		template<class InputIterator>
		void assign(InputIterator first, InputIterator last);

		void assign(size_type n, const value_type &val);

		void push_front(const value_type &val);

		void pop_front();

		iterator insert(iterator position, const value_type &val);

		void insert(iterator position, size_type n, const value_type &val);

		template<class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last);

		iterator erase(iterator position);

		iterator erase(iterator first, iterator last);

		void swap(list &x);

		void resize(size_type n, value_type val = value_type());

		void clear();

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
				if (this != &iterator1)
				{
					_node = iterator1._element;
				}
				return *this;
			}

			const_iterator &operator=(const_iterator const &iterator1){
				if (this != &iterator1)
				{
					_node = iterator1._element;
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
				iterator tmp(*this);
				_node = _node->next;
				return tmp;
			}
			virtual const_iterator &operator--(){ //pref
				_node = _node->prev;
				return *this;
			}
			virtual const_iterator operator--(int){ //post
				iterator tmp(*this);
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

		t_node *addNode(t_node *next, t_node *prev){
			t_node *node = _ptr_alloc.allocate(1);
			node->next = next;
			node->prev = prev;
			node->content = _alloc.allocate(1);
 			return node;
		}

		void fillContent(t_node *node, value_type const & value){
			_alloc.construct(node->content, value);
		}

		void deleteNode(t_node *node){
			_alloc.destruct(node->content);
			_alloc.deallocate(node->content);
			_ptr_alloc.deallocate(node);
		}

		value_type getContent(t_node *node){return node->content;}
	};

}
#endif //FT_CONTAINERS_FT_LIST_H
