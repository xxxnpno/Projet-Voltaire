#include "screen.h"

void Screen::Init(const POINT& p1, const POINT& p2)
{
    m_StartPoint = p1;
    m_EndPoint = p2;

    SaveScreenshot();
}

void Screen::Loop()
{
    SaveScreenshot();
}

void Screen::SaveScreenshot()
{
    if (!ValidateCoordinates(m_StartPoint, m_EndPoint)) return;

    int left = min(m_StartPoint.x, m_EndPoint.x);
    int top = min(m_StartPoint.y, m_EndPoint.y);
    int width = max(m_StartPoint.x, m_EndPoint.x) - left;
    int height = max(m_StartPoint.y, m_EndPoint.y) - top;

    HDC hScreenDC = GetDC(NULL);
    if (!hScreenDC)
    {
        std::cerr << Logger::Error() << "Failed to get screen DC." << std::endl;
        return;
    }

    HBITMAP hBitmap = CaptureScreenArea(hScreenDC, left, top, width, height);

    if (!SaveBitmapToFile(hBitmap, width, height)) return;

    if (hBitmap) DeleteObject(hBitmap);

    ReleaseDC(NULL, hScreenDC);
}

bool Screen::ValidateCoordinates(const POINT& p1, const POINT& p2)
{
    if (p1.x < 0 || p1.y < 0 || p2.x < 0 || p2.y < 0)
    {
        std::cerr << Logger::Error() << "Coordinates cannot be negative." << std::endl;
        return false;
    }
    return true;
}

HBITMAP Screen::CaptureScreenArea(HDC hScreenDC, int left, int top, int width, int height)
{
    HDC hMemoryDC = CreateCompatibleDC(hScreenDC);
    if (!hMemoryDC)
    {
        std::cerr << Logger::Error() << "Failed to create compatible DC." << std::endl;
        return nullptr;
    }

    HBITMAP hBitmap = CreateCompatibleBitmap(hScreenDC, width, height);
    if (!hBitmap)
    {
        std::cerr << Logger::Error() << "Failed to create compatible bitmap." << std::endl;
        DeleteDC(hMemoryDC);
        return nullptr;
    }

    SelectObject(hMemoryDC, hBitmap);
    if (!BitBlt(hMemoryDC, 0, 0, width, height, hScreenDC, left, top, SRCCOPY))
    {
        std::cerr << Logger::Error() << "Failed to capture screen area." << std::endl;
        DeleteObject(hBitmap);
        DeleteDC(hMemoryDC);
        return nullptr;
    }

    DeleteDC(hMemoryDC);
    return hBitmap;
}

bool Screen::SaveBitmapToFile(HBITMAP hBitmap, int width, int height)
{
    BITMAP bitmap;
    if (!GetObject(hBitmap, sizeof(BITMAP), &bitmap))
    {
        std::cerr << Logger::Error() << "Failed to retrieve bitmap object." << std::endl;
        return false;
    }

    int rowSize = ((width * 3 + 3) & ~3);
    int imageSize = rowSize * height;

    BITMAPFILEHEADER bfHeader = {};
    bfHeader.bfType = 0x4D42;
    bfHeader.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + imageSize;
    bfHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    BITMAPINFOHEADER biHeader = {};
    biHeader.biSize = sizeof(BITMAPINFOHEADER);
    biHeader.biWidth = width;
    biHeader.biHeight = -height;
    biHeader.biPlanes = 1;
    biHeader.biBitCount = 24;
    biHeader.biCompression = BI_RGB;

    char* pixels = new (std::nothrow) char[imageSize]();
    if (!pixels)
    {
        std::cerr << Logger::Error() << "Memory allocation for pixel data failed." << std::endl;
        return false;
    }

    HDC hMemoryDC = CreateCompatibleDC(GetDC(NULL));
    if (!GetDIBits(hMemoryDC, hBitmap, 0, height, pixels, reinterpret_cast<BITMAPINFO*>(&biHeader), DIB_RGB_COLORS))
    {
        std::cerr << Logger::Error() << "Failed to retrieve bitmap data." << std::endl;
        delete[] pixels;
        DeleteDC(hMemoryDC);
        return false;
    }

    std::ofstream outFile(m_PngPath, std::ios::binary);
    if (!outFile.is_open())
    {
        std::cerr << Logger::Error() << "Failed to open output file." << std::endl;
        delete[] pixels;
        DeleteDC(hMemoryDC);
        return false;
    }

    outFile.write(reinterpret_cast<char*>(&bfHeader), sizeof(bfHeader));
    outFile.write(reinterpret_cast<char*>(&biHeader), sizeof(biHeader));
    if (!outFile.write(pixels, imageSize))
    {
        std::cerr << Logger::Error() << "Failed to write pixel data to file." << std::endl;
    }

    delete[] pixels;
    outFile.close();
    DeleteDC(hMemoryDC);
    return true;
}
