#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = createNode(newData);
    if (*head == NULL) {
        newNode->next = newNode; 
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head;
    }
    *head = newNode;
}

void deleteNode(struct Node** head, int key) {
    if (*head == NULL)
        return;

    struct Node* curr = *head, *prev = NULL;
    while (curr->data != key) {
        if (curr->next == *head) {
            printf("%d not found in the list\n", key);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    if (curr->next == *head && prev == NULL) {
        *head = NULL;
        free(curr);
        return;
    }

    if (curr == *head) {
        prev = *head;
        while (prev->next != *head)
            prev = prev->next;
        *head = curr->next;
        prev->next = *head;
    } else if (curr->next == *head) { 
        prev->next = *head;
    } else { 
        prev->next = curr->next;
    }

    free(curr); 
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nCircular Linked List Operations\n");
        printf("1. Insert at beginning\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("Circular Linked List: ");
                displayList(head);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
