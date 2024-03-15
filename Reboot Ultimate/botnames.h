#pragma once

#include <vector>
#include <string>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* buffer) {
    size_t total_size = size * nmemb;
    buffer->append((char*)contents, total_size);
    return total_size;
}

std::vector<std::string> PlayerBotNames;

void GetBotNames()
{


}