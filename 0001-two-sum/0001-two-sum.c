#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {

            if (nums[i] + nums[j] == target) {

                int* ans = (int*)malloc(2 * sizeof(int));
                ans[0] = i;
                ans[1] = j;

                return ans;
            }
        }
    }

    return NULL;
}