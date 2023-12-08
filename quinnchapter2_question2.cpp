#include <iostream>
int furlongtoyard(int); // function prototype
int main()
{
	using namespace std;
	int furlong;
	cout << "Enter the distance in furlongs: ";
	cin >> furlong;
	int yards = furlongtoyard(furlong);
	cout << furlong << " furlongs = ";
	cout << yards << " yards." << endl;
	return 0;
}
int furlongtoyard(int sts)
{
	return 220 * sts;
}