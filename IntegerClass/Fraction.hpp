#pragma once
#ifndef FRACTION_CLASS

#include "IntegerH.hpp"

class Fraction {
public:
	Fraction();
	Fraction(Integer divided, Integer divider);
	Fraction(Integer FullNumber, Integer divided, Integer divider);

	friend std::ostream& operator<< (std::ostream& out, Integer& read);

	friend std::istream& operator>>(std::istream& in, Integer& write);

	Fraction operator+(Fraction value);

	Fraction operator-(Fraction value);
	
	Fraction operator*(Fraction value);
	
	Fraction operator/(Fraction value);
	

	
	
	void operator+=(Fraction value);

	void operator-=(Fraction value);
	
	void operator*=(Fraction value);
	
	void operator/=(Fraction value);



	bool operator==(Fraction value);

	bool operator!=(Fraction value);









	Integer FtoInteger();
	int Ftoint();
	std::string getFraction();
private:
	Integer divided_;
	Integer divider_;
};
#endif // !FRACTION_CLASS
