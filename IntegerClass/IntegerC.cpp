#include "IntegerH.hpp"
std::ostream& operator<< (std::ostream& out, Integer& read) {
	read.ValueOut();
	return out;
}

std::istream& operator>>(std::istream& in, Integer& write) {
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

Integer::Integer(int value) {
	value_ = ::abs(value);
	if (value < 0) {
		Positive_ = false;
	}
	else { Positive_ = true; }
}

Integer::Integer() {
	value_ = 0;
	Positive_ = true;
}




int Integer::ToInt() {
	if (Positive_ == true) {
		return int(value_);
	}
	else {
		return -int(value_);
	}
	
}


void Integer::operator++() {
	if (Positive_ == true) {
		value_ += 1;
	}
	else {
		value_ -= 1;
	}
};

void Integer::operator++(int) {
	if (Positive_ == true) {
		value_ += 1;
	}
	else {
		value_ -= 1;
	}
};

void Integer::operator--() {
	if (Positive_ == true) {
		value_ += 1;
	}
	else {
		value_ -= 1;
	}
};

void Integer::operator--(int) {
	if (Positive_ == true) {
		value_ += 1;
	}
	else {
		value_ -= 1;
	}
};










Integer Integer::operator+(Integer other) {
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

Integer Integer::operator-(Integer other) {
	Integer answer;
	if (Positive_ == true && other.Positive_ == true) {
		if (value_ < other.value_) {
			answer = value_ - other.value_;
			answer.Positive_ = false;
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

	return answer;
}

Integer Integer::operator/(Integer other) {
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

Integer Integer::operator*(Integer other) {
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

void Integer::operator+=(Integer other) {
	*this = *this + other;
}

void Integer::operator-=(Integer other) {
	*this = *this - other;
}

void Integer::operator*=(Integer other) {
	*this = *this * other;
}

void Integer::operator/=(Integer other) {
	*this = *this / other;
}

void Integer::operator=(Integer other) {
	value_ = other.value_;
	Positive_ = other.Positive_;
}

void Integer::operator=(int other) {
	value_ = ::abs(other);
	if (other < 0) {
		Positive_ = false;
	}
	else if (other >= 0) {
		Positive_ = true;
	}
}

bool Integer::operator!=(Integer other) {
	return !(*this == other);
}

bool Integer::operator!=(int other) {
	Integer value1;
	value1.set(value_);
	return !(value1 == other);
}

bool Integer::operator==(Integer other) {
	Integer value1;
	value1 = *this;
	bool is_same = false;
	if (value1.value_ == other.value_ && value1.Positive_ == other.Positive_) { is_same = true; }
	return is_same;
}

bool Integer::operator==(int other) {
	Integer value1;
	value1 = *this;
	bool is_same = false;
	if (value1.value_ == other) {
		if (value1.Positive_ == true && other >= 0) { is_same = true; }

		if (value1.Positive_ == false && other < 0) { is_same = true; }
	}
	return is_same;
}

bool Integer::operator<=(Integer other) {
	if (*this < other || *this == other) {
		return true;
	}
	else { return false; }
}


bool Integer::operator>=(Integer other) {
	if (*this > other || *this == other) {
		return true;
	}
	else { return false; }
}

bool Integer::operator<=(int other) {
	Integer a = other;
	return *this <= a;
}

bool Integer::operator>=(int other) {
	Integer a = other;
	return *this >= a;
}

bool Integer::operator>(Integer other) {
	if (this->Positive_ == true && other.Positive_ == false) {
		return true;
	}
	else if (this->Positive_ == true && other.Positive_ == true) {
		if (this->value_ > other.value_) {
			return true;
		}
		else { return false; }
	}
	else if (this->Positive_ == false && other.Positive_ == false) {
		if (this->value_ < other.value_) {
			return true;
		}
		else { return false; }
	}
	else { return false; }
	

};

bool Integer::operator<(Integer other) {
	if (this->Positive_ == true && other.Positive_ == false) {
		return true;
	}
	else if (this->Positive_ == true && other.Positive_ == true) {
		if (this->value_ < other.value_) {
			return true;
		}
		else { return false; }
	}
	else if (this->Positive_ == false && other.Positive_ == false) {
		if (this->value_ > other.value_) {
			return true;
		}
		else { return false; }
	}
	else { return false; }
};








void Integer::ValueOut() {

	if (Positive_) {
		std::cout << value_;
	}
	else {
		std::cout << '-' << value_;
	}
}




Integer Integer::operator%(Integer other) {
	Integer valuesAfter;
	if (this->value() != 0 && other.value()!=0){
		valuesAfter = other.value() % this->value();
	}
	return valuesAfter;
}


Integer Integer::NOD_func(Integer other) {
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

Integer Integer::NOK_func(Integer other) {
	Integer value1, value2;
	value1.set(value_);
	value2 = other;
	return (value1 / NOD_func(other)) * value2;
}


void Integer::set(int value) { value_ = value; }


bool Integer::sign() { Positive_ = isPositive(); return Positive_; }
int Integer::value() { 
	int IntVal = value_;
	if (Positive_ == true) {
		return IntVal;
	}
	else {
		return -IntVal;
	}
}
bool Integer::isEven() { if (value_ % 2 == 0) { return true; } else { return false; } }
bool Integer::isPositive() { if (value_ >= 0) { return true; } else { return false; } }
bool Integer::isSimple() {
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
bool Integer::isEqSimple(Integer other) {
	Integer minValue = 0;
	bool coop = false;
	if (::abs(other.value()) < value_) { minValue = ::abs(other.value()); }
	else { minValue = value_; }
	for (int i = 2; i <= minValue.value_; i++) {
		if (value_ % i == 0 && ::abs(other.value()) % i == 0) { coop = true; }
	}
	return !coop;
}





void Integer::StreamSerialize(std::ostream& writeStream) {
	writeStream << value_ << " " << Positive_ << "\n";
}
void Integer::StreamDeserialize(std::istream& readStream) {
	int val;
	bool sign;
	readStream >> val >> sign;
	set(val);
	Positive_ = sign;
}
void Integer::Serialize(std::string fileNameWrite) {
	std::ofstream outFile(fileNameWrite);
	if (outFile.is_open()) {
		StreamSerialize(outFile);
		outFile.close();
	}
	else {
		std::cout << "Unabkle to open file: " << fileNameWrite << std::endl;
		std::cin; // � �� ����� ��� ��� ��������� ������� �������, visual studio - �������, �������� ���������� ������ � ����
	}
}
void Integer::Deserialize(std::string fileNameRead) {
	std::ifstream inFile(fileNameRead);
	if (inFile.is_open()) {
		StreamDeserialize(inFile);
		inFile.close();
	}
	else {
		std::cerr << "Unable to read file: " << fileNameRead << std::endl;
	}
}



std::string Integer::ToString() {
	return std::to_string(value_);
}











