#include <iostream>
#include <cctype>

using namespace std;

int main() {

	long income;
	double totaltax = 0.0;
	double tax;

	cout << "~~~~ Kingdom of Neutronia Tax Calculator ~~~~" << endl;
	cout << "__--__--__--__--__--__--__--__--__--__--__--__--" << endl;
	cout << "--__--__--__--__--__--__--__--__--__--__--__--__\n\n" << endl;

	cout << "Enter your income in tvarps: " << endl;

	while (true) {

		if (!(cin >> income)) {
			cout << "Invalid input. Enter something else." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue; // checks for a number
		}

		if (income < 0) {
			break;
		} // ends program if negative value

		if (income <= 5000) {
			tax = 0;
		}

		else if (income <= 15000) {
			tax = (0 + (income - 5000) * 0.10);
		}
		else if (income <= 35000) {
			tax = (0 + (10000 * 0.10) + (income - 15000) * 0.15);
		}
		else {
			tax = (0 + (10000 * 0.10) + (20000 * 0.15) + (income - 35000) * 0.20);
		}
		

		totaltax += tax;

		cout << "Tax owed: " << totaltax << " tvarps." << endl;
	}

	
return 0;


}
