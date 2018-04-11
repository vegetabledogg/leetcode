class Solution {
public:
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        if(length == 0){
            return -1;
        }
        if(nums.front() <= target){
            for(int i = 0; i < length; i++){
                if(nums[i] == target){
                    return i;
                }
                if(i != length - 1 && nums[i] > nums[i + 1]){
                    return -1;
                }
                if(nums[i] > target){
                    return -1;
                }
            }
        }
        if(nums.back() >= target){
            for(int i = length - 1; i >= 0; i--){
                if(nums[i] == target){
                    return i;
                }
                if(i != 0 && nums[i] < nums[i - 1]){
                    return -1;
                }
                if(nums[i] < target){
                    return -1;
                }
            }
        }
        return -1;
    }
};

