#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // points to itself initially
    return newNode;
}

// Insert at end in circular linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    // If list is empty
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    // Traverse to last node
    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head;
}

// Display circular list
void display(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

// Concatenate two circular linked lists
void concatenate(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }
    if (*head2 == NULL) return;

    struct Node* temp1 = *head1;
    struct Node* temp2 = *head2;

    // Find last node of both lists
    while (temp1->next != *head1)
        temp1 = temp1->next;

    while (temp2->next != *head2)
        temp2 = temp2->next;

    // Connect them
    temp1->next = *head2;
    temp2->next = *head1;
}

// Main
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
    concatenate(&list1, &list2);

    printf("After concatenation:\n");
    display(list1);

    return 0;
}