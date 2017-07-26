/*
 * 注意median如果用(begin + end) / 2的话，begin + end可能会溢出
 */
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int begin = 1, end = n, median;
        while(begin < end){
            median = begin + (end - begin) / 2;
            if(isBadVersion(median) == true){
                end = median;
            }
            else{
                begin = median + 1;
            }
        }
        return begin;
    }
};

