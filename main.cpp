#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>
#include "register_context.h"
using namespace std;

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
            }
                break;
            case 'e': {
                string name;
                cout << "name: ";
                cin >> name;
                cout << endl << *(reg.getByName(name));
            }
                break;
            case 'a': {
                int l, u;
                cout << "\nfrom: ";
                cin >> l;
                cout << "\nto: ";
                cin >> u;
                for (auto e: reg.getByAge(l, u)) {
                    cout << endl << *e;
                }
            }
                break;
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
