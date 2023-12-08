#include <iostream>

// conversion factors
const double arcsec_to_min = 3600;
const double min_to_deg = 60;

int main() {
    using namespace std;
    double deg, min, sec;

    cout << "Enter a latitude in degrees, minutes, and seconds.\n First, enter the degrees: ";
    cin >> deg;

    cout << "Next, enter the minutes of arc: ";
    cin >> min;

    cout << "Finally,enter the seconds of arc: ";
    cin >> sec;

    // Do all the unit conversions
    double finaldeg = deg;
    double finalmin = min / min_to_deg;
    double finalsec = sec / arcsec_to_min;

    // Calculate BMI
    double decimalform = deg + finalmin + finalsec;

    cout << "The latitude in decimal form is " << decimalform << endl;

    cin.get();
    return 0;
}