#include "map.h"
#include "land.h"
#include "stronghold.h"
#include <iostream>


int main() {
    Map map;
    Land* Winterfell = new Land("Winterfell", 1, 0, StrongHold::Fortress);
    map.add_land(Winterfell);
    Land* MountCoatlin = new Land("MountCoatlin", 0, 1, StrongHold::None);
    map.add_land(MountCoatlin);
    map.make_neighbors(Winterfell, MountCoatlin);
    std::cout << map.print_map() << std::endl;
    return 0;
}
