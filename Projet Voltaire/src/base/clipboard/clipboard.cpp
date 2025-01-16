#include "clipboard.h"

void Clipboard::SaveClipboardImage()
{
    if (!OpenClipboard(nullptr)) return;

    HANDLE hBitmap = GetClipboardData(CF_BITMAP);
    if (!hBitmap)
    {
        CloseClipboard();
        return;
    }

    HBITMAP hImage = static_cast<HBITMAP>(hBitmap);
    BITMAP bmp;
    GetObject(hImage, sizeof(BITMAP), &bmp);

    std::ofstream file(m_PngPath, std::ios::binary);
    if (!file.is_open())
    {
        CloseClipboard();
        return;
    }

    BITMAPFILEHEADER fileHeader = {};
    BITMAPINFOHEADER infoHeader = {};
    fileHeader.bfType = 0x4D42;
    fileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    fileHeader.bfSize = fileHeader.bfOffBits + (bmp.bmWidthBytes * bmp.bmHeight);

    infoHeader.biSize = sizeof(BITMAPINFOHEADER);
    infoHeader.biWidth = bmp.bmWidth;
    infoHeader.biHeight = bmp.bmHeight;
    infoHeader.biPlanes = 1;
    infoHeader.biBitCount = bmp.bmBitsPixel;
    infoHeader.biCompression = BI_RGB;

    file.write(reinterpret_cast<const char*>(&fileHeader), sizeof(fileHeader));
    file.write(reinterpret_cast<const char*>(&infoHeader), sizeof(infoHeader));

    int rowSize = ((bmp.bmWidth * bmp.bmBitsPixel + 31) / 32) * 4;
    char* buffer = new char[rowSize * bmp.bmHeight];
    GetBitmapBits(hImage, rowSize * bmp.bmHeight, buffer);

    for (size_t i = 0; i < bmp.bmHeight / 2; ++i)
    {
        char* row1 = buffer + i * rowSize;
        char* row2 = buffer + (bmp.bmHeight - i - 1) * rowSize;
        for (size_t j = 0; j < rowSize; ++j)
        {
            std::swap(row1[j], row2[j]);
        }
    }

    file.write(buffer, rowSize * bmp.bmHeight);
    delete[] buffer;

    file.close();
    CloseClipboard();
}