#include <iostream>
using namespace std;
void Mice() {
    cout << "Three blind mice\n"; //function prototype for first line
} 

void Run() {
    cout << "See how they run\n"; //function prototype for second line
}

int main() {
    // Printing first line twice
    Mice();
    Mice();

    // Printing second line twice
    Run();
    Run();

    cin.get();
    return 0;
}
