#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <limits>
#include <vector>

using namespace std;

// DEFINITION
struct items {
    int ID;
    string name;
    string desc;
    string price;
    string pcs;
};

vector <items> a;

void step1() {

    string namefile, line;

    cout << "Name of the file:" << endl;
    cin >> namefile;

    ifstream file;

    file.open(namefile.c_str());

    if( !file.is_open()) {

        cout << "File "<< namefile <<" not found." << endl;
        exit(-1);

    }

    for (items i;
        (file >> i.ID).ignore(numeric_limits<streamsize>::max(), ',')
        && getline(file, i.name, ',')
        && getline(file, i.desc, ',')
        && getline(file, i.price, ',')
        && getline(file, i.pcs); ) {
        a.push_back(i);
    }
    cout << a.at(1).name << endl;

    for (vector<items>::iterator it = a.begin(); it != a.end(); ++it) {
        cout << "Elemento Nº" << (a.size() - (a.end() - it)) << ":" << endl
            << "\tID: " << (*it).ID << endl
            << "\tDesctipción: " << (*it).desc << endl
            << "\tPrecio: " << (*it).price << endl
            << "\tCantidad: " << (*it).pcs << endl;
    }

    file.close();
}

int main(){
step1();
return 0;
}
