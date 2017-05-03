int nthUglyNumber(int n) {
    int *dp = (int*)malloc(sizeof(int) * n);
    int min, i, j;
    if(n < 7){
        return n;
    }
    for(i = 0; i < 6; i++){
        dp[i] = i + 1;
    }
    for(i = 6; i < n; i++){
        min = 2147483647;
        for(j = i - 2; j >= 0; j--){
            if(dp[j] * 2 > 0){
                if(dp[j] * 2 > dp[i - 1]){
                    if(dp[j] * 2 < min){
                        min = dp[j] * 2;
                    }
                }
                else if(dp[j] * 3 > 0){
                    if(dp[j] * 3 > dp[i - 1]){
                        if(dp[j] * 3 < min){
                            min = dp[j] * 3;
                        }
                    }
                    else if(dp[j] * 5 > 0){
                        if(dp[j] * 5 > dp[i - 1]){
                            if(dp[j] * 5 < min){
                                min = dp[j] * 5;
                            }
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
        dp[i] = min;
    }
    return dp[i - 1];
}
