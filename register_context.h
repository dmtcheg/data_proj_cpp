#ifndef DATA_PROJ_CPP_REGISTER_CONTEXT_H
#define DATA_PROJ_CPP_REGISTER_CONTEXT_H
#include "employee.h"
#include <memory>
#include <map>
#include <set>

class Register {
private:
    std::map<std::string, std::shared_ptr<Employee>> namesIndex;
    std::map<std::string, std::vector<std::shared_ptr<Employee>>> departmentIndex;
    std::map<std::string, std::vector<std::shared_ptr<Employee>>> subordinatesIndex;
public:
    std::vector<std::shared_ptr<Employee>> emplVector;
    Register();
    ~Register();
    Register(const Register&);
    Register& operator=(const Register& r);

    void load(std::string path);
    void clear();
    const std::vector<std::shared_ptr<Employee>> getStorage() const;
    std::vector<std::shared_ptr<Employee>> getByAge(int l, int u);
    std::shared_ptr<Employee> getByName(std::string name);
    std::vector<std::shared_ptr<Employee>> getByDepartment(std::string dep);
    std::set<std::shared_ptr<Employee>> getByWorkingDays(std::set<std::string>);
    std::vector<std::shared_ptr<Employee>> getDirectSubordinates(std::string emplName);
    std::vector<std::shared_ptr<Employee>> getIndirectSubordinates(std::string emplName);
};

#endif //DATA_PROJ_CPP_REGISTER_CONTEXT_H
