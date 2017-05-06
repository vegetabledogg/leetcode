/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int comp(const int *a, const int *b){
     return *(int*)a - *(int*)b;
 }
int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    if(numsSize == 0){
        *returnSize = 0;
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), comp);
    int *dp = (int*)malloc(numsSize * sizeof(int));
    int i, j, index = 0;
    *returnSize = 0;
    for(i = 0; i < numsSize; i++){
        dp[i] = 1;
        for(j = 0; j < i; j++){
            if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
        if(*returnSize < dp[i]){
            *returnSize = dp[i];
            index = i;
        }
    }
    int *result = (int*)malloc(*returnSize * sizeof(int));
    j = *returnSize - 1;
    result[j--] = nums[index];
    for(i = index - 1; i >= 0; i--){
        if(nums[index] % nums[i] == 0 && dp[index] - 1 == dp[i]){
            index = i;
            result[j] = nums[i];
            j--;
        }
    }
    return result;
}
