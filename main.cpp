//
// Created by Wynn Elease on 3/17/21.
//

#include <list>
#include <vector>
#include <map>
#include <queue>
#include <stack>

#include "ft.h"
#include "ft_list.h"
#include "ft_vector.h"
#include "ft_stack.h"
#include "ft_queue.h"
#include "ft_map.h"

int main() {
	std::list<std::string> sl;
	ft::list<std::string> fl;
	std::list<std::string> sl1;
	ft::list<std::string> fl1;
	bool ret = sl.size() == fl.size();
	std::cout << ret << std::endl;

	for (int i = 0; i < 20; ++i) {
		sl.push_back(std::to_string(i));
		fl.push_back(std::to_string(i));
	}

	ret = sl.size() == fl.size();
	std::cout << ret << std::endl;

	ret = *sl.begin() == *fl.begin();
	std::cout << ret << std::endl;

	for (int i = 100; i < 120; ++i) {
		sl.push_back(std::to_string(i));
		fl.push_back(std::to_string(i));
	}

	for (int i = 1; i < 5; ++i) {
		fl.pop_back();
		sl.pop_back();
	}

	ret = fl.size() == sl.size();
	std::cout << ret << std::endl;

	fl.assign(fl1.begin(), fl1.end());
	sl.assign(sl1.begin(), sl1.end());

	ret = fl.size() == sl.size();
	std::cout << ret << std::endl;

	std::cout << ret << std::endl;

	for (int i = 320; i < 340; ++i) {
		sl.push_front(std::to_string(i));
		fl.push_front(std::to_string(i));
		sl.pop_back();
		fl.pop_back();
	}

	ret = fl.size() == sl.size();
	std::cout << ret << std::endl;

	sl.insert(sl.begin(), ++++++sl1.begin(), sl1.end());
	fl.insert(fl.begin(), ++++++fl1.begin(), fl1.end());

	ret = fl.size() == sl.size();
	std::cout << ret << std::endl;

	std::cout << ret << std::endl;

	sl.erase(sl.begin(), ++++++sl.begin());
	fl.erase(fl.begin(), ++++++fl.begin());

	ret = fl.size() == sl.size();
	std::cout << ret << std::endl;

	std::cout << ret << std::endl;

	fl.swap(fl1);
	sl.swap(sl1);

	ret = fl.size() == sl.size();
	std::cout << ret << std::endl;

	std::cout << ret << std::endl;

	sl.resize(2);
	fl.resize(2);

	ret = fl.size() == sl.size();
	std::cout << ret << std::endl;

	std::cout << ret << std::endl;

	fl.clear();
	sl.clear();

	ret = fl.size() == sl.size();
	std::cout << ret << std::endl;

	std::cout << ret << std::endl;

	for (int i = 100; i < 120; ++i) {
		sl.push_back(std::to_string(i));
		fl.push_back(std::to_string(i));
	}

	sl.splice(++++++sl1.begin(), sl1);
	fl.splice(++++++fl.begin(), fl1);

	ret = fl.size() == sl.size();
	std::cout << ret << std::endl;


	fl.push_back("hello");
	sl.push_back("hello");

	fl.remove("hello");
	sl.remove("hello");

	ret = fl.size() == sl.size();
	std::cout << ret << std::endl;


	for (int i= 1, j = 4; j < 10; ++j) {
		sl.push_back(std::to_string(i));
		fl.push_back(std::to_string(i));
	}

	sl.unique();
	fl.unique();

	ret = fl.size() == sl.size();
	std::cout << ret << std::endl;


	fl.sort();
	sl.sort();

	ret = fl.size() == sl.size();
	std::cout << ret << std::endl;


	fl.reverse(); sl.reverse();

	ret = fl.size() == sl.size();
	std::cout << ret << std::endl;




}
