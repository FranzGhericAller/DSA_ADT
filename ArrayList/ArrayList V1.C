#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

// Function declarations
List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
List display(List L);

// Main function
int main() {
    List L;

    // Initialize list
    L = initialize(L);

    // Insert some values
    L = insertPos(L, 5, 0);         // Insert 5 at position 0
    L = insertPos(L, 10, 1);        // Insert 10 at position 1
    L = insertPos(L, 7, 1);         // Insert 7 at position 1
    L = insertSorted(L, 3);         // Insert 3 in sorted order
    L = insertSorted(L, 12);        // Insert 12 in sorted order

    // Display list
    printf("List after insertions: ");
    display(L);

    // Delete a value at position 2
    L = deletePos(L, 2);
    printf("List after deleting position 2: ");
    display(L);

    // Locate a value
    int index = locate(L, 10);
    if (index != -1)
        printf("10 found at index %d\n", index);
    else
        printf("10 not found\n");

    return 0;
}

// Function Definitions

List initialize(List L) {
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position) {
    if (position <= L.count && L.count < MAX) {
        for (int i = L.count; i > position; i--) {
            L.elem[i] = L.elem[i - 1];
        }
        L.elem[position] = data;
        L.count++;
    }
    return L;
}

List deletePos(List L, int position) {
    if (position < L.count && position >= 0) {
        for (int i = position; i < L.count - 1; i++) {
            L.elem[i] = L.elem[i + 1];
        }
        L.count--;
    }
    return L;
}

int locate(List L, int data) {
    for (int i = 0; i < L.count; i++) {
        if (L.elem[i] == data) return i;
    }
    return -1;
}

List insertSorted(List L, int data) {
    if (L.count < MAX) {
        int i = L.count - 1;
        while (i >= 0 && L.elem[i] > data) {
            L.elem[i + 1] = L.elem[i];
            i--;
        }
        L.elem[i + 1] = data;
        L.count++;
    }
    return L;
}

List display(List L) {
    for (int i = 0; i < L.count; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
    return L;
}
