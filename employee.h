#ifndef DATA_PROJ_CPP_EMPLOYEE_H
#define DATA_PROJ_CPP_EMPLOYEE_H

#include <vector>
#include <string>

using namespace std;

class Employee{
private:
    string name;
    int age;
    string department;
    string position;
    string boss_name;
    vector<string> working_days;

public:
    Employee(string line);
    friend ostream& operator<<(ostream &os, const Employee &e);
};
#endif //DATA_PROJ_CPP_EMPLOYEE_H
