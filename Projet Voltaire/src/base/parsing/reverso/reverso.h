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
};
