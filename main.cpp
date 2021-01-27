#include <list>
#include <iostream>

int main(){
	std::list<int> list(4, 5);
	std::list<int> list2((std::allocator<int>()));

}