#include <fstream>
#include <algorithm>
#include <queue>

#include "register_context.h"
#include "utils.h"

using namespace std;

void Register::load(string path) {
    ifstream fin(path, ios::in);
    auto table = readCSV(fin);
    for (auto row: table){
        shared_ptr<Employee> ePtr(new Employee(row));
        namesIndex[ePtr->getName()] = ePtr;
        departmentIndex[ePtr->getDepartment()].push_back(ePtr);
        subordinatesIndex[ePtr->getBoss()].push_back(ePtr); // todo: possible init error?
        emplVector.push_back(move(ePtr));
    }
}

Register::~Register() {
    emplVector.clear();
    //emplVector.~vector();
}

void Register::clear() {
    emplVector.clear();
}

Register::Register(const Register& r) : emplVector(r.emplVector) {

}

Register::Register() = default;

vector<shared_ptr<Employee>> Register::getStorage() {
    return vector<shared_ptr<Employee>>();
}

shared_ptr<Employee> Register::getByName(string name) {
    return namesIndex[name]; //todo: CHECK!
}

std::vector<std::shared_ptr<Employee>> Register::getByDepartment(std::string dep) {
    return departmentIndex[dep];
}

std::set<std::shared_ptr<Employee>> Register::getByWorkingDays(std::set<std::string> days) {
    set<shared_ptr<Employee>> employees;
    for (auto e:emplVector){
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
    auto employees = getStorage();
    vector<shared_ptr<Employee>> range;
    for (auto e: employees){
        if (e->getAge() >=l && e->getAge()<=u)
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
    while (!q.empty()){
        auto empl = q.front();
        q.pop();
        auto sub = subordinatesIndex[empl->getName()];
        for (auto e: sub){
            subordinates.push_back(e);
            q.push(e);
        }
    }
    return subordinates;
}
