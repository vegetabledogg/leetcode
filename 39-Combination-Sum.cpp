class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    void combination(vector<int> &candidates, int target){
        if(target == 0){
            ans.push_back(vector<int>(res.begin(), res.end()));
            return ;
        }
        for(vector<int>::iterator iter = candidates.begin(); iter < candidates.end(); iter++){
            if(!res.empty() && *iter < res.back()){
                continue;
            }
            if(target - *iter >= 0){
                res.push_back(*iter);
                combination(candidates, target - *iter);
                res.pop_back();
            }
            else{
                return;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        combination(candidates, target);
        return ans;
    }
};

