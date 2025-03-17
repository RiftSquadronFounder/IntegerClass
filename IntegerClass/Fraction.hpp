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



	Fraction operator=(Fraction value);

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
	





	void SetValue(Integer divider, Integer divided);

	Fraction ReverseValue();

	void ValueOut() {
		if (!Positive_) {
			std::cout << "-";
		}
		std::cout << "(" << divided_ << "/" << divider_ << ")";
	}
	Integer FtoInteger();
	int Ftoint();
	std::string getFraction();
private:
	bool Positive_;
	Integer divided_;
	Integer divider_;
};
#endif // !FRACTION_CLASS
