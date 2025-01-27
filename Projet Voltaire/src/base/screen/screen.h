#pragma once

#include "../../src/base/utils/logger.h"

#include <fstream>
#include <string>
#include <windows.h>

class Screen
{
public:
    static void Init(const POINT& p1, const POINT& p2);
    static void Loop();

private:
    static inline const std::string m_PngPath = "image.png";
    inline static POINT m_StartPoint;
    inline static POINT m_EndPoint;

    static void SaveScreenshot();
    static bool ValidateCoordinates(const POINT& p1, const POINT& p2);
    static HBITMAP CaptureScreenArea(HDC hScreenDC, int left, int top, int width, int height);
    static bool SaveBitmapToFile(HBITMAP hBitmap, int width, int height);
};
