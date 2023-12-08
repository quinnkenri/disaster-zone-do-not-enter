#include <iostream>
#include <string>

using namespace std;
int main()
{
	string word;
	int total = 0;

	cout << "Enter some words (enter done to end program): " << endl;

	for (;;) {

		cin >> word;

		if (word == "done") {
			break;
		}
		else {
			total++;
		}
	}

	cout << "You entered " << total << " words." << endl;
	
	cin.get();
	return 0;
}