#include <iostream>
#include <string>

using namespace std;

struct CandyBar {
    string brandname;
    double weight;
    int calories;
};

int main() {
    CandyBar candybar1 = { "Caramilk", 1.7, 280 };
    CandyBar candybar2 = { "Kit Kat", 1.2, 210 };
    CandyBar candybar3 = { "Quinn's Quacky Bar", 5.0, 50 };


    cout << "Brand Name: " << candybar1.brandname << endl;
    cout << "Weight: " << candybar1.weight << " grams" << endl;
    cout << "Calories: " << candybar1.calories << "\n" << endl;

    cout << "Brand Name: " << candybar2.brandname << endl;
    cout << "Weight: " << candybar2.weight << " grams" << endl;
    cout << "Calories: " << candybar2.calories << "\n" << endl;

    cout << "Brand Name: " << candybar3.brandname << endl;
    cout << "Weight: " << candybar3.weight << " grams" << endl;
    cout << "Calories: " << candybar3.calories << "\n" << endl;

    cin.get();
    return 0;
}