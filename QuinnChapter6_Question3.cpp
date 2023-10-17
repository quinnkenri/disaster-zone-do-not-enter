#include <iostream>
using namespace std;
int main()
{
	char choice;
	while (true) {

		cout << "------------------------\n\nFun Fact Program Menu Options: " << endl;
		cout << "A. Airplane fact. " << endl;
		cout << "B. Basketball fact. " << endl;
		cout << "C. Canada fact. " << endl;
		cout << "D. Dolphin fact. " << endl;

		cout << "Enter your choice now (use a capital letter): " << endl;
		cin >> choice;


		if (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D') {
			cout << "\n\nInvalid choice. Pick a valid option.\n " << endl;
			continue;
		}

		switch (choice)
		{
		case 'A': cout << "\nThe fastest electric aicraft is the 'Spirit of Innovation', which can fly at 622 km/h.\n" << endl;
			break;
		case 'B': cout << "\nIn 1987, the tallest-ever and shortest-ever NBA players were on the same team at the same time.\n" << endl;
			break;
		case 'C': cout << "\nThe tallest mountain in Canada is Mount Logan at 19,551 feet high.\n" << endl;
			break;
		case 'D': cout << "\nThe Amazon River is home to freshwater dolphins not found anywhere else.\n" << endl;
			break;
		default: cout << "That's not a choice.\n" << endl;
		}
		cout << "\nPress any key to continue and see another fact. " << endl;
		cin >> choice;
	}
	return 0;
}