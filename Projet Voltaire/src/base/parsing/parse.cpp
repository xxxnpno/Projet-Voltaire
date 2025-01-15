#include "parse.h"

std::string Parse::ParseResponse(const std::string& response)
{
    nlohmann::json jsonResponse = nlohmann::json::parse(response);

    return jsonResponse["text"];
}

std::string Parse::ParseError(const std::string& response)
{
    nlohmann::json jsonResponse = nlohmann::json::parse(response);

    std::stringstream errors;

    if (!jsonResponse["corrections"].empty())
    {
        for (const auto& correction : jsonResponse["corrections"])
        {
            std::string mistakeText = correction["mistakeText"];
            std::string correctionText = correction["correctionText"];

            errors << "Error: " << mistakeText << " -> " << correctionText << "\n";
        }
    }

    if (!jsonResponse["autoReplacements"].empty())
    {
        for (const auto& replacement : jsonResponse["autoReplacements"])
        {
            std::string mistakeText = replacement["mistakeText"];
            std::string replacementText = replacement["replacementText"];

            errors << "Error: " << mistakeText << " -> " << replacementText << "\n";
        }
    }
    return errors.str();
}
