#include <iostream>

using namespace std;

int main() {

	int rownumb;
	

	cout << "Enter the number of rows: " << endl;
	cin >> rownumb;

	for (int i = 1; i <= rownumb; i++) {

		for (int x = 1; x <= (rownumb - i); x++) {
			cout << ".";
		}
		for (int y = 1; y <= i; y++) {
			cout << "*";
		}

		cout << endl;
	
	}

	cin.get();
	return 0;
	
}