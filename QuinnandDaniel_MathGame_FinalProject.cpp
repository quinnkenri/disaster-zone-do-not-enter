#include <iostream>
#include <stdlib.h>
#include <ctime> // Used in the time delay function
#include <cctype> // Used in the loop that checks for 'r' to display rules
#include <cstdlib> // The clearscreen function requires this
#include <windows.h> // The clearscreen function requires this

using namespace std;

char doodle; // Used in the function "drawer"
const int questionbanksize = 20; // for level 3
int thingy2 = 1; // This is used to trigger an if statement that allows the "challenge zone" title to be displayed only once.
int firsttime = 0; // This is used to trigger the introductory animation, but then never trigger it again.
int roundcounter = 1; // This counts the number of rounds of the game that have been played.
int points = 0; // This counts the nubmer of points the player has earned.
int challengecounter = 0; // This counts the number of challenge questions that have been answered. When it reaches 20, all challenge questions have been attempted, and the challenge zone is removed from the menu.

static void drawer(int n, char doodle)
{
    for (int i = 0; i < n; ++i) {
        cout << doodle;
    }
    cout << endl;
    return;
} // Special void function that allows me to draw mass blocks of any character I want for decorative purposes


int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
} // Function to generate a random number between a given range

void clearscreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
} // Void function for clearing the screen. It checks if you are on Windows, if so, it uses the cls function. Otherwise it tries something generic.
// NOTE: This function was derived from one on the Visual Studio help page.


void rules() {
    drawer(40, '*');
    cout << "There are three difficulty levels.\nThe first difficulty level is one digit addition and subtraction (1+2 or 2-1)." << endl;
    cout << "The second dificulty level is two digit addition and subtraction (23+34 or 34-12)." << endl;
    cout << "The third difficulty level is the CHALLENGE LEVEL! These are fun mathematical word problems that might have multiple steps!\n\nWhichever you choose, have fun, and remember each CHALLENGE QUESTION is worth 3 points!" << endl;
    drawer(40, '*');
    cout << "2023 /// QUINN LAWSON AND DANIEL HONG /// COLLEGE OF THE ROCKIES /// CSCI-105 PROJECT";
    cout << "\n\n\n\nPress enter to return to the game." << endl;
    return;
} // Function to display rules/info of the game and some credits.


#pragma warning (disable : 26495) // This struct continually triggers the C26495 warning regarding initalization, despite all of the values being initialized in the array. After thorough testing I decided to disable the warning.
struct wordproblems {

    string question;
    int solution;
    bool checker;
};
#pragma warning (default : 26495) // This re-enables the initialization warning on code after this point.

wordproblems questionbank[questionbanksize]{

    {"Sally has 12 apples. She gives 5 apples to her friend. How many apples does she have left?", 7, false},
    {"The Rocky Mountain Chocolate Factory sells a gift box containing 5 chocolates. Their window display includes 12 of these boxes. How many chocolates are in the window display, in total?", 60, false},
    {"Quinn is an engineer at Boeing. \nHe is designing an airplane with a fuel capacity of 1500 liters, and engines that can fly 150km per 1000 liters of fuel burned. \nHow far could the airplane fly, in kilometers, before it runs out of fuel?",225, false},
    {"Tim has 15 math assignments to finish. He can complete an assignment every two days. How many days will it take him to finish all of them?", 30, false},
    {"There are currently 9 flowers in the Halifax Garden. Each flower costs $5 to plant. If the garden spends $100 planting more flowers, how many total flowers will the garden have?", 29, false},
    {"Jennifer has 18 stickers. She wants to divide them equally into 3 sticker books. How many stickers will be in each album?", 6, false},
    {"The Toyota dealership has 10 cars. On a particular day, they recieve 3 more from the factory and sell 2. How many cars are left at the Toyota dealership at the end of the day?", 11, false},
    {"A giant sequoia tree is planted in a park. The tree grows 5 feet per year. How many years will it take to reach 165 feet in height?", 33, false},
    {"SpaceX is landing a rocket on a barge. \nThe rocket is approaching the barge at 1000km/h, and the engine can slow it down by 125km/h every second. \nHow many seconds will it take to slow down to 0km/h and land?", 8, false},
    {"A clock factory produces 14 clocks per weekday, and 5 clocks per weekend. How many clocks do they produce in two weeks?", 150, false},
    {"A butterfly flaps its wings 20 times per second. How many times will it flap its wings in 10 minutes?", 12000, false},
    {"A farm in Creston grows blueberries for people to pick. \nIf one person can pick 25 blueberries per minute, how many minutes will it take them to pick 1000 blueberries?", 40, false},
    {"Bob is building a shed. He has 5 doors to install on the shed, and each door requires 6 nails. He has 8 boxes of nails, and each box contains 4 nails. After the doors are installed, how many nails will be left?", 2, false},
    {"Moncton City Council has collected $8655 in parking tickets this month. \nThey decide to spend $7000 of it on a statue of the mayor's cat, and $850 on a council dinner. \nHow much money is left, in dollars?", 805, false},
    {"The Toronto Subway rat population grows at a rate of 35 rats per month. It grows unchecked for 24 months, until new rat traps begin trapping 50 rats per month. After 30 months, what is the rat population?", 750, false},
    {"Tim Hortons sells 400 coffees on a particular day. Each coffee costs $2.50, of which $0.50 is tax. How much tax is collected on the coffees, in dollars?", 200, false},
    {"Johnny has 15 oranges. He slices them all into halves and gives 4 halves to his friends. How many oranges does he have left?", 13, false},
    {"Florence is climbing Mount Fisher. \nShe takes 4 hours to drive to the base, 3 hours to reach the summit, spends an hour at the summit, takes 3 hours to descend, and 3 hours to drive home. \nHow long was the whole journey, in hours?", 14, false},
    {"Emily has 24 toy cars, and she wants to arrange them into equal rows. If she wants to make 4 rows, how many toy cars will be in each row?", 6, false},
    {"A space heater warms a room by 2 degrees per hour. If the room started at 15 degrees, how many hours will it take for the room to reach 23 degrees?", 4, false},

}; // A bank of word problems for the challenge level. All word problems written by Quinn Lawson.

wordproblems level3unusedquestion(wordproblems questionbank[], int questionbanksize) {
    int unusedCount = 0;

    for (int i = 0; i < questionbanksize; ++i) {
        if (!questionbank[i].checker) {
            unusedCount++;
        }
    }

    if (unusedCount == 0) {
        return { "", 0, true };  // This should never be triggered, as there is an if statement bypassing more than 20 questions from being asked
    }

    int randomUnusedIndex = rand() % unusedCount;

    for (int i = 0; i < questionbanksize; ++i) {
        if (!questionbank[i].checker) {
            if (randomUnusedIndex == 0) {
                // Marks the question as used and returns it.
                questionbank[i].checker = true;
                return questionbank[i];
            }
            randomUnusedIndex--;
        }
    }
    return { "", 0, true };
} // Function that retrieves a randomly selected word problem from the bank and then removes it from future selection using for loops


int addition(int a, int b) {
    return a + b;
} // Function to perform addition operation (levels 1 and 2)

int subtraction(int a, int b) {
    return a - b;
} // Function to perform subtraction operation (levels 1 and 2)

// Below function is the game itself
int playGame(int difficulty) {
    int score = 0;
    wordproblems randomQuestion;

    for (int i = 0; i < 10; ++i) {
        int num1 = 0, num2 = 0, result = 0, answer = 0;
        int doubleplayer = 0;
        int subtractor = 0;
        int attempts = 0; // Initializing everything

        //Each difficulty is a level.
        if (difficulty == 1) {
            num1 = generateRandomNumber(1, 9);
            num2 = generateRandomNumber(1, 9);
            bool isAddition = rand() % 2 == 0;

            if (isAddition) {
                result = addition(num1, num2);
            }
            else {
                result = subtraction(num1, num2);
                subtractor = 1; // Note that this is triggered for subtraction
            } // Randomly decides whether to give an addition or subtraction question, then randomly generates a question with ONE digit

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
                subtractor = 1; // Again triggered for subtraction
            } // Randomly decides whether to give an addition or subtraction question, then randomly generates a question with TWO digits

        }

        // Displays the question
        if (difficulty == 1 || difficulty == 2) {
            cout << "Question " << i + 1 << ": ";
            cout << "What is " << num1;
            if (difficulty == 1) {
                if (subtractor == 0) {
                    cout << " + ";
                }
                else {
                    cout << " - "; // In this case the subtractor int would be set to 1, so the negative sign will be displayed
                }
            }
            else if (difficulty == 2) {
                if (subtractor == 0) {
                    cout << " + ";
                }
                else {
                    cout << " - "; // Subtractor displays negative sign
                }

            }
            cout << num2 << "? "; // End of question
        }
        else if (difficulty == 3) {
            doubleplayer = 2; //
            if (thingy2 == 1) {
                drawer(40, '!');
                drawer(40, '*');
                cout << "     THE CHALLENGE ZONE     " << endl;
                drawer(40, '*');
                drawer(40, '!');
                cout << endl;
            } // Intro screen triggered on the first question, after which it will not be shown.
            randomQuestion = level3unusedquestion(questionbank, questionbanksize);
            cout << "\nQuestion " << i + 1 << ":" << endl;
            cout << randomQuestion.question << endl; // Grabs a random word problem from the bank and displays it.

        }

        thingy2 = 2; // Stops challenge zone intro from being displayed again.


        // Get player's answers
        do {
            cin >> answer;

            // Error handling for non-numerical answers
            if (cin.fail()) {
                if (doubleplayer == 2) {
                    challengecounter++; // Handles unusual error case where a user completes 20 word problems after entering invalid input for at least one question, then returns to the menu.
                }
                cout << "Invalid input. Only numerical answers are allowed, and the answer should be relatively small (5 digits or less). Moving on..." << endl;
                cin.clear();
                cin.ignore(15000, '\n'); // Ignores their input
                break;
            }
            else if (doubleplayer == 2) {
                if (answer == randomQuestion.solution) {
                    cout << "Correct!\n";
                    score++;
                    points++;
                    points++;
                    points++; // Challenge questions worth 3 points, as promised in the rules!
                    challengecounter++; // One challenge question complete
                    break; // Exit the loop if the answer is correct
                }
                else if (answer != randomQuestion.solution) {
                    cout << "Incorrect. Try again!" << endl; // Wrong answer entered
                    attempts++;
                    if (attempts == 3) { // Encouragement message if multiple wrong answers entered
                        cout << "\nKeep trying! \n" << endl;
                    }
                    if (attempts >= 5) {
                        cout << "\nThe correct answer was " << randomQuestion.solution << "." << endl;
                        cout << "\nMoving on to the next question.\n";
                        challengecounter++; // Ensures user will still see a smooth end to the challenge section
                        break; // Exit the loop if the maximum attempts are reached
                    }

                    cout << "\nEnter a different answer: "; // Prompt after each wrong answer
                }

            }
            else if (answer == result) {
                cout << "Correct!\n";
                score++;
                points++; // Level 1 and 2 questions worth 1 point
                break;  
            }
            else if (answer != result) {
                cout << "Incorrect. Try again!" << endl;
                attempts++;

                if (attempts == 3) { // Gives a visual hint which serves as a ballpark estimate of the real answer. 
                    cout << "\nHere is a hint. The answer is the number of stars here: \n" << endl;
                    drawer(abs(result), '*'); // It shows stars even for negative answers, which isn't ideal but better than no hint
                    cout << "\n" << endl;
                }
                if (attempts >= 5) {
                    cout << "\nThe correct answer was " << result << "." << endl;
                    cout << "\nMoving on to the next question.\n";
                    break; // Exit the loop if the maximum attempts are reached
                }

                cout << "\nEnter a different answer: "; // Prompt after wrong answer
            }
        } while (true); // Repeat until the correct answer or maximum attempts are reached
    }

    return score; // Player score returned here
}


int main() {

    if (firsttime == 0) {
   
        firsttime = 1; // Ensures this animation won't be triggered again
        srand(static_cast<unsigned int>(time(0)));
        drawer(40, '*');
        const clock_t start_time1 = clock();
        while (static_cast<double>(clock() - start_time1) / CLOCKS_PER_SEC < 0.2) {
            // an empty loop to introduce a time delay
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
        while (static_cast<double>(clock() - start_time5) / CLOCKS_PER_SEC < 0.2) {
        }

        cout << "\n\nPress Enter to continue...\n";
        cin.ignore(); // This will wait for the user to press Enter
        drawer(40, '*');
    }

    cout << "ROUND " << roundcounter << endl; // Displays the current round of the game. Two rounds are possible if doing level 3, infinite rounds of 1 and 2 are possible.
    cout << "\nThis game is intended for students at a Grade 3 level." << endl;
    cout << "Read the rules by entering 'r' now. Press q to exit the program. Or, enter any other letter to proceed to the Menu." << endl;


    while (true) {
        char input;
        cin >> input;

        if (input == 'r') {
            clearscreen(); // Clears the screen
            rules(); // Displays the rules function
            cin.ignore();
            cin.ignore(); // Two of these required to prevent it from automatically returning to the game before user has read the rules.
            clearscreen(); // Clears everything before game begins
            break;
        }
        else if (input == 'q') {
            return 0; // Quit with q
        }
        else {
            clearscreen(); // Clears everything before game begins
            break;
        }
    }
    if (challengecounter != 20) { // If there are still challenge questions unattempted, all three levels are available
        cout << "~~~~~  MENU  ~~~~~\n\n";
        cout << "LEVEL 1: Easy. Enter 1 to select. \n";
        cout << "LEVEL 2: Medium. Enter 2 to select. \n";
        cout << "LEVEL 3: CHALLENGE! Enter 3 to select. \n";

        // Get user's choice
        int choice;
        cout << "\nEnter the difficulty level (1-3): ";
        cin >> choice;

        // Validate the user's choice
        if (choice < 1 || choice > 3) {
            cout << "You didn't enter a valid choice, so I'll pick for you. You'll be doing LEVEL 1.\n\n";
            choice = 1; // Forces level 1 if user enters something invalid
            const clock_t start_time6 = clock();
            while (static_cast<double>(clock() - start_time6) / CLOCKS_PER_SEC < 2.0) {
            }
        }

        clearscreen();
        // Play the game and get the score
        int score = playGame(choice);

        // Display how the user did at the game
        if (score >= 8) {
            cout << "You got " << score << " out of 10 questions correct. GREAT job!\n";
            cout << "You have " << points << " points!" << endl;
            cout << "Would you like to continue? Press 'y' to continue, 'n' or any other character to stop" << endl;
            char cont;
            cin >> cont;
            if (cont == 'y' || cont == 'Y') {
                roundcounter++;
                clearscreen();
                return main(); // restarts the game after incrementing the number of rounds and saving user score
            }
            else {
                return 0; // quits
            }


        }
        else if (score >= 5) {
            cout << "You got " << score << " out of 10 questions correct. Good job!\n"; // Different message for less points
            cout << "You have " << points << " points!" << endl;
            cout << "Would you like to continue? Press 'y' to continue, 'n' or any other character to stop" << endl;
            char cont;
            cin >> cont;
            if (cont == 'y' || cont == 'Y') {
                roundcounter++;
                clearscreen();
                return main();
            }
            else {
                return 0;
            }
        }
        else if (score >= 3) {
            cout << "You got " << score << " out of 10 questions correct. There is room for improvement!\n"; // Encouragement for poor performance
            cout << "You have " << points << " points." << endl;
            cout << "Would you like to continue? Press 'y' to continue, 'n' or any other character to stop" << endl;
            char cont;
            cin >> cont;
            if (cont == 'y' || cont == 'Y') {
                roundcounter++;
                clearscreen();
                return main();
            }
            else {
                return 0;
            }
        }
        cout << "You only got " << score << " out of 10 questions correct. Don't give up, try again!\n"; // Encouragement for very bad performance
        cout << "You have " << points << " points." << endl;
        cout << "Would you like to continue? Press 'y' to continue, 'n' or any other character to stop" << endl;
        char cont;
        cin >> cont;
        if (cont == 'y' || cont == 'Y') {
            roundcounter++;
            clearscreen();
            return main();
        }
        else {
            return 0;
        }
    }
    else if (challengecounter == 20) { // If every challenge question has been attempted, level 3 is removed from the game
        cout << "~~~~~  MENU  ~~~~~\n\n";
        cout << "LEVEL 1: Easy. Enter 1 to select. \n";
        cout << "LEVEL 2: Medium. Enter 2 to select. \n";
        cout << "LEVEL 3: COMPLETE\n"; // new Level 3 message

        // Get user's choice
        int choice;
        cout << "\nEnter the difficulty level (1-2): ";
        cin >> choice;

        // Validate the user's choice

        if (choice < 1 || choice > 2) {
            cout << "You didn't enter a valid choice, so I'll pick for you. You'll be doing LEVEL 2.\n\n";
            choice = 2;
            const clock_t start_time6 = clock();
            while (static_cast<double>(clock() - start_time6) / CLOCKS_PER_SEC < 2.0) {
            }
        }


        clearscreen();
        // Play the game and get the score
        int score = playGame(choice);

        // Display how the user did at the game
        // Everything below here is the same as in the first if statement

        if (score >= 8) {
            cout << "You got " << score << " out of 10 questions correct. GREAT job!\n";
            cout << "You have " << points << " points!" << endl;
            cout << "Would you like to continue? Press 'y' to continue, 'n' or any other character to stop" << endl;
            char cont;
            cin >> cont;
            if (cont == 'y' || cont == 'Y') {
                roundcounter++;
                clearscreen();
                return main();
            }
            else {
                return 0;
            }


        }
        else if (score >= 5) {
            cout << "You got " << score << " out of 10 questions correct. Good job!\n";
            cout << "You have " << points << " points!" << endl;
            cout << "Would you like to continue? Press 'y' to continue, 'n' or any other character to stop" << endl;
            char cont;
            cin >> cont;
            if (cont == 'y' || cont == 'Y') {
                roundcounter++;
                clearscreen();
                return main();
            }
            else {
                return 0;
            }
        }
        else if (score >= 3) {
            cout << "You got " << score << " out of 10 questions correct. There is room for improvement!\n";
            cout << "You have " << points << " points." << endl;
            cout << "Would you like to continue? Press 'y' to continue, 'n' or any other character to stop" << endl;
            char cont;
            cin >> cont;
            if (cont == 'y' || cont == 'Y') {
                roundcounter++;
                clearscreen();
                return main();
            }
            else {
                return 0;
            }
        }
        cout << "You only got " << score << " out of 10 questions correct. Don't give up, try again!\n";
        cout << "You have " << points << " points." << endl;
        cout << "Would you like to continue? Press 'y' to continue, 'n' or any other character to stop" << endl;
        char cont;
        cin >> cont;
        if (cont == 'y' || cont == 'Y') {
            roundcounter++;
            clearscreen();
            return main();
        }
        else {
            return 0;
        }
    }
}