// https://leetcode.com/problems/baseball-game
// List of operations given
//      * integer: record score
//      * +: record sum of last 2 scores
//      * D: record double of last score
//      * C: remove last score
// Return the final sum of scores

#include <stdio.h>
#include <stdlib.h>

#include "dynamic_array.h"

int calPoints(char* operations, int operationsSize) {
    DynArr *points = da_initialize(4);
    int sum = 0;
    for (int i = 0; i < operationsSize; i++) {
        switch (operations[i]) {
            case 'C':
                da_pop(points);
                break;
            case 'D':
                da_push(points, 2*da_get(points, points->length-1));
                break;
            case '+':
                da_push(points, da_get(points, points->length-1)+da_get(points, points->length-2));
                break;
            default:
                da_push(points, operations[i]-'0'); // 'num'-'0' = ASCII diff = num itself
                break;
        }
    }

    for (int i = 0; i < points->length; i++) {
        sum += da_get(points, i);
    }

    return sum;
}

int main(int argc, char *argv[]) {

    char ops[] = {'5','2','C','D','+'}; // final [5, 10, 15] = sum 30

    int score_sum = calPoints(ops, 5);
    printf("Sum: %d\n", score_sum);
}
