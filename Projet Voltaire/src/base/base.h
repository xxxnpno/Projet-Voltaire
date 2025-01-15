#pragma once

#include "../../src/base/clipboard/clipboard.h"
#include "../../src/base/network/net.h"
#include "../../src/base/parsing/parse.h"

#include <thread>
#include <chrono>

class Base
{
public:
    static void Init();
    static void Loop();

private:
    static void SetColor(int textColor, int bgColor);

    inline static std::string m_CurrentClipboard;
    inline static std::string m_ApiUrl = "https://orthographe.reverso.net/api/v1/Spelling/";
    inline static std::string m_PostHelp = "{\"englishDialect\":\"indifferent\",\"autoReplace\":true,\"getCorrectionDetails\":true,\"interfaceLanguage\":\"fr\",\"locale\":\"\",\"language\":\"fra\",\"text\":\"";
    inline static std::string m_PreHelp = "\",\"originalText\":\"\",\"spellingFeedbackOptions\":{\"insertFeedback\":true,\"userLoggedOn\":false},\"origin\":\"interactive\",\"isHtml\":false,\"IsUserPremium\":false}";
};