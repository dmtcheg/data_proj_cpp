#include <iostream>
#include <fstream>
#include <vector>
#include "employee.h"
#include "utils.h"
using namespace std;

int main() {
    ifstream fin;
    fin.open("employees2.csv", ios::in);
    auto table = readCSV(fin);
    for (vector<string> row: table) {
        std::string ret;
        for(const auto &s : row) {
            ret += s;
        }
        cout<<ret<<endl;
        Employee e(ret);
        cout<<e;
    }
    return 0;
}
