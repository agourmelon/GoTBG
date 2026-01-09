#pragma once
#include <map>
#include <string>
#include <memory>

using namespace std;

class Land;

class Map {
    map<const string, shared_ptr<Land>> lands;

public:
    Map() {lands = map<const string, shared_ptr<Land>>();}
    void add_land(const shared_ptr<Land> land); 
    void make_neighbors(shared_ptr<Land> land1, shared_ptr<Land> land2); 
    shared_ptr<Land> get_land(const string& name) const {return lands.at(name);}
    string print_map();
};
