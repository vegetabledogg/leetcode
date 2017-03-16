int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int i, j;
    int min;
    for (i = 0; i < gridRowSize; i++)
    {
        for (j = 0; j < gridColSize; j++)
        {
            if (0 == i && 0 == j)
            {
                continue;
            }
            else if (0 == i)
            {
                grid[i][j] += grid[i][j - 1];
            }
            else if (0 == j)
            {
                grid[i][j] += grid[i - 1][j];
            }
            else
            {
                if (grid[i - 1][j] < grid[i][j - 1])
                {
                    grid[i][j] += grid[i - 1][j];
                }
                else
                {
                    grid[i][j] += grid[i][j - 1];
                }
            }
        }
    }
    return grid[gridRowSize - 1][gridColSize - 1];
}
