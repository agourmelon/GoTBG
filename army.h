#pragma once
#include "land.h"
#include <string>
#include <sstream>


enum class House {
    Stark, Greyjoy, Lannister, Tyrell, Baratheon, Martel
};

inline std::string print_house(House house) {
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

class Army : public enable_shared_from_this<Army> {
    House house;
    unsigned int soldiers;
    unsigned int knights;
    Land_sptr position;
public:
    Army(House house, unsigned int soldiers, unsigned int knights, Land_sptr position):
        house{house}, soldiers{soldiers}, knights{knights}, position{position} {}
    
    std::string get_house() const {return print_house(house);}

    unsigned int get_soldiers_number() const {return soldiers;}

    unsigned int get_knights_number() const {return knights;}

    Land_sptr get_position() const {
        return position;
    };

    void set_position(Land_sptr new_position) {
        swap(position, new_position); 
    }

    std::string print_position() const {return position->get_name();}

    std::string print_status() const {
        std::stringstream ss;
        ss 
            << this->get_house() 
            << " army at " 
            << this->print_position() 
            << " with " 
            << this->get_soldiers_number() 
            << " soldiers and " 
            << this->get_knights_number() 
            << " knights";
        return ss.str();
    }

    unsigned int get_strength() const {
        return soldiers + knights * 2;
    }

    void add_soldiers(unsigned int soldiers) {
        this->soldiers += soldiers;
    }

    void add_knights(unsigned int knights) {
        this->knights += knights;
    }
};
