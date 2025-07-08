#include<iostream>
#include<string>
#include <thread>  
#include <chrono> 
using namespace std;

const int maxTasks = 100;
int taskCount = 0;
void viewTasks();

struct Task {
	string description;
	bool completed;
};

Task tasks[maxTasks];

void addTask() {
	if (taskCount >= maxTasks) {
		cout << "List is full.\n\n";
	}
	else {
		cout << "Enter task description: ";
		cin.ignore();
		getline(cin, tasks[taskCount].description);
		tasks[taskCount].completed = false;
		cout << "Task added successfully!\n\n";
		taskCount++;
	}
	this_thread::sleep_for(std::chrono::seconds(2));
	system("cls");
}

void removeTask() {
	int num;
	if (taskCount == 0) {
		cout << "Tasks list is empty...\n\n";
	}
	else {
		viewTasks();
		cout << "Enter task number to remove: ";
		cin >> num;
		if (num<1 || num>taskCount) {
			cout << "Invalid task number...\n\n";
		}
		else {
			for (int i = num - 1; i < taskCount - 1; i++) {
				tasks[i] = tasks[i + 1];
			}
			cout << "Task removed successfully!\n\n";
			taskCount--;
		}
	}
	this_thread::sleep_for(std::chrono::seconds(2));
	system("cls");
}

void markTask() {
	int num;
	if (taskCount == 0) {
		cout << "Tasks list is empty...\n\n";
	}
	else {
		viewTasks();
		cout << "Enter task number to mark as complete: ";
		cin >> num;
		if (num<1 || num>taskCount) {
			cout << "Invalid task number...\n\n";
		}
		else {
			tasks[num - 1].completed = true;
			cout << "Task marked as completed!\n\n";
		}
	}
	this_thread::sleep_for(std::chrono::seconds(2));
	system("cls");
}

void viewTasks() {
	int num;
	if (taskCount == 0) {
		cout << "Tasks list is empty...\n\n";
	}
	else {
		for (int i = 0; i < taskCount; i++) {
			cout << i + 1 << ". " << tasks[i].description;
			if (tasks[i].completed) {
				cout << " [Completed]\n";
			}
			else {
				cout << " [Incomplete]\n";
			}
		}
		cout << endl;
	}
}

int main() {
	int choice;
	cout << " ======= TO-DO-LIST MANAGER ========\n\n";
	do {
		cout << "1. Add Task\n2. Remove Task\n3. Mark Task as Complete\n4. View Tasks\n5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cout << "------------------------------\n";
		switch (choice) {
		case 1:
			addTask();
			break;
		case 2:
			removeTask();
			break;
		case 3:
			markTask();
			break;
		case 4:
			viewTasks();
			break;
		case 5:
			cout << "Exiting...\n\nThank you for using!\n";
			return 0;
		default:
			cout << "Invalid choice. Try again...\n";
			break;
		}
	} while (choice != 5);

	system("pause>0");
	return 0;
}