// ableitung.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdint.h>

class IAuto
{
public:
	virtual void drive() = 0;
	virtual void stop() = 0;
};

class bmw : public IAuto
{
public:
	virtual void drive() { std::cout << "BMW Fahre" << std::endl;}
	virtual void stop(){ std::cout << "BMW Stoppe" << std::endl;};
private:

};

class vw : public IAuto
{
public:
	virtual void drive() { std::cout << "VW Fahre" << std::endl;}
	virtual void stop(){ std::cout << "VW Stoppe" << std::endl;};
private:

};

void CarDrive(IAuto& a)
{
   a.drive();

}
int _tmain(int argc, _TCHAR* argv[])
{
	bmw auto1 =  bmw();
	vw b = vw();

	auto1.drive();
	auto1.stop();
	
	b.drive();
	b.stop();
	CarDrive(auto1);
	CarDrive(b);
	
	return 0;
}

