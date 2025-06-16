#include <iostream>
#include <string>
#include "IntegerH.hpp"
#include "Fraction.hpp"
#include "Real.hpp"
#include "Matrix.hpp"



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

	
	Real value = Real(35,5);
	std::cout << value;
	
	/*
	Matrix matrix = Matrix(3, 3);
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[0][2] = 3;
	matrix[1][0] = 4;
	matrix[1][1] = 5;
	matrix[1][2] = 6;
	matrix[2][0] = 7;
	matrix[2][1] = 8;
	matrix[2][2] = 9;
	matrix = matrix.UpDownMatrix();

	matrix.MatrixOut();
	*/
	return 0;
}
