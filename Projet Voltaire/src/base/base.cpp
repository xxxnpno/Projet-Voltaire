#include "base.h"

void Base::Init()
{
    ClipBoard cb;
    m_CurrentClipboard = cb.GetClipboard();
}

void Base::Loop()
{
    ClipBoard cb;
    Network net;
    Parse par;

    std::string input = cb.GetClipboard();
    if (input == "ERROR_OPENING_CLIPBOARD" || m_CurrentClipboard == "ERROR_OPENING_CLIPBOARD") return;
    if (input == m_CurrentClipboard) return;

    m_CurrentClipboard = input;

    const std::string response = net.POST(m_ApiUrl, m_PostHelp + m_CurrentClipboard + m_PreHelp);

    std::string output = par.ParseResponse(response);

    SetColor(6, 0);
    std::cout << "==========================" << std::endl;
    
    if (output == m_CurrentClipboard)
    {
        SetColor(2, 0);
    }
    else
    {
        SetColor(4, 0);
    }
    std::cout << "Input: " << m_CurrentClipboard << std::endl;

    if (!output.empty() && output.back() == '\n') 
    {
        output.erase(output.size() - 1);
    }
    std::cout << "Output: " << output << std::endl;

    std::string error = par.ParseError(response);

    if (!error.empty() && error.back() == '\n')
    {
        error.erase(error.size() - 1);
    }

    if (!error.empty()) std::cout << error << std::endl;

    SetColor(6, 0);
    std::cout << "==========================" << std::endl;
}

void Base::SetColor(int textColor, int bgColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}