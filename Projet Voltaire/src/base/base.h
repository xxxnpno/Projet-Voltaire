#pragma once

#include "../../src/base/clipboard/screen.h"
#include "../../src/base/network/net.h"
#include "../../src/base/parsing/parse.h"
#include "../../src/base/tesseract/extract.h"

#include <thread>
#include <chrono>

class Base
{
public:
    static void Init();
    static void Loop();

private:
    static void SetConsoleColor(size_t textColor, size_t bgColor);
    static std::string SanitizeString(const std::string& input);
    static void CaptureClickCoordinates();
    static void NormalizeCoordinates();

    inline static POINT m_StartPoint;
    inline static POINT m_EndPoint;
    inline static std::string m_CurrentClipboard;
    inline static const std::string m_ApiUrl = "https://orthographe.reverso.net/api/v1/Spelling/";
    inline static const std::string m_RequestPart1 = "{\"englishDialect\":\"indifferent\",\"autoReplace\":true,\"getCorrectionDetails\":true,\"interfaceLanguage\":\"fr\",\"locale\":\"\",\"language\":\"fra\",\"text\":\"";
    inline static const std::string m_RequestPart2 = "\",\"originalText\":\"\",\"spellingFeedbackOptions\":{\"insertFeedback\":true,\"userLoggedOn\":false},\"origin\":\"interactive\",\"isHtml\":false,\"IsUserPremium\":false}";
};
