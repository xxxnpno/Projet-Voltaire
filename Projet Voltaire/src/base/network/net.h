#pragma once

#include "../../src/base/base.h"

#include <string>
#include <vector>

#include "../../ext/curl/curl.h"

class Network
{
public:
    static std::string POST(const std::string& url, const std::string& data, const std::vector<std::string>& headers);
    static std::string GET(const std::string& url, const std::vector<std::string>& headers);

private:
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
};