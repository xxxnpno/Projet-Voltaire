#pragma once

#include <string>
#include <iomanip>
#include <sstream>

class Encode
{
public:
	static std::string EncodeURL(const std::string& value);
};