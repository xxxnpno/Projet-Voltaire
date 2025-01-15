#include "clipboard.h"

std::string ClipBoard::GetClipboard()
{
    if (!OpenClipboard(nullptr))
    {
        return "ERROR_OPENING_CLIPBOARD";
    }

    std::string clipboardText;

    if (IsClipboardFormatAvailable(CF_UNICODETEXT))
    {
        HANDLE hClipboardData = GetClipboardData(CF_UNICODETEXT);
        if (hClipboardData)
        {
            wchar_t* clipboardContent = static_cast<wchar_t*>(GlobalLock(hClipboardData));
            if (clipboardContent)
            {
                int bufferSize = WideCharToMultiByte(CP_UTF8, 0, clipboardContent, -1, nullptr, 0, nullptr, nullptr);
                if (bufferSize > 0)
                {
                    char* buffer = new char[bufferSize];
                    WideCharToMultiByte(CP_UTF8, 0, clipboardContent, -1, buffer, bufferSize, nullptr, nullptr);
                    clipboardText = buffer;
                    delete[] buffer;
                }
                GlobalUnlock(hClipboardData);
            }
        }
    }
    CloseClipboard();

    const std::string result = FixClipboardString(clipboardText);
    return result;
}

std::string ClipBoard::FixClipboardString(const std::string& clipboardText)
{
    std::string fixedText = clipboardText;

    size_t pos = 0;
    while ((pos = fixedText.find_first_of("\n\r", pos)) != std::string::npos)
    {
        fixedText.replace(pos, 1, " ");
    }
    return fixedText;
}