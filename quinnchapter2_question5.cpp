#include <iostream>

// Program to convert Celsius to Fahrenheit
double celsiustofahrenheit(double celsius) {
    return (celsius * 1.8) + 32.0;
}

int main() {
    double celsius, fahrenheit;

    // Enter a temperature in Celsius
    std::cout << "Please enter a Celsius value: ";
    std::cin >> celsius;

    // Convert Celsius to Fahrenheit
    fahrenheit = celsiustofahrenheit(celsius);

    // Display temperature in Fahrenheit
    std::cout << celsius << " degrees Celsius is " << fahrenheit << " degrees Fahrenheit." << std::endl;

    return 0;
}

