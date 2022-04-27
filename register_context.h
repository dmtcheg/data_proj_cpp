#ifndef DATA_PROJ_CPP_REGISTER_CONTEXT_H
#define DATA_PROJ_CPP_REGISTER_CONTEXT_H
#include "employee.h"
#include <memory>
#include <map>

class Register {
private:
    std::map<std::string, std::unique_ptr<Employee>> namesIndex; //names are unique, see task description
    std::map<std::string, std::vector<std::unique_ptr<Employee>>> departmentIndex;
    std::map<std::string, std::vector<std::unique_ptr<Employee>>> subordinatesIndex; // todo: direct and indirect (recursive)
public:
    std::vector<std::unique_ptr<Employee>> emplVector;
    void load(std::string path);
    std::vector<std::unique_ptr<Employee>> getStorage(); //todo: make sure that this collection is protected from changing and also you have to avoid copying it
    std::unique_ptr<Employee> getByName(std::string name);
    std::vector<std::unique_ptr<Employee>> getByDepartment(std::string dep);

};

#endif //DATA_PROJ_CPP_REGISTER_CONTEXT_H
