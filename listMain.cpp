#include <list>
#include <iostream>
#include <math.h>
#include <map>
#include "ft_map.h"
int main() {
	std::map<int, int> map1;
	ft::map<int, int> map;

	map.insert(std::pair<int,int> (17, 6));
	map.insert(std::pair<int, int>(15, 7));
	map.insert(std::pair<int, int>(19, 8));
	map.insert(std::pair<int, int>(12, 9));
	map.insert(std::pair<int, int>(16, 0));
	map.insert(std::pair<int, int>(20, 0));
	map.insert(std::pair<int, int>(22, 0));

	std::cout << map.size() << std::endl;

	for (ft::map<int, int>::iterator i = map.begin(); i != map.end(); ++i)
		std::cout << i->first << std::endl;

}