#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

// Function declarations
void initialize(List* L);
void insertPos(List* L, int data, int position);
void deletePos(List* L, int position);
int locate(List* L, int data);
void insertSorted(List* L, int data);
void display(List* L);

int main() {
    List L;
    int choice, data, position;

    initialize(&L);

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Position\n");
        printf("2. Insert in Sorted Order\n");
        printf("3. Delete at Position\n");
        printf("4. Locate an Element\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (L.count >= MAX) {
                    printf("List is full. Cannot insert.\n");
                    break;
                }
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position (0 to %d): ", L.count);
                scanf("%d", &position);
                if (position < 0 || position > L.count) {
                    printf("Invalid position.\n");
                } else {
                    insertPos(&L, data, position);
                    printf("Inserted %d at position %d.\n", data, position);
                }
                break;

            case 2:
                if (L.count >= MAX) {
                    printf("List is full. Cannot insert.\n");
                    break;
                }
                printf("Enter data to insert in sorted order: ");
                scanf("%d", &data);
                insertSorted(&L, data);
                printf("Inserted %d in sorted order.\n", data);
                break;

            case 3:
                if (L.count == 0) {
                    printf("List is empty. Nothing to delete.\n");
                    break;
                }
                printf("Enter position to delete (0 to %d): ", L.count - 1);
                scanf("%d", &position);
                if (position < 0 || position >= L.count) {
                    printf("Invalid position.\n");
                } else {
                    printf("Deleted element %d from position %d.\n", L.elem[position], position);
                    deletePos(&L, position);
                }
                break;

            case 4:
                printf("Enter element to search: ");
                scanf("%d", &data);
                position = locate(&L, data);
                if (position != -1)
                    printf("Element %d found at index %d.\n", data, position);
                else
                    printf("Element %d not found in the list.\n", data);
                break;

            case 5:
                printf("List contents: ");
                display(&L);
                break;

            case 6:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// Initialize the list
void initialize(List* L) {
    L->count = 0;
}

// Insert at a specific position
void insertPos(List* L, int data, int position) {
    if (position <= L->count && L->count < MAX) {
        for (int i = L->count; i > position; i--) {
            L->elem[i] = L->elem[i - 1];
        }
        L->elem[position] = data;
        L->count++;
    }
}

// Delete at a specific position
void deletePos(List* L, int position) {
    if (position >= 0 && position < L->count) {
        for (int i = position; i < L->count - 1; i++) {
            L->elem[i] = L->elem[i + 1];
        }
        L->count--;
    }
}

// Locate an element
int locate(List* L, int data) {
    for (int i = 0; i < L->count; i++) {
        if (L->elem[i] == data)
            return i;
    }
    return -1;
}

// Insert in sorted order
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

// Display the list
void display(List* L) {
    if (L->count == 0) {
        printf("List is empty.\n");
        return;
    }
    for (int i = 0; i < L->count; i++) {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}
