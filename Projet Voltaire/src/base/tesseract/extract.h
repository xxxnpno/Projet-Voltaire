#pragma once

#include "../../src/base/base.h"

#include <string>

#include "../../ext/tesseract/baseapi.h"
#include "../../ext/leptonica/allheaders.h"

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
