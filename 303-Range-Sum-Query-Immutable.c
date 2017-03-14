typedef struct {
    int numsSize;
    int *nums;
    int *sums;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *newArray = (NumArray*)malloc(sizeof(NumArray));
    newArray->numsSize  = numsSize;
    newArray->nums = nums;
    newArray->sums = (int*)calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        if (0 == i)
        {
            newArray->sums[i] = nums[i];
        }
        else
        {
            newArray->sums[i] = newArray->sums[i - 1] + nums[i];
        }
    }
    return newArray;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    int sum = 0;
    if (0 > i)
    {
        i = 0;
    }
    if (j > obj->numsSize - 1)
    {
        j = obj->numsSize - 1;
    }
    return obj->sums[j] - obj->sums[i] + obj->nums[i];
}

void numArrayFree(NumArray* obj) {
    free(obj->nums);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * struct NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 * numArrayFree(obj);
 */
