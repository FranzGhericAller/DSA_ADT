#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

void initialize(List* L);
void insertPos(List* L, int data, int position);
void deletePos(List* L, int position);
int locate(List* L, int data);
void insertSorted(List* L, int data);
void display(List* L);

int main() {
    List L;

    initialize(&L);

     insertPos(&L, 5, 0);         
     insertPos(&L, 10, 1);        
     insertPos(&L, 7, 1);         
     insertSorted(&L, 3);         
     insertSorted(&L, 12);        
   
    printf("List after insertions: ");
    display(&L);

    deletePos(&L, 2);
    printf("List after deleting position 2: ");
    display(&L);

    int index = locate(&L, 10);
    if (index != -1)
        printf("10 found at index %d\n", index);
    else
        printf("10 not found\n");

    return 0;
}

void initialize(List* L) {
    L->count = 0;
}

void insertPos(List* L, int data, int position) {
    if (position <= L->count && L->count < MAX) {
        for (int i = L->count; i > position; i--) {
            L->elem[i] = L->elem[i - 1];
        }
        L->elem[position] = data;
        L->count++;
    }
}


void deletePos(List* L, int position) {
    if (position < L->count && position >= 0) {
        for (int i = position; i < L->count - 1; i++) {
            L->elem[i] = L->elem[i + 1];
        }
        L->count--;
    }
}

int locate(List* L, int data) {
    for (int i = 0; i < L->count; i++) {
        if (L->elem[i] == data) return i;
    }
    return -1;
}
void insertSorted(List* L, int data) {
    if (L->count < MAX) {
        int i = L->count - 1;
        while (i >= 0 && L->elem[i] > data) {
            L->elem[i + 1] = L->elem[i];
            i--;
        }
        L->elem[i + 1] = data;
        L->count++;
    }
}

void display(List* L) {
    for (int i = 0; i < L->count; i++) {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
    }

