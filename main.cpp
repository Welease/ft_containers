#include <list>
#include <iostream>
#include "ft_list.h"

int main(){

	//ft::list<int> list;
	//ft::list<int> list1(5, 3);
	//for (ft::list<int>::iterator i = --(list1.end()); i != list1.end(); --i){
	//	std::cout << *i << std::endl;
	//}
//
	//std::cout << std::endl << std::endl;
//
	//std::list<int> list12(5, 3);
	//for (std::list<int>::iterator i = --(list12.end()); i != list12.end(); --i){
	//	std::cout << *i << std::endl;
	//}
//
//
	//std::list<int> f(1, 34);
	//std::cout << f.back() << std::endl;
	//std::cout << f.front() << std::endl << std::endl;
//
	//ft::list<int> d(1, 34);
	//std::cout << d.back() << std::endl;
	//std::cout << d.front() << std::endl;

	//ASSIGN FUNC
//std::list<int> g(3, 7);
//std::list<int> a(5, 9);
//for (std::list<int>::iterator i = a.begin(); i != (a.end()); ++i){
//	std::cout << *i << std::endl;
//}

//a.assign(2, 10);
//for (std::list<int>::iterator i = a.begin(); i != a.end(); ++i){
//	std::cout << *i << std::endl;
//}

//PUSH FRONT

//ft::list<int> mylist (2,100);         // two ints with a value of 100
//mylist.push_front (200);
//mylist.push_front (300);
//std::cout << "mylist contains:";
//for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
//	std::cout << ' ' << *it;

//std::cout << std::endl;

//std::list<int> mylist1 (2,100);         // two ints with a value of 100
//mylist1.push_front (200);
//mylist1.push_front (300);


//std::cout << "mylist contains:";
//for (std::list<int>::iterator it=mylist1.begin(); it!=mylist1.end(); ++it)
//	std::cout << ' ' << *it;

//POP FRONT
	//std::list<int> mylist2;
	//mylist2.push_back (100);
	//mylist2.push_back (200);
	//mylist2.push_back (300);
//
	//std::cout << "Popping out the elements in mylist:";
	//while (!mylist2.empty())
	//{
	//	std::cout << ' ' << mylist2.front();
	//	mylist2.pop_front();
	//}
//
	//std::cout << "\nFinal size of mylist is " << mylist2.size() << '\n';

	//ft::list<int> mylist3;
	//mylist3.push_back (100);
	//mylist3.push_back (200);
	//mylist3.push_back (300);

	//for (ft::list<int>::iterator i = --(mylist3.end()); i != --(mylist3.begin()); --i)
	//{
	//	std::cout << *(i) << std::endl;
	//}

	//std::cout << "Popping out the elements in mylist:";
	//while (!mylist3.empty())
	//{
	//	std::cout << ' ' << mylist3.front();
	//	mylist3.pop_front();
	//}

	//std::cout << "\nFinal size of mylist is " << mylist3.size() << '\n';


	//std::list<int> mylist5;
	//int sum (0);
	//mylist5.push_back (100);
	//mylist5.push_back (200);
	//mylist5.push_back (300);

	//while (!mylist5.empty())
	//{
	//	sum+=mylist5.back();
	//	mylist5.pop_back();
	//}

	//std::cout << "The elements of mylist summed " << sum << '\n';

	//std::list<int> mylist6;
	//int sum1 (0);
	//mylist6.push_back (100);
	//mylist6.push_back (200);
	//mylist6.push_back (300);

	//while (!mylist6.empty())
	//{
	//	sum1+=mylist6.back();
	//	mylist6.pop_back();
	//}

	//std::cout << "The elements of mylist summed " << sum1 << '\n';

	//std::list<int> t(5, 100);
	//std::list<int> h(4, 6);

	//std::cout << *(t.insert(++t.begin(), 34)) << std::endl;
	//for (std::list<int>::iterator i = t.begin(); i != t.end(); ++i){
	//	std::cout << *i << std::endl;
	//}

	//ft::list<int> t1(5, 100);
	//ft::list<int> h1(4, 6);
	//std::cout << std::endl << std::endl;

	//std::cout << *(t1.insert(++t1.begin(), 34)) << std::endl;
	//for (ft::list<int>::iterator i = t1.begin(); i != t1.end(); ++i){
	//	std::cout << *i << std::endl;
	//}

	//std::list<int> t(5, 100);
	//std::list<int> h(4, 6);
//
	//t.insert(++t.begin(), 5, 34);
	//std::cout << "in list :" << std::endl;
	//for (std::list<int>::iterator i = t.begin(); i != t.end(); ++i){
	//	std::cout << *i << std::endl;
	//}
//
	//ft::list<int> t1(5, 100);
	//ft::list<int> h1(4, 6);
	//std::cout << std::endl << std::endl;
//
	//t1.insert(++t1.begin(), 5, 34);
	//std::cout << "in list :" << std::endl;
	//for (ft::list<int>::iterator i = t1.begin(); i != t1.end(); ++i){
	//	std::cout << *i << std::endl;
	//}


	//std::list<int> t(5, 100);
	//std::list<int> h(4, 6);
//
	//t.insert(++t.begin(), h.begin(), h.end());
	//std::cout << "in list :" << std::endl;
	//for (std::list<int>::iterator i = t.begin(); i != t.end(); ++i){
	//	std::cout << *i << std::endl;
	//}
//
	//ft::list<int> t1(5, 100);
	//ft::list<int> h1(4, 6);
	//std::cout << std::endl << std::endl;
//
	//t1.insert(++t1.begin(), h.begin(), h.end());
	//std::cout << "in list :" << std::endl;
	//for (ft::list<int>::iterator i = t1.begin(); i != t1.end(); ++i){
	//	std::cout << *i << std::endl;
	//}


	//std::list<int> mylist;
	//std::list<int>::iterator it1,it2;
//
	//for (int i=1; i<10; ++i) mylist.push_back(i*10);
//
	//it1 = it2 = mylist.begin(); // ^^
	//advance(it2,6);            // ^                 ^
	//++it1;                      //    ^              ^
//
	//it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
	//it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
	//std::cout << *it1 << std::endl;
	//++it1;                      //       ^        ^
	//--it2;                      //       ^     ^
	//mylist.erase (it1,it2);     // 10 30 60 80 90
	//std::cout << *(mylist.erase(mylist.begin(), mylist.begin())) << std::endl;
	//std::cout << "mylist contains:";
	//for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
	//	std::cout << ' ' << *it1;
	//std::cout << '\n';
//
//
	//ft::list<int> mylist1;
	//ft::list<int>::iterator it11,it21;
//
	//for (int i=1; i<10; ++i) mylist1.push_back(i*10);
//
	//it11 = it21 = mylist1.begin(); // ^^
	//advance(it21,6);            // ^                 ^
	//++it11;                      //    ^              ^
//
	//it11 = mylist1.erase (it11);   // 10 30 40 50 60 70 80 90
	//it21 = mylist1.erase (it21);   // 10 30 40 50 60 80 90
	//std::cout <<  *it11 << std::endl;
 	//++it11;                      //       ^        ^
	//--it21;                      //       ^     ^
	//mylist1.erase (it11,it21);     // 10 30 60 80 90
	//std::cout << *(mylist1.erase(mylist1.begin(), mylist1.begin())) << std::endl;
	//std::cout << "mylist contains:";
	//for (it11=mylist1.begin(); it11!=mylist1.end(); ++it11)
	//	std::cout << ' ' << *it11;
	//std::cout << '\n';


	//std::list<int> first (3,100);   // three ints with a value of 100
	//std::list<int> second (5,200);  // five ints with a value of 200
//
	//first.swap(second);
//
	//std::cout << "first contains:";
	//for (std::list<int>::iterator it=first.begin(); it!=first.end(); it++)
	//	std::cout << ' ' << *it;
	//std::cout << '\n';
//
	//std::cout << "second contains:";
	//for (std::list<int>::iterator it=second.begin(); it!=second.end(); it++)
	//	std::cout << ' ' << *it;
	//std::cout << "\n\n\n";
//
//
	//ft::list<int> first1 (3,100);   // three ints with a value of 100
	//ft::list<int> second1(5,200);  // five ints with a value of 200
	//first1.swap(second1);
//
	//std::cout << "first1 contains:";
	//for (ft::list<int>::iterator it=first1.begin(); it!=first1.end(); it++)
	//	std::cout << ' ' << *it;
	//std::cout << '\n';
//
	//std::cout << "second1 contains:";
	//for (ft::list<int>::iterator it=second1.begin(); it!=second1.end(); it++)
	//	std::cout << ' ' << *it;
	//std::cout << '\n';

	//std::list<int> mylist;
//
	//// set some initial content:
	//for (int i=1; i<10; ++i) mylist.push_back(i);
//
	//mylist.resize(5);
	//mylist.resize(8,100);
	//mylist.resize(12);
//
	//std::cout << "mylist contains:";
	//for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
	//	std::cout << ' ' << *it;
//
	//std::cout << "\n\n\n";
//
//
	//ft::list<int> mylist11;
//
	//// set some initial content:
	//for (int i=1; i<10; ++i) mylist11.push_back(i);
//
	//mylist11.resize(5);
	//mylist11.resize(8,100);
	//mylist11.resize(12);
//
	//std::cout << "mylist contains:";
	//for (ft::list<int>::iterator it=mylist11.begin(); it!=mylist11.end(); ++it)
	//	std::cout << ' ' << *it;
//
	//std::cout << '\n';


	std::list<int> mylist;
	std::list<int>::iterator it;

	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);

	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist.clear();
	mylist.push_back (1101);
	mylist.push_back (2202);

	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::list<int> mylist34;
	std::list<int>::iterator it34;

	mylist34.push_back (100);
	mylist34.push_back (200);
	mylist34.push_back (300);

	std::cout << "mylist contains:";
	for (it=mylist34.begin(); it!=mylist34.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist34.clear();
	mylist34.push_back (1101);
	mylist34.push_back (2202);

	std::cout << "mylist contains:";
	for (it=mylist34.begin(); it!=mylist34.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}