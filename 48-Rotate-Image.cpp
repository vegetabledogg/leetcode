class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int side_length = matrix[0].size();
        for(int i = 0; i < side_length / 2; i++){
            for(int j = i; j < side_length - i - 1; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[side_length - j - 1][i];
                matrix[side_length - j - 1][i] = matrix[side_length - i - 1][side_length - j - 1];
                matrix[side_length - i - 1][side_length - j - 1] = matrix[j][side_length - i - 1];
                matrix[j][side_length - i - 1] = temp;
            }
        }
    }
};

