#include "army.h"
#include "land.h"
#include "orders.h"
#include "stronghold.h"
#include <iostream>



int main() {

    Land Winterfell("Winterfell", 1, 0, StrongHold::Fortress);
    Land MountCoatlin("MountCoatlin", 0, 1, StrongHold::None);

    Army EdvardTroops(House::Stark, 1, 1, Winterfell);

    std::cout << EdvardTroops.print_status() << std::endl;

    move(EdvardTroops, MountCoatlin);

    std::cout << EdvardTroops.print_status() << std::endl;

    return 0;
}
