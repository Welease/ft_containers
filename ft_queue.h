//
// Created by Wynn Elease on 3/11/21.
//

#ifndef FT_CONTAINERS_FT_QUEUE_H
#define FT_CONTAINERS_FT_QUEUE_H

#include "ft_list.h"

namespace ft {
	template <class T, class Container = list<T> >
	class queue {

	public:
		typedef Container 	container_type;
		typedef T 			value_type;
		typedef size_t 		size_type;

		explicit queue (const container_type& ctnr = container_type()) { _queue = ctnr; }

		~queue() {};

		bool empty() const { return _queue.empty(); };

		size_type size() const { return _queue.size(); };

		value_type &front() { return _queue.front(); };

		const value_type &front() const { return _queue.front(); };

		value_type &back() { return _queue.back(); };

		const value_type &back() const { return _queue.back(); };

		void push(const value_type &val) { _queue.push_back(val); };

		void pop() { _queue.pop_front(); };

		container_type getContainer() const { return _queue; }

	private:
		container_type _queue;
	};

	template <class T, class Container> bool operator==(const queue<T,Container>& lhs, const queue<T,Container>& rhs);
	template <class T, class Container> bool operator!=(const queue<T,Container>& lhs, const queue<T,Container>& rhs);
	template <class T, class Container> bool operator<(const queue<T,Container>& lhs, const  queue<T,Container>& rhs);
	template <class T, class Container> bool operator<=(const queue<T,Container>& lhs, const queue<T,Container>& rhs);
	template <class T, class Container> bool operator>(const queue<T,Container>& lhs, const queue<T,Container>& rhs);
	template <class T, class Container> bool operator>=(const queue<T,Container>& lhs, const queue<T,Container>& rhs);
}

template <class T, class Container> bool ft::operator==(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) {
	return lhs.getContainer() == rhs.getContainer();
}

template <class T, class Container> bool ft::operator!=(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) {
	return lhs.getContainer() != rhs.getContainer();
}

template <class T, class Container> bool ft::operator<(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) {
	return lhs.getContainer() < rhs.getContainer();
}

template <class T, class Container> bool ft::operator<=(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) {
	return lhs.getContainer() <= rhs.getContainer();
}

template <class T, class Container> bool ft::operator> (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) {
	return lhs.getContainer() > rhs.getContainer();
}

template <class T, class Container> bool ft::operator>=(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) {
	return  lhs.getContainer() >= rhs.getContainer();
}

#endif //FT_CONTAINERS_FT_QUEUE_H
