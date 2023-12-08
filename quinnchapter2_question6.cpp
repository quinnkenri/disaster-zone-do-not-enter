#include <iostream>

// Function to convert light years (ly) to AU
double auly(double ly) {
    return (ly * 63240);
}

int main() {
    double ly, au;

    // Enter distance in light years
    std::cout << "Please enter a distance in light years: ";
    std::cin >> ly;

    // Convert distance
    au = auly(ly);

    // Display distance in AU
    std::cout << ly << " light years is " << au << " Astronomical Units." << std::endl;

    std::cin.get();
    return 0;
}
