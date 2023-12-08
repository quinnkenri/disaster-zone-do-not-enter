#include <iostream>
using namespace std;

const int months1 = 12;

int main() {
    string months2[months1] = { "January ", "February ", "March ", "April ", "May ", "June ", "July ", "August ", "September ", "October ", "November ", "December " };
    int sales[months1];
    int total = 0;

    cout << "Enter monthly sales for the book: " << endl;

    for (int i = 0; i < months1; i++) {

        cout << months2[i];
        cin >> sales[i];
    }

    for (int i = 0; i < months1; i++) {

        total += sales[i];
    }

    cout << "Total sales of C++ For Fools for the year: " << total << endl;

    cin.get();
    return 0;
}