#pragma once
#include <map>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

class Land;

class Map {
    map<const string, shared_ptr<Land>> lands;

public:
    Map() {lands = map<const string, shared_ptr<Land>>();}
    void add_land(const shared_ptr<Land> land); 
    void make_neighbors(shared_ptr<Land> land1, shared_ptr<Land> land2); 
    shared_ptr<Land> get_land(const string& name) const {return lands.at(name);}
    string print();
    const vector<string> get_lands_names() const {
        vector<string> names;
        for_each(
            lands.begin(), lands.end(), [&names](auto& name_land_pair) {
                names.push_back(name_land_pair.first);
            }
        );
        return names;
    }
    bool contains(const string& name) const {return lands.contains(name);}
};
