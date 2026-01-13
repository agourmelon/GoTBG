#include "army.h"
#include "land.h"
#include "stronghold.h"
#include "map.h"
#include "order.h"
#include <iostream>

MoveOrder make_move_order(shared_ptr<Army> army, const Map& map) {
    std::cout <<  army->get_house() << " army at " << army->print_position() << " is moving " << std::endl;
    std::cout << "Possible destinations: " << army->get_position()->print_neighbors() << std::endl;
    std::string destination_name;
    std::getline(std::cin, destination_name);
    bool valid_response = army->get_position()->get_neighbors_name().contains(destination_name);
    while (!valid_response) {
        std::cout << "Invalid destination" << std::endl;
        std::cout << "Possible destinations: " << army->get_position()->print_neighbors() << std::endl;
        std::getline(std::cin, destination_name);
        valid_response = army->get_position()->get_neighbors_name().contains(destination_name);
    }
    Land_sptr destination = map.get_land(destination_name);
    MoveOrder order(army, destination);
    std::cout << "Move order to " 
    << destination->get_name() << " has been sent to the " 
    << army->get_house() << " army at" << army->print_position() 
    << std::endl;
    return order;
}


Map build_map(initializer_list<Land>&& lands, initializer_list<pair<string, string>>&& borders){
    Map map;
    for (auto land: lands) {
        map.add_land(make_shared<Land>(land));
    }
    for (auto [land1, land2]: borders) {
        map.make_neighbors(map.get_land(land1), map.get_land(land2));
    }
    cout << map.print_map() << endl;
    return map;
}


int main() {
    Map map = build_map(
        {
            {"Winterfell", 1, 1, StrongHold::Fortress}, 
            {"Mount Coatlin", 0, 1, StrongHold::None}, 
            {"Castle Black", 1, 0, StrongHold::None}, 
            {"Karhold", 1, 0, StrongHold::None}, 
            {"White Harbor", 0, 0, StrongHold::Castle}, 
            {"Widow's Watch", 0, 1, StrongHold::None}, 
            {"The Stony Shore", 0, 1, StrongHold::None}
        },
        {
            {"Winterfell", "Mount Coatlin"},
            {"Winterfell", "Castle Black"},
            {"Winterfell", "Karhold"},
            {"Winterfell", "White Harbor"},
            {"Winterfell", "The Stony Shore"},
            {"White Harbor", "Widow's Watch"},
            {"Karhold", "Castle Black"},
            {"White Harbor", "Mount Coatlin"}
        }
    );


    shared_ptr<Army> EdvardTroops = make_shared<Army>(House::Stark, 1, 1, map.get_land("Winterfell"));

    std::cout << EdvardTroops->print_status() << std::endl;

    MoveOrder move_order = make_move_order(EdvardTroops, map);
    move_order.execute();

    std::cout << EdvardTroops->print_status() << std::endl;

    return 0;
}
