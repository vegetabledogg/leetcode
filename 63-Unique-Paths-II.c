int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridColSize, int obstacleGridRowSize) {
    int i, j;
    if (1 == obstacleGrid[0][0] || 1 == obstacleGrid[obstacleGridColSize - 1][obstacleGridRowSize - 1])
    {
        return 0;
    }
    obstacleGrid[0][0] = -1;
    for (i = 0; i < obstacleGridColSize; i++)
    {
        for (j = 0; j < obstacleGridRowSize; j++)
        {
            if (1 == obstacleGrid[i][j])
            {
                continue;
            }
            if (i > 0 && 1 != obstacleGrid[i - 1][j])
            {
                obstacleGrid[i][j] += obstacleGrid[i - 1][j];
            }
            if (j > 0 && 1 != obstacleGrid[i][j - 1])
            {
                obstacleGrid[i][j] += obstacleGrid[i][j - 1];
            }
        }
    }
    return -obstacleGrid[obstacleGridColSize - 1][obstacleGridRowSize - 1];
}
