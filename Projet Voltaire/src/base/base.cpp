#include "base.h"

void Base::Init()
{
    Extract e;
    Clipboard cb;

    e.Init();
    cb.SaveClipboardImage();
    
    m_CurrentClipboard = FixString(e.ExtractText());
}

void Base::Loop()
{    
    Network net;
    Parse par;
    Extract e;
    Clipboard cb;

    cb.SaveClipboardImage();

    std::string input = FixString(e.ExtractText());

    if (input == m_CurrentClipboard) return;

    m_CurrentClipboard = input;

    const std::string response = net.POST(m_ApiUrl, m_Jsp1 + m_CurrentClipboard + m_Jsp2);

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

void Base::SetColor(const size_t textColor, const size_t bgColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

std::string Base::FixString(const std::string& input)
{
    std::string output = input;
    for (char& c : output) {
        if (c == '\n') {
            c = ' ';
        }
    }
    return output;
}