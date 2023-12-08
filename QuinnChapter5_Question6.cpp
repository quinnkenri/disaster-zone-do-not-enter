#include <iostream>
using namespace std;

int main() {
    string months[] = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    int sales[3][12];

    for (int year = 0; year < 3; year++) {
        cout << "Enter sales data for year " << (year + 1) << ":" << endl;

        for (int monthsnumb = 0; monthsnumb < 12; monthsnumb++) {
            cout << months[monthsnumb] << ":" << endl;
                cin >> sales[year][monthsnumb];
        }
    }

    int fulltotal = 0;
    cout << "\n\n----------------------\n\nC++ For Fools Annual Sales Data:\n " << endl; // lines for clarity

    for (int year = 0; year < 3; year++) {
        cout << "Year " << (year + 1) << ":" << endl;
        int annualsoldbooks = 0;
        for (int monthsnumb = 0; monthsnumb < 12; monthsnumb++) {
            int soldbooks = sales[year][monthsnumb];
            annualsoldbooks += soldbooks;
        }
        cout << "Total Sales are " << annualsoldbooks << " books sold." << endl;
        fulltotal += annualsoldbooks;
        cout << endl;
    }

    cout << "Total Sales of C++ For Fools Across All Years : " << fulltotal << " books." << endl;
    cin.get();
    return 0;
}