#include <iostream>
#include <cctype>

using namespace std;

int main() {

	string input;
	int vowels = 0;
	int consonants = 0;
	int other = 0;

	cout << "Enter words (enter 'q' to quit): " << endl;

	while (true) {

		cin >> input;

		if (input[0] == 'q') {

			cout << "Program terminated. " << endl;
			break;
		}

		if (isalpha(input[0])) {
			char lowerinput = tolower(input[0]);
			if (lowerinput == 'a' || lowerinput == 'e' || lowerinput == 'i' || lowerinput == 'o' || lowerinput == 'u') {
				vowels++;
			}
			else {
				consonants++;
			}
		}
		else {
			other++;
		}
		
		}

	cout << "Words beginning with a vowel: " << vowels << endl;
	cout << "Words beginning with consonants: " << consonants << endl;
	cout << "Characters fitting neither: " << other << endl;

	cin.get();
	return 0;
	}