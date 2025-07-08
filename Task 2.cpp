#include<iostream>
#include <thread>   // For sleep functions
#include <chrono> 
using namespace std;

void calculations() {
	int num1, num2, operation, choice;
	cout << "Enter 1st number: ";
	cin >> num1;
	cout << "Enter 2nd number: ";
	cin >> num2;
	cout << "Choose Operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n\nEnter your choice: ";
	cin >> operation;
	switch (operation) {
	case 1:
		cout << "Addition Performed\nResult: " << num1 + num2 << endl;
		break;
	case 2:
		cout << "Subtraction Performed\nResult: " << num1 - num2 << endl;
		break;
	case 3:
		cout << "Multiplication Performed\nResult: " << num1 * num2 << endl;
		break;
	case 4:
		if (num2 == 0) {
			cout << "Division not possible because second number is zero\n";
			break;
		}
		else {
			cout << "Division Performed\nResult: " << num1 / num2 << endl;
			break;
		}
	default:
		cout << "Invalid operation/number choosed\nTry again:\n";
		calculations();
	}
	cout << "\nDo you want to perform more calculations: \n1. yes\n2. No\n";
	cout << "Enter your choice: ";
	cin >> choice;
	cout << endl;
	if (choice == 1) {
		this_thread::sleep_for(std::chrono::seconds(1));
		system("cls");
		calculations();
	}
}

int main() {
	int choice;
	cout << " ===== CALCULATOR =====\n\n";
	calculations();
	cout << "Thank You For Using...\n";
	system("pause>0");
	return 0;
}