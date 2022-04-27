#ifndef DATA_PROJ_CPP_EMPLOYEE_H
#define DATA_PROJ_CPP_EMPLOYEE_H

#include <vector>
#include <string>

class Employee{
private:
    std::string name;
    int age;
    std::string department;
    std::string position;
    std::string boss_name;
    std::vector<std::string> working_days;

public:
    Employee(std::vector<std::string> fields);
    friend std::ostream& operator<<(std::ostream &os, const Employee &e);
};
#endif //DATA_PROJ_CPP_EMPLOYEE_H
