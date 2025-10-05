#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue* initialize();
bool isEmpty(Queue* q);
bool isFull(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int frontValue(Queue* q);
void display(Queue* q);

int main() {
    Queue* q = initialize();
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
                enqueue(q, value);
                break;
            case 2:
                value = dequeue(q);
                if (value != -1)
                    printf("Dequeued: %d\n", value);
                break;
            case 3:
                display(q);
                break;
            case 4:
                value = frontValue(q);
                if (value != -1)
                    printf("Front element: %d\n", value);
                break;
            case 5:
                printf("Exiting program.\n");
                free(q);
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
        printf("Memory allocation failed\n");
        exit(1);
    }
    q->front = 1;
    q->rear = 0;
    return q;
}

bool isEmpty(Queue* q) {
    return q->front == (q->rear + 1) % MAX;
}

bool isFull(Queue* q) {
    return q->front == (q->rear + 2) % MAX;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    return value;
}

int frontValue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No front element.\n");
        return -1;
    }
    return q->items[q->front];
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = q->front;
    while (i != (q->rear + 1) % MAX) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}
