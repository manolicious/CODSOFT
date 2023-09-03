#include <iostream>
#include <string>

using namespace std;


struct Task {
    string description;
    bool completed;
};

class ToDoList {
private:
    Task tasks[5];
    int taskCount;

public:
    ToDoList() : taskCount(0) {}

    void addTask(const string& description) {
        if (taskCount < 5) {
            tasks[taskCount].description = description;
            tasks[taskCount].completed = false;
            taskCount++;
            cout << "Task added: " << description << endl;
        } else {
            cout << "Maximum number of tasks reached." << endl;
        }
    }

    void viewTasks() {
        if (taskCount == 0) {
            cout << "No tasks found." << endl;
        } else {
            cout << "Tasks:" << endl;
            for (int i = 0; i < taskCount; ++i) {
                cout << (i + 1) << ". ";
                cout << (tasks[i].completed ? "[X] " : "[ ] ");
                cout << tasks[i].description << endl;
            }
        }
    }

    void markTaskCompleted(int index) {
        if (index >= 1 && index <= taskCount) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(int index) {
        if (index >= 1 && index <= taskCount) {
            for (int i = index - 1; i < taskCount - 1; ++i) {
                tasks[i] = tasks[i + 1];
            }
            taskCount--;
            cout << "Task removed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    ToDoList myList;
    int choice;

    do {
        cout << "===== ToDo List Manager =====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore();
                string description;
                cout << "Enter task description: ";
                getline(cin, description);
                myList.addTask(description);
                break;
            }
            case 2:
                myList.viewTasks();
                break;
            case 3: {
                int index;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> index;
                myList.markTaskCompleted(index);
                break;
            }
            case 4: {
                int index;
                cout << "Enter the index of the task to remove: ";
                cin >> index;
                myList.removeTask(index);
                break;
            }
            case 5:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

