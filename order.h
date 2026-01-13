#pragma once
#include <memory>
#include <string>

using namespace std;

class Army;
class Land;

class MoveOrder{
    weak_ptr<Army> army;
    shared_ptr<Land> destination;
public:
    MoveOrder(shared_ptr<Army> army, const shared_ptr<Land> destination);
    void execute();
    string print() const;
};
