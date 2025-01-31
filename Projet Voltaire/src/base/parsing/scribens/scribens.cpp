#include "scribens.h"

void Scribens::Loop()
{
    const std::string payload = m_RequestPart1 + Encode::EncodeURL(Base::GetCurrentText()) + m_RequestPart2;
    
    const std::string scribensResponse = Network::POST(m_ApiUrl, payload, m_Headers);

    nlohmann::json jsonResponse = nlohmann::json::parse(scribensResponse);

    std::cout << "Scribens:" << std::endl;

    std::cout << scribensResponse << std::endl;
}