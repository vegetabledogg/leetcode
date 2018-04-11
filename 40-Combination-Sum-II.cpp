class Solution {
public:
    vector<int> res;
    vector<vector<int>> ans;
    set<vector<int>> hashset;
    void combination(vector<int>& candidates, const vector<int>::iterator &current_iter, int target){
        if(target == 0){
            vector<int> temp(res.begin(), res.end());
            if(hashset.find(temp) == hashset.end()){
                hashset.insert(temp);
                ans.push_back(temp);
            }
            return ;
        }
        for(vector<int>::iterator iter = current_iter; iter != candidates.end(); iter++){
            if(target - *iter >= 0){
                res.push_back(*iter);
                combination(candidates, iter + 1, target - *iter);
                res.pop_back();
            }
            else{
                return ;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        combination(candidates, candidates.begin(), target);
        return ans;
    }
};

