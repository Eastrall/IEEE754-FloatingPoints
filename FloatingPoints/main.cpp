#include "Includes\IEEE754.h"

int main()
{
	float _intputValue = 0.0;

	std::cout << "Enter a floating point value: ";
	std::cin >> _intputValue;
	std::cout << _intputValue << " = " << convertFloatToBinary(_intputValue) << std::endl;

	std::cout << "Press any key to exit..." << std::endl;
	std::cin.ignore();
	std::cin.get();

	return 0;
}