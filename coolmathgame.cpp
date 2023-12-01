#include <iostream>
#include <stdlib.h>
#include <ctime> // Used in the time delayed intro function
#include <cctype> // Used in the loop that checks for 'r' to display rules
#include <cstdlib> // The clearscreen function requires this
#include <windows.h> // Clearscreen function requires this too

using namespace std;

char doodle; //declaring this now for use in the void function below
const int questionbanksize = 15; //for level 3
int thingy2 = 1;
int firsttime = 0;
int roundcounter = 1;
int points = 0;

static void drawer(int n, char doodle)
{
    for (int i = 0; i < n; ++i) {
        cout << doodle;
    }
    cout << endl;
    return;
} // special void function that allows me to draw mass blocks of any character I want for decorative purposes

// Function to generate a random number between a given range
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void clearscreen() {

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
} // void function for clearing the screen. It checks if you are on windows, if so, it uses the cls function. Otherwise it tries something generic.


void rules() {
    drawer(40, '*');
    cout << "There are three difficulty levels.\nThe first difficulty level is one digit addition and subtraction (1+2 or 2-1)." << endl;
    cout << "The second dificulty level is two digit addition and subtraction (23+34 or 34-12)." << endl;
    cout << "The third difficulty level is the CHALLENGE LEVEL! These are fun word problems that might have multiple steps!\n\nWhichever you choose, have fun, and remember each CHALLENGE QUESTION is worth 3 points!" << endl;
    drawer(40, '*');
    cout << "2023 /// QUINN LAWSON AND DANIEL HONG /// COLLEGE OF THE ROCKIES /// CSCI-105 PROJECT";
    cout << "\n\n\n\nPress enter to return to the game." << endl;
    return;
}


#pragma warning (disable : 26495)
struct wordproblems {

    string question;
    int solution;
    bool checker;
};
#pragma warning (default : 26495)

wordproblems questionbank[questionbanksize]{

    {"Sally has 12 apples. She gives 5 apples to her friend. How many apples does she have left?", 7, false},
    {"The Rocky Mountain Chocolate Factory sells a gift box containing 5 chocolates. Their window display includes 12 of these boxes. How many chocolates are in the window display, in total?", 60, false},
    {"Quinn is an engineer at Boeing. \nHe is designing an airplane with a fuel capacity of 1500 liters, and engines that can fly 150km per 1000 liters of fuel burned. \nHow far could the airplane fly before it runs out of fuel?",225, false},
    {"Tim has 15 math assignments to finish. He can complete an assignment every two days. How many days will it take him to finish all of them?", 30, false},
    {"There are currently 9 flowers in the Halifax Garden. Each flower costs $5 to plant. If the garden spends $100 planting more flowers, how many total flowers will the garden have?", 29, false},
    {"Jennifer has 18 stickers. She wants to divide them equally into 3 sticker books. How many stickers will be in each album?", 6, false},
    {"The Toyota dealership has 10 cars. On a particular day, they recieve 3 more from the factory and sell 2. How many cars are left at the Toyota dealership at the end of the day?", 11, false},
    {"A giant sequoia tree is planted in a park. The tree grows 5 feet per year. How many years will it take to reach 165 feet in height?", 33, false},
    {"SpaceX is landing a rocket on a barge. The rocket is approaching the barge at 1000km/h, and the engine can slow it down by 125km/h every second. How many seconds will it take to land?", 8, false},
    {"A clock factory produces 14 clocks per weekday, and 5 clocks per weekend. How many clocks do they produce in two weeks?", 150, false},
    {"A butterfly flaps its wings 20 times per second. How many times will it flap its wings in 10 minutes?", 12000, false},
    {"A farm in Creston grows blueberries for people to pick. If one person can pick 25 blueberries per minute, how many minutes will it take them to pick 1000 blueberries?", 40, false},
    {"Bob is building a shed. He has 5 doors to install on the shed, and each door requires 6 nails. He has 8 boxes of nails, and each box contains 4 nails. After the doors are installed, how many nails will be left?", 2, false},
    {"Moncton City Council has collected $8655 in parking tickets this month. They decide to spend $7000 of it on a statue of the mayor's cat, and $850 on a council dinner. How much is left?", 805, false},
    {"The Toronto Subway rat population grows at a rate of 35 rats per month. It grows unchecked for 24 months, until new rat traps begin trapping 50 rats per month. After 30 months, what is the rat population?", 750, false}

};

wordproblems level3unusedquestion(wordproblems questionbank[], int questionbanksize) {
    int unusedCount = 0;

    for (int i = 0; i < questionbanksize; ++i) {
        if (!questionbank[i].checker) {
            unusedCount++;
        }
    }

    if (unusedCount == 0) {

        return { "", 0, true };  // 'true' indicates no more unused questions
    }

    int randomUnusedIndex = rand() % unusedCount;

    for (int i = 0; i < questionbanksize; ++i) {
        if (!questionbank[i].checker) {
            if (randomUnusedIndex == 0) {
                // Mark the question as used and return it
                questionbank[i].checker = true;
                return questionbank[i];
            }
            randomUnusedIndex--;
        }
    }
    return { "", 0, true };
}


// Function to perform addition operation
int addition(int a, int b) {
    return a + b;
}

// Function to perform subtraction operation
int subtraction(int a, int b) {
    return a - b;
}

// Function to perform multiplication operation
int multiplication(int a, int b) {
    return a * b;
} //UNUSED

// Function to perform division operation
int division(int a, int b) {
    return a / b;
} //UNUSED

// Function to play the game for a given difficulty level
int playGame(int difficulty) {
    int score = 0;
    wordproblems randomQuestion;

    for (int i = 0; i < 10; ++i) {
        int num1 = 0, num2 = 0, result = 0, answer = 0;
        int thingy = 0;
        int attempts = 0;

        // Generate random numbers based on difficulty
        if (difficulty == 1) {
            num1 = generateRandomNumber(1, 9);
            num2 = generateRandomNumber(1, 9);
            bool isAddition = rand() % 2 == 0;

            if (isAddition) {
                result = addition(num1, num2);
            }
            else {
                result = subtraction(num1, num2);
                thingy = 1;
            }

        }
        else if (difficulty == 2) {
            num1 = generateRandomNumber(10, 99);
            num2 = generateRandomNumber(10, 99);
            bool isAddition = rand() % 2 == 0;

            if (isAddition) {
                result = addition(num1, num2);
            }
            else {
                result = subtraction(num1, num2);
                thingy = 1;
            }

        }

        // Display the math problem
        if (difficulty == 1 || difficulty == 2) {
            cout << "Question " << i + 1 << ": ";
            cout << "What is " << num1;
            if (difficulty == 1) {
                if (thingy == 0) {
                    cout << " + ";
                }
                else {
                    cout << " - ";
                }
            }
            else if (difficulty == 2) {
                if (thingy == 0) {
                    cout << " + ";
                }
                else {
                    cout << " - ";
                }

            }
            cout << num2 << "? ";
        }
        else if (difficulty == 3) {
            thingy = 2;
            if (thingy2 == 1) {
                drawer(40, '!');
                drawer(40, '*');
                cout << "     THE CHALLENGE ZONE     " << endl;
                drawer(40, '*');
                drawer(40, '!');
                cout << endl;
            }
            randomQuestion = level3unusedquestion(questionbank, questionbanksize);
            cout << "\nQuestion " << i + 1 << ":" << endl;
            cout << randomQuestion.question << endl;

        }

        thingy2 = 2;


        // Get user's answer
        do {
            cin >> answer;

            // Check if the answer is correct
            if (cin.fail()) {
                cout << "Invalid input. Only numerical answers are allowed, and the answer should be relatively small (5 digits or less). Moving on..." << endl;
                cin.clear();
                cin.ignore(15000, '\n'); // ignores the input
                break; // checks if user inputted numbers. if not, throws error and moves on
            }
            else if (thingy == 2) {
                if (answer == randomQuestion.solution) {
                    cout << "Correct!\n";
                    score++;
                    points++;
                    points++;
                    points++;
                    break; // Exit the loop if the answer is correct
                }
                else if (answer != randomQuestion.solution) {
                    cout << "Incorrect. Try again!" << endl;
                    attempts++;
                    if (attempts == 3) { //Gives appropriate hint for age level
                        cout << "\nKeep trying! \n" << endl;
                    }
                    if (attempts >= 5) {
                        cout << "\nThe correct answer was " << randomQuestion.solution << "." << endl;
                        cout << "\nMoving on to the next question.\n";
                        break; // Exit the loop if the maximum attempts are reached
                    }

                    cout << "\nEnter a different answer: ";
                }

            }
            else if (answer == result) {
                cout << "Correct!\n";
                score++;
                points++;
                break; // Exit the loop if the answer is correct
            }
            else if (answer != result || answer != randomQuestion.solution) {
                cout << "Incorrect. Try again!" << endl;
                attempts++;

                if (attempts == 3) { //Gives appropriate hint for age level
                    cout << "\nHere is a hint. The answer is the number of stars here: \n" << endl;
                    drawer(abs(result), '*');
                    cout << "\n" << endl;
                }
                if (attempts >= 5) {
                    cout << "\nThe correct answer was " << result << "." << endl;
                    cout << "\nMoving on to the next question.\n";
                    break; // Exit the loop if the maximum attempts are reached
                }

                cout << "\nEnter a different answer: ";
            }
        } while (true); // Repeat until the correct answer or maximum attempts are reached
    }

    return score;
}


int main() {

    if (firsttime == 0) {
        // Seed the random number generator
        firsttime = 1;
        srand(static_cast<unsigned int>(time(0)));

        // Display menu
        drawer(40, '*');
        const clock_t start_time1 = clock();
        while (static_cast<double>(clock() - start_time1) / CLOCKS_PER_SEC < 0.2) {
            // an empty loop to introduce a delay
        }
        drawer(40, '*');
        const clock_t start_time2 = clock();
        while (static_cast<double>(clock() - start_time2) / CLOCKS_PER_SEC < 0.2) {
        }
        cout << "Welcome to the Cool Math Game!" << endl;
        const clock_t start_time3 = clock();
        while (static_cast<double>(clock() - start_time3) / CLOCKS_PER_SEC < 0.2) {
        }
        drawer(40, '*');
        const clock_t start_time4 = clock();
        while (static_cast<double>(clock() - start_time4) / CLOCKS_PER_SEC < 0.2) {
        }
        drawer(40, '*');

        const clock_t start_time5 = clock();
        while (static_cast<double>(clock() - start_time5) / CLOCKS_PER_SEC < 1.0) {
        }

        // Prompt the user to press Enter to continue
        cout << "\n\nPress Enter to continue...\n";
        cin.ignore(); // This will wait for the user to press Enter
        drawer(40, '*');
    }

    cout << "ROUND " << roundcounter << endl;
    cout << "\nThis game is intended for students at a Grade 3 level." << endl;
    cout << "Read the rules by entering 'r' now. Press q to exit the program. Or, enter any other letter to proceed to the Menu." << endl;


    while (true) {
        char input;
        cin >> input;

        if (input == 'r') {
            clearscreen();
            rules();
            cin.ignore();
            cin.ignore(); // two of these required to prevent it from automatically returning to the game before you've read the rules.
            clearscreen();
            break;
        }
        else if (input == 'q') {
            return 0;
        }
        else {
            clearscreen();
            break;
        }
    }
    cout << "~~~~~  MENU  ~~~~~\n\n";
    cout << "LEVEL 1: Easy. Press 1 to select. \n";
    cout << "LEVEL 2: Medium. Press 2 to select. \n";
    cout << "LEVEL 3: CHALLENGE! Press 3 to select. \n";

    // Get user's choice
    int choice;
    cout << "\nEnter the difficulty level (1-3): ";
    cin >> choice;

    // Validate the user's choice

    if (choice < 1 || choice > 3) {
        cout << "You didn't enter a choice, so I'll pick for you. You'll be doing LEVEL 1.\n\n";
        choice = 1;
        const clock_t start_time6 = clock();
        while (static_cast<double>(clock() - start_time6) / CLOCKS_PER_SEC < 2.0) {
        }
    }


    clearscreen();
    // Play the game and get the score
    int score = playGame(choice);

    // Display the final score
    if (score >= 8) {
        cout << "You got " << score << " out of 10 questions correct. GREAT job!\n";
        cout << "You have " << points << " points!" << endl;
        cout << "would like to continue? Press  y to continue, n to stop or any other character" << endl;
        char cont;
        cin >> cont;
        if (cont == 'y' || cont == 'Y') {
            roundcounter++;
            clearscreen();
            return main();
        }
        else if (cont == 'N' || cont == 'n') {
            return 0;

        }


    }
    else if (score >= 5) {
        cout << "You got " << score << " out of 10 questions correct. Good job!\n";
        cout << "You have " << points << " points!" << endl;
        cout << "Would like to continue? Press y to continue, n to stop or any other character" << endl;
        char cont;
        cin >> cont;
        if (cont == 'y' || cont == 'Y') {
            roundcounter++;
            clearscreen();
            return main();
        }
        else if (cont == 'N' || cont == 'n') {
            return 0;
        }
    }
    else if (score >= 3) {
        cout << "You got " << score << " out of 10 questions correct. There is room for improvement!\n";
        cout << "You have " << points << " points." << endl;
        cout << "Would like to continue? Press y to continue, n to stop or any other character" << endl;
        char cont;
        cin >> cont;
        if (cont == 'y' || cont == 'Y') {
            roundcounter++;
            clearscreen();
            return main();
        }
        else if (cont == 'N' || cont == 'n') {
            return 0;
        }
    }
    cout << "You only got " << score << " out of 10 questions correct. Don't give up, try again!\n";
    cout << "You have " << points << " points." << endl;
    cout << "Would like to continue? Press y to continue, n to stop" << endl;
    char cont;
    cin >> cont;
    if (cont == 'y' || cont == 'Y') {
        roundcounter++;
        clearscreen();
        return main();
    }
    else if (cont == 'N' || cont == 'n') {
        return 0;
    }
}