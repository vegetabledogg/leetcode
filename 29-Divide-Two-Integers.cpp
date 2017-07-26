/*
 * 可以用移位运算来代替乘法，
 * 分清条件dd >= dr和dd > dr，int除以int时-2147483647 / -1会溢出，
 * C++11中的abs有int、long int和long long三种不同参数，
 * 如果这里在使用abs时没有强制类型转换的话，会使用int型的abs，这样-2147483648就会溢出
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0){
            return 0;
        }
        if(dividend == -2147483648 && divisor == -1){
            return 2147483647;
        }
        int flag;
        if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)){
            flag = 0;
        }
        else{
            flag = 1;
        }
        long long dd = abs((long long)dividend), dr = abs((long long)divisor), i = 1, res = 0;
        while(dd >= dr){
            dr <<= 1;
            i <<= 1;
        }
        dr >>= 1;
        i >>= 1;
        while(i > 0){
            if(dd >= dr){
                dd -= dr;
                res += i;
            }
            dr >>= 1;
            i >>= 1;
        }
        if(flag == 1){
            return -res;
        }
        return res;
    }
};

