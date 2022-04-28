#include <istream>
#include "utils.h"
using namespace std;

enum class CSVState {
    UnquotedField,
    QuotedField,
    QuotedQuote
};

vector<string> readCSVRow(const string &row) {
    CSVState state = CSVState::UnquotedField;
    vector<string> fields{""};
    size_t i = 0; // index of the current field
    for (char c: row) {
        switch (state) {
            case CSVState::UnquotedField:
                switch (c) {
                    case '\t': // end of field
                        fields.push_back("");
                        i++;
                        break;
                    case '"':
                        state = CSVState::QuotedField;
                        break;
                    default:
                        fields[i].push_back(c);
                        break;
                }
                break;
            case CSVState::QuotedField:
                switch (c) {
                    case '"':
                        state = CSVState::QuotedQuote;
                        break;
                    default:
                        fields[i].push_back(c);
                        break;
                }
                break;
            case CSVState::QuotedQuote:
                switch (c) {
                    case '\t': // , after closing quote
                        fields.push_back("");
                        i++;
                        state = CSVState::UnquotedField;
                        break;
                    case '"': // "" -> "
                        fields[i].push_back('"');
                        state = CSVState::QuotedField;
                        break;
                    default:  // end of quote
                        state = CSVState::UnquotedField;
                        break;
                }
                break;
        }
    }
    return fields;
}

/// Read CSV file, Excel dialect. Accept "quoted fields ""with quotes"""
vector<vector<string>> readCSV(istream &in) {
    vector<vector<string>> table;
    string row;
    //getline(in,row);
    while (!in.eof()) {
        getline(in, row);
        if (in.bad() || in.fail()) {
            break;
        }
        auto fields = readCSVRow(row);
        table.push_back(fields);
    }
    return table;
}
