#include <iostream>

void displayTime(int hour, int minute) {
    std::cout << "Time: " << hour << ":" << minute;
}

int main() {
    int hour, minute;

    // Enter hour and minute values here
    std::cout << "Enter the number of hours: ";
    std::cin >> hour;

    std::cout << "Enter the number of minutes: ";
    std::cin >> minute;

    // Display time. Note that this program does not properly display time between minute 0 and 9...
    displayTime(hour, minute);
    std::cin.get();
    return 0;
}

