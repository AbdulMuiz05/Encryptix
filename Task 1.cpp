#include<iostream>
#include<cstdlib>
using namespace std;

int main() {
	int guess;
	int num = rand() % 100 + 1;
	cout << " ===== NUMBER GUESSING GAME =====\n" << endl;
	cout << "Random Number Generated between 0-100\n" << endl;
	do {
		cout << "Guess the number: ";
		cin >> guess;
		if (guess > num) {
			if ((guess - num) <= 5) {
				cout << "Your guess is slightly high\n";
			}
			else {
				cout << "Your guess is too high\n";
			}
		}
		else if (guess < num) {
			if ((num - guess) <= 5) {
				cout << "Your guess is slightly low\n";
			}
			else {
				cout << "Your guess is too low\n";
			}
		}
		else if (guess == num) {
			cout << "\nCongratulations! You guessed the right number\n";
			break;
		}

	} while (guess != num);

	system("pause>0");
	return 0;
}