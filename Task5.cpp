//Cpp Program for To-Do List
#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 100;

void addTask(string tasks[], bool completed[], int &taskCount) {
    if (taskCount < MAX_TASKS) {
        cout << "Enter task description: ";
        cin.ignore(); 
        getline(cin, tasks[taskCount]);
        completed[taskCount] = false;
        taskCount++;
        cout << "Task added successfully!" << endl;
    } else {
        cout << "Task list is full!" << endl;
    }
}

void markTaskCompleted(bool completed[], int taskCount) {
    int index;
    cout << "Enter task number to mark as completed (1 to " << taskCount << "): ";
    cin >> index;
    if (index >= 1 && index <= taskCount) {
        completed[index - 1] = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

void displayTasks(string tasks[], bool completed[], int taskCount) {
    cout << "\nTo-Do List:" << endl;
    for (int i = 0; i < taskCount; i++) {
        cout << i + 1 << ". " << tasks[i] << (completed[i] ? " [Completed]" : " [Not Completed]") << endl;
    }
}

void deleteTask(string tasks[], bool completed[], int &taskCount, int index) {
    for (int i = index; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
        completed[i] = completed[i + 1];
    }
    taskCount--;
    cout << "Task deleted successfully!" << endl;
}

int main() {
    string tasks[MAX_TASKS];
    bool completed[MAX_TASKS];
    int taskCount = 0;
    int choice;

    do {
        cout << "\nTo-Do List Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Mark Task Completed" << endl;
        cout << "3. Display Tasks" << endl;
        cout << "4. Delete Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks, completed, taskCount);
                break;
            case 2:
                markTaskCompleted(completed, taskCount);
                break;
            case 3:
                displayTasks(tasks, completed, taskCount);
                break;
            case 4: {
                int index;
                cout << "Enter task number to delete (1 to " << taskCount << "): ";
                cin >> index;
                if (index >= 1 && index <= taskCount) {
                    deleteTask(tasks, completed, taskCount, index - 1);
                } else {
                    cout << "Invalid task number!" << endl;
                }
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}