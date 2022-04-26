#ifndef DATA_PROJ_CPP_REGISTER_CONTEXT_H
#define DATA_PROJ_CPP_REGISTER_CONTEXT_H
#include "employee.h"

class Register {
private:
    vector<Employee*> EmplVector;
public:
    void load(string path);

};

#endif //DATA_PROJ_CPP_REGISTER_CONTEXT_H
