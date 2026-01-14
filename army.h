#pragma once
#include <string>
#include <sstream>
#include "house.h"

class Army {
    House house;
    int soldiers;
    int knights;
public:
    Army(House house, int soldiers, int knights):
        house{house}, soldiers{soldiers}, knights{knights}  {}

    std::string get_house() const {return print_house(house);}

    int get_soldiers_number() const {return soldiers;}

    int get_knights_number() const {return knights;}

    void add_soldiers(int number) {soldiers += number;}

    void add_knights(int number) {knights += number;}

    int get_strength() const {return soldiers + knights;}

    std::string print_status() const {
        std::stringstream ss;
        ss << this->get_house() << " army with " << this->get_soldiers_number() 
            << " soldiers and " << this->get_knights_number() << " knights";
        return ss.str();
    }
};
