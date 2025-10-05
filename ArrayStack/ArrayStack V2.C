#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>  
#define MAX 10

typedef struct {
    int items[MAX];
    int top;
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
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to push onto the stack: ");
                scanf("%d", &value);
                push(S, value);
                break;

            case 2:
                value = pop(S);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;

            case 3:
                value = peek(S);
                if (value != -1) {
                    printf("Top value of the stack: %d\n", value);
                }
                break;

            case 4:
                display(S);
                break;

            case 5:
                printf("Exiting the program.\n");
                free(S);  
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

Stack* initialize() {
    Stack* s = (Stack*)malloc(sizeof(Stack));  
    s->top = MAX; // start from MAX (empty)
    return s;
}

bool isFull(Stack* s) {
    return s->top == 0;
}

bool isEmpty(Stack* s) {
    return s->top == MAX;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack is full, cannot push %d\n", value);
        return;
    }
    s->items[--s->top] = value;
    printf("Pushed %d onto the stack\n", value);
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty, cannot pop\n");
        return -1;
    }
    int poppedValue = s->items[s->top++];
    return poppedValue;
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty, cannot peek\n");
        return -1;
    }
    return s->items[s->top];
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (top to bottom):\n");
    for (int i = s->top; i < MAX; i++) {
        printf("%d\n", s->items[i]);
    }
}
