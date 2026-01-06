#pragma once
#include <string>
#include <set>

using namespace std;

enum class StrongHold;

class Land {
    string name;
    int influence;
    int supply;
    StrongHold facility;
    set<Land*> neighbors;

public:
    Land(std::string name, int influence, int supply, StrongHold facility): 
        name{name}, influence{influence}, supply{supply}, facility{facility} {}

    std::string get_name() const {return this->name;}
    void share_border_with(Land* land) {
        auto [_, is_new] = this->neighbors.insert(land);
        if (is_new) {
            land->share_border_with(this);
        }
    }
    set<string> get_neighbors_name() const {
        set<string> neighbors_names;
        for (auto neighbor: this->neighbors) {
            neighbors_names.insert(neighbor->get_name());
        }
        return neighbors_names;
    }
};
