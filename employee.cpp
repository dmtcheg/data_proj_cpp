#include "employee.h"
#include <string>
#include <vector>
#include "utils.cpp"

using namespace std;

class Employee {
public:
    Employee(string line) {
        auto fields = readCSVRow(line);
        name = fields[0];
        age = stoi(fields[1]);
        department = fields[2];
        position = fields[3];
        boss_name = fields[4];
        for (int i = 5; i < size(fields); ++i) {
            working_days.push_back(fields[i]);
        }
    }

    static Employee *make_employee(string line) {

    }

    friend ostream &operator<<(ostream &os, const Employee &e);

private:
    string name;
    int age;
    string department;
    string position;
    string boss_name;
    vector<string> working_days;
};

ostream &operator<<(ostream &os, const Employee &e) {
    os << "Name: " << e.name << ", age" << e.age << ", department: " << e.department << ", boss: " << e.boss_name;
    return os;
}
