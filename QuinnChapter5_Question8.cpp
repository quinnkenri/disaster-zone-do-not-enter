#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const int maxlength = 80; // max length of words entered

    char word[maxlength];
    int wordcount = 0;

    cout << "Enter a word (or 'done' to exit): \n";

    while (true) {
        cin >> word;

        if (strcmp(word, "done") == 0) {
            cout << "Program over. You entered " << wordcount << " words. " << endl;
            break;
        }
        else {
            wordcount++;

        }
    }

    cin.get();
    return 0;
}