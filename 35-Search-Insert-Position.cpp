class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1, median;
        while(1){
			if(end < begin){
				return begin;
			}
            median = (begin + end) / 2;
            if(nums[median] > target){
                end = median - 1;
            }
            else if(nums[median] < target){
                begin = median + 1;
            }
            else{
                return median;
            }
        }
    }
};

