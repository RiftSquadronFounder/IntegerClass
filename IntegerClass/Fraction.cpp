#include "Fraction.hpp"

Fraction::Fraction() {
	divided_ = 1;
	divider_ = 1;
};
Fraction::Fraction(Integer divided, Integer divider) {
	divided_ = divided;
	divider_ = divider;
};

std::ostream& operator<<(std::ostream& out, Fraction& read) {
	read.ValueOut();
	return out;
};

std::istream& operator>>(std::istream& in, Fraction& write) { 
	std::cout << "This action is currently unavialable";  
	return in;
};

Fraction Fraction::operator=(Fraction value) {
	return Fraction(value.divided_, value.divider_);
};


Fraction Fraction::operator+(Fraction value) {
	Fraction Answer = Fraction(0,0);
	Integer Number = 0;


	if (this->divider_ == value.divider_) {
		
		Answer.SetValue(this->divided_ + value.divided_, this->divider_);
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
		Answer.SetValue(this->divided_ + value.divided_, this->divider_);
	}
	else {

		Number = (this->divided_ * value.divider_) - (value.divided_ * this->divider_);

		Answer.SetValue((this->divider_ * value.divider_), Number);
	}

	return Answer;
}

Fraction Fraction::operator*(Fraction value) {
	Fraction Answer;
	Answer.SetValue(this->divider_ * value.divider_, this->divided_ * value.divided_);
	return Answer;
}

Fraction Fraction::operator/(Fraction value) {
	return *this * value.ReverseValue();
}











Fraction Fraction::ReverseValue() {
	return Fraction(this->divided_, this->divider_);
}

void Fraction::ValueOut() {
	if (!Positive_) {
		std::cout << "-";
	}
	std::cout << "(" << divided_ << "/" << divider_ << ")";
}

void Fraction::SetValue(Integer divided, Integer divider) {
	std::cout << "{" << divided << "}";
	divided_ = divided;
	divider_ = divider;
}


/*
Integer Fraction::FtoInteger() { return 0; };
int Fraction::Ftoint() {};
std::string Fraction::getFraction() {};*/