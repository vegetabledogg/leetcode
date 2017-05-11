/*
 * https://leetcode.com/problems/target-sum/#/description
 * 数列的第一个数前也可以用运算符，所以递归的初始情况可以为正负两种情况
 * 注意第一个数为0的情况，在本解答的初始情况判断语句中，如果不单独判断，将只会被计算一次而导致错误
 */
int findTargetSumWays(int* nums, int numsSize, int S) {
    if(numsSize == 1){
        if(nums[0] == 0 && S == 0){
            return 2;
        }
        if(nums[0] == S || nums[0] == -S){
            return 1;
        }
        else{
            return 0;
        }
    }
    return findTargetSumWays(nums, numsSize - 1, S - nums[numsSize - 1]) + findTargetSumWays(nums, numsSize - 1, S + nums[numsSize - 1]);
}