// https://leetcode.com/problems/concatenation-of-array/
// Concatenate given array 2 times
// Constraints:
//     n == nums.length
//     1 <= n <= 1000
//     1 <= nums[i] <= 1000

#include <stdio.h>
#include <stdlib.h>

int* getConcatenation(int* nums, int numsSize/*, int* returnSize*/) {
    int *ans = (int *)malloc(2*numsSize*sizeof(int));

    for (int i=0; i<numsSize; i++) {
        ans[i] = nums[i];
        ans[i+numsSize] = nums[i];
    }

    return ans;
}

void printArr(int *arr, int length) {
    for (int i=0; i<length; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int nums[] = {1,3,2,1};
    int *concat = getConcatenation(nums, 4);
    printArr(concat, 8);
}
