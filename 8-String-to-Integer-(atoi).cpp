/*
 * 循环中对于sum是否溢出的判断应该放在最后，否则无法判断输入为10位且溢出的情况
 */
class Solution {
public:
    int myAtoi(string str) {
        string::iterator i = str.begin();
        while(i != str.end()){
            if(*i != ' '){
                break;
            }
            i++;
        }
        if(i == str.end()){
            return 0;
        }
        int minus = 0;
        if(*i == '+'){
            i++;
        }
        else if(*i == '-'){
            i++;
            minus = 1;
        }
        long long sum = 0, digits = 0;
        while(i != str.end() && *i >= '0' && *i <= '9'){
            sum = sum * 10 + *i - '0';
            i++;
            digits++;
            if(minus == 0 && sum > 2147483647){
                return INT_MAX;
            }
            else if(minus == 1 && sum > 2147483648){
                return INT_MIN;
            }
        }
        if(minus == 0){
            return sum;
        }
        else{
            return -sum;
        }
    }
};

