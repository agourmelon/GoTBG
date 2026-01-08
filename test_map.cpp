#include "map.h"
#include "land.h"
#include "stronghold.h"
#include <iostream>
#include <memory>

using namespace std;

int main() {
    Map map;
    shared_ptr<Land> Winterfell = make_shared<Land>("Winterfell", 1, 0, StrongHold::Fortress);
    map.add_land(Winterfell);
    shared_ptr<Land> MountCoatlin = make_shared<Land>("MountCoatlin", 0, 1, StrongHold::None);
    map.add_land(MountCoatlin);
    map.make_neighbors(Winterfell, MountCoatlin);
    std::cout << map.print_map() << std::endl;
    return 0;
}
