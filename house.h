#pragma once
#include <string>

enum class House {
    Stark, Greyjoy, Lannister, Tyrell, Baratheon, Martel
};

namespace house {
    inline std::string print(House house) {
        switch (house)
        {
        case House::Stark: return "Stark";
        case House::Greyjoy: return "Greyjoy";
        case House::Lannister: return "Lannister";
        case House::Tyrell: return "Tyrell";
        case House::Baratheon: return "Baratheon";
        case House::Martel: return "Martel";
        default: throw "Invalid House";
        }
    }
}
