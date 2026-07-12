/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int *ans = (int *)malloc(numsSize * sizeof(int));
    int *stack = (int *)malloc(numsSize * sizeof(int));
    int top = -1;

    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++)
        ans[i] = -1;

    for (int i = 0; i < 2 * numsSize; i++) {
        int idx = i % numsSize;

        while (top != -1 && nums[idx] > nums[stack[top]]) {
            ans[stack[top]] = nums[idx];
            top--;
        }

        if (i < numsSize)
            stack[++top] = idx;
    }

    free(stack);
    return ans;
}