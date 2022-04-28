#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>
#include "register_context.h"
using namespace std;

void print(vector<shared_ptr<Employee>> employess){
    for (auto e: employess){
        cout<<*e;
    }
}

void ui(Register reg){
    while (true) {
        char command;
        cin >> command;
        command = char(tolower(command));//todo: check
        switch (command) {
            case 'l': {
                cout << "path: ";
                string path;
                cin >> path;
                reg.load(path);
            }
                break;
            case 'n': {
                //todo: check if emplVector exist
                cout << reg.emplVector.size()<<endl;
            }
                break;
            case 'p': {
                for (int i = 0; i < size(reg.emplVector); i++) {
                    cout << *(reg.emplVector[i]) << endl;
                }
            }break;
            case 'e': {
                string name;
                cout << "name: ";
                cin >> name;
                cout << endl << *(reg.getByName(name));
            }break;
            case 'a': {
                int l, u;
                cout << "\nfrom: ";
                cin >> l;
                cout << "\nto: ";
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
                cin>>boss;
                print(reg.getDirectSubordinates(boss)); //
            }break;
            case  'i':{
                string boss;
                cout<<"boss name: ";
                cin>>boss;
                print(reg.getIndirectSubordinates(boss));
            }break;
            case 'c':{
                reg.clear();
            }break;
            case 'x':
                return;
            default:
                cout << "\nincorrect input\n";
        }
    }
}


int main() {
    Register reg;
    ui(reg);
    return 0;
}
