#include "Real.hpp"










Real::Real() {
	value = Fraction(1, 1);
}
Real::Real(Integer divided, Integer divider) {
	value = Fraction(divided, divider);

}


//Real operator+(Real other){}
//Real operator-(Real other){}
//Real operator*(Real other){}
//Real operator/(Real other){}

//Real operator+=(Real other){}
//Real operator-=(Real other){}
//Real operator*=(Real other){}
//Real operator/=(Real other){}


std::ostream& operator<<(std::ostream& out, Real& read) {
	read.ValueOut();
	return out;
};

void Real::SetValue(Integer divider, Integer divided) {
	value.SetValue(divider, divided);
}

void SetValue(Fraction value){}
void SetValue(Real value){}

void Real::ValueOut() {
	std::cout << ToString() << std::endl;
}

std::string Real::ToString() {
	CalcAfterDot();
	if (value.GetDivided() < value.GetDivider()) {
		return "0." + afterDot;
	}
	else {
		return value.FtoInteger().ToString() + "." + afterDot;
	}
}

void Real::CalcAfterDot() {
	afterDot = "";
	Integer valToString = 0;
	Integer divider = value.GetDivider();
	Integer divided = value.GetDivided();
	do {
		valToString = (divided * 10) / divider;
		divided = 0;

		afterDot = afterDot + valToString.ToString();
	} while (valToString != 0);
	
	if (afterDot.length() > 1){
		while (afterDot[afterDot.length() - 1] == '0') {
			std::string afterDotNew = "";
			for (int i = 0; i < afterDot.length() - 1; i++) {
				afterDotNew += afterDot[i];
			}
			afterDot = afterDotNew;
		}
	}
	

}