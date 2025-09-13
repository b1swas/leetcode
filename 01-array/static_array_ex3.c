/* Problems
 * https://leetcode.com/problems/shuffle-the-array
 * Given 2n elements: [x1,x2,...,xn,y1,y2,...,yn]
 * Return: [x1,y1,x2,y2,...,xn,yn]
 * constraints:
 *      1 <= n <= 500        
 *      nums.length == 2n    
 *      1 <= nums[i] <= 10^3 
 */

#include <stdio.h>
#include <stdlib.h>

int* shuffle(int* nums, int numsSize, int n/*,int* returnSize*/){
    int* shuffled = malloc(sizeof(int)*numsSize);
    int endIndex = 0;

    for(int i=0, j=n; i<n; i++, j++) {
        shuffled[endIndex++] = nums[i];
        shuffled[endIndex++] = nums[j];
    }

    return shuffled;
}

void printArr(int *arr, int length) {
    for (int i=0; i<length; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int nums[] = {2,5,1,3,4,7};
    int* shuffled = shuffle(nums, 6, 3);
    printArr(shuffled, 6);
    free(shuffled);
}   
