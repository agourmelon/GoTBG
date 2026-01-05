#pragma once
#include <string>
enum class StrongHold;

class Land {
    std::string name;
    int influence;
    int supply;
    StrongHold facility;
public:
    Land(std::string name, int influence, int supply, StrongHold facility): 
        name{name}, influence{influence}, supply{supply}, facility{facility} {}

    std::string get_name() const {return this->name;}
};
