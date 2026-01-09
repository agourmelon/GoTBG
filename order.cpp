#include "land.h"
#include "army.h"
#include "order.h"
#include <memory>
#include <sstream>

using namespace std;

MoveOrder::MoveOrder(shared_ptr<Army> army, const shared_ptr<Land> destination_arg)
: army{army} {
    if (army->get_position()->is_neighbor(destination_arg)) {
        destination = destination_arg;
    } else {
        stringstream ss;
        ss << "Failed to create MoveOrder: " 
        << army->print_position() 
        << " is not a neighbor of " 
        << destination_arg->get_name();
        throw ss.str();
    }
}

void MoveOrder::execute() {
    army.lock()->set_position(destination);
}

