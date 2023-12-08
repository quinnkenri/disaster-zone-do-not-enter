#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstname, lastname;
    char grade;
    int age;

    cout << "What is your first name? ";
    cin >> firstname;

    cout << "What is your last name? ";
    cin >> lastname;

    cout << "What letter grade do you deserve? ";
    cin >> grade;

    cout << "What is your age? ";
    cin >> age;

    // increment grade
    grade = grade + 1;

    // Display the information
    cout << "\nName: " << lastname << ", " << firstname << endl;
    cout << "Grade: " << grade << endl;
    cout << "Age: " << age << endl;

    cin.get();
    return 0;
}
