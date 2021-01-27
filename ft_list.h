#ifndef FT_CONTAINERS_FT_LIST_H
#define FT_CONTAINERS_FT_LIST_H
#include <iostream>
#include <memory>
template<class T> class ListNode {
	struct SListNode *prev;
	struct SListNode *next;
	T content;
};

namespace ft{
	template < class T, class Alloc = std::allocator<T> >
	class List{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef size_t size_type;
		class iterator;
		class const_iterator;
		class reverse_iterator;
		class const_reverse_iterator;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;


		explicit List(const allocator_type& alloc = allocator_type());
		explicit List(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
		template <class InputIterator> List (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
		List (const List& x);
		~List();
		List& operator= (const List& x);
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;
		bool empty() const;
		size_type size() const;
		size_type max_size() const;
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last);
		void assign (size_type n, const value_type& val);
		void push_front (const value_type& val);
		void pop_front();
		iterator insert (iterator position, const value_type& val);
		void insert (iterator position, size_type n, const value_type& val);
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);
		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
		void swap (List& x);
		void resize (size_type n, value_type val = value_type());
		void clear();
		void splice (iterator position, List& x);
		void splice (iterator position, List& x, iterator i);
		void splice (iterator position, List& x, iterator first, iterator last);
		void remove (const value_type& val);
		template <class Predicate>
		void remove_if (Predicate pred);
		void unique();
		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred);
		void merge (List& x);
		template <class Compare>
		void merge (List& x, Compare comp);
		void sort();
		template <class Compare>
		void sort (Compare comp);
		void reverse();
		class iterator : public std::iterator<std::bidirectional_iterator_tag, value_type>{
		private:
			value_type *_element;
		public:
			iterator(){_element = nullptr;}
			iterator & operator=(iterator const & iterator1){
				if (this != &iterator1){
					_element = iterator1._element;
				}
				return *this;
			}
			iterator(iterator const & iterator1){
				*this = iterator1;
			};
			iterator(T *el) : _element(el){};
			~iterator() {};

			bool operator==(iterator const & iterator){
				return (iterator._element == _element);
			}
			bool operator!=(iterator const & iterator){
				return (iterator._element != _element);
			}


			iterator & operator++(){ //pref
				_element--;
				return *this;
			}
			iterator & operator--(){ //pref
				_element++;
				return *this;
			}


			T operator*() {
				return *_element;
			}
		//	List<value_type>::iterator operator++(int){ //post
		//		List<value_type>::iterator copy = *this;
		//		operator++();
		//		return copy;
		//	}
		//	List<value_type>::iterator operator--(int){ //post
		//		List<value_type>::iterator copy = *this;
		//		operator--();
		//		return copy;
		//	}
		};
	};


};

#endif //FT_CONTAINERS_FT_LIST_H
