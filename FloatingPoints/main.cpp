#include <iostream>
#include <bitset>

union IEEE
{
	float floating;
	int integer;
};

///
/// Convert a binary input into a floating point number.
///
const float 
convertBinaryToFloat(const std::string& binaryString)
{
	if (binaryString.length() != 32)
		return NULL;

	// get the sign
	int _sign = binaryString[0] - '0' == 0 ? 1 : -1;
	
	// convert the exponent
	std::bitset<8> x(binaryString.substr(1, 8));
	int _exponent = x.to_ulong() - 127;

	// convert the mantise
	std::string _mantise = binaryString.substr(9, 23);
	float _mantiseTotal = 0.0;

	for (int i = 0, power = -1; i < 23; i++, power--)
		_mantiseTotal += static_cast<float>(_mantise[i] - '0') * static_cast<float>(pow(2.0, power));

	_mantiseTotal += 1.0;

	return _sign * static_cast<float>(pow(2.0, _exponent)) * static_cast<float>(_mantiseTotal);
}

///
/// Converts a floating point number into a binary string following the IEEE 754 standard.
///
const std::string 
convertFloatToBinary(const float fpNumber)
{
	IEEE _data;

	_data.floating = fpNumber;
	std::bitset<sizeof(float) * CHAR_BIT> _floatBits(_data.integer);
	
	return _floatBits.to_string<char, std::char_traits<char>, std::allocator<char>>();
}

int main()
{
	float _intputValue = 0.0;

	std::cout << "Enter a floating point value: ";
	std::cin >> _intputValue;
	std::cout << _intputValue << " = " << convertFloatToBinary(_intputValue) << std::endl;

	std::cout << "Press any key to exit..." << std::endl;
	getchar();

	return 0;
}