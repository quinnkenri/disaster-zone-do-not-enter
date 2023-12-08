#include <iostream>

using namespace std;

int main() {
    const int attempts = 3;
    double times[attempts];
    double sum = 0.0;

    cout << "Enter time for your first run in seconds: ";
    cin >> times[0];
    sum += times[0];


    cout << "Enter time for run 2 in seconds: ";
    cin >> times[1];
    sum += times[1];


    cout << "Enter time for your final run in seconds: ";
    cin >> times[2];
    sum += times[2];


    double avg = sum / attempts;


    cout << "\nYour 40-yd dash times are:\n";
    cout << "Time 1: " << times[0] << " seconds\n";
    cout << "Time 2: " << times[1] << " seconds\n";
    cout << "Time 3: " << times[2] << " seconds\n";
    cout << "Average time: " << avg << " seconds\n";

    cin.get();
    return 0;
}
