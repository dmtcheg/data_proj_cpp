#include <iostream>
#include <fstream>
#include <vector>
#include "register_context.h"
using namespace std;

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
