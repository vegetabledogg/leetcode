class Solution {
public:
    int romanToInt(string s) {
        int i, length = s.size(), res = 0;
        for(i = 0; i < length; i++){
            if(s[i] == 'M'){
                res += 1000;
            }
            else if(s[i] == 'D'){
                res += 500;
            }
            else if(s[i] == 'L'){
                res += 50;
            }
            else if(s[i] == 'V'){
                res += 5;
            }
            else if(s[i] == 'C'){
                if(i + 1 != length){
                    if(s[i + 1] == 'D' || s[i + 1] == 'M'){
                        res -= 100;
                    }
                    else{
                        res += 100;
                    }
                }
                else{
                    res += 100;
                }
            }
            else if(s[i] == 'X'){
                if(i + 1 != length){
                    if(s[i + 1] == 'L' || s[i + 1] == 'C'){
                        res -= 10;
                    }
                    else{
                        res += 10;
                    }
                }
                else{
                    res += 10;
                }
            }
            else if(s[i] == 'I'){
                if(i + 1 != length){
                    if(s[i + 1] == 'V' || s[i + 1] == 'X'){
                        res -= 1;
                    }
                    else{
                        res += 1;
                    }
                }
                else{
                    res += 1;
                }
            }
        }
        return res;
    }
};

