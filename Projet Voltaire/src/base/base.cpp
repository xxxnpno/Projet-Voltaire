#include "base.h"

void Base::Init()
{
    Extract::Init();

    CaptureClickCoordinates();
    NormalizeCoordinates();

    Screen::SaveScreenshot(m_StartPoint, m_EndPoint);

    m_CurrentClipboard = SanitizeString(Extract::ExtractText());
}

void Base::Loop()
{
    Screen::SaveScreenshot(m_StartPoint, m_EndPoint);

    std::string newInput = SanitizeString(Extract::ExtractText());

    if (newInput == m_CurrentClipboard || newInput.empty()) return;

    m_CurrentClipboard = newInput;

    const std::string response = Network::POST(m_ApiUrl, m_RequestPart1 + m_CurrentClipboard + m_RequestPart2);

    std::string correctedText = Parse::ParseResponse(response);
    std::string errorDetails = Parse::ParseError(response);

    SetConsoleColor(6, 0);
    std::cout << "==========================" << std::endl;

    SetConsoleColor(correctedText == m_CurrentClipboard ? 2 : 4, 0);

    std::cout << "Input: " << m_CurrentClipboard << std::endl;

    if (!correctedText.empty() && correctedText.back() == '\n') correctedText.pop_back();
        
    std::cout << "Output: " << correctedText << std::endl;

    if (!errorDetails.empty())
    {
        if (errorDetails.back() == '\n') errorDetails.pop_back();
            
        std::cout << errorDetails << std::endl;
    }

    SetConsoleColor(6, 0);
    std::cout << "==========================" << std::endl;
}

void Base::SetConsoleColor(size_t textColor, size_t bgColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

std::string Base::SanitizeString(const std::string& input)
{
    std::string sanitized = input;
    for (char& c : sanitized)
    {
        if (c == '\n') c = ' ';
    }
    return sanitized;
}

void Base::CaptureClickCoordinates()
{
    std::cout << Logger::Info() << "Waiting for first click..." << std::endl;

    while (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000));
    GetCursorPos(&m_StartPoint);
    while (GetAsyncKeyState(VK_LBUTTON) & 0x8000);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::cout << Logger::Info() << "Waiting for second click..." << std::endl;

    while (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000));
    GetCursorPos(&m_EndPoint);
    while (GetAsyncKeyState(VK_LBUTTON) & 0x8000);
}

void Base::NormalizeCoordinates()
{
    if (m_StartPoint.x > m_EndPoint.x || m_StartPoint.y > m_EndPoint.y)
    {
        std::swap(m_StartPoint, m_EndPoint);
    }
}
