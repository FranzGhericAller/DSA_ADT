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

int main() {
    List L;
    int choice, data, position, index, n;

    // Initialize list
    L = initialize(L);

    printf("Enter number of elements to insert (max %d): ", MAX);
    scanf("%d", &n);
    if (n > MAX) n = MAX;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &data);
        // Insert elements in sorted order
        L = insertSorted(L, data);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at position\n");
        printf("2. Insert sorted\n");
        printf("3. Delete at position\n");
        printf("4. Locate element\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (L.count >= MAX) {
                    printf("List is full, cannot insert.\n");
                    break;
                }
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position (0 to %d): ", L.count);
                scanf("%d", &position);
                if (position < 0 || position > L.count) {
                    printf("Invalid position.\n");
                } else {
                    L = insertPos(L, data, position);
                    printf("Inserted %d at position %d.\n", data, position);
                }
                break;
            case 2:
                if (L.count >= MAX) {
                    printf("List is full, cannot insert.\n");
                    break;
                }
                printf("Enter data to insert in sorted order: ");
                scanf("%d", &data);
                L = insertSorted(L, data);
                printf("Inserted %d in sorted order.\n", data);
                break;
            case 3:
                if (L.count == 0) {
                    printf("List is empty, nothing to delete.\n");
                    break;
                }
                printf("Enter position to delete (0 to %d): ", L.count - 1);
                scanf("%d", &position);
                if (position < 0 || position >= L.count) {
                    printf("Invalid position.\n");
                } else {
                    data = L.elem[position];
                    L = deletePos(L, position);
                    printf("Deleted element %d at position %d.\n", data, position);
                }
                break;
            case 4:
                if (L.count == 0) {
                    printf("List is empty.\n");
                    break;
                }
                printf("Enter data to locate: ");
                scanf("%d", &data);
                index = locate(L, data);
                if (index != -1)
                    printf("%d found at index %d.\n", data, index);
                else
                    printf("%d not found in the list.\n", data);
                break;
            case 5:
                if (L.count == 0) {
                    printf("List is empty.\n");
                } else {
                    printf("Current list: ");
                    display(L);
                }
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
