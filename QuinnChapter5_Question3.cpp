#include <iostream>
using namespace std;

int main() {
    int num;
    int sum = 0;

    cout << "Enter some numbers that aren't zero:\n";

    while (cin >> num && num != 0) {
        sum += num;
        cout << "Cumulative sum: " << sum << endl;
    }

    cout << "You entered zero, the program has terminated." << endl;

    return 0;
}
