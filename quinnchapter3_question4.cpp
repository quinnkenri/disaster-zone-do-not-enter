#include <iostream>

// constants
const long  sec_per_year = 31536000;
const long  sec_per_day = 86400;
const long  sec_per_hour = 3600;
const long  sec_per_minute = 60;

int main() {
    using namespace std;
    long sec;

    cout << "Enter an amount of time in seconds: ";
    cin >> sec;


    // Do all the unit conversions. This is a mathematical mess but it works
    long timeyears = sec / sec_per_year;
    long timedays = (sec % sec_per_year) / sec_per_day;
    long timehours = ((sec % sec_per_year) % sec_per_day) / sec_per_hour;
    long timeminutes = (((sec % sec_per_year) % sec_per_day) % sec_per_hour) / sec_per_minute;
    long secremainder = (((sec % sec_per_year) % sec_per_day) % sec_per_hour) % sec_per_minute;


    cout << "The time is: " << timeyears << " year, " << timedays << " days, " << timehours << " hours, " << timeminutes << " minutes, " << secremainder << " seconds. " << endl;

    cin.get();
    return 0;
}