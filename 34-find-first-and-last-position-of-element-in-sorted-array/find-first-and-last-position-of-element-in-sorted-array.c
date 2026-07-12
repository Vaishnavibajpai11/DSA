/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *ans = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;
    ans[0] = ans[1] = -1;

    int left = 0, right = numsSize - 1;

    // Find first occurrence
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] >= target)
            right = mid - 1;
        else
            left = mid + 1;

        if (nums[mid] == target)
            ans[0] = mid;
    }

    left = 0;
    right = numsSize - 1;

    // Find last occurrence
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] <= target)
            left = mid + 1;
        else
            right = mid - 1;

        if (nums[mid] == target)
            ans[1] = mid;
    }

    return ans;
}