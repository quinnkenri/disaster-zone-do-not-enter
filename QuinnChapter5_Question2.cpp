// Using array to recreate example 5.4
#include <iostream>
#include <array>
using namespace std;
const int ArSize = 101;
int main()

{
    array<long double, ArSize> additional;
    additional[1] = additional[0] = 1L;
    for (int i = 2; i < ArSize; i++)
        additional[i] = i * additional[i - 1];
    for (int i = 0; i < ArSize; i++)
        cout << i << "! = " << additional[i] << endl;
    cin.get();
    return 0;
}