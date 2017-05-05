/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
    int i = 0, j;
    *returnSize = num + 1;
    int *dp = (int*)malloc((num + 1) * sizeof(int));
    dp[0] = 0;
    do{
        for(j = 0; j <= i && i + j + 1 <= num; j++){
            dp[i + j + 1] = dp[j] + 1; 
        }
        i = i * 2 + 1;
    }while(i <= num);
    return dp;
}
