#include <iostream>

// constants
const long long worldpopulation = 8045311447;
const long long uspopulation = 331900000;

int main() {
    using namespace std;

    // Do the math
    double pctamerica = static_cast<double>(uspopulation) / worldpopulation;


    cout << "The US contains " << pctamerica * 100 << " percent of the global population. " << endl;

    cin.get();
    return 0;
}