class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if(length == 0){
            return 0;
        }
        if(length == 1){
            return 1;
        }
        int current = nums[0];
        int res = 1;
        for(vector<int>::iterator i = nums.begin() + 1; i != nums.end(); ){
            if(*i != current){
                current = *i;
                res++;
                i++;
            }
            else{
                nums.erase(i);
            }
        }
        return res;
    }
};

