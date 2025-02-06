#pragma once

#include "../../src/base/base.h"

#include <string>
#include <sstream>

#include "../../ext/nlohmann/json.hpp"

class Reverso
{
public:
    static void Loop();

private:
    inline static const std::string m_ApiUrl = R"(https://orthographe.reverso.net/api/v1/Spelling/)";
    inline static const std::string m_RequestPart1 = R"({"englishDialect":"indifferent","autoReplace":true,"getCorrectionDetails":true,"interfaceLanguage":"fr","locale":"","language":"fra","text":")";
    inline static const std::string m_RequestPart2 = R"(","originalText":"","spellingFeedbackOptions":{"insertFeedback":true,"userLoggedOn":true},"origin":"interactive","isHtml":false,"IsUserPremium":true})";
    inline static const std::vector<std::string> m_Headers =
    {
        R"(Content-Type: application/json)",
        R"(User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36)"
    };
};
