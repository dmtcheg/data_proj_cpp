#include <fstream>
#include <algorithm>
#include <queue>

#include "register_context.h"
#include "utils.h"

using namespace std;

void Register::load(string path) {
    ifstream fin(path, ios::in);
    auto table = readCSV(fin);
    for (auto row: table) {
        shared_ptr<Employee> ePtr(new Employee(row));
        namesIndex[ePtr->getName()] = ePtr;
        departmentIndex[ePtr->getDepartment()].push_back(ePtr);
        subordinatesIndex[ePtr->getBoss()].push_back(ePtr);
        emplVector.push_back(move(ePtr));
    }
}

Register::~Register() {
    emplVector.clear();
}

void Register::clear() {
    emplVector.clear();
}

Register::Register(const Register &other) : emplVector(), namesIndex() {
    copy(other.emplVector.begin(), other.emplVector.end(), back_inserter(emplVector));
    namesIndex = other.namesIndex;
    subordinatesIndex = other.subordinatesIndex;
    departmentIndex = other.departmentIndex;
}

Register &Register::operator=(const Register &other) {
    if (this != &other) {
        emplVector.~vector();
        copy(other.emplVector.begin(), other.emplVector.end(), back_inserter(emplVector));
        namesIndex = other.namesIndex;
        subordinatesIndex = other.subordinatesIndex;
        departmentIndex = other.departmentIndex;
    }
    return *this;
}

Register::Register() = default;

const std::vector<std::shared_ptr<Employee>> Register::getStorage() const {
    return emplVector;
}

shared_ptr<Employee> Register::getByName(string name) {
    return namesIndex[name];
}

std::vector<std::shared_ptr<Employee>> Register::getByDepartment(std::string dep) {
    return departmentIndex[dep];
}

std::set<std::shared_ptr<Employee>> Register::getByWorkingDays(std::set<std::string> days) {
    set<shared_ptr<Employee>> employees;
    for (auto e: emplVector) {
        auto schedule = e->getSchedule();
        vector<string> intersection;
        set_intersection(schedule.begin(), schedule.end(),
                         days.begin(), days.end(),
                         back_inserter(intersection));
        if (!intersection.empty())
            employees.insert(e);
    }
    return employees;
}

std::vector<std::shared_ptr<Employee>> Register::getByAge(int l, int u) {
    auto employees = emplVector;
    vector<shared_ptr<Employee>> range;
    for (auto e: employees) {
        if (e->getAge() >= l && e->getAge() <= u)
            range.push_back(e);
    }
    return range;
}

std::vector<std::shared_ptr<Employee>> Register::getDirectSubordinates(std::string emplName) {
    return subordinatesIndex[emplName];
}

std::vector<std::shared_ptr<Employee>> Register::getIndirectSubordinates(std::string emplName) {
    auto boss = getByName(emplName);
    vector<shared_ptr<Employee>> subordinates;
    queue<shared_ptr<Employee>> q;
    q.push(getByName(emplName));
    while (!q.empty()) {
        auto empl = q.front();
        q.pop();
        auto sub = subordinatesIndex[empl->getName()];
        for (auto e: sub) {
            subordinates.push_back(e);
            q.push(e);
        }
    }
    return subordinates;
}
