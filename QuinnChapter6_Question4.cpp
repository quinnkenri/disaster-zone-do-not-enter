#include <iostream>

using namespace std;
const int strsize = 50;
const int maxmemb = 5;

struct bop {
	char fullname[strsize]; // real name
	char title[strsize]; // job title
	char bopname[strsize]; // secret BOP name
	int preference; // 0 = fullname, 1 = title, 2 = bopname
};

int main() {

	bop members[maxmemb]{
		{"Tim Tom", "Software Engineer", "CodeWizard", 0},
		{"Jeff Bezos", "Junior Software Engineer", "HackerMan3000", 1},
		{"Quinn Lawson", "CEO", "Quinny", 2},
		{"Quint Larsson", "COO", "Not Quinn", 1},
		{"Mark Zuckerberg", "Privacy Consultant", "The Zucc", 0}
	};

	char choice;
	cout << "Benevolent Order of Programmers (BOP) Members List" << endl;
	cout << "\n-_-_-_-_-_-_-_-_-_-_-_\n" << endl;
	cout << "a. Display by name\n" << endl;
	cout << "b. Display by job title\n" << endl;
	cout << "c. Display by secret BOP name\n" << endl;
	cout << "d. Display by preference\n" << endl;
	cout << "q. Quit program\n" << endl;

	while (true) {

		cout << "\nEnter your choice: ";
		cin >> choice;
		cin.get();

		switch (choice) {

		case 'a': cout << "Members by name: \n";
			for (int i = 0; i < maxmemb; i++) {
				cout << members[i].fullname << endl;
			} break;
		case 'b': cout << "Members by job title: \n";
			for (int i = 0; i < maxmemb; i++) {
				cout << members[i].title << endl;
			} break;
		case 'c': cout << "Members by secret BOP name: \n";
			for (int i = 0; i < maxmemb; i++) {
				cout << members[i].bopname << endl;
			} break;
		case 'd': cout << "Members by preference:\n";
			for (int i = 0; i < maxmemb; i++) {
				switch (members[i].preference) {
				case 0:
					cout << members[i].fullname << endl;
					break;
				case 1:
					cout << members[i].title << endl;
					break;
				case 2:
					cout << members[i].bopname << endl;
					break;
				}
			}
			break;
		case 'q': cout << "Program ended. \n";
			return 0;
		default: cout << "Invalid, enter something else. \n";
			break;

		}
	}
	return 0;

}