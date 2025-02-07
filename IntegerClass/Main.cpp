#include <iostream>
#include <string>
#include "IntegerH.hpp"




int main() {
	Integer value1, value2;
	bool ans;
	Integer ebalonanol;
	ebalonanol = 0;
	std::cin >> value1;
	std::cout <<"\nvalue: "<<value1<< "\n";
	std::cin >> value2;
	std::cout << "\nvalue: " << value2 << "\n";
	std::cout << "\n\n";
	ans = value1 != value2;
	std::cout << ans;



	return 0;
}