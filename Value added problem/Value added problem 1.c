#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// Print nodes in given range using DFS
void printInRange(struct Node* root, int low, int high) {
    if (root == NULL)
        return;

    // If current node is greater than low, explore left
    if (root->data > low)
        printInRange(root->left, low, high);

    // If current node is in range, print it
    if (root->data >= low && root->data <= high)
        printf("%d ", root->data);

    // If current node is less than high, explore right
    if (root->data < high)
        printInRange(root->right, low, high);
}

int main() {
    // Print Name and PRN
    printf("NUPUR MEHAR\n");
    printf("PRN: 25070521110\n\n");

    struct Node* root = NULL;

    // Example BST
    root = insert(root, 17);
    root = insert(root, 4);
    root = insert(root, 18);
    root = insert(root, 2);
    root = insert(root, 9);

    int low = 4, high = 24;

    printf("Nodes in range [%d, %d]:\n", low, high);
    printInRange(root, low, high);

    return 0;
}