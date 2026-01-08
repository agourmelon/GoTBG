#pragma once
#include <string>
#include <set>
#include <memory>

using namespace std;

enum class StrongHold;

class Land;

struct land_weak_ptr_compare {
    bool operator()(const weak_ptr<Land>& land1, const weak_ptr<Land>& land2) const;
};

class Land {
    string name;
    int influence;
    int supply;
    StrongHold facility;
    set<weak_ptr<Land>, land_weak_ptr_compare> neighbors;

public:
    Land(std::string name, int influence, int supply, StrongHold facility): 
        name{name}, influence{influence}, supply{supply}, facility{facility} {}

    std::string get_name() const {return this->name;}
    void share_border_with(weak_ptr<Land> land); 
    set<string> get_neighbors_name() const; 
};
