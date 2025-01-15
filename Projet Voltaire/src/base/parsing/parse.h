#pragma once

#include "nlohmann/json.hpp"

class Parse
{
public:
	static std::string ParseResponse(const std::string& response);
	static std::string ParseError(const std::string& response);
};