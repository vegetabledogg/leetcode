/*
 * 这道题目贪心的思想很简单，但是首先要注意判断起始点就无法到达下一个点的情况，
 * 如果起始点就无法到达下一个点，i和j是相等的，如果不单独判断，和能够走完一圈的判断条件是一样的，
 * 也就无法正确输出，并且为了节省时间，假设从点A出发，第一个出现的到达不了的点是点B，
 * 那么之后就应该从点B后的那个点出发进行判断，因为对于点A到点B路径上的任意一点C，
 * 从点A出发后到达点C且还未加油时油箱的余量都至少是0，也就是从点A出发到达点C和从点C出发，
 * 在点C时油箱的余量至少一样多，甚至有可能比从点C出发时的油量多，这样都到不了点B，
 * 所以应该从点B后的点再开始重新计算
 */
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int tank, i, j, flag;
    for(i = 0; i < gasSize; i++){
        if(gas[i] < cost[i]){
            continue;
        }
        tank= 0;
        j = i;
        do{
            tank += (gas[j] - cost[j]);
            if(tank < 0){
                break;
            }
            j = (j + 1) % gasSize;
        }while(j != i);
        if(i == j){
            return i;
        }
        else{
            if((j + 1) % gasSize != i){
                i = j;
            }
            else{
                return -1;
            }
        }
    }
    return -1;
}
