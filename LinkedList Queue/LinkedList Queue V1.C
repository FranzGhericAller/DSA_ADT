#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int frontValue(Queue* q);
void display(Queue* q);

int main() {
    Queue* Q = initialize();
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Front\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(Q, value);
                break;

            case 2:
                value = dequeue(Q);
                if (value != -1)
                    printf("Dequeued: %d\n", value);
                break;

            case 3:
                display(Q);
                break;

            case 4:
                value = frontValue(Q);
                if (value != -1)
                    printf("Front element: %d\n", value);
                break;

            case 5:
                printf("Exiting program.\n");
                // free remaining nodes
                while (!isEmpty(Q)) dequeue(Q);
                free(Q);
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isFull(Queue* q) {
    return false; // Linked list queue never full unless malloc fails
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot enqueue.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        // first element
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("Enqueued %d\n", value);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    Node* temp = q->front;
    int value = temp->data;

    q->front = q->front->next;
    if (q->front == NULL) {
        // Queue became empty
        q->rear = NULL;
    }

    free(temp);
    return value;
}

int frontValue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No front element.\n");
        return -1;
    }
    return q->front->data;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    Node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

