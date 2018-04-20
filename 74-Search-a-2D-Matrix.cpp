class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()){
            return false;
        }
        if(matrix[0].empty()){
            return false;
        }
        vector<vector<int>>::iterator i;
        for(i = matrix.begin(); i != matrix.end(); i++){
            if((*i)[0] > target){
                if(i == matrix.begin()){
                    return false;
                }
                else{
                    break;
                }
            }
            else if((*i)[0] == target){
                return true;
            }
        }
        i--;
        for(vector<int>::iterator j = i->begin(); j != i->end(); j++){
            if(*j > target){
                return false;
            }
            else if(*j == target){
                return true;
            }
        }
        return false;
    }
};

