typedef struct {
    int **matrix;
    int matrixRowSize;
    int matrixColSize;
} NumMatrix;

NumMatrix* numMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize) {
    NumMatrix *obj = (NumMatrix*)malloc(sizeof(NumMatrix));
    obj->matrix = (int**)malloc(matrixRowSize * sizeof(int*));
    for (int i = 0; i < matrixRowSize; i++)
    {
        obj->matrix[i] = (int*)malloc(matrixColSize * sizeof(int));
    }
    obj->matrixRowSize = matrixRowSize;
    obj->matrixColSize = matrixColSize;
    for (int i = 0; i < matrixRowSize; i++)
    {
        for (int j = 0; j < matrixColSize; j++)
        {
            if (0 == i && 0 == j)
            {
                obj->matrix[0][0] = matrix[0][0];
            }
            else if (0 == i)
            {
                obj->matrix[0][j] = obj->matrix[0][j - 1] + matrix[0][j];
            }
            else if (0 == j)
            {
                obj->matrix[i][0] = obj->matrix[i - 1][0] + matrix[i][0];
            }
            else
            {
                obj->matrix[i][j] = obj->matrix[i][j - 1] + obj->matrix[i - 1][j] - obj->matrix[i - 1][j - 1] + matrix[i][j];
            }
        }
    }
    return obj;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    if (0 == row1 && 0 == col1)
    {
        return obj->matrix[row2][col2];
    }
    else if (0 == row1)
    {
        return obj->matrix[row2][col2] - obj->matrix[row2][col1 - 1];
    }
    else if (0 == col1)
    {
        return obj->matrix[row2][col2] - obj->matrix[row1 - 1][col2];
    }
    else
    {
        return obj->matrix[row2][col2] - obj->matrix[row2][col1 - 1] - obj->matrix[row1 - 1][col2] + obj->matrix[row1 - 1][col1 - 1];
    }
}

void numMatrixFree(NumMatrix* obj) {
    for (int i = 0; i < obj->matrixRowSize; i++)
    {
        free(obj->matrix[i]);
    }
    free(obj->matrix);
    free(obj);
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * struct NumMatrix* obj = numMatrixCreate(matrix, matrixRowSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 * numMatrixFree(obj);
 */
 
