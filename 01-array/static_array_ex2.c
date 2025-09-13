/* Problems
 * https://leetcode.com/problems/remove-element/
 * array and a value given
 * remove all occurrences of value in array in place
 * return number of elements left
 * constraints:
 *      0 <= nums.length <= 100
 *      0 <= nums[i] <= 50      
 *      0 <= val <= 100
 */

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int notVal = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[notVal++] = nums[i];
        }
    }

    return notVal;
}

void printArr(int *arr, int length) {
    for (int i=0; i<length; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int nums[] = {3,2,2,3};
    int k = removeElement(nums, 4, 3);
    printf("%d\n", k);
    printArr(nums, k);
}   
