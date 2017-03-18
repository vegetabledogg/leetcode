int rob(int* nums, int numsSize) {
    int *sum1 = (int*)malloc(numsSize * sizeof(int));
    int *sum2 = (int*)malloc(numsSize * sizeof(int));
    int i;
    sum1[0] = 0;
    if (0 == numsSize)
    {
        return 0;
    }
    if (1 == numsSize)
    {
        return nums[0];
    }
    for (i = 1; i < numsSize; i++)
    {
        if (1 == i)
        {
            sum1[i] = nums[i];
        }
        else
        {
            if (sum1[i - 1] > nums[i] + sum1[i - 2])
            {
                sum1[i] = sum1[i - 1];
            }
            else
            {
                sum1[i] = nums[i] + sum1[i - 2];
            }
        }
    }
    for (i = 0; i < numsSize - 1; i++)
    {
        if (0 == i)
        {
            sum2[i] = nums[i];
        }
        else if (1 == i)
        {
            if (nums[i] > nums[i - 1])
            {
                sum2[i] = nums[i];
            }
            else
            {
                sum2[i] = nums[i - 1];
            }
        }
        else
        {
            if (sum2[i - 1] > nums[i] + sum2[i - 2])
            {
                sum2[i] = sum2[i - 1];
            }
            else
            {
                sum2[i] = nums[i] + sum2[i - 2];
            }
        }
    }
    if (sum1[numsSize - 1] > sum2[numsSize - 2])
    {
        return sum1[numsSize - 1];
    }
    else
    {
        return sum2[numsSize - 2];
    }
}
