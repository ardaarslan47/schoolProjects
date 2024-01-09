#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_NUMBER_OF_TASKS = 5;

struct Task {
    string name;
    string description;
    bool isCompleted;
};

void displayMenu();
void addTask(vector<Task>& tasks);
void showTasks(vector<Task> tasks);
void markAsCompleted(vector<Task>& tasks);

int main(){
    vector<Task> tasks;
    
    cout << "Welcome to the task management app!" << endl;
    
    int choice = 0;
    
    do {
        displayMenu();
        cout << endl << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        
        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            
            case 2:
                showTasks(tasks);
                break;
                
            case 3:
                markAsCompleted(tasks);
                break;
            
            case 4:
                cout << "Goodbye" << endl;
                break;
                
            default:
                cout << "invalid choice" << endl;
                break;
        }
    } while (choice != 4);
    
    return 0;
}

void displayMenu() {
    cout << endl;
    cout << endl << "1. Add Task";
    cout << endl << "2. Show Tasks";
    cout << endl << "3. Mark task as completed";
    cout << endl << "4. Quit";
}

void addTask(vector<Task>& tasks) {
    if (tasks.size() >= MAX_NUMBER_OF_TASKS) {
        cout << "You reached task capacity";
        return;
    }
    
    Task newTask;
    cout << "Enter task name: ";
    cin >> newTask.name;
    cout << "Enter task description: " << endl;
    cin.ignore();
    getline(cin, newTask.description);
    newTask.isCompleted = false;
    tasks.push_back(newTask);
    cout << "Task added succesfully!";
}

void showTasks(vector<Task> tasks) {
    if (tasks.size() == 0) {
        cout << "No tasks to show!";
        return;
    }
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].name << (tasks[i].isCompleted ? " [X]" : " [ ]") << endl
             << tasks[i].description << endl;
    }
}

void markAsCompleted(vector<Task>& tasks) {
    if (tasks.size() == 0) {
        cout << "No tasks to show!";
        return;
    }
    showTasks(tasks);
    
    int index;
    cout << endl << "Enter the task number to mark completed: ";
    cin >> index;
    
    if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].isCompleted = true;
            cout << "Task marked as completed!";
    } else {
            cout << "Invalid task number.";
    }
}
