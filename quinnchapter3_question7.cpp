#include <iostream>

int main() {
    using namespace std;
    double liters;

    // this is actually just taking liters
    cout << "Enter the fuel economy you are getting in Liters per 100km: ";
    cin >> liters;

    // I am using more precise conversion factors than the textbook example because I prefer that
    double gpm = ((liters) / 100) * ((1 / 3.78541) / (62.1371 / 100));
    double mpg = 1 / gpm;

    cout << "Your car is getting " << mpg << " miles per gallon. " << endl;

    cin.get();
    return 0;
}