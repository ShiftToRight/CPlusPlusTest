// Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;



template<typename T>
class array_2d {
    std::size_t data;
    std::size_t col_max;
    std::size_t row_max;
    std::vector<T> a;
public:
    array_2d(std::size_t col, std::size_t row) 
         : data(col*row), col_max(col), row_max(row), a(data)
    {}

    T& operator()(std::size_t col, std::size_t row) {
       // assert(col_max > col && row_max > row);
        return a[col_max*col + row];
    }
};

int main() {
	
	int myints[] = {32,71,12,45,26,80,53,33};

	std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

	// using default comparison (operator <):
	std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33

	// using function as comp
	std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

	// using object as comp
	std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

	// print out content:
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';
	

	int myints2[][2] = { { 32, 0 }, { 71, 1 }, { 12, 2 }, { 45, 3 }, { 26, 4 }, { 80, 5 }, { 53, 6 }, { 33, 7 } };
	std::vector<std::vector<int>> fog 
	{ 
		{ 1, 1, 1 },
        { 2, 2, 2 }
	};
//	std::vector<std::vector<int>> myints2(8, std::vector<int>(2));
//	std::vector<int[8][2] > myvector2(myints2, myints2 + 8);
//	std::sort(myvector2.begin() + 4, myvector2.end(), myfunction);
//	std::sort(fog.begin() + 4, fog.end(), myfunction);

	std::cout << "myvector contains:";
//	for (std::vector<int>::iterator it = myvector2.begin(); it != myvector2.end(); ++it)
//		std::cout << ' ' << *it;

//	for (std::vector<int>::iterator it = fog.begin(); it != fog.end(); ++it)
//		std::cout << ' ' << *it;

	std::cout << '\n';
	
	
	
	array_2d<int> a(2,2);
    a(0,0) = 1;
	a(0,1) = 22;
	a(1,0) = 33;
	a(1,1) = 44;
	// ERROR -> a(2,0) = 55;
    std::cout << a(0,0) << std::endl;
	
	
	return 0;
}