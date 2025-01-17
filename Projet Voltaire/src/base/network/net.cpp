#include "net.h"

size_t Network::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string Network::POST(const std::string& url, const std::string& data)
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

    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36");

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK)
    {
        std::cerr << Logger::Error() << "CURL request failed: " << curl_easy_strerror(res) << std::endl;
        std::cerr << Logger::Error() << "URL: " << url << std::endl;
        std::cerr << Logger::Error() << "Data: " << data << std::endl;
    }

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    return response;
}
