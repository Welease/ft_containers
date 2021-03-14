#include <list>
#include <iostream>
#include <math.h>
#include <map>

int main() {
	std::map <int, std::string> m;
	m.insert(m.begin(), std::make_pair<int, std::string> (8, "first"));
	m.insert(m.begin(), std::make_pair<int, std::string> (5, "first"));
	m.insert(m.begin(), std::make_pair<int, std::string> (10, "first"));
	m.insert(m.begin(), std::make_pair<int, std::string> (3, "first"));
	m.insert(m.begin(), std::make_pair<int, std::string> (6, "first"));
	m.insert(m.begin(), std::make_pair<int, std::string> (9, "first"));
	m.insert(m.begin(), std::make_pair<int, std::string> (11, "first"));
	for (std::map<int, std::string>::iterator i = m.begin(); i != m.end(); ++i)
		std::cout << i->first << std::endl;
}