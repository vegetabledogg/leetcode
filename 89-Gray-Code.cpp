class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        vector<int> temp;
        ans.push_back(0);
        for(int i = 0; i < n; i++){
            int length = ans.size();
            temp.clear();
            for(int i = 0; i < length; i++){
                if(i % 2 == 0){
                    temp.push_back(ans[i] * 2 + 0);
                    temp.push_back(ans[i] * 2 + 1);
                }
                else{
                    temp.push_back(ans[i] * 2 + 1);
                    temp.push_back(ans[i] * 2 + 0);
                }
            }
            ans = temp;
        }
        return ans;
    }
};

