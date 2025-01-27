#include "reverso.h"

void Reverso::Loop()
{
    const std::string reversoResponse = Network::POST(m_ApiUrl, m_RequestPart1 + Base::GetCurrentText() + m_RequestPart2);

    nlohmann::json jsonResponse = nlohmann::json::parse(reversoResponse);

    std::cout << "Reverso:" << std::endl;

    if (jsonResponse.contains("corrections") && jsonResponse["corrections"].is_array())
    {
        for (const auto& correction : jsonResponse["corrections"])
        {
            if (correction.contains("mistakeText") && correction.contains("correctionText"))
            {
                std::string mistake = correction["mistakeText"];
                std::string fix = correction["correctionText"];
                std::cout << mistake << " -> " << fix << std::endl;
            }
        }
    }
}
