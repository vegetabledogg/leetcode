int maxProduct(int* nums, int numsSize) {
    int *pos = (int*)malloc(sizeof(int) * numsSize);
    int *neg = (int*)malloc(sizeof(int) * numsSize);
    int i;
    for(i = 0; i < numsSize; i++){
        if(0 == i){
            if(nums[0] > 0){
                pos[0] = nums[0];
                neg[0] = 0;
            }
            else if(nums[0] < 0){
                pos[0] = 0;
                neg[0] = nums[0];
            }
            else{
                pos[0] = neg[0] = 0;
            }
        }
        else{
            if(nums[i] > 0){
                if(pos[i - 1] > 0){
                    pos[i] = pos[i - 1] * nums[i];
                }
                else{
                    pos[i] = nums[i];
                }
                neg[i] = neg[i - 1] * nums[i];
            }
            else if(nums[i] < 0){
                pos[i] = neg[i - 1] * nums[i];
                if(pos[i - 1] > 0){
                    neg[i] = pos[i - 1] * nums[i];
                }
                else{
                    neg[i] = nums[i];
                }
            }
            else{
                pos[i] = neg[i] = 0;
            }
        }
    }
    int max = nums[0];
    for(i = 1; i < numsSize; i++){
        if(max < pos[i]){
            max = pos[i];
        }
    }
    return max;
}
