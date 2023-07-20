#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store contact information
struct Contact {
    char name[50];
    char phone[15];
    char email[50];
    struct Contact* next;
};

// Global variable to store the head of the linked list
struct Contact* head = NULL;

// Function to create a new contact
struct Contact* createContact(char name[], char phone[], char email[]) {
    struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    strcpy(newContact->email, email);
    newContact->next = NULL;
    return newContact;
}

// Function to add a contact to the linked list
void addContact(char name[], char phone[], char email[]) {
    struct Contact* newContact = createContact(name, phone, email);
    if (head == NULL) {
        head = newContact;
    } else {
        struct Contact* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newContact;
    }
    printf("Contact added successfully!\n");
}

// Function to display all contacts
void displayContacts() {
    if (head == NULL) {
        printf("No contacts found.\n");
    } else {
        struct Contact* current = head;
        printf("Contacts List:\n");
        while (current != NULL) {
            printf("Name: %s\nPhone: %s\nEmail: %s\n\n", current->name, current->phone, current->email);
            current = current->next;
        }
    }
}

// Function to search for a contact by name or phone number
void searchContact(char key[]) {
    if (head == NULL) {
        printf("No contacts found.\n");
    } else {
        struct Contact* current = head;
        int found = 0;
        while (current != NULL) {
            if (strcmp(current->name, key) == 0 || strcmp(current->phone, key) == 0) {
                printf("Contact found:\n");
                printf("Name: %s\nPhone: %s\nEmail: %s\n", current->name, current->phone, current->email);
                found = 1;
                break;
            }
            current = current->next;
        }
        if (!found) {
            printf("Contact not found.\n");
        }
    }
}

// Function to delete a contact by name or phone number
void deleteContact(char key[]) {
    if (head == NULL) {
        printf("No contacts found.\n");
    } else {
        struct Contact* current = head;
        struct Contact* prev = NULL;
        int found = 0;
        while (current != NULL) {
            if (strcmp(current->name, key) == 0 || strcmp(current->phone, key) == 0) {
                if (prev == NULL) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
                printf("Contact deleted successfully!\n");
                found = 1;
                break;
            }
            prev = current;
            current = current->next;
        }
        if (!found) {
            printf("Contact not found.\n");
        }
    }
}

// Function to free memory and exit the program
void exitProgram() {
    struct Contact* current = head;
    while (current != NULL) {
        struct Contact* temp = current;
        current = current->next;
        free(temp);
    }
    printf("Exiting the program.\n");
    exit(0);
}

int main() {
    char name[50], phone[15], email[50], key[50];
    int choice;

    while (1) {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf(" %[^\n]", name);
                printf("Enter Phone: ");
                scanf(" %[^\n]", phone);
                printf("Enter Email: ");
                scanf(" %[^\n]", email);
                addContact(name, phone, email);
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                printf("Enter Name or Phone: ");
                scanf(" %[^\n]", key);
                searchContact(key);
                break;
            case 4:
                printf("Enter Name or Phone: ");
                scanf(" %[^\n]", key);
                deleteContact(key);
                break;
            case 5:
                exitProgram();
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
