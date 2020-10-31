//
// Created by bdmendes on 31/10/20.
//

#include <algorithm>
#include "util.h"

bool util::isdigit(const std::string &str) {
    return std::all_of(str.begin(),str.end(), [](const char c){return std::isdigit(c);});
}

bool util::contains(const std::string &str, const std::string &expected) {
    return str.find(expected) != std::string::npos;
}

void util::normalize(std::string &str, bool isName) {
    for (int i = 0; i < str.size(); ++i){
        //strip unneeded spaces
        if (str.at(i) == SPACE && (i == 0 || (i < str.size() - 1 && str.at(i+1) == SPACE))){
            str.erase(str.begin() + i);
            i--;
            continue;
        }

        //ensure only first word char is uppercase
        if (std::isupper(str.at(i)) && i > 0 && std::isupper(str.at(i-1))){
            str.at(i) = std::tolower(str.at(i));
            continue;
        }

        //if it's a person name, ensure first word char is uppercase
        if (isName && (i==0 || str.at(i-1) == SPACE) && std::islower(str.at(i))){
            str.at(i) = std::toupper(str.at(i));
        }
    }
}

void util::stripSpecialChars(std::string& str){
    str.erase(std::remove(str.begin(),str.end(),[](const char c){return !std::isalnum(c) && c != SPACE;}), str.end());
}

void util::lowercase(std::string &str) {
    std::transform(str.begin(),str.end(),str.begin(),[](unsigned char c){return std::tolower(c);});
}