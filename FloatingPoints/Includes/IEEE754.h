#pragma once

#include <iostream>
#include <bitset>

union IEEE
{
	float floating;
	double doubleNumber;
	int integer;
};

const float convertBinaryToFloat(const std::string& binaryString);
const std::string convertFloatToBinary(const float fpNumber);

const double convertBinaryToDouble(const std::string& binaryString);
const std::string convertDoubleToBinary(const double dNumber);