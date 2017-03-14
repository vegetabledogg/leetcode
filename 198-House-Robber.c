int rob(int* nums, int numsSize) {
    int *max = (int*)calloc(numsSize, sizeof(int));
    int i;
    for (i = 0; i < numsSize; i++)
    {
        if (0 == i)
        {
            max[i] = nums[i];
        }
        else if (1 == i)
        {
            if (max[i - 1] > nums[i])
            {
                max[i] = max[i - 1];
            }
            else
            {
                max[i] = nums[i];
            }
        }
        else
        {
            if (max[i - 1] > max[i - 2] + nums[i])
            {
                max[i] = max[i - 1];
            }
            else
            {
                max[i] = max[i - 2] + nums[i];
            }
        }
    }
    return max[numsSize - 1];
}
