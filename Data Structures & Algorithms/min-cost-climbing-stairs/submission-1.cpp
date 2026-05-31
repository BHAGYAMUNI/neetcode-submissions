class Solution {
public:
    int solve(vector<int>&dp,int i,vector<int>& cost){
        if(i == 0) return cost[0];
        if(i == 1) return cost[1];
        if(dp[i] != -1) return dp[i];
        return dp[i] = cost[i] + min(solve(dp,i-1,cost),solve(dp,i-2,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 0) return cost[0];
        if(n == 1) return cost[1];
        int t2 = cost[0];
        int t1 = cost[1];
        for(int i = 2;i <= n;i++){
            int curr = cost[i] + min(t1,t2);
            t2 = t1;
            t1 = curr;
        }
        return t1;
    }
};
