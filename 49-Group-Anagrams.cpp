class Solution {
public:
    map<string, vector<string>> hashset;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {      
        for(vector<string>::iterator iter = strs.begin(); iter != strs.end(); iter++){
            string s = *iter;
            char *temp_str = (char *)(iter->c_str());
            sort(temp_str, temp_str + strlen(temp_str));
            map<string, vector<string>>::iterator temp_iter = hashset.find(string(temp_str));
            if(temp_iter != hashset.end()){
                (temp_iter->second).push_back(s);
            }
            else{
                vector<string> new_vector;
                new_vector.push_back(s);
                hashset.insert(pair<string, vector<string>>(string(temp_str), new_vector));
            }
        }
        vector<vector<string>> ans;
        for(map<string, vector<string>>::iterator iter = hashset.begin(); iter != hashset.end(); iter++){
            ans.push_back(iter->second);
        }
        return ans;
    }
};

