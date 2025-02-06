#include "reverso.h"

void Reverso::Loop()
{
    try
    {
        const std::string payload = m_RequestPart1 + Base::GetCurrentText() + m_RequestPart2;
        const std::string response = Network::POST(m_ApiUrl, payload, m_Headers);

        nlohmann::json jsonResponse = nlohmann::json::parse(response);
        std::cout << Logger::Info() << "Reverso:" << std::endl;

        size_t errorCount = 0;
        if (jsonResponse.contains("corrections") && jsonResponse["corrections"].is_array())
        {
            for (const auto& correction : jsonResponse["corrections"])
            {
                if (correction.contains("mistakeText") && correction.contains("correctionText"))
                {
                    std::string incorrectPart = correction["mistakeText"];
                    std::string correctionText = correction["correctionText"];
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
        std::cerr << Logger::Error() << "Reverso: " << e.what() << std::endl;
    }
}
