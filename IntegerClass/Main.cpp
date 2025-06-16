#include <iostream>
#include <string>
#include "IntegerH.hpp"
#include "Fraction.hpp"
#include "Real.hpp"




int main() {
	/*
	Fraction frac1 = Fraction(5, 20);
	Fraction frac2 = Fraction(75, 20);

	Fraction ans = (frac1 - frac2);
	std::cout << frac1 << std::endl;

	std::cout << frac2 << std::endl;

	std::cout <<frac1 <<" - " <<frac2 << " = " << ans << std::endl;
	*/
	/*
	Integer value = 12;
	std::cout <<"Initial value: " << value << "\n\n";

	
	value.Serialize("FileName.txt");
	std::cout << "Value Serialized successfully\n\n\n\n";
	
	std::string fileName = "FileName";

	Integer valueSerTest = 0;

	std::cout << "Value two before deserealize: " << valueSerTest << "\n\n";

	
	valueSerTest.Deserialize(fileName + ".txt");
	std::cout << "Value Deserealized from file: \"" << fileName << "\" successfully\n\n";


	std::cout << "Value two after deserealize: " << valueSerTest << "\n\n\n";
	*/

	
	Real value = Real(35,15);
	std::cout << value;
	
	return 0;
}
