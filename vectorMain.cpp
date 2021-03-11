#include <vector>
#include "ft_vector.h"
#include <iostream>

int main() {
	ft::vector<int> first;                                // empty vector of ints
	ft::vector<int> second (4,100);                       // four ints with value 100
	ft::vector<int> third (second.begin(),second.end());  // iterating through second
	ft::vector<int> fourth (third);                       // a copy of third

	for (ft::vector<int>::iterator i = second.begin(); i != second.end(); ++i)
		std::cout << *i << std::endl;

	std::cout << std::endl << std::endl;

	for (ft::vector<int>::iterator i = third.begin(); i != third.end(); ++i)
		std::cout << *i << std::endl;

	std::cout << std::endl << std::endl;

	for (ft::vector<int>::iterator i = fourth.begin(); i != fourth.end(); ++i)
		std::cout << *i << std::endl;

	std::vector<int> myvector (5);  // 5 default-constructed ints
	std::cout << std::endl << std::endl;
//	int i=0;
//
//	std::vector<int>::reverse_iterator rit = myvector.rbegin();
//	for (; rit!= myvector.rend(); ++rit)
//		*rit = ++i;
//
//	std::cout << "myvector contains:";
//	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//	std::cout << std::endl << std::endl;

	ft::vector<int> myvector1 (5, 5);
	int i=0;

	ft::vector<int>::reverse_iterator rit1 = myvector1.rbegin();
	for (; rit1 != myvector1.rend(); ++rit1)
		*rit1 = ++i;

	std::cout << "myvector1 contains:";
	for (ft::vector<int>::iterator it = myvector1.begin(); it != myvector1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';



}

