#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

class Clipboard
{
public:
    static void SaveClipboardImage();

private:
    inline static const std::string m_OutputPath = "ext/image/";
    inline static const std::string m_PngPath = "ext/image/image.png";
};