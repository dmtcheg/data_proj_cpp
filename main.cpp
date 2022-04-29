#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>
#include "register_context.h"
using namespace std;

void print(vector<shared_ptr<Employee>> employess){
    for (auto e: employess){
        cout<<*e<<endl;
    }
}

void ui(Register reg){
    while (true) {
        char command;
        cin >> command;
        command = char(tolower(command));
        switch (command) {
            case 'l': {
                cout << "path: ";
                string path;
                cin >> path;
                reg.load(path);
            }
                break;
            case 'n': {
                cout << reg.getStorage().size()<<endl;
            }
                break;
            case 'p': {
                for (int i = 0; i < size(reg.getStorage()); i++) {
                    cout << *(reg.getStorage()[i]) << endl;
                }
            }break;
            case 'e': {
                string name;
                cout << "name: ";
                cin >> name;
                auto e = reg.getByName(name);
                if (e.get() != NULL){
                    cout << endl << *e;
                }else{
                    cout<<"employee not found";
                }
            }break;
            case 'a': {
                int l, u;
                cout << "from: ";
                cin >> l;
                cout << "to: ";
                cin >> u;
                print(reg.getByAge(l, u));
            }break;
            case 's':{
                set<string> sc;
                cout<<"working days (3 letters format, q to end): "<<endl;
                string day;
                cin>>day;
                while (day != "q" && sc.size()<7){
                    sc.insert(day);
                    cin>>day;
                }
                for (auto e: reg.getByWorkingDays(sc)){
                    cout<<*e;
                }
            }break;
            case 'd':{
                string dep;
                cout<<"department: ";
                cin>>dep;
                print(reg.getByDepartment(dep));
            }break;
            case 'b':{
                string boss;
                cout<<"boss name: ";
                while (boss.length()==0)
                    getline(cin, boss);
                print(reg.getDirectSubordinates(boss)); //
            }break;
            case 'i':{
                string boss;
                cout<<"boss name: ";
                while (boss.length()==0)
                    getline(cin, boss);
                print(reg.getIndirectSubordinates(boss));
            }break;
            case 'c':{
                reg.clear();
            }break;
            case 'x':
                return;
            default:
                cout << "incorrect input";
        }
    }
}

int main() {
    string info = "Employee database\n"
                  "=================\n"
                  "(l) Load a file\n"
                  "(c) Clear a dataset\n"
                  "(n) Print number of records in a dataset\n"
                  "(p) Print all records\n"
                  "(e) Print an employee by their name\n"
                  "(a) Print all employees with an age in a given range\n"
                  "(s) Print all employees with working day in set \n"
                  "(d) Print an employee by department\n"
                  "(b) Print an direct subordinates of employee\n"
                  "(i) Print an indirect subordinates of employee\n"
                  "(x) Exit\n"
                  "Choose an action: _\n";
    cout<<info;
    Register reg;
    ui(reg);
    return 0;
}
