#include <iostream>

int main() {
    using namespace std;
    double miles;
    double gallons;

    cout << "Enter the distance you have driven, in miles: ";
    cin >> miles;

    cout << "Enter the amount of fuel you have used, in gallons: ";
    cin >> gallons;

    double mpg = miles / gallons;

    cout << "Your car is getting " << mpg << " miles per gallon. " << endl;

    cin.get();
    return 0;
}