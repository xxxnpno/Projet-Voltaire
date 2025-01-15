#pragma once

#include "curl/curl.h"

#include <iostream>
#include <string>
#include <chrono>

class Network
{
public:
	static std::string POST(const std::string& url, const std::string& data);

private:
	static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
};