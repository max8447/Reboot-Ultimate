#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "discord.h"
#include "log.h"

static inline size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* buffer) {
    size_t total_size = size * nmemb;
    buffer->append((char*)contents, total_size);
    return total_size;
}

inline std::vector<std::string> PlayerBotNames;

static inline DWORD WINAPI InitBotNames(LPVOID)
{
    std::string URL = "https://raw.githubusercontent.com/max8447/Fortnite-Bot-Names/main/BotNames.txt";

    CURL* curl = curl_easy_init();
    if (!curl)
    {
        LOG_WARN(LogDev, "Failed to init bot names!");
        return 0;
    }

    curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());

    std::string response;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
        LOG_WARN(LogDev, "Failed to fetch: {}", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return 0;
    }

    curl_easy_cleanup(curl);

    std::istringstream stream(response);
    std::string CurrentLine;
    while (std::getline(stream, CurrentLine))
        PlayerBotNames.push_back(CurrentLine);
}