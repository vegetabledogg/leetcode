class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i, j, k, m;
        int length = nums.size();
        int temp;
        vector<vector<int>> ans;
        
        if(length == 0){
            return ans;
        }
        sort(nums.begin(), nums.end());
        if(nums.front() > 0 || nums.back() < 0){
            return ans;
        }
        for(i = 0; i < length - 2; i++){
            if(i > 0 && nums[i - 1] == nums[i]){
                continue;
            }
            for(j = i + 1, k = length - 1; j < k; ){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.push_back(temp);
                    j++;
                    while(j < k && nums[j] == nums[j - 1]){
                        j++;
                    }
                    k--;
                    while(j < k && nums[k] == nums[k + 1]){
                        k--;
                    }
                }
                else if(nums[i] + nums[j] + nums[k] < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};

