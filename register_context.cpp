#include <fstream>

#include "register_context.h"
#include "utils.h"

using namespace std;

void Register::load(string path) {
    ifstream fin(path, ios::in);
    auto table = readCSV(fin);
    for (auto row: table){
        unique_ptr<Employee> ePtr(new Employee(row));
        emplVector.push_back(move(ePtr));
    }
}

vector<unique_ptr<Employee>> Register::getStorage() {
    return vector<unique_ptr<Employee>>();
}

unique_ptr<Employee> Register::getByName(string name) {
    return move(namesIndex[name]); //todo: CHECK!
}

std::vector<std::unique_ptr<Employee>> Register::getByDepartment(std::string dep) {
    return move(departmentIndex[dep]);
}
