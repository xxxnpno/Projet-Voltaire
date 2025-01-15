#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

class ClipBoard
{
public:
    std::string GetClipboard();

private:
    std::string FixClipboardString(const std::string& clipboardText);
};