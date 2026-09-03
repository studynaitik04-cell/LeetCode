#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* nums, int numsSize,
               int* used, int* current,
               int depth, int** result,
               int* returnSize) {

    // Complete permutation
    if (depth == numsSize) {
        result[*returnSize] =
            (int*)malloc(numsSize * sizeof(int));

        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = current[i];
        }

        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {

        // Already used in current permutation
        if (used[i])
            continue;

        // Skip duplicate choices
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            continue;

        // Choose
        used[i] = 1;
        current[depth] = nums[i];

        // Explore
        backtrack(nums, numsSize, used,
                  current, depth + 1,
                  result, returnSize);

        // Backtrack
        used[i] = 0;
    }
}

int** permuteUnique(int* nums, int numsSize,
                    int* returnSize,
                    int** returnColumnSizes) {

    *returnSize = 0;

    qsort(nums, numsSize, sizeof(int), compare);

    int total = 1;

    for (int i = 2; i <= numsSize; i++)
        total *= i;

    int** result =
        (int**)malloc(total * sizeof(int*));

    *returnColumnSizes =
        (int*)malloc(total * sizeof(int));

    for (int i = 0; i < total; i++)
        (*returnColumnSizes)[i] = numsSize;

    int* used =
        (int*)calloc(numsSize, sizeof(int));

    int* current =
        (int*)malloc(numsSize * sizeof(int));

    backtrack(nums, numsSize, used,
              current, 0, result, returnSize);

    free(used);
    free(current);

    return result;
}