#include <iostream>
#include <cstring>
int main()
{
	using namespace std;
	const int maxlength = 50;
	char firstname[maxlength];
	char lastname[maxlength];
	cout << "Enter your first name: "; // must be one word for this program to work
	cin >> firstname;
	cout << "Enter your last name: "; // same
	cin >> lastname;
	cout << "Your name in a single string is:\n";
	cout << lastname << ", " << firstname << " "
		<< endl;

	cin.get();
	return 0;
}