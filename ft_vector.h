//
// Created by Wynn Elease on 3/11/21.
//

#ifndef FT_CONTAINERS_FT_VECTOR_H
#define FT_CONTAINERS_FT_VECTOR_H
#include <memory>
#include "ft.h"
namespace ft {
	template< class T, class Alloc = std::allocator<T> >
	class vector {

	public:
		class 												iterator;
		class 												const_iterator;
		class 												reverse_iterator;
		class 												const_reverse_iterator;
		typedef T 											value_type;
		typedef Alloc 										allocator_type;
		typedef typename allocator_type::reference 			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer 			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef size_t 										size_type;
		typedef ptrdiff_t 									difference_type;

	private:
		size_type		_size;
		size_type 		_capacity;
		pointer 		_mass;
		allocator_type _alloc;

	public:
		class iterator : public std::iterator<std::random_access_iterator_tag, value_type> {

		private:
			pointer _pointer;

		public:
			~iterator() {}
			iterator (iterator const & iter) { *this = iter; }
			iterator(pointer ptr = nullptr) : _pointer(ptr) { }
			iterator & operator=( iterator const & iter ) {
				if (this != &iter)
					_pointer = iter._pointer;
				return *this;
			}
			iterator & operator++() {
				this->_pointer++;
				return *this;
			}
			iterator & operator--() {
				this->_pointer--;
				return *this;
			}
			iterator operator++(int) {
				iterator temp = *this;
				this->operator++();
				return temp;
			}
			iterator operator--(int) {
				iterator temp = *this;
				this->operator--();
				return temp;
			}
			iterator operator+(difference_type const & dt) const { return iterator(_pointer + dt); }
			iterator operator-(difference_type const & dt) const { return iterator(_pointer - dt); }

			iterator operator+=(difference_type const & dt) {
				_pointer += dt;
				return *this;
			};

			iterator operator-=(difference_type const & dt) {
				_pointer -= dt;
				return *this;
			};

			bool operator==(iterator const & dt) const {return this->_pointer == dt._pointer; }
			bool operator!=(iterator const & dt) const { return this->_pointer != dt._pointer; }
			bool operator<=(iterator const & dt) const { return this->_pointer <= dt._pointer; }
			bool operator>=(iterator const & dt) const { return this->_pointer >= dt._pointer; }
			bool  operator<(iterator const & dt) const { return this->_pointer  < dt._pointer; }
			bool  operator>(iterator const & dt) const { return this->_pointer  > dt._pointer; }

			bool operator==(const_iterator const & dt) const { return this->_pointer == dt.getPointer(); }
			bool operator!=(const_iterator const & dt) const { return this->_pointer != dt.getPointer(); }
			bool operator<=(const_iterator const & dt) const { return this->_pointer <= dt.getPointer(); }
			bool operator>=(const_iterator const & dt) const { return this->_pointer >= dt.getPointer(); }
			bool  operator<(const_iterator const & dt) const { return this->_pointer  < dt.getPointer(); }
			bool  operator>(const_iterator const & dt) const { return this->_pointer  > dt.getPointer(); }

			value_type & operator[]( const_reference const & index ) const { return _pointer[index]; }
			value_type & operator*() const { return *this->_pointer; }
			value_type * operator->() const { return this->_pointer; }

			pointer getPointer() const { return _pointer; }
		};




		class const_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type const> {

		private:
			pointer _pointer;

		public:
			const_iterator() { this->_pointer = nullptr; }

			~const_iterator() {}

			const_iterator(const_iterator const & iter) { *this = iter; }

			const_iterator(iterator const & iter) { *this = iter; }

			const_iterator(pointer ptr) { this->_pointer = ptr; }

			const_iterator & operator=(const_iterator const & constIterator) {
				if (this != &constIterator)
					_pointer = constIterator._pointer;
				return *this;
			}

			const_iterator & operator=(iterator const & iter) {
				_pointer = iter.getPointer();
				return *this;
			}

			const_iterator & operator++() {
				this->_pointer++;
				return *this;
			}

			const_iterator & operator--() {
				this->_pointer--;
				return *this;
			}

			const_iterator operator++(int) {
				const_iterator temp = *this;
				this->operator++();
				return temp;
			}

			const_iterator operator--(int) {
				const_iterator tmp = *this;
				this->operator--();
				return tmp;
			}


			const_iterator operator+(difference_type const & dt) const { return const_iterator(_pointer + dt); }
			const_iterator operator-(difference_type const & dt) const { return const_iterator(_pointer - dt); }

			const_iterator operator+=(difference_type const & dt) {
				_pointer += dt;
				return *this;
			};

			const_iterator operator-=(difference_type const & dt) {
				_pointer -= dt;
				return *this;
			};

			bool operator==(const_iterator const & constIterator) const { return this->_pointer == constIterator._pointer; }
			bool operator!=(const_iterator const & constIterator) const { return this->_pointer != constIterator._pointer; }
			bool operator<=(const_iterator const & constIterator) const { return this->_pointer <= constIterator._pointer; }
			bool operator>=(const_iterator const & constIterator) const { return this->_pointer >= constIterator._pointer; }
			bool  operator<(const_iterator const & constIterator) const { return this->_pointer < constIterator._pointer; }
			bool  operator>(const_iterator const & constIterator) const { return this->_pointer > constIterator._pointer; }

			bool operator==(iterator const & iterator) const { return this->_pointer == iterator.getPointer(); }
			bool operator!=(iterator const & iterator) const { return this->_pointer != iterator.getPointer(); }
			bool operator<=(iterator const & iterator) const { return this->_pointer <= iterator.getPointer(); }
			bool operator>=(iterator const & iterator) const { return this->_pointer >= iterator.getPointer(); }
			bool  operator<(iterator const & iterator) const { return this->_pointer  < iterator.getPointer(); }
			bool  operator>(iterator const & iterator) const { return this->_pointer  > iterator.getPointer(); }

			value_type const & operator[]( difference_type const & index ) const { return *(this->_pointer + index); }
			const value_type & operator*() const { return *this->_pointer; }
			const value_type * operator->() const { return this->_pointer; }

			pointer getPointer() const { return _pointer; }
			};


	class reverse_iterator : public std::reverse_iterator<iterator> {
		private:
			pointer _pointer;
		public:
			reverse_iterator() {_pointer = nullptr;}
			~reverse_iterator() {};
			reverse_iterator (reverse_iterator const & iter ) { *this = iter; }
			reverse_iterator(pointer ptr) { this->_pointer = ptr; }

			reverse_iterator & operator=(reverse_iterator const & iter) {
				if (this != &iter)
					_pointer = iter._pointer;
				return *this;
			}
			reverse_iterator & operator++() {
				this->_pointer--;
				return *this;
			}
			reverse_iterator & operator--() {
				this->_pointer++;
				return *this;
			}
			reverse_iterator operator++(int) {
				reverse_iterator temp = *this;
				this->operator++();
				return temp;
			}
			reverse_iterator operator--(int) {
				reverse_iterator temp = *this;
				this->operator--();
				return temp;
			}

			reverse_iterator &operator+=(difference_type count) {
				_pointer -= count;
				return *this;
			};

			reverse_iterator &operator-=(difference_type count) {
				_pointer += count;
				return *this;
			};

			reverse_iterator operator+(difference_type count) const { return reverse_iterator(_pointer - count); };
			reverse_iterator operator-(difference_type count) const { return reverse_iterator(_pointer + count); };
			difference_type operator+(reverse_iterator &i) const { return _pointer - i._pointer; }
			difference_type operator-(reverse_iterator &i) const { return _pointer + i._pointer; }

			bool operator==(reverse_iterator const & dt) const {return this->_pointer == dt._pointer; }
			bool operator!=(reverse_iterator const & dt) const { return this->_pointer != dt._pointer; }
			bool operator<=(reverse_iterator const & dt) const { return this->_pointer >= dt._pointer; }
			bool operator>=(reverse_iterator const & dt) const { return this->_pointer <= dt._pointer; }
			bool  operator<(reverse_iterator const & dt) const { return this->_pointer > dt._pointer; }
			bool  operator>(reverse_iterator const & dt) const { return this->_pointer < dt._pointer; }

			bool operator==(const_reverse_iterator const & dt) const { return this->_pointer == dt.getPointer(); }
			bool operator!=(const_reverse_iterator const & dt) const { return this->_pointer != dt.getPointer(); }
			bool operator<=(const_reverse_iterator const & dt) const { return this->_pointer >= dt.getPointer(); }
			bool operator>=(const_reverse_iterator const & dt) const { return this->_pointer <= dt.getPointer(); }
			bool  operator<(const_reverse_iterator const & dt) const { return this->_pointer < dt.getPointer(); }
			bool  operator>(const_reverse_iterator const & dt) const { return this->_pointer > dt.getPointer(); }

			value_type & operator*() const { return *this->_pointer; }
			value_type * operator->() const { return this->_pointer; }
			const_reference operator[](const_reference ref) const { return *(_pointer - ref); };

			pointer getPointer() const { return _pointer; }
		};


		class const_reverse_iterator : public std::reverse_iterator<const_iterator> {
		private:
			pointer _pointer;
		public:
			const_reverse_iterator() : _pointer(nullptr) {}
			~const_reverse_iterator() {};
			const_reverse_iterator (reverse_iterator const & iter ) { *this = iter; }
			const_reverse_iterator (const_reverse_iterator const & iter ) { *this = iter; }
			const_reverse_iterator(pointer ptr) { this->_pointer = ptr; }
			const_reverse_iterator & operator=(const_reverse_iterator const & iter) {
				if (this != &iter)
					_pointer = iter._pointer;
				return *this;
			}

			const_reverse_iterator & operator=(reverse_iterator const & iter) {
				_pointer = iter.getPointer();
				return *this;
			}

			const_reverse_iterator & operator++() {
				this->_pointer--;
				return *this;
			}
			const_reverse_iterator & operator--() {
				this->_pointer++;
				return *this;
			}
			const_reverse_iterator operator++(int) {
				const_reverse_iterator temp = *this;
				this->operator++();
				return temp;
			}
			const_reverse_iterator operator--(int) {
				const_reverse_iterator temp = *this;
				this->operator--();
				return temp;
			}

			const_reverse_iterator operator+(difference_type val) const { return const_reverse_iterator(_pointer - val); };
			const_reverse_iterator operator-(difference_type val) const { return const_reverse_iterator(_pointer + val); };
			difference_type operator+(const_reverse_iterator &it) const { return _pointer - it._it; }
			difference_type operator-(const_reverse_iterator &it) const { return _pointer + it._it; }
			const_reverse_iterator &operator+=(difference_type count) {
				_pointer -= count;
				return *this;
			};

			const_reverse_iterator &operator-=(difference_type count) {
				_pointer += count;
				return *this;
			};

			const_reference operator[](const_reference cr) { return *(_pointer - cr); };
			const_reference operator*() { return *this->_pointer; }
			const_pointer operator->() { return this->_pointer; }

			bool operator==(reverse_iterator const & dt) const {return this->_pointer == dt.getPointer(); }
			bool operator!=(reverse_iterator const & dt) const { return this->_pointer != dt.getPointer(); }
			bool operator<=(reverse_iterator const & dt) const { return this->_pointer >= dt.getPointer(); }
			bool operator>=(reverse_iterator const & dt) const { return this->_pointer <= dt.getPointer(); }
			bool  operator<(reverse_iterator const & dt) const { return this->_pointer > dt.getPointer(); }
			bool  operator>(reverse_iterator const & dt) const { return this->_pointer < dt.getPointer(); }

			bool operator==(const_reverse_iterator const & dt) const { return this->_pointer == dt.getPointer(); }
			bool operator!=(const_reverse_iterator const & dt) const { return this->_pointer != dt.getPointer(); }
			bool operator<=(const_reverse_iterator const & dt) const { return this->_pointer >= dt.getPointer(); }
			bool operator>=(const_reverse_iterator const & dt) const { return this->_pointer <= dt.getPointer(); }
			bool  operator<(const_reverse_iterator const & dt) const { return this->_pointer > dt.getPointer(); }
			bool  operator>(const_reverse_iterator const & dt) const { return this->_pointer < dt.getPointer(); }

			pointer getPointer() const { return _pointer; }
		};

		explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _mass(nullptr), _alloc(alloc){}

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
					_size(n), _capacity(n), _alloc(alloc){
			_mass = _alloc.allocate(n);
			for (size_type i = 0; i < n; ++i)
				_alloc.construct(_mass + i, val);
		}

		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) : _mass(nullptr), _alloc(alloc), _size(0), _capacity(0) {
			iterator i = begin();
			while (last-- != first) {
				i = insert(i, *last);
			}
		}

		vector (const vector& x) : _size(x._size), _capacity(x._size), _alloc(x._alloc){
			_mass = _alloc.allocate(x._size);
			for (size_type i = 0; i < x._size; ++i)
				_alloc.construct(_mass + i, *(x._mass + i));
		}

		vector& operator= (const vector& x) {
			clear();
			insert(begin(), x.begin(), x.end());
			return *this;
		};

		iterator begin() { return iterator(_mass); }

		const_iterator begin() const { return const_iterator(_mass); }

		iterator end() { return iterator(_mass + _size); }

		const_iterator end() const { return const_iterator(_mass + _size); }

		reverse_iterator rbegin() { return reverse_iterator(_mass + _size - 1); }

		const_reverse_iterator rbegin() const { return const_reverse_iterator(_mass + _size - 1); }

		reverse_iterator rend() { return reverse_iterator(_mass - 1); }

		const_reverse_iterator rend() const { return const_reverse_iterator(_mass - 1); }

		size_type size() const { return _size; }

		size_type 	max_size() const { return std::numeric_limits<size_type>::max() / sizeof(_mass); };

		void resize (size_type n, value_type val = value_type ()) {
			if (n > _size)
				insert(end(), n - _size, val);
			if (n < _size)
				erase(iterator(end().getPointer() - (_size - n)), end());
		}

		size_type capacity() const { return _capacity; }

		bool empty() const { return !_size; }

		void 		reserve (size_type n) {
			if (n > max_size())
				throw std::length_error("wrong arg in reserve");
			if (_capacity > n)
				return;
			pointer newMass = _alloc.allocate(n);
			for (size_type i = 0; i < _size; ++i)
				_alloc.construct(newMass + i, *(_mass + i));
			for (size_type i = 0; i != _size; ++i)
				_alloc.destroy(_mass + i);
			if (_capacity)
				_alloc.deallocate(_mass, _capacity);
			_capacity = n;
			_mass = newMass;
		};

		reference operator[] (size_type n) { return _mass[n]; }

		const_reference operator[] (size_type n) const { return _mass + n; };

		reference at (size_type n) {
			if (n >= _size)
				throw std::out_of_range("incorrect index(out of range)");
			return _mass[n];
		}

		const_reference at (size_type n) const {
			if (n >= _size)
				throw std::out_of_range("incorrect index(out of range)");
			return _mass + n;
		}

		reference front() { return *_mass; };

		const_reference front() const { return *_mass; };

		reference back() { return *(_mass + _size - 1); };

		const_reference back() const { return *(_mass + _size - 1); };

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last) {
			clear();
			insert(begin(), first, last);
		}

		void assign (size_type n, const value_type& val) {
			clear();
			insert(begin(), n, val);
		}

		void push_back (const value_type& val) { insert(end(), val); }

		void pop_back() { erase(--end()); }

		iterator insert (iterator position, const value_type& val) {
			pointer pos = position.getPointer();
			if (!_capacity) {
				_mass = _alloc.allocate(1);
				_alloc.construct(_mass, val);
				_size = 1;
				_capacity = 1;
				pos = begin().getPointer();
			}
			else {
				if (_size + 1 > _capacity) {
					difference_type index = end().getPointer() - pos;
					reserve(_capacity * 2);
					pos = end().getPointer() - index;
				}
				std::memmove(pos + 1, pos, static_cast<size_type>((end().getPointer() - pos)) * sizeof(value_type));
				_alloc.construct(pos, val);
				_size += 1;
			}
			return iterator(pos);
		};

		void insert (iterator position, size_type n, const value_type& val) {
			pointer ptr = position.getPointer();
			if (_size + n  > _capacity) {
				difference_type tmp = end().getPointer() - ptr;
				reserve((_size + n) * 2);
				ptr =  end().getPointer() - tmp;
			}
			std::memmove(ptr + n, ptr, static_cast<size_type>((end().getPointer() - ptr)) * sizeof(value_type));
			for (size_type i = 0; i != n; ++i) {
				_alloc.construct(ptr + i, val);
			}
			_size += n;
		};

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
												   typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
			while (first != last) {
				position = insert(position, *first++);
				++position;
			}
		}

		iterator erase (iterator position) {
			pointer ptr = position.getPointer();
			_alloc.destroy(ptr);
			std::memmove(ptr, ptr + 1, static_cast<size_type>(abs((end().getPointer() - ptr))) * sizeof(value_type));
			--this->_size;
			return iterator(ptr);
		};

		iterator erase (iterator first, iterator last) {
			for (; first != last; )
				erase(--last);
			return last;
		};

		void swap (vector& x) {
			pointer tmpMass = x._mass;
			size_type tmpSize = x._size;
			size_type tmpCapacity = x._capacity;
			allocator_type tmpAlloc = x._alloc;

			x._mass = _mass;
			x._size = _size;
			x._capacity = _capacity;
			x._alloc = _alloc;

			_mass = tmpMass;
			_size = tmpSize;
			_capacity = tmpCapacity;
			_alloc = tmpAlloc;
		};

		void clear() {
			for (size_type i = 0; i != _size; ++i)
				_alloc.destroy(_mass + i);
			_size = 0;
		};

	};
	template <class T, class Alloc> bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		typename ft::vector<T, Alloc>::const_iterator lEnd = lhs.end();
		typename ft::vector<T, Alloc>::const_iterator rBegin = rhs.begin();

		if (lhs.size() != rhs.size())
			return false;
		for (typename ft::vector<T, Alloc>::const_iterator i = lhs.begin(); i != lEnd; ++i)
			if (*i != *rBegin++)
				return false;
		return true;
	}

	template <class T, class Alloc> bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return !(lhs == rhs); };
	template <class T, class Alloc> bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		typename ft::vector<T, Alloc>::const_iterator lBegin = lhs.begin();
		typename ft::vector<T, Alloc>::const_iterator rBegin = rhs.begin();

		while (lBegin != lhs.end() && rBegin != rhs.end()){
			if (*lBegin < *rBegin)
				return true;
			++lBegin;
			++rBegin;
		}
		if (lBegin == lhs.end() && rBegin != rhs.end())
			return true;
		return false;
	};

	template <class T, class Alloc> bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return !(rhs < lhs); };
	template <class T, class Alloc> bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (rhs < lhs); };
	template <class T, class Alloc> bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(lhs < rhs); };
}

#endif //FT_CONTAINERS_FT_VECTOR_H
