#include <list>
#include <iostream>
#include "ft_list.h"

int main(){

//	ft::list<int> list;
	ft::list<int> list1(5, 3);
	for (ft::list<int>::iterator i = list1.begin(); i != list1.end(); ++i){
		std::cout << *i << std::endl;
	}

	std::list<int> l;
	std::list<int> c;
	//std::list<int> list1(5, 3);
	//for (std::list<int>::iterator i = list1.begin(); i != list1.end(); ++i){
	//	std::cout << *i << std::endl;
	//}

}