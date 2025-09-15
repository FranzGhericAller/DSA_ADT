#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#define MAX 10

typedef struct{
    int items[MAX];
    int count;
}List;

typedef struct{
    List list;
    int front;
    int rear;
}Queue;

Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);
int main(void){
    
    Queue* q = initialize();
    int choice, value;
    
    while(1){
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Front\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
    switch(choice){
        case 1: 
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(q, value);
            break;
            
        case 2: 
            value = dequeue(q);
            if(value != -1)
                printf("Dequeued: %d\n", value);
            break;
            
        case 3:
            display(q);
            break;
            
        case 4: 
            value = front(q);
            if(value != -1)
                printf("Front element: %d\n", value);
            break;
        case 5: 
            printf("Exiting program.\n");
            free(q);
            return 0;
        default:
            printf("Invalid choice, try again.\n");
        }
    }
    
}

Queue* initialize(){
    Queue* q = malloc(sizeof(Queue));
    if(q == NULL){
        printf("Memory Allocation failed");
        return NULL;
    }
    q->list.count = 0;
    q->front = -1;
    q->rear = -1;
    
    return q;
}

bool isFull(Queue* q){
    return q->list.count == MAX;
}

bool isEmpty(Queue* q){
    return q->list.count == 0;
}

void enqueue(Queue* q, int value){
    if (isFull(q)){
        printf("The Queue is full");
        return;
    }
    if(isEmpty(q)){
        q->front = 0;
        q->rear = 0;
        
    }else{
        q->rear = (q->rear + 1) % MAX;
    }
    q->list.items[q->rear] = value;
    q->list.count++;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("The Queue is empty");
        return -1;
    }
    int value = q->list.items[q->front];
    
    if(q->list.count == 1){
        q->list.count = -1;
        q->list.count = -1;
    }else{
        q->front = (q->front + 1) % MAX;
    }
    q->list.count--;
    
    return value;
}

int front(Queue* q){
    if(isEmpty(q)){
        printf("The Queue is empty");
        return -1;
    }
    return q->list.items[q->front];
}

void display(Queue* q){
    if(isEmpty(q)){
        printf("The Queue is empty");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    for(int count = 0; count < q->list.count; count++){
        printf("%d", q->list.items[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}
    
