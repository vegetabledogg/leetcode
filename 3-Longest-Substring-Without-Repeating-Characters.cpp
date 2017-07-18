/*
 * 第一种是O(n^3)的解法，没有什么难点
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0, i, j, k, flag;
        for(i = 0; i < s.size(); i++){
            for(j = 1; j < s.size() - i; j++){
                flag = 0;
                for(k = i; k < i + j; k++){
                    if(s[k] == s[i + j]){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1){
                    break;
                }
            }
            if(j > max){
                max = j;
            }
        }
        return max;
    }
};

/*
 * 2n steps，C++的set用红黑树实现，每一步还需考虑库函数的时间复杂度
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }
        int max = 1, i = 0, j = 1;
        set<char> myset;
        myset.insert(s[0]);
        while(j < s.size() - i){
            if(myset.find(s[i + j]) == myset.end()){
                myset.insert(s[i + j]);
                j++;
                if(j > max){
                    max = j;
                }
            }
            else{
                myset.erase(s[i]);
                i++;
                j--;
            }
        }
        return max;
    }
};

