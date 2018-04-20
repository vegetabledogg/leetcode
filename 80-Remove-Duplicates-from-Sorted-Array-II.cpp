class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int last = nums[0];
        int count = 1;
        int dup = 1;
        for(vector<int>::iterator iter = nums.begin() + 1; iter != nums.end(); iter++){
            if(*iter == last){
                if(dup < 2){
                    dup++;
                    count++;
                }
                else{
                    nums.erase(iter);
                    iter--;
                }
            }
            else{
                dup = 1;
                count++;
                last = *iter;
            }
        }
        return count;
    }
};

