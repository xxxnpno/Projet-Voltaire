#pragma once

#include "../../src/base/utils/logger.h"

#include <fstream>
#include <string>
#include <windows.h>

class Screen
{
public:
    static void SaveScreenshot(const POINT& p1, const POINT& p2);

private:
    static inline const std::string m_PngPath = "image.png";

    static bool ValidateCoordinates(const POINT& p1, const POINT& p2);
    static HBITMAP CaptureScreenArea(HDC hScreenDC, int left, int top, int width, int height);
    static bool SaveBitmapToFile(HBITMAP hBitmap, int width, int height);
};
