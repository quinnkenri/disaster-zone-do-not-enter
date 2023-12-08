#include <iostream>

const int inchesperfoot = 12;

int main() {
    using namespace std;

    int heightInInches;

    cout << "Enter your height in inches:___\b\b\b";
    cin >> heightInInches;

    int feet = heightInInches / inchesperfoot;
    int inches = heightInInches % inchesperfoot;

    cout << "Your height is " << feet << " feet and " << inches << " inches." << endl;

    cin.get();
    return 0;
}


