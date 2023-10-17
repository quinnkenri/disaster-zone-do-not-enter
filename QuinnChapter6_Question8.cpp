#include <iostream>
#include <fstream>

using namespace std;

int main() {

	string filename;
	cout << "Enter file to be read (.txt only): " << endl;
	cin >> filename;

	ifstream file(filename);

	if (!file) {
		cout << "Failed to open the file." << endl;
		return 1;
	}

	char characters;
	int charactercount = 0;

	while (file.get(characters)) {
		charactercount++;
	}

	file.close();

	cout << "Characters in  your file: " << charactercount << endl;


	cin.get();
	return 0;
}