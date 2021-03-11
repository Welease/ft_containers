#include <list>
#include <iostream>
#include "ft_list.h"
#include <math.h>
// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
	bool operator() (double first, double second)
	{ return (fabs(first-second)<5.0); }
};

int main ()
{
//	double mydoubles[] = {12.15, 2.72, 73.0, 12.77, 3.14,
//						  12.77, 73.35, 72.25, 15.3, 72.25};
//	std::list<double> mylist(mydoubles, mydoubles + 10);
////
//	mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
//	// 15.3,  72.25, 72.25, 73.0,  73.35
//
//	std::cout << std::endl;
//	for (std::list<double>::iterator i = mylist.begin(); i != mylist.end(); ++i){
//		std::cout << *i << " ";
//	}
//	std::cout << std::endl;
//	mylist.unique();           //  2.72,  3.14, 12.15, 12.77
//	//mylist.unique(same_integral_part);  //  2.72,  3.14, 12.15
//	//mylist.unique(is_near());           //  2.72, 12.15, 72.25
//	std::cout << "mylist contains:";
//	for (std::list<double>::iterator it = mylist.begin(); it != mylist.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << "\n\n\n";
//
//	double mydoubles1[] = {12.15, 2.72, 73.0, 12.77, 3.14,
//						  12.77, 73.35, 72.25, 15.3, 72.25};
//	ft::list<double> mylist1(mydoubles1, mydoubles1 + 10);
//
//	mylist1.sort();
//
//	std::cout << std::endl;
//	for (ft::list<double>::iterator i = mylist1.begin(); i != mylist1.end(); ++i){
//		std::cout << *i << " ";
//	}
//	std::cout << std::endl;
//
//	mylist1.unique();           //  2.72,  3.14, 12.15, 12.77
//	//mylist1.unique(same_integral_part);  //  2.72,  3.14, 12.15
//	//mylist1.unique(is_near());           //  2.72, 12.15, 72.25
//	std::cout << "mylist contains:";
//	for (ft::list<double>::iterator it = mylist1.begin(); it != mylist1.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';

	std::list<int> l;
	l.push_back(3);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	l.unique();

	ft::list<int> b;
	b.push_back(3);
	b.push_back(3);
	b.push_back(4);
	b.push_back(5);

	b.unique();

	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	for (ft::list<int>::iterator it = b.begin(); it != b.end(); ++it)
		std::cout << ' ' << *it;
}