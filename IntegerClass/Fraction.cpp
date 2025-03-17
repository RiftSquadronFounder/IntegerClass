#include "Fraction.hpp"

Fraction::Fraction() {
	divided_ = 1;
	divider_ = 1;
};
Fraction::Fraction(Integer divided, Integer divider) {
	divided_ = divided;
	divider_ = divider;
};

std::ostream& operator<<(std::ostream& out, Integer& read) {
	read.ValueOut();
	return out;
};

std::istream& operator>>(std::istream& in, Integer& write) { std::cout << "This action is currently unavialable"; };

Fraction Fraction::operator=(Fraction value) {
	this->divided_ = value.divided_;
	this->divider_ = value.divider_;
};


Fraction Fraction::operator+(Fraction value) {
	Fraction Answer;
	Integer Number = 0;


	if (this->divider_ == value.divider_) {
		Answer.SetValue(this->divider_, this->divided_ + value.divided_);
	}
	else {

		Number = (this->divided_ * value.divider_) + (value.divided_ * this->divider_);

		Answer.SetValue((this->divider_ * value.divider_), Number);
	}

	return Answer;
};

Fraction Fraction::operator-(Fraction value) {

	Fraction Answer;
	Integer Number = 0;


	if (this->divider_ == value.divider_) {
		Answer.SetValue(this->divider_, this->divided_ - value.divided_);
	}
	else {

		Number = (this->divided_ * value.divider_) - (value.divided_ * this->divider_);

		Answer.SetValue((this->divider_ * value.divider_), Number);
	}

	return Answer;
};

Fraction Fraction::operator*(Fraction value) {
	Fraction Answer;
	Answer.SetValue(this->divider_ * value.divider_, this->divided_ * value.divided_);





};

Fraction Fraction::operator/(Fraction value) {};















void Fraction::SetValue(Integer divider, Integer divided) {
	divided_ = divided;
	divider_ = divider;
}



Integer Fraction::FtoInteger() {};
int Fraction::Ftoint() {};
std::string Fraction::getFraction() {};