#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student
struct Student {
    int id;
    char name[50];
    struct Student* next;
};

// Global pointer to the head of the linked list
struct Student* head = NULL;

// Function to add a student to the linked list
void addStudent(int id, const char* name) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->next = head;
    head = newStudent;
}

// Function to display all students in the linked list
void displayStudents() {
    struct Student* current = head;
    printf("Student List:\n");
    while (current != NULL) {
        printf("ID: %d\nName: %s\n", current->id, current->name);
        current = current->next;
    }
}

// Function to find and display a student by ID
void findStudent(int id) {
    struct Student* current = head;
    while (current != NULL) {
        if (current->id == id) {
            printf("Student Found: ID: %d, Name: %s\n", current->id, current->name);
            return;
        }
        current = current->next;
    }
    printf("Student with ID %d not found.\n", id);
}

// Function to remove a student by ID
void removeStudent(int id) {
    struct Student* current = head;
    struct Student* prev = NULL;
    while (current != NULL) {
        if (current->id == id) {
            if (prev == NULL) {
                // Removing the first element
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Student with ID %d removed.\n", id);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Student with ID %d not found. No student removed.\n", id);
}

// Function to free memory and clear the linked list
void clearStudents() {
    while (head != NULL) {
        struct Student* current = head;
        head = head->next;
        free(current);
    }
}

int main() {
    int choice, id;
    char name[50];

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Find Student by ID\n");
        printf("4. Remove Student by ID\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student ID: ");
                scanf("%d", &id);
                printf("Enter student name: ");
                scanf("%s", name);
                addStudent(id, name);
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Enter student ID to find: ");
                scanf("%d", &id);
                findStudent(id);
                break;
            case 4:
                printf("Enter student ID to remove: ");
                scanf("%d", &id);
                removeStudent(id);
                break;
            case 5:
                clearStudents();
                printf("Exiting the program. Memory freed.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
