#pragma once
#include <string>
#include <set>
#include <memory>
#include <sstream>
#include <algorithm>
#include <iterator>

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
    string print_neighbors() const {
        ostringstream ss;
        auto neighbors_names = get_neighbors_name();
        copy(neighbors_names.begin(), neighbors_names.end(), ostream_iterator<string>(ss, ", "));
        return ss.str();
    }
};

using Land_sptr = shared_ptr<Land>;

inline Land_sptr make_land_ref(string name, int influence, int supply, StrongHold facility) {
    return make_shared<Land>(name, influence, supply, facility);
}
