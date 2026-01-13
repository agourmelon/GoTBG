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
class Army;

struct land_weak_ptr_compare {
    bool operator()(const weak_ptr<Land>& land1, const weak_ptr<Land>& land2) const;
};

class Land {
    string name;
    int influence;
    int supply;
    StrongHold facility;
    set<weak_ptr<Land>, land_weak_ptr_compare> neighbors;
    weak_ptr<Army> army;

public:
    Land(std::string name, int influence, int supply, StrongHold facility): 
        name{name}, influence{influence}, supply{supply}, facility{facility} {}

    const std::string& get_name() const {return name;}
    bool is_neighbor(const shared_ptr<Land> land) const {return this->neighbors.contains(land);}
    void share_border_with(weak_ptr<Land> land); 
    set<string> get_neighbors_name() const;
    string print_neighbors() const {
        ostringstream ss;
        auto neighbors_names = get_neighbors_name();
        copy(neighbors_names.begin(), neighbors_names.end(), ostream_iterator<string>(ss, ", "));
        return ss.str();
    }

    bool has_army() const {return !army.expired();}
    void set_army(weak_ptr<Army> incoming_army) {this->army = incoming_army;}
    shared_ptr<Army> get_army() const {return army.lock();}
};

using Land_sptr = shared_ptr<Land>;

inline Land_sptr make_land_ref(string name, int influence, int supply, StrongHold facility) {
    return make_shared<Land>(name, influence, supply, facility);
}
