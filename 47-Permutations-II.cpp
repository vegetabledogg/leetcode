class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    void permute(vector<int> nums){
        int length = nums.size();
        if(length == 1){
            res.push_back(nums[0]);
            ans.push_back(vector<int>(res.begin(), res.end()));
            res.pop_back();
            return ;
        }
        else{
            int last;
            for(int i = 0; i < length; i++){
                if(i == 0){
                    last = nums[i];
                }
                else if(last == nums[i]){
                    continue;
                }
                last = nums[i];
                swap(nums[0], nums[i]);
                res.push_back(last);
                permute(vector<int>(nums.begin() + 1, nums.end()));
                res.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        permute(vector<int>(nums.begin(), nums.end()));
        return ans;
    }
};

