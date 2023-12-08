#include <iostream>
using namespace std;

int main() {
    double dmoney = 100;
    double cmoney = 100;
    int years = 0;

    while (cmoney <= dmoney) {
        dmoney += 10;
        cmoney += 0.05 * cmoney;
        years++;
    }

    cout << "After " << years << " years, " << endl;
    cout << "The investment of Cleo is worth $" << cmoney << " which overtakes the investment of Daphne at $" << dmoney << endl;

    cin.get();
    return 0;

}