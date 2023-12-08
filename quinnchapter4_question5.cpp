#include <iostream>
#include <string>

using namespace std;

struct CandyBar {
    string brandname;
    double weight;
    int calories;
};

int main() {

    CandyBar snack = { "Mocha Munch", 2.3, 350 };
    cout << "Brand Name: " << snack.brandname << endl;
    cout << "Weight: " << snack.weight << " grams" << endl;
    cout << "Calories: " << snack.calories << endl;

    cin.get();
    return 0;
}