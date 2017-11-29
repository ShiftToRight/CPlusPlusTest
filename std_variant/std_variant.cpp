// std_variant.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"


#include <iostream>
#include <string>
#include <variant>

int main() {
	using namespace std::string_literals;
	std::variant<int, std::string> v;

	// use std::string side
	v = "Hello, World!"s;
	std::cout << std::get<std::string>(v) << '\n';

	// use int side
	v = 42;
	std::cout << "Meaning of life: " << std::get<int>(v) << '\n';
}
