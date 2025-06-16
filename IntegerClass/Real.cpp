#include "Real.hpp"







Real::Real() {
	value = Fraction(1, 1);
}
Real::Real(Integer divided, Integer divider) {
	value = Fraction(divided, divider);
}
Real::Real(Fraction frac) {
    value = frac;
}


Real Real::operator+(Real other){
    return Real(value + other.value);
    }

Real Real::operator-(Real other) {
    return Real(value - other.value);
}

Real Real::operator*(Real other) {
    return Real(value * other.value);
}

Real Real::operator/(Real other) {
    return Real(value / other.value);
}


Real Real::operator+=(Real other) {
    value += other.value;
    return *this;
}

Real Real::operator-=(Real other) {
    value -= other.value;
    return *this;
}

Real Real::operator*=(Real other) {
    value *= other.value;
    return *this;
}

Real Real::operator/=(Real other) {
    value /= other.value;
    return *this;
}


Real Real::operator=(Real other) {
    value = other.value;
    return *this;
}
Real Real::operator=(int other) {
    value = Fraction(other, 1);;
    return *this;
}





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
    Integer divider = value.GetDivider();
    Integer divided = value.GetDivided();

    Integer integerPart = value.FtoInteger();
    Integer remain = divided - (integerPart * divider);

    int maxDigits = 20;
    while (remain != 0 && maxDigits-- > 0) {
        remain = remain * 10;
        Integer digit = remain / divider;
        afterDot += digit.ToString();
        remain = remain - (digit * divider);
    }

    while (afterDot != "" && afterDot[afterDot.length() - 1] == '0') {
        afterDot.pop_back();
    }

    if (afterDot == "") {
        afterDot = "0";
    }
}