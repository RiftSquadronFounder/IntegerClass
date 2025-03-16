#include "Fraction.hpp"

Fraction::Fraction() {
	divided_ = 1;
	divider_ = 1;
};
Fraction::Fraction(Integer divided, Integer divider) {
	divided_ = divided;
	divider_ = divider;
};

std::ostream& operator<<(std::ostream& out, Integer& read) {};

std::istream& operator>>(std::istream& in, Integer& write) {};

Integer Fraction::FtoInteger() {};
int Fraction::Ftoint() {};
std::string Fraction::getFraction() {};