#include <iostream>
#include <cctype>

using namespace std;

int main() {

	const int i = 10;
	double donations[i] = {};
	double sum = 0.0;
	int count = 0;
	int count2 = 0;

	cout << "Enter donation values (maximum 10 values): " << endl;
	
	while (count < i && cin >> donations[count]) {

		sum += donations[count];
		count++;
	}

	double average = (sum / count);

	cout << "Average donation amount: " << average << endl;

	int j = 0;

	for (j = 0; j < count; j++) {


		if (donations[j] > average) {

			count2++;

		}		

	}

	cout << "Numbers above the average: " << count2 << endl;

	cin.get();
	return 0;

}