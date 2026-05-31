class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {  //space
        int n = cost.size();
        int t2 = cost[0];
        int t1 = cost[1];
        for(int i = 2;i < n;i++){
            int curr = cost[i] + min(t1,t2);
            t2 = t1;
            t1 = curr;
        }
        return min(t1,t2);
    }
};
