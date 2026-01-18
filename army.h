#pragma once
#include <string>
#include <sstream>
#include <stdexcept>
#include "house.h"

class Army {
    House house;
    int soldiers;
    int knights;
public:
    Army(House house, int soldiers, int knights):
        house{house}, soldiers{soldiers}, knights{knights}  {}

    std::string print_house() const {return house::print(house);}

    House get_house() const {return house;}

    int get_soldiers_number() const {return soldiers;}

    int get_knights_number() const {return knights;}

    void add_soldiers(int number) {soldiers += number;}

    void add_knights(int number) {knights += number;}

    int get_strength() const {return soldiers + 2*knights;}

    std::string print_status() const {
        std::stringstream ss;
        ss << this->print_house() << " army with " << this->get_soldiers_number() 
            << " soldiers and " << this->get_knights_number() << " knights";
        return ss.str();
    }

    Army withdraw_units(int number_of_soldiers, int number_of_knights) {
        if (number_of_soldiers > soldiers || number_of_knights > knights) {
            std::stringstream ss;
            ss << "number of units to withdraw (" << number_of_soldiers 
            << " soldiers, " << number_of_knights << " knights) can not be higher than army's"
            " number of units (" << soldiers << " soldiers, " << knights << " knights)" << std::endl;
            throw std::invalid_argument(ss.str());
        }
        this->soldiers -= number_of_soldiers;
        this->knights -= number_of_knights;
        return Army(this->house, number_of_soldiers, number_of_knights);
    }

};


Army face_off(Army& army1, Army& army2) {
    if (army1.print_house() == army2.print_house()) {
        return Army(
            army1.get_house(),
            army1.get_soldiers_number() + army2.get_soldiers_number(),
            army1.get_knights_number() + army2.get_knights_number()
        );
    }
    if (army1.get_strength() > army2.get_strength()) {
        return army1;
    }
    return army2;
}
