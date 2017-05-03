int lengthOfLIS(int* nums, int numsSize) {
    int *dp = (int*)malloc(sizeof(int) * numsSize);
    int i, j, max;
    for(i = 0; i < numsSize; i++){
        max = 1;
        for(j = 0; j < i; j++){
            if(nums[j] < nums[i] && dp[j] + 1 > max){
                max = dp[j] + 1;
            }
        }
        dp[i] = max;
    }
    max = dp[0];
    for(i = 0; i < numsSize; i++){
        if(max < dp[i]){
            max = dp[i];
        }
    }
    return max;
}
