int uniquePaths(int m, int n) {
    int** map = (int**)malloc(m * sizeof(int*));
    int i, j;
    for (i = 0; i < m; i++)
    {
        map[i] = (int*)malloc(n * sizeof(int));
        for (j = 0; j < n; j++)
        {
            map[i][j] = 0;
        }
    }
    map[0][0] = 1;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i > 0)
            {
                map[i][j] += map[i - 1][j];
            }
            if (j > 0)
            {
                map[i][j] += map[i][j - 1];
            }
        }
    }
    return map[m - 1][n - 1];
}
