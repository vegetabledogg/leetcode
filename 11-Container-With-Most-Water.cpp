/*
 * 方法二时间更快，i从前开始遍历，j从后开始遍历，如果当前height[i]比之前的i的最高值小或相等，
 * 那么无论如何当前i和之后的j组成的container的大小都不会是max。
 * 又因为j从后往前遍历，只要遇到当前height[j]比当前height[i]大，
 * 那么无论如何当前i和之后的j组成的container的大小都不会是max，
 * 所以遇到这种情况只要比较当前i和j组成的container与max然后跳出循环即可。
 * 而且对于当前i，如果当前height[j]比之前遍历的j小或相等，
 * 那么无论如何当前i和j组成的container的大小都不会是max
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int length = height.size(), i, j, max = 0, temp, maxHeight;
        for(i = 1; i < length; i++){
            temp = height[i];
            maxHeight = 0;
            for(j = 0; j < i; j++){
                if(height[j] > maxHeight){
                    if(height[j] < temp){
                        maxHeight = height[j];
                        if(height[j] * (i - j) > max){
                            max = height[j] * (i - j);
                        }
                    }
                    else{
                        if(temp * (i - j) >= max){
                            max = temp * (i - j);
                        }
                        break;
                    }
                }
            }
        }
        return max;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int length = height.size(), i, j, max = 0, temp = 0, maxHeight;
        for(i = 0; i < length - 1; i++){
            if(temp < height[i]){
                temp = height[i];
            }
            else{
                continue;
            }
            maxHeight = 0;
            for(j = length - 1; j > i; j--){
                if(height[j] > maxHeight){
                    if(height[j] < temp){
                        maxHeight = height[j];
                        if(height[j] * (j - i) > max){
                            max = height[j] * (j - i);
                        }
                    }
                    else{
                        if(temp * (j - i) >= max){
                            max = temp * (j - i);
                        }
                        break;
                    }
                }
            }
        }
        return max;
    }
};

