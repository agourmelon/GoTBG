#pragma once
#include "land.h"
#include "army.h"

void move(Army& army, Land& destination) {
    army.set_position(destination);
}
