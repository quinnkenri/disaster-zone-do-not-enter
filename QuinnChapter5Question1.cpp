#include <iostream>
using namespace std;

int main()
{
    int x;
    int y;

    int summation = 0;
    cout << "Hello! This program will output the sum of all the numbers between two inputs.\n";
    cout << "You must input a smaller number followed by a larger number.\n\n";
    cout << "Input a number: ";
    cin >> x;

    cout << "Input a larger number: ";
    cin >> y;

    int sumthing = x;
    while (sumthing <= y) {

        summation += sumthing;
        ++sumthing;
    }

    cout << "The sum of the numbers in between " << x << " and " << y << " is " << summation << endl;
    cin.get();
    return 0;
}