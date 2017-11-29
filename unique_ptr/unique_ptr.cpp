// unique_ptr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <memory>

struct Foo
{
	Foo()      { std::cout << "Foo::Foo\n"; }
	~Foo()     { std::cout << "Foo::~Foo\n"; }
	void bar() { std::cout << "Foo::bar\n"; }
};

void f(const Foo &)
{
	std::cout << "f(const Foo&)\n";
}

void call_f(std::unique_ptr<Foo>& p3)
{
	std::cout << "call_f\n";
	f(*p3);

}

int main()
{
	std::unique_ptr<Foo> p1(new Foo);  // p1 owns Foo
	if (p1) p1->bar();
	{

		call_f(p1);
		//p1.release();
		Foo* fp = p1.get();// p1.release();
		p1->bar();
		std::unique_ptr<Foo> p2(std::move(p1));  // now p2 owns Foo
		f(*p2);
		f(*p1);
		call_f(p1);

		p1 = std::move(p2);  // ownership returns to p1
		std::cout << "destroying p2...\n";

		call_f(p1);

	}


	if (p1) p1->bar();

	call_f(p1);
	// Foo instance is destroyed when p1 goes out of scope
}

