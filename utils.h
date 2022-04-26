#ifndef DATA_PROJ_CPP_UTILS_H
#define DATA_PROJ_CPP_UTILS_H

#include <vector>
#include <string>

using namespace std;

vector<string> readCSVRow(const string &row);
vector<vector<string>> readCSV(istream &in);
#endif //DATA_PROJ_CPP_UTILS_H
