#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Concatenate two lists
void concatenate(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }

    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head2;
}

// Display list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // List 1: 1 -> 2 -> 3
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 2);
    insertAtEnd(&list1, 3);

    // List 2: 4 -> 5 -> 6
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 5);
    insertAtEnd(&list2, 6);

    printf("List 1:\n");
    display(list1);

    printf("List 2:\n");
    display(list2);

    // Concatenate
    concatenate(&list1, list2);

    printf("After concatenation:\n");
    display(list1);

    return 0;
}