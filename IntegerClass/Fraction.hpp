#pragma once
#ifndef FRACTION_CLASS

#include "IntegerH.hpp"

class Fraction {
public:
	Fraction();
	Fraction(Integer divided, Integer divider);
	Fraction(Integer FullNumber, Integer divided, Integer divider);

	friend std::ostream& operator<< (std::ostream& out, Fraction& read);

	friend std::istream& operator>> (std::istream& in, Fraction& write);



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

	Integer GetDivider();
	Integer GetDivided();


	void NormalizeSign();

	std::string ValueString();
	void ValueOut();
	Integer FtoInteger();
	int Ftoint();
	std::string getFraction();
	void SwitchPositiveness();
private:
	bool Positive_ = true;
	Integer divided_;
	Integer divider_;
};
#endif // !FRACTION_CLASS
