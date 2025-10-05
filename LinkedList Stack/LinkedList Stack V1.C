#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

int main() {
    Stack* S = initialize();
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(S, value);
                break;

            case 2:
                value = pop(S);
                if (value != -1)
                    printf("Popped: %d\n", value);
                break;

            case 3:
                value = peek(S);
                if (value != -1)
                    printf("Top element: %d\n", value);
                break;

            case 4:
                display(S);
                break;

            case 5:
                printf("Exiting program.\n");
                while (!isEmpty(S)) pop(S);
                free(S);
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

Stack* initialize() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    s->top = NULL;
    return s;
}

bool isFull(Stack* s) {
    return false;
}

bool isEmpty(Stack* s) {
    return s->top == NULL;
}

void push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot push.\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;  // link to old top
    s->top = newNode;        // update top
    printf("Pushed %d onto the stack.\n", value);
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    Node* temp = s->top;
    int value = temp->data;
    s->top = s->top->next;  
    free(temp);            
    return value;
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Nothing to peek.\n");
        return -1;
    }
    return s->top->data;
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    Node* current = s->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
