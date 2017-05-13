/*
 * 需要注意判断index和i的关系，而不能简单的将index赋值给i，
 * 因为如果nums[i]为0，按照如下解法将index直接赋值给i的话，会出现死循环，
 * 并且index必须初始化，否则会出错
 */
bool canJump(int* nums, int numsSize) {
    int i, j, max, index = 0;
    for(i = 0; i < numsSize; ){
        max = 0;
        if(i + nums[i] >= numsSize - 1){
            return true;
        }
        for(j = i + nums[i]; j > i; j--){
            if(max < nums[j] + j){
                max = nums[j] + j;
                index = j;
            }
        }
        if(i < index){
            i = index;
        }
        else{
            return false;
        }
    }
    return false;
}
