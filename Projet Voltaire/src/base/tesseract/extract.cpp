#include "extract.h"

void Extract::Init()
{
    m_Tess = new tesseract::TessBaseAPI();
    if (m_Tess->Init(m_LangPath, m_Lang))
    {
        std::cerr << "Error: Failed to initialize Tesseract API." << std::endl;
        delete m_Tess;
        m_Tess = nullptr;
    }
}

std::string Extract::ExtractText()
{
    if (!m_Tess)
    {
        std::cerr << "Error: Tesseract API not initialized." << std::endl;
        return "";
    }

    Pix* image = pixRead(m_ImagePath);
    if (!image)
    {
        std::cerr << "Error: Couldn't load image." << std::endl;
        return "";
    }

    m_Tess->SetImage(image);
    char* extractedText = m_Tess->GetUTF8Text();
    std::string result;

    if (extractedText)
    {
        result = extractedText;
        delete[] extractedText;
    }
    else
    {
        std::cerr << "Error: Couldn't extract text." << std::endl;
    }

    pixDestroy(&image);
    return result;
}