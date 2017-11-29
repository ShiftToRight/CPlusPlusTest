// Exploring_std_string.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
// http://shaharmike.com/cpp/std-string/

#include "stdafx.h"

#if 0
#include <string>
#include <iostream>

int main() {
	std::cout << sizeof(std::string) << std::endl;
}


#else


#include <cstdlib>
#include <iostream>
#include <string>

// replace operator new and delete to log allocations
void* operator new(std::size_t n) {
	std::cout << "[Allocating " << n << " bytes]" << std::endl;
	return malloc(n);
}
void operator delete(void* p) throw() {
	free(p);
}

int main() {
#if 0
	for (size_t i = 0; i < 24; ++i) {
		std::cout << i << ": " << std::string(i, '=') << std::endl;
	}
#else
	std::string s;
	for (size_t i = 0; i != 1000000; ++i) {
		s += '.';
	}
#endif
}

#endif