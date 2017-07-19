/*
 * 注意numRows为1的情况，注意direction的初始值应该设为-1，因为一开始的时候j就是0，
 * 也就是填入第一个字符后就会触发direction改变的条件
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        vector<char> *a = new vector<char>[numRows];
        int direction = -1, i, j = 0, length = s.size();
        for(i = 0; i < length; i++){
            a[j].push_back(s[i]);
            if(j == 0 || j == numRows - 1){
                direction = 0 - direction;
            }
            j += direction;
        }
        string res = "";
        for(i = 0; i < numRows; i++){
            for(j = 0; j < a[i].size(); j++){
                res = res + a[i][j];
            }
        }
        return res;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        int interval = numRows * 2 - 2, length = s.size();
        string res = "";
        for(int i = 0; i < numRows; i++){
            if(i == 0 || i == numRows - 1){
                for(int j = i; j < length; j += interval){
                    res = res + s[j];
                }
            }
            else{
                for(int j = i; j < length; j += interval){
                    res = res + s[j];
                    if(j + interval - i * 2 < length){
                        res = res + s[j + interval - i * 2];
                    }
                }
            }
        }
        return res;
    }
};

