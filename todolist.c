/*
    Build a basic to-do list manager in C. Allow users to add tasks, mark them as completed, and view their current to-do list.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Task struct
typedef struct {
    char description[100];
    int completed;
} Task;

// Task List
Task tasks[100];
int taskCount = 0;

// Function to add a task
void addTask(char *desc) {
    strcpy(tasks[taskCount].description, desc);
    tasks[taskCount].completed = 0;
    taskCount++;
}

// Function to mark a task as completed
void markTaskCompleted(int taskNumber) {
    if (taskNumber >= 0 && taskNumber < taskCount) {
        tasks[taskNumber].completed = 1;
    } else {
        printf("Invalid task number.\n");
    }
}

// Function to print the task list
void printTasks() {
    printf("To-Do List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s [%s]\n", i + 1, tasks[i].description, tasks[i].completed ? "Completed" : "Pending");
    }
}

int main() {
    int choice, taskNumber;
    char taskDesc[100];

    while (1) {
        printf("\n1. Add Task\n2. Mark Task as Completed\n3. View To-Do List\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // to clear the newline character from the buffer

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                fgets(taskDesc, sizeof(taskDesc), stdin);
                taskDesc[strcspn(taskDesc, "\n")] = 0; // Remove newline character
                addTask(taskDesc);
                break;
            case 2:
                printf("Enter task number to mark as completed: ");
                scanf("%d", &taskNumber);
                markTaskCompleted(taskNumber - 1); // array index starts at 0
                break;
            case 3:
                printTasks();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
