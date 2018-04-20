class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++){
            if(*iter == 0){
                red++;
            }
            else if(*iter == 1){
                white++;
            }
            else{
                blue++;
            }
        }
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++){
            if(red > 0){
                *iter = 0;
                red--;
            }
            else if(white > 0){
                *iter = 1;
                white--;
            }
            else if(blue > 0){
                *iter = 2;
                blue--;
            }
        }
    }
};

