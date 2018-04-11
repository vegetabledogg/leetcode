class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row, col;
        int m = matrix.size();
        if(m == 0){
            return ;
        }
        int n = matrix[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for(vector<int>::iterator iter = row.begin(); iter != row.end(); iter++){
            for(int i = 0; i < n; i++){
                matrix[*iter][i] = 0;
            }
        }  
        for(vector<int>::iterator iter = col.begin(); iter != col.end(); iter++){
            for(int i = 0; i < m; i++){
                matrix[i][*iter] = 0;
            }
        }
    }
};

