#include "land.h"
#include "map.h"
#include <sstream>

void Map::add_land(const Land* land){
    lands.insert({land->get_name(), const_cast<Land*>(land)});
}

void Map::make_neighbors(Land* land1, Land* land2){
    land1->share_border_with(land2);
}

string Map::print_map(){
    stringstream ss;
    for (auto land: this->lands) {
        ss << land.first << " has neighbors: " << endl;
        for (auto neighbor_name: land.second->get_neighbors_name()) {
            ss << " " << neighbor_name << endl;
        }
    }
    return ss.str();
}
