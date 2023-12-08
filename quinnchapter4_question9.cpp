#include <iostream>
#include <string>

using namespace std;

struct CandyBar {
    string brandname;
    double weight;
    int calories;
};

int main() {
    CandyBar* candybars = new CandyBar[3];

    candybars[0] = { "Caramilk", 1.7, 280 };
    candybars[1] = { "Kit Kat", 1.2, 210 };
    candybars[2] = { "Quinn's Quacky Bar", 5.0, 50 };


    cout << "Brand Name: " << candybars[0].brandname << endl;
    cout << "Weight: " << candybars[0].weight << " grams" << endl;
    cout << "Calories: " << candybars[0].calories << "\n" << endl;

    cout << "Brand Name: " << candybars[1].brandname << endl;
    cout << "Weight: " << candybars[1].weight << " grams" << endl;
    cout << "Calories: " << candybars[1].calories << "\n" << endl;

    cout << "Brand Name: " << candybars[2].brandname << endl;
    cout << "Weight: " << candybars[2].weight << " grams" << endl;
    cout << "Calories: " << candybars[2].calories << "\n" << endl;

    delete[] candybars;

    cin.get();
    return 0;
}