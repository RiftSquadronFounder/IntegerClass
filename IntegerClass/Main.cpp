#include <iostream>
#include <string>
#include "IntegerH.hpp"
#include "Fraction.hpp"




int main() {


	Fraction frac1 = Fraction(5, 20);
	Fraction frac2 = Fraction(5, 20);

	Fraction ans = (frac1 + frac2);
	std::cout << frac1 << std::endl;

	std::cout << frac2 << std::endl;

	std::cout << ans << std::endl;


	

	return 0;
}