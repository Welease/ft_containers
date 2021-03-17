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
//
//	for (itf = f.begin(); itf != f.end(); ++itf)
//		std::cout << itf->first << std::endl;
//	return 0;
	ft::map<int,int> f;

	f.insert(std::make_pair(5, 0));
	f.insert(std::make_pair(10, 0));
	f.insert(std::make_pair(5, 0));
	f.insert(std::make_pair(10, 0));f.insert(std::make_pair(5, 0));
	f.insert(std::make_pair(10, 0));
	//f._dPrintStrangeTree();




	f.erase(5);
	//f._dPrintStrangeTree();
}
