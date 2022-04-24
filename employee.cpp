#include "employee.h"
#include <string>
#include <vector>

using namespace std;

class Employee {
public:
    Employee(string line){

    }
private:
    string name;
    int age;
    string department;
    string position;
    string boss_name;
    vector<string> working_days;
};
