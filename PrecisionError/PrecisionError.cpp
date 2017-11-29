// PrecisionError.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
// http://mathworld.wolfram.com/RoundoffError.html
// http://demonstrations.wolfram.com/PrecisionError/
#define _USE_MATH_DEFINES 
#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <stdint.h>


int main()
{
	//volatile int x = -5;
	volatile double x = -5;
	volatile double y = 0;
	for (int i = 0; i < 10; i++)
	{
		x = x + 1;
		
		if (x == 0)
			continue;

		y = (atan(x) + atan(1 / x)) - (M_PI / 2);

		std::cout << "X: " << x << " Y: " << y << "\n";
	}
	return 0;
}

