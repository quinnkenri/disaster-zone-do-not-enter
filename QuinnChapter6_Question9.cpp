#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Donor {
    string name;
    double donation = 0;
};

int main() {
    string filename;

    cout << "Enter the name of the file: ";
    cin >> filename;

    ifstream file(filename);

    if (!file) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    int numdonors;
    file >> numdonors;

    if (numdonors <= 0) {
        cout << "No donors!" << endl;
        return 0;
    }

    Donor* donors = new Donor[numdonors];

    file.ignore();

    for (int i = 0; i < numdonors; i++) {
        getline(file, donors[i].name);
        file >> donors[i].donation;
        file.ignore();
    }

    // Display names
    cout << "\nGrand Patrons: \n";
    bool foundgrand = false;
    for (int i = 0; i < numdonors; i++) {
        if (donors[i].donation >= 10000) {
            cout << donors[i].name << ": $" << donors[i].donation << endl;
            foundgrand = true;
        }
    }

    if (!foundgrand) {
        cout << "No donors at this tier." << endl;
    }

    cout << "\nPatrons: \n";
    bool foundpatrons = false;
    for (int i = 0; i < numdonors; i++) {
        if (donors[i].donation < 10000) {
            cout << donors[i].name << ": $" << donors[i].donation << endl;
            foundpatrons = true;
        }
    }

    if (!foundpatrons) {
        cout << "No donors at this tier." << endl;
    }

    delete[] donors;

    cin.get();
    return 0;
}
