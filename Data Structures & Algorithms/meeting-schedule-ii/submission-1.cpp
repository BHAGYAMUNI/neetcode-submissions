/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int>startT;
        vector<int>endT;
        for(auto it:intervals){
            startT.push_back(it.start);
            endT.push_back(it.end);
        }
        sort(startT.begin(),startT.end());
        sort(endT.begin(),endT.end());
        int i = 0,j = 0;
        int curr = 0,maxi = 0;
        while(i < n){
            if(startT[i] < endT[j]){
                curr++;
                maxi = max(maxi,curr);
                i++;
            }else{
                curr--;
                j++;
            }
        }
        return maxi;
    }
};
