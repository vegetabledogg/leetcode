/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool compare(struct Interval a, struct Interval b){
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval>::iterator i, j;
        for(i = intervals.begin(); i != intervals.end(); i++){
            int temp = i->end;
            for(j = i + 1; j != intervals.end(); j++){
                if(j->start <= temp){
                    temp = max(temp, j->end);
                }
                else{
                    break;
                }
            }
            j--;
            ans.push_back(Interval(i->start, temp));
            i = j;
        }
        return ans;
    }
};

