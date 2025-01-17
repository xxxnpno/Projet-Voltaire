#pragma once

#include "../../src/base/utils/logger.h"

#include "curl/curl.h"

#include <string>

class Network
{
public:
    static std::string POST(const std::string& url, const std::string& data);

private:
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
};