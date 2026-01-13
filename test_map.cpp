#include "map.h"
#include "land.h"
#include "stronghold.h"
#include <iostream>
#include <memory>


int main() {
    Map map;
    Land_sptr Winterfell = make_land_ref("Winterfell", 1, 1, StrongHold::Fortress);
    Land_sptr MountCoatlin = make_land_ref("Mount Coatlin", 0, 1, StrongHold::None);
    Land_sptr CastleBlack = make_land_ref("Castle Black", 1, 0, StrongHold::None);
    Land_sptr Karhold = make_land_ref("Karhold", 1, 0, StrongHold::None);
    Land_sptr WhiteHarbor = make_land_ref("White Harbor", 0, 0, StrongHold::Castle);
    Land_sptr WidowsWatch = make_land_ref("Widow's Watch", 0, 1, StrongHold::None);
    Land_sptr TheStonyShore = make_land_ref("The Stony Shore", 0, 1, StrongHold::None);

    map.add_land(MountCoatlin);
    map.add_land(Winterfell);
    map.add_land(CastleBlack);
    map.add_land(Karhold);
    map.add_land(WhiteHarbor);
    map.add_land(WidowsWatch);
    map.add_land(TheStonyShore);

    map.make_neighbors(Winterfell, MountCoatlin);
    map.make_neighbors(Winterfell, CastleBlack);
    map.make_neighbors(Winterfell, Karhold);
    map.make_neighbors(Winterfell, WhiteHarbor);
    map.make_neighbors(Winterfell, TheStonyShore);
    map.make_neighbors(WhiteHarbor, WidowsWatch);
    map.make_neighbors(Karhold, CastleBlack);
    map.make_neighbors(WhiteHarbor, MountCoatlin);

    std::cout << map.print_map() << std::endl;
    return 0;
}
