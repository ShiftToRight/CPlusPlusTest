// "CTest2.cpp": Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <cstdint>

class A
{
public:
    static void func( int i);
    static int var;
};

int A::var = 2;
void A::func( int i)
{
    int x = i + var;
    std::cout << "var: " << x << "\n";
}


A a;
A b;
int main()
{
    a.func(2);
    b.func(3);

    return 0;
}

