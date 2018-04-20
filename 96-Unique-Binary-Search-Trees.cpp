class Solution {
public:
    int numTrees(int n) {
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return 1;
        }
        int sum = 0;
        for(int i = 1; i <= n / 2; i++){
            sum += numTrees(i - 1) * numTrees(n - i);
        }
        sum *= 2;
        if(n % 2 == 1){
            sum += numTrees(n / 2 + 1 - 1) * numTrees(n - n / 2 - 1);
        }
        return sum;
    }
};

