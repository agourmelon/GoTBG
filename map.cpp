#include "land.h"
#include "map.h"
#include <sstream>

void Map::add_land(const shared_ptr<Land> land){ 
    lands.insert({land->get_name(), land});
}

void Map::make_neighbors(shared_ptr<Land> land1, shared_ptr<Land> land2){ 
    land1->share_border_with(land2);
    land2->share_border_with(land1);
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
