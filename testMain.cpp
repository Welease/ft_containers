//
// Created by Wynn Elease on 3/17/21.
//

#include <map>
#include "ft_map.h"
#include <iostream>
#include <sstream>

int main() {
//	std::stringstream ss;
//	std::map<std::string, int> s;
//	ft::map<std::string, int>  f;
//
//	for (char i = 'b'; i < 'z' ; ++i) {
//		ss << i << i;
//		s.insert(std::make_pair(ss.str(), i));
//		f.insert(std::make_pair(ss.str(), i));
//		ss.str("");
//		f._dPrintStrangeTree();
//	}
//
//
//	std::map<std::string, int>::iterator its;
//	ft::map<std::string,  int>::iterator itf;
//	std::map<std::string, int>::iterator itse;
//	ft::map<std::string,  int>::iterator itfe;
//
//	its = s.begin();
//	itf = f.begin();
//
//	for (int i = 0; i < 10; ++i) {
//		f._dPrintStrangeTree();
//		s.erase(++s.begin());
//
//		f.erase(++f.begin());
//	}
//
//	std::cout << f.size() << " " << s.size() << std::endl;

	std::map<int, int> s;
	ft::map<int, int>  f;
	std::map<int, int>::iterator its;
	ft::map<int,  int>::iterator itf;

	f.insert(std::make_pair(30,0));
	f.insert(std::make_pair(40,0));
	f.insert(std::make_pair(50,0));
	f.insert(std::make_pair(35,0));
	f.insert(std::make_pair(20,0));
	f.insert(std::make_pair(9,0));
	f.insert(std::make_pair(8,0));
	f.insert(std::make_pair(5,0));
	f.insert(std::make_pair(4,0));

	s.insert(std::make_pair(30,0));
	s.insert(std::make_pair(40,0));
	s.insert(std::make_pair(50,0));
	s.insert(std::make_pair(35,0));
	s.insert(std::make_pair(20,0));
	s.insert(std::make_pair(9,0));
	s.insert(std::make_pair(8,0));
	s.insert(std::make_pair(5,0));
	s.insert(std::make_pair(4,0));

	f._dPrintStrangeTree();

	its = s.begin();
	itf = f.begin();
	ft::map<int, int>::iterator tmp;


	for (int i = 0; i < 7; ++i) {
//		tmp = ++.begin();
		s.erase(++s.begin());
//		f._dPrintStrangeTree();
	}

	for (; its != s.end(); ++itf)
		std::cout << itf->first << std::endl;

	return 0;
}
