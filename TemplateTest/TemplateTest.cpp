// TemplateTest.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#define _USE_MATH_DEFINES 
#include <math.h>
#include <iostream>
#include <stdint.h>



template< unsigned int PWR, unsigned int BASE = 10 >
struct power
{
	enum { value = BASE * power<PWR - 1, BASE>::value };
};

template<unsigned int BASE> // template specialization
struct power<0, BASE>
{
	enum { value = 1 };
};

int main()
{
	unsigned int KILO   = power<3, 10>::value;
	unsigned int MEGA   = power<6, 10>::value;
	unsigned int kBytes = power<10, 2>::value;

	volatile unsigned int a = 10 * KILO;

	std::cout << a << "\n";
	return 0;
}

