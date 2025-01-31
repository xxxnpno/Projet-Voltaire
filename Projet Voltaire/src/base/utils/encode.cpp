#include "encode.h"

std::string Encode::EncodeURL(const std::string& value)
{
    std::ostringstream encoded;
    encoded.fill('0');
    encoded << std::hex;

    for (char c : value)
    {
        if (isalnum(static_cast<unsigned char>(c)) || c == '-' || c == '_' || c == '.' || c == '~')
        {
            encoded << c;
        }
        else
        {
            encoded << '%' << std::setw(2) << std::uppercase << static_cast<int>(static_cast<unsigned char>(c));
        }
    }
    return encoded.str();
}
