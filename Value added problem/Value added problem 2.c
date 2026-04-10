#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack implementation
char stack[MAX];
int top = -1;

// Push operation
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

// Pop operation
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

// Check if matching pair
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

// Function to check balanced brackets
int isBalanced(char exp[]) {
    for (int i = 0; i < strlen(exp); i++) {
        char ch = exp[i];

        // If opening bracket → push
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        // If closing bracket → check
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1)
                return 0;

            char popped = pop();
            if (!isMatchingPair(popped, ch))
                return 0;
        }
    }
    return (top == -1);
}

int main() {
    // Print Name and PRN
    printf("NUPUR MEHAR\n");
    printf("PRN: 25070521110\n\n");

    char exp[MAX];

    printf("Enter expression: ");
    scanf("%s", exp);

    if (isBalanced(exp))
        printf("Output: true (Balanced)\n");
    else
        printf("Output: false (Not Balanced)\n");

    return 0;
}