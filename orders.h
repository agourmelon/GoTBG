#pragma once
#include "land.h"
#include "army.h"

void move(Army& army, Land_sptr destination) {
    army.set_position(destination);
}
