#include "languageTool.h"

void LanguageTool::Loop()
{
    try
    {
        const std::string payload = m_RequestPart1 + Encode::EncodeURL(Base::GetCurrentText()) + m_RequestPart2;
        const std::string response = Network::POST(m_ApiUrl, payload, m_Headers);

        nlohmann::json jsonResponse = nlohmann::json::parse(response);
        std::cout << Logger::Info() << "LanguageTool:" << std::endl;

        size_t errorCount = 0;
        if (jsonResponse.contains("matches") && jsonResponse["matches"].is_array())
        {
            for (const auto& match : jsonResponse["matches"])
            {
                if (match.contains("message") && match.contains("replacements") && !match["replacements"].empty())
                {
                    std::string incorrectPart = Base::GetCurrentText().substr(match["offset"], match["length"]);
                    std::string correctionText = match["replacements"][0]["value"];
                    std::cout << Logger::Info() << incorrectPart << " -> " << correctionText << std::endl;
                    ++errorCount;
                }
            }
        }
        if (!errorCount)
        {
            std::cout << Logger::Info() << "No error" << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << Logger::Error() << "LanguageTool: " << e.what() << std::endl;
    }
}