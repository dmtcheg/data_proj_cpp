#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>
#include "register_context.h"
using namespace std;



void ui(Register reg){
    char command;
    cin>>command;
    command = char(tolower(command));//todo: check
    switch (command) {
        case 'l': {
            cout << endl << "path: ";
            string path;
            cin >> path;
            cout << endl;
            reg.load(path);
        }break;
        case 'n': {
            //todo: check if emplVector exist
            cout << endl << reg.emplVector.size();
        }break;
        case 'p': {
            for (int i = 0; i < size(reg.emplVector); i++) {
                cout << endl << *(reg.emplVector[i]) << endl;
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
            for (auto e: reg.getByAge(l, u)) {
                cout << endl << *e;
            }
        }break;
        case 'x':
            return;
        default:
            cout<<"\nincorrect input\n";
    }
}


int main() {
    string path ="/home/dmitry/repos/data_proj_cpp/employees2.csv";
//    ifstream fin("/home/dmitry/repos/data_proj_cpp/employees2.csv", ios::in);
//    //fin.open("employees2.csv", ios::in);
//    auto table = readCSV(fin);
//    for (vector<string> row: table) {
//
//        Employee e(row);
//        cout<<e<<endl;
//    }
    Register reg;
    reg.load(path);
    for (int i=0;i<size(reg.emplVector);i++){
        cout<<*(reg.emplVector[i])<<endl;
    }
    return 0;
}
