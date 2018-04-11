class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i, j, mid, start, end, length = nums.size();
        vector<int> ans;
        
        for(i = 0, j = length - 1; i <= j; ){
            mid = (i + j) / 2;
            if(nums[mid] == target){
                if(mid == 0 || i == j){
                    start = mid;
                    break;
                }
                else{
                    if(nums[mid - 1] == target){
                        j = mid - 1;
                    }
                    else{
                        start = mid;
                        break;
                    }
                }
            }
            else if(nums[mid] > target){
                j = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }
        if(i > j){
            return vector<int>(2, -1);
        }
        for(i = 0, j = length - 1; i <= j; ){
            mid = (i + j) / 2;
            if(nums[mid] == target){
                if(mid == length - 1 || i == j){
                    end = mid;
                    break;
                }
                else{
                    if(nums[mid + 1] == target){
                        i = mid + 1;
                    }
                    else{
                        end = mid;
                        break;
                    }
                }
            }
            else if(nums[mid] > target){
                j = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }
        if(i > j){
            return vector<int>(2, -1);
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};

