#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
    struct Contact *prev;
    struct Contact *next;
};

struct Contact *head = NULL;

// Create a new contact
struct Contact* createContact(char name[], char phone[]) {
    struct Contact *newNode = (struct Contact*)malloc(sizeof(struct Contact));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Add contact
void addContact() {
    char name[50], phone[15];

    printf("Enter Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Phone Number: ");
    scanf("%s", phone);

    struct Contact *newNode = createContact(name, phone);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Contact *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Contact Added Successfully!\n");
}

// Display contacts
void displayContacts() {
    struct Contact *temp = head;

    if (head == NULL) {
        printf("Phonebook is Empty!\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    while (temp != NULL) {
        printf("Name : %s\n", temp->name);
        printf("Phone: %s\n\n", temp->phone);
        temp = temp->next;
    }
}

// Search contact
void searchContact() {
    char name[50];
    printf("Enter Name to Search: ");
    scanf(" %[^\n]", name);

    struct Contact *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("\nContact Found\n");
            printf("Name : %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
            return;
        }
        temp = temp->next;
    }

    printf("Contact Not Found!\n");
}

// Delete contact
void deleteContact() {
    char name[50];
    printf("Enter Name to Delete: ");
    scanf(" %[^\n]", name);

    struct Contact *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {

            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            free(temp);
            printf("Contact Deleted Successfully!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Contact Not Found!\n");
}

int main() {
    int choice;

    do {
        printf("\n===== PHONEBOOK MENU =====\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 5);

    return 0;
}