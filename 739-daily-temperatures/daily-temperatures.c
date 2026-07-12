/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int *ans = (int *)calloc(temperaturesSize, sizeof(int));
    int *stack = (int *)malloc(temperaturesSize * sizeof(int));
    int top = -1;

    *returnSize = temperaturesSize;

    for (int i = 0; i < temperaturesSize; i++) {
        while (top != -1 && temperatures[i] > temperatures[stack[top]]) {
            int idx = stack[top--];
            ans[idx] = i - idx;
        }
        stack[++top] = i;
    }

    free(stack);
    return ans;
}