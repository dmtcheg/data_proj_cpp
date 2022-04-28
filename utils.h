#ifndef DATA_PROJ_CPP_UTILS_H
#define DATA_PROJ_CPP_UTILS_H

#include <vector>
#include <string>

std::vector<std::string> readCSVRow(const std::string &row);
std::vector<std::vector<std::string>> readCSV(std::istream &in);
#endif //DATA_PROJ_CPP_UTILS_H
