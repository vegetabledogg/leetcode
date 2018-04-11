class Solution {
public:
    vector<string> ans;
    void generator(string str, int left, int right){
        if(left == 0 && right == 0){
            ans.push_back(str);
            return ;
        }
        if(left > 0){
            generator(str + '(', left - 1, right);
        }
        if(right > 0 && left < right){
            generator(str + ')', left, right - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        
        generator(str, n, n);
        return ans;
    }
};

