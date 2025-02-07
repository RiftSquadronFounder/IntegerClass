#include <iostream>
#include <string>
#include "IntegerH.hpp"



class Integer {
public:
	friend std::ostream& operator<< (std::ostream& out, Integer& read) {
		read.ValueOut();
		return out;
	}

	friend std::istream& operator>>(std::istream& in, Integer& write) {
		std::string symbol, unsignedSTR;

		in >> symbol;
		if (symbol[0] == '-') {
			write.Positive_ = false;
			for (int i = 0; i < symbol.length(); i++) {
				if (symbol[i] != '-') {
					unsignedSTR = unsignedSTR + symbol[i];
				}
			}
		}
		else {
			write.Positive_ = true;
			unsignedSTR = symbol;
		}
		unsigned value__ = std::abs(std::stoi(unsignedSTR));
		write.value_ = value__;
		return in;
	}

	Integer(int value) {
		value_ = ::abs(value);
		if (value < 0) {
			Positive_ = true;
		}
		else { Positive_ = false; }
	}

	Integer() {
		value_ = ;
		if (value < 0) {
			Positive_ = true;
		}
		else { Positive_ = false; }
	}





	Integer operator+(Integer other) {
		Integer answer;
		if (Positive_ == other.Positive_) {
			answer.value_ = value_ + other.value_;
		}
		else {
			if (value_ > other.value_) {
				answer.Positive_ = other.Positive_;
			}
			if (other.Positive_ && Positive_) {
				answer.value_ = other.value_ + value_;
			}
			else {
				if (other.value_ > value_) {
					answer.Positive_ = other.Positive_;
					answer.value_ = other.value_ - value_;
				}
				if (value_ > other.value_) {

					answer.Positive_ = Positive_;
					answer.value_ = value_ - other.value_;
				}
			}
		}
		return answer;
	}

	Integer operator-(Integer other) {
		Integer answer;
		if (Positive_ == true && other.Positive_ == true) {
			if (value_ < other.value_) {
				answer = value_ - other.value_;
				answer.Positive_ = other.Positive_;
			}
			else if (value_ > other.value_) {
				answer = value_ - other.value_;
				answer.Positive_ = other.Positive_;
			}
			else {
				answer = value_ - other.value_;
				answer.Positive_ = other.Positive_;
			}
		}

		else if (Positive_ == false && other.Positive_ == false) {
			answer = value_ + other.value_;
			answer.Positive_ = false;
		}
		/*else {
			if (value_ > other.value_) {
				if (Positive_) {
					answer = value_ - other.value_;
				}
				else if()
				answer.Positive_ = Positive_;
			}
			else if (value_ < other.value_) {
				answer = other.value_ - value_;
				answer.Positive_ = other.Positive_;
			}
			else {
				answer = value_ - other.value_;
				answer.Positive_ = other.Positive_;
			}
		}*/

		return answer;
	}

	Integer operator/(Integer other) {
		Integer answer;
		if (Positive_ == false && other.Positive_ == false) {
			answer.Positive_ = true;
		}
		else if (Positive_ != other.Positive_) {
			answer.Positive_ = false;
		}
		answer.value_ = value_ / other.value_;
		return answer;
	}
	Integer operator*(Integer other) {
		Integer answer;
		if (Positive_ == false && other.Positive_ == false) {
			answer.Positive_ = true;
		}
		else if (Positive_ != other.Positive_) {
			answer.Positive_ = false;
		}

		answer.value_ = value_ * other.value_;

		return answer;
	}
	void operator+=(Integer other) {
		*this = *this + other;
	}
	void operator-=(Integer other) {
		*this = *this - other;
	}
	void operator*=(Integer other) {
		*this = *this * other;
	}
	void operator/=(Integer other) {
		*this = *this / other;
	}
	void operator=(Integer other) {
		value_ = other.value_;
		Positive_ = other.Positive_;
	}
	void operator=(int other) {
		value_ = ::abs(other);
		if (other < 0) {
			Positive_ = false;
		}
		else if (other >= 0) {
			Positive_ = true;
		}
	}
	bool operator!=(Integer other) {
		return !(*this == other);
	}
	bool operator!=(int other) {
		Integer value1;
		value1.set(value_);
		return !(value1 == other);
	}
	bool operator==(Integer other) {
		Integer value1;
		value1 = *this;
		bool is_same = false;
		if (value1.value_ == other.value_ && value1.Positive_ == other.Positive_) { is_same = true; }
		return is_same;
	}
	bool operator==(int other) {
		Integer value1;
		value1 = *this;
		bool is_same = false;
		if (value1.value_ == other) {
			if (value1.Positive_ == true && other >= 0) { is_same = true; }

			if (value1.Positive_ == false && other < 0) { is_same = true; }
		}
		return is_same;
	}

	void ValueOut() {

		if (Positive_) {
			std::cout << value_;
		}
		else {
			std::cout << '-' << value_;
		}
	}




	Integer operator%(Integer other) {
		Integer valuesAfter;
		valuesAfter = other.value() % value_;
		return valuesAfter;
	}


	Integer NOD_func(Integer other) {
		Integer value1, value2;
		value1.set(value_);
		value2 = other;
		while (value2 != 0) {
			int temp = value2.value();
			value2 = value1 % value2;
			value1 = temp;
		}
		return value1;
	}

	Integer NOK_func(Integer other) {
		Integer value1, value2;
		value1.set(value_);
		value2 = other;
		return (value1 / NOD_func(other)) * value2;
	}


	void set(int value) { value_ = value; }


	bool sign() { Positive_ = isPositive(); return Positive_; }
	int value() { return value_; }
	bool isEven() { if (value_ % 2 == 0) { return true; } else { return false; } }
	bool isPositive() { if (value_ >= 0) { return true; } else { return false; } }
	bool isSimple() {
		int amount = 0;
		bool isPos = isPositive();
		for (int i = 1; i <= value_; i++) {
			if (value_ % i == 0) { amount++; }
		}
		if (amount > 0 && amount <= 2) {
			return true;
		}
		else { return false; }
	}
	bool isEqSimple(Integer other) {
		int minValue = 0;
		bool coop = false;
		if (::abs(other.value()) < value_) { minValue = ::abs(other.value()); }
		else { minValue = value_; }
		for (int i = 2; i <= minValue; i++) {
			if (value_ % i == 0 && ::abs(other.value()) % i == 0) { coop = true; }
		}
		return !coop;
		// QUESTIONS!!
	}




private:
	int value_ = 0;
	bool Positive_ = true;

};