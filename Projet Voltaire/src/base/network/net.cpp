#include "net.h"

size_t Network::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string Network::POST(const std::string& url, const std::string& data, const std::vector<std::string>& headers)
{
    CURL* curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if (!curl)
    {
        std::cerr << Logger::Error() << "Failed to initialize CURL." << std::endl;
        return "";
    }

    struct curl_slist* curlHeaders = nullptr;
    for (const auto& header : headers)
    {
        curlHeaders = curl_slist_append(curlHeaders, header.c_str());
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, curlHeaders);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK)
    {
        std::cerr << Logger::Error() << "CURL request failed: " << curl_easy_strerror(res) << std::endl;
        std::cerr << Logger::Error() << "URL: " << url << std::endl;
        std::cerr << Logger::Error() << "Data: " << data << std::endl;
    }

    curl_slist_free_all(curlHeaders);
    curl_easy_cleanup(curl);

    return response;
}

std::string Network::GET(const std::string& url, const std::vector<std::string>& headers)
{
    CURL* curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if (!curl)
    {
        std::cerr << Logger::Error() << "Failed to initialize CURL." << std::endl;
        return "";
    }

    struct curl_slist* curlHeaders = nullptr;
    for (const auto& header : headers)
    {
        curlHeaders = curl_slist_append(curlHeaders, header.c_str());
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, curlHeaders);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK)
    {
        std::cerr << Logger::Error() << "CURL request failed: " << curl_easy_strerror(res) << std::endl;
        std::cerr << Logger::Error() << "URL: " << url << std::endl;
    }

    curl_slist_free_all(curlHeaders);
    curl_easy_cleanup(curl);

    return response;
}