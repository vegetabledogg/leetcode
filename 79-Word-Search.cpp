class Solution {
public:
    int **flag;
    bool search(vector<vector<char>>& board, string word, int row, int col){
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()){
            return false;
        }
        if(word[0] == board[row][col] && flag[row][col] == 0){
            if(word.size() == 1){
                return true;
            }
            else{
                int length = word.size();
                flag[row][col] = 1;
                int ret = search(board, word.substr(1, length - 1), row - 1, col)
                    || search(board, word.substr(1, length - 1), row, col + 1)
                    || search(board, word.substr(1, length - 1), row + 1, col)
                    || search(board, word.substr(1, length - 1), row, col - 1);
                if(ret == true){
                    return true;
                }
                else{
                    flag[row][col] = 0;
                    return false;
                }
            }
        }
        else{
            return false;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        flag = new int*[row];
        for(int i = 0; i < row; i++){
            flag[i] = new int[col];
            for(int j = 0; j < col; j++){
                flag[i][j] = 0;
            }
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(search(board, word, i, j) == true){
                    return true;
                }
            }
        }
        return false;
    }
};

