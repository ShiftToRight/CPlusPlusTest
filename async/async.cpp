// async.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>
 
template <typename RAIter>
int parallel_sum(RAIter beg, RAIter end)
{
    auto len = end - beg;
    if(len < 1000)
        return std::accumulate(beg, end, 0);
 
    RAIter mid = beg + len/2;
    auto handle = std::async(std::launch::async,
                             parallel_sum<RAIter>, mid, end);
    int sum = parallel_sum(beg, mid);
    return sum + handle.get();
}
int add(int a, int b)
{
	return a + b;
}

int main()
{
    std::vector<int> v(1000000, 100000);
    std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << '\n';


	auto handle = std::async(std::launch::async, add, 2,3);
	
	for (int i = 0; i < 100000; i++)
	  std::async(std::launch::async, add, 3,3);
	
	std::cout << " Ergebnis: " << handle.get() << std::endl;
}