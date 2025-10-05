#include <stdio.h>
#include <stdlib.h>
#define LENGTH 4   

typedef struct {
    int *elem;
    int count;
    int max;
} List;

void initialize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
int retrieve(List *L, int position);
void insertSorted(List *L, int data);
void display(List *L);
void resize(List *L);
void makeNULL(List *L);

int main() {
    List L;
    initialize(&L);

    insertPos(&L, 1, 0);
    insertPos(&L, 3, 1);
    insertPos(&L, 2, 2);
    insertPos(&L, 5, 3);

    printf("Before insertPos(4,2):\n");
    display(&L);

    insertPos(&L, 4, 2);

    printf("After insertPos(4,2):\n");
    display(&L);

    deletePos(&L, 1);
    printf("After deletePos(1):\n");
    display(&L);

    printf("Locate 5: %d\n", locate(&L, 5));
    printf("Retrieve pos 2: %d\n", retrieve(&L, 2));

    printf("Before insertSorted(8):\n");
    display(&L);
    insertSorted(&L, 8);
    printf("After insertSorted(8):\n");
    display(&L);

    makeNULL(&L);
    return 0;
}



void initialize(List *L) {
    L->elem = (int *)malloc(sizeof(int) * LENGTH);
    if (L->elem == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    L->max = LENGTH;
    L->count = 0;
}

void resize(List *L) {
    L->max *= 2;
    int *temp = realloc(L->elem, sizeof(int) * L->max);
    if (temp == NULL) {
        printf("Reallocation failed!\n");
        exit(1);
    }
    L->elem = temp;
    printf("Resized: new max = %d\n", L->max);
}

void insertPos(List *L, int data, int position) {
    if (position < 0 || position > L->count) {
        printf("Invalid position!\n");
        return;
    }

    if (L->count >= L->max) {
        resize(L);
    }

    for (int i = L->count; i > position; i--) {
        L->elem[i] = L->elem[i - 1];
    }

    L->elem[position] = data;
    L->count++;
}

void deletePos(List *L, int position) {
    if (position < 0 || position >= L->count) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = position; i < L->count - 1; i++) {
        L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}

int locate(List *L, int data) {
    for (int i = 0; i < L->count; i++) {
        if (L->elem[i] == data)
            return i;
    }
    return -1;
}

int retrieve(List *L, int position) {
    if (position < 0 || position >= L->count) {
        printf("Invalid position!\n");
        return -1;
    }
    return L->elem[position];
}

void insertSorted(List *L, int data) {
    if (L->count >= L->max) {
        resize(L);
    }

    int i = L->count - 1;
    while (i >= 0 && L->elem[i] > data) {
        L->elem[i + 1] = L->elem[i];
        i--;
    }
    L->elem[i + 1] = data;
    L->count++;
}

void display(List *L) {
    printf("List: [ ");
    for (int i = 0; i < L->count; i++) {
        printf("%d ", L->elem[i]);
    }
    printf("] count: %d, max: %d\n", L->count, L->max);
}

void makeNULL(List *L) {
    free(L->elem);
    L->elem = NULL;
    L->count = 0;
    L->max = 0;
    printf("List cleared.\n");
}

