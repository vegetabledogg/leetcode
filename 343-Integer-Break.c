int integerBreak(int n) {
    int i, j, max;
    int *dp = (int*)malloc((n + 1) * sizeof(int));
    dp[1] = 1;
    for(i = 2; i < n; i++){
        max = i;
        for(j = 1; j <= i - j; j++){
            if(dp[j] * dp[i - j] > max){
                max = dp[j] * dp[i - j];
            }
        }
        dp[i] = max;
    }
    max = 0;
    for(j = 1; j <= n - j; j++){
        if(dp[j] * dp[n - j] > max){
            max = dp[j] * dp[n - j];
        }
    }
    return max;
}
