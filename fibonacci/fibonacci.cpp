// fibonacci.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>

template<unsigned int n>
struct fibonacci
{
	static constexpr unsigned int value = fibonacci<n - 1>::value + fibonacci<n - 2>::value;
};

template<>
struct fibonacci<0>
{
	static constexpr unsigned int value = 0;
};

template<>
struct fibonacci<1>
{
	static constexpr unsigned int value = 1;
};

int main()
{
	int a = 0;
	
	
	constexpr int b[]{
		fibonacci<1>::value,
		fibonacci<2>::value,
		fibonacci<3>::value,
		fibonacci<4>::value,
		fibonacci<5>::value, 
		fibonacci<6>::value,
		fibonacci<7>::value,
		fibonacci<8>::value,
		fibonacci<9>::value,
		fibonacci<10>::value,
		fibonacci<11>::value,
		fibonacci<12>::value
	};

	for (int i = 0; i < 12; i++)
		std::cout << b[i] << "\n";
	
	return 0;
}

