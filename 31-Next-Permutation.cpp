class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int>::iterator iter;
        vector<int>::reverse_iterator riter;
        int i;
        for(i = nums.size() - 1; i > 0; i--){
            if(nums[i] > nums[i - 1]){
                break;
            }
        }
        if(i == 0){
            reverse(nums.begin(), nums.end());
        }
        else{
            int temp = nums[i - 1];
            for(riter = nums.rbegin(); ; riter++){
                if(*riter > temp){
                    nums[i - 1] = *riter;
                    *riter = temp;
                    reverse(nums.begin() + i, nums.end());
                    break;
                }
            }
        }
    }
};

