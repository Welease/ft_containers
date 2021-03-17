#include <list>
#include <iostream>
#include <math.h>
#include <map>
#include "ft_map.h"

int main()
{
	std::map<int, int> map1;
	ft::map<int, int> map;

	map.insert(std::pair<int, int>(20, 8));
	//map.insert(std::pair<int, int>(30, 9));
	//map.insert(std::pair<int, int>(40, 7));
	//map.insert(std::pair<int, int>(35, 2));
	//map.insert(std::pair<int, int>(50, 0));


	for (ft::map<int, int>::iterator i = map.begin(); i != map.end(); ++i)
		std::cout << i->first << std::endl;

	//map.insert(std::pair<int, int>(50, 100));

	//std::cout << map.size() << std::endl << std::endl;
	//map.erase(12);
	//std::cout << map.size() << std::endl << std::endl;
	//map.erase(16);
	std::cout << std::endl << std::endl;
//	map.erase(40);
	//map.erase(30);
	//map.erase(40);
	//map.erase(20);
	//map.erase(50);
	//map.erase(35);



	for (ft::map<int, int>::iterator i = map.begin(); i != map.end(); ++i) {
		std::cout << i->first << " " << i->second << std::endl;
	}
}