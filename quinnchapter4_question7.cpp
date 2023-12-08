#include <iostream>
#include <string>

using namespace std;

struct pizzadetails {
    string name;
    double diameter;
    double weight;
};


int main() {
    pizzadetails pizzatime;

    cout << "Please input the pizzeria name: " << endl;
    getline(cin, pizzatime.name);

    cout << "Input the pizza diameter in inches: " << endl;
    cin >> pizzatime.diameter;

    cout << "Input the pizza weight in ounces: " << endl;
    cin >> pizzatime.weight;

    cout << "Pizza Time! The details of your pizza: " << endl;
    cout << "Pizzeria: " << pizzatime.name << endl;
    cout << "Diameter: " << pizzatime.diameter << " inches" << endl;
    cout << "Weight: " << pizzatime.weight << " ounces" << endl;

    cin.get();
    return 0;
}