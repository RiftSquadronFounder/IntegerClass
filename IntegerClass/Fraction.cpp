#include "Fraction.hpp"

Fraction::Fraction() {
	Positive_ = true;
	divided_ = 1;
	divider_ = 1;
};
Fraction::Fraction(Integer divided, Integer divider) {
	Positive_ = true;
	divided_ = divided;
	divider_ = divider;
};

std::ostream& operator<<(std::ostream& out, Fraction& read) {
	read.ValueString();
	return out;
};

std::istream& operator>>(std::istream& in, Fraction& write) { 
	std::cout << "This action is currently unavialable";  
	return in;
};

Fraction Fraction::operator=(Fraction value) {
	divided_ = value.divided_;
	divider_ = value.divider_;
	return *this;
};


Fraction Fraction::operator+(Fraction value) {
	Fraction Answer = Fraction(0,0);
	Integer Number = 0;


	if (this->divider_ == value.divider_) {
		
		Answer.SetValue(this->divided_ + value.divided_, this->divider_);
	}
	else {

		Number = (this->divided_ * value.divider_) + (value.divided_ * this->divider_);
		//std::cout << this->divider_ << "   " << value.divider_ << std::endl;
		Answer.SetValue(Number,(this->divider_ * value.divider_));
	}
	NormalizeSign();
	return Answer;
};

Fraction Fraction::operator-(Fraction value) {

	Fraction Answer;
	Integer Number = 0;


	if (this->divider_ == value.divider_) {
		Answer.SetValue(this->divided_ - value.divided_, this->divider_);
	}
	else {

		Number = (this->divided_ * value.divider_) - (value.divided_ * this->divider_);

		Answer.SetValue(Number,(this->divider_ * value.divider_));
	}
	NormalizeSign();

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


void Fraction::operator+=(Fraction value){
	*this = *this + value;
}

void Fraction::operator-=(Fraction value){
	*this = *this - value;
}

void Fraction::operator*=(Fraction value){
	*this = *this * value;
}

void Fraction::operator/=(Fraction value){
	*this = *this / value;
}








Fraction Fraction::ReverseValue() {
	return Fraction(this->divided_, this->divider_);
}

void Fraction::ValueOut() {
	NormalizeSign();
	if (!Positive_) {
		std::cout << "-";
	}
	std::cout << "(" << divided_ << "/" << divider_ << ")";
}

std::string Fraction::ValueString() {
	std::string line = "";
	NormalizeSign();
	if (!Positive_) {
		line = line + "-";
	}
	line = line + "(" + divided_.ToString() + "/" + divider_.ToString() + ")";
	return line;
}

void Fraction::SetValue(Integer divided, Integer divider) {
	//std::cout << "{" << divided << "}";
	divided_ = divided;
	divider_ = divider;
}
void Fraction::SwitchPositiveness() {
	Positive_ = !Positive_;
}

Integer Fraction::GetDivided(){
	return divided_;
}

Integer Fraction::GetDivider(){
	return divider_;
}



Integer Fraction::FtoInteger() {
	return divided_ / divider_;
}






void Fraction::NormalizeSign() {
	if (divided_.value() < 0) {
		divided_ *= -1;
		SwitchPositiveness();
	}
	if (divider_.value() < 0) {
		divider_ *= -1;
		SwitchPositiveness();
	}
}


/*
Integer Fraction::FtoInteger() { return 0; };
int Fraction::Ftoint() {};
std::string Fraction::getFraction() {};*/
