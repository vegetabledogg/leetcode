int numDecodings(char* s) {
    int i;
    int length = strlen(s);
    int *dp = (int*)malloc(sizeof(int) * length);
    if(length == 0 || s[0] == '0'){
        return 0;
    }
    for(i = 0; i < length; i++){
        if(0 == i){
            dp[i] = 1;
        }
        else if(1 == i){
            if(s[1] != '0'){
                if(s[0] == '1' || s[0] == '2' && s[1] < '7'){
                    dp[i] = 2;
                }
                else{
                    dp[i] = 1;
                }
            }
            else{
                if(s[0] < '3' && s[0] > '0'){
                    dp[i] = 1;
                }
                else{
                    return 0;
                }
            }
        }
        else{
            if(s[i] != '0'){
                if(s[i - 1] == '1' || s[i - 1] == '2' && s[i] < '7'){
                    dp[i] = dp[i - 1] + dp[i - 2];
                }
                else{
                    dp[i] = dp[i - 1];
                }
            }
            else{
                if(s[i - 1] < '3' && s[i - 1] > '0'){
                    dp[i] = dp[i - 2];
                }
                else{
                    return 0;
                }
            }
        }
    }
    return dp[length - 1];
}
