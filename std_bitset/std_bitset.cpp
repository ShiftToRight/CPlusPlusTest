// std_bitset.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <bitset>
int main()
{
	std::bitset<20> bits;

//	bits[0] = true;
//	bits[1] = 1;

	std::cout << bits.to_string() << "\n";
	std::cout << "Anzahl Bits : " << bits.count() << "\n";
	std::cout << "Anzahl Bytes: " << sizeof(bits) << "\n";
	std::cout << bits.set(2, 1) << '\n';
	std::cout << bits.set(10, 1) << '\n';
    return 0;
}

