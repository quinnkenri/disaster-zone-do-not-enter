#include <iostream>
#include <string>

using namespace std;

struct Donor {
    string name;
    double donation = 0;
};

int main() {
    int numdonors;

    cout << "Enter the number of contributors: ";
    cin >> numdonors;

    if (numdonors <= 0) {
        cout << "No donors! " << endl;
        return 0;
    }

    Donor* donors = new Donor[numdonors];

    for (int i = 0; i < numdonors; i++) {
        cin.ignore();
        cout << "Enter the name of donor " << i + 1 << ": ";
        getline(cin, donors[i].name);
        cout << "Enter the donation amount for " << donors[i].name << ": ";
        cin >> donors[i].donation;
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