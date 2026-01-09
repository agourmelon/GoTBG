#include "land.h"
#include <memory>


bool land_weak_ptr_compare::operator()(const weak_ptr<Land>& land1, const weak_ptr<Land>& land2) const {
    return land1.lock()->get_name() < land2.lock()->get_name();
};

void Land::share_border_with(weak_ptr<Land> land) {
    this->neighbors.insert(land);
}

set<string> Land::get_neighbors_name() const {
    set<string> neighbors_names;
    for (auto neighbor: this->neighbors) {
        neighbors_names.insert(neighbor.lock()->get_name());
    }
    return neighbors_names;
}
