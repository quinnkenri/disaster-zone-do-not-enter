#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rules();
void draw(int, char);

int getValidIntegerInput(const char* prompt, int min, int max)
{
    int input;
    int numScanned;
    while (1) {
        printf("%s", prompt);
        numScanned = scanf("%d", &input);
        if (numScanned != 1) {
            printf("Invalid input. Please enter a valid integer.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }
        if (input < min || input > max) {
            printf("Input out of range. Please enter a number between %d and %d.\n", min, max);
            continue;
        }
        break;
    }
    return input;
}

int main()
{
    char player_name[100];
    int amt, bett_amt, guess, dice;
    char choice[2];

    srand(time(0));

    draw(60, '_');
    printf("\n\n\n\t WELCOME TO THE CASINO OF THE ROCKIES \n\n\n\n");
    draw(60, '_');

    printf("\n\n\n\t\t BETTING GAME \n\n\n\n");
    draw(60, '_');

    printf("\n\nEnter Your Name: ");
    if (scanf("%99s", player_name) != 1) {
        printf("Invalid input. Exiting the program.\n");
        return 1;
    }

    printf("Hi %s!", player_name);
    printf("\n\nEnter amount to start the game (USD): ");
    if (scanf("%d", &amt) != 1) {
        printf("Invalid input. Exiting the program.\n");
        return 1;
    }

    do {
        rules();

        printf("\n\nYour current balance is USD. %d\n", amt);

        do {
            printf("%s, enter money to bet (USD): ", player_name);
            if (scanf("%d", &bett_amt) != 1) {
                printf("Invalid input. Please enter a valid integer.\n");
                // Clear the input buffer
                while (getchar() != '\n');
                continue;
            }
        } while (bett_amt > amt);

        do {
            printf("Guess the number between 1 and 10 to bet on: ");
            if (scanf("%d", &guess) != 1) {
                printf("Invalid input. Please enter a valid integer.\n");
                // Clear the input buffer
                while (getchar() != '\n');
                continue;
            }
        } while (guess <= 0 || guess > 10);

        dice = rand() % 10 + 1;

        if (dice == guess) {
            printf("Yeehaw! You won. You get USD %d more\n", bett_amt * 5);
            amt = amt + bett_amt * 5;
        }
        else {
            printf("You lose. You have lost USD %d\n", bett_amt);
            amt = amt - bett_amt;
        }

        if (amt <= 0) {
            printf("\nYou have no money :(");
            break;
        }

        printf("\n\nDo you want to play again (y/n)? ");
        if (scanf("%1s", choice) != 1) {
            printf("Invalid input. Exiting the program.\n");
            return 1;
        }
    } while (choice[0] == 'Y' || choice[0] == 'y');

    printf("\n\n\n");
    draw(70, '=');
    printf("\n\n Thanks for playing. :) Your balance amount is USD %d\n\n", amt);
    draw(70, '=');

    return 0;
}

void rules()
{
    printf("\n\n");
    draw(80, '-');
    printf("\n");
    printf("\t\tRules of the game\n");
    draw(80, '-');

    printf("\t1. Choose any number between 1 to 10\n");
    printf("\t2. If you win, you will get 5x the money you bet!\n");
    printf("\t3. If you bet on the wrong number, you will lose your betting amount\n\n");

    draw(80, '-');
}

void draw(int n, char sym)
{
    int i;

    for (i = 0; i < n; ++i) {
        printf("%c", sym);
    }

    printf("\n");
}


