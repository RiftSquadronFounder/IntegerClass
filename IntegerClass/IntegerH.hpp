#pragma once
#ifndef INT_HPP
#define INT_HPP

#include <iostream>
#include <fstream>
#include <string>

class Integer {
public:

	Integer(int value);
	Integer();


	friend std::ostream& operator<< (std::ostream& out, Integer& read);

	friend std::istream& operator>>(std::istream& in, Integer& write);
	Integer operator+(Integer other);

	Integer operator-(Integer other);

	Integer operator/(Integer other);

	Integer operator*(Integer other);



	void operator+=(Integer other);
	void operator-=(Integer other);
	void operator*=(Integer other);
	void operator/=(Integer other);
	void operator=(Integer other);
	void operator=(int other);
	bool operator!=(Integer other);
	bool operator!=(int other);
	bool operator==(Integer other);
	bool operator==(int other);
	bool operator>=(Integer other);
	bool operator<=(Integer other);
	bool operator>=(int other);
	bool operator<=(int other);

	void ValueOut();




	Integer operator%(Integer other);


	Integer NOD_func(Integer other);

	Integer NOK_func(Integer other);


	void set(int value);


	bool sign();
	int value();
	bool isEven();
	bool isPositive();
	bool isSimple();
	bool isEqSimple(Integer other);




private:
	unsigned value_;
	bool Positive_;

};
#endif // !INTHPP