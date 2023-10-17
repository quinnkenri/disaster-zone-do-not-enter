#include <iostream>
#include <cctype>

using namespace std;

int main() {
    char input;

    cout << "Enter text (type @ to exit): ";

    while (cin.get(input) && input != '@') {
        if (isalpha(input)) {
            if (isupper(input)) {
                input = tolower(input);
            }
            else {
                input = toupper(input);
            }
        }
        else if (isdigit(input)) {
            continue;
        }

        cout << input;
    }

    return 0;
}
