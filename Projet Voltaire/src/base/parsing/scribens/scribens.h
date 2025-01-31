#pragma once

#include "../../src/base/base.h"

#include <string>
#include <sstream>

#include "../../ext/nlohmann/json.hpp"

class Scribens
{
public:
    static void Loop();
private:

    inline static const std::string m_ApiUrl = R"(https://www.scribens.fr/Scribens/TextSolution_Servlet)";
    inline static const std::string m_RequestPart1 = R"(FunctionName=GetSolutionsByPos&plugin=Website_desktop&texteHTML=3Cp%3EJ)";
    inline static const std::string m_RequestPart2 = R"(%3C%2Fp%3E&optionsCor=Genre_Je%3A0%7CGenre_Tu%3A0%7CGenre_Nous%3A0%7CGenre_Vous%3A0%7CGenre_On%3A0%7CRefOrth%3A0%7CUsBr%3A-1%7CShowUPSol%3A1&optionsStyle=RepMin%3A3%7CGapRep%3A3%7CAllWords%3A0%7CFamilyWords%3A0%7CMinPhLg%3A30%7CMinPhCt%3A5%7CTtr%3A250%7CTts%3A150&idLangue=fr&firstRequest=false&cntRequest30=0&langId=fr&nbc=14999700)";
    inline static const std::vector<std::string> m_Headers =
    {
        R"(accept: */*)",
        R"(accept-language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7)",
        R"(content-type: application/x-www-form-urlencoded; charset=UTF-8)",
        R"(origin: https://www.scribens.fr)",
        R"(referer: https://www.scribens.fr/)",
        R"(sec-ch-ua: "Google Chrome";v="131", "Chromium";v="131", "Not_A Brand";v="24")",
        R"(sec-ch-ua-mobile: ?0)",
        R"(sec-ch-ua-platform: "Windows")",
        R"(sec-fetch-dest: empty)",
        R"(sec-fetch-mode: cors)",
        R"(sec-fetch-site: same-origin)",
        R"(user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36)",
        R"(priority: u=1, i)",
    };
};
