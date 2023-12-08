#include <iostream>

const double in_per_ft = 12.0;
const double lbs_per_kg = 2.2;
const double m_per_in = 0.0254;

int main() {
    using namespace std;
    double heightFt, heightIn, weightLbs;

    cout << "Enter your height in feet: ";
    cin >> heightFt;

    cout << "Enter your height in inches: ";
    cin >> heightIn;

    cout << "Enter your weight in pounds: ";
    cin >> weightLbs;

    // Do all the unit conversions
    double totalheightIn = (heightFt * in_per_ft) + heightIn;
    double heightMeters = totalheightIn * m_per_in;
    double weightKg = weightLbs / lbs_per_kg;

    // Calculate BMI
    double bmi = weightKg / (heightMeters * heightMeters);

    cout << "Your BMI is: " << bmi << endl;

    cin.get();
    return 0;
}