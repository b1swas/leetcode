#include <stdio.h>

// Length: real values
// Capacity: memory allocated
#define CAPACITY 5
typedef struct {
    int length;
    int arr[CAPACITY];
} intArr;


void insertEnd(intArr *ia, int n) {
    if (ia->length < CAPACITY) {
        ia->arr[ia->length++] = n; // post-increment: return then increase
    } else {
        printf("Oops, list capacity is full!.\n");
    }
}

void removeEnd(intArr *ia) {
    if (ia->length > 0) {
        ia->arr[--ia->length] = 0; // pre-decrement: decrease then return
    } else {
        printf("Oops, list is empty!.\n");
    }
}

void insertMiddle(intArr *ia, int i, int n) {
    if (ia->length >= CAPACITY || i < 0 || i > ia->length) {
        printf("InsertMiddle Error: either list full or index out of bounds\n");
        return;
    }

    for (int index = ia->length++; index > i; index--) {
        ia->arr[index] = ia->arr[index-1];
    }   
    ia->arr[i] = n;
}

void removeMiddle(intArr *ia, int i) {
    if (ia->length == 0 || i < 0 || i >= ia->length ) {
        printf("RemoveMiddle Error: either list is empty or index out of bounds\n");
        return;
    }

    for (int index = i + 1; index < ia->length; index++) {
        ia->arr[index - 1] = ia->arr[index];
    }
    ia->arr[--ia->length] = 0;
}

void printArr(intArr *ia) {
    for (int i = 0; i < CAPACITY; i++) {
        if (i < ia->length) {
            printf("%d ", ia->arr[i]);
        } else {
            printf("_");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    intArr ia = {
        .arr = {1,2,3,4}, // capacity 5
        .length = 4
    };

    printArr(&ia);

    insertEnd(&ia, 5);
    printArr(&ia);

    removeEnd(&ia);
    printArr(&ia);

    insertMiddle(&ia, 1, 2);
    printArr(&ia);

    removeMiddle(&ia, 1);
    printArr(&ia);

    insertEnd(&ia, 5);
    printArr(&ia);

    return 0;
}
