#pragma once
class Integer {
public:
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
	int value_ = 0;
	bool Positive_ = true;

};