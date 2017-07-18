class Solution {
public:
    string longestPalindrome(string s) {
        int max = 0, i, j, length = s.size();
        string maxString = "";
        if(length == 0){
            return maxString;
        }
        for(i = 0; i < length; i++){
            for(j = 1; i - j >= 0 && i + j < length; j++){
                if(s[i - j] != s[i + j]){
                    break;
                }
            }
            if(max < j * 2 - 1){
                max = j * 2 - 1;
                maxString = s.substr(i - j + 1, max);
            }
        }
        for(i = 0; i < length - 1; i++){
            if(s[i] == s[i + 1]){
                for(j = 1; i - j >= 0 && i + 1 + j < length; j++){
                    if(s[i - j] != s[i + 1 + j]){
                        break;
                    }
                }
                if(max < j * 2){
                    max = j * 2;
                    maxString = s.substr(i - j + 1, max);
                }
            }
        }
        return maxString;
    }
};

/*
 * Manacher's Algorithm
 */
class Solution {
public:
    string longestPalindrome(string s) {
        string str = "#";
        int length = s.size(), i, j;
        for(i = 0; i < length; i++){
            str = str + s[i] + "#";
        }
        length = str.size();
        int *len = new int[length];
        int p = 0, max = 0, po = 0;
        for(i = 0; i < length; i++){
            if(i <= p){
                if(len[2 * po - i] <= p - i + 1){
                    len[i] = len[2 * po - i];
                }
                else{
                    len[i] = p - i + 1;
                }
            }
            else{
                len[i] = 1;
            }
            for(j = len[i]; i - j >= 0 && i + j < length; j++){
                if(str[i - j] != str[i + j]){
                    break;
                }
            }
            len[i] = j;
            if(p < i + len[i] - 1){
                po = i;
                p = i + len[i] - 1;
            }
            if(len[max] < j){
                max = i;
            }
        }
        string res = "";
        int left = max - len[max] + 1, right = max + len[max] - 1;
        for(i = left + 1; i <= right - 1; i += 2){
            res += str[i];
        }
        return res;
    }
};

