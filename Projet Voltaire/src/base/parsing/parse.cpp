#include "parse.h"

std::string Parse::ParseResponse(const std::string& response)
{
    try
    {
        nlohmann::json jsonResponse = nlohmann::json::parse(response);
        if (jsonResponse.contains("text") && jsonResponse["text"].is_string())
        {
            return jsonResponse["text"];
        }
        else
        {
            std::cerr << Logger::Error() << "Missing or invalid 'text' field in response JSON." << std::endl;
            return "";
        }
    }
    catch (const nlohmann::json::exception& e)
    {
        std::cerr << Logger::Error() << "JSON parsing error in ParseResponse: " << e.what() << std::endl;
        return "";
    }
}

std::string Parse::ParseError(const std::string& response)
{
    try
    {
        nlohmann::json jsonResponse = nlohmann::json::parse(response);
        std::stringstream errors;

        if (jsonResponse.contains("corrections") && jsonResponse["corrections"].is_array())
        {
            for (const auto& correction : jsonResponse["corrections"])
            {
                if (correction.contains("mistakeText") && correction.contains("correctionText") &&
                    correction["mistakeText"].is_string() && correction["correctionText"].is_string())
                {
                    errors << "Error: " << correction["mistakeText"] << " -> " << correction["correctionText"] << "\n";
                }
                else
                {
                    std::cerr << Logger::Warn() << "Invalid correction format in response JSON." << std::endl;
                }
            }
        }
        else
        {
            std::cerr << Logger::Warn() << "Missing or invalid 'corrections' field in response JSON." << std::endl;
        }

        if (jsonResponse.contains("autoReplacements") && jsonResponse["autoReplacements"].is_array())
        {
            for (const auto& replacement : jsonResponse["autoReplacements"])
            {
                if (replacement.contains("mistakeText") && replacement.contains("replacementText") &&
                    replacement["mistakeText"].is_string() && replacement["replacementText"].is_string())
                {
                    errors << "Error: " << replacement["mistakeText"] << " -> " << replacement["replacementText"] << "\n";
                }
                else
                {
                    std::cerr << Logger::Warn() << "Invalid autoReplacement format in response JSON." << std::endl;
                }
            }
        }
        else
        {
            std::cerr << Logger::Warn() << "Missing or invalid 'autoReplacements' field in response JSON." << std::endl;
        }

        return errors.str();
    }
    catch (const nlohmann::json::exception& e)
    {
        std::cerr << Logger::Error() << "JSON parsing error in ParseError: " << e.what() << std::endl;
        return "";
    }
}
