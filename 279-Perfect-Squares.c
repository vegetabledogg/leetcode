int numSquares(int n) {
    int *dp = (int*)malloc(sizeof(int) * (n + 1));
    int i, j, min;
    for(i = 1; i <= n; i++){
        dp[i] = 0;
    }
    for(i = 1; i * i <= n; i++){
        dp[i * i] = 1;
    }
    for(i = 1; i <= n; i++){
        if(0 == dp[i]){
            min = 2147483647;
            for(j = 1; j * j <= i; j++){
                if(dp[i - j * j] + 1 < min){
                    min = dp[i - j * j] + 1;
                }
            }
            dp[i] = min;
        }
    }
    return dp[i - 1];
}
