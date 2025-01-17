#pragma once

#include "../../src/base/utils/logger.h"

#include <string>

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

class Extract
{
public:
    static void Init();
    static std::string ExtractText();
    static void Cleanup();

private:
    inline static tesseract::TessBaseAPI* m_Tess = nullptr;
    inline static const char* m_ImagePath = "image.png";
    inline static const char* m_LangPath = "";
    inline static const char* m_Lang = "fra";
};
