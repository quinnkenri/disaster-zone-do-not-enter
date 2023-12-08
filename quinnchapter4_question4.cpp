#include <iostream>
#include <string>
int main()
{
	using namespace std;
	string str1;
	string str2;
	cout << "Enter your first name: "; // again this does not work if you input more than one word names
	cin >> str1;
	cout << "Enter your last name: "; // same
	cin >> str2;

	str2 += ", ";

	string str3 = str2 + str1;

	cout << "Your name as a single string is:\n";
	cout << str3
		<< endl;

	cin.get();
	return 0;
}

