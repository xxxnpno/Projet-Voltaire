#include "base.h"

void Base::Init()
{
    Extract::Init();

    CaptureClickCoordinates();
    NormalizeCoordinates();

    Screen::Init(m_StartPoint, m_EndPoint);

    std::cout << Logger::Info() << "Wating for text!" << std::endl;
}

void Base::Loop()
{    
    Screen::Loop();

    const std::string newInput = SanitizeString(Extract::ExtractText());

    if (newInput == m_CurrentText || newInput.empty()) return;

    m_CurrentText = newInput;

    system("cls");

    std::cout << "Input  : " << m_CurrentText << std::endl;

    Reverso::Loop();
    //Scribens::Loop();
}

std::string Base::GetCurrentText()
{
    return m_CurrentText;
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

    size_t pos;
    while ((pos = sanitized.find("  ")) != std::string::npos)
    {
        sanitized.replace(pos, 2, " ");
    }

    if (!sanitized.empty() && sanitized[sanitized.size() - 1] == ' ')
    {
        sanitized.pop_back();
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
