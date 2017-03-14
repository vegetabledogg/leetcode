int climbStairs(int n) {
    int *ways = (int*)calloc(n, sizeof(n));
    int i;
    for (i = 0; i < n; i++)
    {
        if (0 == i)
        {
            ways[0] = 1;
        }
        else if (1 == i)
        {
            ways[1] = 2;
        }
        else
        {
            ways[i] = ways[i - 1] + ways[i - 2];
        }
    }
    return ways[n - 1];
}
