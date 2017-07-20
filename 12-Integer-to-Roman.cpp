class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        if(num / 1000 > 0){
            for(int i = 0; i < num / 1000; i++){
                res = res + "M";
            }
        }            
        num %= 1000;
        if(num / 100 == 9){
            res = res + "CM";
        }
        else if(num / 100 >= 5){
            res = res + "D";
            for(int i = 0; i < num / 100 - 5; i++){
                res.push_back('C');
            }
        }
        else if(num / 100 == 4){
            res = res + "CD";
        }
        else if(num / 100 > 0){
            for(int i = 0; i < num / 100; i++){
                res.push_back('C');
            }
        }
        num %= 100;
        if(num / 10 == 9){
            res = res + "XC";
        }
        else if(num / 10 >= 5){
            res = res + "L";
            for(int i = 0; i < num / 10 - 5; i++){
                res.push_back('X');
            }
        }
        else if(num / 10 == 4){
            res = res + "XL";
        }
        else if(num / 10 > 0){
            for(int i = 0; i < num / 10; i++){
                res.push_back('X');
            }
        }
        num %= 10;
        if(num == 9){
            res = res + "IX";
        }
        else if(num >= 5){
            res = res + "V";
            for(int i = 0; i < num - 5; i++){
                res.push_back('I');
            }
        }
        else if(num == 4){
            res = res + "IV";
        }
        else if(num > 0){
            for(int i = 0; i < num; i++){
                res.push_back('I');
            }
        }
        return res;
    }
};

