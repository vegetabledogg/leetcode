/*
 * 注意haystack和needle为空的情况
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int lengthH = haystack.size(), lengthN = needle.size();
        if(lengthN > lengthH){
            return -1;
        }
        for(int i = 0; i < lengthH - lengthN + 1; i++){
            int j;
            for(j = 0; j < lengthN; j++){
                if(haystack[i + j] != needle[j]){
                    break;
                }
            }
            if(j == lengthN){
                return i;
            }
        }
        return -1;
    }
};

