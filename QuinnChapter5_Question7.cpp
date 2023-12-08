#include <iostream>
#include <string>

using namespace std;

struct car {
    string make;
    int year = 0;
};

int main() {

    int carnumb;

    cout << "How many cars will you catalogue? ";
    cin >> carnumb;

    car* carArr = new car[carnumb];

    for (int i = 0; i < carnumb; i++) {

        cin.ignore();
        cout << "Make and Model of car " << (i + 1) << ": ";
        getline(cin, carArr[i].make);
        cout << "Year of car " << (i + 1) << ": ";
        cin >> carArr[i].year;
    }

    cout << "\n\n---------------\n\nYour Car Collection: " << endl; // horizontal line for clarity
    for (int i = 0; i < carnumb; i++) {

        cout << "Car " << (i + 1) << "\n Year: " << carArr[i].year << "\n Model: " << carArr[i].make << endl;


    }

    delete[]carArr;

    cin.get();
    return 0;
}