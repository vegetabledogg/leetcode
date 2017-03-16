int numTrees(int n) {
    int kinds = 0;
    if (0 == n || 1 == n)
    {
        return 1;
    }
    int i;
    for (i = 1; i <= n / 2; i++)
    {
        kinds += numTrees(i - 1) * numTrees(n - i) * 2;
    }
    if (1 == n % 2)
    {
        kinds += numTrees(i - 1) * numTrees(n - i);
    }
    return kinds;
}
