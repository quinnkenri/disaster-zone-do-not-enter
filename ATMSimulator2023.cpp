//ATM Simulator 2023 (official game) ($79.99 at best buy)
#include <iostream>
#include <string>


using namespace std;


const int stringsize = 50;

struct info {
	char accountowner[stringsize];
	int accountnumber;
	double balance;
	double amount;
	double limit;
};


int main() {
	info tracy = { "Tracy Smith", 294856, 25895.03, 0.00, 800.00 };
	info john = { "John Doe", 394023, 13511.54, 450.00, 1000.00 };
	info han = { "Han Solo", 932012, 42.11, 580.00, 600.00 };

	cout << "Welcome to College of the Rockies online bank. " << endl;
	cout << "\n-___-___-___-___-___-___-___-___-___\n" << endl;
	cout << "\nEnter your account number: " << endl;
	char decision{};
	int choice;
	int person;
	int deposit;
	int withdrawal;
	while (1)
	{
		cin >> choice;

		if (choice == tracy.accountnumber)
		{
			cout << "Hello, " << tracy.accountowner;
			person = 1;
			break;
		}
		else if (choice == john.accountnumber) {
			cout << "Hello, " << john.accountowner;
			person = 2;
			break;
		}
		else if (choice == han.accountnumber) {
			cout << "Hello, " << han.accountowner;
			person = 3;
			break;
		}
		else if (choice == 999999) {
			cout << "Program terminated. Shutting down... " << endl;
			return 0;
		}
		else {
			cout << "Enter a valid account number. " << endl;
		}
	}
	while (1) {
		cout << "\nPlease select an option: " << endl;
		cout << "\n-_-_-_-_-_-_-_-_-_-_-_-\n" << endl;
		cout << "a. Display balance\n" << endl;
		cout << "b. Deposit\n" << endl;
		cout << "c. Withdrawal\n" << endl;
		cout << "d. Log out\n" << endl;
		cin >> decision;



		switch (decision) {

		case 'a': cout << "Your balance is: \n";
			if (person == 1) {
				cout << tracy.balance << endl;
			}
			else if (person == 2) {
				cout << john.balance << endl;
			}
			else if (person == 3) {
				cout << han.balance << endl;
			} break;

		case 'b': cout << "Deposit amount: \n";
			if (person == 1) {
				cin >> deposit;
				cout << "Your new account balance is " << (tracy.balance + deposit) << endl;
				tracy.balance += deposit;
			}
			else if (person == 2) {
				cin >> deposit;
				cout << "Your new account balance is " << (john.balance + deposit) << endl;
				john.balance += deposit;
			}
			else if (person == 3) {
				cin >> deposit;
				cout << "Your new account balance is " << (han.balance + deposit) << endl;
				han.balance += deposit;
			} break;

		case 'c': cout << "Withdrawal amount: \n";
			if (person == 1) {
				cout << "Total withdrawals made today: " << tracy.amount << endl;
				cin >> withdrawal;
				if (withdrawal <= tracy.balance && withdrawal <= (tracy.limit - tracy.amount)) {
					(tracy.balance -= withdrawal);
					(tracy.amount += withdrawal);
					cout << "Withdrawal complete. Your new account balance is " << tracy.amount << endl;
				}
				else if (withdrawal >= tracy.balance) {
					cout << "Insufficient funds. " << endl;
					break;
				}
				else {
					cout << "Daily withdrawal limit reached. " << endl;
					break;
				}
			}
			else if (person == 2) {
				cout << "Total withdrawals made today: " << john.amount << endl;
				cin >> withdrawal;
				if (withdrawal <= john.balance && withdrawal <= (john.limit - john.amount)) {
					(john.balance -= withdrawal);
					(john.amount += withdrawal);
					cout << "Withdrawal complete. Your new account balance is " << john.balance << endl;
				}
				else if (withdrawal >= john.balance) {
					cout << "Insufficient funds. " << endl;
						break;
				}
				else {
					cout << "Daily withdrawal limit reached. " << endl;
					break;
				}
			}
			else if (person == 3) {
				cout << "Total withdrawals made today: " << han.amount << endl;
				cin >> withdrawal;
				if (withdrawal <= han.balance && withdrawal <= (han.limit - han.amount)) {
					(han.balance -= withdrawal);
					(han.amount += withdrawal);
					cout << "Withdrawal complete. Your new account balance is " << han.balance << endl;
				}
				else if (withdrawal >= han.balance) {
					cout << "Insufficient funds. " << endl;
					break;
				}
				else {
					cout << "Daily withdrawal limit reached. " << endl;
					break;
				}
			}
			else {
				cout << "Insufficient funds. " << endl;
			} break;
		case 'd': cout << "Thanks! Logged out. " << endl;
			break;
		default: break;
		}
	}
	return 0;
}