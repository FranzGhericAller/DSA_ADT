#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#define MAX log10

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

int main(){
    
    return 0;
}

Queue* initialize(){
    Queue* q = malloc(sizeof(Queue));
    if(q = NULL){
        printf("Memory Allocation failed");
        return NULL;
    }
    q->count = 0;
    q->front = -1;
    q->rear = -1;
    
    return q;
}

bool isFull(Queue* q){
    return q->count == MAX;
}

bool isEmpty(Queue* q){
    return q->count == 0;
}

void enqueue(Queue* q, int value){
    if (isFull(q)){
        printf("The Queue is full");
        return;
    }
    if(q->count == 0){
        q->front = 0;
        q->rear = 0;
        
    }else{
        q->rear = (q->rear + 1) % MAX;
    }
    q->data[q->rear] = value;
    q->count++;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("The Queue is empty");
        return -1;
    }
    int value - q->data[q->front];
    
    if(q->count == 1){
        q->count = -1;
        q->count = -1;
    }else{
        q->front = (q->front + 1) % MAX;
    }
    q->count--;
    
    return value;
}

int front(Queue* q){
    if(isEmpty(q)){
        printf("The Queue is empty");
        return q->front;
    }
}

void display(Queue* q){
    if(isEmpty(q)){
        printf("The Queue is empty");
    }
    for()
}
    
