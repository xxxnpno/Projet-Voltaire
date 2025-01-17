#include "extract.h"

void Extract::Init()
{
    if (m_Tess)
    {
        std::cerr << Logger::Warn() << "Tesseract API is already initialized." << std::endl;
        return;
    }

    m_Tess = new tesseract::TessBaseAPI();

    if (m_Tess->Init(m_LangPath, m_Lang))
    {
        std::cerr << Logger::Error() << "Failed to initialize Tesseract API with language: " << m_Lang << std::endl;
        delete m_Tess;
        m_Tess = nullptr;
    }
    else
    {
        std::cout << Logger::Info() << "Tesseract API initialized successfully." << std::endl;
    }
}

std::string Extract::ExtractText()
{
    if (!m_Tess)
    {
        std::cerr << Logger::Error() << "Tesseract API not initialized. Call Init() first." << std::endl;
        return "";
    }

    Pix* image = pixRead(m_ImagePath);
    if (!image)
    {
        std::cerr << Logger::Error() << "Couldn't load image at path: " << m_ImagePath << std::endl;
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
        std::cerr << Logger::Error() << "Text extraction failed." << std::endl;
    }

    pixDestroy(&image);
    return result;
}

void Extract::Cleanup()
{
    if (m_Tess)
    {
        m_Tess->End();
        delete m_Tess;
        m_Tess = nullptr;
    }
}
