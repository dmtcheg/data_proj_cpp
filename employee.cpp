#include "employee.h"

using namespace std;

Employee::Employee(vector<string> fields) {
    //auto fields = readCSVRow(line);
    name = fields[0];
    age = stoi(fields[1]);
    department = fields[2];
    position = fields[3];
    boss_name = fields[4];
    for (int i = 5; i < size(fields); ++i) {
        working_days.push_back(fields[i]);
    }
}

ostream &operator<<(ostream &os, const Employee &e) {
    os << ("Name: "+ e.name + ", age " + to_string(e.age) + ", department: " + e.department + ", boss: " + e.boss_name);
    return os;
}

std::string Employee::getName() {
    return name;
}

std::string Employee::getDepartment() {
    return department;
}

std::string Employee::getBoss() {
    return boss_name;
}

std::vector<std::string> Employee::getSchedule() {
    return working_days;
}

int Employee::getAge() {
    return age;
}
//static Employee *make_employee(string line) {   }
