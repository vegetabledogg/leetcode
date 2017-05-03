#define MIN(a, b) ((a) < (b) ? (a) : (b))
int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
    int **l = (int**)malloc(sizeof(int*) * matrixRowSize);
    int i, j, max = 0;
    for(i = 0; i < matrixRowSize; i++){
        l[i] = (int*)malloc(sizeof(int) * matrixColSize);
    }
    for(i = 0; i < matrixRowSize; i++){
        if(matrix[i][0] == '0'){
            l[i][0] = 0;
        }
        else{
            l[i][0] = 1;
            max = 1;
        }
    }
    for(i = 0; i < matrixColSize; i++){
        if(matrix[0][i] == '0'){
            l[0][i] = 0;
        }
        else{
            l[0][i] = 1;
            max = 1;
        }
    }
    for(i = 1; i < matrixRowSize; i++){
        for(j = 1; j < matrixColSize; j++){
            if('0' != matrix[i][j]){
                l[i][j] = MIN(MIN(l[i - 1][j], l[i - 1][j - 1]), l[i][j - 1]) + 1;
            }
            else{
                l[i][j] = 0;
            }
            if(l[i][j] > max){
                max = l[i][j];
            }
        }
    }
    return max * max;
}
