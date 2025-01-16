#include <iostream>
#include <string>

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

class Extract
{
public:
    static void Init();
    static std::string ExtractText();

private:
    inline static tesseract::TessBaseAPI* m_Tess = nullptr;
    inline static const char* m_ImagePath = "ext/image/image.png";
    inline static const char* m_LangPath = "ext/lang";
    inline static const char* m_Lang = "fra";
};