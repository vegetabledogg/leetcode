class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int i = 0, j = -1;
        int m = matrix.size();
        if(m == 0){
            return ans;
        }
        int n = matrix[0].size();
        vector<int *> flag;
        for(int k = 0; k < m; k++){
            flag.push_back(new int[n]);
            for(int l = 0; l < n; l++){
                flag[k][l] = 0;
            }
        }
        
        while(1){
            int tempi = i;
            int tempj = j;
            for(j++ ; j < n; j++){
                if(flag[i][j] != -1){
                    ans.push_back(matrix[i][j]);
                    flag[i][j] = -1;
                }
                else{
                    break;
                }
            }
            j--;
            for(i++ ; i < m; i++){
                if(flag[i][j] != -1){
                    ans.push_back(matrix[i][j]);
                    flag[i][j] = -1;
                }
                else{
                    break;
                }
            }
            i--;
            for(j-- ; j >= 0; j--){
                if(flag[i][j] != -1){
                    ans.push_back(matrix[i][j]);
                    flag[i][j] = -1;
                }
                else{
                    break;
                }
            }
            j++;
            for(i-- ; i >= 0; i--){
                if(flag[i][j] != -1){
                    ans.push_back(matrix[i][j]);
                    flag[i][j] = -1;
                }
                else{
                    break;
                }
            }
            i++;
            if(tempi == i && tempj == j){
                return ans;
            }
        }
    }
};

