/* Problems
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * sorted array given with repetition
 * return the number of unique elements
 * remove the duplicates in place
 * constraints:
 *      1 <= nums.length <= 3 * 104
 *      -100 <= nums[i] <= 100
 *      nums is sorted in non-decreasing order.
 */

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int uniq;

    for (int i = 0; i < numsSize; i++) {
        if ( i == 0 || nums[i] != nums[i-1]) {
            nums[uniq] = nums[i];
            uniq++;
        }
    }

    return uniq;
}

void printArr(int *arr, int length) {
    for (int i=0; i<length; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int nums[] = {1,1,2,2,3,3};
    int k = removeDuplicates(nums, 6);
    printf("%d\n", k);
    printArr(nums, k);
}   
