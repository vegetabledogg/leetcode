int comp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
bool checkSubarraySum(int* nums, int numsSize, int k) {
    if(numsSize == 1){
        return false;
    }
    int i, j, count = 0, flag = 1;
    if(k == 0){
        for(i = 1; i < numsSize; i++){
            if(nums[i] == 0 && nums[i - 1] == 0){
                return true;
            }
        }
        return false;
    }
    for(i = 0; i < numsSize; i++){
        if(i == 0){
            nums[i] = nums[i] % k;
        }
        else{
            nums[i] = (nums[i - 1] + nums[i]) % k;
        }
        if(i != 0 && nums[i] == 0){
            return true;
        }
    }
    qsort(nums, numsSize, sizeof(int), comp);
    for(i = 1; i < numsSize; i++){
        if(nums[i] == nums[i - 1]){
            return true;
        }
    }
    return false;
}
