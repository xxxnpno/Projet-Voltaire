#pragma once

#include "../../src/base/base.h"

#include <string>
#include <sstream>

#include "../../ext/nlohmann/json.hpp"

class LanguageTool
{
public:
    static void Loop();

private:
    inline static const std::string m_ApiUrl = R"(https://api.languagetool.org/v2/check?c=1&instanceId=58378%3A1738854908952&v=standalone)";
    inline static const std::string m_RequestPart1 = R"(data=%7B%22text%22%3A%22)";
    inline static const std::string m_RequestPart2 = R"(%22%7D&textSessionId=58378%3A1738854908952&enableHiddenRules=true&level=picky&language=auto&noopLanguages=fr%2Cen&preferredVariants=en-US%2Cde-DE%2Cpt-PT%2Cca-es&abtest=deggec%2Cptggec&preferredLanguages=fr%2Cen&disabledRules=WHITESPACE_RULE&useragent=standalone&mode=allButTextLevelOnly&allowIncompleteResults=true)";
    inline static const std::vector<std::string> m_Headers =
    {
        R"(Content-Type: application/json)",
        R"(User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36)"
    };
};
