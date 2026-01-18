#pragma once
#include <map>
#include <memory>
#include <iostream>
#include <string>
#include <stdexcept>
#include "map.h"
#include "army.h"


using ArmyUptr = std::unique_ptr<Army>;

void check_position(const Map& map, const string& position) {
    if (!map.contains(position)) {
        throw std::invalid_argument("Invalid position: " + position);
    }
}


class Board {
    Map map;
    std::map<string, ArmyUptr> armies;
public:
    Board(Map&& map) : map{std::move(map)} {armies = std::map<string, ArmyUptr>();}

    void place_units(const string& position, House house, int number_of_soldiers, int number_of_knights) {
        check_position(map, position);
        auto army = armies.find(position);
        if (army == armies.end()) {
            armies.insert({position, make_unique<Army>(house, number_of_soldiers, number_of_knights)});
            cout << "New " << house::print(house) << " army was formed at " << position << " with " 
            << number_of_soldiers << " soldiers and " << number_of_knights << " knights" << endl;
        } else {
            army->second->add_soldiers(number_of_soldiers);
            army->second->add_knights(number_of_knights);
            cout << "House " << house::print(house) << " has recruted " << number_of_soldiers
            << " soldiers and " << number_of_knights << " knights at " << position << endl;
        }
    }

    const std::string print() const {
        std::stringstream ss;
        for (auto& land_name: map.get_lands_names()) {
            ss << land_name;
            auto army = armies.find(land_name);
            if (army != armies.end()) {
                ss << ": " << army->second->print_status();
            }
            ss << endl;
        }
        return ss.str();
    }

    const std::string print_map() const { return map.print(); }

    void move_units(const string& from, const string& to, int number_of_soldiers, int number_of_knights) {
        check_position(map, from);
        check_position(map, to);
        auto origin_army = armies.find(from);
        if (origin_army == armies.end()) {
            cout << "[ERROR]: No army found at " << from << endl;
            return;
        }
        ArmyUptr moving_army = make_unique<Army>(
            origin_army->second->withdraw_units(number_of_soldiers, number_of_knights)
        );
        cout << number_of_soldiers << " soldiers and " << number_of_knights << " knights of house "
        << origin_army->second->print_house() <<" were moved from " << from << " to " << to << endl;
        auto destination_army = armies.find(to);
        if (destination_army == armies.end()) {
            armies.insert({to, std::move(moving_army)});
        } else {
            ArmyUptr resulting_army = make_unique<Army>(face_off(*moving_army, *destination_army->second));
            armies.at(to) = std::move(resulting_army);
        }
    }
};
