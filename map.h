#pragma once
#include <map>
#include <string>

using namespace std;

class Land;

class Map {
    map<string, Land*> lands;

public:
    Map() {lands = map<string, Land*>();}
    void add_land(const Land* land); 
    void make_neighbors(Land* land1, Land* land2); 
    string print_map();
};
