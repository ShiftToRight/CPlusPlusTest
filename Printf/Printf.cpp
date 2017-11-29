// Printf.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdint.h>

int _tmain(int argc, _TCHAR* argv[])
{
	
	volatile int32_t number = -5;

	printf("%d.%1u\n\n", (int32_t)(number)/(int32_t)(10), number % 10);
	printf("%.2f\n\n", (float)(number)/(float)(10));
	//printf("Decimal:\t%i | %d | %.6i | %i|  %.0i |%+i |%i\n", 1, 2, 3, 0, 0, 4, -1);
	//printf("Rounding:\t%f %.0f %.32f\n", 1.5, 1.5, 1.3);
	return 0;
}

