#ifndef __STRINGUTIL_HH__
#define __STRINGUTIL_HH__

#include <ctime>
#include <random>
#include <string>

std::string generateRandomString(size_t length) {
    const std::string characters = 
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789";

    static std::random_device rd;  // Seed source
    static std::mt19937 rng(rd()); // Random engine seeded once
    std::uniform_int_distribution<> dist(0, characters.size() - 1);

    std::string result;
    result.reserve(length);

    for (size_t i = 0; i < length; ++i) {
        result += characters[dist(rng)];
    }
    return result;
}


#endif // __STRINGUTIL_HH__