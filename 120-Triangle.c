int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    int i, j;
    for (i = 1; i < triangleRowSize; i++)
    {
        for (j = 0; j < triangleColSizes[i]; j++)
        {
            if (0 == j)
            {
                triangle[i][j] += triangle[i - 1][j];
            }
            else if (triangleColSizes[i] - 1 == j)
            {
                triangle[i][j] += triangle[i - 1][j - 1];
            }
            else
            {
                triangle[i][j] += (triangle[i - 1][j - 1] > triangle[i - 1][j] ? triangle[i - 1][j] : triangle[i - 1][j - 1]);
            }
        }
    }
    int min = triangle[triangleRowSize - 1][0];
    for (i = 1; i < triangleColSizes[triangleRowSize - 1]; i++)
    {
        if (min > triangle[triangleRowSize - 1][i])
        {
            min = triangle[triangleRowSize - 1][i];
        }
    }
    return min;
}
