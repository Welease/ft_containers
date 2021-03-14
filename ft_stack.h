//
// Created by Wynn Elease on 3/11/21.
//

#ifndef FT_CONTAINERS_FT_STACK_H
#define FT_CONTAINERS_FT_STACK_H
#include "ft_list.h"

namespace ft {
	template<class T, class Container = list<T> >
	class stack
	{

	public:
		typedef Container container_type;
		typedef T value_type;
		typedef size_t size_type;

		explicit stack(const container_type &ctnr = container_type()) : _stack(ctnr) {};

		~stack() {};

		bool empty() const { return _stack.empty(); };

		size_type size() const { return _stack.size(); };

		value_type &top() { return _stack.back(); };

		const value_type &top() const { return _stack.back(); };

		void push(const value_type &val) { _stack.push_back(val); };

		void pop() { _stack.pop_back(); };

		container_type getStack() const { return _stack; }

	private:
		container_type _stack;
	};
		template <class T, class Container> bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs.getStack() == rhs.getStack();
		}
		template <class T, class Container> bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs.getStack() != rhs.getStack();
		}
		template <class T, class Container> bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs.getStack() < rhs.getStack();
		}
		template <class T, class Container> bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs.getStack() <= rhs.getStack();
		}
		template <class T, class Container> bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs.getStack() > rhs.getStack();
		}
		template <class T, class Container> bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs.getStack() >= rhs.getStack();
		}
};

#endif //FT_CONTAINERS_FT_STACK_H
