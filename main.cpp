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
    << army->get_house() << " army at " << army->print_position() 
    << std::endl;
    return order;
}


Map build_map(initializer_list<Land>&& lands, initializer_list<pair<string, string>>&& borders){
    Map map;
    for (auto&& land: lands) {
        map.add_land(make_shared<Land>(move(land)));
    }
    for (auto&& [land1, land2]: borders) {
        map.make_neighbors(map.get_land(move(land1)), map.get_land(move(land2)));
    }
    cout << map.print_map() << endl;
    return map;
}


shared_ptr<Army> build_army(House house, unsigned int soldiers, unsigned int knights, string&& position, Map& map) {
    shared_ptr<Army> army = make_shared<Army>(house, soldiers, knights, map.get_land(move(position)));
    army->get_position()->set_army(army);
    return army;
}


void merge_armies(shared_ptr<Army> incoming_army, shared_ptr<Army> inplace_army) {
    cout << "Merging " << incoming_army->get_house() << " armies at " << incoming_army->print_position() << endl;
    incoming_army->add_soldiers(inplace_army->get_soldiers_number());
    incoming_army->add_knights(inplace_army->get_knights_number());
    //TODO: delete inplace_army.get();
    cout << incoming_army->print_status() << endl;
    incoming_army->get_position()->set_army(incoming_army);
}

void initiate_battle(shared_ptr<Army> incoming_army, shared_ptr<Army> inplace_army) {
    shared_ptr<Army>& winning_army = incoming_army->get_strength() > inplace_army->get_strength() ? 
        incoming_army : inplace_army;
    shared_ptr<Army>& losing_army = incoming_army->get_strength() > inplace_army->get_strength() ?
        inplace_army : incoming_army;
    delete losing_army.get();
    winning_army->get_position()->set_army(winning_army);
}


void execute_move_order(MoveOrder& move_order, Map map){
    move_order.execute();
    if (map.get_land(move_order.get_destination())->has_army()) {
        shared_ptr<Army> inplace_army = map.get_land(move_order.get_destination())->get_army();
        shared_ptr<Army> incoming_army = move_order.get_army();
        inplace_army->get_house() == incoming_army->get_house() ? 
            merge_armies(incoming_army, inplace_army)
            : initiate_battle(incoming_army, inplace_army);
    }
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


    shared_ptr<Army> EdvardStarkTroops = build_army(House::Stark, 2, 1, "Winterfell", map);
    shared_ptr<Army> JonSnowTroops = build_army(House::Stark, 1, 1, "Mount Coatlin", map);
    

    std::cout << EdvardStarkTroops->print_status() << std::endl;
    std::cout << JonSnowTroops->print_status() << std::endl;

    MoveOrder move_order = make_move_order(EdvardStarkTroops, map);
    execute_move_order(move_order, map);

    std::cout << EdvardStarkTroops->print_status() << std::endl;
    std::cout << JonSnowTroops->print_status() << std::endl;

    return 0;
}
