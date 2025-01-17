#pragma once

#include <iostream>

class Logger
{
public:
	static std::string Info();
	static std::string Error();
	static std::string Warn();
};