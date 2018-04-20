class Solution {
public:
    vector<vector<int>> generate_combinations(int start, int n, int k){
        vector<vector<int>> ret, temp;
        if(k == 1){
            for(int i = start; i <= n; i++){
                vector<int> combination;
                combination.push_back(i);
                ret.push_back(combination);
            }
            return ret;
        }
        for(int i = start; i + k <= n + 1; i++){
            temp = generate_combinations(i + 1, n, k - 1);
            for(vector<vector<int>>::iterator iter = temp.begin(); iter != temp.end(); iter++){
                iter->insert(iter->begin(), i);
                ret.push_back(*iter);
            }
        }
        return ret;
    }
    vector<vector<int>> combine(int n, int k) {
        return generate_combinations(1, n, k);
    }
};

