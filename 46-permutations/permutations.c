
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void backtrack(int *nums, int start, int n,
               int **result, int *returnSize, int *returnColumnSizes) {
    
    if (start == n) {
        result[*returnSize] = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            result[*returnSize][i] = nums[i];
        }

        returnColumnSizes[*returnSize] = n;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < n; i++) {
        swap(&nums[start], &nums[i]);

        backtrack(nums, start + 1, n,
                  result, returnSize, returnColumnSizes);

        swap(&nums[start], &nums[i]);
    }
}

int** permute(int* nums, int numsSize,
              int* returnSize, int** returnColumnSizes) {
    
    int total = 1;

    // Calculate n!
    for (int i = 1; i <= numsSize; i++) {
        total *= i;
    }

    int **result = malloc(total * sizeof(int *));
    *returnColumnSizes = malloc(total * sizeof(int));

    *returnSize = 0;

    backtrack(nums, 0, numsSize,
              result, returnSize, *returnColumnSizes);

    return result;
}