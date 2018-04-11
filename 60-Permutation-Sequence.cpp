class Solution {
public:
    long long fac(int n){
        int ret = 1;
        while(n > 1){
            ret *= n;
            n--;
        }
        return ret;
    }
    string getPermutation(int n, int k) {
        long long total = fac(n);
        vector<int> left;
        string ans;
        int length, temp, digit;
        
        for(int i = 1; i <= n; i++){
            left.push_back(i);
        }
        for(int i = n; i > 0; i--){
            total /= i;
            temp = k / total;
            if(k != temp * total){
                digit = left[temp];
                left.erase(left.begin() + temp);
            }
            else{
                digit = left[temp - 1];
                left.erase(left.begin() + temp - 1);
            }
            ans = ans + to_string(digit);
            if(k != temp * total){
                k -= temp * total;
            }
            else{
                k -= (temp - 1) * total;
            }
        }
        return ans;
    }
};

