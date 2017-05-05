comp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int coinChange(int* coins, int coinsSize, int amount) {
    if(0 == amount){
        return 0;
    }
    int i, j, min;
    int *dp = (int*)malloc((amount + 1) * sizeof(int));
    for(i = 1; i <= amount; i++){
        dp[i] = 0;
    }
    qsort(coins, coinsSize, sizeof(int), comp);
    for(i = 0; i < coinsSize && coins[i] <= amount; i++){
        dp[coins[i]] = 1;
    }
    for(i = 1; i <= amount; i++){
        if(dp[i] == 0){
            min = 2147483647;
            for(j = 0; j < coinsSize; j++){
                if(i > coins[j] && dp[i - coins[j]] != 0 && dp[i - coins[j]] + 1 < min){
                    min = dp[i - coins[j]] + 1;
                    dp[i] = min;
                }
            }
        }
    }
    return dp[amount] > 0 ? dp[amount] : -1;
}
