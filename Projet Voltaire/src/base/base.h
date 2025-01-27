#pragma once

#include "../../src/base/screen/screen.h"
#include "../../src/base/network/net.h"
#include "../../src/base/parsing/reverso/reverso.h"
#include "../../src/base/tesseract/extract.h"

#include <thread>
#include <chrono>

class Base
{
public:
    static void Init();
    static void Loop();

    static std::string GetCurrentText();

private:
    static void SetConsoleColor(size_t textColor, size_t bgColor);
    static std::string SanitizeString(const std::string& input);
    static void CaptureClickCoordinates();
    static void NormalizeCoordinates();

    inline static POINT m_StartPoint;
    inline static POINT m_EndPoint;
    inline static std::string m_CurrentText;
};
