int maxSubArray(int* nums, int numsSize) {
    int *sum = (int*)calloc(numsSize, sizeof(int));
    int i, j;
    int max = nums[0];
    for (i = 0; i < numsSize; i++)
    {
        if (0 == i)
        {
            sum[i] = nums[i];
        }
        else
        {
            if (sum[i - 1] > 0)
            {
                sum[i] = sum[i - 1] + nums[i];
            }
            else
            {
                sum[i] = nums[i];
            }
        }
        if (sum[i] > max)
        {
            max = sum[i];
        }
    }
    return max;
}
