// builtinliterale.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
// http://www.linux-magazin.de/Ausgaben/2015/06/C-11#article_l2

#include "stdafx.h"


#include <iostream>
#include <ostream>
#include <initializer_list>


#define erweiterung_Cplusplusvierzehrn 0 // lässt sich nicht mit VS kompilieren

namespace Distance {
	class MyDistance {
	public:
		constexpr MyDistance(double i) :m(i) {}

		friend constexpr MyDistance operator +(const MyDistance& a, const MyDistance& b) {
			return MyDistance(a.m + b.m);

		}
		friend constexpr MyDistance operator -(const MyDistance& a, const MyDistance& b) {
			return MyDistance(a.m - b.m);

		}

		friend constexpr MyDistance operator*(double m, const MyDistance& a) {
			return MyDistance(m*a.m);

		}

		friend constexpr MyDistance operator/(const MyDistance& a, int n) {
			return MyDistance(a.m / n);
			
		}

		friend std::ostream& operator<< (std::ostream &out, const MyDistance& myDist) {
			out << myDist.m << " m";
			return out;

		}
	private:
		double m;


	};

	namespace Unit {
		MyDistance constexpr operator "" _km(long double d) {
			return MyDistance(1000 * d);

		}
		MyDistance constexpr operator "" _m(long double m) {
			return MyDistance(m);

		}
		MyDistance constexpr operator "" _dm(long double d) {
			return MyDistance(d / 10);

		}
		MyDistance constexpr operator "" _cm(long double c) {
			return MyDistance(c / 100);

		}

	}

}

using namespace Distance::Unit;

#if erweiterung_Cplusplusvierzehrn	> 0
constexpr Distance::MyDistance getAverageDistance(std::initializer_list <Distance::MyDistance> inList) 
{
	   auto sum = Distance::MyDistance(0.0);
	   for (auto i : inList) 
		   sum = sum + i;

	   return sum / inList.size();
	
}
#endif

int main() 
{

	std::cout << "1.0_km: " << 1.0_km << std::endl;
	std::cout << "1.0_m: " << 1.0_m << std::endl;
	std::cout << "1.0_dm: " << 1.0_dm << std::endl;
	std::cout << "1.0_cm: " << 1.0_cm << std::endl;
	std::cout << "1.5_km + 105.1_m: " << .5_km + 105.1_m << std::endl;

	std::cout << std::endl;

	constexpr Distance::MyDistance work = 63.0_km;
	constexpr Distance::MyDistance workPerDay = 2 * work;
	constexpr Distance::MyDistance abbrevationToWork = 5400.0_m;
	constexpr Distance::MyDistance workout = 2 * 1600.0_m;
	constexpr Distance::MyDistance shopping = 2 * 1200.0_m;

	constexpr Distance::MyDistance myDistancePerWeek = 4 * workPerDay - 3 * abbrevationToWork + workout + shopping;

	std::cout << "4 * workPerDay - 3 * abbrevationToWork + workout + shopping: " << myDistancePerWeek;

#if erweiterung_Cplusplusvierzehrn	> 0
	constexpr Distance::MyDistance myDistancePerWeek1 = 4 * workPerDay - 3 * abbrevationToWork + workout + shopping;
	constexpr Distance::MyDistance myDistancePerWeek2 = 4 * workPerDay - 3 * abbrevationToWork + 2 * workout;
	constexpr Distance::MyDistance myDistancePerWeek3 = 4 * workout + 2 * shopping;
	constexpr Distance::MyDistance myDistancePerWeek4 = 5 * workout + shopping;
	
	constexpr Distance::MyDistance averagePerWeek /*perMonth*/ = getAverageDistance({ myDistancePerWeek1,myDistancePerWeek2,myDistancePerWeek3,myDistancePerWeek4 });
	
	std::cout << "Average per week: " << averagePerWeek << std::endl;
#endif

	std::cout << "\n\n";
}

