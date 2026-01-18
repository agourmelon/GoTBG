#include "army.h"
#include "land.h"
#include "stronghold.h"
#include "map.h"
#include "board.h"
#include <iostream>


const Map build_map(initializer_list<Land>&& lands, initializer_list<pair<string, string>>&& borders){
    Map map;
    for (auto land: move(lands)) {
        map.add_land(make_shared<Land>(move(land)));
    }
    for (auto [land1, land2]: move(borders)) {
        map.make_neighbors(map.get_land(move(land1)), map.get_land(move(land2)));
    }
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


    Board board(move(map));
    cout << board.print_map() << endl;

    board.place_units("Winterfell", House::Stark, 1, 0);
    board.place_units("Winterfell", House::Stark, 0, 2);
    board.place_units("Mount Coatlin", House::Greyjoy, 1, 1);
    board.place_units("White Harbor", House::Greyjoy, 1, 1);

    cout << board.print() << endl;

    board.move_units("Winterfell", "Castle Black", 1, 0);
    board.move_units("Mount Coatlin", "White Harbor", 1, 0);

    cout << board.print() << endl;

    board.move_units("White Harbor", "Winterfell", 2, 1);

    cout << board.print() << endl;

    return 0;
}
