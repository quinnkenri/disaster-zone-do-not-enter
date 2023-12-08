#include <iostream>
int main()
{
	using namespace std;
	int age;
	cout << "What is your age in years?" << endl;
	cin >> age; // input age in years
	cout << "Here is your age in months...";
	age = age * 12;
	// output age in months
	cout << "Your age is " << age << " months. " << endl;
	cin.get();
	return 0;
}