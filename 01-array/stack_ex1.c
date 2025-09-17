// https://leetcode.com/problems/baseball-game
// List of operations given
//      * integer: record score
//      * +: record sum of last 2 scores
//      * D: record double of last score
//      * C: remove last score
// Return the final sum of scores

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArr(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int calPoints(char** operations, int operationsSize) {
    int capacity = operationsSize;
    int length = 0;
    int* points = malloc(capacity*sizeof(int));
    int sum = 0;

    for (int i = 0; i < operationsSize; i++) {
        if (strcmp(operations[i], "C") == 0) {
            sum -= points[--length];
        } else if (strcmp(operations[i], "D") == 0) {
            points[length] = 2*points[length-1];
            sum += points[length++];
        } else if (strcmp(operations[i], "+") == 0) {
            points[length] = points[length-1] + points[length-2];
            sum += points[length++];
        } else {
            points[length] = atoi(operations[i]);
            sum += points[length++];
        }

        printArr(points, length);
    }

    return sum;
}

int main(int argc, char *argv[]) {

    char* ops[] = {"5","-2","4","C","D","9","+","+"}; // final sum 27

    int score_sum = calPoints(ops, 8);
    printf("Sum: %d\n", score_sum);
}
