#include "..\Includes\IEEE754.h"

///
/// Convert a binary input into a floating point number following the IEEE754 Standard.
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

///
/// Converts a binary string input into a double value following the IEEE754 Standard.
///
const double convertBinaryToDouble(const std::string& binaryString)
{
	// NOT IMPLEMENTED YET
	return 0.0;
}

///
/// Converts a double into binary string follow the IEEE754 Standard.
///
const std::string convertDoubleToBinary(const double dNumber)
{
	// NOT IMPLEMENTED YET
	return NULL;
}
