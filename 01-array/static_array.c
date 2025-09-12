#include <stdio.h>

// Length: real values
// Capacity: memory allocated
#define CAPACITY 5
typedef struct {
    int length;
    int arr[CAPACITY];
} intArr;


void insertEnd(int arr[], int n, int length, int capacity) {
    if (length < capacity) {
        arr[length] = n;
    }
}

void removeEnd(int arr[], int length) {
    if (length > 0) {
        arr[length - 1] = 0;
    }
}

void insertMiddle(int arr[], int i, int n, int length) {
    for (int index = length - 1; index >= i; index--) {
        arr[index + 1] = arr[index];
    }   
    arr[i] = n;
}

void removeMiddle(int arr[], int i, int length) {
    for (int index = i + 1; index < length; index++) {
        arr[index - 1] = arr[index];
    }
    arr[length - 1] = 0;
}

void printArr(int arr[], int capacity) {
    for (int i = 0; i < capacity; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    intArr ia = {
        .arr = {1,2,3,4}, // capacity 5
        .length = 4
    };

    printArr(ia.arr, CAPACITY);

    insertEnd(ia.arr, 5, ia.length, CAPACITY);
    ia.length++;
    printArr(ia.arr, CAPACITY);

    removeEnd(ia.arr, ia.length);
    ia.length--;
    printArr(ia.arr, CAPACITY);

    insertMiddle(ia.arr, 1, 2, ia.length);
    ia.length++;
    printArr(ia.arr, CAPACITY);

    removeMiddle(ia.arr, 1, ia.length);
    ia.length--;
    printArr(ia.arr, CAPACITY);

    insertEnd(ia.arr, 5, ia.length, CAPACITY);
    ia.length++;
    printArr(ia.arr, CAPACITY);

    return 0;
}
